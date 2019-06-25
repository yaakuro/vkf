/*
	Vulkan Framework Copyright (c) 2017 - 2019 Cengiz Terzibas

	Permission is hereby granted, free of charge, to any person obtaining a copy of
	this software and associated documentation files (the "Software"), to deal in the
	Software without restriction, including without limitation the rights to use, copy,
	modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
	and to permit persons to whom the Software is furnished to do so, subject to the
	following conditions:

	The above copyright notice and this permission notice shall be included in all copies
	or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
	INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
	PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
	FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
	OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
	DEALINGS IN THE SOFTWARE.

*/

#include <vkf/vulkan_framework_types.h>
#include <vkf/vulkan_framework_windows_c.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if VKF_SURFACE_WIN32
	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
		switch(message) {
			case WM_SIZE:
			case WM_EXITSIZEMOVE:
				PostMessage(hWnd, WM_USER + 1, wParam, lParam);
				break;
			case WM_KEYDOWN:
			case WM_CLOSE:
				PostMessage(hWnd, WM_USER + 2, wParam, lParam);
				break;
			default:
				return DefWindowProc(hWnd, message, wParam, lParam);
		}
		return 0;
	}
#endif

VKFAPI VkfResult vkfCreateWindow(VkfWindowCreateInfo* createInfo, VkfWindow** window) {
	(*window) = (VkfWindow*)malloc(sizeof(VkfWindow));
	(*window)->title = createInfo->title;
	(*window)->width = createInfo->width;
	(*window)->height = createInfo->height;

#ifdef VKF_SURFACE_XCB
	//
	// Connect to X11 server and create a window.
	//

	// Use DISPLAY environment variable to connect to display server and use Screen 0.
	(*window)->connection = xcb_connect(NULL, NULL);
	(*window)->screen = xcb_setup_roots_iterator(xcb_get_setup((*window)->connection)).data;
	(*window)->window = xcb_generate_id((*window)->connection);

	uint32_t values[2];
	uint32_t mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
	values[0] = (*window)->screen->black_pixel;
	values[1] = XCB_EVENT_MASK_EXPOSURE | XCB_EVENT_MASK_BUTTON_PRESS | XCB_EVENT_MASK_BUTTON_RELEASE |
	            XCB_EVENT_MASK_POINTER_MOTION | XCB_EVENT_MASK_ENTER_WINDOW | XCB_EVENT_MASK_LEAVE_WINDOW |
	            XCB_EVENT_MASK_KEY_PRESS | XCB_EVENT_MASK_KEY_RELEASE;

	xcb_create_window((*window)->connection,                 // X11 connection.
	                  XCB_COPY_FROM_PARENT,                  // Depth.
	                  (*window)->window,                     // Window id.
	                  (*window)->screen->root,               // Parent window.
	                  0, 0,                                  // X, Y position of the window on the screen.
	                  createInfo->width, createInfo->height, // Width, Height of the window.
	                  0,                                     // Border width.
	                  XCB_WINDOW_CLASS_INPUT_OUTPUT,         // Class type. (Input/Output for normal window)
	                  (*window)->screen->root_visual,        // Visual.
	                  mask,                                  // Masks.
	                  values);                               // Values.

	(*window)->cookie = xcb_intern_atom((*window)->connection, 1, 12, "WM_PROTOCOLS");
	xcb_intern_atom_reply_t* reply = xcb_intern_atom_reply((*window)->connection, (*window)->cookie, 0);

	(*window)->cookie2 = xcb_intern_atom((*window)->connection, 0, 16, "WM_DELETE_WINDOW");
	(*window)->atom_wm_delete_window = xcb_intern_atom_reply((*window)->connection, (*window)->cookie2, 0);

	xcb_change_property((*window)->connection,
	                    XCB_PROP_MODE_REPLACE,
	                    (*window)->window,
	                    reply->atom,
	                    4,
	                    32,
	                    1,
	                    &(*(*window)->atom_wm_delete_window).atom);

	xcb_change_property((*window)->connection,
	                    XCB_PROP_MODE_REPLACE,
	                    (*window)->window,
	                    XCB_ATOM_WM_NAME,
	                    XCB_ATOM_STRING,
	                    8,
	                    strlen(createInfo->title),
	                    createInfo->title);

	free(reply);

	// Flush the command queue for the X11 server.
	xcb_flush((*window)->connection);

	// Create Key symbols which will be used when converting key events into keysym.
	(*window)->kss = xcb_key_symbols_alloc((*window)->connection);
#elif defined(VKF_SURFACE_XLIB)
	(*window)->display = XOpenDisplay(NULL);
	if(NULL == (*window)->display) {
		printf("Couldn't connect to X11 display server.\n");
		return VKF_FAILED;
	}

	(*window)->window = XCreateSimpleWindow((*window)->display, DefaultRootWindow((*window)->display), 0, 0, (*window)->width, (*window)->height, 0, 0, 0x888888);
	if(None == (*window)->window) {
		printf("Couldn't create a X11 window\n");
		return VKF_FAILED;
	}
	XSelectInput((*window)->display, (*window)->window, PropertyChangeMask | ButtonPressMask | ButtonReleaseMask | KeyPressMask |
	             KeyReleaseMask | PointerMotionMask | StructureNotifyMask);
	(*window)->WM_DELETE_WINDOW = XInternAtom((*window)->display, "WM_DELETE_WINDOW", False);
	(*window)->WM_PROTOCOLS = XInternAtom((*window)->display, "WM_PROTOCOLS", False);

	XClassHint* class_hints = XAllocClassHint();
	XTextProperty windowName;
	XTextProperty iconName;
	XStringListToTextProperty((char**)&(*window)->title, 1, &windowName);
	XStringListToTextProperty((char**)&(*window)->title, 1, &iconName);
	class_hints->res_name   = (char*)(*window)->title;
	class_hints->res_class  = (char*)(*window)->title;
	XSetWMProperties((*window)->display, (*window)->window, &windowName, &iconName, NULL, 0, NULL, NULL, class_hints);
	XFree(windowName.value);
	XFree(iconName.value);
	XFree(class_hints);

	XFlush((*window)->display);
#elif defined(VKF_SURFACE_WIN32)
	(*window)->hinstance = GetModuleHandle(NULL);

	// Register window class
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = (*window)->hinstance;
	wcex.hIcon = NULL;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = (*window)->title;
	wcex.hIconSm = NULL;

	if(!RegisterClassEx(&wcex)) {
		return VKF_FAILED;
	}

	// Create window
	(*window)->hwnd = CreateWindow((*window)->title, (*window)->title, WS_OVERLAPPEDWINDOW, 0, 0, (*window)->width, (*window)->height, NULL, NULL, (*window)->hinstance, NULL);
	if(!(*window)->hwnd) {
		return VKF_FAILED;
	}
#endif

	return VKF_SUCCESS;
}

