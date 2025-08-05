#pragma once
#include<msclr/marshal_cppstd.h>
#include <string>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Drawing;
using namespace System::Threading;
using namespace System::IO;
using namespace System::Runtime::InteropServices;

[DllImport("ServerDLL.dll", CallingConvention = CallingConvention::Cdecl)]
void sendmessage(std::string stdusername);

[DllImport("ServerDLL.dll", CallingConvention = CallingConvention::Cdecl)]
void sendUsername(std::string stdusername);

[DllImport("ServerDLL.dll", CallingConvention = CallingConvention::Cdecl)]
void sendPassword(std::string stdusername);

//[DllImport("ServerDLL.dll", CallingConvention = CallingConvention::Cdecl)]
//void sendToUiLogin(sendmessege^, std::string uiMessege);

namespace SocketUI {

	/// <summary>
	/// Summary for login
	/// </summary>
	public ref class login : public System::Windows::Forms::UserControl
	{

		//sendmessege^ sndmsg;

	public:
		login(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(42, 91);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"username";
			this->label1->Click += gcnew System::EventHandler(this, &login::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(43, 120);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"password";
			this->label2->Click += gcnew System::EventHandler(this, &login::label2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(103, 179);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(64, 22);
			this->button1->TabIndex = 2;
			this->button1->Text = L"login";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &login::button1_Click_1);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::LightBlue;
			this->textBox1->Location = System::Drawing::Point(121, 91);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::LightBlue;
			this->textBox2->Location = System::Drawing::Point(121, 117);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 4;
			// 
			// login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"login";
			this->Size = System::Drawing::Size(276, 271);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void getmessege(std::string msg) {
			if (msg == "true")
			{
				msg = "login Successful!";

			}
			else
			{
				msg = "your information is WORNG";
			}

			MessageBox::Show(gcnew String(msg.c_str()));
		}

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {

		String^ username;
		username = textBox1->Text->ToString();
		std::string stdusername;
		msclr::interop::marshal_context context;
		stdusername = context.marshal_as<std::string>(username);
		sendUsername(stdusername);


		String^ password;
		password = textBox2->Text->ToString();
		std::string stdpassword;
		//msclr::interop::marshal_context context;
		stdpassword = context.marshal_as<std::string>(password);
		sendPassword(stdpassword);

		//sndmsg = gcnew sendmessege(this, &login::getmessege);
		//sendToUi(sndmsg, "NULLTEXT");
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
