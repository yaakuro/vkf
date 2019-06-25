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

#include <vkf/vulkan_framework_windows.h>
#include <vkf/vulkan_framework.h>
#include <limits>
#include <stdint.h>

namespace vkf {

	BufferStride BufferStride::Zero = BufferStride(0);
	BufferSize BufferSize::Zero = BufferSize(0);
	DescriptorCount DescriptorCount::Zero = DescriptorCount(0);
	BindingPoint BindingPoint::Zero = BindingPoint(0);
	LocationPoint LocationPoint::Zero = LocationPoint(0);

	bool dumpInstanceSupportedLayerAndExtensions = false;
	bool dumpDeviceSupportedExtensions = false;

	void setImageLayout(class CommandBuffer* commandBuffer,
	                    VkImage image,
	                    VkImageAspectFlags aspectMask,
	                    VkImageLayout oldImageLayout,
	                    VkImageLayout newImageLayout) {
		vkfSetImageLayout(*commandBuffer, image, aspectMask, oldImageLayout, newImageLayout);
	}

	void init() {
		vkfLoadVulkanLibrary();
	}

	void destroy() {
		vkfDestroy();
	}

	Windows* createWindows() {
		Windows* windows = new Windows();
		return windows;
	}

	Instance* createInstance() {
		Instance* instance = new Instance();
		return instance;
	}

	VkResult showSupportedLayersAndExtensions() {
		//
		// Let's check the supported instance extensions.
		//
		uint32_t propertyCount = 0;
		VkResult result = vkEnumerateInstanceExtensionProperties(nullptr, &propertyCount, nullptr);
		if(VK_SUCCESS != result) {
			std::cerr << "vkEnumerateInstanceExtensionProperties failed: " << vkfVkResultToString(result) << std::endl;
			return result;
		}

		std::vector<VkExtensionProperties> extensionProperties(propertyCount);
		vkEnumerateInstanceExtensionProperties(nullptr, &propertyCount, extensionProperties.data());
		std::cout << "Supported Instance Extension: " << std::endl;
		for(auto extension : extensionProperties) {
			std::cout << "Extension name: " << extension.extensionName << " Version: " << extension.specVersion << std::endl;
		}
		std::cout << std::endl;

		//
		// Let's check the supported instance layers.
		//
		uint32_t layerPropertyCount = 0;
		result = vkEnumerateInstanceLayerProperties(&layerPropertyCount, nullptr);
		if(VK_SUCCESS != result) {
			std::cerr << "vkEnumerateInstanceLayerProperties failed: " << vkfVkResultToString(result) << std::endl;
			return result;
		}

		std::vector<VkLayerProperties> instanceLayerProperties(layerPropertyCount);
		vkEnumerateInstanceLayerProperties(&layerPropertyCount, instanceLayerProperties.data());
		std::cout << "Supported layer names: " << std::endl;
		for(auto extension : instanceLayerProperties) {
			std::cout << "Layer name: " << extension.layerName << " Version: " << extension.specVersion << std::endl;
		}
		std::cout << std::endl;

		return VK_SUCCESS;
	}

	void showSupportedDeviceExtensions(VkPhysicalDevice physicalDevice) {
		uint32_t propertyCount = 0;
		vkEnumerateDeviceExtensionProperties(physicalDevice, nullptr, &propertyCount, nullptr);

		std::vector<VkExtensionProperties> extensionProperties(propertyCount);
		vkEnumerateDeviceExtensionProperties(physicalDevice, nullptr, &propertyCount, extensionProperties.data());

		std::cout << "Supported Device Extension: " << std::endl;
		for(auto extension : extensionProperties) {
			std::cout << "Extension name: " << extension.extensionName << " Version: " << extension.specVersion << std::endl;
		}
		std::cout << std::endl;


	}

	Windows::Windows() {
	}

	Windows::Windows(const std::string& title, uint32_t width, uint32_t height) {
		m_title = title;
		m_width = width;
		m_height = height;
	}

	Windows::~Windows() {
		destroy();
	}

	int Windows::init() {
		VkfWindowCreateInfo createInfo = {};
		createInfo.title = m_title.c_str();
		createInfo.width = m_width;
		createInfo.height = m_height;

		return vkfCreateWindow(&createInfo, &m_window);
	}

#ifdef VKF_SURFACE_XCB
	int Windows::init(xcb_connection_t* connection, xcb_window_t window) {
		m_window->connection = connection;
		m_window->window = window;
		return 0;
	}
#elif defined(VKF_SURFACE_XLIB)
	int Windows::init(Display* display, Window window) {
		m_window->display = display;
		m_window->window = window;
		return 0;
	}
#elif defined(VKF_SURFACE_WIN32)
	int Windows::init(HINSTANCE instance, HWND hwnd) {
		m_window->hinstance = instance;
		m_window->hwnd = hwnd;
		return 0;
	}
#endif

	int Windows::init(const std::string& title, uint32_t width, uint32_t height) {
		m_title = title;
		m_height = height;
		m_width = width;
		return init();
	}

#ifdef VKF_SURFACE_XCB
	int Windows::init(const std::string& title, uint32_t width, uint32_t height, xcb_connection_t* connection, xcb_window_t window) {
		m_window->connection = connection;
		m_window->window = window;
		m_title = title;
		m_width = width;
		m_height = height;
		return 0;
	}
#elif defined(VKF_SURFACE_XLIB)
	int Windows::init(const std::string& title, uint32_t width, uint32_t height, Display* display, Window window) {
		m_window->display = display;
		m_window->window = window;
		m_title = title;
		m_width = width;
		m_height = height;
		return 0;
	}
#elif defined(VKF_SURFACE_WIN32)
	int Windows::init(const std::string& title, uint32_t width, uint32_t height, HINSTANCE instance, HWND hwnd) {
		m_window->hinstance = instance;
		m_window->hwnd = hwnd;
		m_title = title;
		m_width = width;
		m_height = height;
		return 0;
	}
#endif

	int Windows::destroy() {
		vkfDestroyWindow(m_window);
		return 0;
	}

	VkfWindow* Windows::getVkfWindow() const {
		return m_window;
	}

	void Windows::setInputFocus() {
		vkfShowWindow(m_window);
	}

	void Windows::show() {
		vkfShowWindow(m_window);
	}

	bool Windows::pollEvents() {
		return VkfPollWindowEvents(m_window);
	}

	uint32_t Windows::getWidth() const {
		return m_width;
	}

	uint32_t Windows::getHeight() const {
		return m_height;
	}

	const std::string& Windows::getTitle() const {
		return m_title;
	}

#ifdef VKF_SURFACE_XCB
	xcb_connection_t* Windows::getConnection() const {
		return m_window->connection;
	}

	xcb_window_t Windows::getWindow() const {
		return m_window->window;
	}
#elif defined(VKF_SURFACE_XLIB)

	Display* Windows::getDisplay() const {
		return m_window->display;
	}

	Window Windows::getWindow() const {
		return m_window->window;
	}
#elif defined(VKF_SURFACE_WIN32)

	HINSTANCE Windows::getInstance() const {
		return m_window->hinstance;
	}

	HWND Windows::getHandle() const {
		return m_window->hwnd;
	}
#endif

//
// VK_EXT_debug_report
//

	Debug::Debug(VkfInstance* instance)
		: m_instance(instance) {

	}

	Debug::~Debug() {

	}

	VkfResult Debug::init() {
		return vkfCreateDebug(m_instance, &m_debug);
	}

	void Debug::destroy() {
		vkfDestroyDebug(m_debug);
	}

//
//
//

	Instance::Instance()
		: m_instance(nullptr)
		, m_title("Vulkan Application")
		, m_version(VK_MAKE_VERSION(1, 0, 0))
		, m_debug(nullptr) {

	}

	Instance::~Instance() {

	}

	VkfInstance* Instance::getVkfHandle() const {
		return m_instance;
	}

	Result Instance::init() {
		if(dumpInstanceSupportedLayerAndExtensions) {
			showSupportedLayersAndExtensions();
		}

		VkfInstanceCreateInfo instanceCreateInfo = {};
		instanceCreateInfo.title = m_title.c_str();
		instanceCreateInfo.apiVersion = m_version;

		if(vkfCreateInstance(&instanceCreateInfo, &m_instance) != VKF_SUCCESS) {
			return Result::FAILED;
		}

		return postInit();
	}

	Result Instance::init(const std::string& title, uint32_t vulkanVersion) {
		m_title = title;
		m_version = vulkanVersion;
		return init();
	}

	Result Instance::init(VkInstance instance) {
		if(m_instance) {
			m_instance->instance = instance;
		}
		return postInit();
	}

	void Instance::destroy() {
		if(nullptr != m_debug) {
			m_debug->destroy();
			delete m_debug;
		}

		vkfDestroyInstance(m_instance);
	}

	Result Instance::postInit() {
		m_debug = new Debug(m_instance);
		if(m_debug->init() != VKF_SUCCESS) {
			return Result::FAILED;
		}

		return Result::SUCCESS;
	}

	Device* Instance::createDevice(VkQueueFlagBits queueFlagBits, VkPhysicalDeviceType physicalDeviceType) {

		VkfDeviceCreateInfo deviceCreateInfo = {};
		deviceCreateInfo.physicalDeviceType = physicalDeviceType;
		deviceCreateInfo.instance = m_instance;

		VkfDevice* deviceHandle = NULL;
		if(vkfCreateDevice(&deviceCreateInfo, &deviceHandle) != VKF_SUCCESS) {
			return NULL;
		}

		Device* device = new Device(this, deviceHandle);
		return device;
	}

//
// Device
//

