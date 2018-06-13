#ifndef GLFW_EXTENSIONS_H
#define GLFW_EXTENSIONS_H

#if defined(__linux__) || defined(__FreeBSD__)
#define GLFW_EXPOSE_NATIVE_X11
#define GLFW_EXPOSE_NATIVE_GLX
#elif __APPLE__
#define GLFW_EXPOSE_NATIVE_COCOA
#define GLFW_EXPOSE_NATIVE_NSGL
#elif _WIN32
#define GLFW_EXPOSE_NATIVE_WIN32
#define GLFW_EXPOSE_NATIVE_WGL
#endif

#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#ifdef __cplusplus
extern "C"
{
#endif

	inline void* glfwNativeWindowHandle(GLFWwindow* window)
	{
#if defined(__linux__) || defined(__FreeBSD__)
		return (void*)(uintptr_t)glfwGetX11Window(window);
#elif __APPLE__
		return glfwGetCocoaWindow(window);
#elif _WIN32
		return glfwGetWin32Window(window);
#endif
		return nullptr;
	}

#ifdef __cplusplus
}
#endif

#endif
