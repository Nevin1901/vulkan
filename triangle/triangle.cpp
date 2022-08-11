#include "triangle.h"

void Triangle::run() {
    initWindow();
    initVulkan();
    mainLoop();
    cleanup();
}

void Triangle::initWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
}


void Triangle::createInstance() {
    VkApplicationInfo appInfo {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Triangle App";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "None";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo {};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    uint32_t glfwExtensionCount = 0;
    const char **glfwExtensions;

    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;

    createInfo.enabledLayerCount = 0;

    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
        throw std::runtime_error("failed to create instance");
    }

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    std::vector<VkExtensionProperties> extensions(extensionCount);

    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

    std::cout << "available extensions:\n";

    int count = sizeof(glfwExtensions) / 4;

    for (int i = 0; i < count; i++) {
        const char* glfwExtension = glfwExtensions[i];
        auto it = std::find_if(extensions.begin(), extensions.end(), [&glfwExtension](const VkExtensionProperties& e) {return *e.extensionName == *glfwExtension;});

        if (it != extensions.end()) {
            std::cout << glfwExtension << " found" << std::endl;
        }
    }

}

void Triangle::checkRequiredExtensions(std::vector<VkExtensionProperties> &extensions) {
}

void Triangle::initVulkan() {
    createInstance();
}

void Triangle::mainLoop() {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
}

void Triangle::cleanup() {
    vkDestroyInstance(instance, nullptr);
    glfwDestroyWindow(window);

    glfwTerminate();
}