	Device::Device(Instance* instance, VkfDevice* device)
		: m_instance(instance)
		, m_device(device)
		, m_queueIndex(0)
		, m_physicalDeviceMemoryProperties {} {
	}

	Device::~Device() {
	}

	VkfDevice* Device::getVkfHandle() const {
		return m_device;
	}

	Result Device::init() {
		vkGetPhysicalDeviceMemoryProperties(m_device->physicalDevice, &m_physicalDeviceMemoryProperties);
		return Result::SUCCESS;
	}

	Result Device::init(VkDevice device, VkPhysicalDevice physicalDevice, uint32_t graphicsQueueIndex, uint32_t maxQueueCount) {
		m_device->physicalDevice = physicalDevice;
		m_device->device = device;
		m_device->familyQueueIndex = graphicsQueueIndex;
		m_device->maxFamilyQueueCount = maxQueueCount;
		return init();
	}

	void Device::destroy() {
		vkfDestroyDevice(m_device);
	}

	Instance* Device::getInstance() const {
		return m_instance;
	}

	VkResult Device::waitIdle() {
		VkResult result = vkDeviceWaitIdle(m_device->device);
		if(VK_SUCCESS != result) {
			std::cerr << "vkDeviceWaitIdle failed: " << vkfVkResultToString(result) << std::endl;
		}
		return result;
	}

	VkPhysicalDeviceMemoryProperties Device::getPhysicalDeviceMemoryProperties() const {
		return m_physicalDeviceMemoryProperties;
	}

	const VkPhysicalDevice& Device::getPhysicalDevice() const {
		return m_device->physicalDevice;
	}

	FamilyQueueIndex Device::getGraphicsQueueIndex() const {
		return m_device->familyQueueIndex;
	}

	uint32_t Device::getQueueIndex() const {
		return m_queueIndex;
	}

	Surface* Device::createSurface(Windows* window) {
		Surface* surface = new Surface(m_instance, this, window);
		return surface;
	}

	CommandPool* Device::createCommandPool() {
		CommandPool* commandPool = new CommandPool(this);
		return commandPool;
	}

	VertexBuffer* Device::createVertexBuffer() {
		VertexBuffer* vertexBuffer = new VertexBuffer(this);
		return vertexBuffer;
	}

	IndexBuffer* Device::createIndexBuffer() {
		IndexBuffer* indexBuffer = new IndexBuffer(this);
		return indexBuffer;
	}

	UniformBuffer* Device::createUniformBuffer() {
		UniformBuffer* uniformBuffer = new UniformBuffer(this);
		return uniformBuffer;
	}

	StagingBuffer* Device::createStagingBuffer() {
		StagingBuffer* statgingBuffer = new StagingBuffer(this);
		return statgingBuffer;
	}

	Queue* Device::createQueue() {
		Queue* queue = new Queue(this, FamilyQueueIndex(m_device->familyQueueIndex));
		return queue;
	}

	Semaphore* Device::createSemaphore() {
		Semaphore* semaphore = new Semaphore(this);
		return semaphore;
	}

	VertexShader* Device::createVertexShader() {
		VertexShader* vertexShader = new VertexShader(this);
		return vertexShader;
	}

	GeometryShader* Device::createGeometryShader() {
		GeometryShader* geometryShader = new GeometryShader(this);
		return geometryShader;
	}

	FragmentShader* Device::createFragmentShader() {
		FragmentShader* fragmentShader = new FragmentShader(this);
		return fragmentShader;
	}

	TesselationControlShader* Device::createTessellationControlShader() {
		TesselationControlShader* tesselationControlShader = new TesselationControlShader(this);
		return tesselationControlShader;
	}

	TesselationEvaluationShader* Device::createTessellationEvaluationShader() {
		TesselationEvaluationShader* tesselationEvaluationShader = new TesselationEvaluationShader(this);
		return tesselationEvaluationShader;
	}

	ComputeShader* Device::createComputeShader() {
		ComputeShader* computeShader = new ComputeShader(this);
		return computeShader;
	}

	DescriptorPool* Device::createDescriptorPool() {
		DescriptorPool* descriptorPool = new DescriptorPool(this);
		return descriptorPool;
	}

	DescriptorSetLayout* Device::createDescriptorSetLayout() {
		DescriptorSetLayout* descriptorSetLayout = new DescriptorSetLayout(this);
		return descriptorSetLayout;
	}

	PipelineCache* Device::createPipelineCache() {
		PipelineCache* pipelineCache = new PipelineCache(this);
		return pipelineCache;
	}

	Pipeline* Device::createPipeline() {
		Pipeline* pipeline = new Pipeline(this);
		return pipeline;
	}

	FrameBuffer* Device::createFrameBuffer() {
		FrameBuffer* frameBuffer = new FrameBuffer(this);
		return frameBuffer;
	}

	RenderPass* Device::createRenderPass() {
		RenderPass* renderPass = new RenderPass(this);
		return renderPass;
	}

	Texture2D* Device::createTexture2D() {
		Texture2D* texture2D = new Texture2D(this);
		return texture2D;
	}

	Fence* Device::createFence() {
		Fence* fence = new Fence(this);
		return fence;
	}

	FenceManager* Device::createFenceManager() {
		FenceManager* fenceManager = new FenceManager(this);
		return fenceManager;
	}

//
// Surface
//

	Surface::Surface(Instance* instance, Device* device, Windows* window)
		:	m_instance(instance)
		, m_device(device)
		, m_window(window)
		, m_surface(VK_NULL_HANDLE)
		, m_queueFamilyIndex(0)
		, m_queueIndex(0) {
	}

	Surface::~Surface() {

	}

	Result Surface::init() {
		VkfSurfaceCreateInfo createInfo = {};
		createInfo.instance = m_instance->getVkfHandle();
		createInfo.device = m_device->getVkfHandle();
		createInfo.window = m_window->getVkfWindow();
		if(vkfCreateSurface(&createInfo, &m_surface) != VKF_SUCCESS) {
			return Result::FAILED;
		}

		return Result::SUCCESS;
	}

	SwapChain* Surface::createSwapChain() {
		SwapChain* swapChain = new SwapChain(this);
		return swapChain;
	}

	void Surface::destroy() {
		vkfDestroySurface(m_surface);
	}

	Device* Surface::getDevice() const {
		return m_device;
	}

	VkSurfaceCapabilitiesKHR Surface::getSurfaceCaps() const {
		return m_surface->surfaceCaps;
	}

	VkFormat Surface::getColorFormat() const {
		return m_surface->colorFormat;
	}

	VkColorSpaceKHR Surface::getColorSpace() const {
		return m_surface->colorSpace;
	}

	VkExtent2D Surface::getExtent2D() const {
		return m_surface->extent2D;
	}

	VkPresentModeKHR Surface::getPresentMode() const {
		return m_surface->presentMode;
	}

	VkfSurface* Surface::getVkfHandle() const {
		return m_surface;
	}

//
// SwapChain
//

	SwapChain::SwapChain(Surface* surface)
		: m_surface(surface)
		, m_swapChain(nullptr) {
	}

	SwapChain::~SwapChain() {

	}


	Result SwapChain::init() {

		VkfSwapchainCreateInfo createInfo = {};
		createInfo.device = m_surface->getDevice()->getVkfHandle();
		createInfo.surface = m_surface->getVkfHandle();

		if(vkfCreateSwapchain(&createInfo, &m_swapChain) != VKF_SUCCESS) {
			return Result::FAILED;
		}

		return Result::SUCCESS;
	}

	void SwapChain::destroy() {
		vkfDestroySwapchain(m_swapChain);
	}

	VkRenderPass SwapChain::getRenderPass() const {
		return m_swapChain->renderPass->renderPass;
	}

	Surface* SwapChain::getSurface() const {
		return m_surface;
	}

	VkResult SwapChain::nextImage(uint32_t& imageIndices, Semaphore* presentSemaphore, FenceManager* fenceManager) {
		if(fenceManager) {
			fenceManager->resetAll();
		}

		VkResult result = vkAcquireNextImageKHR(*m_surface->getDevice(),
		                                        m_swapChain->swapChain,
												UINT64_MAX,
		                                        *presentSemaphore,
		                                        fenceManager ? fenceManager->getFence(FenceManager::FenceType::AquireImage) : VK_NULL_HANDLE,
		                                        &imageIndices);
		if(result == VK_ERROR_OUT_OF_DATE_KHR) {
			std::cout << "VK_ERROR_OUT_OF_DATE_KHR" << std::endl;
		} else if(result == VK_SUBOPTIMAL_KHR) {
			std::cout << "VK_SUBOPTIMAL_KHR" << std::endl;
		} else {
			assert(VK_SUCCESS == result);
		}

		if(fenceManager) {
			fenceManager->waitForFence(FenceManager::FenceType::AquireImage);
		}

		return result;
	}

	VkResult SwapChain::present(Queue* queue, uint32_t imageIndices, Semaphore* renderingFinishedSemaphore) {

		VkPresentInfoKHR present;
		present.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
		present.pNext = nullptr;
		present.swapchainCount = 1;
		present.pSwapchains = &m_swapChain->swapChain;
		present.pImageIndices = &imageIndices;
		present.waitSemaphoreCount = 1;
		present.pWaitSemaphores = *renderingFinishedSemaphore;
		present.pResults = nullptr;

		VkResult result = vkQueuePresentKHR(*queue, &present);
		return result;
	}

	uint32_t SwapChain::getImageCount() {
		return m_swapChain->numberOfImages;
	}

	VkFramebuffer SwapChain::getFramebuffer(uint32_t idx) const {
		return m_swapChain->framebuffers[idx]->framebuffer;
	}

//
// CommandPool
//