#ifdef VKF_SURFACE_XCB
VKFAPI VkfResult vkfCreateWindowXCB(const char* title, uint32_t width, uint32_t height, xcb_connection_t* connection, xcb_window_t wnd, VkfWindow** window) {
	(*window) = (VkfWindow*)malloc(sizeof(VkfWindow));
	(*window)->title = title;
	(*window)->width = width;
	(*window)->height = height;
	(*window)->connection = connection;
	(*window)->window = wnd;

	return VKF_SUCCESS;
}
#elif defined(VKF_SURFACE_XLIB)
VKFAPI VkfResult vkfCreateWindowXLIB(const char* title, uint32_t width, uint32_t height, Display* display, Window wnd, VkfWindow** window) {
	(*window) = (VkfWindow*)malloc(sizeof(VkfWindow));
	(*window)->title = title;
	(*window)->width = width;
	(*window)->height = height;
	(*window)->display = display;
	(*window)->window = wnd;
	(*window)->WM_DELETE_WINDOW = XInternAtom(display, "WM_DELETE_WINDOW", False);
	(*window)->WM_PROTOCOLS = XInternAtom(display, "WM_PROTOCOLS", False);

	return VKF_SUCCESS;
}
#elif defined(VKF_SURFACE_WIN32)
VKFAPI VkfResult vkfCreateWindowWindows(const char* title, uint32_t width, uint32_t height, HINSTANCE instance, HWND hwnd, VkfWindow** window) {
	(*window) = (VkfWindow*)malloc(sizeof(VkfWindow));
	(*window)->title = title;
	(*window)->width = width;
	(*window)->height = height;
	(*window)->hinstance = instance;
	(*window)->hwnd = hwnd;

	return VKF_SUCCESS;
}
#endif



