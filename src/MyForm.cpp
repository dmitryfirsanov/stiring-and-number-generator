#include "MyForm.h"
#include <Windows.h>
#include "Generator.h"
#include "midSquareMethod.h"
#include "ParkMillerGenerator.h"
#include "BBS.h"
#include <msclr\marshal_cppstd.h>
#include <fstream>

using namespace coursework;
using namespace msclr::interop;
using namespace System::IO;

[System::STAThread]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}

System::Void coursework::MyForm::buttonGenerate_Click(System::Object^ sender, System::EventArgs^ e) { 
	Output->Text = "";
	buttonGenerate->Enabled = false;

	int n;

	try {
		n = Convert::ToInt32(inputMax->Text);
	}
	catch (Exception^) {
		MessageBox::Show("Введите max!", "Error Max", MessageBoxButtons::OK, MessageBoxIcon::Error);
		buttonGenerate->Enabled = true;
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

	Generator* object;

	switch (method) {
	case 0:
		object = &midSquareMethod(n, type);
		break;
	case 1:
		object = &ParkMillerGenerator(n, type);
		break;
	case 2:
		break;
	case 3:
		object = &BBS(n, type);
		break;
	default:
		break;
	}

	if (ArrayOfGenerating->Checked) {
		int size;

		try {
			size = Convert::ToInt32(inputSizeArray->Text);
		}
		catch (Exception^) {
			MessageBox::Show("Введите size!", "Error Size", MessageBoxButtons::OK, MessageBoxIcon::Error);
			buttonGenerate->Enabled = true;
			return;
		}

		for (int i = 0; i < size; i++)
			output += marshal_as<String^>(object->Generate()) + Environment::NewLine;
	}
	else {
		output = marshal_as<String^>(object->Generate());
	}

	Output->Text = output;
	buttonGenerate->Enabled = true;
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

	try
	{
		std::string filepath = marshal_as<std::string>(saveFileDialog1->FileName);
		std::string extenstion = filepath;
		std::string data = marshal_as<std::string>(Output->Text);
		if (extenstion.erase(0, extenstion.rfind(".") + 1) == "txt") {
			std::ofstream fText(filepath);
			fText << data;
			fText.close();
		}
		else {
			std::ofstream fBin(filepath, std::ios::out | std::ios::binary);
			fBin.write(reinterpret_cast<char*>(&data), sizeof(data));
			fBin.close();
		}
	}
	catch (Exception^) {
		MessageBox::Show("Неккоректный файл!", "Error File", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
}

System::Void coursework::MyForm::openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	openFileDialog1->ShowDialog();
	try {
		std::string filepath = marshal_as<std::string>(openFileDialog1->FileName);
		std::string extenstion = filepath;
		Output->Text = "";
		if (extenstion.erase(0, extenstion.rfind(".") + 1) == "txt") {
			std::ifstream iText(filepath);
			std::string line;
			if (iText.is_open())
			{
				while (getline(iText, line))
				{
					Output->Text += marshal_as<String^>(line) + Environment::NewLine;
				}
			}
			iText.close();
		}
		else {
			std::ifstream iBin;
			iBin.open(filepath, std::ios::in | std::ios::binary);
			iBin.seekg(0, std::ios::end);
			size_t size = iBin.tellg();
			iBin.seekg(0, std::ios::beg);

			char* buf = new char[size];
			std::string data;
			while (iBin.tellg() < size) {
				iBin.read((char*)&buf, sizeof(buf));
				Output->Text += Convert::ToString(buf);
			}

			iBin.close();
		}
	}
	catch (Exception^) {
		MessageBox::Show("Неккоректный файл!", "Error File", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
}
