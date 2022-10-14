#include "MyForm.h"
#include <Windows.h>
#include "Generator.h"	
#include <msclr\marshal_cppstd.h>
#include <fstream>

using namespace coursework;
using namespace msclr::interop;

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
			output += marshal_as<String^>(object.Generate()) + Environment::NewLine;
	}
	else {
		output = marshal_as<String^>(object.Generate());
	}

	Output->Text = output;
}

System::Void coursework::MyForm::ArrayOfGenerating_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (ArrayOfGenerating->Checked) {
		sizeArray->Visible = true;
		inputSizeArray->Visible = true;
	}
	else {
		sizeArray->Visible = false;
		inputSizeArray->Visible = false;
	}
}

System::Void coursework::MyForm::saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	saveFileDialog1->ShowDialog();
	String^ filepath = saveFileDialog1->FileName;
	System::IO::File::WriteAllText(filepath, Output->Text);
}

System::Void coursework::MyForm::openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	openFileDialog1->ShowDialog();
	String^ filepath = openFileDialog1->FileName;
	array <String^>^ lines = System::IO::File::ReadAllLines(filepath);
	Output->Text = "";
	for (int i = 0; i < lines->Length; i++) {
		Output->Text += lines[i] + Environment::NewLine;
	}
}
