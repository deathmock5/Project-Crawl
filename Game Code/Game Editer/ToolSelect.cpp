#include "Tool Select.h"

using namespace System;
using namespace System ::Windows::Forms;

[STAThread]
void main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	GameEditer::ToolSelect form;
	Application::Run(%form);
}