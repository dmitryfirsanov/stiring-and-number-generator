#include "MyForm.h"
#include <Windows.h>
#include "Generator.h"
#include "midSquareMethod.h"
#include "ParkMillerGenerator.h"
#include "BBS.h"
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include <vector>

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

std::vector <std::string> session;
std::string buf;

bool isNewValue(std::string value) {
	for (int i = 0; i < session.size(); i++) {
		if (value == session[i]) {
			return false;
		}
	}

	return true;
}



System::Void coursework::MyForm::buttonGenerate_Click(System::Object^ sender, System::EventArgs^ e) { 
	Output->Text = "";
	buttonGenerate->Enabled = false;

	int n;

	try {
		n = Convert::ToInt32(inputMax->Text);
	}
	catch (Exception^) {
		MessageBox::Show("������� max!", "Error Max", MessageBoxButtons::OK, MessageBoxIcon::Error);
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

	int arraySize;
	if (isArrayButton->Checked) {

		try {
			arraySize = Convert::ToInt32(inputSizeArray->Text);
		}
		catch (Exception^) {
			MessageBox::Show("������� size!", "Error Size", MessageBoxButtons::OK, MessageBoxIcon::Error);
			buttonGenerate->Enabled = true;
			return;
		}

		for (int i = 0; i < arraySize; i++) {
			buf = object->Generate();
			/*if (isSessionButton->Checked) {
				if (session.size() >= n + 1) {
					MessageBox::Show("������ ���������!", "Seession is over", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
				if (n < arraySize - 1) {
					MessageBox::Show("!", "Seession is over", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
				while (!isNewValue(buf)) {
					buf = object->Generate();
				}
				session.push_back(buf);
				
			}*/
			
			output += marshal_as<String^>(buf) + Environment::NewLine;
		}
	}
	else {
		buf = object->Generate();
		if (isSessionButton->Checked) {
			if (session.size() >= n + 1) {
				MessageBox::Show("������ ���������!", "Seession is over", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			while (!isNewValue(buf)) {
				buf = object->Generate();
			}
			session.push_back(buf);
		}

		output = marshal_as<String^>(buf);
	}

	if (isSessionButton->Checked) {
		//std::string filepath = ".\\cache.txt";
		//std::ofstream fSession;
		//fSession.open(filepath, std::ios::app);
		//fSession << marshal_as<std::string>(output);
		//fSession << '\n';
		//fSession.close();
		
	}

	Output->Text = output;
	buttonGenerate->Enabled = true;
}

System::Void coursework::MyForm::isArrayButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (isArrayButton->Checked) {
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
			for (int i = 0; i < data.length(); i++) {
				fBin << data[i];
			}
			fBin.close();
		}
	}
	catch (Exception^) {
		MessageBox::Show("������������ ����!", "Error File", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
}

System::Void coursework::MyForm::openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	openFileDialog1->ShowDialog();
	try {
		std::string filepath = marshal_as<std::string>(openFileDialog1->FileName);
		std::string extenstion = filepath;
		extenstion.erase(0, extenstion.rfind(".") + 1);
		Output->Text = "";
		if ( extenstion == "txt") {
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
			std::ifstream iBin(filepath, std::ios::in | std::ios::binary);
			std::stringstream ss;
			ss << iBin.rdbuf();
			iBin.close();

			std::string data = ss.str();
			Output->Text = marshal_as<String^>(data);
			
				
		}
	}
	catch (Exception^) {
		MessageBox::Show("����������� ����!", "Error File", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
}

System::Void coursework::MyForm::saveSessionToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	return System::Void();
}

System::Void coursework::MyForm::openSessionToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	return System::Void();
}

System::Void coursework::MyForm::isSessionButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (isSessionButton->Checked) {
		isArrayButton->Enabled = false;
		saveSessionToolStripMenuItem->Visible = true;
		openSessionToolStripMenuItem->Visible = true;
	}
	else {
		isArrayButton->Enabled = true;
		saveSessionToolStripMenuItem->Visible = false;
		openSessionToolStripMenuItem->Visible = false;
	}
}

System::Void coursework::MyForm::inputMax_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (isSessionButton->Checked) {
		int max;
		inputMax->Text == "" ? max = 0 : max = Convert::ToInt32(inputMax->Text);
		max >= session.size() ? buttonGenerate->Enabled = true : buttonGenerate->Enabled = false;
	}
}
