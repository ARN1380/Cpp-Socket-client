#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace SocketUI {

	/// <summary>
	/// Summary for bookIcon
	/// </summary>
	public ref class bookIcon : public System::Windows::Forms::UserControl
	{
	public:
		bookIcon(void)
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
		~bookIcon()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel4;
	protected:
	private: System::Windows::Forms::Label^ bookName;
	private: System::Windows::Forms::PictureBox^ bookPic;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(bookIcon::typeid));
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->bookName = (gcnew System::Windows::Forms::Label());
			this->bookPic = (gcnew System::Windows::Forms::PictureBox());
			this->tableLayoutPanel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bookPic))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 1;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel4->Controls->Add(this->bookName, 0, 1);
			this->tableLayoutPanel4->Controls->Add(this->bookPic, 0, 0);
			this->tableLayoutPanel4->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 2;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 85)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 15)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(150, 150);
			this->tableLayoutPanel4->TabIndex = 1;
			// 
			// bookName
			// 
			this->bookName->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->bookName->AutoSize = true;
			this->bookName->Location = System::Drawing::Point(43, 132);
			this->bookName->Name = L"bookName";
			this->bookName->Size = System::Drawing::Size(64, 13);
			this->bookName->TabIndex = 0;
			this->bookName->Text = L"GOOD BOY";
			// 
			// bookPic
			// 
			this->bookPic->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->bookPic->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bookPic.Image")));
			this->bookPic->Location = System::Drawing::Point(25, 6);
			this->bookPic->Name = L"bookPic";
			this->bookPic->Size = System::Drawing::Size(100, 115);
			this->bookPic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->bookPic->TabIndex = 1;
			this->bookPic->TabStop = false;
			// 
			// bookIcon
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->tableLayoutPanel4);
			this->Name = L"bookIcon";
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bookPic))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	public:
		void setBookName(String^ name) {
			bookName->Text = name;
		}
		void setBookPic() {

		}
	};
}
