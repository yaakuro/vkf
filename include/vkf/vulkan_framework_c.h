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

#ifndef VULKAN_FRAMEWORK_C_H
#define VULKAN_FRAMEWORK_C_H

#include <vkf/vulkan_framework_types.h>
#include <vkf/vulkan_framework_windows_c.h>

#define VKF_VAR_EXPORT VKFAPI
#define VKF_FUN_EXPORT VKFAPI

#define CHECK_VULKAN(VULKAN_FUNCTION) 	{ \
		VkResult result = VULKAN_FUNCTION; \
		if(VK_SUCCESS != result) { \
			exit(1); \
		} \
	} \

// Macro to get a procedure address based on a vulkan instance
#define GET_INSTANCE_PROC_ADDR(inst, entrypoint)                                            \
	{                                                                                       \
		vk##entrypoint = (PFN_vk##entrypoint)vkGetInstanceProcAddr(inst, "vk" #entrypoint); \
		if(vk##entrypoint == NULL) {                                                        \
			exit(1);                                                                        \
		}                                                                                   \
	}

// Macro to get a procedure address based on a vulkan device
#define GET_DEVICE_PROC_ADDR(dev, entrypoint)                                            \
	{                                                                                    \
		vk##entrypoint = (PFN_vk##entrypoint)vkGetDeviceProcAddr(dev, "vk" #entrypoint); \
		if(vk##entrypoint == NULL) {                                                     \
			exit(1);                                                                     \
		}                                                                                \
	}

#define VKF_FUNCTION_EXPORT(entrypoint) VKF_VAR_EXPORT PFN_##entrypoint entrypoint;
#define VKF_FUNCTION_DEFINE(entrypoint) PFN_##entrypoint entrypoint = NULL;
#define VKF_INSTANCE_FUNCTION_LOAD(LIBRARY, entrypoint) entrypoint = (PFN_##entrypoint)vkGetInstanceProcAddr(NULL, #entrypoint);
#define VKF_DEVICE_FUNCTION_LOAD(LIBRARY, entrypoint) entrypoint = (PFN_##entrypoint)vkGetDeviceProcAddr(NULL, #entrypoint);

// -----------------------------------------------------------------------------
// Vulkan 1.0
//

