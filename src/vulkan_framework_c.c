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

#include <vkf/vulkan_framework_c.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __linux__
#include <dlfcn.h>
#define VKF_FUNCTION_LOAD(LIBRARY, entrypoint) entrypoint = (PFN_##entrypoint)dlsym(LIBRARY, #entrypoint);
#elif defined(WIN32)
#include <windows.h>
#define VKF_FUNCTION_LOAD(LIBRARY, entrypoint) entrypoint = (PFN_##entrypoint)GetProcAddress((HMODULE)(LIBRARY), #entrypoint);
#endif

// -----------------------------------------------------------------------------
// Vulkan 1.0
//
#ifdef VK_NO_PROTOTYPES
VKF_FUNCTION_DEFINE(vkCreateInstance)
VKF_FUNCTION_DEFINE(vkDestroyInstance)
VKF_FUNCTION_DEFINE(vkEnumeratePhysicalDevices)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceFeatures)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceFormatProperties)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceImageFormatProperties)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceProperties)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceQueueFamilyProperties)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceMemoryProperties)
VKF_FUNCTION_DEFINE(vkGetInstanceProcAddr)
VKF_FUNCTION_DEFINE(vkGetDeviceProcAddr)
VKF_FUNCTION_DEFINE(vkCreateDevice)
VKF_FUNCTION_DEFINE(vkDestroyDevice)
VKF_FUNCTION_DEFINE(vkEnumerateInstanceExtensionProperties)
VKF_FUNCTION_DEFINE(vkEnumerateDeviceExtensionProperties)
VKF_FUNCTION_DEFINE(vkEnumerateInstanceLayerProperties)
VKF_FUNCTION_DEFINE(vkEnumerateDeviceLayerProperties)
VKF_FUNCTION_DEFINE(vkGetDeviceQueue)
VKF_FUNCTION_DEFINE(vkQueueSubmit)
VKF_FUNCTION_DEFINE(vkQueueWaitIdle)
VKF_FUNCTION_DEFINE(vkDeviceWaitIdle)
VKF_FUNCTION_DEFINE(vkAllocateMemory)
VKF_FUNCTION_DEFINE(vkFreeMemory)
VKF_FUNCTION_DEFINE(vkMapMemory)
VKF_FUNCTION_DEFINE(vkUnmapMemory)
VKF_FUNCTION_DEFINE(vkFlushMappedMemoryRanges)
VKF_FUNCTION_DEFINE(vkInvalidateMappedMemoryRanges)
VKF_FUNCTION_DEFINE(vkGetDeviceMemoryCommitment)
VKF_FUNCTION_DEFINE(vkBindBufferMemory)
VKF_FUNCTION_DEFINE(vkBindImageMemory)
VKF_FUNCTION_DEFINE(vkGetBufferMemoryRequirements)
VKF_FUNCTION_DEFINE(vkGetImageMemoryRequirements)
VKF_FUNCTION_DEFINE(vkGetImageSparseMemoryRequirements)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceSparseImageFormatProperties)
VKF_FUNCTION_DEFINE(vkQueueBindSparse)
VKF_FUNCTION_DEFINE(vkCreateFence)
VKF_FUNCTION_DEFINE(vkDestroyFence)
VKF_FUNCTION_DEFINE(vkResetFences)
VKF_FUNCTION_DEFINE(vkGetFenceStatus)
VKF_FUNCTION_DEFINE(vkWaitForFences)
VKF_FUNCTION_DEFINE(vkCreateSemaphore)
VKF_FUNCTION_DEFINE(vkDestroySemaphore)
VKF_FUNCTION_DEFINE(vkCreateEvent)
VKF_FUNCTION_DEFINE(vkDestroyEvent)
VKF_FUNCTION_DEFINE(vkGetEventStatus)
VKF_FUNCTION_DEFINE(vkSetEvent)
VKF_FUNCTION_DEFINE(vkResetEvent)
VKF_FUNCTION_DEFINE(vkCreateQueryPool)
VKF_FUNCTION_DEFINE(vkDestroyQueryPool)
VKF_FUNCTION_DEFINE(vkGetQueryPoolResults)
VKF_FUNCTION_DEFINE(vkCreateBuffer)
VKF_FUNCTION_DEFINE(vkDestroyBuffer)
VKF_FUNCTION_DEFINE(vkCreateBufferView)
VKF_FUNCTION_DEFINE(vkDestroyBufferView)
VKF_FUNCTION_DEFINE(vkCreateImage)
VKF_FUNCTION_DEFINE(vkDestroyImage)
VKF_FUNCTION_DEFINE(vkGetImageSubresourceLayout)
VKF_FUNCTION_DEFINE(vkCreateImageView)
VKF_FUNCTION_DEFINE(vkDestroyImageView)
VKF_FUNCTION_DEFINE(vkCreateShaderModule)
VKF_FUNCTION_DEFINE(vkDestroyShaderModule)
VKF_FUNCTION_DEFINE(vkCreatePipelineCache)
VKF_FUNCTION_DEFINE(vkDestroyPipelineCache)
VKF_FUNCTION_DEFINE(vkGetPipelineCacheData)
VKF_FUNCTION_DEFINE(vkMergePipelineCaches)
VKF_FUNCTION_DEFINE(vkCreateGraphicsPipelines)
VKF_FUNCTION_DEFINE(vkCreateComputePipelines)
VKF_FUNCTION_DEFINE(vkDestroyPipeline)
VKF_FUNCTION_DEFINE(vkCreatePipelineLayout)
VKF_FUNCTION_DEFINE(vkDestroyPipelineLayout)
VKF_FUNCTION_DEFINE(vkCreateSampler)
VKF_FUNCTION_DEFINE(vkDestroySampler)
VKF_FUNCTION_DEFINE(vkCreateDescriptorSetLayout)
VKF_FUNCTION_DEFINE(vkDestroyDescriptorSetLayout)
VKF_FUNCTION_DEFINE(vkCreateDescriptorPool)
VKF_FUNCTION_DEFINE(vkDestroyDescriptorPool)
VKF_FUNCTION_DEFINE(vkResetDescriptorPool)
VKF_FUNCTION_DEFINE(vkAllocateDescriptorSets)
VKF_FUNCTION_DEFINE(vkFreeDescriptorSets)
VKF_FUNCTION_DEFINE(vkUpdateDescriptorSets)
VKF_FUNCTION_DEFINE(vkCreateFramebuffer)
VKF_FUNCTION_DEFINE(vkDestroyFramebuffer)
VKF_FUNCTION_DEFINE(vkCreateRenderPass)
VKF_FUNCTION_DEFINE(vkDestroyRenderPass)
VKF_FUNCTION_DEFINE(vkGetRenderAreaGranularity)
VKF_FUNCTION_DEFINE(vkCreateCommandPool)
VKF_FUNCTION_DEFINE(vkDestroyCommandPool)
VKF_FUNCTION_DEFINE(vkResetCommandPool)
VKF_FUNCTION_DEFINE(vkAllocateCommandBuffers)
VKF_FUNCTION_DEFINE(vkFreeCommandBuffers)
VKF_FUNCTION_DEFINE(vkBeginCommandBuffer)
VKF_FUNCTION_DEFINE(vkEndCommandBuffer)
VKF_FUNCTION_DEFINE(vkResetCommandBuffer)
VKF_FUNCTION_DEFINE(vkCmdBindPipeline)
VKF_FUNCTION_DEFINE(vkCmdSetViewport)
VKF_FUNCTION_DEFINE(vkCmdSetScissor)
VKF_FUNCTION_DEFINE(vkCmdSetLineWidth)
VKF_FUNCTION_DEFINE(vkCmdSetDepthBias)
VKF_FUNCTION_DEFINE(vkCmdSetBlendConstants)
VKF_FUNCTION_DEFINE(vkCmdSetDepthBounds)
VKF_FUNCTION_DEFINE(vkCmdSetStencilCompareMask)
VKF_FUNCTION_DEFINE(vkCmdSetStencilWriteMask)
VKF_FUNCTION_DEFINE(vkCmdSetStencilReference)
VKF_FUNCTION_DEFINE(vkCmdBindDescriptorSets)
VKF_FUNCTION_DEFINE(vkCmdBindIndexBuffer)
VKF_FUNCTION_DEFINE(vkCmdBindVertexBuffers)
VKF_FUNCTION_DEFINE(vkCmdDraw)
VKF_FUNCTION_DEFINE(vkCmdDrawIndexed)
VKF_FUNCTION_DEFINE(vkCmdDrawIndirect)
VKF_FUNCTION_DEFINE(vkCmdDrawIndexedIndirect)
VKF_FUNCTION_DEFINE(vkCmdDispatch)
VKF_FUNCTION_DEFINE(vkCmdDispatchIndirect)
VKF_FUNCTION_DEFINE(vkCmdCopyBuffer)
VKF_FUNCTION_DEFINE(vkCmdCopyImage)
VKF_FUNCTION_DEFINE(vkCmdBlitImage)
VKF_FUNCTION_DEFINE(vkCmdCopyBufferToImage)
VKF_FUNCTION_DEFINE(vkCmdCopyImageToBuffer)
VKF_FUNCTION_DEFINE(vkCmdUpdateBuffer)
VKF_FUNCTION_DEFINE(vkCmdFillBuffer)
VKF_FUNCTION_DEFINE(vkCmdClearColorImage)
VKF_FUNCTION_DEFINE(vkCmdClearDepthStencilImage)
VKF_FUNCTION_DEFINE(vkCmdClearAttachments)
VKF_FUNCTION_DEFINE(vkCmdResolveImage)
VKF_FUNCTION_DEFINE(vkCmdSetEvent)
VKF_FUNCTION_DEFINE(vkCmdResetEvent)
VKF_FUNCTION_DEFINE(vkCmdWaitEvents)
VKF_FUNCTION_DEFINE(vkCmdPipelineBarrier)
VKF_FUNCTION_DEFINE(vkCmdBeginQuery)
VKF_FUNCTION_DEFINE(vkCmdEndQuery)
VKF_FUNCTION_DEFINE(vkCmdResetQueryPool)
VKF_FUNCTION_DEFINE(vkCmdWriteTimestamp)
VKF_FUNCTION_DEFINE(vkCmdCopyQueryPoolResults)
VKF_FUNCTION_DEFINE(vkCmdPushConstants)
VKF_FUNCTION_DEFINE(vkCmdBeginRenderPass)
VKF_FUNCTION_DEFINE(vkCmdNextSubpass)
VKF_FUNCTION_DEFINE(vkCmdEndRenderPass)
VKF_FUNCTION_DEFINE(vkCmdExecuteCommands)
#endif

// -----------------------------------------------------------------------------
// Vulkan 1.1
//
#ifdef VK_NO_PROTOTYPES
VKF_FUNCTION_DEFINE(vkEnumerateInstanceVersion)
VKF_FUNCTION_DEFINE(vkBindBufferMemory2)
VKF_FUNCTION_DEFINE(vkBindImageMemory2)
VKF_FUNCTION_DEFINE(vkGetDeviceGroupPeerMemoryFeatures)
VKF_FUNCTION_DEFINE(vkCmdSetDeviceMask)
VKF_FUNCTION_DEFINE(vkCmdDispatchBase)
VKF_FUNCTION_DEFINE(vkEnumeratePhysicalDeviceGroups)
VKF_FUNCTION_DEFINE(vkGetImageMemoryRequirements2)
VKF_FUNCTION_DEFINE(vkGetBufferMemoryRequirements2)
VKF_FUNCTION_DEFINE(vkGetImageSparseMemoryRequirements2)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceFeatures2)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceProperties2)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceFormatProperties2)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceImageFormatProperties2)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceQueueFamilyProperties2)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceMemoryProperties2)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceSparseImageFormatProperties2)
VKF_FUNCTION_DEFINE(vkTrimCommandPool)
VKF_FUNCTION_DEFINE(vkGetDeviceQueue2)
VKF_FUNCTION_DEFINE(vkCreateSamplerYcbcrConversion)
VKF_FUNCTION_DEFINE(vkDestroySamplerYcbcrConversion)
VKF_FUNCTION_DEFINE(vkCreateDescriptorUpdateTemplate)
VKF_FUNCTION_DEFINE(vkDestroyDescriptorUpdateTemplate)
VKF_FUNCTION_DEFINE(vkUpdateDescriptorSetWithTemplate)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceExternalBufferProperties)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceExternalFenceProperties)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceExternalSemaphoreProperties)
VKF_FUNCTION_DEFINE(vkGetDescriptorSetLayoutSupport)
#endif

// -----------------------------------------------------------------------------
// KHR Swapchain
//
#ifdef VK_NO_PROTOTYPES
VKF_FUNCTION_DEFINE(vkCreateSwapchainKHR)
VKF_FUNCTION_DEFINE(vkDestroySwapchainKHR)
VKF_FUNCTION_DEFINE(vkGetSwapchainImagesKHR)
VKF_FUNCTION_DEFINE(vkAcquireNextImageKHR)
VKF_FUNCTION_DEFINE(vkQueuePresentKHR)
VKF_FUNCTION_DEFINE(vkGetDeviceGroupPresentCapabilitiesKHR)
VKF_FUNCTION_DEFINE(vkGetDeviceGroupSurfacePresentModesKHR)
VKF_FUNCTION_DEFINE(vkGetPhysicalDevicePresentRectanglesKHR)
VKF_FUNCTION_DEFINE(vkAcquireNextImage2KHR)
#endif

// -----------------------------------------------------------------------------
// KHR Surface
//
#ifdef VK_NO_PROTOTYPES
VKF_FUNCTION_DEFINE(vkDestroySurfaceKHR)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceSurfaceSupportKHR)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceSurfaceCapabilitiesKHR)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceSurfaceFormatsKHR)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceSurfacePresentModesKHR)
#endif

// -----------------------------------------------------------------------------
// KHR Display
//
#ifdef VK_NO_PROTOTYPES
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceDisplayPropertiesKHR)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceDisplayPlanePropertiesKHR)
VKF_FUNCTION_DEFINE(vkGetDisplayPlaneSupportedDisplaysKHR)
VKF_FUNCTION_DEFINE(vkGetDisplayModePropertiesKHR)
VKF_FUNCTION_DEFINE(vkCreateDisplayModeKHR)
VKF_FUNCTION_DEFINE(vkGetDisplayPlaneCapabilitiesKHR)
VKF_FUNCTION_DEFINE(vkCreateDisplayPlaneSurfaceKHR)
#endif

// -----------------------------------------------------------------------------
// KHR Display Swapchain
//
#ifdef VK_NO_PROTOTYPES
VKF_FUNCTION_DEFINE(vkCreateSharedSwapchainsKHR)
#endif

// -----------------------------------------------------------------------------
// KHR Multiview
//
#ifdef VK_NO_PROTOTYPES
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceFeatures2KHR)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceProperties2KHR)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceFormatProperties2KHR)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceImageFormatProperties2KHR)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceQueueFamilyProperties2KHR)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceMemoryProperties2KHR)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceSparseImageFormatProperties2KHR)
#endif

// -----------------------------------------------------------------------------
// KHR Xcb Surface
//
#if defined(VK_USE_PLATFORM_XCB_KHR) && defined(VK_NO_PROTOTYPES)
VKF_FUNCTION_DEFINE(vkCreateXcbSurfaceKHR)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceXcbPresentationSupportKHR)
#endif

