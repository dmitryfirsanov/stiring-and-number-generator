#include "MyForm.h"
#include <Windows.h>
#include "Generator.h"
#include "Methods.h"
#include "CustomEx.h"
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

/* вектор заполн€етс€ всеми возможными вариантами
методы генерируют индекс и удал€ет из вектора элемент */
std::vector <std::string> session;
std::vector <std::string> allPossibleValues;

const int numberOfSymbols = 126;
unsigned long long maxSessionSize;
unsigned long stepForDouble;
std::stringstream ss;
std::string value;

std::string firstsymbol("\".,-:;?!AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZzAaЅб¬в√гƒд≈е®Є∆ж«з»и…й кЋлћмЌнќоѕп–р—с“т”у‘ф’х÷ц„чЎшўщЏъџы№ьЁэёюя€");
std::string symbols("\".,-:;?!AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZzAaЅб¬в√гƒд≈е®Є∆ж«з»и…й кЋлћмЌнќоѕп–р—с“т”у‘ф’х÷ц„чЎшўщЏъџы№ьЁэёюя€");
bool isNewValue(std::string value) {
	for (int i = 0; i < session.size(); i++) {
		if (value == session[i]) {
			return false;
		}
	}
	return true;
}

void generateStrings(std::string str, int N) {
	if (N == 0) {
		allPossibleValues.push_back(str);
		return;
	}
	for (int i = 0; i < symbols.size(); i++) {
		char c = symbols[i];
		generateStrings(str + c, N - 1);
	}
}

