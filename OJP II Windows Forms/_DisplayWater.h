#pragma once

#include "OpenGLWater.h"
//#include "_CDisplay_Water.h"

namespace OJPIIWindowsForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLWater;

	/// <summary>
	/// Summary for _DisplayWater
	/// </summary>
	public ref class _DisplayWater : public System::Windows::Forms::Form
	{

	public: delegate void DelegateButton(System::Object^ sender, System::EventArgs^ e);
	public: event DelegateButton^ EventButton;

	public:
		_DisplayWater(void)
		{
			InitializeComponent();

			OpenGL_W = gcnew _COpenGLWater(this, 800, 600);
			//
			//TODO: Add the constructor code here
			//
		}

		void SetHeight(int height)
		{
			this->height = height;
		}


	protected:

		int height, i = 0;
		OpenGLWater::_COpenGLWater ^ OpenGL_W;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  labelOGL_PX;



	private: System::Windows::Forms::Label^  labelOGL_Z;


	private: System::Windows::Forms::Button^  buttonOGLStart;
	private: System::Windows::Forms::Button^  buttonOGLSlowMo;
	private: System::Windows::Forms::Label^  labelOGL_Zas;
	private: System::Windows::Forms::Label^  labelOGL_X;

	private: System::Windows::Forms::Label^  labelOGL_PY;
	private: System::Windows::Forms::Label^  labelOGL_Y;
	private: System::Windows::Forms::Label^  labelOGL_TL;
	private: System::Windows::Forms::Label^  labelOGL_T;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;




	protected:

	protected:
	private: System::Windows::Forms::Timer^  timer1;

			 /// <summary>
			 /// Clean up any resources being used.
			 /// </summary>
			 ~_DisplayWater()
			 {
				 if (components)
				 {
					 delete components;
				 }
			 }
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->labelOGL_PX = (gcnew System::Windows::Forms::Label());
			this->labelOGL_Z = (gcnew System::Windows::Forms::Label());
			this->buttonOGLStart = (gcnew System::Windows::Forms::Button());
			this->buttonOGLSlowMo = (gcnew System::Windows::Forms::Button());
			this->labelOGL_Zas = (gcnew System::Windows::Forms::Label());
			this->labelOGL_X = (gcnew System::Windows::Forms::Label());
			this->labelOGL_PY = (gcnew System::Windows::Forms::Label());
			this->labelOGL_Y = (gcnew System::Windows::Forms::Label());
			this->labelOGL_TL = (gcnew System::Windows::Forms::Label());
			this->labelOGL_T = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 30;
			this->timer1->Tick += gcnew System::EventHandler(this, &_DisplayWater::timer1_Tick);
			// 
			// button1
			// 
			this->button1->AutoSize = true;
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(185)), static_cast<System::Int32>(static_cast<System::Byte>(122)),
				static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button1->Location = System::Drawing::Point(16, 673);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(109, 43);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Powrót";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &_DisplayWater::button1_Click);
			// 
			// labelOGL_PX
			// 
			this->labelOGL_PX->AutoSize = true;
			this->labelOGL_PX->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)), static_cast<System::Int32>(static_cast<System::Byte>(217)),
				static_cast<System::Int32>(static_cast<System::Byte>(234)));
			this->labelOGL_PX->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelOGL_PX->Location = System::Drawing::Point(636, 85);
			this->labelOGL_PX->Name = L"labelOGL_PX";
			this->labelOGL_PX->Size = System::Drawing::Size(143, 31);
			this->labelOGL_PX->TabIndex = 1;
			this->labelOGL_PX->Text = L"Pozycja X:";
			this->labelOGL_PX->UseWaitCursor = true;
			// 
			// labelOGL_Z
			// 
			this->labelOGL_Z->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->labelOGL_Z->AutoSize = true;
			this->labelOGL_Z->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)), static_cast<System::Int32>(static_cast<System::Byte>(217)),
				static_cast<System::Int32>(static_cast<System::Byte>(234)));
			this->labelOGL_Z->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelOGL_Z->Location = System::Drawing::Point(675, 26);
			this->labelOGL_Z->Name = L"labelOGL_Z";
			this->labelOGL_Z->Size = System::Drawing::Size(104, 31);
			this->labelOGL_Z->TabIndex = 2;
			this->labelOGL_Z->Text = L"Zasiêg:";
			this->labelOGL_Z->UseWaitCursor = true;
			// 
			// buttonOGLStart
			// 
			this->buttonOGLStart->AutoSize = true;
			this->buttonOGLStart->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)), static_cast<System::Int32>(static_cast<System::Byte>(217)),
				static_cast<System::Int32>(static_cast<System::Byte>(234)));
			this->buttonOGLStart->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->buttonOGLStart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonOGLStart->Location = System::Drawing::Point(16, 26);
			this->buttonOGLStart->Name = L"buttonOGLStart";
			this->buttonOGLStart->Size = System::Drawing::Size(109, 47);
			this->buttonOGLStart->TabIndex = 3;
			this->buttonOGLStart->Text = L"Start";
			this->buttonOGLStart->UseVisualStyleBackColor = false;
			this->buttonOGLStart->Click += gcnew System::EventHandler(this, &_DisplayWater::buttonOGLStart_Click);
			// 
			// buttonOGLSlowMo
			// 
			this->buttonOGLSlowMo->AutoSize = true;
			this->buttonOGLSlowMo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)), static_cast<System::Int32>(static_cast<System::Byte>(217)),
				static_cast<System::Int32>(static_cast<System::Byte>(234)));
			this->buttonOGLSlowMo->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->buttonOGLSlowMo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonOGLSlowMo->Location = System::Drawing::Point(258, 26);
			this->buttonOGLSlowMo->Name = L"buttonOGLSlowMo";
			this->buttonOGLSlowMo->Size = System::Drawing::Size(285, 47);
			this->buttonOGLSlowMo->TabIndex = 4;
			this->buttonOGLSlowMo->Text = L"W³¹cz zwolnione tempo";
			this->buttonOGLSlowMo->UseVisualStyleBackColor = false;
			this->buttonOGLSlowMo->Click += gcnew System::EventHandler(this, &_DisplayWater::buttonOGLSlowMo_Click);
			// 
			// labelOGL_Zas
			// 
			this->labelOGL_Zas->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->labelOGL_Zas->AutoSize = true;
			this->labelOGL_Zas->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)), static_cast<System::Int32>(static_cast<System::Byte>(217)),
				static_cast<System::Int32>(static_cast<System::Byte>(234)));
			this->labelOGL_Zas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelOGL_Zas->Location = System::Drawing::Point(811, 26);
			this->labelOGL_Zas->Name = L"labelOGL_Zas";
			this->labelOGL_Zas->Size = System::Drawing::Size(29, 31);
			this->labelOGL_Zas->TabIndex = 5;
			this->labelOGL_Zas->Text = L"0";
			this->labelOGL_Zas->UseWaitCursor = true;
			// 
			// labelOGL_X
			// 
			this->labelOGL_X->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->labelOGL_X->AutoSize = true;
			this->labelOGL_X->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)), static_cast<System::Int32>(static_cast<System::Byte>(217)),
				static_cast<System::Int32>(static_cast<System::Byte>(234)));
			this->labelOGL_X->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelOGL_X->Location = System::Drawing::Point(811, 85);
			this->labelOGL_X->Name = L"labelOGL_X";
			this->labelOGL_X->Size = System::Drawing::Size(29, 31);
			this->labelOGL_X->TabIndex = 6;
			this->labelOGL_X->Text = L"0";
			this->labelOGL_X->UseWaitCursor = true;
			// 
			// labelOGL_PY
			// 
			this->labelOGL_PY->AutoSize = true;
			this->labelOGL_PY->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)), static_cast<System::Int32>(static_cast<System::Byte>(217)),
				static_cast<System::Int32>(static_cast<System::Byte>(234)));
			this->labelOGL_PY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelOGL_PY->Location = System::Drawing::Point(636, 146);
			this->labelOGL_PY->Name = L"labelOGL_PY";
			this->labelOGL_PY->Size = System::Drawing::Size(143, 31);
			this->labelOGL_PY->TabIndex = 7;
			this->labelOGL_PY->Text = L"Pozycja Y:";
			this->labelOGL_PY->UseWaitCursor = true;
			// 
			// labelOGL_Y
			// 
			this->labelOGL_Y->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->labelOGL_Y->AutoSize = true;
			this->labelOGL_Y->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)), static_cast<System::Int32>(static_cast<System::Byte>(217)),
				static_cast<System::Int32>(static_cast<System::Byte>(234)));
			this->labelOGL_Y->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelOGL_Y->Location = System::Drawing::Point(811, 146);
			this->labelOGL_Y->Name = L"labelOGL_Y";
			this->labelOGL_Y->Size = System::Drawing::Size(29, 31);
			this->labelOGL_Y->TabIndex = 8;
			this->labelOGL_Y->Text = L"0";
			this->labelOGL_Y->UseWaitCursor = true;
			// 
			// labelOGL_TL
			// 
			this->labelOGL_TL->AutoSize = true;
			this->labelOGL_TL->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)), static_cast<System::Int32>(static_cast<System::Byte>(217)),
				static_cast<System::Int32>(static_cast<System::Byte>(234)));
			this->labelOGL_TL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelOGL_TL->Location = System::Drawing::Point(694, 208);
			this->labelOGL_TL->Name = L"labelOGL_TL";
			this->labelOGL_TL->Size = System::Drawing::Size(85, 31);
			this->labelOGL_TL->TabIndex = 9;
			this->labelOGL_TL->Text = L"Czas:";
			this->labelOGL_TL->UseWaitCursor = true;
			// 
			// labelOGL_T
			// 
			this->labelOGL_T->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->labelOGL_T->AutoSize = true;
			this->labelOGL_T->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)), static_cast<System::Int32>(static_cast<System::Byte>(217)),
				static_cast<System::Int32>(static_cast<System::Byte>(234)));
			this->labelOGL_T->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelOGL_T->Location = System::Drawing::Point(811, 208);
			this->labelOGL_T->Name = L"labelOGL_T";
			this->labelOGL_T->Size = System::Drawing::Size(29, 31);
			this->labelOGL_T->TabIndex = 10;
			this->labelOGL_T->Text = L"0";
			this->labelOGL_T->UseWaitCursor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)), static_cast<System::Int32>(static_cast<System::Byte>(217)),
				static_cast<System::Int32>(static_cast<System::Byte>(234)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(995, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 31);
			this->label1->TabIndex = 11;
			this->label1->Text = L"[m]";
			this->label1->UseWaitCursor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)), static_cast<System::Int32>(static_cast<System::Byte>(217)),
				static_cast<System::Int32>(static_cast<System::Byte>(234)));
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(995, 85);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 31);
			this->label2->TabIndex = 12;
			this->label2->Text = L"[m]";
			this->label2->UseWaitCursor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)), static_cast<System::Int32>(static_cast<System::Byte>(217)),
				static_cast<System::Int32>(static_cast<System::Byte>(234)));
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(995, 146);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(52, 31);
			this->label3->TabIndex = 13;
			this->label3->Text = L"[m]";
			this->label3->UseWaitCursor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)), static_cast<System::Int32>(static_cast<System::Byte>(217)),
				static_cast<System::Int32>(static_cast<System::Byte>(234)));
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(995, 208);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(44, 31);
			this->label4->TabIndex = 14;
			this->label4->Text = L"[s]";
			this->label4->UseWaitCursor = true;
			// 
			// _DisplayWater
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1059, 731);
			this->ControlBox = false;
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->labelOGL_T);
			this->Controls->Add(this->labelOGL_TL);
			this->Controls->Add(this->labelOGL_Y);
			this->Controls->Add(this->labelOGL_PY);
			this->Controls->Add(this->labelOGL_X);
			this->Controls->Add(this->labelOGL_Zas);
			this->Controls->Add(this->buttonOGLSlowMo);
			this->Controls->Add(this->buttonOGLStart);
			this->Controls->Add(this->labelOGL_Z);
			this->Controls->Add(this->labelOGL_PX);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximumSize = System::Drawing::Size(1065, 737);
			this->MinimumSize = System::Drawing::Size(1065, 737);
			this->Name = L"_DisplayWater";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
				 double temp;
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 temp = OpenGL_W->GetPosX();
				 this->labelOGL_X->Text = temp.ToString("G7");
				 temp = -OpenGL_W->GetPosY();
				 this->labelOGL_Y->Text = temp.ToString("G7");
				 temp = OpenGL_W->GetTime();
				 this->labelOGL_T->Text = temp.ToString("G7");
				 OpenGL_W->Render();
				 OpenGL_W->SwapOpenGLBuffers();
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
				 timer1->Enabled = false;
				 this->EventButton(this, e);
				 this->Hide();
				 OpenGL_W->~_COpenGLWater();

	}

	public: System::Void Start(void)
	{

				OpenGL_W->RefreshContexts(800, 600);
				timer1->Enabled = true;
	}

	public: System::Void Count()
	{
				OpenGL_W->Count(height);
				double temp = OpenGL_W->GetRangeMax();
				this->labelOGL_Zas->Text = temp.ToString("G7");
	}

	private: System::Void buttonOGLStart_Click(System::Object^  sender, System::EventArgs^  e)
	{
				 this->buttonOGLSlowMo->Text = (OpenGL_W->GetSlowMo() ? "Wy³¹cz zwolnione tempo" : "W³¹cz zwolnione tempo");
				 OpenGL_W->Start();
	}
	private: System::Void buttonOGLSlowMo_Click(System::Object^  sender, System::EventArgs^  e)
	{
				 OpenGL_W->ChangeSlowMo();
				 this->buttonOGLSlowMo->Text = (OpenGL_W->GetSlowMo() ? "Wy³¹cz zwolnione tempo" : "W³¹cz zwolnione tempo");
	}
	};
}