// -----------------------------------------------------------------------------
// KHR Xlib Surface
//
#if defined(VK_USE_PLATFORM_XLIB_KHR) && defined(VK_NO_PROTOTYPES)
VKF_FUNCTION_DEFINE(vkCreateXlibSurfaceKHR)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceXlibPresentationSupportKHR)
#endif

// -----------------------------------------------------------------------------
// KHR Win32 Surface
//
#if defined(VK_USE_PLATFORM_WIN32_KHR) && defined(VK_NO_PROTOTYPES)
VKF_FUNCTION_DEFINE(vkCreateWin32SurfaceKHR)
VKF_FUNCTION_DEFINE(vkGetPhysicalDeviceWin32PresentationSupportKHR)
#endif

// -----------------------------------------------------------------------------
// KHR Android Surface
//
#if defined(VK_USE_PLATFORM_ANDROID_KHR) && defined(VK_NO_PROTOTYPES)
VKF_FUNCTION_DEFINE(vkCreateAndroidSurfaceKHR)
#endif

// -----------------------------------------------------------------------------
// KHR MacOS Surface
//
#if defined(VK_USE_PLATFORM_MACOS_MVK) && defined(VK_NO_PROTOTYPES)
VKF_FUNCTION_DEFINE(vkCreateMacOSSurfaceMVK)
#endif

// -----------------------------------------------------------------------------
// KHR IOS Surface
//
#if defined(VK_USE_PLATFORM_IOS_MVK) && defined(VK_NO_PROTOTYPES)
VKF_FUNCTION_DEFINE(vkCreateIOSSurfaceMVK)
#endif

static void* sharedLibrary = NULL;

void vkfLoadVulkanLibrary() {
#ifdef __linux__
	sharedLibrary = dlopen("libvulkan.so.1", RTLD_NOW | RTLD_LOCAL);
	if(sharedLibrary == NULL) {
		assert(0 && "Can open libvulkan.so.1");
	}
#elif defined(WIN32)
	sharedLibrary = LoadLibraryA("vulkan-1.dll");
	if(sharedLibrary == NULL) {
		assert(0 && "Can open vulkan-1.dll");
	}
#endif
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetInstanceProcAddr)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetInstanceProcAddr)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCreateInstance)
	VKF_FUNCTION_LOAD(sharedLibrary, vkDestroyInstance)
	VKF_FUNCTION_LOAD(sharedLibrary, vkEnumeratePhysicalDevices)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceProperties)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceFormatProperties)
	VKF_FUNCTION_LOAD(sharedLibrary, vkEnumerateInstanceExtensionProperties)
	VKF_FUNCTION_LOAD(sharedLibrary, vkEnumerateInstanceLayerProperties)
	VKF_FUNCTION_LOAD(sharedLibrary, vkEnumerateDeviceLayerProperties)
	VKF_FUNCTION_LOAD(sharedLibrary, vkEnumerateDeviceExtensionProperties)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceQueueFamilyProperties)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceFeatures)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceMemoryProperties)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceImageFormatProperties)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCreateDevice)
	VKF_FUNCTION_LOAD(sharedLibrary, vkDestroyDevice)
	VKF_FUNCTION_LOAD(sharedLibrary, vkDeviceWaitIdle)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCreateCommandPool)
	VKF_FUNCTION_LOAD(sharedLibrary, vkResetCommandPool)
	VKF_FUNCTION_LOAD(sharedLibrary, vkDestroyCommandPool)
	VKF_FUNCTION_LOAD(sharedLibrary, vkAllocateCommandBuffers)
	VKF_FUNCTION_LOAD(sharedLibrary, vkBeginCommandBuffer)
	VKF_FUNCTION_LOAD(sharedLibrary, vkEndCommandBuffer)
	VKF_FUNCTION_LOAD(sharedLibrary, vkFreeCommandBuffers)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCreateSemaphore)
	VKF_FUNCTION_LOAD(sharedLibrary, vkDestroySemaphore)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCreateFence)
	VKF_FUNCTION_LOAD(sharedLibrary, vkDestroyFence)
	VKF_FUNCTION_LOAD(sharedLibrary, vkResetFences)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetFenceStatus)
	VKF_FUNCTION_LOAD(sharedLibrary, vkWaitForFences)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCreateEvent)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdPipelineBarrier)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetDeviceQueue)
	VKF_FUNCTION_LOAD(sharedLibrary, vkQueueSubmit)
	VKF_FUNCTION_LOAD(sharedLibrary, vkQueueWaitIdle)
	VKF_FUNCTION_LOAD(sharedLibrary, vkDestroySurfaceKHR)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCreateRenderPass)
	VKF_FUNCTION_LOAD(sharedLibrary, vkDestroyRenderPass)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdBeginRenderPass)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdEndRenderPass)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetDeviceProcAddr)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCreateImageView)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCreateFramebuffer)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCreateImage)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetImageMemoryRequirements)
	VKF_FUNCTION_LOAD(sharedLibrary, vkAllocateMemory)
	VKF_FUNCTION_LOAD(sharedLibrary, vkBindImageMemory)
	VKF_FUNCTION_LOAD(sharedLibrary, vkDestroyFramebuffer)
	VKF_FUNCTION_LOAD(sharedLibrary, vkDestroyImageView)
	VKF_FUNCTION_LOAD(sharedLibrary, vkFreeMemory)
	VKF_FUNCTION_LOAD(sharedLibrary, vkDestroyImage)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCreateBuffer)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetBufferMemoryRequirements)
	VKF_FUNCTION_LOAD(sharedLibrary, vkBindBufferMemory)
	VKF_FUNCTION_LOAD(sharedLibrary, vkMapMemory)
	VKF_FUNCTION_LOAD(sharedLibrary, vkUnmapMemory)
	VKF_FUNCTION_LOAD(sharedLibrary, vkFlushMappedMemoryRanges)
	VKF_FUNCTION_LOAD(sharedLibrary, vkInvalidateMappedMemoryRanges)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetDeviceMemoryCommitment)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetImageSparseMemoryRequirements)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceSparseImageFormatProperties)
	VKF_FUNCTION_LOAD(sharedLibrary, vkQueueBindSparse)
	VKF_FUNCTION_LOAD(sharedLibrary, vkDestroyBuffer)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCreateDescriptorSetLayout)
	VKF_FUNCTION_LOAD(sharedLibrary, vkDestroyDescriptorSetLayout)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCreateDescriptorPool)
	VKF_FUNCTION_LOAD(sharedLibrary, vkDestroyDescriptorPool)
	VKF_FUNCTION_LOAD(sharedLibrary, vkAllocateDescriptorSets)
	VKF_FUNCTION_LOAD(sharedLibrary, vkUpdateDescriptorSets)
	VKF_FUNCTION_LOAD(sharedLibrary, vkFreeDescriptorSets)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCreatePipelineCache)
	VKF_FUNCTION_LOAD(sharedLibrary, vkDestroyPipelineCache)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCreateShaderModule)
	VKF_FUNCTION_LOAD(sharedLibrary, vkDestroyShaderModule)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetImageSubresourceLayout)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCreateSampler)
	VKF_FUNCTION_LOAD(sharedLibrary, vkDestroySampler)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCreatePipelineLayout)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCreateGraphicsPipelines)
	VKF_FUNCTION_LOAD(sharedLibrary, vkDestroyPipelineLayout)
	VKF_FUNCTION_LOAD(sharedLibrary, vkDestroyPipeline)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdCopyBufferToImage)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdSetViewport)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdSetScissor)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdBindPipeline)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdBindVertexBuffers)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdBindDescriptorSets)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdBindIndexBuffer)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdDrawIndexed)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdDraw)
	VKF_FUNCTION_LOAD(sharedLibrary, vkDestroyEvent)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetEventStatus)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdDrawIndirect)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdDrawIndexedIndirect)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdDispatch)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdDispatchIndirect)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdCopyBuffer)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdCopyImage)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdBlitImage)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdCopyBufferToImage)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdCopyImageToBuffer)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdUpdateBuffer)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdFillBuffer)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdClearColorImage)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdClearDepthStencilImage)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdClearAttachments)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdResolveImage)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdSetEvent)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdResetEvent)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdWaitEvents)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdPipelineBarrier)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdBeginQuery)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdEndQuery)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdResetQueryPool)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdWriteTimestamp)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdCopyQueryPoolResults)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdPushConstants)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdBeginRenderPass)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdNextSubpass)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdEndRenderPass)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdExecuteCommands)

// -----------------------------------------------------------------------------
// KHR Swapchain
//
#ifdef VK_NO_PROTOTYPES
	VKF_FUNCTION_LOAD(sharedLibrary, vkCreateSwapchainKHR)
	VKF_FUNCTION_LOAD(sharedLibrary, vkDestroySwapchainKHR)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetSwapchainImagesKHR)
	VKF_FUNCTION_LOAD(sharedLibrary, vkAcquireNextImageKHR)
	VKF_FUNCTION_LOAD(sharedLibrary, vkQueuePresentKHR)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetDeviceGroupPresentCapabilitiesKHR)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetDeviceGroupSurfacePresentModesKHR)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDevicePresentRectanglesKHR)
	VKF_FUNCTION_LOAD(sharedLibrary, vkAcquireNextImage2KHR)
#endif

// -----------------------------------------------------------------------------
// KHR Surface
//
#ifdef VK_NO_PROTOTYPES
	VKF_FUNCTION_LOAD(sharedLibrary, vkDestroySurfaceKHR)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceSurfaceSupportKHR)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceSurfaceCapabilitiesKHR)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceSurfaceFormatsKHR)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceSurfacePresentModesKHR)
#endif

// -----------------------------------------------------------------------------
// KHR Xcb Surface
//
#if defined(VK_USE_PLATFORM_XCB_KHR) && defined(VK_NO_PROTOTYPES)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCreateXcbSurfaceKHR)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceXcbPresentationSupportKHR)
#endif

// -----------------------------------------------------------------------------
// KHR Xlib Surface
//
#if defined(VK_USE_PLATFORM_XLIB_KHR) && defined(VK_NO_PROTOTYPES)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCreateXlibSurfaceKHR)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceXlibPresentationSupportKHR)
#endif

// -----------------------------------------------------------------------------
// KHR Win32 Surface
//
#if defined(VK_USE_PLATFORM_WIN32_KHR) && defined(VK_NO_PROTOTYPES)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCreateWin32SurfaceKHR)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceWin32PresentationSupportKHR)
#endif

// -----------------------------------------------------------------------------
// KHR Android Surface
//
#if defined(VK_USE_PLATFORM_ANDROID_KHR) && defined(VK_NO_PROTOTYPES)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCreateAndroidSurfaceKHR)
#endif

// -----------------------------------------------------------------------------
// KHR MacOS Surface
//
#if defined(VK_USE_PLATFORM_MACOS_MVK) && defined(VK_NO_PROTOTYPES)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCreateMacOSSurfaceMVK)
#endif

// -----------------------------------------------------------------------------
// KHR IOS Surface
//
#if defined(VK_USE_PLATFORM_IOS_MVK) && defined(VK_NO_PROTOTYPES)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCreateIOSSurfaceMVK)
#endif


// -----------------------------------------------------------------------------
// Vulkan 1.1
//
#ifdef VK_NO_PROTOTYPES
	VKF_FUNCTION_LOAD(sharedLibrary, vkEnumerateInstanceVersion)
	VKF_FUNCTION_LOAD(sharedLibrary, vkBindBufferMemory2)
	VKF_FUNCTION_LOAD(sharedLibrary, vkBindImageMemory2)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetDeviceGroupPeerMemoryFeatures)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdSetDeviceMask)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCmdDispatchBase)
	VKF_FUNCTION_LOAD(sharedLibrary, vkEnumeratePhysicalDeviceGroups)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetImageMemoryRequirements2)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetBufferMemoryRequirements2)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetImageSparseMemoryRequirements2)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceFeatures2)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceProperties2)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceFormatProperties2)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceImageFormatProperties2)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceQueueFamilyProperties2)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceMemoryProperties2)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceSparseImageFormatProperties2)
	VKF_FUNCTION_LOAD(sharedLibrary, vkTrimCommandPool)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetDeviceQueue2)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCreateSamplerYcbcrConversion)
	VKF_FUNCTION_LOAD(sharedLibrary, vkDestroySamplerYcbcrConversion)
	VKF_FUNCTION_LOAD(sharedLibrary, vkCreateDescriptorUpdateTemplate)
	VKF_FUNCTION_LOAD(sharedLibrary, vkDestroyDescriptorUpdateTemplate)
	VKF_FUNCTION_LOAD(sharedLibrary, vkUpdateDescriptorSetWithTemplate)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceExternalBufferProperties)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceExternalFenceProperties)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceExternalSemaphoreProperties)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetDescriptorSetLayoutSupport)

	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceFeatures2KHR)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceProperties2KHR)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceFormatProperties2KHR)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceImageFormatProperties2KHR)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceQueueFamilyProperties2KHR)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceMemoryProperties2KHR)
	VKF_FUNCTION_LOAD(sharedLibrary, vkGetPhysicalDeviceSparseImageFormatProperties2KHR)

#endif

}

VkSurfaceFormatKHR preferedColorFormat = {VK_FORMAT_UNDEFINED, VK_COLOR_SPACE_SRGB_NONLINEAR_KHR};

VKFAPI void vkfInit() {
	vkfLoadVulkanLibrary();
}

VKFAPI void vkfDestroy() {
#ifdef __linux__
	if(NULL != sharedLibrary) {
		dlclose(sharedLibrary);
		sharedLibrary = NULL;
	}
#elif defined(WIN32)
	if(NULL != sharedLibrary) {
		FreeLibrary((HMODULE)sharedLibrary);
		sharedLibrary = NULL;
	}
#endif
}

VKFAPI uint32_t vkfBytesPerPixelFromFormat(VkFormat format) {
	switch(format) {
		case VK_FORMAT_B8G8R8A8_SINT:
		case VK_FORMAT_B8G8R8A8_UNORM:
		case VK_FORMAT_R8G8B8A8_SINT:
		case VK_FORMAT_R8G8B8A8_SNORM:
			return 4;
		case VK_FORMAT_R8G8B8_UINT:
		case VK_FORMAT_R8G8B8_UNORM:
		case VK_FORMAT_B8G8R8_UINT:
		case VK_FORMAT_B8G8R8_UNORM:
			return 3;
		case VK_FORMAT_UNDEFINED:
			return 0;
	}
	return 0;
}

VKFAPI uint32_t vkfBitsPerPixelFromFormat(VkFormat format) {
	switch(format) {
		case VK_FORMAT_B8G8R8A8_SINT:
		case VK_FORMAT_B8G8R8A8_UNORM:
		case VK_FORMAT_R8G8B8A8_SINT:
		case VK_FORMAT_R8G8B8A8_SNORM:
			return 32;
		case VK_FORMAT_R8G8B8_UINT:
		case VK_FORMAT_R8G8B8_UNORM:
		case VK_FORMAT_B8G8R8_UINT:
		case VK_FORMAT_B8G8R8_UNORM:
			return 24;
		case VK_FORMAT_UNDEFINED:
			return 0;
	}
	return 0;
}

VKFAPI const char* vkfVkPresentModeKHRToString(VkPresentModeKHR presentMode) {
	switch(presentMode) {
		case VK_PRESENT_MODE_IMMEDIATE_KHR:
			return "VK_PRESENT_MODE_IMMEDIATE_KHR";
		case VK_PRESENT_MODE_MAILBOX_KHR:
			return "VK_PRESENT_MODE_MAILBOX_KHR";
		case VK_PRESENT_MODE_FIFO_KHR:
			return "VK_PRESENT_MODE_FIFO_KHR";
		case VK_PRESENT_MODE_FIFO_RELAXED_KHR:
			return "VK_PRESENT_MODE_FIFO_RELAXED_KHR";
		default:
			break;
	}
	return "VK_PRESENT_MODE_MAX_ENUM_KHR";
}

