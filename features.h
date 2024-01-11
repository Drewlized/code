#include "menu.h"
#include < sstream >
    #include < iostream >
    #include "cksauce.h"
#include "imguipp_v2.h"
#include "icons.h"

static ImVec4 active = ImGuiPP:: ToVec4(219, 190, 0, 255);
static ImVec4 inactive = ImGuiPP:: ToVec4(255, 255, 255, 255);
bool applymode = false;
static char operator_skin[128] = "";

void SetCamo(int Class, int Weapon, int Camo)
{
	char context[255];
	char state[255];
	int navStringCount;
    char * navStrings[16]{ };
    const char* mode = "";

    if (gameMode == 0) {
        mode = xorstr_("ddl/mp/rankedloadouts.ddl");
        CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 3);
    }
    else if (gameMode == 1) {
        mode = xorstr_("ddl/mp/wzrankedloadouts.ddl");
        CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 5);
    }

	__int64 ddl_file = Com_DDL_LoadAsset((__int64)mode);

    DDL_GetRootState((__int64)state, ddl_file);
	char buffer[200];
    memset(buffer, 0, 200);
    sprintf_s(buffer, xorstr_("squadMembers.loadouts.%i.weaponSetups.%i.camo"), Class, Weapon);
    ParseShit(buffer, (const char**)navStrings, 16, & navStringCount);
    if (DDL_MoveToPath((__int64 *) & state, (__int64 *) & state, navStringCount, (const char**)navStrings))
    {
        DDL_SetInt((__int64)state, (__int64)context, Camo);
    }

}

void setOperators(const char operators[255], int operatorid)
{
	char context[255];
	char state[255];
	int string_count;
    char * str[16]{ };
    const char* mode = "";
	char buffer[200];

    if (gameMode == 0) {
        mode = xorstr_("ddl/mp/rankedloadouts.ddl");
        CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 3);
    }
    else if (gameMode == 1) {
        mode = xorstr_("ddl/mp/wzrankedloadouts.ddl");
        CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 5);
    }

	__int64 ddl_file = Com_DDL_LoadAsset((__int64)mode);
    DDL_GetRootState((__int64)state, ddl_file);
    memset(buffer, 0, 200);
    sprintf_s(buffer, xorstr_("customizationSetup.operatorCustomization.%s.skin"), operators);
    ParseShit(buffer, (const char**)str, 32, & string_count);
    if (DDL_MoveToPath((__int64 *) & state, (__int64 *) & state, string_count, (const char**)str))
    {
        DDL_SetInt((__int64)state, (__int64)context, operatorid);
    }
}

void CopyWeapon(int Class)
{
	char context[255];
	char state[255];
	char context2[255];
	char state2[255];
	int navStringCount;
    char * navStrings[16]{ };
	int navStringCount2;
    char * navStrings2[16]{ };
    const char* mode = "";
	int wep = 0;

    if (gameMode == 0) {
        mode = xorstr_("ddl/mp/rankedloadouts.ddl");
        CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 3);
    }
    else if (gameMode == 1) {
        mode = xorstr_("ddl/mp/wzrankedloadouts.ddl");
        CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 5);
    }

	__int64 ddl_file = Com_DDL_LoadAsset((__int64)mode);

    DDL_GetRootState((__int64)state, ddl_file);
	char buffer[200];
    memset(buffer, 0, 200);
    sprintf_s(buffer, xorstr_("squadMembers.loadouts.%i.weaponSetups.0.weapon"), Class);
    ParseShit(buffer, (const char**)navStrings, 16, & navStringCount);
    if (DDL_MoveToPath((__int64 *) & state, (__int64 *) & state, navStringCount, (const char**)navStrings))
    {
        wep = DDL_GetInt((__int64 *) & state, (__int64 *) & context);

    }
    if (gameMode == 0) {
        mode = xorstr_("ddl/mp/rankedloadouts.ddl");
        CL_PlayerData_GetDDLBuffer((__int64)context2, 0, 0, 3);
    }
    else if (gameMode == 1) {
        mode = xorstr_("ddl/mp/wzrankedloadouts.ddl");
        CL_PlayerData_GetDDLBuffer((__int64)context2, 0, 0, 5);
    }
	__int64 ddl_file2 = Com_DDL_LoadAsset((__int64)mode);
    DDL_GetRootState((__int64)state2, ddl_file2);
	char buffer2[200];
    memset(buffer2, 0, 200);
    sprintf_s(buffer2, xorstr_("squadMembers.loadouts.%i.weaponSetups.1.weapon"), Class);
    ParseShit(buffer2, (const char**)navStrings2, 16, & navStringCount2);
    if (DDL_MoveToPath((__int64 *) & state2, (__int64 *) & state2, navStringCount2, (const char**)navStrings2))
    {
        DDL_SetInt2((__int64 *) & state2, (__int64 *) & context2, wep);
    }
}


void SetName(int Class, char * Name)
{
	char context[255];
	char state[255];
	int navStringCount;
    char * navStrings[16]{ };
    const char* mode = "";

    if (gameMode == 0) {
        mode = xorstr_("ddl/mp/rankedloadouts.ddl");
        CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 3);
    }
    else if (gameMode == 1) {
        mode = xorstr_("ddl/mp/wzrankedloadouts.ddl");
        CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 5);
    }

	__int64 ddl_file = Com_DDL_LoadAsset((__int64)mode);

    DDL_GetRootState((__int64)state, ddl_file);
	char buffer[200];
    memset(buffer, 0, 200);
    sprintf_s(buffer, xorstr_("squadMembers.loadouts.%i.name"), Class);
    ParseShit(buffer, (const char**)navStrings, 16, & navStringCount);
    if (DDL_MoveToPath((__int64 *) & state, (__int64 *) & state, navStringCount, (const char**)navStrings))
    {
        DDL_SetString((__int64)state, (__int64)context, Name);
    }

}


ImFont * MainCaps;
ImFont * Main;
ImFont * FMenu;
char customtag[6] = "";
char customname[255] = "";



ImVec4 player_colorVec44 = ImVec4(1.00f, 0.0f, 0.0f, 1.00f);
ImVec4 item_colorVec44 = ImVec4(0.00f, 0.0f, 1.0f, 1.00f);

namespace Tabs {
	int iTab = 3;
	bool bExit = false;
};


