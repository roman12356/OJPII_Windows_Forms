#pragma once

namespace OJPIIWindowsForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for _MenuWater
	/// </summary>
	public ref class _MenuWater : public System::Windows::Forms::Form
	{


	public: delegate void EventDelegate(System::Object^ sender, System::EventArgs^ e);
	public: event EventDelegate^ Event_MenuWater;

	public: delegate void EventDelegateDisplayWater(System::Object^ sender, System::EventArgs^ e, String^ WaterHeightString);
	public: event EventDelegateDisplayWater^ Event_MenuWater_DisplayWater;


	public:
		_MenuWater(void)
		{
			InitializeComponent();
			this->maskedTextBoxMenuWater->Focus();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~_MenuWater()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  buttonWaterNext;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBoxMenuWater;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(_MenuWater::typeid));
			this->buttonWaterNext = (gcnew System::Windows::Forms::Button());
			this->maskedTextBoxMenuWater = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// buttonWaterNext
			// 
			this->buttonWaterNext->AutoSize = true;
			this->buttonWaterNext->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->buttonWaterNext->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonWaterNext->Location = System::Drawing::Point(855, 620);
			this->buttonWaterNext->Margin = System::Windows::Forms::Padding(4);
			this->buttonWaterNext->Name = L"buttonWaterNext";
			this->buttonWaterNext->Size = System::Drawing::Size(109, 43);
			this->buttonWaterNext->TabIndex = 1;
			this->buttonWaterNext->Text = L"Dalej";
			this->buttonWaterNext->UseVisualStyleBackColor = true;
			this->buttonWaterNext->Click += gcnew System::EventHandler(this, &_MenuWater::buttonWaterNext_Click);
			// 
			// maskedTextBoxMenuWater
			// 
			this->maskedTextBoxMenuWater->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->maskedTextBoxMenuWater->Location = System::Drawing::Point(543, 226);
			this->maskedTextBoxMenuWater->Margin = System::Windows::Forms::Padding(4);
			this->maskedTextBoxMenuWater->Mask = L"00000";
			this->maskedTextBoxMenuWater->Name = L"maskedTextBoxMenuWater";
			this->maskedTextBoxMenuWater->Size = System::Drawing::Size(132, 26);
			this->maskedTextBoxMenuWater->TabIndex = 2;
			this->maskedTextBoxMenuWater->ValidatingType = System::Int32::typeid;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(81, 215);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(223, 31);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Wysokoœæ cieczy";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(684, 215);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(66, 31);
			this->label2->TabIndex = 4;
			this->label2->Text = L"[cm]";
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(81, 312);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(824, 234);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Program obliczy i zaprezentuje tor lotu cieczy wyp³ywaj¹cej z naczynia umieszczon"
				L"ego na wysokoœci dwóch metrów oraz zadan¹ wysokoœci¹ s³upa cieczy.";
			// 
			// _MenuWater
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1059, 731);
			this->ControlBox = false;
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->maskedTextBoxMenuWater);
			this->Controls->Add(this->buttonWaterNext);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1065, 737);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(1065, 737);
			this->Name = L"_MenuWater";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Shown += gcnew System::EventHandler(this, &_MenuWater::_MenuWater_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonWaterBack_Click(System::Object^  sender, System::EventArgs^  e)
	{
				 this->Hide();
				 this->Event_MenuWater(this, e);
	}
	private: System::Void buttonWaterNext_Click(System::Object^  sender, System::EventArgs^  e)
	{
				 if (maskedTextBoxMenuWater->Text != "")
				 {
					 this->Hide();
					 this->Event_MenuWater_DisplayWater(this, e, maskedTextBoxMenuWater->Text);
				 }
				 else
				 {
					 MessageBox::Show("WprowadŸ wysokoœæ");
				 }
	}

	public: System::Void FocusMaskedText(void)
	{
				this->maskedTextBoxMenuWater->Focus();
	}
	private: System::Void _MenuWater_Load(System::Object^  sender, System::EventArgs^  e)
	{
				 FocusMaskedText();
	}
};
}