#ifdef VK_NO_PROTOTYPES
VKF_FUNCTION_EXPORT(vkCreateInstance)
VKF_FUNCTION_EXPORT(vkDestroyInstance)
VKF_FUNCTION_EXPORT(vkEnumeratePhysicalDevices)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceFeatures)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceFormatProperties)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceImageFormatProperties)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceProperties)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceQueueFamilyProperties)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceMemoryProperties)
VKF_FUNCTION_EXPORT(vkGetInstanceProcAddr)
VKF_FUNCTION_EXPORT(vkGetDeviceProcAddr)
VKF_FUNCTION_EXPORT(vkCreateDevice)
VKF_FUNCTION_EXPORT(vkDestroyDevice)
VKF_FUNCTION_EXPORT(vkEnumerateInstanceExtensionProperties)
VKF_FUNCTION_EXPORT(vkEnumerateDeviceExtensionProperties)
VKF_FUNCTION_EXPORT(vkEnumerateInstanceLayerProperties)
VKF_FUNCTION_EXPORT(vkEnumerateDeviceLayerProperties)
VKF_FUNCTION_EXPORT(vkGetDeviceQueue)
VKF_FUNCTION_EXPORT(vkQueueSubmit)
VKF_FUNCTION_EXPORT(vkQueueWaitIdle)
VKF_FUNCTION_EXPORT(vkDeviceWaitIdle)
VKF_FUNCTION_EXPORT(vkAllocateMemory)
VKF_FUNCTION_EXPORT(vkFreeMemory)
VKF_FUNCTION_EXPORT(vkMapMemory)
VKF_FUNCTION_EXPORT(vkUnmapMemory)
VKF_FUNCTION_EXPORT(vkFlushMappedMemoryRanges)
VKF_FUNCTION_EXPORT(vkInvalidateMappedMemoryRanges)
VKF_FUNCTION_EXPORT(vkGetDeviceMemoryCommitment)
VKF_FUNCTION_EXPORT(vkBindBufferMemory)
VKF_FUNCTION_EXPORT(vkBindImageMemory)
VKF_FUNCTION_EXPORT(vkGetBufferMemoryRequirements)
VKF_FUNCTION_EXPORT(vkGetImageMemoryRequirements)
VKF_FUNCTION_EXPORT(vkGetImageSparseMemoryRequirements)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceSparseImageFormatProperties)
VKF_FUNCTION_EXPORT(vkQueueBindSparse)
VKF_FUNCTION_EXPORT(vkCreateFence)
VKF_FUNCTION_EXPORT(vkDestroyFence)
VKF_FUNCTION_EXPORT(vkResetFences)
VKF_FUNCTION_EXPORT(vkGetFenceStatus)
VKF_FUNCTION_EXPORT(vkWaitForFences)
VKF_FUNCTION_EXPORT(vkCreateSemaphore)
VKF_FUNCTION_EXPORT(vkDestroySemaphore)
VKF_FUNCTION_EXPORT(vkCreateEvent)
VKF_FUNCTION_EXPORT(vkDestroyEvent)
VKF_FUNCTION_EXPORT(vkGetEventStatus)
VKF_FUNCTION_EXPORT(vkSetEvent)
VKF_FUNCTION_EXPORT(vkResetEvent)
VKF_FUNCTION_EXPORT(vkCreateQueryPool)
VKF_FUNCTION_EXPORT(vkDestroyQueryPool)
VKF_FUNCTION_EXPORT(vkGetQueryPoolResults)
VKF_FUNCTION_EXPORT(vkCreateBuffer)
VKF_FUNCTION_EXPORT(vkDestroyBuffer)
VKF_FUNCTION_EXPORT(vkCreateBufferView)
VKF_FUNCTION_EXPORT(vkDestroyBufferView)
VKF_FUNCTION_EXPORT(vkCreateImage)
VKF_FUNCTION_EXPORT(vkDestroyImage)
VKF_FUNCTION_EXPORT(vkGetImageSubresourceLayout)
VKF_FUNCTION_EXPORT(vkCreateImageView)
VKF_FUNCTION_EXPORT(vkDestroyImageView)
VKF_FUNCTION_EXPORT(vkCreateShaderModule)
VKF_FUNCTION_EXPORT(vkDestroyShaderModule)
VKF_FUNCTION_EXPORT(vkCreatePipelineCache)
VKF_FUNCTION_EXPORT(vkDestroyPipelineCache)
VKF_FUNCTION_EXPORT(vkGetPipelineCacheData)
VKF_FUNCTION_EXPORT(vkMergePipelineCaches)
VKF_FUNCTION_EXPORT(vkCreateGraphicsPipelines)
VKF_FUNCTION_EXPORT(vkCreateComputePipelines)
VKF_FUNCTION_EXPORT(vkDestroyPipeline)
VKF_FUNCTION_EXPORT(vkCreatePipelineLayout)
VKF_FUNCTION_EXPORT(vkDestroyPipelineLayout)
VKF_FUNCTION_EXPORT(vkCreateSampler)
VKF_FUNCTION_EXPORT(vkDestroySampler)
VKF_FUNCTION_EXPORT(vkCreateDescriptorSetLayout)
VKF_FUNCTION_EXPORT(vkDestroyDescriptorSetLayout)
VKF_FUNCTION_EXPORT(vkCreateDescriptorPool)
VKF_FUNCTION_EXPORT(vkDestroyDescriptorPool)
VKF_FUNCTION_EXPORT(vkResetDescriptorPool)
VKF_FUNCTION_EXPORT(vkAllocateDescriptorSets)
VKF_FUNCTION_EXPORT(vkFreeDescriptorSets)
VKF_FUNCTION_EXPORT(vkUpdateDescriptorSets)
VKF_FUNCTION_EXPORT(vkCreateFramebuffer)
VKF_FUNCTION_EXPORT(vkDestroyFramebuffer)
VKF_FUNCTION_EXPORT(vkCreateRenderPass)
VKF_FUNCTION_EXPORT(vkDestroyRenderPass)
VKF_FUNCTION_EXPORT(vkGetRenderAreaGranularity)
VKF_FUNCTION_EXPORT(vkCreateCommandPool)
VKF_FUNCTION_EXPORT(vkDestroyCommandPool)
VKF_FUNCTION_EXPORT(vkResetCommandPool)
VKF_FUNCTION_EXPORT(vkAllocateCommandBuffers)
VKF_FUNCTION_EXPORT(vkFreeCommandBuffers)
VKF_FUNCTION_EXPORT(vkBeginCommandBuffer)
VKF_FUNCTION_EXPORT(vkEndCommandBuffer)
VKF_FUNCTION_EXPORT(vkResetCommandBuffer)
VKF_FUNCTION_EXPORT(vkCmdBindPipeline)
VKF_FUNCTION_EXPORT(vkCmdSetViewport)
VKF_FUNCTION_EXPORT(vkCmdSetScissor)
VKF_FUNCTION_EXPORT(vkCmdSetLineWidth)
VKF_FUNCTION_EXPORT(vkCmdSetDepthBias)
VKF_FUNCTION_EXPORT(vkCmdSetBlendConstants)
VKF_FUNCTION_EXPORT(vkCmdSetDepthBounds)
VKF_FUNCTION_EXPORT(vkCmdSetStencilCompareMask)
VKF_FUNCTION_EXPORT(vkCmdSetStencilWriteMask)
VKF_FUNCTION_EXPORT(vkCmdSetStencilReference)
VKF_FUNCTION_EXPORT(vkCmdBindDescriptorSets)
VKF_FUNCTION_EXPORT(vkCmdBindIndexBuffer)
VKF_FUNCTION_EXPORT(vkCmdBindVertexBuffers)
VKF_FUNCTION_EXPORT(vkCmdDraw)
VKF_FUNCTION_EXPORT(vkCmdDrawIndexed)
VKF_FUNCTION_EXPORT(vkCmdDrawIndirect)
VKF_FUNCTION_EXPORT(vkCmdDrawIndexedIndirect)
VKF_FUNCTION_EXPORT(vkCmdDispatch)
VKF_FUNCTION_EXPORT(vkCmdDispatchIndirect)
VKF_FUNCTION_EXPORT(vkCmdCopyBuffer)
VKF_FUNCTION_EXPORT(vkCmdCopyImage)
VKF_FUNCTION_EXPORT(vkCmdBlitImage)
VKF_FUNCTION_EXPORT(vkCmdCopyBufferToImage)
VKF_FUNCTION_EXPORT(vkCmdCopyImageToBuffer)
VKF_FUNCTION_EXPORT(vkCmdUpdateBuffer)
VKF_FUNCTION_EXPORT(vkCmdFillBuffer)
VKF_FUNCTION_EXPORT(vkCmdClearColorImage)
VKF_FUNCTION_EXPORT(vkCmdClearDepthStencilImage)
VKF_FUNCTION_EXPORT(vkCmdClearAttachments)
VKF_FUNCTION_EXPORT(vkCmdResolveImage)
VKF_FUNCTION_EXPORT(vkCmdSetEvent)
VKF_FUNCTION_EXPORT(vkCmdResetEvent)
VKF_FUNCTION_EXPORT(vkCmdWaitEvents)
VKF_FUNCTION_EXPORT(vkCmdPipelineBarrier)
VKF_FUNCTION_EXPORT(vkCmdBeginQuery)
VKF_FUNCTION_EXPORT(vkCmdEndQuery)
VKF_FUNCTION_EXPORT(vkCmdResetQueryPool)
VKF_FUNCTION_EXPORT(vkCmdWriteTimestamp)
VKF_FUNCTION_EXPORT(vkCmdCopyQueryPoolResults)
VKF_FUNCTION_EXPORT(vkCmdPushConstants)
VKF_FUNCTION_EXPORT(vkCmdBeginRenderPass)
VKF_FUNCTION_EXPORT(vkCmdNextSubpass)
VKF_FUNCTION_EXPORT(vkCmdEndRenderPass)
VKF_FUNCTION_EXPORT(vkCmdExecuteCommands)
#endif

