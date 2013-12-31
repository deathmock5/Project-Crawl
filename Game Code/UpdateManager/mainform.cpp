#include "mainform.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<System::String ^> ^argv) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//MessageBox::Show(arg[0]);
	UpdateManager::mainform form;
	Application::Run(%form);
}