// основна€ функци€ интерфейса дл€ генерации
System::Void coursework::MyForm::buttonGenerate_Click(System::Object^ sender, System::EventArgs^ e) { 
	Output->Text = "";
	buttonGenerate->Enabled = false;

	// ѕарсинг введенного числа
	int n;
	try {
		bool isParse = Int32::TryParse(inputMax->Text, n);
		if(isParse == false) {
			throw CustomEx("¬ведите max!");
		}
	}
	catch (CustomEx E) {
		MessageBox::Show(E.getMessage(), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		buttonGenerate->Enabled = true;
		return;
	}

	// ѕоиск выбранного метода
	int type = -1;
	for (int i = 0; i < groupBoxTypes->Controls->Count; i++) {
		RadioButton^ button = (RadioButton^)groupBoxTypes->Controls[i];
		if (button->Checked) {
			type = i;
			break;
		}
	}

	// ѕоиск выбранного метода
	int method = -1;
	for (int i = 0; i < groupBoxMethods->Controls->Count; i++) {
		RadioButton^ button = (RadioButton^)groupBoxMethods->Controls[i];
		if (button->Checked) {
			method = i;
			break;
		}
	}

	// ќсновоной объект класса
	Generator* object;

	switch (method) {
	case 0:
		object = &midSquareMethod(n, type);
		break;
	case 1:
		object = &ParkMillerGenerator(n, type);
		break;
	case 2:
		object = &FIPS186(n, type);
	case 3:
		object = &BBS(n, type);
		break;
	default:
		break;
	}

	int arraySize;
	std::string output = "";
	if (isArrayButton->Checked) {
		try {
			bool isParse = Int32::TryParse(inputSizeArray->Text, arraySize);
			if (isParse == false) {
				throw CustomEx("¬ведите size!");
			}
		}
		catch (CustomEx E) {
			MessageBox::Show(E.getMessage(), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			buttonGenerate->Enabled = true;
			return;
		}

		for (int i = 0; i < arraySize; i++) {
			output += object->Generate() + "\r\n";
		}
	}
	else  if (isSessionButton->Checked) {
		// если сесси€, то формировать массив всех возможный значений 
		// и забирать оттуда значение, выдава€ его пользователю
		switch (type) {
		case 0:
			maxSessionSize = n + 1;
			if (allPossibleValues.size() == 0 && session.size() == 0) {
				for (int i = 0; i < maxSessionSize; i++) {
					allPossibleValues.push_back(std::to_string(i));
				}
			}
			else if (session.size() != 0) {
				allPossibleValues.clear();
				for (int i = 0; i < maxSessionSize; i++) {
					value = std::to_string(i);
					if (isNewValue(value)) {
						allPossibleValues.push_back(value);
					}
				}
			}
			break;
		case 1:
			stepForDouble = pow(10, n);
			maxSessionSize = stepForDouble + 1;

			if (allPossibleValues.size() == 0 && session.size() == 0) {
				for (int i = 0; i < maxSessionSize; i++) {
					double buf = double(i) / stepForDouble;
					ss << std::fixed << std::setprecision(n) << buf;
					value = ss.str();
					normalizeDouble(value, n);
					allPossibleValues.push_back(value);
					ss.str("");
					ss.clear();
				}
			}
			else if (session.size() != 0 && allPossibleValues.size() == 0) {
				for (int i = 0; i < maxSessionSize; i++) {
					double buf = double(i) / stepForDouble;
					ss << std::fixed << std::setprecision(n) << buf;
					value = ss.str();
					normalizeDouble(value, n);
					if (isNewValue(value)) {
						allPossibleValues.push_back(value);
					}
					ss.str("");
					ss.clear();
				}
			}
			break;
		case 2:
			maxSessionSize = pow(numberOfSymbols, n);
			if (n > 4) {
				CustomEx E("ћаксимальное значение больше допустимого");
				MessageBox::Show(E.getMessage(), "Seession is over", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			if (firstsymbol.size() != 0) {
				std::random_device rd;
				std::default_random_engine gen(rd());
				std::uniform_int_distribution<int> uni_dist(0, firstsymbol.size() - 1);

				auto index = uni_dist(gen);
				std::string buf = "";
				generateStrings(buf + firstsymbol[index], n - 1);
				firstsymbol.erase(index, 1);
			}
			break;
		default:
			break;
		}

		if (session.size() == maxSessionSize) {
			CustomEx E("—есси€ закончена!");
			MessageBox::Show(E.getMessage(), "Seession is over", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		
		auto index = object->getRandomValue() % allPossibleValues.size();
		output = allPossibleValues[index] ;
		session.push_back(output);
		allPossibleValues.erase(allPossibleValues.begin() + index);
	}
	else {
		output = object->Generate();
	}
	Output->Text = marshal_as<String^>(output);
	buttonGenerate->Enabled = true;
}

System::Void coursework::MyForm::isArrayButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	inputSizeArray->Text = "";
	if (isArrayButton->Checked) {
		isSessionButton->Visible = false;
		sizeArray->Visible = true;
		inputSizeArray->Visible = true;
	}
	else {
		isSessionButton->Visible = true;
		sizeArray->Visible = false;
		inputSizeArray->Visible = false;	
	}
}

System::Void coursework::MyForm::isSessionButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (isSessionButton->Checked) {
		isArrayButton->Visible = false;
		buttonGenerate->Enabled = true;
		inputMax->Enabled = false;
		saveSession->Visible = true;
		loadSession->Visible = true;
		clearSession->Visible = true;
		groupBoxTypes->Enabled = false;
	}
	else {
		isArrayButton->Visible = true;
		buttonGenerate->Enabled = true;
		inputMax->Enabled = true;
		saveSession->Visible = false;
		loadSession->Visible = false;
		clearSession->Visible = false;
		groupBoxTypes->Enabled = true;
		session.clear();
		allPossibleValues.clear();
	}
}

System::Void coursework::MyForm::saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	saveFileDialog1->ShowDialog();

	try
	{
		std::string filepath = marshal_as<std::string>(saveFileDialog1->FileName);
		if (filepath == "") {
			throw CustomEx("Ќеккоретный файл!");
		}
		std::string extenstion = filepath;
		std::string data = marshal_as<std::string>(Output->Text);
		extenstion.erase(0, extenstion.rfind(".") + 1);
		if (extenstion == "txt") {
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
	catch (CustomEx E) {
		MessageBox::Show(E.getMessage(), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
}

System::Void coursework::MyForm::openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	openFileDialog1->ShowDialog();

	try {
		std::string filepath = marshal_as<std::string>(openFileDialog1->FileName);
		if (filepath == "openFileDialog1") {
			throw CustomEx("Ќекорректный файл!");
		}
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
	catch (CustomEx E) {
		MessageBox::Show(E.getMessage(), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
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

System::Void coursework::MyForm::saveSession_Click(System::Object^ sender, System::EventArgs^ e) {
	saveFileDialog1->ShowDialog();

	try
	{
		std::string filepath = marshal_as<std::string>(saveFileDialog1->FileName);
		if (filepath == "") {
			throw CustomEx("Ќекорректный файл!");
		}
		std::string extenstion = filepath;
		extenstion.erase(0, extenstion.rfind(".") + 1);
		if (extenstion == "txt") {
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
	catch (CustomEx E) {
		MessageBox::Show(E.getMessage(), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
}

System::Void coursework::MyForm::loadSession_Click(System::Object^ sender, System::EventArgs^ e) {
	Output->Text = "";
	openFileDialog1->ShowDialog();
	
	try {
		std::string filepath = marshal_as<std::string>(openFileDialog1->FileName);
		if (filepath == "openFileDialog1") {
			throw CustomEx("Ќекорректный файл!");
		}
		std::string extenstion = filepath;
		extenstion.erase(0, extenstion.rfind(".") + 1);
		session.clear();
		allPossibleValues.clear();

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

			std::string buf = "";
			for (int i = 0; i < data.size(); i++) {
				buf += data[i];
				if (data[i + 1] == '\n') {
					session.push_back(buf);
					buf.clear();
					i++;
				}
			}
		}
		buttonGenerate->Enabled = true;
	}
	catch (CustomEx E) {
		MessageBox::Show(E.getMessage(), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
}

System::Void coursework::MyForm::clearSession_Click(System::Object^ sender, System::EventArgs^ e) {
	Output->Text = "";
	buttonGenerate->Enabled = true;
	session.clear();
	allPossibleValues.clear();
	stepForDouble = 0;
}
