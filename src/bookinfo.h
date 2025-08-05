#pragma once
#include<msclr/marshal_cppstd.h>
#include <string>
#include "AllGenre.h"


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

//
[UnmanagedFunctionPointerAttribute(CallingConvention::Cdecl)]
delegate void sendmessege(std::string);


namespace SocketUI {

	/// <summary>
	/// Summary for bookinfo
	/// </summary>
	public ref class bookinfo : public System::Windows::Forms::UserControl
	{

		sendmessege^ sndmsg;
		AllGenre^ AllGenreForm = gcnew AllGenre();

	public:

		bookinfo(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			//sndmsg = gcnew sendmessege(this, &bookinfo::getmessege);

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~bookinfo()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ bookname;



	private: System::Windows::Forms::Label^ writer;
	private: System::Windows::Forms::Label^ date;

	private: System::Windows::Forms::Label^ details;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ edit;
	private: System::Windows::Forms::Label^ version;
	private: System::Windows::Forms::Label^ price;
	private: System::Windows::Forms::Label^ genre;
	private: System::Windows::Forms::Label^ publisher;
	private: System::Windows::Forms::Label^ languege;
	private: System::Windows::Forms::Label^ inventory;


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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->bookname = (gcnew System::Windows::Forms::Label());
			this->writer = (gcnew System::Windows::Forms::Label());
			this->date = (gcnew System::Windows::Forms::Label());
			this->details = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->edit = (gcnew System::Windows::Forms::Label());
			this->version = (gcnew System::Windows::Forms::Label());
			this->price = (gcnew System::Windows::Forms::Label());
			this->genre = (gcnew System::Windows::Forms::Label());
			this->publisher = (gcnew System::Windows::Forms::Label());
			this->languege = (gcnew System::Windows::Forms::Label());
			this->inventory = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(74, 41);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(222, 335);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// bookname
			// 
			this->bookname->AutoSize = true;
			this->bookname->Location = System::Drawing::Point(327, 45);
			this->bookname->Name = L"bookname";
			this->bookname->Size = System::Drawing::Size(63, 13);
			this->bookname->TabIndex = 1;
			this->bookname->Text = L"Book Name";
			// 
			// writer
			// 
			this->writer->AutoSize = true;
			this->writer->Location = System::Drawing::Point(327, 65);
			this->writer->Name = L"writer";
			this->writer->Size = System::Drawing::Size(32, 13);
			this->writer->TabIndex = 2;
			this->writer->Text = L"writer";
			// 
			// date
			// 
			this->date->AutoSize = true;
			this->date->Location = System::Drawing::Point(329, 93);
			this->date->Name = L"date";
			this->date->Size = System::Drawing::Size(30, 13);
			this->date->TabIndex = 3;
			this->date->Text = L"Date";
			// 
			// details
			// 
			this->details->AutoSize = true;
			this->details->Location = System::Drawing::Point(329, 302);
			this->details->Name = L"details";
			this->details->Size = System::Drawing::Size(210, 13);
			this->details->TabIndex = 4;
			this->details->Text = L"book details, everything about book is here";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(331, 328);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// edit
			// 
			this->edit->AutoSize = true;
			this->edit->Location = System::Drawing::Point(328, 119);
			this->edit->Name = L"edit";
			this->edit->Size = System::Drawing::Size(62, 13);
			this->edit->TabIndex = 6;
			this->edit->Text = L"EditNumber";
			// 
			// version
			// 
			this->version->AutoSize = true;
			this->version->Location = System::Drawing::Point(328, 148);
			this->version->Name = L"version";
			this->version->Size = System::Drawing::Size(66, 13);
			this->version->TabIndex = 7;
			this->version->Text = L"VersionType";
			// 
			// price
			// 
			this->price->AutoSize = true;
			this->price->Location = System::Drawing::Point(329, 173);
			this->price->Name = L"price";
			this->price->Size = System::Drawing::Size(31, 13);
			this->price->TabIndex = 8;
			this->price->Text = L"Price";
			// 
			// genre
			// 
			this->genre->AutoSize = true;
			this->genre->Location = System::Drawing::Point(328, 198);
			this->genre->Name = L"genre";
			this->genre->Size = System::Drawing::Size(36, 13);
			this->genre->TabIndex = 9;
			this->genre->Text = L"Genre";
			// 
			// publisher
			// 
			this->publisher->AutoSize = true;
			this->publisher->Location = System::Drawing::Point(329, 224);
			this->publisher->Name = L"publisher";
			this->publisher->Size = System::Drawing::Size(50, 13);
			this->publisher->TabIndex = 10;
			this->publisher->Text = L"Publisher";
			// 
			// languege
			// 
			this->languege->AutoSize = true;
			this->languege->Location = System::Drawing::Point(329, 249);
			this->languege->Name = L"languege";
			this->languege->Size = System::Drawing::Size(55, 13);
			this->languege->TabIndex = 11;
			this->languege->Text = L"Language";
			// 
			// inventory
			// 
			this->inventory->AutoSize = true;
			this->inventory->Location = System::Drawing::Point(329, 274);
			this->inventory->Name = L"inventory";
			this->inventory->Size = System::Drawing::Size(51, 13);
			this->inventory->TabIndex = 12;
			this->inventory->Text = L"Inventory";
			// 
			// bookinfo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->inventory);
			this->Controls->Add(this->languege);
			this->Controls->Add(this->publisher);
			this->Controls->Add(this->genre);
			this->Controls->Add(this->price);
			this->Controls->Add(this->version);
			this->Controls->Add(this->edit);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->details);
			this->Controls->Add(this->date);
			this->Controls->Add(this->writer);
			this->Controls->Add(this->bookname);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"bookinfo";
			this->Size = System::Drawing::Size(834, 428);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void getmessege(std::string msg) {
			bookname->Text = gcnew String(msg.c_str());
		}

	};


}
