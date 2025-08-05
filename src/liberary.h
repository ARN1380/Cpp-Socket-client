#pragma once
#include<msclr/marshal_cppstd.h>
#include <string>
#include "HorrorGenre.h"
#include "PoemGenre.h"
#include "AllGenre.h"
#include "bookinfo.h"
#include "bookIcon.h"

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
void sendmessage(std::string stdbookname);

[DllImport("ServerDLL.dll", CallingConvention = CallingConvention::Cdecl)]
void sendToUi(sendmessege^, std::string uiMessege);

[DllImport("ServerDLL.dll", CallingConvention = CallingConvention::Cdecl)]
void getBookName(std::string stdbookname);



namespace SocketUI {

	/// <summary>
	/// Summary for liberary
	/// </summary>
	public ref class liberary : public System::Windows::Forms::UserControl
	{
		sendmessege^ sndmsg;

		HorrorGenre^ HorrorGenreForm = gcnew HorrorGenre();
		PoemGenre^ PoemGenreForm = gcnew PoemGenre();
		AllGenre^ AllGenreForm = gcnew AllGenre();
		bookinfo^ bookinfoForm = gcnew bookinfo();
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;



	private: System::Windows::Forms::ToolStripMenuItem^ allToolStripMenuItem;

	public:
		liberary(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			addBook("hey");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~liberary()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ genreToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ horrorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ poemToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ authorToolStripMenuItem;
	private: System::Windows::Forms::Panel^ panel1;
	protected:

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
		/// 
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->genreToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->horrorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->poemToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->authorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->allToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->menuStrip1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->genreToolStripMenuItem,
					this->authorToolStripMenuItem, this->allToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(834, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// genreToolStripMenuItem
			// 
			this->genreToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->horrorToolStripMenuItem,
					this->poemToolStripMenuItem
			});
			this->genreToolStripMenuItem->Name = L"genreToolStripMenuItem";
			this->genreToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->genreToolStripMenuItem->Text = L"Genre";
			// 
			// horrorToolStripMenuItem
			// 
			this->horrorToolStripMenuItem->Name = L"horrorToolStripMenuItem";
			this->horrorToolStripMenuItem->Size = System::Drawing::Size(109, 22);
			this->horrorToolStripMenuItem->Text = L"Horror";
			this->horrorToolStripMenuItem->Click += gcnew System::EventHandler(this, &liberary::horrorToolStripMenuItem_Click);
			// 
			// poemToolStripMenuItem
			// 
			this->poemToolStripMenuItem->Name = L"poemToolStripMenuItem";
			this->poemToolStripMenuItem->Size = System::Drawing::Size(109, 22);
			this->poemToolStripMenuItem->Text = L"poem";
			this->poemToolStripMenuItem->Click += gcnew System::EventHandler(this, &liberary::poemToolStripMenuItem_Click);
			// 
			// authorToolStripMenuItem
			// 
			this->authorToolStripMenuItem->Name = L"authorToolStripMenuItem";
			this->authorToolStripMenuItem->Size = System::Drawing::Size(56, 20);
			this->authorToolStripMenuItem->Text = L"Author";
			// 
			// allToolStripMenuItem
			// 
			this->allToolStripMenuItem->Name = L"allToolStripMenuItem";
			this->allToolStripMenuItem->Size = System::Drawing::Size(31, 20);
			this->allToolStripMenuItem->Text = L"all";
			this->allToolStripMenuItem->Click += gcnew System::EventHandler(this, &liberary::allToolStripMenuItem_Click);
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->Controls->Add(this->tableLayoutPanel1);
			this->panel1->Location = System::Drawing::Point(0, 27);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(831, 398);
			this->panel1->TabIndex = 3;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 4;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->Location = System::Drawing::Point(95, 22);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 7;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 150)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 150)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 150)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 150)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 80)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 80)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 80)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(616, 454);
			this->tableLayoutPanel1->TabIndex = 2;
			// 
			// liberary
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->panel1);
			this->Name = L"liberary";
			this->Size = System::Drawing::Size(834, 428);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		std::string getmessege(std::string msg) {
			return msg;
		}
	private: System::Void horrorToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		panel1->Controls->Clear();
		panel1->Controls->Add(HorrorGenreForm);
	}
	private: System::Void poemToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		panel1->Controls->Clear();
		panel1->Controls->Add(PoemGenreForm);
	}
	private: System::Void allToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		panel1->Controls->Clear();
		panel1->Controls->Add(AllGenreForm);
	}
		   void addBook(std::string msg) {
			   //sndmsg = gcnew sendmessege(this, &liberary::addBook);
			   //sendToUi(sndmsg, "NULLTEXT");

			   std::string input = msg, name = "null";
			   input = "#hey#you#have to#be OKEY#yes#";
			  
			   int i = 0, j = 0;
			   for (int k = 0; k < input.length(); k++)
			   {
				   if (input[k] == '#')
				   {
					   int l = k + 1;
					   while ((input[l] >= 'A' && input[l] <= 'Z') || (input[l] >= 'a' && input[l] <= 'z') || input[l] == ' ')
					   {
						   l++;
					   }
					   name = input.substr(k + 1, l - k - 1);

					   if (name != "")
					   {
						   bookIcon^ bookObj = gcnew bookIcon();
						   String^ sysName = gcnew String(name.c_str());
						   bookObj->setBookName(sysName);
						   //grid child add
						   tableLayoutPanel1->Controls->Add(bookObj, i, j);
						   i++;
						   if (i == 4)
						   {
							   i = 0;
							   j++;
						   }

					   }
				   }

		
			   }

		   }

	};
}

