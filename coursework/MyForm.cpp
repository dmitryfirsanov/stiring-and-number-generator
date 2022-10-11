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

// tab Unit of generated
// button "Generate"

System::Void coursework::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox2->Text = "";

	int n = Convert::ToInt64(textBox1->Text->ToString());

	int type;
	for (int i = 0; i < groupBox1->Controls->Count; i++) {
		RadioButton^ button = (RadioButton^)groupBox1->Controls[i];
		if (button->Checked) type = i;
	}

	int method;
	for (int i = 0; i < groupBox2->Controls->Count; i++) {
		RadioButton^ button = (RadioButton^)groupBox2->Controls[i];
		if (button->Checked) method = i;
	}

	unitGenerator object(n, type, method);
	String^ output = msclr::interop::marshal_as<String^>(object.ParkMillerGenerator());
	textBox2->Text = output;
}
