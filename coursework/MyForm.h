#pragma once

namespace coursework {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
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
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonGenerate;
	private: System::Windows::Forms::TextBox^ textBoxInputN;
	protected:

	protected:







	private: System::Windows::Forms::Label^ N;
	private: System::Windows::Forms::RadioButton^ radioButtonInt;
	private: System::Windows::Forms::RadioButton^ radioButtonDouble;
	private: System::Windows::Forms::RadioButton^ radioButtonString;




	private: System::Windows::Forms::TextBox^ textBoxOutput;
	private: System::Windows::Forms::GroupBox^ groupBoxTypes;



	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::GroupBox^ groupBoxMethods;
	private: System::Windows::Forms::RadioButton^ radioButtonMS;
	private: System::Windows::Forms::RadioButton^ radioButtonPM;














	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->groupBoxMethods = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonMS = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonPM = (gcnew System::Windows::Forms::RadioButton());
			this->textBoxOutput = (gcnew System::Windows::Forms::TextBox());
			this->groupBoxTypes = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonInt = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonDouble = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonString = (gcnew System::Windows::Forms::RadioButton());
			this->buttonGenerate = (gcnew System::Windows::Forms::Button());
			this->N = (gcnew System::Windows::Forms::Label());
			this->textBoxInputN = (gcnew System::Windows::Forms::TextBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->groupBoxMethods->SuspendLayout();
			this->groupBoxTypes->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBoxMethods
			// 
			this->groupBoxMethods->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->groupBoxMethods->Controls->Add(this->radioButtonMS);
			this->groupBoxMethods->Controls->Add(this->radioButtonPM);
			this->groupBoxMethods->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->groupBoxMethods->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBoxMethods->Location = System::Drawing::Point(376, 159);
			this->groupBoxMethods->Margin = System::Windows::Forms::Padding(2);
			this->groupBoxMethods->Name = L"groupBoxMethods";
			this->groupBoxMethods->Padding = System::Windows::Forms::Padding(2);
			this->groupBoxMethods->Size = System::Drawing::Size(108, 98);
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
			this->radioButtonMS->Location = System::Drawing::Point(5, 21);
			this->radioButtonMS->Margin = System::Windows::Forms::Padding(2);
			this->radioButtonMS->Name = L"radioButtonMS";
			this->radioButtonMS->Size = System::Drawing::Size(101, 22);
			this->radioButtonMS->TabIndex = 12;
			this->radioButtonMS->TabStop = true;
			this->radioButtonMS->Text = L"Mid Square";
			this->radioButtonMS->UseVisualStyleBackColor = true;
			// 
			// radioButtonPM
			// 
			this->radioButtonPM->AutoSize = true;
			this->radioButtonPM->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButtonPM->Location = System::Drawing::Point(5, 43);
			this->radioButtonPM->Margin = System::Windows::Forms::Padding(2);
			this->radioButtonPM->Name = L"radioButtonPM";
			this->radioButtonPM->Size = System::Drawing::Size(97, 22);
			this->radioButtonPM->TabIndex = 13;
			this->radioButtonPM->TabStop = true;
			this->radioButtonPM->Text = L"Park-Miller";
			this->radioButtonPM->UseVisualStyleBackColor = true;
			// 
			// textBoxOutput
			// 
			this->textBoxOutput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxOutput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxOutput->Location = System::Drawing::Point(133, 61);
			this->textBoxOutput->Margin = System::Windows::Forms::Padding(2);
			this->textBoxOutput->Name = L"textBoxOutput";
			this->textBoxOutput->ReadOnly = true;
			this->textBoxOutput->Size = System::Drawing::Size(507, 32);
			this->textBoxOutput->TabIndex = 15;
			this->textBoxOutput->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
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
			this->groupBoxTypes->Location = System::Drawing::Point(258, 159);
			this->groupBoxTypes->Margin = System::Windows::Forms::Padding(2);
			this->groupBoxTypes->Name = L"groupBoxTypes";
			this->groupBoxTypes->Padding = System::Windows::Forms::Padding(2);
			this->groupBoxTypes->Size = System::Drawing::Size(108, 98);
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
			this->radioButtonInt->Location = System::Drawing::Point(5, 21);
			this->radioButtonInt->Margin = System::Windows::Forms::Padding(2);
			this->radioButtonInt->Name = L"radioButtonInt";
			this->radioButtonInt->Size = System::Drawing::Size(44, 24);
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
			this->radioButtonDouble->Location = System::Drawing::Point(5, 42);
			this->radioButtonDouble->Margin = System::Windows::Forms::Padding(2);
			this->radioButtonDouble->Name = L"radioButtonDouble";
			this->radioButtonDouble->Size = System::Drawing::Size(75, 24);
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
			this->radioButtonString->Location = System::Drawing::Point(5, 62);
			this->radioButtonString->Margin = System::Windows::Forms::Padding(2);
			this->radioButtonString->Name = L"radioButtonString";
			this->radioButtonString->Size = System::Drawing::Size(66, 24);
			this->radioButtonString->TabIndex = 14;
			this->radioButtonString->TabStop = true;
			this->radioButtonString->Text = L"string";
			this->radioButtonString->UseVisualStyleBackColor = true;
			// 
			// buttonGenerate
			// 
			this->buttonGenerate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonGenerate->Location = System::Drawing::Point(258, 276);
			this->buttonGenerate->Margin = System::Windows::Forms::Padding(2);
			this->buttonGenerate->Name = L"buttonGenerate";
			this->buttonGenerate->Size = System::Drawing::Size(226, 54);
			this->buttonGenerate->TabIndex = 9;
			this->buttonGenerate->Text = L"Generate";
			this->buttonGenerate->UseVisualStyleBackColor = true;
			this->buttonGenerate->Click += gcnew System::EventHandler(this, &MyForm::buttonGenerate_Click);
			// 
			// N
			// 
			this->N->AutoSize = true;
			this->N->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->N->Location = System::Drawing::Point(298, 118);
			this->N->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->N->Name = L"N";
			this->N->Size = System::Drawing::Size(31, 24);
			this->N->TabIndex = 11;
			this->N->Text = L"N:";
			// 
			// textBoxInputN
			// 
			this->textBoxInputN->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxInputN->Location = System::Drawing::Point(341, 118);
			this->textBoxInputN->Margin = System::Windows::Forms::Padding(2);
			this->textBoxInputN->Name = L"textBoxInputN";
			this->textBoxInputN->Size = System::Drawing::Size(59, 23);
			this->textBoxInputN->TabIndex = 10;
			this->textBoxInputN->Text = L"5";
			this->textBoxInputN->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(739, 442);
			this->Controls->Add(this->groupBoxMethods);
			this->Controls->Add(this->textBoxOutput);
			this->Controls->Add(this->groupBoxTypes);
			this->Controls->Add(this->buttonGenerate);
			this->Controls->Add(this->N);
			this->Controls->Add(this->textBoxInputN);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->groupBoxMethods->ResumeLayout(false);
			this->groupBoxMethods->PerformLayout();
			this->groupBoxTypes->ResumeLayout(false);
			this->groupBoxTypes->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void buttonGenerate_Click(System::Object^ sender, System::EventArgs^ e);
};
}
