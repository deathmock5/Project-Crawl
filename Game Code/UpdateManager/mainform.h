#pragma once

#include <tchar.h>
#include <direct.h>
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
#include <wininet.h>
#pragma comment(lib,"Wininet.lib")
#include "ManifistOBJ.h"
#include "DMManifest.h"
#include "UpdateMaker.h"
#pragma warning(disable:4996) 
using namespace System::Runtime::InteropServices;
//TODO: actuly download the files.
//TODO: create a temp folder
//TODO: delete the temp folder.
namespace UpdateManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	/// <summary>
	/// The main form of the updater.
	/// </summary>
	public ref class mainform : public System::Windows::Forms::Form
	{
	public:
		mainform(void)
		{
			
			InitializeComponent();
			//
			//Add the constructor code here
			//
			manifestset = new DMManifest();
			startmethod();
		}
		void startmethod();
		void updateMethod();
		void _DownloadFileCompleted(System::Object ^sender, AsyncCompletedEventArgs ^e)
		{
			// File download completed
			MessageBox::Show("DONE!");
		}

		// Occurs when an asynchronous download operation successfully transfers some or all of the data.
		void _DownloadProgressChanged(System::Object ^sender, System::Net::DownloadProgressChangedEventArgs ^e)
		{
			// Update progress bar
			downloadprogress->Value = e->ProgressPercentage;
		}
		
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~mainform()
		{
			if (components)
			{
				delete components;
			}
			//delete manifestset;
		}
	private: DMManifest* updatemanifest;
	private: DMManifest* manifestset;
	private: System::Windows::Forms::Label^  statuslabel;
	private: System::Windows::Forms::ProgressBar^  downloadprogress;
	private: System::Windows::Forms::ProgressBar^  totalprogress;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(mainform::typeid));
			this->statuslabel = (gcnew System::Windows::Forms::Label());
			this->downloadprogress = (gcnew System::Windows::Forms::ProgressBar());
			this->totalprogress = (gcnew System::Windows::Forms::ProgressBar());
			this->SuspendLayout();
			// 
			// statuslabel
			// 
			this->statuslabel->AutoSize = true;
			this->statuslabel->Location = System::Drawing::Point(372, 9);
			this->statuslabel->Name = L"statuslabel";
			this->statuslabel->Size = System::Drawing::Size(48, 17);
			this->statuslabel->TabIndex = 0;
			this->statuslabel->Text = L"Status";
			this->statuslabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// downloadprogress
			// 
			this->downloadprogress->Location = System::Drawing::Point(15, 29);
			this->downloadprogress->Name = L"downloadprogress";
			this->downloadprogress->Size = System::Drawing::Size(763, 23);
			this->downloadprogress->TabIndex = 11;
			// 
			// totalprogress
			// 
			this->totalprogress->Location = System::Drawing::Point(15, 58);
			this->totalprogress->Name = L"totalprogress";
			this->totalprogress->Size = System::Drawing::Size(763, 41);
			this->totalprogress->TabIndex = 12;
			// 
			// mainform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(792, 111);
			this->Controls->Add(this->totalprogress);
			this->Controls->Add(this->downloadprogress);
			this->Controls->Add(this->statuslabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->HelpButton = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"mainform";
			this->Text = L"DMUpdater";
			this->HelpButtonClicked += gcnew System::ComponentModel::CancelEventHandler(this, &mainform::mainform_HelpButtonClicked);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 ManifistOBJ newobj;
				 //newobj.setFilename((char*)(void*)Marshal::StringToHGlobalAnsi(textBox1->Text));
				 DMVersion newversion;
				 //newversion.setMajorVersion(Decimal::ToInt32(numericUpDown1->Value));
				 //newversion.setMinorVersion(Decimal::ToInt32(numericUpDown2->Value));
				 //newversion.setBugFixes(Decimal::ToInt32(numericUpDown2->Value));
				 //newversion.setBuildNumber(Decimal::ToInt32(numericUpDown2->Value));
				 newobj.setVersion(newversion);
				 manifestset->addManifistObj(newobj);
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 manifestset->writeToFile("FileUpdate.DMManifest");
			 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 manifestset->readFromFile("FileUpdate.DMManifest");
			 for(int i =0;i < (int)manifestset->getManifistList().size();i++)
			 {
				 ManifistOBJ temp = manifestset->getManifistList()[i];
				 String^ cAddress =  gcnew String(temp.getFilename());
				 //listBox1->Items->Add(cAddress);
			 }
		 }
private: System::Void mainform_HelpButtonClicked(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			UpdateMaker^ myform = gcnew UpdateMaker();
			myform->Show();
		 }
};
	void mainform::startmethod()
	{
		//HRESULT hr;
		LPCWSTR url = L"http://www.google.com";
		System::Net::WebClient ^_WebClient = gcnew System::Net::WebClient();
		_WebClient->DownloadFileCompleted += gcnew AsyncCompletedEventHandler(this, &mainform::_DownloadFileCompleted);
		_WebClient->DownloadProgressChanged += gcnew System::Net::DownloadProgressChangedEventHandler(this, &mainform::_DownloadProgressChanged);
		//TODO: Create the starting method.
		//Do verification code here
		//check for internet
		bool bConnect = false;
		if(InternetCheckConnection(url, FLAG_ICC_FORCE_CONNECTION, 0) == TRUE)
		{
			bConnect = true;
		}
		if (bConnect)
		{
			//internet connection exists !
			statuslabel->Text = "Connected!";
			//ping server to get version
			_mkdir("c:\\DMUPDATETEMP");
			statuslabel->Text = "Downloading file: RemoteManifest.DMManifest";
			//_WebClient->DownloadFileAsync(gcnew Uri("www.deathmock.zxq.net/RemoteManifest.DMManifest"), "c:\\DMUPDATETEMP\\test.jpg");
			//compare versions
			statuslabel->Text = "Compareing versions";
			//is diffrent
				//Update()
			//display:launchgame
				//Game.exe -verification code
			//display:edit game
				//editer.exe -verification code
		}
		else
		{
			statuslabel->Text = "Not Connected!";
			//internet connection DOES NOT exists !
		}
		
	}

	void mainform::updateMethod()
	{
		//TODO: Create the update method.
		manifestset->readFromFile("c:\\DMUPDATETEMP\\FileUpdate.DMManifest");
		//load up my version map
		//compare
		//build list of changes
		//for each change
			//download new file
			//check hash
			//replace old
			//update myversionmap
			//remove change from list
		//delete c:\\DMUPDATETEMP
	}
}
