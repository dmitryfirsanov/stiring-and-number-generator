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

System::Void coursework::MyForm::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void coursework::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	textBox2->Text = "";
	int type = 0;
	int method = 0;
	int n = Convert::ToInt32(textBox1->Text->ToString());
	if (radioButton4->Checked) //METHOD 1
		method = 0;
	else //METHOD 2
		method = 1;
	if (radioButton1->Checked) // int
		type = 0;
	else if (radioButton2->Checked) // double
		type = 1;
	else if (radioButton3->Checked) // string
		type = 2;

	unitGenerator Gen(n, type, method);
	std::string result = Gen.midSquareMethodInt();
	String^ output = msclr::interop::marshal_as<String^>(result);
	textBox2->Text = output;
}

System::Void coursework::MyForm::radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void coursework::MyForm::radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void coursework::MyForm::radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void coursework::MyForm::radioButton4_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void coursework::MyForm::groupBox2_Enter(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void coursework::MyForm::radioButton5_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void coursework::MyForm::groupBox1_Enter(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