	CommandPool::CommandPool(Device* device, VkCommandPoolCreateFlags commandPoolCreateFlags)
		: m_device(device)
		, m_cmdPool(VK_NULL_HANDLE)
		, m_commandPoolCreateFlags(commandPoolCreateFlags) {
	}

	CommandPool::~CommandPool() {
	}

	VkResult CommandPool::init() {

		VkCommandPoolCreateInfo cmdPoolInfo {};
		cmdPoolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
		cmdPoolInfo.queueFamilyIndex = m_device->getGraphicsQueueIndex();
		cmdPoolInfo.flags = m_commandPoolCreateFlags;

		VkResult result = vkCreateCommandPool(*m_device, &cmdPoolInfo, nullptr, &m_cmdPool);
		if(VK_SUCCESS != result) {
			std::cerr << "vkCreateCommandPool failed: " << vkfVkResultToString(result) << std::endl;
		}

		return result;
	}

	CommandBuffers* CommandPool::createCommandBuffers() {
		CommandBuffers* commandBuffers = new CommandBuffers(m_device, this);
		return commandBuffers;
	}

	CommandBuffer* CommandPool::createCommandBuffer() {
		CommandBuffer* commandBuffer = new CommandBuffer(this);
		return commandBuffer;
	}

	VkResult CommandPool::reset(VkCommandPoolCreateFlags commandPoolCreateFlags) {
		m_commandPoolCreateFlags = commandPoolCreateFlags;

		VkResult result = vkResetCommandPool(*m_device, m_cmdPool, m_commandPoolCreateFlags);
		if(VK_SUCCESS != result) {
			std::cerr << "vkResetCommandPool failed: " << vkfVkResultToString(result) << std::endl;
		}

		return result;
	}

	Device* CommandPool::getDevice() const {
		return m_device;
	}

	void CommandPool::destroy() {
		if(VK_NULL_HANDLE != m_cmdPool) {
			vkDestroyCommandPool(*m_device, m_cmdPool, nullptr);
			m_cmdPool = VK_NULL_HANDLE;
		}
	}

//
// CommandBuffer
//

	CommandBuffer::CommandBuffer(CommandPool* commandPool)
		: m_commandPool(commandPool)
		, m_cmdBuffer(VK_NULL_HANDLE)
		, m_isBegin(false) {
	}

	CommandBuffer::~CommandBuffer() {
	}

	VkResult CommandBuffer::init() {

		VkCommandBufferAllocateInfo commandBufferAllocateInfo {};
		commandBufferAllocateInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
		commandBufferAllocateInfo.commandPool = *m_commandPool;
		commandBufferAllocateInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
		commandBufferAllocateInfo.commandBufferCount = 1;

		VkResult result = vkAllocateCommandBuffers(*m_commandPool->getDevice(), &commandBufferAllocateInfo, &m_cmdBuffer);
		if(result != VK_SUCCESS) {
			std::cerr << "vkAllocateCommandBuffers failed: " << vkfVkResultToString(result) << std::endl;
			return result;
		}
		return result;
	}

	VkResult CommandBuffer::begin(VkCommandBufferUsageFlags usageFlags) {
		assert(true != m_isBegin && "vkBeginCommandBuffer will fail because it is already used.");

		VkCommandBufferBeginInfo commandBufferBeginInfo {};
		commandBufferBeginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;

		// Command buffer will be reset and recorded again between each submission.
		commandBufferBeginInfo.flags = usageFlags;

		VkResult result = vkBeginCommandBuffer(m_cmdBuffer, &commandBufferBeginInfo);
		if(result != VK_SUCCESS) {
			std::cerr << "vkBeginCommandBuffer failed: " << vkfVkResultToString(result) << std::endl;
			return result;
		}

		m_isBegin = true;

		return result;
	}

	VkResult CommandBuffer::end() {
		assert(true == m_isBegin && "vkEndCommandBuffer will fail because vkBeginCommandBuffer is not used.");

		VkResult result = vkEndCommandBuffer(m_cmdBuffer);
		if(result != VK_SUCCESS) {
			std::cerr << "vkEndCommandBuffer failed: " << vkfVkResultToString(result) << std::endl;
		}

		m_isBegin = false;

		return result;
	}

	void CommandBuffer::destroy() {
		if(VK_NULL_HANDLE != m_cmdBuffer) {
			vkFreeCommandBuffers(*m_commandPool->getDevice(), *m_commandPool, 1, &m_cmdBuffer);
			m_cmdBuffer = VK_NULL_HANDLE;
		}
		m_isBegin = false;
	}

	void CommandBuffer::reset() {
		vkResetCommandPool(*m_commandPool->getDevice(), *m_commandPool, 0);
	}

//
// CommandBuffers
//

	CommandBuffers::CommandBuffers(Device* device, CommandPool* commandPool)
		: m_device(device)
		, m_commandPool(commandPool)
		, m_postPresentCmdBuffer(VK_NULL_HANDLE) {
	}

	CommandBuffers::CommandBuffers(Device* device, CommandPool* commandPool, uint32_t number)
		: m_device(device)
		, m_commandPool(commandPool)
		, m_postPresentCmdBuffer(VK_NULL_HANDLE) {
		m_cmdBuffers.reserve(number);
		m_cmdBuffers.resize(number);
	}

	CommandBuffers::~CommandBuffers() {
	}

	VkResult CommandBuffers::init() {

		for(size_t index = 0; index < m_cmdBuffers.size(); index++) {
			m_cmdBuffers[index] = new CommandBuffer(m_commandPool);
			VkResult Result = m_cmdBuffers[index]->init();
			if(VK_SUCCESS != Result) {
				destroy();
				return Result;
			}
		}

		return VK_SUCCESS;
	}

	VkResult CommandBuffers::init(uint32_t number) {
		m_cmdBuffers.reserve(number);
		m_cmdBuffers.resize(number);
		return init();
	}

	void CommandBuffers::destroy() {
		for(auto& commandBuffer : m_cmdBuffers) {
			commandBuffer->destroy();
		}
		m_cmdBuffers.clear();
	}

	std::vector<VkCommandBuffer> CommandBuffers::getCommandBuffers() const {
		std::vector<VkCommandBuffer> commandBuffersTmp;
		for(const auto& cmd : m_cmdBuffers) {
			commandBuffersTmp.push_back(*cmd);
		}
		return commandBuffersTmp;
	}

//
// Semaphore
//

	Semaphore::Semaphore(Device* device)
		: m_device(device)
		, m_semaphore(VK_NULL_HANDLE) {
	}

	Semaphore::~Semaphore() {
	}

	VkResult Semaphore::init() {
		VkSemaphoreCreateInfo semaphoreCreateInfo {};
		semaphoreCreateInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

		VkResult result = vkCreateSemaphore(*m_device, &semaphoreCreateInfo, nullptr, &m_semaphore);
		if(result != VK_SUCCESS) {
			std::cerr << "vkCreateSemaphore failed: " << vkfVkResultToString(result) << std::endl;
		}
		return result;
	}

	void Semaphore::destroy() {
		if(VK_NULL_HANDLE != m_semaphore) {
			vkDestroySemaphore(*m_device, m_semaphore, nullptr);
			m_semaphore = VK_NULL_HANDLE;
		}
	}

//
// Fence
//

	Fence::Fence(Device* device)
		: m_device(device)
		, m_fence(VK_NULL_HANDLE) {
	}

	VkResult Fence::init() {
		VkFenceCreateInfo fenceCreateInfo {};
		fenceCreateInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
		fenceCreateInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;

		VkResult result = vkCreateFence(*m_device, &fenceCreateInfo, nullptr, &m_fence);
		if(VK_SUCCESS != result) {
			std::cerr << "vkQueueSubmit failed: " << vkfVkResultToString(result) << std::endl;
		}
		return result;
	}

	void Fence::destroy() {
		if(VK_NULL_HANDLE != m_fence) {
			vkDestroyFence(*m_device, m_fence, nullptr);
			m_fence = VK_NULL_HANDLE;
		}
	}

	void Fence::reset() {
		vkResetFences(*m_device, 1, &m_fence);
	}

//
// FenceManager
//

	FenceManager::FenceManager(Device* device)
		: m_device(device) {
	}

	VkResult FenceManager::init() {
		return VK_SUCCESS;
	}

	void FenceManager::destroy() {
		for(auto& fence : m_fences) {
			fence->destroy();
		}
		m_fences.clear();
	}

	VkResult FenceManager::getStatus(Fence* fence) {
		return vkGetFenceStatus(*m_device, *fence);
	}

	void FenceManager::add(Fence* fence) {
		m_fences.push_back(fence);
		m_nativeHandles.push_back(fence->getNativeHandle());
	}

	void FenceManager::remove(Fence* fence) {
//		for(auto& fence : m_fences) {
//			m_fences.erase(fence);
//		}
	}

	void FenceManager::reset(Fence* fence) {
		if(fence) {
			vkResetFences(*m_device, 1, *fence);
		}
	}

	void FenceManager::resetAll() {
		if(m_nativeHandles.size() > 0) {
			vkResetFences(*m_device, m_nativeHandles.size(), m_nativeHandles.data());
		}
	}

	VkResult FenceManager::waitForAllFences() {
		VkResult result = vkWaitForFences(*m_device, m_nativeHandles.size(), m_nativeHandles.data(), VK_TRUE, UINT64_MAX);

		assert(result != VK_ERROR_DEVICE_LOST);
		return result;
	}

