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

#ifndef VULKAN_FRAMEWORK_WINDOWS_C_H
#define VULKAN_FRAMEWORK_WINDOWS_C_H

#include <vkf/vulkan_framework_types.h>

#define VKF_CHECK(A) assert(A)

#ifdef __linux__
	#ifdef __ANDROID__
		#define VK_USE_PLATFORM_ANDROID_KHR
	#elif defined(VKF_SURFACE_XCB)
		#define VK_USE_PLATFORM_XCB_KHR
		#include <xcb/xcb_keysyms.h>
		#include <X11/keysym.h>
	#elif defined(VKF_SURFACE_XLIB)
		#define VK_USE_PLATFORM_XLIB_KHR
		#include <X11/Xlib.h>
		#include <X11/keysym.h>
		#include <X11/XKBlib.h>
		#include <X11/Xatom.h>
		#include <X11/Xutil.h>
	#elif defined(VKF_SURFACE_WAYLAND)
		#define VK_USE_PLATFORM_WAYLAND_KHR
		#include <wayland-client.h>
	#endif

#elif defined(WIN32)
	#ifdef VKF_SURFACE_WIN32
		#define VK_USE_PLATFORM_WIN32_KHR
		#include <windows.h>
	#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct VkfWindowCreateInfo {
	const char* title;
	int32_t width;
	int32_t height;
} VkfWindowCreateInfo;

typedef struct VkfWindow {
	const char* title;
	int32_t width;
	int32_t height;
#ifdef VKF_SURFACE_XCB
	xcb_connection_t* connection;
	xcb_screen_t* screen;
	xcb_window_t window;

	xcb_key_symbols_t* kss;
	xcb_intern_atom_cookie_t cookie;
	xcb_intern_atom_cookie_t cookie2;
	xcb_intern_atom_reply_t* atom_wm_delete_window;
#elif defined(VKF_SURFACE_XLIB)
	Display* display;
	Window window;
	Atom WM_PROTOCOLS;
	Atom WM_DELETE_WINDOW;
#elif defined(__ANDROID__)
	struct ANativeWindow* window;
#elif defined(VKF_SURFACE_WIN32)
	HINSTANCE hinstance;
	HWND hwnd;
#endif
} VkfWindow;

VKFAPI VkfResult vkfCreateWindow(VkfWindowCreateInfo* createInfo, VkfWindow** window);
#ifdef VKF_SURFACE_XCB
VKFAPI VkfResult vkfCreateWindowXCB(const char* title, uint32_t width, uint32_t height, xcb_connection_t* connection, xcb_window_t wnd, VkfWindow** window);
#elif defined(VKF_SURFACE_XLIB)
VKFAPI VkfResult vkfCreateWindowXLIB(const char* title, uint32_t width, uint32_t height, Display* display, Window wnd, VkfWindow** window);
#elif defined(VKF_SURFACE_WIN32)
VKFAPI VkfResult vkfCreateWindowWindows(const char* title, uint32_t width, uint32_t height, HINSTANCE instance, HWND hwnd, VkfWindow** window);
#endif
VKFAPI VkfResult vkfDestroyWindow(VkfWindow* window);
VKFAPI void vkfShowWindow(VkfWindow* window);
VKFAPI void vkfSetWindowInputFocus(VkfWindow* window);
VKFAPI uint32_t VkfPollWindowEvents(VkfWindow* window);

#ifdef __cplusplus
} //end extern "C"
#endif

#endif
