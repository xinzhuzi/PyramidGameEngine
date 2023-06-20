#include <imgui.h>
#include "EditorFlag.h"
#include "EditorWidgetData.h"

void DrawControlPanel()
{
	if (!ShowControlPanel) return;

	if (ImGui::Begin("ControlPanel", &ShowControlPanel))
	{


		ImGui::End();
	}
}