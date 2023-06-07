#pragma once
#include <GLFW/glfw3.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>


class BaseHWindow
{
public:
	//BaseHWindow() {
	//	glfwInit();
	//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//};
	//~BaseHWindow();
	virtual void InitWindows() { return; }
	virtual void* CreateWindows(const char* Title, int x, int y) { return NULL; }
	virtual bool InitializeBeforeRendering() { return false; }
	virtual bool WhetherToEndableRenderingLoop() { return false; }
	virtual void FrameInit() { return; }
	virtual void FrameEnd() { return; }


	virtual const char* GetCode_Inculd() { return ""; }
	virtual const char* GetCode_InitWindows() { return ""; }
	virtual const char* GetCode_CreateWindows(const char* Title, int x, int y) { return ""; }
	virtual const char* GetCode_InitializeBeforeRendering() { return ""; }
	virtual const char* GetCode_FrameInit() { return ""; }
	virtual const char* GetCode_FrameEnd() { return ""; }
private:

};


class HOpenGLWindow : public BaseHWindow
{
public:
	virtual void InitWindows() override;
	virtual void* CreateWindows(const char* Title, int x, int y)override;
	virtual void* GetWindows() { return Windows; }
	virtual bool InitializeBeforeRendering()override;
	virtual bool WhetherToEndableRenderingLoop()override;
	virtual void FrameInit()override;
	virtual void FrameEnd()override;


	virtual const char* GetCode_Inculd() override;
	virtual const char* GetCode_InitWindows()override;
	virtual const char* GetCode_CreateWindows(const char* Title, int x, int y)override;
	virtual const char* GetCode_InitializeBeforeRendering()override;
	virtual const char* GetCode_FrameInit()override;
	virtual const char* GetCode_FrameEnd()override;

private:
	GLFWwindow* Windows;
};
