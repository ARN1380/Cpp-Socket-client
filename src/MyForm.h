#pragma once
#include<msclr/marshal_cppstd.h>
#include <string>
#include "login.h"
#include "liberary.h"

namespace SocketUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::IO;
	using namespace System::Runtime::InteropServices;


	delegate void DelADDCLIENT(String^, bool);
	delegate void DelADDQUEUE(array< String^>^);
	delegate void DelProgressBar(int, int);
	delegate void DelCompelete(int);


	[UnmanagedFunctionPointerAttribute(CallingConvention::Cdecl)]
	delegate void UIChangeProgress(int queueid, int value);
	[UnmanagedFunctionPointerAttribute(CallingConvention::Cdecl)]
	delegate void UINewClient(std::string, bool flag);
	[UnmanagedFunctionPointerAttribute(CallingConvention::Cdecl)]
	delegate void UINewRecieve(int Queueid, std::string Name, std::string Extention);

	[UnmanagedFunctionPointerAttribute(CallingConvention::Cdecl)]
	delegate void sendmessege(std::string);


	[DllImport("ServerDLL.dll", CallingConvention = CallingConvention::Cdecl)]
	void Startup(std::string, int, UIChangeProgress^, UINewClient^, UINewRecieve^/*, sendmessege^*/);

	[DllImport("ServerDLL.dll", CallingConvention = CallingConvention::Cdecl)]
	void SendFile(std::string path);

	[DllImport("ServerDLL.dll", CallingConvention = CallingConvention::Cdecl)]
	void StartDownload(int queueid);

	[DllImport("ServerDLL.dll", CallingConvention = CallingConvention::Cdecl)]
	void sendToUi(sendmessege^, std::string uiMessege);
	
	public ref class MyForm : public System::Windows::Forms::Form
	{
		login^ loginForm = gcnew login();
		liberary^ liberaryForm = gcnew liberary();


		sendmessege^ sndmsg;
		DelADDCLIENT^ Event_ADDCLIENT;
		DelADDQUEUE^ Event_ADDQUEUE;
		DelProgressBar^ Event_Progress;
		UIChangeProgress^ Event_UIChangeProgress;
		UINewClient^ Event_UINewClient;
		UINewRecieve^ Event_UINewRecieve;
		DelCompelete^ Event_Compelete;
		bool IsRunning;


	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Panel^ panel2;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::PictureBox^ pictureBox4;


		   bool IsTransfer;
	public:MyForm()
	{
		InitializeComponent();
		//Rigster();
		IsRunning = false;
		IsTransfer = false;
		Thread^ thread = gcnew Thread(gcnew ThreadStart(this, &MyForm::StartServer));
		thread->Start();

		//sndmsg = gcnew sendmessege(this, &MyForm::getmessege);
		sndmsg = gcnew sendmessege(this, &MyForm::getmessege);
		sendToUi(sndmsg, "NULLTEXT");
	}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::ColumnHeader^ RowIndex;
	private: System::Windows::Forms::ColumnHeader^ Name;
	private: System::Windows::Forms::ColumnHeader^ Tenasferd;
	private: System::Windows::Forms::ColumnHeader^ Type;
	private: System::Windows::Forms::ColumnHeader^ Time;
	private: System::Windows::Forms::ColumnHeader^ Date;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->RowIndex = (gcnew System::Windows::Forms::ColumnHeader());
			this->Name = (gcnew System::Windows::Forms::ColumnHeader());
			this->Tenasferd = (gcnew System::Windows::Forms::ColumnHeader());
			this->Type = (gcnew System::Windows::Forms::ColumnHeader());
			this->Time = (gcnew System::Windows::Forms::ColumnHeader());
			this->Date = (gcnew System::Windows::Forms::ColumnHeader());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->SuspendLayout();
			// 
			// RowIndex
			// 
			this->RowIndex->Text = L"Index";
			this->RowIndex->Width = 42;
			// 
			// Name
			// 
			this->Name->Text = L"File Name";
			this->Name->Width = 118;
			// 
			// Tenasferd
			// 
			this->Tenasferd->Text = L"Tenasferd";
			this->Tenasferd->Width = 66;
			// 
			// Type
			// 
			this->Type->Text = L"Type";
			// 
			// Time
			// 
			this->Time->Text = L"Time";
			this->Time->Width = 80;
			// 
			// Date
			// 
			this->Date->Text = L"Date";
			this->Date->Width = 104;
			// 
			// panel1
			// 
			this->panel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel1->Location = System::Drawing::Point(0, 78);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(834, 428);
			this->panel1->TabIndex = 21;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 56);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(43, 13);
			this->label1->TabIndex = 22;
			this->label1->Text = L"buy List";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(102, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 13);
			this->label2->TabIndex = 26;
			this->label2->Text = L"Login";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(9, 7);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(47, 39);
			this->pictureBox1->TabIndex = 24;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(98, 7);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(42, 39);
			this->pictureBox2->TabIndex = 25;
			this->pictureBox2->TabStop = false;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::PaleGreen;
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Controls->Add(this->pictureBox4);
			this->panel2->Controls->Add(this->pictureBox2);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(834, 77);
			this->panel2->TabIndex = 28;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(187, 56);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(44, 13);
			this->label4->TabIndex = 30;
			this->label4->Text = L"Liberary";
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(187, 7);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(44, 39);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 27;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Click += gcnew System::EventHandler(this, &MyForm::pictureBox4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Inherit;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(834, 506);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->HelpButton = true;
			this->MaximizeBox = false;
//			this->Name = L"MyForm";
			this->Text = L"Book Store";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	
		std::string to_stirng(String^ str)
		{
			msclr::interop::marshal_context contex;
			return contex.marshal_as<std::string>(str);
		}

		void StartServer()
		{
			std::string ip = "127.0.0.1";
			int port = 7071;
			IsRunning = true;
			Startup(ip, port, Event_UIChangeProgress, Event_UINewClient, Event_UINewRecieve/*, sndmsg*/);

		}

		
		void getmessege(std::string msg) {
			MessageBox::Show(gcnew String(msg.c_str()));
		}


	
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	panel1->Controls->Clear();
	panel1->Controls->Add(loginForm);
}

private: System::Void pictureBox4_Click(System::Object^ sender, System::EventArgs^ e) {
	panel1->Controls->Clear();
	panel1->Controls->Add(liberaryForm);
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {

	//std::string str = "get";
	//String^ str2 = gcnew String(str.c_str());
	//label1->Text = str2;
}
};
}














