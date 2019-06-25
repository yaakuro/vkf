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

#ifndef VULKAN_FRAMEWORK_H
#define VULKAN_FRAMEWORK_H

#include <vkf/vulkan_framework_c.h>

#include <string>
#include <vector>
#include <array>
#include <iostream>
#include <cassert>
#include <memory>
#include <string.h>
#include <limits>
#include <fstream>
#include <sstream>
#include <map>

namespace vkf {

	extern void init();
	extern void destroy();
	extern class Windows* createWindows();
	extern class Instance* createInstance();
	extern VkResult showSupportedLayersAndExtensions();
	extern void setImageLayout(class CommandBuffer* cmdbuffer,
	                           VkImage image,
	                           VkImageAspectFlags aspectMask,
	                           VkImageLayout oldImageLayout,
	                           VkImageLayout newImageLayout);

	enum class Result {
		SUCCESS = VKF_SUCCESS,
		FAILED = VKF_FAILED
	};

	struct VulkanImage {
		VkImage image;
		VkDeviceMemory memory;
		VkImageView imageView;
	};

	class BufferStride {
	public:
		explicit BufferStride(uint32_t stride)
			: m_stride(stride) {
		}

		operator uint32_t() {
			return m_stride;
		}

		static BufferStride Zero;

	private:

		uint32_t m_stride;
	};

	class BufferSize {
	public:
		explicit BufferSize(uint64_t size)
			: m_size(size) {
		}

		operator uint64_t() {
			return m_size;
		}

		// TODO I don't like this but for now ...
		operator size_t() const {
			return m_size;
		}

		static BufferSize Zero;

	private:

		uint64_t m_size;
	};

	class DescriptorCount {
	public:
		explicit DescriptorCount(uint32_t count)
			: m_count(count) {
		}

		operator uint32_t() {
			return m_count;
		}

		// TODO I don't like this but for now ...
		operator size_t() const {
			return m_count;
		}

		static DescriptorCount Zero;

	private:

		uint32_t m_count;
	};

	class BindingPoint {
	public:
		explicit BindingPoint(uint32_t binding)
			: m_binding(binding) {
		}

		operator uint32_t() {
			return m_binding;
		}

		operator uint32_t() const {
			return m_binding;
		}

		static BindingPoint Zero;

	private:

		uint32_t m_binding;
	};

	class LocationPoint {
	public:
		explicit LocationPoint(uint32_t location)
			: m_location(location) {
		}

		operator uint32_t() {
			return m_location;
		}

		operator uint32_t() const {
			return m_location;
		}

		static LocationPoint Zero;

	private:

		uint32_t m_location;
	};

	class FileName {
	public:
		FileName(const std::string& filename)
			: m_filename(filename) {

		}

		operator const char* () const {
			return m_filename.c_str();
		}

	private:

		std::string m_filename;
	};

	class ShaderSource {
	public:
		ShaderSource(const std::string& source)
			: m_source(source) {

		}

		uint32_t size() const {
			return (uint32_t)m_source.size();
		}

		uint32_t* data() const {
			return (uint32_t*)m_source.data();
		}

		operator const char* () const {
			return m_source.c_str();
		}

	private:

		std::string m_source;
	};

	extern bool dumpInstanceSupportedLayerAndExtensions;
	extern bool dumpDeviceSupportedExtensions;

	/**
	 * @class Debug
	 * @brief Helper class for VkDebugReportCallbackEXT.
	 */
	class Debug {
	public:
		Debug(VkfInstance* instance);

		~Debug();

		VkfResult init();
		void destroy();

		operator VkDebugReportCallbackEXT() {
			return m_debug->callback;
		}

	private:

		VkfInstance* m_instance;
		VkfDebug* m_debug;

	};

	class FamilyQueueIndex {
	public:
		FamilyQueueIndex() : m_familyQueueIndex(UINT32_MAX) {}
		FamilyQueueIndex(uint32_t familyQueueIndex) : m_familyQueueIndex(familyQueueIndex) {}

		operator uint32_t() {
			return m_familyQueueIndex;
		}

	private:

		uint32_t m_familyQueueIndex;
	};

	/**
	 * @class Instance
	 * @brief Helper class for VkInstance.
	 */
	class Instance {
	public:
		Instance();
		~Instance();

		/// Initialize the Vulkan instance.
		Result init();

		/// Initialize the Vulkan instance with some parameters.
		Result init(const std::string& title, uint32_t vulkanVersion = VK_MAKE_VERSION(1, 0, 0));

