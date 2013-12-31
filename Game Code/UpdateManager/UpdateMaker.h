#pragma once
#include "DMManifest.h"
#include "DMVersion.h"
#include "ManifistOBJ.h"
#include <stdlib.h>
#include <string.h>
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include <iostream>
//TODO: upload the update to the server
namespace UpdateManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for UpdateMaker
	/// </summary>
	public ref class UpdateMaker : public System::Windows::Forms::Form
	{
	public:
		UpdateMaker(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			newversions = new DMManifest();
			oldversions = new DMManifest();
			std::ifstream filestream = std::ifstream("FileUpdate.DMManifest");
			if(filestream)
			{
				filestream.close();//close it so i can reopen it to process.
				//Lets load in the data.
				oldversions->readFromFile("FileUpdate.DMManifest");
				//Oldversions should now be populated lets populate the listbox.
				for(int i = 0;i < (int)oldversions->getManifistList().size();i++)
				{
					ManifistOBJ temp = oldversions->getManifistList()[i];
					String^ cAddress =  gcnew String(temp.getFilename());
					listBox1->Items->Add(cAddress);
				}
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		DMManifest* newversions;
		DMManifest* oldversions;
		~UpdateMaker()
		{
			if (components)
			{
				delete components;
			}
			delete newversions;
			delete oldversions;
		}
	private: System::Windows::Forms::ListBox^  listBox1;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ListBox^  listBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown3;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown4;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;

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
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown4))->BeginInit();
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(12, 146);
			this->listBox1->Name = L"listBox1";
			this->listBox1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->listBox1->Size = System::Drawing::Size(328, 356);
			this->listBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 126);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"CurrentFiles";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(346, 126);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(64, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Changes";
			// 
			// listBox2
			// 
			this->listBox2->AllowDrop = true;
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 16;
			this->listBox2->Location = System::Drawing::Point(346, 146);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(328, 356);
			this->listBox2->TabIndex = 2;
			this->listBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &UpdateMaker::listBox2_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(86, 82);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(43, 17);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Major";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 32);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(71, 17);
			this->label4->TabIndex = 5;
			this->label4->Text = L"File Name";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 59);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(60, 17);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Version:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(188, 82);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(33, 17);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Bug";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(137, 82);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(43, 17);
			this->label7->TabIndex = 8;
			this->label7->Text = L"Minor";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(89, 29);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(585, 22);
			this->textBox1->TabIndex = 9;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(89, 57);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(45, 22);
			this->numericUpDown1->TabIndex = 10;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(140, 57);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(45, 22);
			this->numericUpDown2->TabIndex = 11;
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(191, 57);
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(45, 22);
			this->numericUpDown3->TabIndex = 12;
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->Location = System::Drawing::Point(242, 57);
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(45, 22);
			this->numericUpDown4->TabIndex = 13;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(239, 82);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(39, 17);
			this->label8->TabIndex = 14;
			this->label8->Text = L"Build";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(349, 508);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(325, 23);
			this->button1->TabIndex = 15;
			this->button1->Text = L"Delete Selection";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &UpdateMaker::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 508);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(328, 23);
			this->button2->TabIndex = 16;
			this->button2->Text = L"Delete Selection";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &UpdateMaker::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(561, 53);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(113, 46);
			this->button3->TabIndex = 17;
			this->button3->Text = L"Make Update .DMManifest";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &UpdateMaker::button3_Click);
			// 
			// UpdateMaker
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(686, 542);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->numericUpDown4);
			this->Controls->Add(this->numericUpDown3);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listBox1);
			this->Name = L"UpdateMaker";
			this->Text = L"UpdateMaker";
			this->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &UpdateMaker::UpdateMaker_DragEnter);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void UpdateMaker_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
			 System::Array^ myarray = (Array^)e->Data->GetData(DataFormats::FileDrop);
				if (myarray->Length != 0)
				{
					for(int i = 0; i < myarray->Length;i++)
					{
						String^ s = myarray->GetValue(i)->ToString()->Substring(myarray->GetValue(i)->ToString()->LastIndexOf("\\") + 1);
						listBox2->Items->Add(s);
						delete s;
					}
					// Extract string from first array element
					// (ignore all files except first if number of files are dropped).
					
					
				 }

		 }
private: System::Void listBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				// Get the currently selected item in the ListBox.
			 if(listBox2->SelectedIndex != -1)
			 {
				String^ curItem = listBox2->SelectedItem->ToString();
				// Find the string in ListBox2. 
				int index = listBox1->FindString(curItem);
				// If the item was not found in ListBox 2 display a message box, otherwise select it in ListBox2. 
				if(index != -1)
					listBox1->SetSelected(index,true);				
			 }
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			  //remove from box2
			 if(listBox2->SelectedIndex != -1)
			 {
				listBox2->Items->Remove(listBox2->SelectedItem);
			 }
			
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 //remove from box 1
			 if(listBox1->SelectedIndex != -1)
			 {
				listBox1->Items->Remove(listBox1->SelectedItem);
			 }
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 char *cstr;
			 for(int i =0;i< listBox2->Items->Count;i++)
			 {
				 ManifistOBJ newobj = ManifistOBJ();
				 DMVersion newversion = DMVersion();
				 System::String^ temp = listBox2->Items[i]->ToString(); 
				 std::string temp1 = msclr::interop::marshal_as< std::string >( temp );
				 cstr = new char[temp1.length() + 1];
				 strcpy(cstr, temp1.c_str());
				 newobj.setFilename(cstr);

				 int isthereaprevius = listBox1->FindString(temp);
				 if(isthereaprevius != -1)
				 {
					 //there was a previus version incriment the old version.
					 newversion = ++oldversions->getManifistList()[i].getVersion();
				 }
				 else
				 {
					 //there wasent a previus version set defaults.
					 newversion.setMajorVersion(1);
					 newversion.setMinorVersion(0);
					 newversion.setBugFixes(0);
					 newversion.setBuildNumber(0);
				 }
				 //set the version of this new object.
				 newobj.setVersion(newversion);
				 //add it to the list
				 newversions->addManifistObj(newobj);
				 
				 // do stuff
				 
			 }
			 //all objects added to the list, LETS WRITE A FILE!
			 newversions->writeToFile("FileUpdate.DMManifest");
			 //files written, lets clear the newversions list.
			 newversions->clearList();
			 delete [] cstr;
		 }
};
}
