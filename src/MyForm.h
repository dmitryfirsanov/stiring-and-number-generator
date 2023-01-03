#pragma once

namespace coursework {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: 
		System::Windows::Forms::Button^ buttonGenerate;
		System::Windows::Forms::Label^ max;
		System::Windows::Forms::TextBox^ inputMax;
		System::Windows::Forms::RadioButton^ radioButtonInt;
		System::Windows::Forms::RadioButton^ radioButtonDouble;
		System::Windows::Forms::RadioButton^ radioButtonString;
		System::Windows::Forms::TextBox^ Output;
		System::Windows::Forms::GroupBox^ groupBoxTypes;
		System::Windows::Forms::GroupBox^ groupBoxMethods;
	private: System::Windows::Forms::RadioButton^ radioButtonFIPS186;

		System::Windows::Forms::RadioButton^ radioButtonBBS;
		System::Windows::Forms::CheckBox^ isArrayButton;
		System::Windows::Forms::Label^ sizeArray;
		System::Windows::Forms::TextBox^ inputSizeArray;
		System::Windows::Forms::ContextMenuStrip^ contextMenuStripForOutput;
		System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;
		System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
		System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
		System::Windows::Forms::OpenFileDialog^ openFileDialog1;
		System::Windows::Forms::ErrorProvider^ errorProvider1;
		System::Windows::Forms::RadioButton^ radioButtonMS;
		System::Windows::Forms::RadioButton^ radioButtonPM;
		System::Windows::Forms::CheckBox^ isSessionButton;


	private: System::Windows::Forms::Button^ clearSession;
	private: System::Windows::Forms::Button^ loadSession;
	private: System::Windows::Forms::Button^ saveSession;











