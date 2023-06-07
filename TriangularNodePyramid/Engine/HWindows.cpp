#include "HWindows.h"
#include <string>

void HOpenGLWindow::InitWindows()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void* HOpenGLWindow::CreateWindows(const char* Title, int x, int y)
{
	Windows = glfwCreateWindow(x, y, Title, NULL,NULL);
	glfwMakeContextCurrent(Windows);
	glfwSwapInterval(0);
	return Windows;
}

bool HOpenGLWindow::InitializeBeforeRendering()
{
	if (!ImGui_ImplGlfw_InitForOpenGL(Windows, true))
	{
		return false;
	}
	if (!ImGui_ImplOpenGL3_Init("#version 330"))
	{
		return false;
	}
	
	return true;
}

bool HOpenGLWindow::WhetherToEndableRenderingLoop()
{
	return !(bool)glfwWindowShouldClose(Windows);
}

void HOpenGLWindow::FrameInit()
{
	glClear(GL_COLOR_BUFFER_BIT);
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void HOpenGLWindow::FrameEnd()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	glfwSwapBuffers(Windows);
	glfwPollEvents();
}

const char* HOpenGLWindow::GetCode_Inculd()
{
	return "\n#include <GLFW/glfw3.h>\n#include <imgui_impl_glfw.h>\n#include <imgui_impl_opengl3.h>";
}

const char* HOpenGLWindow::GetCode_InitWindows()
{
	return "\nglfwInit();\nglfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);\nglfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);\nglfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);";
}

const char* HOpenGLWindow::GetCode_CreateWindows(const char* Title, int x, int y)
{
	return std::string("\nGLFWwindow* Windows = glfwCreateWindow(").append(std::to_string(x)).append(",").append(std::to_string(y)).append(",").append(Title).append(", NULL, NULL); \nglfwMakeContextCurrent(Windows); \nglfwSwapInterval(0); ").c_str();
}

const char* HOpenGLWindow::GetCode_InitializeBeforeRendering()
{
	return "\nImGui_ImplGlfw_InitForOpenGL(Windows, true);\nImGui_ImplOpenGL3_Init(\"#version 330\");";
}

const char* HOpenGLWindow::GetCode_FrameInit()
{
	return "\nglClear(GL_COLOR_BUFFER_BIT);\nImGui_ImplOpenGL3_NewFrame();\nImGui_ImplGlfw_NewFrame();\nImGui::NewFrame(); ";
}

const char* HOpenGLWindow::GetCode_FrameEnd()
{
	return "ImGui::Render();\nImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());\nglfwSwapBuffers(Windows);\nglfwPollEvents();";
}