VKFAPI VkfResult vkfDestroyWindow(VkfWindow* window) {
#ifdef VKF_SURFACE_XCB
	if(NULL != window->connection) {
		xcb_key_symbols_free(window->kss);
		xcb_destroy_window(window->connection, window->window);
		xcb_disconnect(window->connection);
	}
#elif defined(VKF_SURFACE_XLIB)
	if(None != window->window) {
		XUnmapWindow(window->display, window->window);
		XDestroyWindow(window->display, window->window);
		window->window = None;
	}
	if(NULL != window->display) {
		XCloseDisplay(window->display);
		window->display = NULL;
	}
#elif defined(VKF_SURFACE_WIN32)
	if(window->hwnd) {
		DestroyWindow(window->hwnd);
	}

	if(window->hinstance) {
		UnregisterClass(window->title, window->hinstance);
	}
#endif
	free(window);

	return VKF_SUCCESS;
}

VKFAPI void vkfShowWindow(VkfWindow* window) {
#ifdef VKF_SURFACE_XCB
	xcb_map_window(window->connection, window->window);
	xcb_flush(window->connection);
#elif defined(VKF_SURFACE_XLIB)
	XMapRaised(window->display, window->window);
	XFlush(window->display);
#elif defined(VKF_SURFACE_WIN32)
	ShowWindow(window->hwnd, TRUE);
#endif
}

VKFAPI uint32_t VkfPollWindowEvents(VkfWindow* window) {
#ifdef VKF_SURFACE_WIN32
	MSG message;
	uint32_t resize = 0;

	if(PeekMessage(&message, NULL, 0, 0, PM_REMOVE)) {
		// Process events
		switch(message.message) {
			// Resize
			case WM_USER + 1:
				resize = 1;
				break;
				return 0;
			case WM_USER + 2:
				// loop = false;
				break;
		}
		TranslateMessage(&message);
		DispatchMessage(&message);
	} else {
		// Draw
		//			if( resize ) {
		//				resize = false;
		//				if( !tutorial.OnWindowSizeChanged() ) {
		//					loop = false;
		//				}
		//			}
		//			if( !tutorial.Draw() ) {
		//				loop = false;
		//			}
	}
#elif defined(VKF_SURFACE_XCB)
	xcb_generic_event_t* event;
	event = xcb_poll_for_event(window->connection);
	if(NULL != event) {
		switch(event->response_type & ~0x80) {

			case XCB_EXPOSE: {
				// xcb_expose_event_t *ev = (xcb_expose_event_t *)event;
				break;
			}

			case XCB_KEY_PRESS: {
				xcb_key_press_event_t* ev = (xcb_key_press_event_t*)event;
				xcb_keysym_t ks = xcb_key_symbols_get_keysym(window->kss, ev->detail, 0);

				if(XK_Escape == ks) {
					return 0;
				}

				break;
			}
			case XCB_KEY_RELEASE: {
				// xcb_key_release_event_t* ev =
				//(xcb_key_release_event_t*)event;
				break;
			}
			case XCB_CLIENT_MESSAGE: {
				if((*(xcb_client_message_event_t*)event).data.data32[0] == (*window->atom_wm_delete_window).atom) {
					return 0;
				}
			}
			break;

			case XCB_DESTROY_NOTIFY: {
				return 0;
			}
			break;
		}
	}
#elif defined(VKF_SURFACE_XLIB)
	while(XPending(window->display)) {
		XEvent event;
		XNextEvent(window->display, &event);
		switch(event.type) {
			case ButtonPress: {
			} break;
			case ButtonRelease: {
			} break;
			case MotionNotify: {
			} break;
			case ClientMessage: {
				if((event.xclient.message_type == window->WM_PROTOCOLS) && ((Atom)event.xclient.data.l[0] == window->WM_DELETE_WINDOW) &&
				    (event.xclient.format == 32)) {
					return 0;
				}
			}
			break;
			case KeyPress: {
				KeySym keysym = XkbKeycodeToKeysym(window->display, event.xkey.keycode, 0, 0);
				if(XK_Escape == keysym) {
					return 0;
				}
			}
			break;
			case KeyRelease: {

			} break;
		}
	}
#endif

	return 1;
}

VKFAPI void vkfSetWindowInputFocus(VkfWindow* window) {
#ifdef VKF_SURFACE_XCB
		xcb_set_input_focus(window->connection, XCB_INPUT_FOCUS_POINTER_ROOT, window->window, XCB_CURRENT_TIME);
		xcb_flush(window->connection);
#elif defined(VKF_SURFACE_XLIB)
		XSetInputFocus(window->display, window->window, RevertToPointerRoot, CurrentTime);
		XFlush(window->display);
#endif
	}
