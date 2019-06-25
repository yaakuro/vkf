cmake_minimum_required(VERSION 3.11)

project(vkf VERSION 0.1.0 DESCRIPTION "Framework for Vulkan" LANGUAGES C CXX)

# This is only for codelite users. It will make targets seperate projects.
set(CMAKE_CODELITE_USE_TARGETS ON)

# Here we set if you want to use XLIB or XCB on GNUX.
set(SURFACE_EXTENSION_TO_USE "VKF_SURFACE_XLIB")

# Use -fPIC
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(VKF_STATIC 1)

#
# Set output directories.
#

if(NOT XDEVL_ARCH)
	if(UNIX)
		if(APPLE)
			set(XDEVL_ARCH "x86_64")
		elseif(ANDROID)
			set(XDEVL_ARCH "x86_64")
		else()
			set(XDEVL_ARCH "x86_64")
		endif()
	endif()
endif()

set(OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

if(UNIX)
	if(APPLE)
		set(OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}/mac/${XDEVL_ARCH})
		if(${XDEVL_ARCH} STREQUAL "x86")
			set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")
			set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m32")
		elseif(${XDEVL_ARCH} STREQUAL "x86_64")
			set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64")
			set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64")
		else()
			set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64")
			set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64")
		endif()
	elseif(ANDROID)
#		set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} --hash-style=both)
		if(CMAKE_BUILD_TYPE MATCHES Debug)
			set(OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}/android/debug/${ANDROID_ABI})
		else()
			set(OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}/android/release/${ANDROID_ABI})
		endif()
	else()
		set(OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}/linux/${XDEVL_ARCH})
		if(${XDEVL_ARCH} STREQUAL "x86")
			set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")
			set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m32")
		elseif(${XDEVL_ARCH} STREQUAL "x86_64")
			set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64")
			set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64")
		else()
			set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64")
			set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64")
		endif()
	endif()
elseif(MINGW)
	set(OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}/windows/${XDEVL_ARCH})
elseif(WIN32)
	set(OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}/windows/${XDEVL_ARCH})
endif()


if(NOT ANDROID)
	if(CMAKE_BUILD_TYPE MATCHES Debug)
		set(OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}/debug)
	else()
		set(OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}/release)
	endif()
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_DIRECTORY})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_DIRECTORY})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_DIRECTORY})

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_DIRECTORY})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_DIRECTORY})

set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_DIRECTORY})
set(EXECUTABLE_OUTPUT_PATH_DEBUG ${OUTPUT_DIRECTORY})
set(EXECUTABLE_OUTPUT_PATH_RELEASE ${OUTPUT_DIRECTORY})

if (VKF_STATIC EQUAL 1)
	add_library(vkf STATIC)
	add_library(vkfcpp STATIC)
else()
	add_library(vkf SHARED)
	add_library(vkfcpp SHARED)
endif()

target_sources(vkf
	PUBLIC 
		${CMAKE_CURRENT_SOURCE_DIR}/include/vkf/vulkan_framework_c.h 
		${CMAKE_CURRENT_SOURCE_DIR}/include/vkf/vulkan_framework_windows_c.h 
	PRIVATE 
		${CMAKE_CURRENT_SOURCE_DIR}/src/vulkan_framework_c.c 
		${CMAKE_CURRENT_SOURCE_DIR}/src/vulkan_framework_windows_c.c
)

target_sources(vkfcpp
	PUBLIC 
		${CMAKE_CURRENT_SOURCE_DIR}/include/vkf/vulkan_framework_types.h 
		${CMAKE_CURRENT_SOURCE_DIR}/include/vkf/vulkan_framework.h
		${CMAKE_CURRENT_SOURCE_DIR}/include/vkf/vulkan_framework_windows.h
	PRIVATE 
		${CMAKE_CURRENT_SOURCE_DIR}/src/vulkan_framework.cpp 
)

target_compile_definitions(vkf 
	PUBLIC
		$<$<PLATFORM_ID:Windows>:VKF_SURFACE_WIN32>
		$<$<PLATFORM_ID:Windows>:VKF_BUILD_DLL>
		$<$<PLATFORM_ID:Linux>:${SURFACE_EXTENSION_TO_USE}>
)

target_compile_definitions(vkfcpp 
	PUBLIC
		$<$<PLATFORM_ID:Windows>:VKF_BUILD_DLL>
)

target_compile_options(vkf 
	PRIVATE
		$<$<PLATFORM_ID:Linux>:-Wall>
		$<$<PLATFORM_ID:Linux>:-Wno-switch>
)

target_compile_options(vkfcpp 
	PRIVATE
		$<$<PLATFORM_ID:Linux>:-std=c++14 -pedantic -Wall>
)

target_include_directories(vkf 
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/thirdparty>
		$<INSTALL_INTERFACE:include>
)

target_include_directories(vkfcpp 
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/thirdparty>
		$<INSTALL_INTERFACE:include>
)

if(${SURFACE_EXTENSION_TO_USE} STREQUAL "VKF_SURFACE_XCB")
	target_link_libraries(vkf 
		PRIVATE
			$<$<PLATFORM_ID:Linux>:xcb>
			$<$<PLATFORM_ID:Linux>:xcb-keysyms>
			$<$<PLATFORM_ID:Linux>:dl>
	)
elseif(${SURFACE_EXTENSION_TO_USE} STREQUAL "VKF_SURFACE_XLIB")
	target_link_libraries(vkf 
		PRIVATE
			$<$<PLATFORM_ID:Linux>:X11>
			$<$<PLATFORM_ID:Linux>:dl>
			
	)
endif()

target_link_libraries(vkfcpp PRIVATE vkf)