	VkResult FenceManager::waitForFence(uint32_t idx) {
		VkResult result = vkWaitForFences(*m_device, 1, &m_nativeHandles[idx], VK_TRUE, UINT64_MAX);

		assert(result != VK_ERROR_DEVICE_LOST);
		return result;
	}

//
// Queue
//

	Queue::Queue(Device* device, FamilyQueueIndex famliyQueueIndex)
		: m_device(device)
		, m_queue(VK_NULL_HANDLE)
		, m_queueFamilyIndex(famliyQueueIndex) {
	}


	Queue::Queue(Device* device, FamilyQueueIndex famliyQueueIndex, uint32_t queueIndex)
		: m_device(device)
		, m_queue(VK_NULL_HANDLE)
		, m_queueFamilyIndex(famliyQueueIndex)
		, m_queueIndex(queueIndex) {
	}

	VkResult Queue::init(uint32_t queueIndex) {
		m_queueIndex = queueIndex;
		return init();
	}

	VkResult Queue::init() {
		vkGetDeviceQueue(*m_device, m_queueFamilyIndex, m_queueIndex, &m_queue);
		return VK_SUCCESS;
	}

	void Queue::destroy() {
	}

	VkResult Queue::submit(VkSubmitInfo& submitInfo, Fence* fence) {
		VkResult result = vkQueueSubmit(m_queue, 1, &submitInfo, (fence != nullptr) ? fence->getNativeHandle() : VK_NULL_HANDLE);
		if(VK_SUCCESS != result) {
			std::cerr << "vkQueueSubmit failed: " << vkfVkResultToString(result) << std::endl;
		}
		return result;
	}

	VkResult Queue::submit(CommandBuffer* commandBuffer, Fence* fence) {
		VkSubmitInfo submitInfo {};
		submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
		submitInfo.commandBufferCount = 1;
		submitInfo.pCommandBuffers = *commandBuffer;

		VkResult result = vkQueueSubmit(m_queue, 1, &submitInfo, (fence != nullptr) ? fence->getNativeHandle() : VK_NULL_HANDLE);
		if(VK_SUCCESS != result) {
			std::cerr << "vkQueueSubmit failed: " << vkfVkResultToString(result) << std::endl;
		}
		return result;
	}

	VkResult Queue::submit(CommandBuffer* commandBuffer, const VkPipelineStageFlags pipelineStageFlags, Fence* fence) {
		VkSubmitInfo submitInfo {};
		submitInfo.pWaitDstStageMask = &pipelineStageFlags;
		submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
		submitInfo.commandBufferCount = 1;
		submitInfo.pCommandBuffers = *commandBuffer;

		VkResult result = vkQueueSubmit(m_queue, 1, &submitInfo, (fence != nullptr) ? fence->getNativeHandle() : VK_NULL_HANDLE);
		if(VK_SUCCESS != result) {
			std::cerr << "vkQueueSubmit failed: " << vkfVkResultToString(result) << std::endl;
		}
		return result;
	}

	VkResult Queue::submit(CommandBuffer* commandBuffer, VkPipelineStageFlags pipelineStageFlags, Semaphore* renderComplete, Semaphore* presentComplete, Fence* fence) {
		VkSubmitInfo submitInfo {};
		submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
		submitInfo.pWaitDstStageMask = &pipelineStageFlags;
		submitInfo.commandBufferCount = 1;
		submitInfo.pCommandBuffers = *commandBuffer;
		submitInfo.waitSemaphoreCount = 1;
		submitInfo.pWaitSemaphores = *presentComplete;
		submitInfo.signalSemaphoreCount = 1;
		submitInfo.pSignalSemaphores = *renderComplete;
		VkResult result = vkQueueSubmit(m_queue, 1, &submitInfo, (fence != nullptr) ? fence->getNativeHandle() : VK_NULL_HANDLE);
		if(VK_SUCCESS != result) {
			std::cerr << "vkQueueSubmit failed: " << vkfVkResultToString(result) << std::endl;
		}
		return result;
	}

	VkResult Queue::waitIdle() {
		VkResult result = vkQueueWaitIdle(m_queue);
		return result;
	}

	uint32_t Queue::getQueueFamilyIndex() const {
		return m_queueFamilyIndex;
	}

//
// RenderPass
//

	RenderPass::RenderPass(Device* device)
		: m_device(device)
		, m_renderPass(VK_NULL_HANDLE) {
		vkfInitRenderPass(device->getVkfHandle(), &m_renderPass);
	}

	RenderPass::~RenderPass() {

	}

	void RenderPass::addColorAttachment(VkFormat format, VkImageLayout initialImageLayout, VkImageLayout finalImageLayout) {
		vkfRenderPassAddColorAttachment(m_renderPass, format, initialImageLayout, finalImageLayout);
	}

	void RenderPass::addDepthStencilAttachment(VkFormat format, VkImageLayout initialImageLayout) {
		vkfRenderPassAddDepthStencilAttachment(m_renderPass, format, initialImageLayout);
	}

	Result RenderPass::init() {
		if(vkfCreateRenderPass(m_device->getVkfHandle(), &m_renderPass) != VKF_SUCCESS) {
			return Result::FAILED;
		}
		return Result::SUCCESS;
	}

	VkfRenderPass* RenderPass::getVkfHandle() const {
		return m_renderPass;
	}

	void RenderPass::destroy() {
		vkfDestroyRenderPass(m_renderPass);
	}

//
// RenderPassScope
//

	RenderPassScope::RenderPassScope(CommandBuffer* commandBuffer, VkFramebuffer framebuffer, VkRenderPass renderPass, VkExtent2D extent, std::vector<VkClearValue>& clearValues)
		: m_commandBuffer(commandBuffer) {

		VkRenderPassBeginInfo renderPassBeginInfo {};
		renderPassBeginInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
		renderPassBeginInfo.framebuffer = framebuffer;
		renderPassBeginInfo.renderPass = renderPass;
		renderPassBeginInfo.renderArea.offset.x = 0;
		renderPassBeginInfo.renderArea.offset.y = 0;
		renderPassBeginInfo.renderArea.extent = extent;
		renderPassBeginInfo.clearValueCount = clearValues.size();
		renderPassBeginInfo.pClearValues = clearValues.data();

		vkCmdBeginRenderPass(*m_commandBuffer, &renderPassBeginInfo, VK_SUBPASS_CONTENTS_INLINE);
	}

	RenderPassScope::~RenderPassScope() {
		vkCmdEndRenderPass(*m_commandBuffer);
	}

//
// FrameBuffer
//

	FrameBuffer::FrameBuffer(Device* device)
		: m_device(device)
		, m_renderPass(nullptr)
		, m_frameBuffer(nullptr) {
		vkfInitFrameBuffer(m_device->getVkfHandle(), &m_frameBuffer);
	}

	FrameBuffer::FrameBuffer(Device* device, RenderPass* renderPass)
		: m_device(device)
		, m_renderPass(renderPass)
		, m_frameBuffer(nullptr) {
		vkfInitFrameBuffer(m_device->getVkfHandle(), &m_frameBuffer);
	}

	Result FrameBuffer::init(uint32_t width, uint32_t height) {
		VkfFrameBufferCreateInfo createInfo = {};
		createInfo.device = m_device->getVkfHandle();
		createInfo.renderPass = m_renderPass->getVkfHandle();
		createInfo.width = width;
		createInfo.height = height;

		if(vkfCreateFrameBuffer(&createInfo, &m_frameBuffer) != VKF_SUCCESS) {
			return Result::FAILED;
		}
		return Result::SUCCESS;
	}

	Result FrameBuffer::init(RenderPass* renderPass, uint32_t width, uint32_t height) {
		m_renderPass = renderPass;
		return init(width, height);
	}

	void FrameBuffer::destroy() {
		vkfDestroyFrameBuffer(m_frameBuffer);
	}


	VkResult FrameBuffer::addColor(Texture2D* imageColor) {
		vkfFrameBufferAddColorAttachment(m_frameBuffer, imageColor->getImageView());
		return VK_SUCCESS;
	}

	Result FrameBuffer::addDepthStencil(VkFormat format, uint32_t width, uint32_t height) {
		assert(0);
		return Result::FAILED;
	}

	Result FrameBuffer::addDepthStencil(Texture2D* depthStencilTexture) {
		vkfFrameBufferAddDepthStencilrAttachment(m_frameBuffer, depthStencilTexture->getImageView());
		return Result::SUCCESS;
	}

//
// BufferBase
//

	BufferBase::BufferBase(Device* device, VkBufferUsageFlagBits bufferUsageFlagBits)
		: m_device(device)
		, m_buffer(nullptr)
		, m_bufferUsageFlagBits(bufferUsageFlagBits)
		, m_size(0) {
			
		VkfBufferCreateInfo createInfo = {};
		createInfo.device = m_device->getVkfHandle();
		createInfo.bufferUsageFlagBits = m_bufferUsageFlagBits;
		createInfo.size = m_size;

		if(VK_BUFFER_USAGE_VERTEX_BUFFER_BIT == bufferUsageFlagBits) {
			vkfInitVertexBuffer(&createInfo, &m_buffer);
		} else if(VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT == bufferUsageFlagBits) {
			vkfInitUniformBuffer(&createInfo, &m_buffer);
		} else if(VK_BUFFER_USAGE_INDEX_BUFFER_BIT == bufferUsageFlagBits) {
			vkfInitIndexBuffer(&createInfo, &m_buffer);
		} else if(VK_BUFFER_USAGE_TRANSFER_SRC_BIT == bufferUsageFlagBits) {
			vkfInitStagingBuffer(&createInfo, &m_buffer);
		} else {
			assert(0);
		}
	}