		/// Initialize this object using a already initialized VkInstance.
		Result init(VkInstance instance);

		/// Create the Vulkan device.
		class Device* createDevice(VkQueueFlagBits queueFlagBits = VK_QUEUE_GRAPHICS_BIT, VkPhysicalDeviceType physicalDeviceType = VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU);

		/// Destroy the Vulkan instance.
		void destroy();

		VkfInstance* getVkfHandle() const;

		operator VkInstance() {
			return m_instance->instance;
		}

	protected:

		Result postInit();

	private:

		VkfInstance* m_instance;
		std::string m_title;
		uint32_t m_version;
		Debug* m_debug;
	};

	/**
	 * @class Device
	 * @brief Helper class for VkDevice.
	 */
	class Device {
	public:
		Device(Instance* instance, VkfDevice* device);
		~Device();

		/// Initialize the Vulkan device.
		Result init();

		/// Initialize the Vulkan device using native handles.
		Result init(VkDevice device, VkPhysicalDevice physicalDevice, uint32_t familyQueueIndex, uint32_t maxQueueCount);

		/// Create a Surface.
		class Surface* createSurface(Windows* window);

		/// Create a Command Pool.
		class CommandPool* createCommandPool();

		/// Create a Vertex Buffer.
		class VertexBuffer* createVertexBuffer();

		/// Create a Index Buffer.
		class IndexBuffer* createIndexBuffer();

		/// Create a Uniform Buffer.
		class UniformBuffer* createUniformBuffer();

		/// Create a Staging Buffer.
		class StagingBuffer* createStagingBuffer();

		/// Create a Vertex Shader.
		class VertexShader* createVertexShader();

		/// Create a Geometry Shader.
		class GeometryShader* createGeometryShader();

		/// Create a Fragment Shader.
		class FragmentShader* createFragmentShader();

		/// Create a Tessellation Control Shader.
		class TesselationControlShader* createTessellationControlShader();

		/// Create a Tessellation Evaluation Shader.
		class TesselationEvaluationShader* createTessellationEvaluationShader();

		/// Create a Compute Shader.
		class ComputeShader* createComputeShader();

		/// Create a Queue.
		class Queue* createQueue();

		/// Create a Semaphore.
		class Semaphore* createSemaphore();

		/// Create a Descriptor Pool.
		class DescriptorPool* createDescriptorPool();

		/// Create a Descriptor Set layout.
		class DescriptorSetLayout* createDescriptorSetLayout();

		class PipelineCache* createPipelineCache();
		class Pipeline* createPipeline();

		class FrameBuffer* createFrameBuffer();
		class RenderPass* createRenderPass();
		class Texture2D* createTexture2D();

		class Fence* createFence();
		class FenceManager* createFenceManager();

		/// Destroy the device.
		void destroy();

		/// Wait until device gets into idle state.
		VkResult waitIdle();

		/// Returns the Vulkan instance object.
		Instance* getInstance() const;

		/// Returns the device memory properties.
		VkPhysicalDeviceMemoryProperties getPhysicalDeviceMemoryProperties() const;

		/// Returns the physical device assigned to this device.
		const VkPhysicalDevice& getPhysicalDevice() const;

		FamilyQueueIndex getGraphicsQueueIndex() const;

		uint32_t getQueueIndex() const;

		VkfDevice* getVkfHandle() const;

		operator VkDevice() {
			return m_device->device;
		}

		operator VkDevice*() {
			return &m_device->device;
		}

	private:

		Instance* m_instance;
		VkfDevice* m_device;

		// Holds the familiy queue index of this device.
		uint32_t m_queueIndex;

		// Holds physical device memory properties.
		VkPhysicalDeviceMemoryProperties m_physicalDeviceMemoryProperties;
	};

	/**
	 * @class Surface
	 * @brief Helper class for VkSurfaceKHR.
	 */
	class Surface {
	public:
		Surface(Instance* instance, Device* device, Windows* window);
		~Surface();

		typedef void* SurfaceType;

		/// Initialize surface.
		Result init();

		class SwapChain* createSwapChain();

		/// Create surface.
		VkResult create(Windows& window);

		/// Returns the device assigned to this surface.
		Device* getDevice() const;

		/// Destroy this surface.
		void destroy();

		/// Returns the surface capabilities.
		VkSurfaceCapabilitiesKHR getSurfaceCaps() const;

