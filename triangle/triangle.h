#define GLFW_INCLUDE_VULKAN
#include <iostream>
#include <GLFW/glfw3.h>
#include <vector>
#include <algorithm>
#include <cstring>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

const std::vector<const char*> validationLayers = {
    "VK_LAYER_KHRONOS_validation"
};

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif

class Triangle {
    public:
        void run();
    
    private:
        GLFWwindow *window;
        VkInstance instance;

        std::vector<const char*> getRequiredExtensions();
        bool checkValidationLayerSupport();
        void checkRequiredExtensions(std::vector<VkExtensionProperties> &extensions);
        void createInstance();
        void initVulkan();
        void initWindow();
        void mainLoop();
        void cleanup();
};
