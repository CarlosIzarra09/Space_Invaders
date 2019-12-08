#include "Inicio.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace SpaceInvaders;
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew SpaceInvaders::Inicio());
}