void ESPTab()
{
    if (Tabs:: iTab == 1)
    {
        ImGui:: Dummy(ImVec2(0.0f, 1.0f));
        ImGui:: TextDisabled("Visual Settings");
        ImGui:: Dummy(ImVec2(0.0f, 1.0f));
        (ImGui:: Checkbox("Enable Chams", & g_vars -> msettings.chams));
        if (g_vars -> msettings.chams) {
            ImGui:: SameLine();
            ImGui:: SliderInt(xorstr_("  ##LINEWIDTH"), & g_vars -> msettings.lineWidthNum, 0.0f, 1000.0f, "%1f");
        }
        if (ImGui:: IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
        {
            ImGui:: SetTooltip("ONLY ENABLE ESP INGAME, NOT IN LOBBY!");
        }
        ImGui:: Checkbox(xorstr_("Crosshair"), & g_vars -> msettings.b_crosshair);
        ImGui:: Checkbox("Fill Outlines", & g_vars -> msettings.chamFill);
        ImGui:: Checkbox("Visible Outlines", & g_vars -> msettings.visibleOutlines);
        ImGui:: Checkbox("Not Visible Outlines", & g_vars -> msettings.notVisibleOutlines);
        ImGui:: Checkbox("Loot Items Outlines", & g_vars -> msettings.lootChams);
        ImGui:: Checkbox("RGB Mode for Outlines", & g_vars -> msettings.rgbChams);
        ImGui:: Dummy(ImVec2(0.0f, 1.0f));
        ImGui:: Separator();
        ImGui:: Dummy(ImVec2(0.0f, 1.0f));
        ImGui:: TextDisabled("Visual Color Settings");
        ImGui:: Dummy(ImVec2(0.0f, 1.0f));
        ImGui:: ColorEdit3("Player Color", (float *) & player_colorVec44);
        ImGui:: ColorEdit3("Loot Item Color", (float *) & item_colorVec44);
        ImGui:: ColorEdit3("Crosshair Color", (float *) & g_vars -> msettings.crosshair_color);
        g_vars -> msettings.playerColor = ImGui:: ColorConvertFloat4ToU32(player_colorVec44);

        g_vars -> msettings.lootColor = ImGui:: ColorConvertFloat4ToU32(item_colorVec44);

    }
}

void Loadouts()
{
    if (Tabs:: iTab == 2)
    {
        ImGui:: Dummy(ImVec2(0.0f, 1.0f));
        ImGui:: TextDisabled("Choose Configuration");
        ImGui:: RadioButton(xorstr_("Multiplayer"), & gameMode, 0);
        ImGui:: SameLine();
        ImGui:: RadioButton(xorstr_("Warzone"), & gameMode, 1);
        ImGui:: SameLine();
        ImGui:: Checkbox("Apply All Mode", & applymode);
        ImGui:: Dummy(ImVec2(0.0f, 1.0f));
        ImGui:: Separator();
        ImGui:: TextDisabled("Camo Editor ");
        ImGui:: Dummy(ImVec2(0.0f, 1.0f));
        static const char* items[] = { "(MW) Gold", "(MW) Platinum", "(MW) Damascus", "(MW) Obsidian", "(CW) Gold", "(CW) Diamond", "(CW) DMU", "(CW) Golden Viper", "(CW) Plague Diamond", "(CW) Dark Aether", "(VG) Gold", "(VG) Diamond", "(VG) Atomic", "(VG) Fake Diamond", "(VG) Golden Viper", "(VG) Plague Diamond", "(VG) Dark Aether", "(CW) Cherry Blossom", "(MW) Acticamo", "(MW) Banded", "(VG) False Prospector", "(VG) Death Prospector", "(VG) Titanium Chrome", "(VG) Liquid Metal", "(VG) Skynet" };
        static const char* current_item = "Select Camo";
		static int item_current_2 = 0;
		static int class1 = 0;
		static int class2 = 1;
		static int class3 = 2;
		static int class4 = 3;
		static int class5 = 4;
		static int class6 = 5;
		static int class7 = 6;
		static int class8 = 7;
		static int class9 = 8;
		static int class10 = 9;
		static int primary = 0;
		static int secondary = 1;
        ImGui:: Combo("                   ", & item_current_2, xorstr_("Class 1\0Class 2\0Class 3\0Class 4\0Class 5\0Class 6\0Class 7\0Class 8\0Class 9\0Class 10\0\0"));
		static int item_current_3 = 0;
        ImGui:: Combo("           ", & item_current_3, xorstr_("Primary\0Secondary\0\0"));
        if (ImGui:: BeginCombo(xorstr_("##combo"), current_item))
        {
            for (int n = 0; n < IM_ARRAYSIZE(items); n++)
            {
				bool is_selected = (current_item == items[n]);
                if (ImGui:: Selectable(items[n], is_selected))
                current_item = items[n];
                if (is_selected)
                    ImGui:: SetItemDefaultFocus();
            }
            ImGui:: EndCombo();
        }
        ImGui:: SameLine();
        if (ImGui:: Button(xorstr_("Set Camo"), ImVec2(-1, 23)))
        {
            if (applymode) {
                if (current_item == "(MW) Gold")
                    SetCamo(class1, primary, 111),
                        SetCamo(class2, primary, 111),
                        SetCamo(class3, primary, 111),
                        SetCamo(class4, primary, 111),
                        SetCamo(class5, primary, 111),
                        SetCamo(class6, primary, 111),
                        SetCamo(class7, primary, 111),
                        SetCamo(class8, primary, 111),
                        SetCamo(class9, primary, 111),
                        SetCamo(class10, primary, 111),
                        SetCamo(class1, secondary, 111),
                        SetCamo(class2, secondary, 111),
                        SetCamo(class3, secondary, 111),
                        SetCamo(class4, secondary, 111),
                        SetCamo(class5, secondary, 111),
                        SetCamo(class6, secondary, 111),
                        SetCamo(class7, secondary, 111),
                        SetCamo(class8, secondary, 111),
                        SetCamo(class9, secondary, 111),
                        SetCamo(class10, secondary, 111);

                if (current_item == "(MW) Platinum")
                    SetCamo(class1, primary, 112),
                        SetCamo(class2, primary, 112),
                        SetCamo(class3, primary, 112),
                        SetCamo(class4, primary, 112),
                        SetCamo(class5, primary, 112),
                        SetCamo(class6, primary, 112),
                        SetCamo(class7, primary, 112),
                        SetCamo(class8, primary, 112),
                        SetCamo(class9, primary, 112),
                        SetCamo(class10, primary, 112),
                        SetCamo(class1, secondary, 112),
                        SetCamo(class2, secondary, 112),
                        SetCamo(class3, secondary, 112),
                        SetCamo(class4, secondary, 112),
                        SetCamo(class5, secondary, 112),
                        SetCamo(class6, secondary, 112),
                        SetCamo(class7, secondary, 112),
                        SetCamo(class8, secondary, 112),
                        SetCamo(class9, secondary, 112),
                        SetCamo(class10, secondary, 112);

                if (current_item == "(MW) Damascus")
                    SetCamo(class1, primary, 113),
                        SetCamo(class2, primary, 113),
                        SetCamo(class3, primary, 113),
                        SetCamo(class4, primary, 113),
                        SetCamo(class5, primary, 113),
                        SetCamo(class6, primary, 113),
                        SetCamo(class7, primary, 113),
                        SetCamo(class8, primary, 113),
                        SetCamo(class9, primary, 113),
                        SetCamo(class10, primary, 113),
                        SetCamo(class1, secondary, 113),
                        SetCamo(class2, secondary, 113),
                        SetCamo(class3, secondary, 113),
                        SetCamo(class4, secondary, 113),
                        SetCamo(class5, secondary, 113),
                        SetCamo(class6, secondary, 113),
                        SetCamo(class7, secondary, 113),
                        SetCamo(class8, secondary, 113),
                        SetCamo(class9, secondary, 113),
                        SetCamo(class10, secondary, 113);

                if (current_item == "(MW) Obsidian")
                    SetCamo(class1, primary, 114),
                        SetCamo(class2, primary, 114),
                        SetCamo(class3, primary, 114),
                        SetCamo(class4, primary, 114),
                        SetCamo(class5, primary, 114),
                        SetCamo(class6, primary, 114),
                        SetCamo(class7, primary, 114),
                        SetCamo(class8, primary, 114),
                        SetCamo(class9, primary, 114),
                        SetCamo(class10, primary, 114),
                        SetCamo(class1, secondary, 114),
                        SetCamo(class2, secondary, 114),
                        SetCamo(class3, secondary, 114),
                        SetCamo(class4, secondary, 114),
                        SetCamo(class5, secondary, 114),
                        SetCamo(class6, secondary, 114),
                        SetCamo(class7, secondary, 114),
                        SetCamo(class8, secondary, 114),
                        SetCamo(class9, secondary, 114),
                        SetCamo(class10, secondary, 114);

                if (current_item == "(CW) Gold")
                    SetCamo(class1, primary, 133),
                        SetCamo(class2, primary, 133),
                        SetCamo(class3, primary, 133),
                        SetCamo(class4, primary, 133),
                        SetCamo(class5, primary, 133),
                        SetCamo(class6, primary, 133),
                        SetCamo(class7, primary, 133),
                        SetCamo(class8, primary, 133),
                        SetCamo(class9, primary, 133),
                        SetCamo(class10, primary, 133),
                        SetCamo(class1, secondary, 133),
                        SetCamo(class2, secondary, 133),
                        SetCamo(class3, secondary, 133),
                        SetCamo(class4, secondary, 133),
                        SetCamo(class5, secondary, 133),
                        SetCamo(class6, secondary, 133),
                        SetCamo(class7, secondary, 133),
                        SetCamo(class8, secondary, 133),
                        SetCamo(class9, secondary, 133),
                        SetCamo(class10, secondary, 133);

                if (current_item == "(CW) Diamond")
                    SetCamo(class1, primary, 134),
                        SetCamo(class2, primary, 134),
                        SetCamo(class3, primary, 134),
                        SetCamo(class4, primary, 134),
                        SetCamo(class5, primary, 134),
                        SetCamo(class6, primary, 134),
                        SetCamo(class7, primary, 134),
                        SetCamo(class8, primary, 134),
                        SetCamo(class9, primary, 134),
                        SetCamo(class10, primary, 134),
                        SetCamo(class1, secondary, 134),
                        SetCamo(class2, secondary, 134),
                        SetCamo(class3, secondary, 134),
                        SetCamo(class4, secondary, 134),
                        SetCamo(class5, secondary, 134),
                        SetCamo(class6, secondary, 134),
                        SetCamo(class7, secondary, 134),
                        SetCamo(class8, secondary, 134),
                        SetCamo(class9, secondary, 134),
                        SetCamo(class10, secondary, 134);

                if (current_item == "(CW) DMU")
                    SetCamo(class1, primary, 135),
                        SetCamo(class2, primary, 135),
                        SetCamo(class3, primary, 135),
                        SetCamo(class4, primary, 135),
                        SetCamo(class5, primary, 135),
                        SetCamo(class6, primary, 135),
                        SetCamo(class7, primary, 135),
                        SetCamo(class8, primary, 135),
                        SetCamo(class9, primary, 135),
                        SetCamo(class10, primary, 135),
                        SetCamo(class1, secondary, 135),
                        SetCamo(class2, secondary, 135),
                        SetCamo(class3, secondary, 135),
                        SetCamo(class4, secondary, 135),
                        SetCamo(class5, secondary, 135),
                        SetCamo(class6, secondary, 135),
                        SetCamo(class7, secondary, 135),
                        SetCamo(class8, secondary, 135),
                        SetCamo(class9, secondary, 135),
                        SetCamo(class10, secondary, 135);

                if (current_item == "(CW) Golden Viper")
                    SetCamo(class1, primary, 242),
                        SetCamo(class2, primary, 242),
                        SetCamo(class3, primary, 242),
                        SetCamo(class4, primary, 242),
                        SetCamo(class5, primary, 242),
                        SetCamo(class6, primary, 242),
                        SetCamo(class7, primary, 242),
                        SetCamo(class8, primary, 242),
                        SetCamo(class9, primary, 242),
                        SetCamo(class10, primary, 242),
                        SetCamo(class1, secondary, 242),
                        SetCamo(class2, secondary, 242),
                        SetCamo(class3, secondary, 242),
                        SetCamo(class4, secondary, 242),
                        SetCamo(class5, secondary, 242),
                        SetCamo(class6, secondary, 242),
                        SetCamo(class7, secondary, 242),
                        SetCamo(class8, secondary, 242),
                        SetCamo(class9, secondary, 242),
                        SetCamo(class10, secondary, 242);

                if (current_item == "(CW) Plague Diamond")
                    SetCamo(class1, primary, 243),
                        SetCamo(class2, primary, 243),
                        SetCamo(class3, primary, 243),
                        SetCamo(class4, primary, 243),
                        SetCamo(class5, primary, 243),
                        SetCamo(class6, primary, 243),
                        SetCamo(class7, primary, 243),
                        SetCamo(class8, primary, 243),
                        SetCamo(class9, primary, 243),
                        SetCamo(class10, primary, 243),
                        SetCamo(class1, secondary, 243),
                        SetCamo(class2, secondary, 243),
                        SetCamo(class3, secondary, 243),
                        SetCamo(class4, secondary, 243),
                        SetCamo(class5, secondary, 243),
                        SetCamo(class6, secondary, 243),
                        SetCamo(class7, secondary, 243),
                        SetCamo(class8, secondary, 243),
                        SetCamo(class9, secondary, 243),
                        SetCamo(class10, secondary, 243);

                if (current_item == "(CW) Dark Aether")
                    SetCamo(class1, primary, 244),
                        SetCamo(class2, primary, 244),
                        SetCamo(class3, primary, 244),
                        SetCamo(class4, primary, 244),
                        SetCamo(class5, primary, 244),
                        SetCamo(class6, primary, 244),
                        SetCamo(class7, primary, 244),
                        SetCamo(class8, primary, 244),
                        SetCamo(class9, primary, 244),
                        SetCamo(class10, primary, 244),
                        SetCamo(class1, secondary, 244),
                        SetCamo(class2, secondary, 244),
                        SetCamo(class3, secondary, 244),
                        SetCamo(class4, secondary, 244),
                        SetCamo(class5, secondary, 244),
                        SetCamo(class6, secondary, 244),
                        SetCamo(class7, secondary, 244),
                        SetCamo(class8, secondary, 244),
                        SetCamo(class9, secondary, 244),
                        SetCamo(class10, secondary, 244);

                if (current_item == "(VG) Gold")
                    SetCamo(class1, primary, 345),
                        SetCamo(class2, primary, 345),
                        SetCamo(class3, primary, 345),
                        SetCamo(class4, primary, 345),
                        SetCamo(class5, primary, 345),
                        SetCamo(class6, primary, 345),
                        SetCamo(class7, primary, 345),
                        SetCamo(class8, primary, 345),
                        SetCamo(class9, primary, 345),
                        SetCamo(class10, primary, 345),
                        SetCamo(class1, secondary, 345),
                        SetCamo(class2, secondary, 345),
                        SetCamo(class3, secondary, 345),
                        SetCamo(class4, secondary, 345),
                        SetCamo(class5, secondary, 345),
                        SetCamo(class6, secondary, 345),
                        SetCamo(class7, secondary, 345),
                        SetCamo(class8, secondary, 345),
                        SetCamo(class9, secondary, 345),
                        SetCamo(class10, secondary, 345);

                if (current_item == "(VG) Diamond")
                    SetCamo(class1, primary, 346),
                        SetCamo(class2, primary, 346),
                        SetCamo(class3, primary, 346),
                        SetCamo(class4, primary, 346),
                        SetCamo(class5, primary, 346),
                        SetCamo(class6, primary, 346),
                        SetCamo(class7, primary, 346),
                        SetCamo(class8, primary, 346),
                        SetCamo(class9, primary, 346),
                        SetCamo(class10, primary, 346),
                        SetCamo(class1, secondary, 346),
                        SetCamo(class2, secondary, 346),
                        SetCamo(class3, secondary, 346),
                        SetCamo(class4, secondary, 346),
                        SetCamo(class5, secondary, 346),
                        SetCamo(class6, secondary, 346),
                        SetCamo(class7, secondary, 346),
                        SetCamo(class8, secondary, 346),
                        SetCamo(class9, secondary, 346),
                        SetCamo(class10, secondary, 346);

                if (current_item == "(VG) Atomic")
                    SetCamo(class1, primary, 350),
                        SetCamo(class2, primary, 350),
                        SetCamo(class3, primary, 350),
                        SetCamo(class4, primary, 350),
                        SetCamo(class5, primary, 350),
                        SetCamo(class6, primary, 350),
                        SetCamo(class7, primary, 350),
                        SetCamo(class8, primary, 350),
                        SetCamo(class9, primary, 350),
                        SetCamo(class10, primary, 350),
                        SetCamo(class1, secondary, 350),
                        SetCamo(class2, secondary, 350),
                        SetCamo(class3, secondary, 350),
                        SetCamo(class4, secondary, 350),
                        SetCamo(class5, secondary, 350),
                        SetCamo(class6, secondary, 350),
                        SetCamo(class7, secondary, 350),
                        SetCamo(class8, secondary, 350),
                        SetCamo(class9, secondary, 350),
                        SetCamo(class10, secondary, 350);

                if (current_item == "(VG) Fake Diamond")
                    SetCamo(class1, primary, 349),
                        SetCamo(class2, primary, 349),
                        SetCamo(class3, primary, 349),
                        SetCamo(class4, primary, 349),
                        SetCamo(class5, primary, 349),
                        SetCamo(class6, primary, 349),
                        SetCamo(class7, primary, 349),
                        SetCamo(class8, primary, 349),
                        SetCamo(class9, primary, 349),
                        SetCamo(class10, primary, 349),
                        SetCamo(class1, secondary, 349),
                        SetCamo(class2, secondary, 349),
                        SetCamo(class3, secondary, 349),
                        SetCamo(class4, secondary, 349),
                        SetCamo(class5, secondary, 349),
                        SetCamo(class6, secondary, 349),
                        SetCamo(class7, secondary, 349),
                        SetCamo(class8, secondary, 349),
                        SetCamo(class9, secondary, 349),
                        SetCamo(class10, secondary, 349);

                if (current_item == "(VG) Golden Viper")
                    SetCamo(class1, primary, 402),
                        SetCamo(class2, primary, 402),
                        SetCamo(class3, primary, 402),
                        SetCamo(class4, primary, 402),
                        SetCamo(class5, primary, 402),
                        SetCamo(class6, primary, 402),
                        SetCamo(class7, primary, 402),
                        SetCamo(class8, primary, 402),
                        SetCamo(class9, primary, 402),
                        SetCamo(class10, primary, 402),
                        SetCamo(class1, secondary, 402),
                        SetCamo(class2, secondary, 402),
                        SetCamo(class3, secondary, 402),
                        SetCamo(class4, secondary, 402),
                        SetCamo(class5, secondary, 402),
                        SetCamo(class6, secondary, 402),
                        SetCamo(class7, secondary, 402),
                        SetCamo(class8, secondary, 402),
                        SetCamo(class9, secondary, 402),
                        SetCamo(class10, secondary, 402);

                if (current_item == "(VG) Plague Diamond")
                    SetCamo(class1, primary, 403),
                        SetCamo(class2, primary, 403),
                        SetCamo(class3, primary, 403),
                        SetCamo(class4, primary, 403),
                        SetCamo(class5, primary, 403),
                        SetCamo(class6, primary, 403),
                        SetCamo(class7, primary, 403),
                        SetCamo(class8, primary, 403),
                        SetCamo(class9, primary, 403),
                        SetCamo(class10, primary, 403),
                        SetCamo(class1, secondary, 403),
                        SetCamo(class2, secondary, 403),
                        SetCamo(class3, secondary, 403),
                        SetCamo(class4, secondary, 403),
                        SetCamo(class5, secondary, 403),
                        SetCamo(class6, secondary, 403),
                        SetCamo(class7, secondary, 403),
                        SetCamo(class8, secondary, 403),
                        SetCamo(class9, secondary, 403),
                        SetCamo(class10, secondary, 403);

                if (current_item == "(VG) Dark Aether")
                    SetCamo(class1, primary, 404),
                        SetCamo(class2, primary, 404),
                        SetCamo(class3, primary, 404),
                        SetCamo(class4, primary, 404),
                        SetCamo(class5, primary, 404),
                        SetCamo(class6, primary, 404),
                        SetCamo(class7, primary, 404),
                        SetCamo(class8, primary, 404),
                        SetCamo(class9, primary, 404),
                        SetCamo(class10, primary, 404),
                        SetCamo(class1, secondary, 404),
                        SetCamo(class2, secondary, 404),
                        SetCamo(class3, secondary, 404),
                        SetCamo(class4, secondary, 404),
                        SetCamo(class5, secondary, 404),
                        SetCamo(class6, secondary, 404),
                        SetCamo(class7, secondary, 404),
                        SetCamo(class8, secondary, 404),
                        SetCamo(class9, secondary, 404),
                        SetCamo(class10, secondary, 404);

                if (current_item == "(CW) Cherry Blossom")
                    SetCamo(class1, primary, 160),
                        SetCamo(class2, primary, 160),
                        SetCamo(class3, primary, 160),
                        SetCamo(class4, primary, 160),
                        SetCamo(class5, primary, 160),
                        SetCamo(class6, primary, 160),
                        SetCamo(class7, primary, 160),
                        SetCamo(class8, primary, 160),
                        SetCamo(class9, primary, 160),
                        SetCamo(class10, primary, 160),
                        SetCamo(class1, secondary, 160),
                        SetCamo(class2, secondary, 160),
                        SetCamo(class3, secondary, 160),
                        SetCamo(class4, secondary, 160),
                        SetCamo(class5, secondary, 160),
                        SetCamo(class6, secondary, 160),
                        SetCamo(class7, secondary, 160),
                        SetCamo(class8, secondary, 160),
                        SetCamo(class9, secondary, 160),
                        SetCamo(class10, secondary, 160);

                if (current_item == "(MW) Acticamo")
                    SetCamo(class1, primary, 2),
                        SetCamo(class2, primary, 2),
                        SetCamo(class3, primary, 2),
                        SetCamo(class4, primary, 2),
                        SetCamo(class5, primary, 2),
                        SetCamo(class6, primary, 2),
                        SetCamo(class7, primary, 2),
                        SetCamo(class8, primary, 2),
                        SetCamo(class9, primary, 2),
                        SetCamo(class10, primary, 2),
                        SetCamo(class1, secondary, 2),
                        SetCamo(class2, secondary, 2),
                        SetCamo(class3, secondary, 2),
                        SetCamo(class4, secondary, 2),
                        SetCamo(class5, secondary, 2),
                        SetCamo(class6, secondary, 2),
                        SetCamo(class7, secondary, 2),
                        SetCamo(class8, secondary, 2),
                        SetCamo(class9, secondary, 2),
                        SetCamo(class10, secondary, 2);

                if (current_item == "(MW) Banded")
                    SetCamo(class1, primary, 3),
                        SetCamo(class2, primary, 3),
                        SetCamo(class3, primary, 3),
                        SetCamo(class4, primary, 3),
                        SetCamo(class5, primary, 3),
                        SetCamo(class6, primary, 3),
                        SetCamo(class7, primary, 3),
                        SetCamo(class8, primary, 3),
                        SetCamo(class9, primary, 3),
                        SetCamo(class10, primary, 3),
                        SetCamo(class1, secondary, 3),
                        SetCamo(class2, secondary, 3),
                        SetCamo(class3, secondary, 3),
                        SetCamo(class4, secondary, 3),
                        SetCamo(class5, secondary, 3),
                        SetCamo(class6, secondary, 3),
                        SetCamo(class7, secondary, 3),
                        SetCamo(class8, secondary, 3),
                        SetCamo(class9, secondary, 3),
                        SetCamo(class10, secondary, 3);

                if (current_item == "(VG) False Prospector")
                    SetCamo(class1, primary, 509),
                        SetCamo(class2, primary, 509),
                        SetCamo(class3, primary, 509),
                        SetCamo(class4, primary, 509),
                        SetCamo(class5, primary, 509),
                        SetCamo(class6, primary, 509),
                        SetCamo(class7, primary, 509),
                        SetCamo(class8, primary, 509),
                        SetCamo(class9, primary, 509),
                        SetCamo(class10, primary, 509),
                        SetCamo(class1, secondary, 509),
                        SetCamo(class2, secondary, 509),
                        SetCamo(class3, secondary, 509),
                        SetCamo(class4, secondary, 509),
                        SetCamo(class5, secondary, 509),
                        SetCamo(class6, secondary, 509),
                        SetCamo(class7, secondary, 509),
                        SetCamo(class8, secondary, 509),
                        SetCamo(class9, secondary, 509),
                        SetCamo(class10, secondary, 509);

                if (current_item == "(VG) Death Prospector")
                    SetCamo(class1, primary, 510),
                        SetCamo(class2, primary, 510),
                        SetCamo(class3, primary, 510),
                        SetCamo(class4, primary, 510),
                        SetCamo(class5, primary, 510),
                        SetCamo(class6, primary, 510),
                        SetCamo(class7, primary, 510),
                        SetCamo(class8, primary, 510),
                        SetCamo(class9, primary, 510),
                        SetCamo(class10, primary, 510),
                        SetCamo(class1, secondary, 510),
                        SetCamo(class2, secondary, 510),
                        SetCamo(class3, secondary, 510),
                        SetCamo(class4, secondary, 510),
                        SetCamo(class5, secondary, 510),
                        SetCamo(class6, secondary, 510),
                        SetCamo(class7, secondary, 510),
                        SetCamo(class8, secondary, 510),
                        SetCamo(class9, secondary, 510),
                        SetCamo(class10, secondary, 510);

                if (current_item == "(VG) Titanium Chrome")
                    SetCamo(class1, primary, 511),
                        SetCamo(class2, primary, 511),
                        SetCamo(class3, primary, 511),
                        SetCamo(class4, primary, 511),
                        SetCamo(class5, primary, 511),
                        SetCamo(class6, primary, 511),
                        SetCamo(class7, primary, 511),
                        SetCamo(class8, primary, 511),
                        SetCamo(class9, primary, 511),
                        SetCamo(class10, primary, 511),
                        SetCamo(class1, secondary, 511),
                        SetCamo(class2, secondary, 511),
                        SetCamo(class3, secondary, 511),
                        SetCamo(class4, secondary, 511),
                        SetCamo(class5, secondary, 511),
                        SetCamo(class6, secondary, 511),
                        SetCamo(class7, secondary, 511),
                        SetCamo(class8, secondary, 511),
                        SetCamo(class9, secondary, 511),
                        SetCamo(class10, secondary, 511);

                if (current_item == "(VG) Liquid Metal")
                    SetCamo(class1, primary, 512),
                        SetCamo(class2, primary, 512),
                        SetCamo(class3, primary, 512),
                        SetCamo(class4, primary, 512),
                        SetCamo(class5, primary, 512),
                        SetCamo(class6, primary, 512),
                        SetCamo(class7, primary, 512),
                        SetCamo(class8, primary, 512),
                        SetCamo(class9, primary, 512),
                        SetCamo(class10, primary, 512),
                        SetCamo(class1, secondary, 512),
                        SetCamo(class2, secondary, 512),
                        SetCamo(class3, secondary, 512),
                        SetCamo(class4, secondary, 512),
                        SetCamo(class5, secondary, 512),
                        SetCamo(class6, secondary, 512),
                        SetCamo(class7, secondary, 512),
                        SetCamo(class8, secondary, 512),
                        SetCamo(class9, secondary, 512),
                        SetCamo(class10, secondary, 512);

                if (current_item == "(VG) Skynet")
                    SetCamo(class1, primary, 513),
                        SetCamo(class2, primary, 513),
                        SetCamo(class3, primary, 513),
                        SetCamo(class4, primary, 513),
                        SetCamo(class5, primary, 513),
                        SetCamo(class6, primary, 513),
                        SetCamo(class7, primary, 513),
                        SetCamo(class8, primary, 513),
                        SetCamo(class9, primary, 513),
                        SetCamo(class10, primary, 513),
                        SetCamo(class1, secondary, 513),
                        SetCamo(class2, secondary, 513),
                        SetCamo(class3, secondary, 513),
                        SetCamo(class4, secondary, 513),
                        SetCamo(class5, secondary, 513),
                        SetCamo(class6, secondary, 513),
                        SetCamo(class7, secondary, 513),
                        SetCamo(class8, secondary, 513),
                        SetCamo(class9, secondary, 513),
                        SetCamo(class10, secondary, 513);
            }

            if (current_item == "(MW) Gold")
                SetCamo(item_current_2, item_current_3, 111);

            if (current_item == "(MW) Platinum")
                SetCamo(item_current_2, item_current_3, 112);

            if (current_item == "(MW) Damascus")
                SetCamo(item_current_2, item_current_3, 113);

            if (current_item == "(MW) Obsidian")
                SetCamo(item_current_2, item_current_3, 114);

            if (current_item == "(CW) Gold")
                SetCamo(item_current_2, item_current_3, 133);

            if (current_item == "(CW) Diamond")
                SetCamo(item_current_2, item_current_3, 134);

            if (current_item == "(CW) DMU")
                SetCamo(item_current_2, item_current_3, 135);

            if (current_item == "(CW) Golden Viper")
                SetCamo(item_current_2, item_current_3, 242);

            if (current_item == "(CW) Plague Diamond")
                SetCamo(item_current_2, item_current_3, 243);

            if (current_item == "(CW) Dark Aether")
                SetCamo(item_current_2, item_current_3, 244);

            if (current_item == "(VG) Gold")
                SetCamo(item_current_2, item_current_3, 345);

            if (current_item == "(VG) Diamond")
                SetCamo(item_current_2, item_current_3, 346);

            if (current_item == "(VG) Atomic")
                SetCamo(item_current_2, item_current_3, 350);

            if (current_item == "(VG) Fake Diamond")
                SetCamo(item_current_2, item_current_3, 349);

            if (current_item == "(VG) Golden Viper")
                SetCamo(item_current_2, item_current_3, 402);

            if (current_item == "(VG) Plague Diamond")
                SetCamo(item_current_2, item_current_3, 403);

            if (current_item == "(VG) Dark Aether")
                SetCamo(item_current_2, item_current_3, 404);

            if (current_item == "(CW) Cherry Blossom")
                SetCamo(item_current_2, item_current_3, 160);

            if (current_item == "(MW) Acticamo")
                SetCamo(item_current_2, item_current_3, 2);

            if (current_item == "(MW) Banded")
                SetCamo(item_current_2, item_current_3, 3);

            if (current_item == "(VG) False Prospector")
                SetCamo(item_current_2, item_current_3, 509);

            if (current_item == "(VG) Death Prospector")
                SetCamo(item_current_2, item_current_3, 510);

            if (current_item == "(VG) Titanium Chrome")
                SetCamo(item_current_2, item_current_3, 511);

            if (current_item == "(VG) Liquid Metal")
                SetCamo(item_current_2, item_current_3, 512);

            if (current_item == "(VG) Skynet")
                SetCamo(item_current_2, item_current_3, 513);
        }
        ImGui:: Dummy(ImVec2(0.0f, 1.0f));
        ImGui:: Separator();
        ImGui:: TextDisabled("Class Name Editor");
        ImGui:: Dummy(ImVec2(0.0f, 1.0f));
		static int item_current_4 = 0;
        ImGui:: Combo("##Class", & item_current_4, xorstr_("Class 1\0Class 2\0Class 3\0Class 4\0Class 5\0Class 6\0Class 7\0Class 8\0Class 9\0Class 10\0\0"));
        ImGui:: InputTextWithHint(xorstr_("##InputClass"), xorstr_("Enter Class Name"), customname, 255);
        ImGui:: SameLine();
        if (ImGui:: Button(xorstr_("Set Name"), ImVec2(-1, 23)))
        {
            if (applymode) {
                SetName(item_current_4, customname);
                SetName(class2, customname);
                SetName(class3, customname);
                SetName(class4, customname);
                SetName(class5, customname);
                SetName(class6, customname);
                SetName(class7, customname);
                SetName(class8, customname);
                SetName(class9, customname);
                SetName(class10, customname);
            }

            SetName(item_current_4, customname);
        }
        ImGui:: Dummy(ImVec2(0.0f, 1.0f));
        ImGui:: Separator();
        ImGui:: Dummy(ImVec2(0.0f, 1.0f));
        ImGui:: Separator();
        ImGui:: TextDisabled("Apply Double Guns");
        ImGui:: Dummy(ImVec2(0.0f, 1.0f));
		static int item_current_6 = 0;
        ImGui:: Combo("##Classes", & item_current_6, xorstr_("Class 1\0Class 2\0Class 3\0Class 4\0Class 5\0Class 6\0Class 7\0Class 8\0Class 9\0Class 10\0\0"));
        ImGui:: SameLine();
        if (ImGui:: Button(xorstr_("Set Double"), ImVec2(-1, 23)))
        {
            if (applymode) {
                CopyWeapon(item_current_6);
                CopyWeapon(class2);
                CopyWeapon(class3);
                CopyWeapon(class4);
                CopyWeapon(class5);
                CopyWeapon(class6);
                CopyWeapon(class7);
                CopyWeapon(class8);
                CopyWeapon(class9);
                CopyWeapon(class10);
            }

            CopyWeapon(item_current_6);
        }
    }
}

{
    if (Tabs:: iTab == 3)
    {
        ImGui:: Dummy(ImVec2(0.0f, 1.0f));
        ImGui:: TextDisabled("DVAR Options");
        ImGui:: Dummy(ImVec2(0.0f, 1.0f));
        ImGui:: Checkbox(xorstr_("FOV "), & g_vars -> msettings.b_fov);
        if (g_vars -> msettings.b_fov) {
            ImGui:: SameLine();
            ImGui:: SliderFloat(xorstr_("##FOVSLIDER"), & g_vars -> msettings.f_fov, 1.0f, 2.0f, "%.1f");
            dvar_set2("NSSLSNKPN", g_vars -> msettings.f_fov);
        }

        ImGui:: Checkbox(xorstr_("No Gun "), & g_vars -> msettings.b_nogun);
        if (g_vars -> msettings.b_nogun) {
            dvar_set2("SROLTPQLK", 0);
        }
        else {
            dvar_set2("SROLTPQLK", 1);
        }
        ImGui:: Checkbox(xorstr_("No Fog "), & g_vars -> msettings.b_fog);
        if (g_vars -> msettings.b_fog) {
            dvar_set2("LTOKRMRTMM", 0);
        }
        else {
            dvar_set2("LTOKRMRTMM", 1);
        }
        ImGui:: Checkbox(xorstr_("Max Bright "), & g_vars -> msettings.b_brightmax);
        if (g_vars -> msettings.b_brightmax) {
            dvar_set2("NQKKOONQPR", 0);
            dvar_set2("MTLMSQMNTR", 0);
            dvar_set2("RNPPKQOTN", 0);
            dvar_set2("LKOLRONRNQ", 0);
            dvar_set2("LTOKRMRTMM", 0);
        }
        else {
            dvar_set2("NQKKOONQPR", 1);
            dvar_set2("MTLMSQMNTR", 1);
            dvar_set2("RNPPKQOTN", 1);
            dvar_set2("LKOLRONRNQ", 1);
            dvar_set2("LTOKRMRTMM", 1);
        }
        ImGui:: Checkbox(xorstr_("Heartcheat "), & g_vars -> msettings.b_heartcheat);
        if (g_vars -> msettings.b_heartcheat) {
            dvar_set2("NSKNMSMOLP", 2);
            dvar_set2("NLLRSSOQMQ", 10000);
        }
        else {
            dvar_set2("NSKNMSMOLP", 5);
            dvar_set2("NLLRSSOQMQ", 500);
        }
        ImGui:: Checkbox(xorstr_("Third Person "), & g_vars -> msettings.b_thirdperson);
        if (g_vars -> msettings.b_thirdperson) {
            dvar_set2("NOSLRNTRKL", 1);
        }
        else {
            dvar_set2("NOSLRNTRKL", 0);
        }
        ImGui:: Checkbox(xorstr_("Dynamic Third Person "), & g_vars -> msettings.b_dynamic3p);
        ImGui:: Checkbox(xorstr_("Profanity Name Bypass "), & g_vars -> msettings.b_profanity);
        if (g_vars -> msettings.b_profanity) {
            dvar_set2("PLTMTSLKT", 0);
        }
        ImGui:: Checkbox(xorstr_("Ownership Check Bypass "), & g_vars -> msettings.b_ownership);
        if (g_vars -> msettings.b_ownership) {
            dvar_set2("NRQQOMLOQL", 0);
            dvar_set2("RRTLRKKTT", 0);
            dvar_set2("MKQPRPLQKL", 0);
        }
        else {
            dvar_set2("NRQQOMLOQL", 1);
            dvar_set2("RRTLRKKTT", 1);
            dvar_set2("MKQPRPLQKL", 1);
        }
        ImGui:: Dummy(ImVec2(0.0f, 1.0f));
        ImGui:: Dummy(ImVec2(0.0f, 1.0f));
        ImGui:: Separator();
        ImGui:: TextDisabled("Exploits ");
        ImGui:: Dummy(ImVec2(0.0f, 1.0f));
        static const char* itemclantag[] = { "Logo IW", "Logo RVN", "Logo SHG", "Logo DW", "Logo HMS", "Logo BNOX", "Logo 3ARC", "Logo VV", "Logo TFB", "Logo KING", "Logo BLIZZARD", "Red 1W", "Red LW", "Red IW DEV", "Red RAVN", "Red RAVEN", "Red R4VEN", "Red OW", "Red BN0X", "Red 34RC", "Red ATVI" };
        static const char* current_clantag = "Select Clan Tag";
        if (ImGui:: BeginCombo("##combo4", current_clantag)) // The second parameter is the label previewed before opening the combo.
        {
            for (int n = 0; n < IM_ARRAYSIZE(itemclantag); n++)
            {
				bool is_selected4 = (current_clantag == itemclantag[n]); // You can store your selection however you want, outside or inside your objects
                if (ImGui:: Selectable(itemclantag[n], is_selected4))
                current_clantag = itemclantag[n];
                if (is_selected4)
                    ImGui:: SetItemDefaultFocus();   // You may set the initial focus when opening the combo (scrolling + for keyboard navigation support)
            }
            ImGui:: EndCombo();
        }
        ImGui:: SameLine();

        if (ImGui:: Button(xorstr_("Set Tag"), ImVec2(-1, 23))) {
            if (current_clantag == "Logo IW")
                CL_PlayerData_SetCustomClanTag("iw");
            if (current_clantag == "Logo RVN")
                CL_PlayerData_SetCustomClanTag("rvn");
            if (current_clantag == "Logo SHG")
                CL_PlayerData_SetCustomClanTag("shg");
            if (current_clantag == "Logo DW")
                CL_PlayerData_SetCustomClanTag("dw");
            if (current_clantag == "Logo HMS")
                CL_PlayerData_SetCustomClanTag("hms");
            if (current_clantag == "Logo BNOX")
                CL_PlayerData_SetCustomClanTag("bnox");
            if (current_clantag == "Logo 3ARC")
                CL_PlayerData_SetCustomClanTag("3arc");
            if (current_clantag == "Logo VV")
                CL_PlayerData_SetCustomClanTag("vv");
            if (current_clantag == "Logo TFB")
                CL_PlayerData_SetCustomClanTag("tfb");
            if (current_clantag == "Logo KING")
                CL_PlayerData_SetCustomClanTag("king");
            if (current_clantag == "Logo BLIZZARD")
                CL_PlayerData_SetCustomClanTag("bliz");
            if (current_clantag == "Red 1W")
                CL_PlayerData_SetCustomClanTag("1W");
            if (current_clantag == "Red LW")
                CL_PlayerData_SetCustomClanTag("LW");
            if (current_clantag == "Red IW DEV")
                CL_PlayerData_SetCustomClanTag("IWDev");
            if (current_clantag == "Red RAVN")
                CL_PlayerData_SetCustomClanTag("RAVN");
            if (current_clantag == "Red RAVEN")
                CL_PlayerData_SetCustomClanTag("RAVEN");
            if (current_clantag == "Red R4VEN")
                CL_PlayerData_SetCustomClanTag("R4VEN");
            if (current_clantag == "Red OW")
                CL_PlayerData_SetCustomClanTag("OW");
            if (current_clantag == "Red BN0X")
                CL_PlayerData_SetCustomClanTag("BN0X");
            if (current_clantag == "Red 34RC")
                CL_PlayerData_SetCustomClanTag("34RC");
            if (current_clantag == "Red ATVI")
                CL_PlayerData_SetCustomClanTag("ATVI");
        }
        ImGui:: InputTextWithHint(xorstr_("##KeyInput"), xorstr_("Enter Custom Tag"), customtag, 6);
        ImGui:: SameLine();
        if (ImGui:: Button(xorstr_("Set Custom"), ImVec2(-1, 23)))
        {
            CL_PlayerData_SetCustomClanTag(customtag);
        }
        ImGui:: Dummy(ImVec2(0.0f, 1.0f));
        ImGui:: Separator();
        ImGui:: Dummy(ImVec2(0.0f, 1.0f));
        ImGui:: Dummy(ImVec2(0.0f, 1.0f));
        if (ImGui:: Button(xorstr_(ICON_FA_LOCK "  Unlock All"), ImVec2(280, 26)))
        {
            thirdunlock();

            ImGui:: SameLine();
            if (ImGui:: Button(xorstr_(ICON_FA_LINK"  Reverse Camos"), ImVec2(280, 26)))
            {
                halfinchisgoat();
                vgcamos();
                cwcamos();
                //ShowToastNotificationAfterUserJoinedParty("^6Reverse Camos");
            }
            ImGui:: Dummy(ImVec2(0.0f, 1.0f));
        }
    }
    {
        void Stats()
        {
            if (Tabs:: iTab == 4)
            {

                ImGui:: Dummy(ImVec2(0.0f, 1.0f));
                ImGui:: TextDisabled("Choose Gamemode");

                ImGui:: RadioButton(xorstr_("Rebirth Stats"), & statmode, 0);
                ImGui:: SameLine();
                ImGui:: RadioButton(xorstr_("Warzone Stats"), & statmode, 1);
                ImGui:: Dummy(ImVec2(0.0f, 1.0f));
                ImGui:: Separator();
                ImGui:: Dummy(ImVec2(0.0f, 1.0f));
                if (statmode == 0) {
                    ImGui:: Dummy(ImVec2(0.0f, 1.0f));
                    ImGui:: TextDisabled(" 1. Set the Stats you want");
                    ImGui:: TextDisabled(" 2. Go into a Lobby (after 60 Seconds Pregame)");
                    ImGui:: TextDisabled(" 3. Kill yourself or get killed to make the stats apply!");
                    ImGui:: Dummy(ImVec2(0.0f, 1.0f));
                    ImGui:: Dummy(ImVec2(0.0f, 1.0f));
                    ImGui:: SliderInt("##WINS", & g_vars -> msettings.i_wins, 1, 9999999, "Wins %d");
                    ImGui:: SameLine();
                    if (ImGui:: Button(xorstr_("Set Wins"), ImVec2(-1, 23)))
                    {
						char context[255];
						char state[255];

						__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

                        CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

                        DDL_GetRootState((__int64)state, ddl_file);

                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br_rebirth");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"wins");

                        DDL_SetInt((__int64)state, (__int64)context, (unsigned int)g_vars -> msettings.i_wins);
                    }

                    ImGui:: Dummy(ImVec2(0.0f, 3.0f));
                    ImGui:: SliderInt("##TOP5", & g_vars -> msettings.i_top5, 1, 9999999, "Top 5 %d");
                    ImGui:: SameLine();
                    if (ImGui:: Button(xorstr_("Set Top5"), ImVec2(-1, 23)))
                    {
						char context[255];
						char state[255];

						__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

                        CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

                        DDL_GetRootState((__int64)state, ddl_file);

                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br_rebirth");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"topFive");
                        DDL_SetInt((__int64)state, (__int64)context, (unsigned int)g_vars -> msettings.i_top5);

                    }

                    ImGui:: Dummy(ImVec2(0.0f, 3.0f));
                    ImGui:: SliderInt("##KILLS", & g_vars -> msettings.i_kills, 1, 9999999, "Kills %d");
                    ImGui:: SameLine();
                    if (ImGui:: Button(xorstr_("Set Kills"), ImVec2(-1, 23)))
                    {
						char context[255];
						char state[255];

						__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

                        CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

                        DDL_GetRootState((__int64)state, ddl_file);

                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br_rebirth");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"kills");

                        DDL_SetInt((__int64)state, (__int64)context, (unsigned int)g_vars -> msettings.i_kills);
                    }

                    ImGui:: Dummy(ImVec2(0.0f, 3.0f));
                    ImGui:: SliderInt("##DEATHS", & g_vars -> msettings.i_deaths, 1, 9999999, "Deaths %d");
                    ImGui:: SameLine();
                    if (ImGui:: Button(xorstr_("Set Deaths"), ImVec2(-1, 23)))
                    {
						char context[255];
						char state[255];

						__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

                        CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

                        DDL_GetRootState((__int64)state, ddl_file);

                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br_rebirth");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"deaths");

                        DDL_SetInt((__int64)state, (__int64)context, (unsigned int)g_vars -> msettings.i_deaths);
                    }
                }

                if (statmode == 1) {
                    ImGui:: Dummy(ImVec2(0.0f, 1.0f));
                    ImGui:: Dummy(ImVec2(0.0f, 1.0f));
                    ImGui:: Dummy(ImVec2(0.0f, 1.0f));
                    ImGui:: SliderInt("##BRSOCRE", & g_vars -> msettings.i_score, 1, 5555555555, "Score %d");
                    ImGui:: SameLine();
                    if (ImGui:: Button(xorstr_("Set Score"), ImVec2(-1, 23)))
                    {
						char context[255];
						char state[255];

						__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

                        CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

                        DDL_GetRootState((__int64)state, ddl_file);

                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"score");

                        DDL_SetInt((__int64)state, (__int64)context, (unsigned int)g_vars -> msettings.i_score);
                    }
                    ImGui:: Dummy(ImVec2(0.0f, 3.0f));

                    ImGui:: SliderInt("##BRGAMES", & g_vars -> msettings.i_games, 1, 5555555555, "Games Played %d");
                    ImGui:: SameLine();
                    if (ImGui:: Button(xorstr_("Set Games"), ImVec2(-1, 23)))
                    {
						char context[255];
						char state[255];

						__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

                        CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

                        DDL_GetRootState((__int64)state, ddl_file);

                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"gamesPlayed");

                        DDL_SetInt((__int64)state, (__int64)context, (unsigned int)g_vars -> msettings.i_games);
                    }
                    ImGui:: Dummy(ImVec2(0.0f, 3.0f));

                    ImGui:: SliderInt("##BRTIME", & g_vars -> msettings.i_timeplayed, 1, 5555555555, "Time Played %d");
                    ImGui:: SameLine();
                    if (ImGui:: Button(xorstr_("Set Time"), ImVec2(-1, 23)))
                    {
						char context[255];
						char state[255];

						__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

                        CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

                        DDL_GetRootState((__int64)state, ddl_file);

                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"timePlayed");

                        DDL_SetInt((__int64)state, (__int64)context, (unsigned int)g_vars -> msettings.i_timeplayed);
                    }

                    ImGui:: Dummy(ImVec2(0.0f, 3.0f));
                    ImGui:: SliderInt("##BRWINS", & g_vars -> msettings.i_wins, 1, 5555555555, "Wins %d");
                    ImGui:: SameLine();
                    if (ImGui:: Button(xorstr_("Set Wins"), ImVec2(-1, 23)))
                    {
						char context[255];
						char state[255];

						__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

                        CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

                        DDL_GetRootState((__int64)state, ddl_file);

                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"wins");

                        DDL_SetInt((__int64)state, (__int64)context, (unsigned int)g_vars -> msettings.i_wins);
                    }

                    ImGui:: Dummy(ImVec2(0.0f, 3.0f));
                    ImGui:: SliderInt("##BRTOP5", & g_vars -> msettings.i_top5, 1, 5555555555, "Top 5 %d");
                    ImGui:: SameLine();
                    if (ImGui:: Button(xorstr_("Set Top5"), ImVec2(-1, 23)))
                    {
						char context[255];
						char state[255];

						__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

                        CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

                        DDL_GetRootState((__int64)state, ddl_file);

                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"topFive");
                        DDL_SetInt((__int64)state, (__int64)context, (unsigned int)g_vars -> msettings.i_top5);

                    }

                    ImGui:: Dummy(ImVec2(0.0f, 3.0f));
                    ImGui:: SliderInt("##BRTOP10", & g_vars -> msettings.i_top10, 1, 5555555555, "Top 10 %d");
                    ImGui:: SameLine();
                    if (ImGui:: Button(xorstr_("Set Top10"), ImVec2(-1, 23)))
                    {
						char context[255];
						char state[255];

						__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

                        CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

                        DDL_GetRootState((__int64)state, ddl_file);

                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"topTen");
                        DDL_SetInt((__int64)state, (__int64)context, (unsigned int)g_vars -> msettings.i_top10);

                    }

                    ImGui:: Dummy(ImVec2(0.0f, 3.0f));
                    ImGui:: SliderInt("##BRKILLS", & g_vars -> msettings.i_kills, 1, 5555555555, "Kills %d");
                    ImGui:: SameLine();
                    if (ImGui:: Button(xorstr_("Set Kills"), ImVec2(-1, 23)))
                    {
						char context[255];
						char state[255];

						__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

                        CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

                        DDL_GetRootState((__int64)state, ddl_file);

                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"kills");

                        DDL_SetInt((__int64)state, (__int64)context, (unsigned int)g_vars -> msettings.i_kills);
                    }

                    ImGui:: Dummy(ImVec2(0.0f, 3.0f));
                    ImGui:: SliderInt("##BRDEATHS", & g_vars -> msettings.i_deaths, 1, 5555555555, "Deaths %d");
                    ImGui:: SameLine();
                    if (ImGui:: Button(xorstr_("Set Deaths"), ImVec2(-1, 23)))
                    {
						char context[255];
						char state[255];

						__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

                        CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

                        DDL_GetRootState((__int64)state, ddl_file);

                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"deaths");

                        DDL_SetInt((__int64)state, (__int64)context, (unsigned int)g_vars -> msettings.i_deaths);
                    }

                    ImGui:: Dummy(ImVec2(0.0f, 3.0f));
                    ImGui:: SliderInt("##BRDOWNS", & g_vars -> msettings.i_downs, 1, 5555555555, "Downs %d");
                    ImGui:: SameLine();
                    if (ImGui:: Button(xorstr_("Set Downs"), ImVec2(-1, 23)))
                    {
						char context[255];
						char state[255];

						__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

                        CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

                        DDL_GetRootState((__int64)state, ddl_file);

                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br");
                        DDL_MoveToName((__int64)state, (__int64)state, (__int64)"downs");

                        DDL_SetInt((__int64)state, (__int64)context, (unsigned int)g_vars -> msettings.i_downs);
                    }

                }
            }
        }
    }