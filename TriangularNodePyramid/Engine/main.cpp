#include "HWindows.h"
#include <iostream>


#include "ControlPanel.h"
#include "MainMenuBar.h"


BaseHWindow* RootHWindows;

int main()
{
	switch (0) //select windows mode
	{
	case 0:
		RootHWindows = new HOpenGLWindow;
		
	default:
		RootHWindows = new HOpenGLWindow;
		break;
	}

	RootHWindows->InitWindows();

	RootHWindows->CreateWindows("HalfPeopleStudio ImGui Editor",800, 900);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext(NULL);
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.ConfigFlags |= ImGuiViewportFlags_NoDecoration;
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
	io.ConfigFlags |= ImGuiCol_DockingEmptyBg;

	ImGui::StyleColorsDark();

	if (!RootHWindows->InitializeBeforeRendering())
	{
		std::cout << "\n InitializeBeforeRendering error ";
	}
	

	std::cout << "\n WhetherToEndableRenderingLoop " << RootHWindows->WhetherToEndableRenderingLoop();

	while (RootHWindows->WhetherToEndableRenderingLoop())
	{
		RootHWindows->FrameInit();

		ImGui::DockSpaceOverViewport();

		ImGui::ShowDemoWindow();
		
		DrawMainMenuBar();

		if (ShowControlPanel)
		{
			DrawControlPanel();
		}

		RootHWindows->FrameEnd();


		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup_current_context);
		}

	}


	return 0;
}