	BufferBase::BufferBase(Device* device, VkBufferUsageFlagBits bufferUsageFlagBits, const BufferSize& size)
		: m_device(device)
		, m_buffer(nullptr)
		, m_bufferUsageFlagBits(bufferUsageFlagBits)
		, m_size(size) {
		VkfBufferCreateInfo createInfo = {};
		createInfo.device = m_device->getVkfHandle();
		createInfo.bufferUsageFlagBits = m_bufferUsageFlagBits;
		createInfo.size = m_size;
		vkfInitBuffer(&createInfo, &m_buffer);
	}

	BufferBase::~BufferBase() {
	}

	Result BufferBase::init() {
		VkfBufferCreateInfo createInfo = {};
		createInfo.device = m_device->getVkfHandle();
		createInfo.bufferUsageFlagBits = m_bufferUsageFlagBits;
		createInfo.size = m_size;

		if(vkfCreateBuffer(&createInfo, &m_buffer) != VKF_SUCCESS) {
			return Result::FAILED;
		}

		return Result::SUCCESS;
	}

	Result BufferBase::init(const BufferSize& size) {
		m_size = size;
		return init();
	}

	Result BufferBase::upload(uint8_t* src, const BufferSize& size, uint64_t offset) {
		if(vkfUploadBuffer(m_buffer, src, size, offset) != VKF_SUCCESS) {
			return Result::FAILED;
		}

		return Result::SUCCESS;
	}

	void BufferBase::destroy() {
		vkfDestroyBuffer(m_buffer);
	}

	VkfBuffer* BufferBase::getVkfHandle() const {
		return m_buffer;
	}

//
// VertexBuffer
//

	VertexBuffer::VertexBuffer(Device* device)
		: BufferBase(device, VK_BUFFER_USAGE_VERTEX_BUFFER_BIT)
		, m_stride(BufferStride::Zero) {
	}

	VertexBuffer::VertexBuffer(Device* device, const BufferSize& size, BufferStride stride)
		: BufferBase(device, VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, size)
		, m_stride(stride) {
	}

	Result VertexBuffer::init() {
		return BufferBase::init();
	}

	Result VertexBuffer::init(const BufferSize& size, BufferStride stride) {
		m_stride = stride;
		return BufferBase::init(size);
	}

	uint32_t VertexBuffer::getBindingID() const {
		return m_buffer->binding;
	}

	BufferStride VertexBuffer::getStride() const {
		return m_stride;
	}

	VertexBuffer& VertexBuffer::addElement(const BindingPoint& binding, const LocationPoint& location, VkFormat format, uint32_t offset) {
		vkfBufferAddElement(m_buffer, binding, location, format, offset);
		return *this;
	}

//
// IndexBuffer
//

	IndexBuffer::IndexBuffer(Device* device)
		: BufferBase(device, VK_BUFFER_USAGE_INDEX_BUFFER_BIT)
		, m_number(0) {
	}

	IndexBuffer::IndexBuffer(Device* device, uint32_t numberOfIndicies, const BufferSize& size)
		: BufferBase(device, VK_BUFFER_USAGE_INDEX_BUFFER_BIT, size)
		, m_number(numberOfIndicies) {
	}

	Result IndexBuffer::init(uint32_t numberOfIndicies, const BufferSize& size) {
		m_number = numberOfIndicies;
		return BufferBase::init(size);
	}

	uint32_t IndexBuffer::getNumberOfIndicies() const {
		return m_number;
	}

//
//
//

	UniformBuffer::UniformBuffer(Device* device)
		: BufferBase(device, VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT) {
	}

	UniformBuffer::UniformBuffer(Device* device, const BufferSize& size)
		: BufferBase(device, VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT, size) {
	}

	VkDescriptorBufferInfo& UniformBuffer::getDescriptorBufferInfo() {
		descriptorBufferInfo = {m_buffer->buffer, 0, m_buffer->size};

		return descriptorBufferInfo;
	}

//
//
//
	StagingBuffer::StagingBuffer(Device* device)
		: BufferBase(device, VK_BUFFER_USAGE_TRANSFER_SRC_BIT) {
	}

	StagingBuffer::StagingBuffer(Device* device, const BufferSize& size)
		: BufferBase(device, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, size) {
	}

	Result StagingBuffer::init(const BufferSize& size) {
		return BufferBase::init(size);
	}
//
//
//

	DescriptorSetLayout::DescriptorSetLayout(Device* device)
		: m_descriptorSetLayout(nullptr) {
		VkfDescriptorSetLayoutCreateInfo createInfo = {};
		createInfo.device = device->getVkfHandle();
		vkfInitDescriptorSetLayout(&createInfo, &m_descriptorSetLayout);
	}

	DescriptorSetLayout& DescriptorSetLayout::add(const BindingPoint& binding, const DescriptorCount& count, VkDescriptorType descriptorType, VkShaderStageFlags shaderStageFlags) {
		vkfDescriptorSetLayoutBind(m_descriptorSetLayout, binding, count, descriptorType, shaderStageFlags);
		return *this;
	}

	Result DescriptorSetLayout::init() {

		if(vkfCreateDescriptorSetLayout(m_descriptorSetLayout) != VKF_SUCCESS) {
			return Result::FAILED;
		}

		return Result::SUCCESS;
	}

	void DescriptorSetLayout::destroy() {
		vkfDestroyDescriptorSetLayout(m_descriptorSetLayout);
	}

//
// DescriptorPool
//

	DescriptorPool::DescriptorPool(Device* device)
		: m_device(device)
		, m_descriptorPool(nullptr) {
		VkfDescriptorPoolCreateInfo descriptorPoolCreateInfo = {};
		descriptorPoolCreateInfo.device = device->getVkfHandle();

		vkfInitDescriptorPool(&descriptorPoolCreateInfo, &m_descriptorPool);
	}

	DescriptorPool& DescriptorPool::add(VkDescriptorType descriptorType, uint32_t count) {
		vkfDescriptorPoolAdd(m_descriptorPool, descriptorType, count);
		return *this;
	}

	Result DescriptorPool::init() {
		if(vkfCreateDescriptorPool(m_descriptorPool) != VKF_SUCCESS) {
			return Result::FAILED;
		}

		return Result::SUCCESS;
	}

	void DescriptorPool::destroy() {
		vkfDestroyDescriptorPool(m_descriptorPool);
	}

	DescriptorSet* DescriptorPool::createDescriptorSet() {
		DescriptorSet* descriptorSet = new DescriptorSet(m_device, this);
		return descriptorSet;
	}


//
// DescriptorSet
//

	DescriptorSet::DescriptorSet(Device* device, DescriptorPool* descriptorPool)
		: m_device(device)
		, m_descriptorPool(descriptorPool)
		, m_layout(nullptr) {
		VkfDescriptorSetCreateInfo createInfo = {};
		createInfo.device = device->getVkfHandle();
		createInfo.descriptorPool = descriptorPool->getVkfHandle();
		createInfo.descriptorSetLayout = NULL;
		vkfInitDescriptorSet(&createInfo, &m_descriptorSet);
	}

	DescriptorSet::DescriptorSet(Device* device, DescriptorPool* descriptorPool, DescriptorSetLayout* layout)
		: m_device(device)
		, m_descriptorPool(descriptorPool)
		, m_layout(layout) {
		VkfDescriptorSetCreateInfo createInfo = {};
		createInfo.device = device->getVkfHandle();
		createInfo.descriptorPool = descriptorPool->getVkfHandle();
		createInfo.descriptorSetLayout = layout->getVkfHandle();
		vkfInitDescriptorSet(&createInfo, &m_descriptorSet);
	}

	void DescriptorSet::bind(const BindingPoint& binding, UniformBuffer* uniformBuffer) {
		vkfDescriptorSetBindUniformBuffer(m_descriptorSet, binding, uniformBuffer->getVkfHandle());
	}

	void DescriptorSet::bind(const BindingPoint& binding, vkf::Texture* texture, vkf::TextureSampler* textureSampler) {
		vkfDescriptorSetBindTexture(m_descriptorSet, binding, texture->getVkfHandle(), textureSampler->getVkfHandle());
//		VkDescriptorImageInfo descriptorImageInfo {};
//		if(texture) {
//			descriptorImageInfo.imageView = texture->getImageView();
//			descriptorImageInfo.imageLayout = texture->getImageLayout();
//		}
//		if(textureSampler) {
//			descriptorImageInfo.sampler = *textureSampler;
//		}
//
//		m_descriptorImageInfo[binding] = descriptorImageInfo;
//
//		VkWriteDescriptorSet write {};
//		write.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
//		write.descriptorCount = 1; // TODO Do we need to adapt something here?
//		write.descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
//		write.pImageInfo = &m_descriptorImageInfo[binding];
//		write.dstBinding = binding;
//
//		m_writeDescriptorSets.push_back(write);
	}


	Result DescriptorSet::init() {
		m_descriptorSet->descriptorSetLayout = m_layout->getVkfHandle();
		if(vkfCreateDescriptorSet(m_descriptorSet) != VKF_SUCCESS) {
			return Result::FAILED;
		}

		return Result::SUCCESS;
	}

	Result DescriptorSet::init(DescriptorSetLayout* layout) {
		m_layout = layout;
		return init();
	}

	void DescriptorSet::destroy() {
		vkfDestroyDescriptorSet(m_descriptorSet);
	}

//
// PipelineCache
//

	PipelineCache::PipelineCache(Device* device)
		: m_device(device)
		, m_pipeLineCache(VK_NULL_HANDLE) {
	}

	PipelineCache::~PipelineCache() {

	}