VKFAPI const char* vkfVkPhysicalDeviceTypeToString(VkPhysicalDeviceType physicalDeviceType) {
	switch(physicalDeviceType) {
		case VK_PHYSICAL_DEVICE_TYPE_OTHER:
			return "VK_PHYSICAL_DEVICE_TYPE_OTHER";
		case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU:
			return "VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU";
		case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:
			return "VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU";
		case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU:
			return "VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU";
		case VK_PHYSICAL_DEVICE_TYPE_CPU:
			return "VK_PHYSICAL_DEVICE_TYPE_CPU";
		default:
			break;
	}
	return "VK_PHYSICAL_DEVICE_TYPE_MAX_ENUM";
}

VKFAPI const char* vkfVkResultToString(VkResult result) {
	switch(result) {
		case VK_SUCCESS:
			return "VK_SUCCESS";
		case VK_NOT_READY:
			return "VK_NOT_READY";
		case VK_TIMEOUT:
			return "VK_TIMEOUT";
		case VK_EVENT_SET:
			return "VK_EVENT_SET";
		case VK_EVENT_RESET:
			return "VK_EVENT_RESET";
		case VK_INCOMPLETE:
			return "VK_INCOMPLETE";
		case VK_ERROR_OUT_OF_HOST_MEMORY:
			return "VK_ERROR_OUT_OF_HOST_MEMORY";
		case VK_ERROR_OUT_OF_DEVICE_MEMORY:
			return "VK_ERROR_OUT_OF_DEVICE_MEMORY";
		case VK_ERROR_INITIALIZATION_FAILED:
			return "VK_ERROR_INITIALIZATION_FAILED";
		case VK_ERROR_DEVICE_LOST:
			return "VK_ERROR_DEVICE_LOST";
		case VK_ERROR_MEMORY_MAP_FAILED:
			return "VK_ERROR_MEMORY_MAP_FAILED";
		case VK_ERROR_LAYER_NOT_PRESENT:
			return "VK_ERROR_LAYER_NOT_PRESENT";
		case VK_ERROR_EXTENSION_NOT_PRESENT:
			return "VK_ERROR_EXTENSION_NOT_PRESENT";
		case VK_ERROR_FEATURE_NOT_PRESENT:
			return "VK_ERROR_FEATURE_NOT_PRESENT";
		case VK_ERROR_INCOMPATIBLE_DRIVER:
			return "VK_ERROR_INCOMPATIBLE_DRIVER";
		case VK_ERROR_TOO_MANY_OBJECTS:
			return "VK_ERROR_TOO_MANY_OBJECTS";
		case VK_ERROR_FORMAT_NOT_SUPPORTED:
			return "VK_ERROR_FORMAT_NOT_SUPPORTED";
		case VK_ERROR_SURFACE_LOST_KHR:
			return "VK_ERROR_SURFACE_LOST_KHR";
		case VK_ERROR_NATIVE_WINDOW_IN_USE_KHR:
			return "VK_ERROR_NATIVE_WINDOW_IN_USE_KHR";
		case VK_SUBOPTIMAL_KHR:
			return "VK_SUBOPTIMAL_KHR";
		case VK_ERROR_OUT_OF_DATE_KHR:
			return "VK_ERROR_OUT_OF_DATE_KHR";
		case VK_ERROR_INCOMPATIBLE_DISPLAY_KHR:
			return "VK_ERROR_INCOMPATIBLE_DISPLAY_KHR";
		case VK_ERROR_VALIDATION_FAILED_EXT:
			return "VK_ERROR_VALIDATION_FAILED_EXT";
		case VK_RESULT_RANGE_SIZE:
			return "VK_RESULT_RANGE_SIZE";
		default:
			break;
	}
	return "VK_RESULT_MAX_ENUM";
}


VKFAPI void vkfSetImageLayout(VkCommandBuffer commandBuffer,
                              VkImage image,
                              VkImageAspectFlags aspectMask,
                              VkImageLayout oldImageLayout,
                              VkImageLayout newImageLayout) {
	// Create an image barrier object
	VkImageMemoryBarrier imageMemoryBarrier = {0};
	imageMemoryBarrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
	imageMemoryBarrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
	imageMemoryBarrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
	imageMemoryBarrier.oldLayout = oldImageLayout;
	imageMemoryBarrier.newLayout = newImageLayout;
	imageMemoryBarrier.image = image;
	imageMemoryBarrier.subresourceRange.aspectMask = aspectMask;
	imageMemoryBarrier.subresourceRange.baseMipLevel = 0;
	imageMemoryBarrier.subresourceRange.levelCount = 1;
	imageMemoryBarrier.subresourceRange.layerCount = 1;

	switch(oldImageLayout) {
		case VK_IMAGE_LAYOUT_UNDEFINED:
			// Image layout is undefined (or does not matter)
			// Only valid as initial layout
			// No flags required, listed only for completeness
			imageMemoryBarrier.srcAccessMask = 0;
			break;

		case VK_IMAGE_LAYOUT_PREINITIALIZED:
			// Image is preinitialized
			// Only valid as initial layout for linear images, preserves memory contents
			// Make sure host writes have been finished
			imageMemoryBarrier.srcAccessMask = VK_ACCESS_HOST_WRITE_BIT;
			break;

		case VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL:
			// Image is a color attachment
			// Make sure any writes to the color buffer have been finished
			imageMemoryBarrier.srcAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
			break;

		case VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL:
			// Image is a depth/stencil attachment
			// Make sure any writes to the depth/stencil buffer have been finished
			imageMemoryBarrier.srcAccessMask = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;
			break;

		case VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL:
			// Image is a transfer source
			// Make sure any reads from the image have been finished
			imageMemoryBarrier.srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
			break;

		case VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL:
			// Image is a transfer destination
			// Make sure any writes to the image have been finished
			imageMemoryBarrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
			break;

		case VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL:
			// Image is read by a shader
			// Make sure any shader reads from the image have been finished
			imageMemoryBarrier.srcAccessMask = VK_ACCESS_SHADER_READ_BIT;
			break;
		default:
			// Other source layouts aren't handled (yet)
			break;
	}

	// Target layouts (new)
	// Destination access mask controls the dependency for the new image layout
	switch(newImageLayout) {
		case VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL:
			// Image will be used as a transfer destination
			// Make sure any writes to the image have been finished
			imageMemoryBarrier.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
			break;

		case VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL:
			// Image will be used as a transfer source
			// Make sure any reads from the image have been finished
			imageMemoryBarrier.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
			break;

		case VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL:
			// Image will be used as a color attachment
			// Make sure any writes to the color buffer have been finished
			imageMemoryBarrier.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
			break;

		case VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL:
			// Image layout will be used as a depth/stencil attachment
			// Make sure any writes to depth/stencil buffer have been finished
			imageMemoryBarrier.dstAccessMask = imageMemoryBarrier.dstAccessMask | VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;
			break;

		case VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL:
			// Image will be read in a shader (sampler, input attachment)
			// Make sure any writes to the image have been finished
			if(imageMemoryBarrier.srcAccessMask == 0) {
				imageMemoryBarrier.srcAccessMask = VK_ACCESS_HOST_WRITE_BIT | VK_ACCESS_TRANSFER_WRITE_BIT;
			}
			imageMemoryBarrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
			break;
		default:
			// Other source layouts aren't handled (yet)
			break;
	}
	// Put barrier on top
	VkPipelineStageFlags srcStageFlags = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;
	VkPipelineStageFlags destStageFlags = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;

	// Put barrier inside setup command buffer
	vkCmdPipelineBarrier(commandBuffer, srcStageFlags, destStageFlags, 0, 0, NULL, 0, NULL, 1, &imageMemoryBarrier);
}

VKFAPI uint32_t getMemoryTypeIndex(VkPhysicalDeviceMemoryProperties deviceMemoryProperties, VkMemoryRequirements memoryRequirements, VkFlags properties) {
	for(uint32_t i = 0; i < deviceMemoryProperties.memoryTypeCount; i++) {
		if((memoryRequirements.memoryTypeBits & 1) == 1) {
			if((deviceMemoryProperties.memoryTypes[i].propertyFlags & properties) == properties) {
				return i;
			}
		}
		memoryRequirements.memoryTypeBits >>= 1;
	}
	return UINT32_MAX;
}

VKFAPI VkImageAspectFlags getImageAspectFlagBitsFromFormat(VkFormat format) {
	VkImageAspectFlags flags = VK_IMAGE_ASPECT_FLAG_BITS_MAX_ENUM;
	if(VK_FORMAT_D24_UNORM_S8_UINT == format) {
		flags = (VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT);
	} else if(VK_FORMAT_D16_UNORM == format) {
		flags = VK_IMAGE_ASPECT_DEPTH_BIT;
	} else if(VK_FORMAT_D16_UNORM_S8_UINT == format) {
		flags = VK_IMAGE_ASPECT_DEPTH_BIT;
	} else if(VK_FORMAT_D32_SFLOAT == format) {
		flags = VK_IMAGE_ASPECT_DEPTH_BIT;
	} else if(VK_FORMAT_D32_SFLOAT_S8_UINT == format) {
		flags = (VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT);
	} else {
		flags = VK_IMAGE_ASPECT_COLOR_BIT;
	}
	return flags;
}



PFN_vkCreateDebugReportCallbackEXT vkCreateDebugReportCallbackEXT;
PFN_vkDebugReportMessageEXT vkDebugReportMessageEXT;
PFN_vkDestroyDebugReportCallbackEXT vkDestroyDebugReportCallbackEXT;

VKAPI_ATTR VkBool32 VKAPI_CALL debugReportCallback(VkDebugReportFlagsEXT flags,
        VkDebugReportObjectTypeEXT objectType,
        uint64_t object,
        size_t location,
        int32_t messageCode,
        const char* pLayerPrefix,
        const char* pMessage,
        void* pUserData) {
	printf("VKF:LAYER: %s: %s\n", pLayerPrefix, pMessage);
	return VK_FALSE;
}