		/// Returns the present mode count.
		uint32_t getPresentModeCount() const;

		/// Returns the present mode.
		VkPresentModeKHR getPresentMode() const;

		/// Returns the color format supported by this surface.
		VkFormat getColorFormat() const;

		/// Returns the supported color space.
		VkColorSpaceKHR getColorSpace() const;

		/// Returns the extend2D of this surface.
		VkExtent2D getExtent2D() const;

		VkfSurface* getVkfHandle() const;

		operator VkSurfaceKHR() {
			return m_surface->surface;
		}

	private:

		Instance* m_instance;
		Device* m_device;
		Windows* m_window;
		VkfSurface* m_surface;

		uint32_t m_queueFamilyIndex;
		uint32_t m_queueIndex;
	};

	/**
	 * @class SwapChain
	 * @brief Helper class for VkSwapchainKHR.
	 */
	class SwapChain {
	public:
		SwapChain(Surface* surface);
		~SwapChain();

		/// Initialize the SwapChain.
		Result init();

		/// Returns the next image in the SwapChain that needs to be handled.
		VkResult nextImage(uint32_t& imageIndices, Semaphore* presentSemaphore, FenceManager* fenceManager = nullptr);

		/// Present the image.
		VkResult present(Queue* queue, uint32_t imageIndices, Semaphore* renderingFinishedSemaphore);

		/// Destroy the SwapChain.
		void destroy();

		/// Returns the number of SwapChain framebuffers.
		uint32_t getImageCount();

		/// Returns the specified Swap Chain Framebuffer.
		VkFramebuffer getFramebuffer(uint32_t idx) const;

		/// Returns the associated Surface.
		Surface* getSurface() const;

		VkRenderPass getRenderPass() const;

		inline VkExtent2D getExtent2D() {
			return m_surface->getExtent2D();
		}

		operator VkSwapchainKHR() {
			return m_swapChain->swapChain;
		}

		operator const VkSwapchainKHR*() {
			return &m_swapChain->swapChain;
		}

	private:

		Surface* m_surface;
		VkfSwapchain* m_swapChain;
	};

	/**
	 * @class RenderPass
	 * @brief Helper class for VkRenderPass.
	 */
	class RenderPass {
	public:
		RenderPass(Device* device);
		~RenderPass();

		/// Initialize render pass.
		Result init();

		/// Destroy render pass.
		void destroy();

		void addColorAttachment(VkFormat format, VkImageLayout initialImageLayout = VK_IMAGE_LAYOUT_UNDEFINED, VkImageLayout finalImageLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL);
		void addDepthStencilAttachment(VkFormat format, VkImageLayout initialImageLayout = VK_IMAGE_LAYOUT_UNDEFINED);
		
		VkfRenderPass* getVkfHandle() const;
	
		operator VkRenderPass() {
			return m_renderPass->renderPass;
		}

	private:

		Device* m_device;
		VkfRenderPass* m_renderPass;
	};

	class RenderPassScope {
	public:
		RenderPassScope(CommandBuffer* commandBuffer, VkFramebuffer framebuffer, VkRenderPass renderPass, VkExtent2D extent, std::vector<VkClearValue>& clearValues);
		~RenderPassScope();
	private:
		CommandBuffer* m_commandBuffer;
	};

	/**
	 * @class FrameBuffer
	 * @brief Helper class for VkFramebuffer.
	 */
	class FrameBuffer {
	public:
		FrameBuffer(Device* device);
		FrameBuffer(Device* device, RenderPass* renderPass);

		Result init(uint32_t width, uint32_t height);
		Result init(RenderPass* renderPass, uint32_t width, uint32_t height);
		void destroy();
		VkResult create();
		VkResult addColor(Texture2D* colorTexture);
		Result addDepthStencil(VkFormat format, uint32_t width, uint32_t height);
		Result addDepthStencil(Texture2D* depthStencilTexture);

		operator VkFramebuffer() {
			return m_frameBuffer->framebuffer;
		}

	private:

		Device* m_device;
		RenderPass* m_renderPass;
		VkfFrameBuffer* m_frameBuffer;
	};

	/**
	 * @class CommandPool
	 * @brief Helper class for the VkCommandPool.
	 */
	class CommandPool {
	public:
		CommandPool(Device* device, VkCommandPoolCreateFlags commandPoolCreateFlags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT);
		~CommandPool();

		/// Initialize the command pool.
		VkResult init();

		class CommandBuffers* createCommandBuffers();
		class CommandBuffer* createCommandBuffer();

