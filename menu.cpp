#include "features.h"
#include "icons.h"
#include "imguipp_v2.h"
#include "menu.h"

void cMenu::DrawMenu()
{
    ImGuiStyle &Style = ImGui::GetStyle();
    auto Color = Style.Colors;

    Style.WindowMinSize = ImVec2(600, 482);
    Style.WindowBorderSize = 0;

    Style.ChildRounding = 6;
    Style.FrameRounding = 5;
    Style.ScrollbarRounding = 0;
    Style.GrabRounding = 0;
    Style.PopupRounding = 0;
    Style.WindowRounding = 10;
    Style.WindowTitleAlign = ImVec2(0.5, 0.5);
    Style.ButtonTextAlign = ImVec2(0.5, 0.5);

    Color[ImGuiCol_WindowBg] = ImColor(20, 20, 20, 255);
    // Color[ImGuiCol_WindowBg] = ImColor(16, 16, 16, 255);

    Color[ImGuiCol_FrameBg] = ImColor(20, 20, 20, 255);
    Color[ImGuiCol_FrameBgActive] = ImColor(18, 17, 17, 255);
    Color[ImGuiCol_FrameBgHovered] = ImColor(18, 17, 17, 255);

    Color[ImGuiCol_Button] = ImColor(45, 10, 52, 255);
    Color[ImGuiCol_ButtonActive] = ImColor(52, 10, 60, 255);
    Color[ImGuiCol_ButtonHovered] = ImColor(64, 15, 74, 255);

    Color[ImGuiCol_Separator] = ImColor(36, 36, 36, 255);

    Color[ImGuiCol_TitleBg] = ImColor(16, 16, 16, 255);
    // Color[ImGuiCol_TitleBg] = ImColor(16, 16, 16, 255);
    Color[ImGuiCol_TitleBgActive] = ImColor(16, 16, 16, 255);

    Color[ImGuiCol_ResizeGrip] = ImColor(30, 30, 30, 255);
    Color[ImGuiCol_ResizeGripActive] = ImColor(30, 30, 30, 255);
    Color[ImGuiCol_ResizeGripHovered] = ImColor(30, 30, 30, 255);

    Color[ImGuiCol_ChildBg] = ImColor(15, 15, 15, 255);

    Color[ImGuiCol_ScrollbarBg] = ImColor(24, 24, 24, 255);
    Color[ImGuiCol_ScrollbarGrab] = ImColor(24, 24, 24, 255);

    if (ImGui::Begin("UwU", &g_vars->msettings.b_menuEnable, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar | ImGuiCond_Always))
    {
        ImGui::BeginChild("##TopBar", ImVec2(ImGui::GetContentRegionAvail().x, 40), TRUE);
        ImGui::Dummy(ImVec2(0.0f, 0.1f));
        ImGuiPP::CenterText("MW/WZ AIO TOOL", 0, 0);
        ImGui::EndChild();

        // ImGuiPP::Line(1);
        ImGui::Dummy(ImVec2(0.0f, 0.1f));

        ImGui::BeginChild("##SecondBar", ImVec2(ImGui::GetContentRegionAvail().x, 469), TRUE);
        ImGui::Dummy(ImVec2(0.0f, 0.1f));
        if (ImGui::Button(ICON_FA_STAR "  Exploits", ImVec2(136, 28)))
        {
            Tabs::iTab = 3;
        }
        ImGui::SameLine();
        if (ImGui::Button(ICON_FA_USER "  Loadouts", ImVec2(136, 28)))
        {
            Tabs::iTab = 2;
        }
        ImGui::SameLine();
        if (ImGui::Button(ICON_FA_MAGIC "  Visuals", ImVec2(136, 28)))
        {
            Tabs::iTab = 1;
        }
        ImGui::SameLine();
        if (ImGui::Button(ICON_FA_ADDRESS_BOOK "  Stat Editor", ImVec2(136, 28)))
        {
            Tabs::iTab = 4;
        }
        else if (Tabs::iTab == 2)
        {
            Loadouts();
        }
        else if (Tabs::iTab == 4)
        {
            Stats();
        }
        else if (Tabs::iTab == 1)
        {
            ESPTab();
        }

        ImGui::EndChild();
    }
    ImGui::End();
}