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

#ifndef VULKAN_FRAMEWORK_WINDOWS_H
#define VULKAN_FRAMEWORK_WINDOWS_H

#include <vkf/vulkan_framework_types.h>
#include <vkf/vulkan_framework_windows_c.h>

#include <string>

namespace vkf {

	/**
	 * @class Windows
	 * @brief Helper class to handle cross platform windowing.
	 */
	class Windows {
	public:
			Windows();
			Windows(const std::string& title, uint32_t width, uint32_t height);
			~Windows();

			/// Create the window.
			int init();
#ifdef VKF_SURFACE_XCB
			int init(xcb_connection_t* connection, xcb_window_t window);
#elif defined(VKF_SURFACE_XLIB)
			int init(Display* display, Window window);
#elif defined(VKF_SURFACE_WIN32)
			int init(HINSTANCE instance, HWND hwnd);
#endif

			int init(const std::string& title, uint32_t width, uint32_t height);
#ifdef VKF_SURFACE_XCB
			int init(const std::string& title, uint32_t width, uint32_t height, xcb_connection_t* connection, xcb_window_t window);
#elif defined(VKF_SURFACE_XLIB)
			int init(const std::string& title, uint32_t width, uint32_t height, Display* display, Window window);
#elif defined(VKF_SURFACE_WIN32)
			int init(const std::string& title, uint32_t width, uint32_t height, HINSTANCE instance, HWND hwnd);
#endif

			/// Destroy the window.
			int destroy();

			/// Set keyboard focus.
			void setInputFocus();

			/// Show the window.
			void show();

			/// Poll events.
			bool pollEvents();

			/// Returns the width of the window.
			uint32_t getWidth() const;

			/// Returns the height of the window.
			uint32_t getHeight() const;

			const std::string& getTitle() const;

#ifdef VKF_SURFACE_XCB
			/// Returns the native xcb connection handle.
			xcb_connection_t* getConnection() const;

			/// Return the native xcb window handle.
			xcb_window_t getWindow() const;

#elif defined(VKF_SURFACE_XLIB)

			/// Returns the native xcb connection handle.
			Display* getDisplay() const;

			/// Return the native xcb window handle.
			Window getWindow() const;

#elif defined(VKF_SURFACE_WIN32)
			HINSTANCE getInstance() const;

			HWND getHandle() const;
#endif

		VkfWindow* getVkfWindow() const;

		private:

		std::string m_title;
		uint32_t m_width;
		uint32_t m_height;

		VkfWindow* m_window;
	};
}
#endif