		/// Resets the command pool.
		VkResult reset(VkCommandPoolCreateFlags commandPoolCreateFlags);

		/// Destroys the command pool.
		void destroy();

		/// Return the device assigned to the command pool.
		Device* getDevice() const;

		operator VkCommandPool() {
			return m_cmdPool;
		}

	public:
		Device* m_device;
		VkCommandPool m_cmdPool;
		VkCommandPoolCreateFlags m_commandPoolCreateFlags;
	};

	/**
	 * @class CommandBuffer
	 * @brief Helper class for the VkCommandBuffer.
	 */
	class CommandBuffer {
	public:
		CommandBuffer(CommandPool* commandPool);
		~CommandBuffer();

		/// Initialize command buffer.
		VkResult init();

		/// Destroy command buffer.
		void destroy();

		/// Begin recording into command buffer.
		VkResult begin(VkCommandBufferUsageFlags usageFlags = VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT);

		/// End recording into command buffer.
		VkResult end();

		void reset();

		operator VkCommandBuffer() {
			return m_cmdBuffer;
		}

		operator const VkCommandBuffer*() {
			return &m_cmdBuffer;
		}

	public:

		CommandPool* m_commandPool;
		VkCommandBuffer m_cmdBuffer;
		bool m_isBegin;
	};

	/**
	 * @class CommandBufferScope
	 * @brief
	 */
	class CommandBufferScope {
	public:
		CommandBufferScope(CommandBuffer* commandBuffer, VkCommandBufferUsageFlags usageFlags) : cmdBuffer(commandBuffer) {
			cmdBuffer->begin(usageFlags);
		}

		~CommandBufferScope() {
			cmdBuffer->end();
		}

	private:

		CommandBuffer* cmdBuffer;
	};

	/**
	 * @class CommandBuffers
	 * @brief Helper class for multiple CommandBuffer.
	 */
	class CommandBuffers {
	public:
		CommandBuffers(Device* device, CommandPool* commandPool);
		CommandBuffers(Device* device, CommandPool* commandPool, uint32_t number);
		~CommandBuffers();

		/// Initialize the command buffers.
		VkResult init();
		VkResult init(uint32_t number);

		/// Destroy the command buffers.
		void destroy();

		/// Returns the command buffers array.
		std::vector<VkCommandBuffer> getCommandBuffers() const;

		CommandBuffer* getCommandBuffer(int index) const {
			return m_cmdBuffers[index];
		}

		inline CommandBuffer* operator[](int index) {
			return m_cmdBuffers[index];
		}

		inline uint32_t getNumber() const {
			return m_cmdBuffers.size();
		}

	public:

		Device* m_device;
		CommandPool* m_commandPool;
		CommandBuffer* m_postPresentCmdBuffer;
		std::vector<CommandBuffer*> m_cmdBuffers;
	};

	/**
	 * @class Semaphore
	 * @brief Helper class for VkSemaphore.
	 */
	class Semaphore {
	public:
		Semaphore(Device* device);

		~Semaphore();

		/// Initialize semaphore.
		VkResult init();

		/// Destroy semaphore.
		void destroy();

		operator VkSemaphore() {
			return m_semaphore;
		}

		operator const VkSemaphore*() {
			return &m_semaphore;
		}

	private:

		Device* m_device;
		VkSemaphore m_semaphore;
	};

	/**
	 * @struct Fence
	 * @brief Helper struct for VkFence.
	 */
	class Fence {
	public:
		friend class FenceManager;

		Fence(Device* device);

		void reset();

		/// Initialize the fence.
		VkResult init();

		VkFence getNativeHandle() {
			return m_fence;
		}

		operator VkFence() {
			return m_fence;
		}

		operator const VkFence* () {
			return &m_fence;
		}

	protected:

		/// Destroy the fence.
		void destroy();

	private:

		Device* m_device;
		VkFence m_fence;
	};

	class FenceManager {
	public:
		FenceManager(Device* device);

		enum FenceType {
			AquireImage,
			Unknown
		};

		/// Initialize the manager.
		VkResult init();

		/// Destroy the manager.
		void destroy();

		/// Add a new fence to the system.
		void add(Fence* fence);

		/// Removes the fence from the system.
		void remove(Fence* fence);

		/// Reset one specific fence.
		void reset(Fence* fence);

		/// Reset all fences.
		void resetAll();

		/// Returns the state of the fence.
		VkResult getStatus(Fence* fence);

