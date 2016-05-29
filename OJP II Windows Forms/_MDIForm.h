#pragma once

#include "_MenuWater.h"
#include "_DisplayWater.h"



namespace OJPIIWindowsForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for _MDIForm
	/// </summary>
	public ref class _MDIForm : public System::Windows::Forms::Form
	{

	private:


		_MenuWater^ MenuWater = gcnew _MenuWater;
		_DisplayWater^ DisplayWater = gcnew _DisplayWater;





	public:
		//OJPIIWindowsForms::_MainForm MainForm;

		_MDIForm(void)
		{
			InitializeComponent();

			this->MenuWater->Event_MenuWater += gcnew _MenuWater::EventDelegate(this, &OJPIIWindowsForms::_MDIForm::mySubscriber1);
			this->MenuWater->Event_MenuWater_DisplayWater += gcnew _MenuWater::EventDelegateDisplayWater(this, &OJPIIWindowsForms::_MDIForm::SubscribeDisplayWater);
			this->DisplayWater->EventButton += gcnew _DisplayWater::DelegateButton(this, &OJPIIWindowsForms::_MDIForm::mySubscriber1);

			MenuWater->MdiParent = this;
			DisplayWater->MdiParent = this;
			MenuWater->Show();
			//DisplayWater->Show();




		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~_MDIForm()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->SuspendLayout();
			// 
			// _MDIForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(1072, 743);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->IsMdiContainer = true;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1088, 782);
			this->MinimumSize = System::Drawing::Size(1088, 782);
			this->Name = L"_MDIForm";
			this->Text = L"Grawitacja dla gimnazjum";
			this->ResumeLayout(false);

		}

	private: void mySubscriber1(System::Object^ sender, System::EventArgs^ e)
	{
				 MenuWater->Show();
				 MenuWater->FocusMaskedText();
	}


private: void SubscribeDisplayWater(System::Object^ sender, System::EventArgs^ e, String^ WaterHeightString)
{


			 DisplayWater->SetHeight(System::Convert::ToInt32(WaterHeightString));

			 DisplayWater->Count();

			 MenuWater->Hide();

			 DisplayWater->Show();
			 DisplayWater->Start();
}

#pragma endregion
};
}
