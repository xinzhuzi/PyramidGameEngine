#pragma once
#include <imgui.h>
#include "EditorWidgetData.h"


void (*DetailsPanelData)();

void DrawDetailsPanel()
{
	if (!ShowDetailsPanel) return;

	if (ImGui::Begin("DetailsPanel", &ShowDetailsPanel))
	{
		if (DetailsPanelData)
		{
			DetailsPanelData();
		}

		ImGui::End();
	}

}