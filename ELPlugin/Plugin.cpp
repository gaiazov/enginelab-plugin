#include "api.h"

using namespace ELPlugin;
using namespace System;
using namespace System::Runtime::InteropServices;

extern "C" __declspec(dllexport) void GetPlugInName(char **name, unsigned int *name_size) {
	Implementation implementation;
	String^ nameCliStr = implementation.GetPlugInName();

	IntPtr nameStrPtr = Marshal::StringToHGlobalAnsi(nameCliStr);
	char* nameStr = static_cast<char*>(nameStrPtr.ToPointer());

	*name = nameStr;
	*name_size = nameCliStr->Length + 1;
}

extern "C" __declspec(dllexport) const pELVersions InitializeDockablePlugIn(const pELVersions versions, pELHost host, const pELGenericFunctionTable generic_functions) {
	return versions;
}

extern "C" __declspec(dllexport) void InitializeDockablePlugInFinished(PLUGINSTATUS status, UINT * plugin_ids, UINT * menu_ids, UINT id_count) {
}

char dll_menu[] =
"Menu {                          "
"  \"Normal PlugIn Window\"=0;   "// Option for generating a simple single instance window.
"}                               ";

extern "C" __declspec(dllexport) void GetPlugInMenuString(char **menu_string, UINT *menu_size) {
	*menu_string = dll_menu;
	*menu_size = sizeof(dll_menu);
}

extern "C" __declspec(dllexport) void HostReady(pELHost host, pELLayout layout) { }

extern "C" __declspec(dllexport) void MenuClicked(WORD menu_id) {
	ELPlugin::Implementation impl;
	impl.MenuClicked(menu_id);
}

extern "C" __declspec(dllexport) void TargetConnected(pELTarget target) {
	ELPlugin::Implementation impl;
	ELTargetWrapper^ _target = gcnew ELTargetWrapper((System::IntPtr)target);
	impl.TargetConnected(_target);
}

extern "C" __declspec(dllexport) void TargetDisconnected(pELTarget target) { }

ELControlInfo dll_controls[] = {
	{ NULL, NULL } // Host expects the last entry to be invalid.
};

extern "C" __declspec(dllexport) pELControlInfo SupportedControls() { return dll_controls; }

ELWindowInfo dll_windows[] = {
	{ NULL, NULL }
};
extern "C" __declspec(dllexport) pELWindowInfo SavableWindows() { return dll_windows; }