VKFAPI VkfResult vkfCreateDebug(VkfInstance* instance, VkfDebug** debug) {
	(*debug) = (VkfDebug*)malloc(sizeof(VkfDebug));

	GET_INSTANCE_PROC_ADDR(instance->instance, CreateDebugReportCallbackEXT);
	GET_INSTANCE_PROC_ADDR(instance->instance, DebugReportMessageEXT);
	GET_INSTANCE_PROC_ADDR(instance->instance, DestroyDebugReportCallbackEXT);

	VkDebugReportCallbackCreateInfoEXT callbackCreateInfo = {0};
	callbackCreateInfo.sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CREATE_INFO_EXT;
	callbackCreateInfo.flags = VK_DEBUG_REPORT_ERROR_BIT_EXT |
	                           VK_DEBUG_REPORT_WARNING_BIT_EXT |
	                           VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT |
	                           VK_DEBUG_REPORT_DEBUG_BIT_EXT;
	callbackCreateInfo.pfnCallback = &debugReportCallback;

	VkDebugReportCallbackEXT callback = VK_NULL_HANDLE;
	VkResult result = vkCreateDebugReportCallbackEXT(instance->instance, &callbackCreateInfo, NULL, &callback);
	if(VK_SUCCESS != result) {
		printf("vkCreateInstance failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}
	(*debug)->instance = instance->instance;
	(*debug)->callback = callback;

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfDestroyDebug(VkfDebug* debug) {
	vkDestroyDebugReportCallbackEXT(debug->instance, debug->callback, NULL);
	free(debug);

	return VKF_SUCCESS;
}


VKFAPI VkfResult  vkfCreateInstance(VkfInstanceCreateInfo* createInfo, VkfInstance** instance) {
	VkInstance vulkanInstance = VK_NULL_HANDLE;
	uint32_t instanceAPIVersion = 0;

	*instance = (VkfInstance*)malloc(sizeof(VkfInstance));
	if(NULL == *instance) {
		return VKF_FAILED;
	}

	if(createInfo->title) {
		(*instance)->title = (char*)malloc(sizeof(char) * (strlen(createInfo->title) + 1));
		memset((*instance)->title, '\0', sizeof(char) * strlen(createInfo->title) + 1);
		strcpy((*instance)->title, createInfo->title);
	}


	if(vkEnumerateInstanceVersion) {
		vkEnumerateInstanceVersion(&instanceAPIVersion);
		printf("Vulkan Instance Version: %d, %d, %d\n", VK_VERSION_MAJOR(instanceAPIVersion), VK_VERSION_MINOR(instanceAPIVersion), VK_VERSION_PATCH(instanceAPIVersion));
	}
	//
	// Let's create the Vulkan applications info. We will use it for the VKInstanceCreateInfo.
	//
	VkApplicationInfo applicationInfo = {0};
	applicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	applicationInfo.pNext = NULL;
	applicationInfo.pApplicationName = (*instance)->title;
	applicationInfo.applicationVersion = 0;
	applicationInfo.pEngineName = (*instance)->title;
	applicationInfo.engineVersion = 0;
	if(createInfo->apiVersion > 0) {
		applicationInfo.apiVersion = createInfo->apiVersion;
	} else {
		applicationInfo.apiVersion = VK_MAKE_VERSION(1,0,0);
	}

	uint32_t numberOfExtensions = 2;
	char* enabledExtensions [6];
	if(createInfo->enableDebuging) {
		numberOfExtensions = 4;
		enabledExtensions[2] = VK_EXT_DEBUG_REPORT_EXTENSION_NAME;
		enabledExtensions[3] = VK_EXT_DEBUG_UTILS_EXTENSION_NAME;
	}
	enabledExtensions[0] = VK_KHR_SURFACE_EXTENSION_NAME;
	enabledExtensions[1] =
#if defined(_WIN32)
	    VK_KHR_WIN32_SURFACE_EXTENSION_NAME;
#elif defined(__ANDROID__)
	    VK_KHR_ANDROID_SURFACE_EXTENSION_NAME;
#elif defined(VKF_SURFACE_XCB)
	    VK_KHR_XCB_SURFACE_EXTENSION_NAME;
#elif defined(VKF_SURFACE_XLIB)
	    VK_KHR_XLIB_SURFACE_EXTENSION_NAME;
#elif defined(VKF_SURFACE_WAYLAND)
	    VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME;
#elif defined(VKF_SURFACE_MIR)
	    VK_KHR_MIR_SURFACE_EXTENSION_NAME;
#endif

	const VkInstanceCreateInfo instanceCreateInfo = {
		VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
		NULL,
		0,
		&applicationInfo,
		createInfo->numberOfLayers,
		(const char *const *)&createInfo->layerNames,
		numberOfExtensions,
		(const char *const *)&enabledExtensions
	};

	//
	// Create the Vulkan instance.
	//
	VkResult result = vkCreateInstance(&instanceCreateInfo, NULL, &vulkanInstance);
	if(VK_SUCCESS != result) {
		printf("vkCreateInstance failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}


	(*instance)->instance = vulkanInstance;



	// -------------------------------------------------------------------------
	// Get all infos about available devices.
	//
	uint32_t deviceCount;
	result = vkEnumeratePhysicalDevices(vulkanInstance, &deviceCount, NULL);
	if(result != VK_SUCCESS) {
		printf("vkEnumeratePhysicalDevices failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}

	VkPhysicalDevice* physicalDevices = malloc(sizeof(VkPhysicalDevice) * deviceCount);
	result = vkEnumeratePhysicalDevices(vulkanInstance, &deviceCount, physicalDevices);
	if(result != VK_SUCCESS) {
		printf("vkEnumeratePhysicalDevices failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}
	(*instance)->numberOfPhysicalDevices = deviceCount;
	(*instance)->physicalDevices = physicalDevices;

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfDestroyInstance(VkfInstance* instance) {
	if(instance) {
		free(instance->title);
		free(instance->physicalDevices);
		vkDestroyInstance(instance->instance, NULL);
		free(instance);
	}

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfCreateDevice(VkfDeviceCreateInfo* createInfo, VkfDevice** device) {
	//
	// Get the physical device the user specified. Default is VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU.
	//
	uint32_t graphicsQueueIndex = UINT32_MAX;
	uint32_t maxQueueCount = UINT32_MAX;
	uint32_t queueFamilyCount = 0;
	VkPhysicalDevice foundPhysicalDevice = VK_NULL_HANDLE;
	VkQueueFamilyProperties* queueFamilyProperties = NULL;

	if(NULL == createInfo->instance) {
		printf("vkfCreateDevice: No valid instance specified.\n");
		return VKF_FAILED;
	}

	// If nothing specified we will look for a discrete GPU.
	if(VK_PHYSICAL_DEVICE_TYPE_OTHER == createInfo->physicalDeviceType) {
		createInfo->physicalDeviceType = VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU;
	}

	for(uint32_t i = 0; i < createInfo->instance->numberOfPhysicalDevices; i++) {
		VkPhysicalDeviceProperties physicalDeviceProperties = {0};
		vkGetPhysicalDeviceProperties(createInfo->instance->physicalDevices[i], &physicalDeviceProperties);

		if(physicalDeviceProperties.deviceType == createInfo->physicalDeviceType) {
			vkGetPhysicalDeviceQueueFamilyProperties(createInfo->instance->physicalDevices[i], &queueFamilyCount, NULL);

			queueFamilyProperties = (VkQueueFamilyProperties*)malloc(sizeof(VkQueueFamilyProperties) * queueFamilyCount);
			vkGetPhysicalDeviceQueueFamilyProperties(createInfo->instance->physicalDevices[i], &queueFamilyCount, queueFamilyProperties);

			// Get the index for the graphics queue.
			// TODO We have to change this later if the user wants to use the physical device other than as GFX device.
			for(uint32_t j = 0; j < queueFamilyCount; j++) {
				if((queueFamilyProperties[j].queueCount > 0) && (queueFamilyProperties[j].queueFlags & VK_QUEUE_GRAPHICS_BIT)) {
					graphicsQueueIndex = j;
					maxQueueCount = queueFamilyProperties[j].queueCount;
					foundPhysicalDevice = createInfo->instance->physicalDevices[i];
					goto finished;
				}
			}
			break;
		}
	}

finished:

	if(UINT32_MAX == graphicsQueueIndex) {
		printf("Couldn't find graphics queue index.\n");
		return VKF_FAILED;
	}

	//
	// Next step is to create the queue. For this we have to create first the info for it.
	//
	VkDeviceQueueCreateInfo deviceQueueInfo = {0};
	deviceQueueInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
	deviceQueueInfo.queueFamilyIndex = graphicsQueueIndex;
	deviceQueueInfo.queueCount = maxQueueCount;

	float* queuePriorities = (float*)malloc(sizeof(float) * maxQueueCount);
	for(uint32_t i = 0; i < maxQueueCount; i++) {
		queuePriorities[i] = 1.0f;
	}
	deviceQueueInfo.pQueuePriorities = queuePriorities;

	const char* enabledExtensions [] = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };
	VkDeviceCreateInfo deviceCreateInfo = {0};
	deviceCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;

	if(SIZE_OF_ARRAY(enabledExtensions) > 0) {
		deviceCreateInfo.enabledExtensionCount = SIZE_OF_ARRAY(enabledExtensions);
		deviceCreateInfo.ppEnabledExtensionNames = (const char *const *)enabledExtensions;
	}

	deviceCreateInfo.queueCreateInfoCount = 1;
	deviceCreateInfo.pQueueCreateInfos = &deviceQueueInfo;

	// TODO I have to come up with passing those informations.
	VkPhysicalDeviceFeatures physicalDeviceFeatures = {0};
	physicalDeviceFeatures.geometryShader = VK_TRUE;

	deviceCreateInfo.pEnabledFeatures = &physicalDeviceFeatures;

	VkDevice deviceHandle = VK_NULL_HANDLE;
	VkResult result = vkCreateDevice(foundPhysicalDevice, &deviceCreateInfo, NULL, &deviceHandle);
	if(VK_SUCCESS != result) {
		printf("vkCreateDevice failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}

	free(queuePriorities);

	(*device) = malloc(sizeof(VkfDevice));
	(*device)->device = deviceHandle;
	(*device)->physicalDevice = foundPhysicalDevice;
	(*device)->familyQueueIndex = graphicsQueueIndex;
	(*device)->maxFamilyQueueCount = maxQueueCount;
	(*device)->queueFamilyCount = queueFamilyCount;
	(*device)->queueFamilyProperties = queueFamilyProperties;
	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfDestroyDevice(VkfDevice* device) {
	vkDestroyDevice(device->device, NULL);
	free(device);

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfCreateSurface(VkfSurfaceCreateInfo* createInfo, VkfSurface** surface) {
	VkResult result = VK_RESULT_MAX_ENUM;
	VkSurfaceKHR surfaceHandle = VK_NULL_HANDLE;

	if(createInfo && (NULL == createInfo->instance)) {
		printf("vkfCreateSurface: No valid instance specified.\n");
		return VKF_FAILED;
	}

	if(NULL == createInfo->device) {
		printf("vkfCreateSurface: No valid device specified.\n");
		return VKF_FAILED;
	}

	if(NULL == createInfo->window) {
		printf("vkfCreateSurface: No valid window specified.\n");
		return VKF_FAILED;
	}

	(*surface) = (VkfSurface*)malloc(sizeof(VkfSurface));

#ifdef _WIN32
	VkWin32SurfaceCreateInfoKHR surfaceCreateInfo = {0};
	surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
	surfaceCreateInfo.hinstance = (HINSTANCE)createInfo->window->hinstance;
	surfaceCreateInfo.hwnd = (HWND)createInfo->window->hwnd;
	result = vkCreateWin32SurfaceKHR(createInfo->instance->instance, &surfaceCreateInfo, NULL, &surfaceHandle);
#elif defined(__ANDROID__)
	VkAndroidSurfaceCreateInfoKHR surfaceCreateInfo = {0};
	surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR;
	surfaceCreateInfo.window = createInfo->window->window;
	result = vkCreateAndroidSurfaceKHR(createInfo->instance->instance, &surfaceCreateInfo, NULL, &surfaceHandle);
#elif defined(VKF_SURFACE_XCB)
	VkXcbSurfaceCreateInfoKHR surfaceCreateInfo = { VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR, NULL, 0, createInfo->window->connection, createInfo->window->window};
	result = vkCreateXcbSurfaceKHR(createInfo->instance->instance, &surfaceCreateInfo, NULL, &surfaceHandle);
#elif defined(VKF_SURFACE_XLIB)
	VkXlibSurfaceCreateInfoKHR surfaceCreateInfo = { VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR, NULL, 0, createInfo->window->display, createInfo->window->window };
	result = vkCreateXlibSurfaceKHR(createInfo->instance->instance, &surfaceCreateInfo, NULL, &surfaceHandle);
#else
//#error "Vulkan Surface Platform not supported."
#endif
	if(VK_SUCCESS != result) {
		printf("vkCreateSurfaceKHR failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}

	// Search for a graphics and a present queue in the array of queue
	// families, try to find one that supports both
	uint32_t m_queueIndex = 0;
	for(uint32_t i = 0; i < createInfo->device->queueFamilyCount; i++) {

		VkBool32 supported = VK_FALSE;

		VkResult result = vkGetPhysicalDeviceSurfaceSupportKHR(createInfo->device->physicalDevice, i, surfaceHandle, &supported);
		if(VK_SUCCESS != result) {
			printf("vkGetPhysicalDeviceSurfaceSupportKHR failed: %s\n", vkfVkResultToString(result));
			return VKF_FAILED;
		}

		if(supported && (createInfo->device->queueFamilyProperties[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) && (createInfo->device->queueFamilyProperties[i].queueCount > m_queueIndex)) {
			(*surface)->queueFamilyIndex = i;
		}
	}



	// -------------------------------------------------------------------------
	// Get list of supported surface formats and choose one.
	//
	uint32_t formatCount;
	result = vkGetPhysicalDeviceSurfaceFormatsKHR(createInfo->device->physicalDevice, surfaceHandle, &formatCount, NULL);
	if(VK_SUCCESS != result) {
		printf("vkGetPhysicalDeviceSurfaceFormatsKHR failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}

	VkSurfaceFormatKHR* surfaceFormats = (VkSurfaceFormatKHR*)malloc(sizeof(VkSurfaceFormatKHR) * formatCount);
	result = vkGetPhysicalDeviceSurfaceFormatsKHR(createInfo->device->physicalDevice, surfaceHandle, &formatCount, surfaceFormats);
	if(VK_SUCCESS != result) {
		free(surfaceFormats);
		printf("vkGetPhysicalDeviceSurfaceFormatsKHR failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}

	VkFormat colorFormat = VK_FORMAT_UNDEFINED;
	VkColorSpaceKHR colorSpace = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;

	// If we have only one format count and it is VK_FORMAT_UNDEFINED
	if((formatCount == 1) && (surfaceFormats[0].format == VK_FORMAT_UNDEFINED)) {
		if(preferedColorFormat.format != VK_FORMAT_UNDEFINED) {
			colorFormat = preferedColorFormat.format;
			colorSpace = preferedColorFormat.colorSpace;
		} else {
			colorFormat = VK_FORMAT_B8G8R8A8_UNORM;
			colorSpace = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
		}

	} else {
		// Always select the first available color format
		// If you need a specific format (e.g. SRGB) you'd need to
		// iterate over the list of available surface format and
		// check for it's presence
		colorFormat = surfaceFormats[0].format;
		colorSpace = surfaceFormats[0].colorSpace;
	}

	// -------------------------------------------------------------------------


	// -------------------------------------------------------------------------
	// Get physical device surface properties and formats.
	//
	VkSurfaceCapabilitiesKHR surfaceCaps;
	result = vkGetPhysicalDeviceSurfaceCapabilitiesKHR(createInfo->device->physicalDevice, surfaceHandle, &surfaceCaps);
	if(VK_SUCCESS != result) {
		printf("vkGetPhysicalDeviceSurfaceCapabilitiesKHR failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}

	VkExtent2D extent2D;
	if(surfaceCaps.currentExtent.width != UINT32_MAX) {
		extent2D.width = surfaceCaps.currentExtent.width;
		extent2D.height = surfaceCaps.currentExtent.height;
	}
	// -------------------------------------------------------------------------


	// -------------------------------------------------------------------------
	// Get the number of Present Modes. (That is how stuff are drawn like using VSYNC or not ...)
	//
	uint32_t presentModeCount = 0;
	result = vkGetPhysicalDeviceSurfacePresentModesKHR(createInfo->device->physicalDevice, surfaceHandle, &presentModeCount, NULL);
	if(VK_SUCCESS != result) {
		printf("vkGetPhysicalDeviceSurfacePresentModesKHR failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}

	// Use the number of modes and create an array of modes.
	VkPresentModeKHR* presentModes = (VkPresentModeKHR*)malloc(sizeof(VkPresentModeKHR) * presentModeCount);
	result = vkGetPhysicalDeviceSurfacePresentModesKHR(createInfo->device->physicalDevice, surfaceHandle, &presentModeCount, presentModes);
	if(VK_SUCCESS != result) {
		printf("vkGetPhysicalDeviceSurfacePresentModesKHR failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}

	//
	// Select the Present mode we prefer. If not supported then use the default one that is supported.
	//
	VkPresentModeKHR presentMode = VK_PRESENT_MODE_FIFO_KHR;
	for(uint32_t i = 0; i < presentModeCount; i++) {

		// We will try to use the Present Mode that waits for VSYNC.
		if(presentModes[i] == VK_PRESENT_MODE_MAILBOX_KHR) {
			presentMode = VK_PRESENT_MODE_MAILBOX_KHR;
			break;
		}

		if(presentModes[i] == VK_PRESENT_MODE_FIFO_RELAXED_KHR) {
			presentMode = VK_PRESENT_MODE_FIFO_RELAXED_KHR;
			break;
		}

		if((presentMode != VK_PRESENT_MODE_MAILBOX_KHR) && (presentModes[i] == VK_PRESENT_MODE_IMMEDIATE_KHR)) {
			presentMode = VK_PRESENT_MODE_IMMEDIATE_KHR;
		}
	}
	// -------------------------------------------------------------------------


	(*surface)->instance = createInfo->instance->instance;
	(*surface)->surface = surfaceHandle;
	(*surface)->colorFormat = colorFormat;
	(*surface)->colorSpace = colorSpace;
	(*surface)->surfaceCaps = surfaceCaps;
	(*surface)->extent2D = extent2D;
	(*surface)->presentMode = presentMode;

	free(surfaceFormats);

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfDestroySurface(VkfSurface* surface) {
	vkDestroySurfaceKHR(surface->instance, surface->surface, NULL);
	free(surface);

	return VKF_SUCCESS;
}


VKFAPI VkfResult  vkfInitRenderPass(VkfDevice* device, VkfRenderPass** renderPass) {
	(*renderPass) = (VkfRenderPass*)malloc(sizeof(VkfRenderPass));
	if(NULL == (*renderPass)) {
		printf("vkfInitRenderPass failed: Couldn't allocate memory.\n");
		return VKF_FAILED;
	}

	memset((*renderPass), 0, sizeof(VkfRenderPass));
	(*renderPass)->device = device->device;
	(*renderPass)->numberOfAttachments = 0;

	return VKF_SUCCESS;
}


VKFAPI VkfResult  vkfCreateRenderPass(VkfDevice* device, VkfRenderPass** renderPass) {
	if(NULL == (*renderPass)) {
		printf("vkfCreateRenderPass failed: Use vkfInitRenderPass before you create the render pass.\n");
		return VKF_FAILED;
	}

	uint32_t i = 0;
	VkAttachmentDescription* attachments = (VkAttachmentDescription*)malloc(sizeof(VkAttachmentDescription) * (*renderPass)->numberOfAttachments);
	VkAttachmentReference* colorAttachmentReferences = (VkAttachmentReference*)malloc(sizeof(VkAttachmentReference) * (*renderPass)->colorAttachmentCount);
	for(i = 0; i < (*renderPass)->colorAttachmentCount; i++) {
		VkAttachmentReference colorReference = {0};
		colorReference.attachment = i;
		colorReference.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

		colorAttachmentReferences[i] = colorReference;
		attachments[i] = (*renderPass)->colorAttachments[i];
	}


	VkAttachmentReference depthStencilReferences = {0};
	depthStencilReferences.attachment = i;
	depthStencilReferences.layout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;
	attachments[i++] = (*renderPass)->depthStencilAttachment;

	VkSubpassDependency dependencies = {0};

	// First dependency at the start of the renderpass
	// Does the transition from final to initial layout
	dependencies.srcSubpass = VK_SUBPASS_EXTERNAL;
	dependencies.dstSubpass = 0;
	dependencies.srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
	dependencies.srcAccessMask = 0;
	dependencies.dstStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
	dependencies.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_READ_BIT | VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;

	VkSubpassDescription subpassDescription = {0};
	subpassDescription.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
	subpassDescription.inputAttachmentCount = 0;
	subpassDescription.pInputAttachments = 0;
	subpassDescription.colorAttachmentCount = (*renderPass)->colorAttachmentCount;
	subpassDescription.pColorAttachments = colorAttachmentReferences;
	subpassDescription.pDepthStencilAttachment = &depthStencilReferences;

	// Global render pass for frame buffer writes
	VkRenderPassCreateInfo renderPassCreateInfo = {0};
	renderPassCreateInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
	renderPassCreateInfo.attachmentCount = (*renderPass)->colorAttachmentCount + 1;
	renderPassCreateInfo.pAttachments = attachments;
	renderPassCreateInfo.subpassCount = 1;
	renderPassCreateInfo.pSubpasses = &subpassDescription;
	renderPassCreateInfo.dependencyCount = 1;
	renderPassCreateInfo.pDependencies = &dependencies;

	VkRenderPass renderPassHandle = VK_NULL_HANDLE;
	VkResult result = vkCreateRenderPass((*renderPass)->device, &renderPassCreateInfo, NULL, &renderPassHandle);
	if(VK_SUCCESS != result) {
		printf("vkCreateRenderPass failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}

	(*renderPass)->renderPass = renderPassHandle;
	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfRenderPassAddColorAttachment(VkfRenderPass* renderPass, VkFormat format, VkImageLayout initialImageLayout, VkImageLayout finalImageLayout) {
	if(NULL == renderPass) {
		printf("vkfRenderPassAddColorAttachment failed: Invalid renderPass parameter: %p\n", renderPass);
		return VKF_FAILED;
	}

	renderPass->colorAttachments[renderPass->colorAttachmentCount].flags = 0;
	renderPass->colorAttachments[renderPass->colorAttachmentCount].format = format;
	renderPass->colorAttachments[renderPass->colorAttachmentCount].samples = VK_SAMPLE_COUNT_1_BIT;
	renderPass->colorAttachments[renderPass->colorAttachmentCount].loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
	renderPass->colorAttachments[renderPass->colorAttachmentCount].storeOp = VK_ATTACHMENT_STORE_OP_STORE;
	renderPass->colorAttachments[renderPass->colorAttachmentCount].stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
	renderPass->colorAttachments[renderPass->colorAttachmentCount].stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
	renderPass->colorAttachments[renderPass->colorAttachmentCount].initialLayout = initialImageLayout;
	renderPass->colorAttachments[renderPass->colorAttachmentCount].finalLayout = finalImageLayout;

	renderPass->colorAttachmentCount++;
	renderPass->numberOfAttachments++;

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfRenderPassAddDepthStencilAttachment(VkfRenderPass* renderPass, VkFormat format, VkImageLayout initialImageLayout) {
	if(NULL == renderPass) {
		printf("vkfRenderPassAddDepthStencilAttachment failed: Invalid renderPass parameter: %p\n", renderPass);
		return VKF_FAILED;
	}

	renderPass->depthStencilAttachment.flags = 0;
	renderPass->depthStencilAttachment.format = format;
	renderPass->depthStencilAttachment.samples = VK_SAMPLE_COUNT_1_BIT;
	renderPass->depthStencilAttachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
	renderPass->depthStencilAttachment.storeOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
	renderPass->depthStencilAttachment.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
	renderPass->depthStencilAttachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
	renderPass->depthStencilAttachment.initialLayout = initialImageLayout;
	renderPass->depthStencilAttachment.finalLayout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;

	renderPass->numberOfAttachments++;

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfDestroyRenderPass(VkfRenderPass* renderPass) {
	vkDestroyRenderPass(renderPass->device, renderPass->renderPass, NULL);
	free(renderPass);

	return VKF_SUCCESS;
}




VKFAPI VkfResult  vkfCreateSwapchain(VkfSwapchainCreateInfo* createInfo, VkfSwapchain** swapchain) {
	if(createInfo && (NULL == createInfo->device)) {
		printf("vkfCreateSwapchain: No valid device specified.\n");
		return VKF_FAILED;
	}

	if(NULL == createInfo->surface) {
		printf("vkfCreateSwapchain: No valid surface specified.\n");
		return VKF_FAILED;
	}


	// Determine the number of images. We want to use at least one.
	uint32_t numberImages = createInfo->surface->surfaceCaps.minImageCount + 1;

	VkSurfaceTransformFlagBitsKHR surfaceTransformFlagsKHR;
	if(createInfo->surface->surfaceCaps.supportedTransforms & VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR) {
		// The presented image isn't going to be transformed.
		surfaceTransformFlagsKHR = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR;
	} else {
		surfaceTransformFlagsKHR = createInfo->surface->surfaceCaps.currentTransform;
	}

	VkCompositeAlphaFlagBitsKHR CompositeAlpha = VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR;
	if(createInfo->surface->surfaceCaps.supportedCompositeAlpha & VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR) {
		CompositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
	}

	VkSwapchainCreateInfoKHR swapchainCreateInfo = {0};
	swapchainCreateInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
	swapchainCreateInfo.surface = createInfo->surface->surface;
	swapchainCreateInfo.minImageCount = numberImages;
	swapchainCreateInfo.queueFamilyIndexCount = createInfo->device->familyQueueIndex;

	swapchainCreateInfo.imageArrayLayers = 1;
	swapchainCreateInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;
	swapchainCreateInfo.imageFormat = createInfo->surface->colorFormat;
	swapchainCreateInfo.imageColorSpace = createInfo->surface->colorSpace;
	swapchainCreateInfo.imageExtent = createInfo->surface->surfaceCaps.currentExtent;
	swapchainCreateInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;

	swapchainCreateInfo.preTransform = surfaceTransformFlagsKHR;

	// Don't use VSYNC, just render as soon as possible.
	swapchainCreateInfo.presentMode = createInfo->surface->presentMode;
	swapchainCreateInfo.oldSwapchain = VK_NULL_HANDLE;
	swapchainCreateInfo.compositeAlpha = CompositeAlpha;

	VkSwapchainKHR swapchainHandle = VK_NULL_HANDLE;
	VkResult result = vkCreateSwapchainKHR(createInfo->device->device, &swapchainCreateInfo, NULL, &swapchainHandle);
	if(VK_SUCCESS != result) {
		printf("vkCreateSwapchainKHR failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}

	//
	// Now let's get the number of available images from the swapchain.
	//
	uint32_t imageCount;
	result = vkGetSwapchainImagesKHR(createInfo->device->device, swapchainHandle, &imageCount, NULL);
	if(VK_SUCCESS != result) {
		printf("vkGetSwapchainImagesKHR failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}

	VkImage* swapChainImages = (VkImage*)malloc(sizeof(VkImage) * imageCount);
	result = vkGetSwapchainImagesKHR(createInfo->device->device, swapchainHandle, &imageCount, swapChainImages);
	if(VK_SUCCESS != result) {
		printf("vkGetSwapchainImagesKHR failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}

	VkfTexture** colorAttachments = (VkfTexture**)malloc(sizeof(VkfTexture*));
	for(uint32_t i = 0; i < imageCount; i++) {
		vkfCreateTexture2(createInfo->device, swapChainImages[i], createInfo->surface->colorFormat, VK_IMAGE_VIEW_TYPE_2D, createInfo->surface->extent2D.width, createInfo->surface->extent2D.height, 1, &colorAttachments[i]);
	}

	VkfTexture* depthStencil = NULL;
	vkfCreateTexture(createInfo->device,
	                 VK_FORMAT_D24_UNORM_S8_UINT,
	                 VK_IMAGE_TYPE_2D,
	                 VK_IMAGE_VIEW_TYPE_2D,
	                 createInfo->surface->extent2D.width,
	                 createInfo->surface->extent2D.height,
	                 1,
	                 VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT,
	                 VK_IMAGE_LAYOUT_UNDEFINED,
	                 VK_IMAGE_TILING_OPTIMAL,
	                 VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
	                 &depthStencil);

	VkfRenderPass* renderPass = NULL;
	vkfInitRenderPass(createInfo->device, &renderPass);
	vkfRenderPassAddColorAttachment(renderPass, createInfo->surface->colorFormat, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_PRESENT_SRC_KHR);
	vkfRenderPassAddDepthStencilAttachment(renderPass, VK_FORMAT_D24_UNORM_S8_UINT, VK_IMAGE_LAYOUT_UNDEFINED);
	vkfCreateRenderPass(createInfo->device, &renderPass);


	VkfFrameBuffer** framebuffers = (VkfFrameBuffer**)malloc(sizeof(VkfFrameBuffer*));
	for(uint32_t i = 0; i < imageCount; i++) {
		VkfFrameBuffer* framebuffer = NULL;
		vkfInitFrameBuffer(createInfo->device, &framebuffer);
		vkfFrameBufferAddColorAttachment(framebuffer, colorAttachments[i]->imageView);
		vkfFrameBufferAddDepthStencilrAttachment(framebuffer, depthStencil->imageView);

		VkfFrameBufferCreateInfo frameBufferCreateInfo = {0};
		frameBufferCreateInfo.device = createInfo->device;
		frameBufferCreateInfo.renderPass = renderPass;
		frameBufferCreateInfo.width = createInfo->surface->extent2D.width;
		frameBufferCreateInfo.height = createInfo->surface->extent2D.height;

		vkfCreateFrameBuffer(&frameBufferCreateInfo, &framebuffer);
		framebuffers[i] = framebuffer;
	}

	(*swapchain) = (VkfSwapchain*)malloc(sizeof(VkfSwapchain));
	(*swapchain)->device = createInfo->device;
	(*swapchain)->swapChain = swapchainHandle;
	(*swapchain)->numberOfImages = imageCount;
	(*swapchain)->images = colorAttachments;
	(*swapchain)->depthStencil = depthStencil;
	(*swapchain)->renderPass = renderPass;
	(*swapchain)->framebufferCount = imageCount;
	(*swapchain)->framebuffers = framebuffers;
	(*swapchain)->extent2D = swapchainCreateInfo.imageExtent;

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfDestroySwapchain(VkfSwapchain* swapchain) {
	for(uint32_t i = 0; i < swapchain->numberOfImages; i++) {
		vkfDestroyTexture(swapchain->images[i]);
	}
	for(uint32_t i = 0; i < swapchain->framebufferCount; i++) {
		vkfDestroyFrameBuffer(swapchain->framebuffers[i]);
	}
	vkfDestroyTexture(swapchain->depthStencil);
	vkfDestroyRenderPass(swapchain->renderPass);
	vkDestroySwapchainKHR(swapchain->device->device, swapchain->swapChain, NULL);
	free(swapchain);

	return VKF_SUCCESS;
}




VKFAPI VkfResult  vkfInitFrameBuffer(VkfDevice* device, VkfFrameBuffer** framebuffer) {
	(*framebuffer) = (VkfFrameBuffer*)malloc(sizeof(VkfFrameBuffer));
	if(NULL == (*framebuffer)) {
		return VKF_FAILED;
	}
	(*framebuffer)->device = device->device;
	(*framebuffer)->attachmentCount = 0;

	for(uint32_t i = 0; i < 8; i++) {
		(*framebuffer)->attachments[i] = VK_NULL_HANDLE;
	}

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfCreateFrameBuffer(VkfFrameBufferCreateInfo* createInfo, VkfFrameBuffer** framebuffer) {
	if(NULL == (*framebuffer)) {
		return VKF_FAILED;
	}

	(*framebuffer)->width = createInfo->width;
	(*framebuffer)->height = createInfo->height;

	VkFramebufferCreateInfo frameBufferCreateInfo = {0};
	frameBufferCreateInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
	frameBufferCreateInfo.renderPass = createInfo->renderPass->renderPass;
	frameBufferCreateInfo.attachmentCount = (*framebuffer)->attachmentCount;
	frameBufferCreateInfo.pAttachments = (*framebuffer)->attachments;
	frameBufferCreateInfo.width = createInfo->width;
	frameBufferCreateInfo.height = createInfo->height;
	frameBufferCreateInfo.layers = 1;

	// Create frame buffers for every swap chain image
	VkFramebuffer frameBufferHandle = VK_NULL_HANDLE;
	VkResult result = vkCreateFramebuffer(createInfo->device->device, &frameBufferCreateInfo, NULL, &frameBufferHandle);
	if(VK_SUCCESS != result) {
		printf("vkCreateFramebuffer failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}

	(*framebuffer)->framebuffer = frameBufferHandle;

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfFrameBufferAddColorAttachment(VkfFrameBuffer* framebuffer, VkImageView imageView) {
	framebuffer->attachments[framebuffer->attachmentCount] = imageView;
	framebuffer->attachmentCount++;

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfFrameBufferAddDepthStencilrAttachment(VkfFrameBuffer* framebuffer, VkImageView imageView) {
	framebuffer->attachments[framebuffer->attachmentCount] = imageView;
	framebuffer->attachmentCount++;

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfDestroyFrameBuffer(VkfFrameBuffer* framebuffer) {
	vkDestroyFramebuffer(framebuffer->device, framebuffer->framebuffer, NULL);
	free(framebuffer);

	return VKF_SUCCESS;
}



VKFAPI VkfResult  vkfInitPipeline(VkfPipelineCreateInfo* createInfo, VkfPipeline** pipeline) {
	(*pipeline) = (VkfPipeline*)malloc(sizeof(VkfPipeline));
	if(NULL == (*pipeline)) {
		return VKF_FAILED;
	}
	(*pipeline)->device = createInfo->device;
	(*pipeline)->renderPass = createInfo->renderPass;
	(*pipeline)->extent2D = createInfo->extent2D;
	(*pipeline)->descriptorSetLayout = createInfo->descriptorSetLayout;
	(*pipeline)->shaderStageCount = 0;
	(*pipeline)->shaderStageCreateInfo = (VkPipelineShaderStageCreateInfo*)malloc(sizeof(VkPipelineShaderStageCreateInfo) * VKF_MAX_SHADER_STAGE_COUNT);
	(*pipeline)->vertexInputAttributeDescriptionCount = 0;
	(*pipeline)->vertexInputAttributeDescription = (VkVertexInputAttributeDescription*)malloc(sizeof(VkVertexInputAttributeDescription) * 8);
	(*pipeline)->vertexInputBindingDescriptionCount = 0;
	(*pipeline)->vertexInputBindingDescription = (VkVertexInputBindingDescription*)malloc(sizeof(VkVertexInputBindingDescription) * 8);
	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfCreatePipeline(VkfPipeline* pipeline) {

	VkPipelineLayoutCreateInfo pipelineLayoutCreateInfo = {0};
	pipelineLayoutCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
	pipelineLayoutCreateInfo.setLayoutCount = 1;
	pipelineLayoutCreateInfo.pSetLayouts = &pipeline->descriptorSetLayout->descriptorSetLayout;

	VkPipelineLayout pipelineLayoutHandle = VK_NULL_HANDLE;
	VkResult result = vkCreatePipelineLayout(pipeline->device->device, &pipelineLayoutCreateInfo, NULL, &pipelineLayoutHandle);
	if(VK_SUCCESS != result) {
		printf("vkCreatePipelineLayout failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}
	pipeline->pipelineLayout = pipelineLayoutHandle;

	// -------------------------------------------------------------------------
	// Set Viewport states.
	//
	VkViewport viewport = {0};
	viewport.x = 0.0f;
	viewport.y = 0.0f;
	viewport.width = pipeline->extent2D.width;
	viewport.height = pipeline->extent2D.height;
	viewport.minDepth = 0.0f;
	viewport.maxDepth = 1.0f;

	VkRect2D scissor = {0};
	scissor.extent.width = pipeline->extent2D.width;
	scissor.extent.height = pipeline->extent2D.height;
	scissor.offset.x = 0;
	scissor.offset.y = 0;

	// Color blend state
	// -------------------------------------------------------------------------
	// Blending is not used in this example
	//
	pipeline->pipelineColorBlendAttachmentState.blendEnable = VK_FALSE;
	pipeline->pipelineColorBlendAttachmentState.srcColorBlendFactor = VK_BLEND_FACTOR_ONE;
	pipeline->pipelineColorBlendAttachmentState.dstColorBlendFactor = VK_BLEND_FACTOR_ONE;
	pipeline->pipelineColorBlendAttachmentState.colorBlendOp = VK_BLEND_OP_ADD;
	pipeline->pipelineColorBlendAttachmentState.srcAlphaBlendFactor = VK_BLEND_FACTOR_ZERO;
	pipeline->pipelineColorBlendAttachmentState.dstAlphaBlendFactor = VK_BLEND_FACTOR_ZERO;
	pipeline->pipelineColorBlendAttachmentState.alphaBlendOp = VK_BLEND_OP_ADD;
	pipeline->pipelineColorBlendAttachmentState.colorWriteMask = 0xf;

	// Describes blend modes and color masks
	VkPipelineColorBlendStateCreateInfo colorBlendState = {0};
	colorBlendState.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
	colorBlendState.attachmentCount = 1;
	colorBlendState.pAttachments = &pipeline->pipelineColorBlendAttachmentState;

	VkPipelineViewportStateCreateInfo viewportState = {0};
	viewportState.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
	viewportState.viewportCount = 1;
	viewportState.pViewports = &viewport;
	viewportState.scissorCount = 1;
	viewportState.pScissors = &scissor;

	VkDynamicState dynamicStateEnables[2];
	dynamicStateEnables[0] = VK_DYNAMIC_STATE_VIEWPORT;
	dynamicStateEnables[1] = VK_DYNAMIC_STATE_SCISSOR;

	VkPipelineDynamicStateCreateInfo dynamicState = {0};
	dynamicState.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
	dynamicState.dynamicStateCount = 2;
	dynamicState.pDynamicStates = dynamicStateEnables;

	// Multi sampling state
	VkPipelineMultisampleStateCreateInfo multisampleState = {0};
	multisampleState.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
	multisampleState.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
	multisampleState.sampleShadingEnable = VK_FALSE;
	multisampleState.minSampleShading = 0.0f;
	multisampleState.pSampleMask = NULL;
	multisampleState.alphaToCoverageEnable = VK_FALSE;
	multisampleState.alphaToOneEnable = VK_FALSE;

	// -------------------------------------------------------------------------
	// Vertex input state.
	//
	VkPipelineVertexInputStateCreateInfo pipelineVertexInputStateCreateInfo = {0};
	pipelineVertexInputStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
	pipelineVertexInputStateCreateInfo.vertexBindingDescriptionCount = pipeline->vertexInputBindingDescriptionCount;
	pipelineVertexInputStateCreateInfo.pVertexBindingDescriptions = pipeline->vertexInputBindingDescription;
	pipelineVertexInputStateCreateInfo.vertexAttributeDescriptionCount = pipeline->vertexInputAttributeDescriptionCount;
	pipelineVertexInputStateCreateInfo.pVertexAttributeDescriptions = pipeline->vertexInputAttributeDescription;

	// -------------------------------------------------------------------------
	// Input assembly state.
	//
	memset(&pipeline->pipelineInputAssemblyStateCreateInfo, 0, sizeof(VkPipelineInputAssemblyStateCreateInfo));
	pipeline->pipelineInputAssemblyStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
	pipeline->pipelineInputAssemblyStateCreateInfo.pNext = NULL;
	pipeline->pipelineInputAssemblyStateCreateInfo.flags = 0;
	pipeline->pipelineInputAssemblyStateCreateInfo.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
	pipeline->pipelineInputAssemblyStateCreateInfo.primitiveRestartEnable = VK_FALSE;

	// -------------------------------------------------------------------------
	// Rasterization state
	//
	memset(&pipeline->pipelineRasterizationStateCreateInfo, 0, sizeof(VkPipelineRasterizationStateCreateInfo));
	pipeline->pipelineRasterizationStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
	pipeline->pipelineRasterizationStateCreateInfo.depthClampEnable = VK_FALSE;
	pipeline->pipelineRasterizationStateCreateInfo.rasterizerDiscardEnable = VK_FALSE;
	pipeline->pipelineRasterizationStateCreateInfo.polygonMode = VK_POLYGON_MODE_FILL;
	pipeline->pipelineRasterizationStateCreateInfo.lineWidth = 1.0f;
	pipeline->pipelineRasterizationStateCreateInfo.cullMode = VK_CULL_MODE_NONE;
	pipeline->pipelineRasterizationStateCreateInfo.frontFace = VK_FRONT_FACE_CLOCKWISE;
	pipeline->pipelineRasterizationStateCreateInfo.depthBiasEnable = VK_FALSE;

	// -------------------------------------------------------------------------
	// Depth and stencil state
	//
	memset(&pipeline->pipelineDepthStencilStateCreateInfo, 0, sizeof(VkPipelineDepthStencilStateCreateInfo));
	pipeline->pipelineDepthStencilStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
	pipeline->pipelineDepthStencilStateCreateInfo.depthTestEnable = VK_TRUE;
	pipeline->pipelineDepthStencilStateCreateInfo.depthWriteEnable = VK_TRUE;
	pipeline->pipelineDepthStencilStateCreateInfo.depthCompareOp = VK_COMPARE_OP_LESS_OR_EQUAL;
	pipeline->pipelineDepthStencilStateCreateInfo.depthBoundsTestEnable = VK_FALSE;
	pipeline->pipelineDepthStencilStateCreateInfo.back.failOp = VK_STENCIL_OP_KEEP;
	pipeline->pipelineDepthStencilStateCreateInfo.back.passOp = VK_STENCIL_OP_KEEP;
	pipeline->pipelineDepthStencilStateCreateInfo.back.compareOp = VK_COMPARE_OP_ALWAYS;
	pipeline->pipelineDepthStencilStateCreateInfo.stencilTestEnable = VK_FALSE;
	pipeline->pipelineDepthStencilStateCreateInfo.front = pipeline->pipelineDepthStencilStateCreateInfo.back;

	VkGraphicsPipelineCreateInfo pipelineCreateInfo = {0};
	pipelineCreateInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
	pipelineCreateInfo.flags = VK_PIPELINE_CREATE_DISABLE_OPTIMIZATION_BIT;
	// Set vertex input state so the pipeline has access to the vertex data.
	if(pipelineVertexInputStateCreateInfo.vertexBindingDescriptionCount > 0) {
		pipelineCreateInfo.pVertexInputState = &pipelineVertexInputStateCreateInfo;
	}
	pipelineCreateInfo.stageCount = pipeline->shaderStageCount;
	pipelineCreateInfo.pStages = pipeline->shaderStageCreateInfo;
	pipelineCreateInfo.pInputAssemblyState = &pipeline->pipelineInputAssemblyStateCreateInfo;
	pipelineCreateInfo.pTessellationState = NULL;
	pipelineCreateInfo.pViewportState = &viewportState;
	pipelineCreateInfo.pRasterizationState = &pipeline->pipelineRasterizationStateCreateInfo;
	pipelineCreateInfo.pMultisampleState = &multisampleState;
	pipelineCreateInfo.pDepthStencilState = &pipeline->pipelineDepthStencilStateCreateInfo;
	pipelineCreateInfo.pColorBlendState = &colorBlendState;
	pipelineCreateInfo.pDynamicState = &dynamicState;
	pipelineCreateInfo.layout = pipelineLayoutHandle;
	pipelineCreateInfo.renderPass = pipeline->renderPass->renderPass;
	pipelineCreateInfo.subpass = 0;
	pipelineCreateInfo.basePipelineHandle = VK_NULL_HANDLE;
	pipelineCreateInfo.basePipelineIndex = 0;


	VkPipeline pipelineHandle = VK_NULL_HANDLE;
	result = vkCreateGraphicsPipelines(pipeline->device->device, VK_NULL_HANDLE, 1, &pipelineCreateInfo, NULL, &pipelineHandle);
	if(VK_SUCCESS != result) {
		printf("vkCreateGraphicsPipelines failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}

	pipeline->pipeline = pipelineHandle;
	pipeline->pipelineLayout = pipelineLayoutHandle;

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfPipelineAddVertexState(VkfPipeline* pipeline, VkfBuffer* buffer) {

	// ---------------------------------------------------------------------------
	// Here we will describe how the vertex buffer looks like and how the shaders can access it.
	//

	// This part we should actually do inside the buffer but for now, until I decided the API desn't i will do that inside the pipeline
	memset(&pipeline->vertexInputBindingDescription[pipeline->vertexInputBindingDescriptionCount], 0, sizeof(VkVertexInputBindingDescription));
	pipeline->vertexInputBindingDescription[pipeline->vertexInputBindingDescriptionCount].binding = buffer->binding;
	pipeline->vertexInputBindingDescription[pipeline->vertexInputBindingDescriptionCount].stride = buffer->stride;
	pipeline->vertexInputBindingDescription[pipeline->vertexInputBindingDescriptionCount].inputRate = VK_VERTEX_INPUT_RATE_VERTEX;
	pipeline->vertexInputBindingDescriptionCount++;

	VkfVertexInputAttributeDescription* vertexBufferBinding = (VkfVertexInputAttributeDescription*)buffer->pNext;
	if(vertexBufferBinding) {
		pipeline->vertexInputAttributeDescription = vertexBufferBinding->descriptions;
		pipeline->vertexInputAttributeDescriptionCount = vertexBufferBinding->descriptionCount;
	}

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfPipelineAddShader(VkfPipeline* pipeline, VkfShaderModule* shaderModule) {
	memset(&pipeline->shaderStageCreateInfo[pipeline->shaderStageCount], 0, sizeof(VkPipelineShaderStageCreateInfo));
	pipeline->shaderStageCreateInfo[pipeline->shaderStageCount].sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
	pipeline->shaderStageCreateInfo[pipeline->shaderStageCount].stage = shaderModule->shaderStageFlagBits;
	pipeline->shaderStageCreateInfo[pipeline->shaderStageCount].module = shaderModule->shaderModule;
	pipeline->shaderStageCreateInfo[pipeline->shaderStageCount].pName = shaderModule->entryName;
	pipeline->shaderStageCount++;

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfDestroyPipeline(VkfPipeline* pipeline) {
	if(NULL != pipeline->shaderStageCreateInfo) {
		free(pipeline->shaderStageCreateInfo);
	}
	free(pipeline);

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfInitTextureSampler(VkfTextureSamplerCreateInfo* createInfo, VkfTextureSampler** textureSampler) {
	(*textureSampler) = (VkfTextureSampler*)malloc(sizeof(VkfTextureSampler));
	if(NULL == (*textureSampler)) {
		return VKF_MEMORY_ALLOCATION;
	}

	memset((*textureSampler), 0, sizeof(VkfTextureSampler));

	(*textureSampler)->device = createInfo->device;

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfCreateTextureSampler(VkfTextureSamplerCreateInfo* createInfo, VkfTextureSampler** textureSampler) {

	VkSamplerCreateInfo samplerCreateInfo = {0};
	samplerCreateInfo.sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
	samplerCreateInfo.magFilter = createInfo->magFilter;
	samplerCreateInfo.minFilter = createInfo->minFilter;
	samplerCreateInfo.addressModeU = createInfo->addressModeU;
	samplerCreateInfo.addressModeV = createInfo->addressModeV;
	samplerCreateInfo.addressModeW = createInfo->addressModeW;
	samplerCreateInfo.anisotropyEnable = VK_FALSE;
	samplerCreateInfo.maxAnisotropy = 0;
	samplerCreateInfo.borderColor = VK_BORDER_COLOR_INT_OPAQUE_BLACK;
	samplerCreateInfo.unnormalizedCoordinates = VK_FALSE;
	samplerCreateInfo.compareEnable = VK_FALSE;
	samplerCreateInfo.compareOp = VK_COMPARE_OP_ALWAYS;
	samplerCreateInfo.mipmapMode = VK_SAMPLER_MIPMAP_MODE_NEAREST;
	samplerCreateInfo.mipLodBias = 0.0f;
	samplerCreateInfo.minLod = 0.0f;
	samplerCreateInfo.maxLod = 0.0f;
	VkSampler textureSamplerHandle = VK_NULL_HANDLE;
	VkResult result = vkCreateSampler(createInfo->device->device, &samplerCreateInfo, NULL, &textureSamplerHandle);
	if(VK_SUCCESS != result) {
		return VKF_FAILED;
	}

	(*textureSampler)->textureSampler = textureSamplerHandle;
	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfDestroyTextureSampler(VkfTextureSampler* textureSampler) {
	vkDestroySampler(textureSampler->device->device, textureSampler->textureSampler, NULL);
	free(textureSampler);
	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfCreateTexture1D(VkfDevice* device,
                                     VkFormat format,
                                     uint32_t width,
                                     uint32_t height,
                                     uint32_t depth,
                                     VkImageLayout initializeLayout,
                                     VkfTexture** texture) {
	return vkfCreateTexture(device,
	                        format,
	                        VK_IMAGE_TYPE_1D,
	                        VK_IMAGE_VIEW_TYPE_1D,
	                        width,
	                        height,
	                        depth,
	                        VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT,
	                        initializeLayout,
	                        VK_IMAGE_TILING_LINEAR,
	                        VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT,
	                        texture);
}

VKFAPI VkfResult  vkfCreateTexture1DArray(VkfDevice* device,
        VkFormat format,
        uint32_t width,
        uint32_t height,
        uint32_t depth,
        VkImageLayout initializeLayout,
        VkfTexture** texture) {
	return vkfCreateTexture(device,
	                        format,
	                        VK_IMAGE_TYPE_1D,
	                        VK_IMAGE_VIEW_TYPE_1D_ARRAY,
	                        width,
	                        height,
	                        depth,
	                        VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT,
	                        initializeLayout,
	                        VK_IMAGE_TILING_LINEAR,
	                        VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT,
	                        texture);
}

VKFAPI VkfResult  vkfCreateTexture2D(VkfDevice* device,
                                     VkFormat format,
                                     uint32_t width,
                                     uint32_t height,
                                     uint32_t depth,
                                     VkImageLayout initializeLayout,
                                     VkfTexture** texture) {
	return vkfCreateTexture(device,
	                        format,
	                        VK_IMAGE_TYPE_2D,
	                        VK_IMAGE_VIEW_TYPE_2D,
	                        width,
	                        height,
	                        depth,
	                        VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT,
	                        initializeLayout,
	                        VK_IMAGE_TILING_LINEAR,
	                        VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT,
	                        texture);
}

VKFAPI VkfResult  vkfCreateTexture2DArray(VkfDevice* device,
        VkFormat format,
        uint32_t width,
        uint32_t height,
        uint32_t depth,
        VkImageLayout initializeLayout,
        VkfTexture** texture) {
	return vkfCreateTexture(device,
	                        format,
	                        VK_IMAGE_TYPE_3D,
	                        VK_IMAGE_VIEW_TYPE_2D_ARRAY,
	                        width,
	                        height,
	                        depth,
	                        VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT,
	                        initializeLayout,
	                        VK_IMAGE_TILING_LINEAR,
	                        VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT,
	                        texture);
}


VKFAPI VkfResult  vkfCreateTexture3D(VkfDevice* device,
                                     VkFormat format,
                                     uint32_t width,
                                     uint32_t height,
                                     uint32_t depth,
                                     VkImageLayout initializeLayout,
                                     VkfTexture** texture) {
	return vkfCreateTexture(device,
	                        format,
	                        VK_IMAGE_TYPE_3D,
	                        VK_IMAGE_VIEW_TYPE_3D,
	                        width,
	                        height,
	                        depth,
	                        VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT,
	                        initializeLayout,
	                        VK_IMAGE_TILING_LINEAR,
	                        VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT,
	                        texture);
}

VKFAPI VkfResult  vkfCreateTextureCube(VkfDevice* device,
                                       VkFormat format,
                                       uint32_t width,
                                       uint32_t height,
                                       uint32_t depth,
                                       VkImageLayout initializeLayout,
                                       VkfTexture** texture) {
	return vkfCreateTexture(device,
	                        format,
	                        VK_IMAGE_TYPE_3D,
	                        VK_IMAGE_VIEW_TYPE_CUBE,
	                        width,
	                        height,
	                        depth,
	                        VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT,
	                        initializeLayout,
	                        VK_IMAGE_TILING_LINEAR,
	                        VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT,
	                        texture);
}

VKFAPI VkfResult  vkfCreateTexture(VkfDevice* device,
                                   VkFormat format,
                                   VkImageType imageType,
                                   VkImageViewType imageViewType,
                                   uint32_t width,
                                   uint32_t height,
                                   uint32_t depth,
                                   VkImageUsageFlags usage,
                                   VkImageLayout initializeLayout,
                                   VkImageTiling tiling,
                                   VkFlags memoryAllocationFlags,
                                   VkfTexture** texture) {
	VkImageCreateInfo imageCreateInfo = {0};
	imageCreateInfo.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
	imageCreateInfo.imageType = imageType;
	imageCreateInfo.format = format;
	imageCreateInfo.extent.width = width;
	imageCreateInfo.extent.height = height;
	imageCreateInfo.extent.depth = (imageType==VK_IMAGE_TYPE_3D) ? 1 : depth;
	imageCreateInfo.mipLevels = 1;
	imageCreateInfo.arrayLayers = depth;
	imageCreateInfo.samples = VK_SAMPLE_COUNT_1_BIT;
	imageCreateInfo.tiling = tiling;
	imageCreateInfo.usage = usage;
	imageCreateInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
	imageCreateInfo.initialLayout = initializeLayout;

	VkImage image = VK_NULL_HANDLE;
	VkResult result = vkCreateImage(device->device, &imageCreateInfo, NULL, &image);
	if(VK_SUCCESS != result) {
		printf("vkCreateImage failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}

	VkMemoryRequirements memoryRequirements = {0};
	vkGetImageMemoryRequirements(device->device, image, &memoryRequirements);

	VkMemoryAllocateInfo memoryAllocateInfo = {0};
	memoryAllocateInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
	memoryAllocateInfo.pNext = NULL;

	VkPhysicalDeviceMemoryProperties physicalDeviceMemoryProperties = {0};
	vkGetPhysicalDeviceMemoryProperties(device->physicalDevice, &physicalDeviceMemoryProperties);

	memoryAllocateInfo.memoryTypeIndex = getMemoryTypeIndex(physicalDeviceMemoryProperties, memoryRequirements, memoryAllocationFlags);
	memoryAllocateInfo.allocationSize = memoryRequirements.size;

	VkDeviceMemory deviceMemory = VK_NULL_HANDLE;
	result = vkAllocateMemory(device->device, &memoryAllocateInfo, NULL, &deviceMemory);
	if(VK_SUCCESS != result) {
		printf("vkAllocateMemory failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}

	result = vkBindImageMemory(device->device, image, deviceMemory, 0);
	if(VK_SUCCESS != result) {
		printf("vkBindImageMemory failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}

	VkImageViewCreateInfo imageViewCreateInfo = {0};
	imageViewCreateInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
	imageViewCreateInfo.viewType = imageViewType;
	imageViewCreateInfo.format = format;
	imageViewCreateInfo.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;
	imageViewCreateInfo.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
	imageViewCreateInfo.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
	imageViewCreateInfo.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
	imageViewCreateInfo.subresourceRange.aspectMask = getImageAspectFlagBitsFromFormat(format);
	imageViewCreateInfo.subresourceRange.baseMipLevel = 0;
	imageViewCreateInfo.subresourceRange.levelCount = 1; // MipMapLevels
	imageViewCreateInfo.subresourceRange.baseArrayLayer = 0;
	imageViewCreateInfo.subresourceRange.layerCount = (imageViewType == VK_IMAGE_VIEW_TYPE_CUBE) ? 6 : 1;
	imageViewCreateInfo.image = image;

	VkImageView imageView = VK_NULL_HANDLE;
	result = vkCreateImageView(device->device, &imageViewCreateInfo, NULL, &imageView);
	if(VK_SUCCESS != result) {
		printf("vkCreateImageView failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}

	(*texture) = (VkfTexture*)malloc(sizeof(VkfTexture));
	(*texture)->device = device->device;
	(*texture)->image = image;
	(*texture)->imageView = imageView;
	(*texture)->width = width;
	(*texture)->height = height;
	(*texture)->depth = depth;
	(*texture)->memory = deviceMemory;
	(*texture)->isSwapchainImage = 0;
	(*texture)->imageLayout = initializeLayout;
	(*texture)->format = imageCreateInfo.format;
	(*texture)->size = memoryAllocateInfo.allocationSize;

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfCreateTexture2(VkfDevice* device, VkImage image, VkFormat format, VkImageViewType imageViewType, uint32_t width, uint32_t height, uint32_t depth, VkfTexture** texture) {

	VkImageViewCreateInfo imageViewCreateInfo = {0};
	imageViewCreateInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
	imageViewCreateInfo.viewType = imageViewType;
	imageViewCreateInfo.format = format;
	imageViewCreateInfo.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;
	imageViewCreateInfo.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
	imageViewCreateInfo.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
	imageViewCreateInfo.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
	imageViewCreateInfo.subresourceRange.aspectMask = getImageAspectFlagBitsFromFormat(format);
	imageViewCreateInfo.subresourceRange.baseMipLevel = 0;
	imageViewCreateInfo.subresourceRange.levelCount = 1; // MipMapLevels
	imageViewCreateInfo.subresourceRange.baseArrayLayer = 0;
	imageViewCreateInfo.subresourceRange.layerCount = (imageViewType == VK_IMAGE_VIEW_TYPE_CUBE) ? 6 : 1;
	imageViewCreateInfo.image = image;

	VkImageView imageView = VK_NULL_HANDLE;
	VkResult result = vkCreateImageView(device->device, &imageViewCreateInfo, NULL, &imageView);
	if(VK_SUCCESS != result) {
		printf("vkCreateImageView failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}

	(*texture) = (VkfTexture*)malloc(sizeof(VkfTexture));
	(*texture)->device = device->device;
	(*texture)->image = image;
	(*texture)->imageView = imageView;
	(*texture)->width = width;
	(*texture)->height = height;
	(*texture)->depth = depth;
	(*texture)->memory = VK_NULL_HANDLE;
	(*texture)->isSwapchainImage = 1;
	(*texture)->imageLayout = 0;

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfUploadTexture(VkfTexture* texture, uint8_t* src, uint64_t size, uint64_t offset) {
	uint8_t* buffer;

	VkMemoryRequirements memoryRequirements = {0};
	vkGetImageMemoryRequirements(texture->device, texture->image, &memoryRequirements);

	VkResult result = vkMapMemory(texture->device, texture->memory, offset, memoryRequirements.size, 0, (void **)&buffer);
	if(VK_SUCCESS != result) {
		return VKF_FAILED;
	}

	memcpy(buffer, src, size);

	vkUnmapMemory(texture->device, texture->memory);
	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfDestroyTexture(VkfTexture* texture) {
	vkDestroyImageView(texture->device, texture->imageView, NULL);
	if(0 == texture->isSwapchainImage) {
		vkFreeMemory(texture->device, texture->memory, NULL);
		vkDestroyImage(texture->device, texture->image, NULL);
	}
	free(texture);

	return VKF_SUCCESS;
}

uint32_t VKFAPI vkfTextureGetPitch(VkfTexture* texture) {
	VkImageSubresource imageSubresource = {0};
	imageSubresource.aspectMask = getImageAspectFlagBitsFromFormat(texture->format);
	if(imageSubresource.aspectMask) {
		imageSubresource.mipLevel = 0;
	}

	VkSubresourceLayout subResLayout;
	vkGetImageSubresourceLayout(texture->device, texture->image, &imageSubresource, &subResLayout);

	return subResLayout.rowPitch;
}

VKFAPI VkfResult  vkfCreateShaderModule(VkfShaderModuleCreateInfo* createInfo, VkfShaderModule** shaderModule) {
	(*shaderModule) = (VkfShaderModule*)malloc(sizeof(VkfShaderModule));
	(*shaderModule)->device = createInfo->device;
	(*shaderModule)->shaderStageFlagBits = createInfo->shaderStageFlagBits;

	if(createInfo->entryName) {
		(*shaderModule)->entryName = (char*)malloc(sizeof(char) * strlen(createInfo->entryName) + 1);
		memset((*shaderModule)->entryName, '\0', sizeof(sizeof(char) * strlen(createInfo->entryName) + 1));
		strcpy((*shaderModule)->entryName, createInfo->entryName);
	}

	uint32_t shaderSize = 0;
	uint32_t* shaderBinary = NULL;
	if(createInfo->filename) {
		FILE* file = fopen(createInfo->filename, "rb");
		if(file) {

			// Allocate memory for the binary.
			fseek(file, 0, SEEK_END);
			shaderSize = ftell(file);
			fseek(file, 0, SEEK_SET);
			// TODO We are maybe allocating too much.
			shaderBinary = (uint32_t*)malloc(sizeof(uint32_t) * shaderSize);
			uint32_t length = 0;
			// TODO We are not checking the size here.
			if((length = fread((void*)shaderBinary, 1, shaderSize, file)) != shaderSize) {
				printf("Failed to read SPRI-V binary file: %s\n", createInfo->filename);
			}
		} else {
			printf("Couldn't open file: %s\n", createInfo->filename);
			return VKF_FAILED;
		}
	} else if((createInfo->shaderSize > 0) && (NULL != createInfo->shaderBinary)) {
		shaderSize = createInfo->shaderSize;
		shaderBinary = createInfo->shaderBinary;
	} else {
		assert(0 && "No valid VkfShaderModuleCreateInfo specified.");
	}

	//
	// Create the Vulkan Shader Module.
	//
	VkShaderModuleCreateInfo moduleCreateInfo = {0};
	moduleCreateInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
	moduleCreateInfo.codeSize = shaderSize;
	moduleCreateInfo.pCode = shaderBinary;

	VkShaderModule shaderModuleHandle = VK_NULL_HANDLE;
	VkResult result = vkCreateShaderModule(createInfo->device->device, &moduleCreateInfo, NULL, &shaderModuleHandle);
	if(VK_SUCCESS != result) {
		printf("vkCreateShaderModule failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}

	(*shaderModule)->shaderModule = shaderModuleHandle;
	(*shaderModule)->binary = shaderBinary;
	(*shaderModule)->binarySize = shaderSize;
	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfCreateVertexShaderModule(VkfShaderModuleCreateInfo* createInfo, VkfShaderModule** shaderModule) {
	createInfo->shaderStageFlagBits = VK_SHADER_STAGE_VERTEX_BIT;
	return vkfCreateShaderModule(createInfo, shaderModule);
}

VKFAPI VkfResult  vkfCreateGeometryShaderModule(VkfShaderModuleCreateInfo* createInfo, VkfShaderModule** shaderModule) {
	createInfo->shaderStageFlagBits = VK_SHADER_STAGE_GEOMETRY_BIT;
	return vkfCreateShaderModule(createInfo, shaderModule);
}

VKFAPI VkfResult  vkfCreateFragmentShaderModule(VkfShaderModuleCreateInfo* createInfo, VkfShaderModule** shaderModule) {
	createInfo->shaderStageFlagBits = VK_SHADER_STAGE_FRAGMENT_BIT;
	return vkfCreateShaderModule(createInfo, shaderModule);
}

VKFAPI VkfResult  vkfCreateTessellationControlShaderModule(VkfShaderModuleCreateInfo* createInfo, VkfShaderModule** shaderModule) {
	createInfo->shaderStageFlagBits = VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT;
	return vkfCreateShaderModule(createInfo, shaderModule);
}

VKFAPI VkfResult  vkfCreateTessellationEvaluationShaderModule(VkfShaderModuleCreateInfo* createInfo, VkfShaderModule** shaderModule) {
	createInfo->shaderStageFlagBits = VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT;
	return vkfCreateShaderModule(createInfo, shaderModule);
}

VKFAPI VkfResult  vkfCreateComputeShaderModule(VkfShaderModuleCreateInfo* createInfo, VkfShaderModule** shaderModule) {
	createInfo->shaderStageFlagBits = VK_SHADER_STAGE_COMPUTE_BIT;
	return vkfCreateShaderModule(createInfo, shaderModule);
}

VKFAPI VkfResult  vkfDestroyShaderModule(VkfShaderModule* shaderModule) {
	free(shaderModule->entryName);
	vkDestroyShaderModule(shaderModule->device->device, shaderModule->shaderModule, NULL);
	free(shaderModule);

	return VKF_SUCCESS;
}


VKFAPI VkfResult  vkfInitVertexBuffer(VkfBufferCreateInfo* createInfo, VkfBuffer** buffer) {
	createInfo->bufferUsageFlagBits = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT;
	return vkfInitBuffer(createInfo, buffer);
}

VKFAPI VkfResult  vkfInitIndexBuffer(VkfBufferCreateInfo* createInfo, VkfBuffer** buffer) {
	createInfo->bufferUsageFlagBits = VK_BUFFER_USAGE_INDEX_BUFFER_BIT;
	return vkfInitBuffer(createInfo, buffer);
}

VKFAPI VkfResult  vkfInitUniformBuffer(VkfBufferCreateInfo* createInfo, VkfBuffer** buffer) {
	createInfo->bufferUsageFlagBits = VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT;
	return vkfInitBuffer(createInfo, buffer);
}

VKFAPI VkfResult  vkfInitStagingBuffer(VkfBufferCreateInfo* createInfo, VkfBuffer** buffer) {
	createInfo->bufferUsageFlagBits = VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
	return vkfInitBuffer(createInfo, buffer);
}

VKFAPI VkfResult  vkfInitBuffer(VkfBufferCreateInfo* createInfo, VkfBuffer** buffer) {
	(*buffer) = (VkfBuffer*)malloc(sizeof(VkfBuffer));
	if(NULL == (*buffer)) {
		return VKF_FAILED;
	}
	memset((*buffer), 0, sizeof(VkfBuffer));
	(*buffer)->device = createInfo->device;
	(*buffer)->stride = createInfo->stride;

	if(createInfo->bufferUsageFlagBits == VK_BUFFER_USAGE_VERTEX_BUFFER_BIT) {
		VkfVertexInputAttributeDescription* bufferBinding = (VkfVertexInputAttributeDescription*)malloc(sizeof(VkfVertexInputAttributeDescription));
		memset(bufferBinding, 0, sizeof(VkfVertexInputAttributeDescription));
		bufferBinding->sType = VKF_S_VERTEX_BUFFER_BINDING_INFO;
		(*buffer)->pNext = bufferBinding;
	}

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfCreateBuffer(VkfBufferCreateInfo* createInfo, VkfBuffer** buffer) {

	VkBufferCreateInfo bufferCreateInfo = {0};
	bufferCreateInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
	bufferCreateInfo.usage = createInfo->bufferUsageFlagBits;
	bufferCreateInfo.size = createInfo->size;

	VkBuffer bufferHandle = VK_NULL_HANDLE;
	VkResult result = vkCreateBuffer(createInfo->device->device, &bufferCreateInfo, NULL, &bufferHandle);
	if(VK_SUCCESS != result) {
		printf("vkCreateBuffer failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}

	VkMemoryRequirements memoryRequirements = {0};
	vkGetBufferMemoryRequirements(createInfo->device->device, bufferHandle, &memoryRequirements);

	VkMemoryAllocateInfo memoryAllocateInfo = {0};
	memoryAllocateInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
	memoryAllocateInfo.pNext = NULL;

	VkPhysicalDeviceMemoryProperties physicalDeviceMemoryProperties = {0};
	vkGetPhysicalDeviceMemoryProperties(createInfo->device->physicalDevice, &physicalDeviceMemoryProperties);

	memoryAllocateInfo.memoryTypeIndex = getMemoryTypeIndex(physicalDeviceMemoryProperties, memoryRequirements, VK_MEMORY_PROPERTY_HOST_COHERENT_BIT | VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT);
	memoryAllocateInfo.allocationSize = memoryRequirements.size;

	VkDeviceMemory memoryHandle = VK_NULL_HANDLE;
	result = vkAllocateMemory(createInfo->device->device, &memoryAllocateInfo, NULL, &memoryHandle);
	if(VK_SUCCESS != result) {
		printf("vkAllocateMemory failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}

	result = vkBindBufferMemory(createInfo->device->device, bufferHandle, memoryHandle, 0);
	if(VK_SUCCESS != result) {
		printf("vkBindBufferMemory failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}

	(*buffer)->buffer = bufferHandle;
	(*buffer)->memory = memoryHandle;
	(*buffer)->size = memoryRequirements.size;

	if((createInfo->bufferUsageFlagBits == VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT) ||
	        (createInfo->bufferUsageFlagBits == VK_BUFFER_USAGE_STORAGE_BUFFER_BIT)) {
		(*buffer)->descriptorBufferInfo = (VkDescriptorBufferInfo*)malloc(sizeof(VkDescriptorBufferInfo));
		(*buffer)->descriptorBufferInfo->buffer =  bufferHandle;
		(*buffer)->descriptorBufferInfo->offset = 0;
		(*buffer)->descriptorBufferInfo->range = bufferCreateInfo.size;
	} else {
		(*buffer)->descriptorBufferInfo = NULL;
	}

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfCreateVertexBuffer(VkfBufferCreateInfo* createInfo, VkfBuffer** buffer) {
	createInfo->bufferUsageFlagBits = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT;
	return vkfCreateBuffer(createInfo, buffer);
}

VKFAPI VkfResult  vkfCreateIndexBuffer(VkfBufferCreateInfo* createInfo, VkfBuffer** buffer) {
	createInfo->bufferUsageFlagBits = VK_BUFFER_USAGE_INDEX_BUFFER_BIT;
	return vkfCreateBuffer(createInfo, buffer);
}

VKFAPI VkfResult  vkfCreateUniformBuffer(VkfBufferCreateInfo* createInfo, VkfBuffer** buffer) {
	createInfo->bufferUsageFlagBits = VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT;

	return vkfCreateBuffer(createInfo, buffer);
}

VKFAPI VkfResult  vkfCreateStagingBuffer(VkfBufferCreateInfo* createInfo, VkfBuffer** buffer) {
	createInfo->bufferUsageFlagBits = VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
	return vkfCreateBuffer(createInfo, buffer);
}

VkfResult vkfBufferAddElement(VkfBuffer* buffer, uint32_t binding, uint32_t location, VkFormat format, uint32_t offset) {
	if(NULL == buffer->pNext) {
		return VKF_PARAMETER_INVALID;
	}

	VkfVertexInputAttributeDescription* vertexInputAttributeDescription = (VkfVertexInputAttributeDescription*)buffer->pNext;

	uint32_t i = vertexInputAttributeDescription->descriptionCount;
	vertexInputAttributeDescription->descriptions[i].binding = binding;
	vertexInputAttributeDescription->descriptions[i].location = location;
	vertexInputAttributeDescription->descriptions[i].format = format;
	vertexInputAttributeDescription->descriptions[i].offset = offset;
	vertexInputAttributeDescription->descriptionCount++;
	buffer->binding = binding;

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfUploadBuffer(VkfBuffer* buffer, uint8_t* src, uint64_t size, uint64_t offset) {
	uint8_t* memory = NULL;

	if(size > buffer->size) {
		return VKF_FAILED;
	}

	VkResult result = vkMapMemory(buffer->device->device, buffer->memory, offset, size, 0, (void **)&memory);
	if(VK_SUCCESS != result) {
		return VKF_FAILED;
	}

	memcpy(memory, src, size);

	vkUnmapMemory(buffer->device->device, buffer->memory);
	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfDestroyBuffer(VkfBuffer* buffer) {
	if(buffer->pNext) {
		VkfVertexInputAttributeDescription* bufferBinding = (VkfVertexInputAttributeDescription*)buffer->pNext;
		if(bufferBinding->sType == VKF_S_VERTEX_BUFFER_BINDING_INFO) {
			free(bufferBinding);
		}
	}

	vkFreeMemory(buffer->device->device, buffer->memory, NULL);
	vkDestroyBuffer(buffer->device->device, buffer->buffer, NULL);
	free(buffer);

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfInitDescriptorPool(VkfDescriptorPoolCreateInfo* createInfo, VkfDescriptorPool** descriptorPool) {
	(*descriptorPool) = (VkfDescriptorPool*)malloc(sizeof(VkfDescriptorPool));
	if(NULL == (*descriptorPool)) {
		return VKF_FAILED;
	}
	(*descriptorPool)->device = createInfo->device;
	(*descriptorPool)->poolSizeCount = 0;

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfCreateDescriptorPool(VkfDescriptorPool* descriptorPool) {

	VkDescriptorPoolCreateInfo descriptorPoolCreateInfo = {0};
	descriptorPoolCreateInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
	descriptorPoolCreateInfo.flags = VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT;
	descriptorPoolCreateInfo.poolSizeCount = descriptorPool->poolSizeCount;
	descriptorPoolCreateInfo.pPoolSizes = descriptorPool->poolSize;

	// TODO We might want to change that.
	descriptorPoolCreateInfo.maxSets = descriptorPool->poolSizeCount;

	VkDescriptorPool descriptorPoolHandle = VK_NULL_HANDLE;
	VkResult result = vkCreateDescriptorPool(descriptorPool->device->device, &descriptorPoolCreateInfo, NULL, &descriptorPoolHandle);
	if(VK_SUCCESS != result) {
		printf("vkCreateDescriptorPool failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}

	descriptorPool->descriptorPool = descriptorPoolHandle;

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfDescriptorPoolAdd(VkfDescriptorPool* descriptorPool, VkDescriptorType descriptorType, uint32_t count) {
	descriptorPool->poolSize[descriptorPool->poolSizeCount].type = descriptorType;
	descriptorPool->poolSize[descriptorPool->poolSizeCount].descriptorCount = count;
	descriptorPool->poolSizeCount++;

	return VKF_SUCCESS;
}

VkfResult vkfDestroyDescriptorPool(VkfDescriptorPool* descriptorPool) {
	vkDestroyDescriptorPool(descriptorPool->device->device, descriptorPool->descriptorPool, NULL);
	free(descriptorPool);

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfInitDescriptorSet(VkfDescriptorSetCreateInfo* createInfo, VkfDescriptorSet** descriptorSet) {
	(*descriptorSet) = (VkfDescriptorSet*)malloc(sizeof(VkfDescriptorSet));
	if(NULL == (*descriptorSet)) {
		return VKF_FAILED;
	}
	memset((*descriptorSet), 0, sizeof(VkfDescriptorSet));

	(*descriptorSet)->device = createInfo->device;
	(*descriptorSet)->descriptorPool = createInfo->descriptorPool;
	(*descriptorSet)->descriptorSetLayout = createInfo->descriptorSetLayout;
	(*descriptorSet)->writeDescriptorSetCount = 0;
	for(uint32_t i = 0; i < 8; i++) {
		memset((void*)&(*descriptorSet)->writeDescriptorSet[i], 0, sizeof(VkWriteDescriptorSet));
	}
	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfCreateDescriptorSet(VkfDescriptorSet* descriptorSet) {


	VkDescriptorSetAllocateInfo descriptorSetAllocateInfo = {0};
	descriptorSetAllocateInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
	descriptorSetAllocateInfo.descriptorPool = descriptorSet->descriptorPool->descriptorPool;
	descriptorSetAllocateInfo.descriptorSetCount = 1;
	descriptorSetAllocateInfo.pSetLayouts = &descriptorSet->descriptorSetLayout->descriptorSetLayout;

	VkDescriptorSet descriptorSetHandle = VK_NULL_HANDLE;
	VkResult result = vkAllocateDescriptorSets(descriptorSet->device->device, &descriptorSetAllocateInfo, &descriptorSetHandle);
	if(VK_SUCCESS != result) {
		printf("vkCreateDescriptorPool failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}
	for(uint32_t i = 0; i < descriptorSet->writeDescriptorSetCount; i++) {
		descriptorSet->writeDescriptorSet[i].dstSet = descriptorSetHandle;
	}
	vkUpdateDescriptorSets(descriptorSet->device->device, descriptorSet->writeDescriptorSetCount, descriptorSet->writeDescriptorSet, 0, NULL);

	descriptorSet->descriptorSet = descriptorSetHandle;
	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfDescriptorSetBindUniformBuffer(VkfDescriptorSet* descriptorSet, uint32_t binding, VkfBuffer* buffer) {
	assert((VK_NULL_HANDLE == descriptorSet->descriptorSet) && "You must use this function before creating the descriptor set.");

	// TODO We might want to update everytime we change something.
	memset((void*)&descriptorSet->writeDescriptorSet[descriptorSet->writeDescriptorSetCount], 0, sizeof(VkWriteDescriptorSet));
	descriptorSet->writeDescriptorSet[descriptorSet->writeDescriptorSetCount].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
	descriptorSet->writeDescriptorSet[descriptorSet->writeDescriptorSetCount].descriptorCount = 1; // TODO Do we need to adapt something here?
	descriptorSet->writeDescriptorSet[descriptorSet->writeDescriptorSetCount].descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
	descriptorSet->writeDescriptorSet[descriptorSet->writeDescriptorSetCount].pBufferInfo = buffer->descriptorBufferInfo;
	descriptorSet->writeDescriptorSet[descriptorSet->writeDescriptorSetCount].dstBinding = binding;
	descriptorSet->writeDescriptorSetCount++;

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfDescriptorSetBindTexture(VkfDescriptorSet* descriptorSet, uint32_t binding, struct VkfTexture* texture, VkfTextureSampler* textureSampler) {
	VkDescriptorImageInfo* descriptorImageInfo = (VkDescriptorImageInfo*)malloc(sizeof(VkDescriptorImageInfo));
	if(NULL == descriptorImageInfo) {
		return VKF_MEMORY_ALLOCATION;
	}

	memset(descriptorImageInfo, 0, sizeof(VkDescriptorImageInfo));
	if(texture) {
		descriptorImageInfo->imageView = texture->imageView;
		descriptorImageInfo->imageLayout = texture->imageLayout;
	}
	if(textureSampler) {
		descriptorImageInfo->sampler = textureSampler->textureSampler;
	}

	memset((void*)&descriptorSet->writeDescriptorSet[descriptorSet->writeDescriptorSetCount], 0, sizeof(VkWriteDescriptorSet));
	descriptorSet->writeDescriptorSet[descriptorSet->writeDescriptorSetCount].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
	// TODO Do we need to adapt something here?
	descriptorSet->writeDescriptorSet[descriptorSet->writeDescriptorSetCount].descriptorCount = 1;

	descriptorSet->writeDescriptorSet[descriptorSet->writeDescriptorSetCount].descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
	descriptorSet->writeDescriptorSet[descriptorSet->writeDescriptorSetCount].pImageInfo = descriptorImageInfo;
	descriptorSet->writeDescriptorSet[descriptorSet->writeDescriptorSetCount].dstBinding = binding;
	descriptorSet->writeDescriptorSetCount++;

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfDestroyDescriptorSet(VkfDescriptorSet* descriptorSet) {
	for(uint32_t i = 0; i < descriptorSet->writeDescriptorSetCount; i++) {
		if(descriptorSet->writeDescriptorSet[i].pImageInfo) {
			free((void*)descriptorSet->writeDescriptorSet[i].pImageInfo);
		}
	}
	vkFreeDescriptorSets(descriptorSet->device->device, descriptorSet->descriptorPool->descriptorPool, 1, &descriptorSet->descriptorSet);
	free(descriptorSet);

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfInitDescriptorSetLayout(VkfDescriptorSetLayoutCreateInfo* createInfo, VkfDescriptorSetLayout** layout) {
	(*layout) = (VkfDescriptorSetLayout*)malloc(sizeof(VkfDescriptorSetLayout));
	if(NULL == (*layout)) {
		return VKF_FAILED;
	}
	memset((*layout), 0, sizeof(VkfDescriptorSetLayout));

	(*layout)->device = createInfo->device;
	for(uint32_t i = 0; i < 8; i++) {
		memset(&(*layout)->bindings[i], 0, sizeof(VkDescriptorSetLayoutBinding));
	}
	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfDescriptorSetLayoutBind(VkfDescriptorSetLayout* layout, uint32_t binding, uint32_t count, VkDescriptorType descriptorType, VkShaderStageFlags shaderStageFlags) {
	layout->bindings[layout->bindingCount].binding = binding;
	layout->bindings[layout->bindingCount].descriptorType = descriptorType;
	layout->bindings[layout->bindingCount].stageFlags = shaderStageFlags;
	layout->bindings[layout->bindingCount].descriptorCount = count;
	layout->bindingCount++;

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfCreateDescriptorSetLayout(VkfDescriptorSetLayout* layout) {

	VkDescriptorSetLayoutCreateInfo descriptorSetLayoutCreateInfo = {0};
	descriptorSetLayoutCreateInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
	descriptorSetLayoutCreateInfo.bindingCount = layout->bindingCount;
	descriptorSetLayoutCreateInfo.pBindings = layout->bindings;

	VkDescriptorSetLayout descriptorSetLayoutHandle = VK_NULL_HANDLE;
	VkResult result = vkCreateDescriptorSetLayout(layout->device->device, &descriptorSetLayoutCreateInfo, NULL, &descriptorSetLayoutHandle);
	if(VK_SUCCESS != result) {
		printf("vkCreateDescriptorSetLayout failed: %s\n", vkfVkResultToString(result));
		return VKF_FAILED;
	}

	layout->descriptorSetLayout = descriptorSetLayoutHandle;

	return VKF_SUCCESS;
}

VKFAPI VkfResult  vkfDestroyDescriptorSetLayout(VkfDescriptorSetLayout* layout) {
	vkDestroyDescriptorSetLayout(layout->device->device, layout->descriptorSetLayout, NULL);
	free(layout);

	return VKF_SUCCESS;
}
