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
		System::Windows::Forms::RadioButton^ radioButtonMS;
		System::Windows::Forms::RadioButton^ radioButtonPM;
		System::Windows::Forms::CheckBox^ ArrayOfGenerating;
		System::Windows::Forms::Label^ sizeArray;
		System::Windows::Forms::TextBox^ inputSizeArray;
		System::Windows::Forms::ContextMenuStrip^ contextMenuStripForOutput;
		System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;


	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::ErrorProvider^ errorProvider1;
		   System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->groupBoxMethods = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonMS = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonPM = (gcnew System::Windows::Forms::RadioButton());
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
			this->ArrayOfGenerating = (gcnew System::Windows::Forms::CheckBox());
			this->sizeArray = (gcnew System::Windows::Forms::Label());
			this->inputSizeArray = (gcnew System::Windows::Forms::TextBox());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
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
			this->groupBoxMethods->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->groupBoxMethods->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBoxMethods->Location = System::Drawing::Point(376, 68);
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
			// Output
			// 
			this->Output->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Output->ContextMenuStrip = this->contextMenuStripForOutput;
			this->Output->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Output->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Output->Location = System::Drawing::Point(11, 29);
			this->Output->Margin = System::Windows::Forms::Padding(2);
			this->Output->Multiline = true;
			this->Output->Name = L"Output";
			this->Output->ReadOnly = true;
			this->Output->Size = System::Drawing::Size(230, 231);
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
			this->contextMenuStripForOutput->Size = System::Drawing::Size(204, 48);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->ShortcutKeyDisplayString = L"";
			this->saveToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->saveToolStripMenuItem->Size = System::Drawing::Size(203, 22);
			this->saveToolStripMenuItem->Text = L"—охранить как...";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveToolStripMenuItem_Click);
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(203, 22);
			this->openToolStripMenuItem->Text = L"ќткрыть";
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
			this->groupBoxTypes->Location = System::Drawing::Point(264, 68);
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
			this->buttonGenerate->Location = System::Drawing::Point(11, 274);
			this->buttonGenerate->Margin = System::Windows::Forms::Padding(2);
			this->buttonGenerate->Name = L"buttonGenerate";
			this->buttonGenerate->Size = System::Drawing::Size(473, 54);
			this->buttonGenerate->TabIndex = 9;
			this->buttonGenerate->Text = L"Generate";
			this->buttonGenerate->UseVisualStyleBackColor = true;
			this->buttonGenerate->Click += gcnew System::EventHandler(this, &MyForm::buttonGenerate_Click);
			// 
			// max
			// 
			this->max->AutoSize = true;
			this->max->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->max->Location = System::Drawing::Point(283, 39);
			this->max->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->max->Name = L"max";
			this->max->Size = System::Drawing::Size(55, 24);
			this->max->TabIndex = 11;
			this->max->Text = L"max:";
			// 
			// inputMax
			// 
			this->inputMax->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->inputMax->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->inputMax->Location = System::Drawing::Point(342, 39);
			this->inputMax->Margin = System::Windows::Forms::Padding(2);
			this->inputMax->Name = L"inputMax";
			this->inputMax->Size = System::Drawing::Size(79, 23);
			this->inputMax->TabIndex = 10;
			this->inputMax->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// ArrayOfGenerating
			// 
			this->ArrayOfGenerating->AutoSize = true;
			this->ArrayOfGenerating->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ArrayOfGenerating->Location = System::Drawing::Point(342, 171);
			this->ArrayOfGenerating->Name = L"ArrayOfGenerating";
			this->ArrayOfGenerating->Size = System::Drawing::Size(65, 24);
			this->ArrayOfGenerating->TabIndex = 18;
			this->ArrayOfGenerating->Text = L"Array";
			this->ArrayOfGenerating->UseVisualStyleBackColor = true;
			this->ArrayOfGenerating->CheckedChanged += gcnew System::EventHandler(this, &MyForm::ArrayOfGenerating_CheckedChanged);
			// 
			// sizeArray
			// 
			this->sizeArray->AutoSize = true;
			this->sizeArray->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->sizeArray->Location = System::Drawing::Point(285, 198);
			this->sizeArray->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->sizeArray->Name = L"sizeArray";
			this->sizeArray->Size = System::Drawing::Size(53, 24);
			this->sizeArray->TabIndex = 19;
			this->sizeArray->Text = L"size:";
			this->sizeArray->Visible = false;
			// 
			// inputSizeArray
			// 
			this->inputSizeArray->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->inputSizeArray->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->inputSizeArray->Location = System::Drawing::Point(342, 200);
			this->inputSizeArray->Margin = System::Windows::Forms::Padding(2);
			this->inputSizeArray->Name = L"inputSizeArray";
			this->inputSizeArray->Size = System::Drawing::Size(79, 23);
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
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(496, 368);
			this->Controls->Add(this->inputSizeArray);
			this->Controls->Add(this->sizeArray);
			this->Controls->Add(this->ArrayOfGenerating);
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
		System::Void ArrayOfGenerating_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
