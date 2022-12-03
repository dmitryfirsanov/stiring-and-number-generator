#include "MyForm.h"
#include <Windows.h>
#include "Generator.h"
#include "midSquareMethod.h"
#include "ParkMillerGenerator.h"
#include "BBS.h"
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include <vector>
#include <algorithm>

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

	int arraySize;
	if (isArrayButton->Checked) {

		try {
			arraySize = Convert::ToInt32(inputSizeArray->Text);
		}
		catch (Exception^) {
			MessageBox::Show("Введите size!", "Error Size", MessageBoxButtons::OK, MessageBoxIcon::Error);
			buttonGenerate->Enabled = true;
			return;
		}

		for (int i = 0; i < arraySize; i++) {
			buf = object->Generate();
			if (type == 2) {
				for (int i = 0; i < buf.length(); i++) {
					if (buf[i] == '\"' || buf[i] == '.' || buf[i] == ',' || buf[i] == '-' || buf[i] == ':' || buf[i] == ';' || buf[i] == '?' || buf[i] == '!') {
						buf.insert(i + 1, " ");
					}
				}
			}
			output += marshal_as<String^>(buf) + Environment::NewLine;
		}
	}
	else {
		buf = object->Generate();
		if (isSessionButton->Checked) {
			unsigned long long maxSessionSize;
			int numberOfSymbols = 126;
			switch (type) {
			case 0:
				maxSessionSize = n + 1;
				break;
			case 1:
				maxSessionSize = pow(10, n) + 1;
				break;
			case 2:
				maxSessionSize = pow(numberOfSymbols, n);
				break;
			default:
				break;
			}

			if (session.size() >= maxSessionSize) {
				MessageBox::Show("Сессия закончена!", "Seession is over", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			while (!isNewValue(buf)) {
				buf = object->Generate();
			}
			if (type == 2) {
				for (int i = 0; i < buf.length(); i++) {
					if (buf[i] == '\"' || buf[i] == '.' || buf[i] == ',' || buf[i] == '-' || buf[i] == ':' || buf[i] == ';' || buf[i] == '?' || buf[i] == '!') {
						buf.insert(i + 1, " ");
					}
				}
			}
			session.push_back(buf);
		}

		output = marshal_as<String^>(buf);
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

System::Void coursework::MyForm::isSessionButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (isSessionButton->Checked) {
		isArrayButton->Enabled = false;
		isArrayButton->Checked = false;
		saveSessionToolStripMenuItem->Visible = true;
		openSessionToolStripMenuItem->Visible = true;
	}
	else {
		isArrayButton->Enabled = true;
		buttonGenerate->Enabled = true;
		saveSessionToolStripMenuItem->Visible = false;
		openSessionToolStripMenuItem->Visible = false;
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
		MessageBox::Show("Неккоректный файл!", "Error File", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
}

System::Void coursework::MyForm::saveSessionToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	saveFileDialog1->ShowDialog();

	try
	{
		std::string filepath = marshal_as<std::string>(saveFileDialog1->FileName);
		std::string extenstion = filepath;
		if (extenstion.erase(0, extenstion.rfind(".") + 1) == "txt") {
			std::ofstream fText(filepath);
			for (int i = 0; i < session.size(); i++) {
				fText << session[i];
				fText << '\n';
			}
			fText.close();
		}
		else {
			std::ofstream fBin(filepath, std::ios::out | std::ios::binary);
			for (int i = 0; i < session.size(); i++) {
				fBin << session[i];
				fBin << '\n';
			}
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
		extenstion.erase(0, extenstion.rfind(".") + 1);
		Output->Text = "";
		if (extenstion == "txt") {
			std::ifstream iText(filepath);
			std::string line;
			if (iText.is_open())
			{
				while (getline(iText, line))
				{
					std::string::iterator it = std::remove(line.begin(), line.end(), '\r');
					line.erase(it, line.end());

					if (isSessionButton->Checked) {
						session.push_back(line);
					}
					Output->Text += marshal_as<String^>(line) + Environment::NewLine;
				}
			}
			if (isSessionButton->Checked) {
				std::sort(session.begin(), session.end());
				auto last = std::unique(session.begin(), session.end());
				session.erase(last, session.end());
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
		MessageBox::Show("Некоректный файл!", "Error File", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
}

System::Void coursework::MyForm::openSessionToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	openFileDialog1->ShowDialog();

	try {
		std::string filepath = marshal_as<std::string>(openFileDialog1->FileName);
		std::string extenstion = filepath;
		extenstion.erase(0, extenstion.rfind(".") + 1);
		Output->Text = "";
		if (extenstion == "txt") {
			std::ifstream iText(filepath);
			std::string line;
			if (iText.is_open())
			{
				while (getline(iText, line))
				{
					std::string::iterator it = std::remove(line.begin(), line.end(), '\r');
					line.erase(it, line.end());
					session.push_back(line);
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
			session.clear();
			std::string buf;
			for (int i = 0; i < data.length(); i++) {
				buf += data[i];
				if (data[i + 1] == '\n') {
					session.push_back(buf);
					buf.clear();
					i++;
				}
			}
		}
	}
	catch (Exception^) {
		MessageBox::Show("Некоректный файл!", "Error File", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
}

System::Void coursework::MyForm::inputMax_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (isSessionButton->Checked) {
		int max;
		inputMax->Text == "" ? max = 0 : max = Convert::ToInt32(inputMax->Text);
		max >= session.size() ? buttonGenerate->Enabled = true : buttonGenerate->Enabled = false;
	}
}
