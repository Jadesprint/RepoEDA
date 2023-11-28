#include "MyForm.h"
#include <iostream>
#include <string>
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    ContactosLista::MyForm form;
    Application::Run(% form);
}