		   System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->groupBoxMethods = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonMS = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonPM = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonFIPS186 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonBBS = (gcnew System::Windows::Forms::RadioButton());
			this->Output = (gcnew System::Windows::Forms::TextBox());
			this->contextMenuStripForOutput = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBoxTypes = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonInt = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonDouble = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonString = (gcnew System::Windows::Forms::RadioButton());
			this->buttonGenerate = (gcnew System::Windows::Forms::Button());
			this->max = (gcnew System::Windows::Forms::Label());
			this->inputMax = (gcnew System::Windows::Forms::TextBox());
			this->isArrayButton = (gcnew System::Windows::Forms::CheckBox());
			this->sizeArray = (gcnew System::Windows::Forms::Label());
			this->inputSizeArray = (gcnew System::Windows::Forms::TextBox());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->isSessionButton = (gcnew System::Windows::Forms::CheckBox());
			this->saveSession = (gcnew System::Windows::Forms::Button());
			this->loadSession = (gcnew System::Windows::Forms::Button());
			this->clearSession = (gcnew System::Windows::Forms::Button());
			this->groupBoxMethods->SuspendLayout();
			this->contextMenuStripForOutput->SuspendLayout();
			this->groupBoxTypes->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBoxMethods
			// 
			this->groupBoxMethods->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->groupBoxMethods->Controls->Add(this->radioButtonMS);
			this->groupBoxMethods->Controls->Add(this->radioButtonPM);
			this->groupBoxMethods->Controls->Add(this->radioButtonFIPS186);
			this->groupBoxMethods->Controls->Add(this->radioButtonBBS);
			this->groupBoxMethods->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->groupBoxMethods->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBoxMethods->Location = System::Drawing::Point(470, 85);
			this->groupBoxMethods->Margin = System::Windows::Forms::Padding(2);
			this->groupBoxMethods->Name = L"groupBoxMethods";
			this->groupBoxMethods->Padding = System::Windows::Forms::Padding(2);
			this->groupBoxMethods->Size = System::Drawing::Size(135, 155);
			this->groupBoxMethods->TabIndex = 17;
			this->groupBoxMethods->TabStop = false;
			this->groupBoxMethods->Text = L"Method";
			// 
			// radioButtonMS
			// 
			this->radioButtonMS->AutoSize = true;
			this->radioButtonMS->Checked = true;
			this->radioButtonMS->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButtonMS->Location = System::Drawing::Point(6, 25);
			this->radioButtonMS->Margin = System::Windows::Forms::Padding(2);
			this->radioButtonMS->Name = L"radioButtonMS";
			this->radioButtonMS->Size = System::Drawing::Size(122, 26);
			this->radioButtonMS->TabIndex = 15;
			this->radioButtonMS->TabStop = true;
			this->radioButtonMS->Text = L"Mid Square";
			this->radioButtonMS->UseVisualStyleBackColor = true;
			// 
			// radioButtonPM
			// 
			this->radioButtonPM->AutoSize = true;
			this->radioButtonPM->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButtonPM->Location = System::Drawing::Point(6, 58);
			this->radioButtonPM->Margin = System::Windows::Forms::Padding(2);
			this->radioButtonPM->Name = L"radioButtonPM";
			this->radioButtonPM->Size = System::Drawing::Size(116, 26);
			this->radioButtonPM->TabIndex = 14;
			this->radioButtonPM->Text = L"Park-Miller";
			this->radioButtonPM->UseVisualStyleBackColor = true;
			// 
			// radioButtonFIPS186
			// 
			this->radioButtonFIPS186->AutoSize = true;
			this->radioButtonFIPS186->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->radioButtonFIPS186->Location = System::Drawing::Point(6, 90);
			this->radioButtonFIPS186->Margin = System::Windows::Forms::Padding(2);
			this->radioButtonFIPS186->Name = L"radioButtonFIPS186";
			this->radioButtonFIPS186->Size = System::Drawing::Size(105, 26);
			this->radioButtonFIPS186->TabIndex = 12;
			this->radioButtonFIPS186->Text = L"FIPS 186";
			this->radioButtonFIPS186->UseVisualStyleBackColor = true;
			// 
			// radioButtonBBS
			// 
			this->radioButtonBBS->AutoSize = true;
			this->radioButtonBBS->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButtonBBS->Location = System::Drawing::Point(6, 122);
			this->radioButtonBBS->Margin = System::Windows::Forms::Padding(2);
			this->radioButtonBBS->Name = L"radioButtonBBS";
			this->radioButtonBBS->Size = System::Drawing::Size(67, 26);
			this->radioButtonBBS->TabIndex = 13;
			this->radioButtonBBS->Text = L"BBS";
			this->radioButtonBBS->UseVisualStyleBackColor = true;
			// 
			// Output
			// 
			this->Output->ContextMenuStrip = this->contextMenuStripForOutput;
			this->Output->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Output->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Output->Location = System::Drawing::Point(14, 49);
			this->Output->Margin = System::Windows::Forms::Padding(2);
			this->Output->Multiline = true;
			this->Output->Name = L"Output";
			this->Output->ReadOnly = true;
			this->Output->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->Output->Size = System::Drawing::Size(312, 287);
			this->Output->TabIndex = 15;
			this->Output->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// contextMenuStripForOutput
			// 
			this->contextMenuStripForOutput->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStripForOutput->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->saveToolStripMenuItem,
					this->openToolStripMenuItem
			});
			this->contextMenuStripForOutput->Name = L"contextMenuStripForOutput";
			this->contextMenuStripForOutput->Size = System::Drawing::Size(238, 52);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->ShortcutKeyDisplayString = L"";
			this->saveToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->saveToolStripMenuItem->Size = System::Drawing::Size(237, 24);
			this->saveToolStripMenuItem->Text = L"Сохранить как...";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveToolStripMenuItem_Click);
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(237, 24);
			this->openToolStripMenuItem->Text = L"Открыть";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// groupBoxTypes
			// 
			this->groupBoxTypes->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->groupBoxTypes->Controls->Add(this->radioButtonInt);
			this->groupBoxTypes->Controls->Add(this->radioButtonDouble);
			this->groupBoxTypes->Controls->Add(this->radioButtonString);
			this->groupBoxTypes->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->groupBoxTypes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBoxTypes->Location = System::Drawing::Point(330, 85);
			this->groupBoxTypes->Margin = System::Windows::Forms::Padding(2);
			this->groupBoxTypes->Name = L"groupBoxTypes";
			this->groupBoxTypes->Padding = System::Windows::Forms::Padding(2);
			this->groupBoxTypes->Size = System::Drawing::Size(135, 155);
			this->groupBoxTypes->TabIndex = 16;
			this->groupBoxTypes->TabStop = false;
			this->groupBoxTypes->Text = L"Type";
			// 
			// radioButtonInt
			// 
			this->radioButtonInt->AutoSize = true;
			this->radioButtonInt->Checked = true;
			this->radioButtonInt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButtonInt->Location = System::Drawing::Point(5, 26);
			this->radioButtonInt->Margin = System::Windows::Forms::Padding(2);
			this->radioButtonInt->Name = L"radioButtonInt";
			this->radioButtonInt->Size = System::Drawing::Size(53, 29);
			this->radioButtonInt->TabIndex = 12;
			this->radioButtonInt->TabStop = true;
			this->radioButtonInt->Text = L"int";
			this->radioButtonInt->UseVisualStyleBackColor = true;
			// 
			// radioButtonDouble
			// 
			this->radioButtonDouble->AutoSize = true;
			this->radioButtonDouble->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButtonDouble->Location = System::Drawing::Point(5, 55);
			this->radioButtonDouble->Margin = System::Windows::Forms::Padding(2);
			this->radioButtonDouble->Name = L"radioButtonDouble";
			this->radioButtonDouble->Size = System::Drawing::Size(92, 29);
			this->radioButtonDouble->TabIndex = 13;
			this->radioButtonDouble->TabStop = true;
			this->radioButtonDouble->Text = L"double";
			this->radioButtonDouble->UseVisualStyleBackColor = true;
			// 
			// radioButtonString
			// 
			this->radioButtonString->AutoSize = true;
			this->radioButtonString->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButtonString->Location = System::Drawing::Point(5, 88);
			this->radioButtonString->Margin = System::Windows::Forms::Padding(2);
			this->radioButtonString->Name = L"radioButtonString";
			this->radioButtonString->Size = System::Drawing::Size(80, 29);
			this->radioButtonString->TabIndex = 14;
			this->radioButtonString->TabStop = true;
			this->radioButtonString->Text = L"string";
			this->radioButtonString->UseVisualStyleBackColor = true;
			// 
			// buttonGenerate
			// 
			this->buttonGenerate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonGenerate->Location = System::Drawing::Point(14, 342);
			this->buttonGenerate->Margin = System::Windows::Forms::Padding(2);
			this->buttonGenerate->Name = L"buttonGenerate";
			this->buttonGenerate->Size = System::Drawing::Size(591, 68);
			this->buttonGenerate->TabIndex = 9;
			this->buttonGenerate->Text = L"Generate";
			this->buttonGenerate->UseVisualStyleBackColor = true;
			this->buttonGenerate->Click += gcnew System::EventHandler(this, &MyForm::buttonGenerate_Click);
			// 
			// max
			// 
			this->max->AutoSize = true;
			this->max->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->max->Location = System::Drawing::Point(368, 49);
			this->max->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->max->Name = L"max";
			this->max->Size = System::Drawing::Size(59, 25);
			this->max->TabIndex = 11;
			this->max->Text = L"max:";
			// 
			// inputMax
			// 
			this->inputMax->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->inputMax->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->inputMax->Location = System::Drawing::Point(428, 49);
			this->inputMax->Margin = System::Windows::Forms::Padding(2);
			this->inputMax->Name = L"inputMax";
			this->inputMax->Size = System::Drawing::Size(98, 27);
			this->inputMax->TabIndex = 10;
			this->inputMax->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->inputMax->TextChanged += gcnew System::EventHandler(this, &MyForm::inputMax_TextChanged);
			// 
			// isArrayButton
			// 
			this->isArrayButton->AutoSize = true;
			this->isArrayButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->isArrayButton->Location = System::Drawing::Point(350, 246);
			this->isArrayButton->Margin = System::Windows::Forms::Padding(4);
			this->isArrayButton->Name = L"isArrayButton";
			this->isArrayButton->Size = System::Drawing::Size(81, 29);
			this->isArrayButton->TabIndex = 18;
			this->isArrayButton->Text = L"Array";
			this->isArrayButton->UseVisualStyleBackColor = true;
			this->isArrayButton->CheckedChanged += gcnew System::EventHandler(this, &MyForm::isArrayButton_CheckedChanged);
			// 
			// sizeArray
			// 
			this->sizeArray->AutoSize = true;
			this->sizeArray->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->sizeArray->Location = System::Drawing::Point(423, 247);
			this->sizeArray->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->sizeArray->Name = L"sizeArray";
			this->sizeArray->Size = System::Drawing::Size(53, 25);
			this->sizeArray->TabIndex = 19;
			this->sizeArray->Text = L"size:";
			this->sizeArray->Visible = false;
			// 
			// inputSizeArray
			// 
			this->inputSizeArray->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->inputSizeArray->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->inputSizeArray->Location = System::Drawing::Point(476, 246);
			this->inputSizeArray->Margin = System::Windows::Forms::Padding(2);
			this->inputSizeArray->Name = L"inputSizeArray";
			this->inputSizeArray->Size = System::Drawing::Size(129, 27);
			this->inputSizeArray->TabIndex = 20;
			this->inputSizeArray->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->inputSizeArray->Visible = false;
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->Filter = L"txt files (*.txt)|*.txt|bin files (*.bin)|*.bin";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// errorProvider1
			// 
			this->errorProvider1->ContainerControl = this;
			// 
			// isSessionButton
			// 
			this->isSessionButton->AutoSize = true;
			this->isSessionButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->isSessionButton->Location = System::Drawing::Point(482, 246);
			this->isSessionButton->Margin = System::Windows::Forms::Padding(4);
			this->isSessionButton->Name = L"isSessionButton";
			this->isSessionButton->Size = System::Drawing::Size(105, 29);
			this->isSessionButton->TabIndex = 21;
			this->isSessionButton->Text = L"Session";
			this->isSessionButton->UseVisualStyleBackColor = true;
			this->isSessionButton->CheckedChanged += gcnew System::EventHandler(this, &MyForm::isSessionButton_CheckedChanged);
			// 
			// saveSession
			// 
			this->saveSession->Location = System::Drawing::Point(330, 245);
			this->saveSession->Name = L"saveSession";
			this->saveSession->Size = System::Drawing::Size(135, 26);
			this->saveSession->TabIndex = 22;
			this->saveSession->Text = L"Сохранить сессию";
			this->saveSession->UseVisualStyleBackColor = true;
			this->saveSession->Visible = false;
			this->saveSession->Click += gcnew System::EventHandler(this, &MyForm::saveSession_Click);
			// 
			// loadSession
			// 
			this->loadSession->Location = System::Drawing::Point(330, 278);
			this->loadSession->Name = L"loadSession";
			this->loadSession->Size = System::Drawing::Size(135, 26);
			this->loadSession->TabIndex = 23;
			this->loadSession->Text = L"Загрузить сессию\r\n";
			this->loadSession->UseVisualStyleBackColor = true;
			this->loadSession->Visible = false;
			this->loadSession->Click += gcnew System::EventHandler(this, &MyForm::loadSession_Click);
			// 
			// clearSession
			// 
			this->clearSession->Location = System::Drawing::Point(330, 310);
			this->clearSession->Name = L"clearSession";
			this->clearSession->Size = System::Drawing::Size(135, 26);
			this->clearSession->TabIndex = 24;
			this->clearSession->Text = L"Очистить сессию";
			this->clearSession->UseVisualStyleBackColor = true;
			this->clearSession->Visible = false;
			this->clearSession->Click += gcnew System::EventHandler(this, &MyForm::clearSession_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(620, 460);
			this->Controls->Add(this->clearSession);
			this->Controls->Add(this->loadSession);
			this->Controls->Add(this->saveSession);
			this->Controls->Add(this->isSessionButton);
			this->Controls->Add(this->inputSizeArray);
			this->Controls->Add(this->sizeArray);
			this->Controls->Add(this->isArrayButton);
			this->Controls->Add(this->groupBoxMethods);
			this->Controls->Add(this->Output);
			this->Controls->Add(this->groupBoxTypes);
			this->Controls->Add(this->buttonGenerate);
			this->Controls->Add(this->max);
			this->Controls->Add(this->inputMax);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->HelpButton = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Random Generator";
			this->groupBoxMethods->ResumeLayout(false);
			this->groupBoxMethods->PerformLayout();
			this->contextMenuStripForOutput->ResumeLayout(false);
			this->groupBoxTypes->ResumeLayout(false);
			this->groupBoxTypes->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void buttonGenerate_Click(System::Object^ sender, System::EventArgs^ e);

		System::Void isArrayButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void isSessionButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

		System::Void saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

		System::Void inputMax_TextChanged(System::Object^ sender, System::EventArgs^ e);		

		System::Void saveSession_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void loadSession_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void clearSession_Click(System::Object^ sender, System::EventArgs^ e);
};
}
