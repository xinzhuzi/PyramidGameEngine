#pragma once


bool ShowControlPanel = false;

void DrawMainMenuBar()
{
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Save"))
			{


			}
			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Editor"))
		{
			if (ImGui::MenuItem("Save"))
			{


			}
			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Window"))
		{
			ImGui::MenuItem("ControlPanel", "ShowControlPanel", &ShowControlPanel);
			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Help"))
		{
			if (ImGui::MenuItem("Save"))
			{


			}
			ImGui::EndMenu();
		}



		ImGui::EndMainMenuBar();
	}
	
}