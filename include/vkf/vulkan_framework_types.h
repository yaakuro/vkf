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

#ifndef VULKAN_FRAMEWORK_TYPES_H
#define VULKAN_FRAMEWORK_TYPES_H

#define VKF_CHECK(A) assert(A)

#include <stdint.h>

#ifdef VKF_STATIC
#  define VKFAPI extern
#else
#  if defined(__WIN32__) || defined(__WINRT__)
#   ifdef VKF_BUILD_DLL
#      define VKFAPI __declspec(dllexport)
#   else
#      define VKFAPI __declspec(dllimport)
#   endif
#  elif defined(__GNUC__) && __GNUC__>=4
#   define VKFAPI extern __attribute__ ((visibility("default")))
#  elif defined(__SUNPRO_C) || defined(__SUNPRO_CC)
#   define VKFAPI extern __global
#  else
#   define VKFAPI extern
#  endif
#endif

#ifdef __APPLE__
	#ifdef TARGET_OS_IPHONE
		#define VK_USE_PLATFORM_IOS_MVK
	#elif defined(TARGET_OS_MAC)
		#define VK_USE_PLATFORM_MACOS_MVK
	#else
		#error "Unknown platform."
	#endif
#elif defined(__linux__)
	#ifdef __ANDROID__
		#define VK_USE_PLATFORM_ANDROID_KHR
	#elif defined(VKF_SURFACE_XCB)
		#define VK_USE_PLATFORM_XCB_KHR
	#elif defined(VKF_SURFACE_XLIB)
		#define VK_USE_PLATFORM_XLIB_KHR
	#elif defined(VKF_SURFACE_WAYLAND)
		#define VK_USE_PLATFORM_WAYLAND_KHR
	#endif
#elif defined(WIN32)
	#ifdef VKF_SURFACE_WIN32
		#define VK_USE_PLATFORM_WIN32_KHR
	#endif
#endif

#define VK_NO_PROTOTYPES
#include <vulkan/vulkan.h>

typedef enum VkfResult {
	VKF_SUCCESS,
	VKF_FAILED,
	VKF_MEMORY_ALLOCATION,
	VKF_PARAMETER_INVALID
} VkfResult;


#endif
