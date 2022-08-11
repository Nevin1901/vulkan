#define GLFW_INCLUDE_VULKAN
#include <iostream>
#include <GLFW/glfw3.h>
#include <vector>
#include <algorithm>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

class Triangle {
    public:
        void run();
    
    private:
        GLFWwindow *window;
        VkInstance instance;

        void checkRequiredExtensions(std::vector<VkExtensionProperties> &extensions);
        void createInstance();
        void initVulkan();
        void initWindow();
        void mainLoop();
        void cleanup();
};