		/// Wait for all fences.
		VkResult waitForAllFences();

		/// Wait for one fence.
		VkResult waitForFence(uint32_t idx);

		VkFence getFence(uint32_t idx) {
			return m_nativeHandles[idx];
		}

		std::vector<VkFence> getFences() {
			return m_nativeHandles;
		}

	private:

		Device* m_device;
		std::vector<Fence*> m_fences;
		std::vector<VkFence> m_nativeHandles;
	};

	/**
	 * @class Queue
	 * @brief Helper class for VkQueue.
	 */
	class Queue {
	public:
		Queue(Device* device, FamilyQueueIndex famliyQueueIndex);
		Queue(Device* device, FamilyQueueIndex famliyQueueIndex, uint32_t queueIndex);

		/// Initialize queue.
		VkResult init();
		VkResult init(uint32_t queueIndex);

		VkResult submit(VkSubmitInfo& submitInfo, Fence* fence = nullptr);

		VkResult submit(CommandBuffer* commandBuffer, Fence* fence = nullptr);

		/// Submit command buffer.
		VkResult submit(CommandBuffer* commandBuffer, VkPipelineStageFlags pipelineStageFlags, Fence* fence = nullptr);

		/// Submit command buffer with a specified fence.
		VkResult submit(CommandBuffer* commandBuffer, VkPipelineStageFlags pipelineStageFlags, Semaphore* renderComplete, Semaphore* presentComplete, Fence* fence = nullptr);

		/// Wait until idle state.
		VkResult waitIdle();

		/// Returns the queue family index.
		uint32_t getQueueFamilyIndex() const;

		void destroy();

		operator VkQueue() {
			return m_queue;
		}

	private:

		Device* m_device;
		VkQueue m_queue;
		uint32_t m_queueFamilyIndex;
		uint32_t m_queueIndex;
	};

	/**
	 * @class BufferBase
	 * @brief Helper class for basic buffer handling.
	 */
	class BufferBase {
	public:
		BufferBase(Device* device, VkBufferUsageFlagBits bufferUsageFlagBits);
		BufferBase(Device* device, VkBufferUsageFlagBits bufferUsageFlagBits, const BufferSize& size);
		virtual ~BufferBase();

		Result init();
		Result init(const BufferSize& size);

		void destroy();
		Result upload(uint8_t* src, const BufferSize& size, uint64_t offset = 0);

		operator VkBuffer() {
			return m_buffer->buffer;
		}

		operator VkBuffer*() {
			return &m_buffer->buffer;
		}

		VkfBuffer* getVkfHandle() const;

	protected:

		Device* m_device;
		VkfBuffer* m_buffer;
		VkBufferUsageFlagBits m_bufferUsageFlagBits;
		BufferSize m_size;
	};

	/**
	 * @class VertexBuffer
	 * @brief Helper class for vertex buffer.
	 */
	class VertexBuffer : public BufferBase {
	public:
		explicit VertexBuffer(Device* device);
		explicit VertexBuffer(Device* device, const BufferSize& size, BufferStride stride = BufferStride::Zero);

		Result init();
		Result init(const BufferSize& size, BufferStride stride = BufferStride::Zero);

		uint32_t getBindingID() const;
		BufferStride getStride() const;
		VertexBuffer& addElement(const BindingPoint& binding, const LocationPoint& location, VkFormat format, uint32_t offset);

	private:

		BufferStride m_stride;
	};

	/**
	 * @class IndexBuffer
	 * @brief Helper class for index buffer.
	 */
	class IndexBuffer : public BufferBase {
	public:
		explicit IndexBuffer(Device* device);
		explicit IndexBuffer(Device* device, uint32_t numberOfIndicies, const BufferSize& size = BufferSize::Zero);
		Result init(uint32_t numberOfIndicies, const BufferSize& size);
		uint32_t getNumberOfIndicies() const;

	private:

		uint32_t m_number;
	};


	/**
	 * @class UniformBuffer
	 * @brief Helper class for uniform buffer.
	 */
	class UniformBuffer : public BufferBase {
	public:
		explicit UniformBuffer(Device* device);
		explicit UniformBuffer(Device* device, const BufferSize& size);
		VkDescriptorBufferInfo& getDescriptorBufferInfo();

	private:

		VkDescriptorBufferInfo descriptorBufferInfo;
	};