// -----------------------------------------------------------------------------
// Vulkan 1.1
//
#ifdef VK_NO_PROTOTYPES
VKF_FUNCTION_EXPORT(vkEnumerateInstanceVersion)
VKF_FUNCTION_EXPORT(vkBindBufferMemory2)
VKF_FUNCTION_EXPORT(vkBindImageMemory2)
VKF_FUNCTION_EXPORT(vkGetDeviceGroupPeerMemoryFeatures)
VKF_FUNCTION_EXPORT(vkCmdSetDeviceMask)
VKF_FUNCTION_EXPORT(vkCmdDispatchBase)
VKF_FUNCTION_EXPORT(vkEnumeratePhysicalDeviceGroups)
VKF_FUNCTION_EXPORT(vkGetImageMemoryRequirements2)
VKF_FUNCTION_EXPORT(vkGetBufferMemoryRequirements2)
VKF_FUNCTION_EXPORT(vkGetImageSparseMemoryRequirements2)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceFeatures2)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceProperties2)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceFormatProperties2)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceImageFormatProperties2)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceQueueFamilyProperties2)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceMemoryProperties2)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceSparseImageFormatProperties2)
VKF_FUNCTION_EXPORT(vkTrimCommandPool)
VKF_FUNCTION_EXPORT(vkGetDeviceQueue2)
VKF_FUNCTION_EXPORT(vkCreateSamplerYcbcrConversion)
VKF_FUNCTION_EXPORT(vkDestroySamplerYcbcrConversion)
VKF_FUNCTION_EXPORT(vkCreateDescriptorUpdateTemplate)
VKF_FUNCTION_EXPORT(vkDestroyDescriptorUpdateTemplate)
VKF_FUNCTION_EXPORT(vkUpdateDescriptorSetWithTemplate)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceExternalBufferProperties)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceExternalFenceProperties)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceExternalSemaphoreProperties)
VKF_FUNCTION_EXPORT(vkGetDescriptorSetLayoutSupport)
#endif

// -----------------------------------------------------------------------------
// KHR Swapchain
//
#ifdef VK_NO_PROTOTYPES
VKF_FUNCTION_EXPORT(vkCreateSwapchainKHR)
VKF_FUNCTION_EXPORT(vkDestroySwapchainKHR)
VKF_FUNCTION_EXPORT(vkGetSwapchainImagesKHR)
VKF_FUNCTION_EXPORT(vkAcquireNextImageKHR)
VKF_FUNCTION_EXPORT(vkQueuePresentKHR)
VKF_FUNCTION_EXPORT(vkGetDeviceGroupPresentCapabilitiesKHR)
VKF_FUNCTION_EXPORT(vkGetDeviceGroupSurfacePresentModesKHR)
VKF_FUNCTION_EXPORT(vkGetPhysicalDevicePresentRectanglesKHR)
VKF_FUNCTION_EXPORT(vkAcquireNextImage2KHR)
#endif