	VkResult PipelineCache::init() {
		VkPipelineCacheCreateInfo pipelineCacheCreateInfo {};
		pipelineCacheCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO;
		VkResult result = vkCreatePipelineCache(*m_device, &pipelineCacheCreateInfo, nullptr, &m_pipeLineCache);
		if(VK_SUCCESS != result) {
			std::cerr << "vkCreatePipelineCache failed: " << vkfVkResultToString(result) << std::endl;
		}
		return result;
	}

	void PipelineCache::destroy() {
		if(VK_NULL_HANDLE != m_pipeLineCache) {
			vkDestroyPipelineCache(*m_device, m_pipeLineCache, nullptr);
			m_pipeLineCache = VK_NULL_HANDLE;
		}
	}

//
//
//

	ShaderModule::ShaderModule(Device* device, VkShaderStageFlagBits shaderStageFalgBits, const std::string& entryName)
		: m_device(device)
		, m_shaderModule(VK_NULL_HANDLE)
		, m_shaderStageFlagBits(shaderStageFalgBits)
		, m_entryName(entryName) {

	}

	ShaderModule::~ShaderModule() {

	}

	Result ShaderModule::load(const FileName& filename) {
		VkfShaderModuleCreateInfo createInfo = {};
		createInfo.device = m_device->getVkfHandle();
		createInfo.filename = filename;
		createInfo.shaderBinary = NULL;
		createInfo.shaderSize = 0;
		createInfo.shaderBinary = NULL;
		createInfo.shaderStageFlagBits = m_shaderStageFlagBits;
		createInfo.entryName = m_entryName.c_str();

		if(vkfCreateShaderModule(&createInfo, &m_shaderModule) != VKF_SUCCESS) {
			return Result::FAILED;
		}

		return Result::SUCCESS;
	}

	void ShaderModule::destroy() {
		vkfDestroyShaderModule(m_shaderModule);
	}

	VkShaderStageFlagBits ShaderModule::getShaderStageFlagBits() const {
		return m_shaderModule->shaderStageFlagBits;
	}

	const char* ShaderModule::getEntryName() const {
		return m_entryName.c_str();
	}

	uint32_t* ShaderModule::getBinary() const {
		return m_shaderModule->binary;
	}

	uint32_t ShaderModule::getBinarySize() const {
		return m_shaderModule->binarySize;
	}


//
//
//

	VertexShader::VertexShader(Device* device)
		: ShaderModule(device, VK_SHADER_STAGE_VERTEX_BIT) {
	}

//
//
//

	GeometryShader::GeometryShader(Device* device)
		: ShaderModule(device, VK_SHADER_STAGE_GEOMETRY_BIT) {
	}

//
//
//

	FragmentShader::FragmentShader(Device* device)
		: ShaderModule(device, VK_SHADER_STAGE_FRAGMENT_BIT) {
	}

//
//
//

	TesselationControlShader::TesselationControlShader(Device* device)
		: ShaderModule(device, VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT) {
	}

//
//
//

	TesselationEvaluationShader::TesselationEvaluationShader(Device* device)
		: ShaderModule(device, VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT) {
	}

//
//
//

	ComputeShader::ComputeShader(Device* device)
		: ShaderModule(device, VK_SHADER_STAGE_COMPUTE_BIT) {
	}

//
//
//
	Texture::Texture(Device* device)
		: m_device(device)
		, m_imageType(VK_IMAGE_TYPE_2D)
		, m_imageViewType(VK_IMAGE_VIEW_TYPE_2D)
		, m_memoryAllocateInfo {}
		, m_width(0)
		, m_height(0)
		, m_depth(1)
		, m_tiling(VK_IMAGE_TILING_LINEAR) {
	}

	Texture::Texture(Device* device,
	                 VkImageLayout imageTextureLayout,
	                 VkImageType imageType,
	                 VkImageViewType imageViewType,
	                 VkImageUsageFlags imageUsageFlags,
	                 VkFormat format,
	                 uint32_t width,
	                 uint32_t height,
	                 uint32_t depth)
		: m_device(device)
		, m_imageType(imageType)
		, m_imageViewType(VK_IMAGE_VIEW_TYPE_2D)
		, m_format(format)
		, m_imageLayout(imageTextureLayout)
		, m_imageUsageFlags(imageUsageFlags)
		, m_memoryAllocateInfo {}
		, m_width(width)
		, m_height(height)
		, m_depth(depth)
		, m_tiling(VK_IMAGE_TILING_LINEAR) {
	}

	Texture::~Texture() {
	}

	Result Texture::init() {
		if(vkfCreateTexture(m_device->getVkfHandle(), m_format, m_imageType, m_imageViewType, m_width, m_height, m_depth, m_imageUsageFlags, m_imageLayout, m_tiling, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, &m_texture) != VKF_SUCCESS) {
			return Result::FAILED;
		}
		return Result::SUCCESS;
	}