	/**
	 * @class StagingBuffer
	 * @brief This buffers memory will reside in the host side and will be used to copy data to GPU memory.
	 */
	class StagingBuffer : public BufferBase {
	public:
		explicit StagingBuffer(Device* device);
		explicit StagingBuffer(Device* device, const BufferSize& size);
		Result init(const BufferSize& size);
	};

	/**
	 * @class DescriptorSetLayout
	 * @brief Helper class for VkDescriptorSetLayout.
	 */
	class DescriptorSetLayout {
	public:
		DescriptorSetLayout(Device* device);

		DescriptorSetLayout& add(const BindingPoint& binding, const DescriptorCount& count, VkDescriptorType descriptorType, VkShaderStageFlags shaderStageFlags);

		Result init();

		void destroy();

		VkfDescriptorSetLayout* getVkfHandle() const {
			return m_descriptorSetLayout;
		}

		operator const VkDescriptorSetLayout*() {
			return &m_descriptorSetLayout->descriptorSetLayout;
		}

		operator VkDescriptorSetLayout() {
			return m_descriptorSetLayout->descriptorSetLayout;
		}

	private:

		VkfDescriptorSetLayout* m_descriptorSetLayout;
	};

	/**
	 * @class DescriptorPool
	 * @brief Helper class for VkDescriptorPool.
	 */
	class DescriptorPool {
	public:
		DescriptorPool(Device* device);

		DescriptorPool& add(VkDescriptorType descriptorType, uint32_t count = 1);
		class DescriptorSet* createDescriptorSet();

		Result init();

		void destroy();

		VkfDescriptorPool* getVkfHandle() const {
			return m_descriptorPool;
		}

		operator VkDescriptorPool() {
			return m_descriptorPool->descriptorPool;
		}

	private:

		Device* m_device;
		VkfDescriptorPool* m_descriptorPool;
	};

	/**
	 * @class DescriptorSet
	 * @brief Helper class for VkDescriptorSet.
	 */
	class DescriptorSet {
	public:
		DescriptorSet(Device* device, DescriptorPool* descriptorPool);
		DescriptorSet(Device* device, DescriptorPool* descriptorPool, DescriptorSetLayout* layout);

		void bind(const BindingPoint& binding, class UniformBuffer* uniformBuffer);
		void bind(const BindingPoint& binding, class Texture* texture, class TextureSampler* textureSample);

		/// Initialize descriptor set.
		Result init();
		Result init(DescriptorSetLayout* layout);

		/// Destroys the descriptor set.
		void destroy();

		operator VkDescriptorSet() {
			return m_descriptorSet->descriptorSet;
		}

		operator const VkDescriptorSet*() {
			return &m_descriptorSet->descriptorSet;
		}
	private:

		Device* m_device;
		VkfDescriptorSet* m_descriptorSet;
		DescriptorPool* m_descriptorPool;
		DescriptorSetLayout* m_layout;
		std::map<uint32_t, VkDescriptorImageInfo> m_descriptorImageInfo;
	};

	/**
	 * @class PipelineCache
	 * @brief
	 */
	class PipelineCache {
	public:
		PipelineCache(Device* device);

		~PipelineCache();

		VkResult init();

		void destroy();

		operator VkPipelineCache() {
			return m_pipeLineCache;
		}

	private:

		Device* m_device;
		VkPipelineCache m_pipeLineCache;
	};

	/**
	 * @class ShaderModule
	 * @brief Helper class for VkShaderModule.
	 */
	class ShaderModule {
	public:
		ShaderModule(Device* device, VkShaderStageFlagBits shaderStageFalgBits, const std::string& entryName = "main");
		~ShaderModule();

		/// Load the shader source.
		Result load(const FileName& filename);

		/// Destroy the shader.
		void destroy();

		VkShaderStageFlagBits getShaderStageFlagBits() const;

		/// Returns the name of the entry shader function.
		const char* getEntryName() const;

		/// Returns the pointer to the binary/
		uint32_t* getBinary() const;

		/// Returns the size of the binary.
		uint32_t getBinarySize() const;

		operator VkShaderModule() {
			return m_shaderModule->shaderModule;
		}

		operator VkShaderModule*() {
			return &m_shaderModule->shaderModule;
		}

	private:

		Device* m_device;
		VkfShaderModule* m_shaderModule;
		VkShaderStageFlagBits m_shaderStageFlagBits;
		std::string m_entryName;
	};

	/**
	 * @class VertexShader
	 * @brief
	 */
	class VertexShader : public ShaderModule {
	public:
		VertexShader(Device* device);
	};

