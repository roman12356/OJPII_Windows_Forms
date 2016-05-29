#include "_MDIForm.h"
//#include "_MainForm.h"


using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void mainasd(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	OJPIIWindowsForms::_MDIForm MDIForm;
	Application::Run(%MDIForm);

}