	VkImageAspectFlags Texture::getImageAspectFlagBitsFromFormat(VkFormat format) {
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

	Result Texture::init(VkImageLayout imageTextureLayout, VkImageType imageType, VkImageViewType imageViewType, VkImageUsageFlags imageUsageFlags, VkFormat format, uint32_t width, uint32_t height, uint32_t depth) {
		m_imageLayout = imageTextureLayout;
		m_imageType = imageType;
		m_imageViewType = imageViewType;
		m_imageUsageFlags = imageUsageFlags;
		m_format = format;
		m_width = width;
		m_height = height;
		m_depth = depth;
		return init();
	}

	void Texture::init(VkImage image, VkFormat format, uint32_t width, uint32_t height, uint32_t depth) {
		m_format = format;
		m_width = width;
		m_height = height;
		m_depth = depth;

		vkfCreateTexture2(m_device->getVkfHandle(), image, format, m_imageViewType, width, height, depth, &m_texture);
	}

	void Texture::destroy() {
		vkfDestroyTexture(m_texture);
	}

	void* Texture::map() {
		void* data = nullptr;
		VkResult result = vkMapMemory(*m_device, m_texture->memory, 0, m_memoryAllocateInfo.allocationSize, 0, &data);
		if(VK_SUCCESS != result) {
			std::cerr << "vkAllocateMemory failed: " << vkfVkResultToString(result) << std::endl;
			return nullptr;
		}
		return data;
	}

	void Texture::unmap() {
		vkUnmapMemory(*m_device, m_texture->memory);
	}

	Result Texture::upload(uint8_t* src, const BufferSize& size, uint64_t offset) {
		if(vkfUploadTexture(m_texture, src, size, offset) != VKF_SUCCESS) {
			return Result::FAILED;
		}

		return Result::SUCCESS;
	}

	uint32_t Texture::getWidth() const {
		return m_width;
	}

	uint32_t Texture::getHeight() const {
		return m_height;
	}

	uint32_t Texture::getDepth() const {
		return m_depth;
	}

	size_t Texture::getSize() {
		return m_memoryAllocateInfo.allocationSize;
	}

	VkFormat Texture::getFormat() const {
		return m_format;
	}

	VkImage Texture::getImage() const {
		return m_texture->image;
	}

	VkImageView Texture::getImageView() const {
		return m_texture->imageView;
	}

	VkImageLayout Texture::getImageLayout() const {
		return m_imageLayout;
	}

//
//
//

	TextureSampler::TextureSampler(Device* device) {
		m_createInfo = {};
		m_createInfo.device = device->getVkfHandle();
		vkfInitTextureSampler(&m_createInfo, &m_textureSampler);
	}

	Result TextureSampler::init() {
		if(vkfCreateTextureSampler(&m_createInfo, &m_textureSampler) != VKF_SUCCESS) {
			return Result::FAILED;
		}

		return Result::SUCCESS;
	}

	void TextureSampler::destroy() {
		vkfDestroyTextureSampler(m_textureSampler);
	}

	TextureSampler& TextureSampler::setMinFilter(VkFilter minFilter) {
		m_createInfo.minFilter = minFilter;
		return *this;
	}

	TextureSampler& TextureSampler::setMagFilter(VkFilter magFilter) {
		m_createInfo.magFilter = magFilter;
		return *this;
	}

	TextureSampler& TextureSampler::setAddressModeU(VkSamplerAddressMode U) {
		m_createInfo.addressModeU = U;
		return *this;
	}

	TextureSampler& TextureSampler::setAddressModeV(VkSamplerAddressMode V) {
		m_createInfo.addressModeV = V;
		return *this;
	}

	TextureSampler& TextureSampler::setAddressModeW(VkSamplerAddressMode W) {
		m_createInfo.addressModeW = W;
		return *this;
	}

//
//
//

	Pipeline::Pipeline(Device* device)
		: m_device(device)
		, m_descriptorSetLayout(VK_NULL_HANDLE)
		, m_renderPass(VK_NULL_HANDLE)
		, m_pipelineLayout(VK_NULL_HANDLE)
		, m_pipeline(VK_NULL_HANDLE)
		, m_pipelineVertexInputStateCreateInfo { VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO, nullptr, 0, 0,
		    nullptr, 0, nullptr } {

		// -------------------------------------------------------------------------
		// Rasterization state
		//
		memset(&m_rasterizationStateCreateInfo, 0, sizeof(VkPipelineRasterizationStateCreateInfo));
		m_rasterizationStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
		m_rasterizationStateCreateInfo.depthClampEnable = VK_FALSE;
		m_rasterizationStateCreateInfo.rasterizerDiscardEnable = VK_FALSE;
		m_rasterizationStateCreateInfo.polygonMode = VK_POLYGON_MODE_FILL;
		m_rasterizationStateCreateInfo.lineWidth = 1.0f;
		m_rasterizationStateCreateInfo.cullMode = VK_CULL_MODE_NONE;
		m_rasterizationStateCreateInfo.frontFace = VK_FRONT_FACE_CLOCKWISE;
		m_rasterizationStateCreateInfo.depthBiasEnable = VK_FALSE;

		// -------------------------------------------------------------------------


		// -------------------------------------------------------------------------
		// Input assembly state.
		//
		memset(&m_inputAssemblyState, 0, sizeof(VkPipelineInputAssemblyStateCreateInfo));
		m_inputAssemblyState.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
		m_inputAssemblyState.pNext = nullptr;
		m_inputAssemblyState.flags = 0;
		m_inputAssemblyState.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
		m_inputAssemblyState.primitiveRestartEnable = VK_FALSE;

		// -------------------------------------------------------------------------

//		// -------------------------------------------------------------------------
//		// Set Viewport states.
//		//
//		VkViewport viewport {};
//		viewport.x = 0.0f;
//		viewport.y = 0.0f;
//		viewport.width = m_extent2D.width;
//		viewport.height = m_extent2D.height;
//		viewport.minDepth = 0.0f;
//		viewport.maxDepth = 1.0f;
//
//		m_viewports.push_back(viewport);
//
//		VkRect2D scissor;
//		scissor.extent.width = m_extent2D.width;
//		scissor.extent.height = m_extent2D.height;
//		scissor.offset.x = 0;
//		scissor.offset.y = 0;
//
//		m_scissors.push_back(scissor);

		// -------------------------------------------------------------------------

		// -------------------------------------------------------------------------
		// Depth and stencil state
		//

		memset(&m_depthStencilState, 0, sizeof(VkPipelineDepthStencilStateCreateInfo));
		m_depthStencilState.sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
		m_depthStencilState.depthTestEnable = VK_TRUE;
		m_depthStencilState.depthWriteEnable = VK_TRUE;
		m_depthStencilState.depthCompareOp = VK_COMPARE_OP_LESS_OR_EQUAL;
		m_depthStencilState.depthBoundsTestEnable = VK_FALSE;
		m_depthStencilState.back.failOp = VK_STENCIL_OP_KEEP;
		m_depthStencilState.back.passOp = VK_STENCIL_OP_KEEP;
		m_depthStencilState.back.compareOp = VK_COMPARE_OP_ALWAYS;
		m_depthStencilState.stencilTestEnable = VK_FALSE;
		m_depthStencilState.front = m_depthStencilState.back;

		// -------------------------------------------------------------------------


		// -------------------------------------------------------------------------
		// Blending is not used in this example
		//
		memset(&m_blendAttachmentState, 0, sizeof(VkPipelineColorBlendAttachmentState));
		m_blendAttachmentState.blendEnable = VK_FALSE;
		m_blendAttachmentState.srcColorBlendFactor = VK_BLEND_FACTOR_ONE;
		m_blendAttachmentState.dstColorBlendFactor = VK_BLEND_FACTOR_ONE;
		m_blendAttachmentState.colorBlendOp = VK_BLEND_OP_ADD;
		m_blendAttachmentState.srcAlphaBlendFactor = VK_BLEND_FACTOR_ZERO;
		m_blendAttachmentState.dstAlphaBlendFactor = VK_BLEND_FACTOR_ZERO;
		m_blendAttachmentState.alphaBlendOp = VK_BLEND_OP_ADD;
		m_blendAttachmentState.colorWriteMask = 0xf;

		// -------------------------------------------------------------------------

	}

	Pipeline::Pipeline(Device* device, DescriptorSetLayout* descriptorSetLayout, RenderPass* renderPass, VkExtent2D extent2D)
		: m_device(device)
		, m_descriptorSetLayout(descriptorSetLayout)
		, m_renderPass(renderPass)
		, m_pipelineLayout(VK_NULL_HANDLE)
		, m_pipeline(VK_NULL_HANDLE)
		, m_pipelineVertexInputStateCreateInfo { VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO, nullptr, 0, 0,
		    nullptr, 0, nullptr
		                                       }
		, m_extent2D(extent2D) {

		// -------------------------------------------------------------------------
		// Rasterization state
		//
		memset(&m_rasterizationStateCreateInfo, 0, sizeof(VkPipelineRasterizationStateCreateInfo));
		m_rasterizationStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
		m_rasterizationStateCreateInfo.depthClampEnable = VK_FALSE;
		m_rasterizationStateCreateInfo.rasterizerDiscardEnable = VK_FALSE;
		m_rasterizationStateCreateInfo.polygonMode = VK_POLYGON_MODE_FILL;
		m_rasterizationStateCreateInfo.lineWidth = 1.0f;
		m_rasterizationStateCreateInfo.cullMode = VK_CULL_MODE_NONE;
		m_rasterizationStateCreateInfo.frontFace = VK_FRONT_FACE_CLOCKWISE;
		m_rasterizationStateCreateInfo.depthBiasEnable = VK_FALSE;

		// -------------------------------------------------------------------------


		// -------------------------------------------------------------------------
		// Input assembly state.
		//
		memset(&m_inputAssemblyState, 0, sizeof(VkPipelineInputAssemblyStateCreateInfo));
		m_inputAssemblyState.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
		m_inputAssemblyState.pNext = nullptr;
		m_inputAssemblyState.flags = 0;
		m_inputAssemblyState.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
		m_inputAssemblyState.primitiveRestartEnable = VK_FALSE;

		// -------------------------------------------------------------------------

		// -------------------------------------------------------------------------
		// Set Viewport states.
		//
		VkViewport viewport {};
		viewport.x = 0.0f;
		viewport.y = 0.0f;
		viewport.width = m_extent2D.width;
		viewport.height = m_extent2D.height;
		viewport.minDepth = 0.0f;
		viewport.maxDepth = 1.0f;

		m_viewports.push_back(viewport);

		VkRect2D scissor;
		scissor.extent.width = m_extent2D.width;
		scissor.extent.height = m_extent2D.height;
		scissor.offset.x = 0;
		scissor.offset.y = 0;

		m_scissors.push_back(scissor);

		// -------------------------------------------------------------------------

		// -------------------------------------------------------------------------
		// Depth and stencil state
		//

		memset(&m_depthStencilState, 0, sizeof(VkPipelineDepthStencilStateCreateInfo));
		m_depthStencilState.sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
		m_depthStencilState.depthTestEnable = VK_TRUE;
		m_depthStencilState.depthWriteEnable = VK_TRUE;
		m_depthStencilState.depthCompareOp = VK_COMPARE_OP_LESS_OR_EQUAL;
		m_depthStencilState.depthBoundsTestEnable = VK_FALSE;
		m_depthStencilState.back.failOp = VK_STENCIL_OP_KEEP;
		m_depthStencilState.back.passOp = VK_STENCIL_OP_KEEP;
		m_depthStencilState.back.compareOp = VK_COMPARE_OP_ALWAYS;
		m_depthStencilState.stencilTestEnable = VK_FALSE;
		m_depthStencilState.front = m_depthStencilState.back;

		// -------------------------------------------------------------------------


		// -------------------------------------------------------------------------
		// Blending is not used in this example
		//
		memset(&m_blendAttachmentState, 0, sizeof(VkPipelineColorBlendAttachmentState));
		m_blendAttachmentState.blendEnable = VK_FALSE;
		m_blendAttachmentState.srcColorBlendFactor = VK_BLEND_FACTOR_ONE;
		m_blendAttachmentState.dstColorBlendFactor = VK_BLEND_FACTOR_ONE;
		m_blendAttachmentState.colorBlendOp = VK_BLEND_OP_ADD;
		m_blendAttachmentState.srcAlphaBlendFactor = VK_BLEND_FACTOR_ZERO;
		m_blendAttachmentState.dstAlphaBlendFactor = VK_BLEND_FACTOR_ZERO;
		m_blendAttachmentState.alphaBlendOp = VK_BLEND_OP_ADD;
		m_blendAttachmentState.colorWriteMask = 0xf;

		// -------------------------------------------------------------------------

	}

	Pipeline::~Pipeline() {

	}

	VkResult Pipeline::init() {

		finalizeVertexState();

		VkPipelineLayoutCreateInfo pipelineLayoutCreateInfo {};
		pipelineLayoutCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		pipelineLayoutCreateInfo.setLayoutCount = 1;
		pipelineLayoutCreateInfo.pSetLayouts = *m_descriptorSetLayout;

		VkResult result = vkCreatePipelineLayout(*m_device, &pipelineLayoutCreateInfo, nullptr, &m_pipelineLayout);
		if(VK_SUCCESS != result) {
			std::cerr << "vkCreateDescriptorSetLayout failed: " << vkfVkResultToString(result) << std::endl;
			return result;
		}


		// -------------------------------------------------------------------------
		// Set Viewport states.
		//
		VkViewport viewport {};
		viewport.x = 0.0f;
		viewport.y = 0.0f;
		viewport.width = m_extent2D.width;
		viewport.height = m_extent2D.height;
		viewport.minDepth = 0.0f;
		viewport.maxDepth = 1.0f;

		m_viewports.push_back(viewport);

		VkRect2D scissor;
		scissor.extent.width = m_extent2D.width;
		scissor.extent.height = m_extent2D.height;
		scissor.offset.x = 0;
		scissor.offset.y = 0;

		m_scissors.push_back(scissor);


		// Color blend state
		// Describes blend modes and color masks
		VkPipelineColorBlendStateCreateInfo colorBlendState = {};
		colorBlendState.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
		colorBlendState.attachmentCount = 1;
		colorBlendState.pAttachments = &m_blendAttachmentState;


		VkPipelineViewportStateCreateInfo viewportState {};
		viewportState.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
		viewportState.viewportCount = static_cast<uint32_t>(m_viewports.size());
		viewportState.pViewports = m_viewports.data();
		viewportState.scissorCount = static_cast<uint32_t>(m_scissors.size());
		viewportState.pScissors = m_scissors.data();

		VkPipelineDynamicStateCreateInfo dynamicState {};
		std::vector<VkDynamicState> dynamicStateEnables;
		dynamicStateEnables.push_back(VK_DYNAMIC_STATE_VIEWPORT);
		dynamicStateEnables.push_back(VK_DYNAMIC_STATE_SCISSOR);
		dynamicState.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
		dynamicState.pDynamicStates = dynamicStateEnables.data();
		dynamicState.dynamicStateCount = dynamicStateEnables.size();

		// Multi sampling state
		VkPipelineMultisampleStateCreateInfo multisampleState {};
		multisampleState.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
		multisampleState.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
		multisampleState.sampleShadingEnable = VK_FALSE;
		multisampleState.minSampleShading = 0.0f;
		multisampleState.pSampleMask = nullptr;
		multisampleState.alphaToCoverageEnable = VK_FALSE;
		multisampleState.alphaToOneEnable = VK_FALSE;

		VkGraphicsPipelineCreateInfo pipelineCreateInfo {};
		pipelineCreateInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
		pipelineCreateInfo.pNext = nullptr;

		// Don't optimize this pipeline, will be created faster but not optimized.
		pipelineCreateInfo.flags = VK_PIPELINE_CREATE_DISABLE_OPTIMIZATION_BIT;

		// Set shader stages.
		pipelineCreateInfo.stageCount = m_shaderStages.size();
		pipelineCreateInfo.pStages = m_shaderStages.data();

		// Set vertex input state so the pipeline has access to the vertex data.
		if(m_pipelineVertexInputStateCreateInfo.vertexBindingDescriptionCount > 0) {
			pipelineCreateInfo.pVertexInputState = &m_pipelineVertexInputStateCreateInfo;
		}

		pipelineCreateInfo.pInputAssemblyState = &m_inputAssemblyState;
		pipelineCreateInfo.pTessellationState = nullptr;
		pipelineCreateInfo.pViewportState = &viewportState;
		pipelineCreateInfo.pRasterizationState = &m_rasterizationStateCreateInfo;
		pipelineCreateInfo.pMultisampleState = &multisampleState;
		pipelineCreateInfo.pDepthStencilState = &m_depthStencilState;
		pipelineCreateInfo.pColorBlendState = &colorBlendState;
		pipelineCreateInfo.pDynamicState = &dynamicState;
		pipelineCreateInfo.layout = m_pipelineLayout;
		pipelineCreateInfo.renderPass = (m_renderPass) ? *m_renderPass : m_nativeRenderPass;
		pipelineCreateInfo.subpass = 0;
		pipelineCreateInfo.basePipelineHandle = VK_NULL_HANDLE;
		pipelineCreateInfo.basePipelineIndex = 0;

		result = vkCreateGraphicsPipelines(*m_device, VK_NULL_HANDLE, 1, &pipelineCreateInfo, nullptr, &m_pipeline);
		if(VK_SUCCESS != result) {
			std::cerr << "vkCreateDescriptorSetLayout failed: " << vkfVkResultToString(result) << std::endl;
		}
		return result;
	}

	VkResult Pipeline::init(DescriptorSetLayout* descriptorSetLayout, RenderPass* renderPass, VkExtent2D extent2D) {
		m_descriptorSetLayout = descriptorSetLayout;
		m_renderPass = renderPass;
		m_nativeRenderPass = VK_NULL_HANDLE;
		m_extent2D = extent2D;
		return init();
	}

	VkResult Pipeline::init(DescriptorSetLayout* descriptorSetLayout, VkRenderPass renderPass, VkExtent2D extent2D) {
		m_descriptorSetLayout = descriptorSetLayout;
		m_renderPass = nullptr;
		m_nativeRenderPass = renderPass;
		m_extent2D = extent2D;
		return init();
	}

	void Pipeline::destroy() {
		if(VK_NULL_HANDLE != m_pipelineLayout) {
			vkDestroyPipelineLayout(*m_device, m_pipelineLayout, nullptr);
			m_pipelineLayout = VK_NULL_HANDLE;
		}
		if(VK_NULL_HANDLE != m_pipeline) {
			vkDestroyPipeline(*m_device, m_pipeline, nullptr);
			m_pipeline = VK_NULL_HANDLE;
		}
	}

	void Pipeline::addVertexState(VertexBuffer* vertexBuffer) {

		VkVertexInputBindingDescription vertexInputBindingDescription {};

		vertexInputBindingDescription.binding = vertexBuffer->getBindingID();
		vertexInputBindingDescription.stride = vertexBuffer->getStride();
		vertexInputBindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

		m_vertexInputBindingDescriptions.push_back(vertexInputBindingDescription);

		VkfVertexInputAttributeDescription* attributeDescription = (VkfVertexInputAttributeDescription*)vertexBuffer->getVkfHandle()->pNext;
		if(attributeDescription->sType == VKF_S_VERTEX_BUFFER_BINDING_INFO) {
			for(uint32_t i = 0; i < attributeDescription->descriptionCount; i++) {
				m_vertexInputAttributeDescriptions.push_back(attributeDescription->descriptions[i]);
			}
		}
	}

	void Pipeline::finalizeVertexState() {
		m_pipelineVertexInputStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
		m_pipelineVertexInputStateCreateInfo.pNext = nullptr;
		m_pipelineVertexInputStateCreateInfo.flags = 0;
		m_pipelineVertexInputStateCreateInfo.vertexBindingDescriptionCount = static_cast<uint32_t>(m_vertexInputBindingDescriptions.size());
		m_pipelineVertexInputStateCreateInfo.pVertexBindingDescriptions = m_vertexInputBindingDescriptions.data();
		m_pipelineVertexInputStateCreateInfo.vertexAttributeDescriptionCount = static_cast<uint32_t>(m_vertexInputAttributeDescriptions.size());
		m_pipelineVertexInputStateCreateInfo.pVertexAttributeDescriptions = m_vertexInputAttributeDescriptions.data();
	}

	void Pipeline::addIndexState(IndexBuffer* indexBuffer) {

	}

	void Pipeline::addShaderModule(ShaderModule* shaderModule) {

		for(auto& info : m_shaderStages) {
			if(info.stage == shaderModule->getShaderStageFlagBits()) {
				std::cerr << "The shader stage is already set. " << std::endl;
				exit(1);
			}
		}

		VkPipelineShaderStageCreateInfo pipelineShaderStageCreateInfo;
		pipelineShaderStageCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
		pipelineShaderStageCreateInfo.pNext = nullptr;
		pipelineShaderStageCreateInfo.flags = 0;
		pipelineShaderStageCreateInfo.stage = shaderModule->getShaderStageFlagBits();
		pipelineShaderStageCreateInfo.module = *shaderModule;
		// A pointer to a null-terminated UTF-8 string specifying the entry point name of the shader for this stage
		pipelineShaderStageCreateInfo.pName = shaderModule->getEntryName();
		pipelineShaderStageCreateInfo.pSpecializationInfo = nullptr;

		m_shaderStages.push_back(pipelineShaderStageCreateInfo);
	}

	Pipeline& Pipeline::setUsedTopology(VkPrimitiveTopology primitiveTopology) {
		m_inputAssemblyState.topology = primitiveTopology;
		return *this;
	}

	VkPipelineLayout Pipeline::getPipelineLayout() const {
		return m_pipelineLayout;
	}

	Pipeline& Pipeline::setCullMode(VkCullModeFlags cullModeFlags) {
		m_rasterizationStateCreateInfo.cullMode = cullModeFlags;
		return *this;
	}

	Pipeline& Pipeline::setFrontFace(VkFrontFace frontFace) {
		m_rasterizationStateCreateInfo.frontFace = frontFace;
		return *this;
	}

	Pipeline& Pipeline::setEnableDepthStencil(VkBool32 enable) {
		m_depthStencilState.depthTestEnable = enable;
		return *this;
	}

	Pipeline& Pipeline::setBlendEnable(VkBool32 enable) {
		m_blendAttachmentState.blendEnable = enable;
		return *this;
	}

	Pipeline& Pipeline::setBlendSrcColorFactor(VkBlendFactor factor) {
		m_blendAttachmentState.srcColorBlendFactor = factor;
		return *this;
	}

	Pipeline& Pipeline::setBlendDstColorFactor(VkBlendFactor factor) {
		m_blendAttachmentState.dstColorBlendFactor = factor;
		return *this;
	}

	Pipeline& Pipeline::setBlendSrcAlphaFactor(VkBlendFactor factor) {
		m_blendAttachmentState.srcAlphaBlendFactor = factor;
		return *this;
	}

	Pipeline& Pipeline::setBlendDstAlphaFactor(VkBlendFactor factor) {
		m_blendAttachmentState.dstAlphaBlendFactor = factor;
		return *this;
	}

	Pipeline& Pipeline::setBlendColorOp(VkBlendOp factor) {
		m_blendAttachmentState.colorBlendOp = factor;
		return *this;
	}

	Pipeline& Pipeline::setBlendAlphaOp(VkBlendOp factor) {
		m_blendAttachmentState.alphaBlendOp = factor;
		return *this;
	}

	Pipeline& Pipeline::setBlendColorWriteMask(VkColorComponentFlags flags) {
		m_blendAttachmentState.colorWriteMask = flags;
		return *this;
	}

}