	/**
	 * @class GeometryShader
	 * @brief
	 */
	class GeometryShader : public ShaderModule {
	public:
		GeometryShader(Device* device);
	};

	/**
	 * @class FragmentShader
	 * @brief
	 */
	class FragmentShader : public ShaderModule {
	public:
		FragmentShader(Device* device);
	};

	/**
	 * @class TesselationControlShader
	 * @brief
	 */
	class TesselationControlShader : public ShaderModule {
	public:
		TesselationControlShader(Device* device);
	};

	/**
	 * @class TesselationEvaluationShader
	 * @brief
	 */
	class TesselationEvaluationShader : public ShaderModule {
	public:
		TesselationEvaluationShader(Device* device);
	};

	/**
	 * @class ComputeShader
	 * @brief
	 */
	class ComputeShader : public ShaderModule {
	public:
		ComputeShader(Device* device);
	};

	/**
	 * @class Texture
	 * @brief Base class for textures.
	 *
	 * All texture memory will be located on the GPU device.
	 */
	class Texture {
	public:
		Texture(Device* device);
		Texture(Device* device,
		        VkImageLayout imageTextureLayout,
		        VkImageType imageType,
		        VkImageViewType imageViewType,
		        VkImageUsageFlags imageUsageFlags,
		        VkFormat format,
		        uint32_t width,
		        uint32_t height,
		        uint32_t depth = 1);
		~Texture();

		Result init();
		void init(VkImage image, VkFormat format, uint32_t width, uint32_t height, uint32_t depth = 1);

		Result init(VkImageLayout imageTextureLayout,
		              VkImageType imageType,
		              VkImageViewType imageViewType,
		              VkImageUsageFlags imageUsageFlags,
		              VkFormat format,
		              uint32_t width,
		              uint32_t height,
		              uint32_t depth = 1);
		void destroy();
		void* map();
		void unmap();
		Result upload(uint8_t* src, const BufferSize& size, uint64_t offset = 0);
		uint32_t getWidth() const;
		uint32_t getHeight() const;
		uint32_t getDepth() const;
		size_t getSize();
		VkFormat getFormat() const;
		VkImage getImage() const;
		VkImageView getImageView() const;
		VkImageLayout getImageLayout() const;
		Texture& setDisableImageAutoDelete(bool disable);
		VkImageAspectFlags getImageAspectFlagBitsFromFormat(VkFormat format);
		VkfTexture* getVkfHandle() const {
			return m_texture;
		}
	private:

		Device* m_device;
		VkfTexture* m_texture;
		VkImageType m_imageType;
		VkImageViewType m_imageViewType;
		VkFormat m_format;
		VkImageLayout m_imageLayout;
		VkImageUsageFlags m_imageUsageFlags;
		VkMemoryAllocateInfo m_memoryAllocateInfo;
		uint32_t m_width;
		uint32_t m_height;
		uint32_t m_depth;
		VkMemoryRequirements m_memoryRequirements;
		VkImageTiling m_tiling;
	};

	class Texture1D : public Texture {
	public:
		Texture1D(Device* device, VkFormat format, uint32_t width, uint32_t height, VkImageUsageFlags imageUsageFlags = VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT)
			: Texture(device, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_TYPE_1D, VK_IMAGE_VIEW_TYPE_1D, imageUsageFlags, format, width, height, 1) {

		}
	};

	class Texture2D : public Texture {
	public:
		Texture2D(Device* device) : Texture(device) {}
		Texture2D(Device* device, VkFormat format, uint32_t width, uint32_t height, VkImageUsageFlags imageUsageFlags = VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT)
			: Texture(device, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_TYPE_2D, VK_IMAGE_VIEW_TYPE_2D, imageUsageFlags, format, width, height, 1) {

		}
	};

	class Texture3D : public Texture {
	public:
		Texture3D(Device* device, VkFormat format, uint32_t width, uint32_t height, uint32_t depth, VkImageUsageFlags imageUsageFlags = VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT)
			: Texture(device, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_TYPE_3D, VK_IMAGE_VIEW_TYPE_3D, imageUsageFlags, format, width, height, depth) {

		}
	};

	class TextureCube : public Texture {
	public:
		TextureCube(Device* device, VkFormat format, uint32_t width, uint32_t height, VkImageUsageFlags imageUsageFlags = VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT)
			: Texture(device, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_TYPE_2D, VK_IMAGE_VIEW_TYPE_CUBE, imageUsageFlags, format, width, height, 6) {

		}
	};

