#include "MyForm.h"
#include <Windows.h>
#include "Generator.h"	
#include <msclr\marshal_cppstd.h>
#include <fstream>

using namespace coursework;

[System::STAThread]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}

System::Void coursework::MyForm::buttonGenerate_Click(System::Object^ sender, System::EventArgs^ e) { 
	Output->Text = "";

	int n;

	try {
		n = Convert::ToInt64(inputMax->Text);
	}
	catch (Exception^ e) {
		MessageBox::Show("¬ведите max!", "Error Max", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

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

	String^ output = "";
	Generator object(n, type, method);

	if (ArrayOfGenerating->Checked) {
		int size;

		try {
			size = Convert::ToInt64(inputSizeArray->Text);
		}
		catch (Exception^ e) {
			MessageBox::Show("¬ведите size!", "Error Size", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		for (int i = 0; i < size; i++)
			output += msclr::interop::marshal_as<String^>(object.Generate()) + Environment::NewLine;
	}
	else {
		output = msclr::interop::marshal_as<String^>(object.Generate());
	}

	Output->Text = output;
}

System::Void coursework::MyForm::ArrayOfGenerating_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (ArrayOfGenerating->Checked) {
		sizeArray->Visible = true;
		inputSizeArray->Visible = true;
	}
	else {
		sizeArray->Visible = false;
		inputSizeArray->Visible = false;
	}
}

System::Void coursework::MyForm::txtToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Output->Text = "click txt";
}

System::Void coursework::MyForm::binToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Output->Text = "click bin";
}
