#include "MyForm.h"
#include <Windows.h>
#include "Generator.h"	
#include <msclr\marshal_cppstd.h>
using namespace coursework;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}

System::Void coursework::MyForm::buttonGenerate_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxOutput->Text = "";

	int n = Convert::ToInt64(textBoxInputN->Text->ToString());

	int type;
	for (int i = 0; i < groupBoxTypes->Controls->Count; i++) {
		RadioButton^ button = (RadioButton^)groupBoxTypes->Controls[i];
		if (button->Checked) type = i;
	}

	int method;
	for (int i = 0; i < groupBoxMethods->Controls->Count; i++) {
		RadioButton^ button = (RadioButton^)groupBoxMethods->Controls[i];
		if (button->Checked) method = i;
	}

	unitGenerator object(n, type, method);
	String^ output = msclr::interop::marshal_as<String^>(object.Generate());
	textBoxOutput->Text = output;
}