// -----------------------------------------------------------------------------
// KHR Surface
//
#ifdef VK_NO_PROTOTYPES
VKF_FUNCTION_EXPORT(vkDestroySurfaceKHR)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceSurfaceSupportKHR)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceSurfaceCapabilitiesKHR)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceSurfaceFormatsKHR)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceSurfacePresentModesKHR)
#endif

// -----------------------------------------------------------------------------
// KHR Display
//
#ifdef VK_NO_PROTOTYPES
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceDisplayPropertiesKHR)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceDisplayPlanePropertiesKHR)
VKF_FUNCTION_EXPORT(vkGetDisplayPlaneSupportedDisplaysKHR)
VKF_FUNCTION_EXPORT(vkGetDisplayModePropertiesKHR)
VKF_FUNCTION_EXPORT(vkCreateDisplayModeKHR)
VKF_FUNCTION_EXPORT(vkGetDisplayPlaneCapabilitiesKHR)
VKF_FUNCTION_EXPORT(vkCreateDisplayPlaneSurfaceKHR)
#endif

// -----------------------------------------------------------------------------
// KHR Display Swapchain
//
#ifdef VK_NO_PROTOTYPES
VKF_FUNCTION_EXPORT(vkCreateSharedSwapchainsKHR)
#endif

// -----------------------------------------------------------------------------
// KHR Multiview
//
#ifdef VK_NO_PROTOTYPES
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceFeatures2KHR)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceProperties2KHR)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceFormatProperties2KHR)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceImageFormatProperties2KHR)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceQueueFamilyProperties2KHR)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceMemoryProperties2KHR)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceSparseImageFormatProperties2KHR)
#endif

// -----------------------------------------------------------------------------
// KHR Xcb Surface
//
#if defined(VK_USE_PLATFORM_XCB_KHR) && defined(VK_NO_PROTOTYPES)
VKF_FUNCTION_EXPORT(vkCreateXcbSurfaceKHR)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceXcbPresentationSupportKHR)
#endif

// -----------------------------------------------------------------------------
// KHR Xlib Surface
//
#if defined(VK_USE_PLATFORM_XLIB_KHR) && defined(VK_NO_PROTOTYPES)
VKF_FUNCTION_EXPORT(vkCreateXlibSurfaceKHR)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceXlibPresentationSupportKHR)
#endif

// -----------------------------------------------------------------------------
// KHR Win32 Surface
//
#if defined(VK_USE_PLATFORM_WIN32_KHR) && defined(VK_NO_PROTOTYPES)
VKF_FUNCTION_EXPORT(vkCreateWin32SurfaceKHR)
VKF_FUNCTION_EXPORT(vkGetPhysicalDeviceWin32PresentationSupportKHR)
#endif

// -----------------------------------------------------------------------------
// KHR Android Surface
//
#if defined(VK_USE_PLATFORM_ANDROID_KHR) && defined(VK_NO_PROTOTYPES)
VKF_FUNCTION_EXPORT(vkCreateAndroidSurfaceKHR)
#endif

// -----------------------------------------------------------------------------
// KHR MacOS Surface
//
#if defined(VK_USE_PLATFORM_MACOS_MVK) && defined(VK_NO_PROTOTYPES)
VKF_FUNCTION_EXPORT(vkCreateMacOSSurfaceMVK)
#endif

// -----------------------------------------------------------------------------
// KHR IOS Surface
//
#if defined(VK_USE_PLATFORM_IOS_MVK) && defined(VK_NO_PROTOTYPES)
VKF_FUNCTION_EXPORT(vkCreateIOSSurfaceMVK)
#endif

#define VKF_DEFINE_HANDLE(object) typedef struct object##_T* object;
#define SIZE_OF_ARRAY(ARRAY_NAME) sizeof(ARRAY_NAME)/sizeof(ARRAY_NAME[0])