	class TextureArray2D : public Texture {
	public:
		TextureArray2D(Device* device, VkFormat format, uint32_t width, uint32_t height, uint32_t depth, VkImageUsageFlags imageUsageFlags = VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT)
			: Texture(device, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_TYPE_2D, VK_IMAGE_VIEW_TYPE_2D_ARRAY, imageUsageFlags, format, width, height) {

		}
	};


	class TextureSampler {
	public:
		TextureSampler(Device* device);

		Result init();
		void destroy();

		TextureSampler& setMinFilter(VkFilter minFilter);
		TextureSampler& setMagFilter(VkFilter magFilter);
		TextureSampler& setAddressModeU(VkSamplerAddressMode U);
		TextureSampler& setAddressModeV(VkSamplerAddressMode V);
		TextureSampler& setAddressModeW(VkSamplerAddressMode W);

		operator VkSampler() {
			return m_textureSampler->textureSampler;
		}

		VkfTextureSampler* getVkfHandle() const {
			return m_textureSampler;
		}

	private:

		VkfTextureSampler* m_textureSampler;
		VkfTextureSamplerCreateInfo m_createInfo;
	};

	/**
	 * @class Pipeline
	 * @brief Helper class for VkPipeline.
	 */

	class Pipeline {
	public:
		Pipeline(Device* device);
		Pipeline(Device* device, DescriptorSetLayout* descriptorSetLayout, RenderPass* renderPass, VkExtent2D extent2D);
		~Pipeline();

		VkResult init();
		VkResult init(DescriptorSetLayout* descriptorSetLayout, RenderPass* renderPass, VkExtent2D extent2D);
		VkResult init(DescriptorSetLayout* descriptorSetLayout, VkRenderPass renderPass, VkExtent2D extent2D);

		void destroy();

		void addVertexState(VertexBuffer* vertexBuffer);
		void finalizeVertexState();

		void addIndexState(IndexBuffer* indexBuffer);
		void addShaderModule(ShaderModule* shaderModule);

		Pipeline& setUsedTopology(VkPrimitiveTopology primitiveTopology);
		Pipeline& setFrontFace(VkFrontFace frontFace);
		Pipeline& setEnableDepthStencil(VkBool32 enable);
		Pipeline& setCullMode(VkCullModeFlags cullModeFlags);

		// -----------------------------------------------------------------------
		// Blending
		//
		Pipeline& setBlendEnable(VkBool32 enable);
		Pipeline& setBlendSrcColorFactor(VkBlendFactor factor);
		Pipeline& setBlendDstColorFactor(VkBlendFactor factor);
		Pipeline& setBlendSrcAlphaFactor(VkBlendFactor factor);
		Pipeline& setBlendDstAlphaFactor(VkBlendFactor factor);
		Pipeline& setBlendColorOp(VkBlendOp factor);
		Pipeline& setBlendAlphaOp(VkBlendOp factor);
		Pipeline& setBlendColorWriteMask(VkColorComponentFlags flags);


		VkPipelineLayout getPipelineLayout() const;

		operator VkPipeline() {
			return m_pipeline;
		}

	private:

		Device* m_device;
		DescriptorSetLayout* m_descriptorSetLayout;
		RenderPass* m_renderPass;
		VkRenderPass m_nativeRenderPass;
		VkPipelineLayout m_pipelineLayout;
		VkPipeline m_pipeline;

		VkPipelineVertexInputStateCreateInfo m_pipelineVertexInputStateCreateInfo;
		VkPipelineInputAssemblyStateCreateInfo m_inputAssemblyState;
		std::vector<VkPipelineShaderStageCreateInfo> m_shaderStages;
		std::vector<VkVertexInputBindingDescription> m_vertexInputBindingDescriptions;
		std::vector<VkVertexInputAttributeDescription> m_vertexInputAttributeDescriptions;
		VkExtent2D m_extent2D;
		std::vector<VkViewport> m_viewports;
		std::vector<VkRect2D> m_scissors;
		VkPipelineRasterizationStateCreateInfo m_rasterizationStateCreateInfo;
		VkPipelineDepthStencilStateCreateInfo m_depthStencilState;
		VkPipelineColorBlendAttachmentState m_blendAttachmentState;
	};

}

#ifdef VKF_USE_INLINED_DEFINITION
#include "vulkan_framework.cpp"
#endif

#endif