#ifdef __cplusplus
extern "C" {
#endif

#define VKF_MAX_SHADER_STAGE_COUNT 4

VKFAPI void vkfInit();
VKFAPI void vkfDestroy();
VKFAPI void vkfLoadVulkanLibrary();
VKFAPI uint32_t vkfBytesPerPixelFromFormat(VkFormat format);
VKFAPI uint32_t vkfBitsPerPixelFromFormat(VkFormat format);
VKFAPI const char* vkfVkPresentModeKHRToString(VkPresentModeKHR presentMode);
VKFAPI const char* vkfVkPhysicalDeviceTypeToString(VkPhysicalDeviceType physicalDeviceType);
VKFAPI const char* vkfVkResultToString(VkResult result);

extern VkSurfaceFormatKHR preferedColorFormat;

typedef enum VkfStructureInfo {
	VKF_S_INSTANCE_CREATE_INFO,
	VKF_S_DEVICE_CREATE_INFO,
	VKF_S_SURFACE_CREATE_INFO,
	VKF_S_SWAPCHAIN_CREATE_INFO,
	VKF_S_FRAMEBUFFER_CREATE_INFO,
	VKF_S_BUFFER_CREATE_INFO,
	VKF_S_SHADERMODULE_CREATE_INFO,
	VKF_S_DESCRIPTORPOOL_CREATE_INFO,
	VKF_S_TEXTURE_SAMPLER_CREATE_INFO,
	VKF_S_VERTEX_BUFFER_BINDING_INFO,
	VKF_S_MAX_ENUM = 0x7FFFFFFF
} VkfStructureInfo;


typedef struct VkfTextureSamplerCreateInfo {
	struct VkfDevice* device;
	VkFilter minFilter;
	VkFilter magFilter;
	VkSamplerAddressMode addressModeU;
	VkSamplerAddressMode addressModeV;
	VkSamplerAddressMode addressModeW;
} VkfTextureSamplerCreateInfo;

typedef struct VkfTextureSampler {
	struct VkfDevice* device;
	VkSampler textureSampler;
} VkfTextureSampler;

typedef struct VkfTexture {
	VkDevice device;
	VkImage image;
	VkImageView imageView;
	VkImageLayout imageLayout;
	VkDeviceMemory memory;
	uint64_t size;
	VkFormat format;
	uint32_t width;
	uint32_t height;
	uint32_t depth;
	uint32_t isSwapchainImage;
} VkfTexture;

typedef struct VkfDebug {
	VkInstance instance;
	VkDebugReportCallbackEXT callback;
} VkfDebug;

typedef struct VkfInstanceCreateInfo {
	const char* title;
	uint32_t apiVersion;
	int numberOfLayers;
	const char* layerNames;
	int enableDebuging;
} VkfInstanceCreateInfo;

typedef struct VkfInstance {
	VkInstance instance;
	uint32_t numberOfPhysicalDevices;
	VkPhysicalDevice* physicalDevices;
	char* title;
} VkfInstance;

typedef struct VkfDeviceCreateInfo {
	VkfStructureInfo sType;
	struct VkfInstance* instance;
	VkPhysicalDeviceType physicalDeviceType;
} VkfDeviceCreateInfo;

typedef struct VkfDevice {
	VkDevice device;
	VkPhysicalDevice physicalDevice;
	uint32_t familyQueueIndex;
	uint32_t maxFamilyQueueCount;
	uint32_t queueFamilyCount;
	VkQueueFamilyProperties* queueFamilyProperties;
} VkfDevice;

typedef struct VkfSurfaceCreateInfo {
	VkfStructureInfo sType;
	struct VkfInstance* instance;
	struct VkfDevice* device;
	struct VkfWindow* window;
} VkfSurfaceCreateInfo;

typedef struct VkfSurface {
	VkInstance instance;
	VkSurfaceKHR surface;
	VkSurfaceCapabilitiesKHR surfaceCaps;
	VkPresentModeKHR presentMode;
	VkFormat colorFormat;
	VkColorSpaceKHR colorSpace;
	VkExtent2D extent2D;
	uint32_t queueFamilyIndex;
} VkfSurface;

typedef struct VkfRenderPassCreateInfo {
	VkfStructureInfo sType;
	struct VkfDevice* device;
	struct VkfRenderPass* renderPass;
	VkFormat format;
	VkImageLayout initialImageLayout;
	VkImageLayout finalImageLayout;
	uint32_t width;
	uint32_t height;
} VkfRenderPassCreateInfo;

typedef struct VkfRenderPass {
	VkDevice device;
	VkRenderPass renderPass;
	uint32_t numberOfAttachments;
	uint32_t colorAttachmentCount;
	VkAttachmentDescription colorAttachments[4];
	VkAttachmentDescription depthStencilAttachment;
} VkfRenderPass;

typedef struct VkfSwapchainCreateInfo {
	VkfStructureInfo sType;
	struct VkfDevice* device;
	struct VkfSurface* surface;
} VkfSwapchainCreateInfo;

typedef struct VkfSwapchain {
	struct VkfDevice* device;
	VkSwapchainKHR swapChain;
	VkSwapchainKHR oldSwapchain;
	VkExtent2D extent2D;
	uint32_t numberOfImages;
	struct VkfTexture** images;
	struct VkfTexture* depthStencil;
	struct VkfRenderPass* renderPass;
	uint32_t framebufferCount;
	struct VkfFrameBuffer** framebuffers;
} VkfSwapchain;

typedef struct VkfFrameBufferCreateInfo {
	VkfStructureInfo sType;
	struct VkfDevice* device;
	struct VkfRenderPass* renderPass;
	uint32_t width;
	uint32_t height;
} VkfFrameBufferCreateInfo;

typedef struct VkfFrameBuffer {
	VkDevice device;
	VkFramebuffer framebuffer;
	uint32_t width;
	uint32_t height;
	uint32_t attachmentCount;
	VkImageView attachments[8];
} VkfFrameBuffer;

typedef struct VkfShaderModuleCreateInfo {
	VkfStructureInfo sType;
	struct VkfDevice* device;
	const char* filename;
	const char* entryName;
	VkShaderStageFlagBits shaderStageFlagBits;
	uint32_t shaderSize;
	uint32_t* shaderBinary;
} VkfShaderModuleCreateInfo;

typedef struct VkfShaderModule {
	struct VkfDevice* device;
	char* entryName;
	uint32_t* binary;
	uint32_t binarySize;
	VkShaderModule shaderModule;
	VkShaderStageFlagBits shaderStageFlagBits;
} VkfShaderModule;

typedef struct VkfVertexInputAttributeDescription {
	VkfStructureInfo sType;
	const void* pNext;
	uint32_t descriptionCount;
	VkVertexInputAttributeDescription descriptions[8];
} VkfVertexInputAttributeDescription;

typedef struct VkfBufferCreateInfo {
	VkfStructureInfo sType;
	const void* pNext;
	struct VkfDevice* device;
	VkDeviceSize size;
	uint32_t stride;
	VkBufferUsageFlagBits bufferUsageFlagBits;
	VkFlags memoryAllocationflags;
} VkfBufferCreateInfo;

typedef struct VkfBuffer {
	const void* pNext;
	struct VkfDevice* device;
	VkBuffer buffer;
	VkDeviceMemory memory;
	VkDeviceSize size;
	uint32_t binding;
	uint32_t stride;
	VkDescriptorBufferInfo* descriptorBufferInfo;
} VkfBuffer;

typedef struct VkfDescriptorPoolCreateInfo {
	struct VkfDevice* device;
} VkfDescriptorPoolCreateInfo;

typedef struct VkfDescriptorPool {
	struct VkfDevice* device;
	VkDescriptorPool descriptorPool;
	uint32_t poolSizeCount;
	VkDescriptorPoolSize poolSize[8];
} VkfDescriptorPool;

typedef struct VkfDescriptorSetLayoutCreateInfo {
	VkfStructureInfo sType;
	struct VkfDevice* device;
} VkfDescriptorSetLayoutCreateInfo;

typedef struct VkfDescriptorSetLayout {
	struct VkfDevice* device;
	VkDescriptorSetLayout descriptorSetLayout;
	uint32_t bindingCount;
	VkDescriptorSetLayoutBinding bindings[8];
} VkfDescriptorSetLayout;

typedef struct VkfDescriptorSetCreateInfo {
	VkfStructureInfo sType;
	struct VkfDevice* device;
	struct VkfDescriptorPool* descriptorPool;
	struct VkfDescriptorSetLayout* descriptorSetLayout;
} VkfDescriptorSetCreateInfo;

typedef struct VkfDescriptorSet {
	struct VkfDevice* device;
	struct VkfDescriptorPool* descriptorPool;
	struct VkfDescriptorSetLayout* descriptorSetLayout;
	VkDescriptorSet descriptorSet;
	uint32_t writeDescriptorSetCount;
	VkWriteDescriptorSet writeDescriptorSet[8];
} VkfDescriptorSet;

typedef struct VkfPipelineCreateInfo {
	VkfStructureInfo sType;
	struct VkfDevice* device;
	struct VkfRenderPass* renderPass;
	struct VkfDescriptorSetLayout* descriptorSetLayout;
	VkExtent2D extent2D;
} VkfPipelineCreateInfo;

typedef struct VkfPipeline {
	struct VkfDevice* device;
	struct VkfRenderPass* renderPass;
	struct VkfDescriptorSetLayout* descriptorSetLayout;
	VkPipeline pipeline;
	VkPipelineLayout pipelineLayout;
	VkExtent2D extent2D;
	uint32_t shaderStageCount;
	VkPipelineShaderStageCreateInfo* shaderStageCreateInfo;
	VkPipelineColorBlendAttachmentState pipelineColorBlendAttachmentState;
	VkPipelineInputAssemblyStateCreateInfo pipelineInputAssemblyStateCreateInfo;
	VkPipelineRasterizationStateCreateInfo pipelineRasterizationStateCreateInfo;
	VkPipelineDepthStencilStateCreateInfo pipelineDepthStencilStateCreateInfo;
	uint32_t vertexInputAttributeDescriptionCount;
	VkVertexInputAttributeDescription* vertexInputAttributeDescription;
	uint32_t vertexInputBindingDescriptionCount;
	VkVertexInputBindingDescription* vertexInputBindingDescription;
} VkfPipeline;


VKFAPI void vkfSetImageLayout(VkCommandBuffer commandBuffer, VkImage image, VkImageAspectFlags aspectMask, VkImageLayout oldImageLayout, VkImageLayout newImageLayout);
VKFAPI uint32_t getMemoryTypeIndex(VkPhysicalDeviceMemoryProperties deviceMemoryProperties, VkMemoryRequirements memoryRequirements, VkFlags properties);

VKFAPI VkfResult vkfCreateDebug(VkfInstance* instance, VkfDebug** debug);
VKFAPI VkfResult vkfDestroyDebug(VkfDebug* debug);

// -----------------------------------------------------------------------------
// Instance
//

VKFAPI VkfResult vkfCreateInstance(VkfInstanceCreateInfo* createInfo, VkfInstance** instance);
VKFAPI VkfResult vkfDestroyInstance(VkfInstance* instance);

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Device
//

VKFAPI VkfResult vkfCreateDevice(VkfDeviceCreateInfo* createInfo, VkfDevice** device);
VKFAPI VkfResult vkfDestroyDevice(VkfDevice* device);

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Surface
//

VKFAPI VkfResult vkfCreateSurface(VkfSurfaceCreateInfo* createInfo, VkfSurface** surface);
VKFAPI VkfResult vkfDestroySurface(VkfSurface* surface);

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Swapchain
//

VKFAPI VkfResult vkfCreateSwapchain(VkfSwapchainCreateInfo* createInfo, VkfSwapchain** swapchain);
VKFAPI VkfResult vkfDestroySwapchain(VkfSwapchain* swapchain);

// -----------------------------------------------------------------------------
// Framebuffer
//

VKFAPI VkfResult vkfInitFrameBuffer(VkfDevice* device, VkfFrameBuffer** framebuffer);
VKFAPI VkfResult vkfCreateFrameBuffer(VkfFrameBufferCreateInfo* createInfo, VkfFrameBuffer** framebuffer);
VKFAPI VkfResult vkfFrameBufferAddColorAttachment(VkfFrameBuffer* framebuffer, VkImageView imageView);
VKFAPI VkfResult vkfFrameBufferAddDepthStencilrAttachment(VkfFrameBuffer* framebuffer, VkImageView imageView);
VKFAPI VkfResult vkfDestroyFrameBuffer(VkfFrameBuffer* framebuffer);

// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// RenderPass
//

VKFAPI VkfResult vkfInitRenderPass(VkfDevice* device, VkfRenderPass** renderPass);
VKFAPI VkfResult vkfCreateRenderPass(VkfDevice* device, VkfRenderPass** renderPass);
VKFAPI VkfResult vkfRenderPassAddColorAttachment(VkfRenderPass* renderPass, VkFormat format, VkImageLayout initialImageLayout, VkImageLayout finalImageLayout);
VKFAPI VkfResult vkfRenderPassAddDepthStencilAttachment(VkfRenderPass* renderPass, VkFormat format, VkImageLayout initialImageLayout);
VKFAPI VkfResult vkfDestroyRenderPass(VkfRenderPass* renderPass);

// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Pipeline
//

VKFAPI VkfResult vkfInitPipeline(VkfPipelineCreateInfo* createInfo, VkfPipeline** pipeline);
VKFAPI VkfResult vkfCreatePipeline(VkfPipeline* pipeline);
VKFAPI VkfResult vkfPipelineAddShader(VkfPipeline* pipeline, VkfShaderModule* shaderModule);
VKFAPI VkfResult vkfPipelineAddVertexState(VkfPipeline* pipeline, VkfBuffer* buffer);
VKFAPI VkfResult vkfDestroyPipeline(VkfPipeline* pipeline);


// -----------------------------------------------------------------------------
// Shader Modules
//

VKFAPI VkfResult vkfCreateShaderModule(VkfShaderModuleCreateInfo* createInfo, VkfShaderModule** shaderModule);
VKFAPI VkfResult vkfCreateVertexShaderModule(VkfShaderModuleCreateInfo* createInfo, VkfShaderModule** shaderModule);
VKFAPI VkfResult vkfCreateGeometryShaderModule(VkfShaderModuleCreateInfo* createInfo, VkfShaderModule** shaderModule);
VKFAPI VkfResult vkfCreateFragmentShaderModule(VkfShaderModuleCreateInfo* createInfo, VkfShaderModule** shaderModule);
VKFAPI VkfResult vkfCreateTessellationControlShaderModule(VkfShaderModuleCreateInfo* createInfo, VkfShaderModule** shaderModule);
VKFAPI VkfResult vkfCreateTessellationEvaluationShaderModule(VkfShaderModuleCreateInfo* createInfo, VkfShaderModule** shaderModule);
VKFAPI VkfResult vkfCreateComputeShaderModule(VkfShaderModuleCreateInfo* createInfo, VkfShaderModule** shaderModule);
VKFAPI VkfResult vkfDestroyShaderModule(VkfShaderModule* shaderModule);

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Buffers
//

VKFAPI VkfResult vkfInitVertexBuffer(VkfBufferCreateInfo* createInfo, VkfBuffer** buffer);
VKFAPI VkfResult vkfInitIndexBuffer(VkfBufferCreateInfo* createInfo, VkfBuffer** buffer);
VKFAPI VkfResult vkfInitUniformBuffer(VkfBufferCreateInfo* createInfo, VkfBuffer** buffer);
VKFAPI VkfResult vkfInitStagingBuffer(VkfBufferCreateInfo* createInfo, VkfBuffer** buffer);
VKFAPI VkfResult vkfInitBuffer(VkfBufferCreateInfo* createInfo, VkfBuffer** buffer);
VKFAPI VkfResult vkfCreateBuffer(VkfBufferCreateInfo* createInfo, VkfBuffer** buffer);
VKFAPI VkfResult vkfCreateVertexBuffer(VkfBufferCreateInfo* createInfo, VkfBuffer** buffer);
VKFAPI VkfResult vkfCreateIndexBuffer(VkfBufferCreateInfo* createInfo, VkfBuffer** buffer);
VKFAPI VkfResult vkfCreateUniformBuffer(VkfBufferCreateInfo* createInfo, VkfBuffer** buffer);
VKFAPI VkfResult vkfCreateStagingBuffer(VkfBufferCreateInfo* createInfo, VkfBuffer** buffer);
VKFAPI VkfResult vkfBufferAddElement(VkfBuffer* buffer, uint32_t binding, uint32_t location, VkFormat format, uint32_t offset);
VKFAPI VkfResult vkfUploadBuffer(VkfBuffer* buffer, uint8_t* src, uint64_t size, uint64_t offset);
VKFAPI VkfResult vkfDestroyBuffer(VkfBuffer* buffer);

// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Descriptors
//

VKFAPI VkfResult vkfInitDescriptorPool(VkfDescriptorPoolCreateInfo* createInfo, VkfDescriptorPool** descriptorPool);
VKFAPI VkfResult vkfCreateDescriptorPool(VkfDescriptorPool* descriptorPool);
VKFAPI VkfResult vkfDescriptorPoolAdd(VkfDescriptorPool* descriptorPool, VkDescriptorType descriptorType, uint32_t count);
VKFAPI VkfResult vkfDestroyDescriptorPool(VkfDescriptorPool* descriptorPool);

VKFAPI VkfResult vkfInitDescriptorSetLayout(VkfDescriptorSetLayoutCreateInfo* createInfo, VkfDescriptorSetLayout** layout);
VKFAPI VkfResult vkfDescriptorSetLayoutBind(VkfDescriptorSetLayout* layout, uint32_t binding, uint32_t count, VkDescriptorType descriptorType, VkShaderStageFlags shaderStageFlags);
VKFAPI VkfResult vkfCreateDescriptorSetLayout(VkfDescriptorSetLayout* layout);
VKFAPI VkfResult vkfDestroyDescriptorSetLayout(VkfDescriptorSetLayout*  layout);

VKFAPI VkfResult vkfInitDescriptorSet(VkfDescriptorSetCreateInfo* createInfo, VkfDescriptorSet** descriptorSet);
VKFAPI VkfResult vkfCreateDescriptorSet(VkfDescriptorSet* descriptorSet);
VKFAPI VkfResult vkfDescriptorSetBindUniformBuffer(VkfDescriptorSet* descriptorSet, uint32_t binding, VkfBuffer* buffer);
VKFAPI VkfResult vkfDescriptorSetBindTexture(VkfDescriptorSet* descriptorSet, uint32_t binding, struct VkfTexture* texture, VkfTextureSampler* textureSampler);
VKFAPI VkfResult vkfDestroyDescriptorSet(VkfDescriptorSet* descriptorSet);

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Texture Sampler
//

VKFAPI VkfResult vkfInitTextureSampler(VkfTextureSamplerCreateInfo* createInfo, VkfTextureSampler** textureSampler);
VKFAPI VkfResult vkfCreateTextureSampler(VkfTextureSamplerCreateInfo* createInfo, VkfTextureSampler** textureSampler);
VKFAPI VkfResult vkfDestroyTextureSampler(VkfTextureSampler* textureSampler);

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Textures
//
VKFAPI VkfResult vkfCreateTexture1D(VkfDevice* device,
                             VkFormat format,
                             uint32_t width,
                             uint32_t height,
                             uint32_t depth,
                             VkImageLayout initializeLayout,
                             VkfTexture** texture);
VKFAPI VkfResult vkfCreateTexture1DArray(VkfDevice* device,
                                  VkFormat format,
                                  uint32_t width,
                                  uint32_t height,
                                  uint32_t depth,
                                  VkImageLayout initializeLayout,
                                  VkfTexture** texture);
VKFAPI VkfResult vkfCreateTexture2D(VkfDevice* device,
                             VkFormat format,
                             uint32_t width,
                             uint32_t height,
                             uint32_t depth,
                             VkImageLayout initializeLayout,
                             VkfTexture** texture);
VKFAPI VkfResult vkfCreateTexture2DArray(VkfDevice* device,
                                  VkFormat format,
                                  uint32_t width,
                                  uint32_t height,
                                  uint32_t depth,
                                  VkImageLayout initializeLayout,
                                  VkfTexture** texture);
VKFAPI VkfResult vkfCreateTexture3D(VkfDevice* device,
                             VkFormat format,
                             uint32_t width,
                             uint32_t height,
                             uint32_t depth,
                             VkImageLayout initializeLayout,
                             VkfTexture** texture);
VKFAPI VkfResult vkfCreateTextureCube(VkfDevice* device,
                               VkFormat format,
                               uint32_t width,
                               uint32_t height,
                               uint32_t depth,
                               VkImageLayout initializeLayout,
                               VkfTexture** texture);
VKFAPI VkfResult vkfCreateTexture(VkfDevice* device,
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
                           VkfTexture** texture);
VKFAPI VkfResult vkfCreateTexture2(VkfDevice* device,
                            VkImage image,
                            VkFormat format,
                            VkImageViewType imageViewType,
                            uint32_t width,
                            uint32_t height,
                            uint32_t depth,
                            VkfTexture** texture);
VKFAPI VkfResult vkfUploadTexture(VkfTexture* texture, uint8_t* src, uint64_t size, uint64_t offset);
VKFAPI VkfResult vkfDestroyTexture(VkfTexture* texture);
VKFAPI uint32_t vkfTextureGetPitch(VkfTexture* texture);

// -----------------------------------------------------------------------------

#ifdef __cplusplus
} //end extern "C"
#endif

#endif
