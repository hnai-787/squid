#pragma once
#include "TeamForm.h" // Include the TeamForm header file
#include "ScheduleForm.h" // Include the ScheduleForm header file
#include "SimulateForm.h" // Include the SimulateForm header file
#include "RulesForm.h" // Include the RulesForm header file
#include "TeamLogoManager.h" // Include the GlobalData header file
#include "Scheduler.h" // Include the Schedule header file
#include <Windows.h> // Include the Windows header file

namespace CompetitionScheduler {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainMenuForm
	/// </summary>
	public ref class MainMenuForm : public System::Windows::Forms::Form
	{
	public:
		// Pointer to schedule and simulation instances 
		Scheduler* scheduler;
		

		MainMenuForm(Scheduler* scheduler)
		{
			this->scheduler = scheduler;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainMenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ heading_lbl;
	protected:


	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Panel^ homebtn_pnl;
	private: System::Windows::Forms::PictureBox^ homebtn_icon;



	private: System::Windows::Forms::Button^ home_btn;
	private: System::Windows::Forms::Panel^ teambtn_pnl;
	private: System::Windows::Forms::PictureBox^ teambtn_icon;


	private: System::Windows::Forms::Button^ loadTeam_btn;
	private: System::Windows::Forms::Panel^ schedulebtn_pnl;
	private: System::Windows::Forms::PictureBox^ schedulebtn_icon;



	private: System::Windows::Forms::Button^ schedule_btn;
	private: System::Windows::Forms::Panel^ simulatebtn_pnl;
	private: System::Windows::Forms::PictureBox^ simulatebtn_icon;



	private: System::Windows::Forms::Button^ simulate_btn;
	private: System::Windows::Forms::Panel^ rulesbtn_pnl;
	private: System::Windows::Forms::PictureBox^ rulesbtn_icon;



	private: System::Windows::Forms::Button^ rule_btn;


















	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainMenuForm::typeid));
			this->heading_lbl = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->homebtn_pnl = (gcnew System::Windows::Forms::Panel());
			this->homebtn_icon = (gcnew System::Windows::Forms::PictureBox());
			this->home_btn = (gcnew System::Windows::Forms::Button());
			this->teambtn_pnl = (gcnew System::Windows::Forms::Panel());
			this->teambtn_icon = (gcnew System::Windows::Forms::PictureBox());
			this->loadTeam_btn = (gcnew System::Windows::Forms::Button());
			this->schedulebtn_pnl = (gcnew System::Windows::Forms::Panel());
			this->schedulebtn_icon = (gcnew System::Windows::Forms::PictureBox());
			this->schedule_btn = (gcnew System::Windows::Forms::Button());
			this->simulatebtn_pnl = (gcnew System::Windows::Forms::Panel());
			this->simulatebtn_icon = (gcnew System::Windows::Forms::PictureBox());
			this->simulate_btn = (gcnew System::Windows::Forms::Button());
			this->rulesbtn_pnl = (gcnew System::Windows::Forms::Panel());
			this->rulesbtn_icon = (gcnew System::Windows::Forms::PictureBox());
			this->rule_btn = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel1->SuspendLayout();
			this->homebtn_pnl->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->homebtn_icon))->BeginInit();
			this->teambtn_pnl->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->teambtn_icon))->BeginInit();
			this->schedulebtn_pnl->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->schedulebtn_icon))->BeginInit();
			this->simulatebtn_pnl->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->simulatebtn_icon))->BeginInit();
			this->rulesbtn_pnl->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rulesbtn_icon))->BeginInit();
			this->SuspendLayout();
			// 
			// heading_lbl
			// 
			this->heading_lbl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->heading_lbl->AutoSize = true;
			this->heading_lbl->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->heading_lbl->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->heading_lbl->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(221)),
				static_cast<System::Int32>(static_cast<System::Byte>(171)));
			this->heading_lbl->Location = System::Drawing::Point(2, 20);
			this->heading_lbl->Margin = System::Windows::Forms::Padding(2, 20, 2, 50);
			this->heading_lbl->Name = L"heading_lbl";
			this->heading_lbl->Padding = System::Windows::Forms::Padding(25, 0, 0, 0);
			this->heading_lbl->Size = System::Drawing::Size(246, 44);
			this->heading_lbl->TabIndex = 1;
			this->heading_lbl->Text = L"HOME";
			this->heading_lbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->heading_lbl);
			this->flowLayoutPanel1->Controls->Add(this->homebtn_pnl);
			this->flowLayoutPanel1->Controls->Add(this->teambtn_pnl);
			this->flowLayoutPanel1->Controls->Add(this->schedulebtn_pnl);
			this->flowLayoutPanel1->Controls->Add(this->simulatebtn_pnl);
			this->flowLayoutPanel1->Controls->Add(this->rulesbtn_pnl);
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->flowLayoutPanel1->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(2);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(250, 649);
			this->flowLayoutPanel1->TabIndex = 6;
			// 
			// homebtn_pnl
			// 
			this->homebtn_pnl->Controls->Add(this->homebtn_icon);
			this->homebtn_pnl->Controls->Add(this->home_btn);
			this->homebtn_pnl->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Small Semibol", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->homebtn_pnl->Location = System::Drawing::Point(5, 119);
			this->homebtn_pnl->Margin = System::Windows::Forms::Padding(5);
			this->homebtn_pnl->Name = L"homebtn_pnl";
			this->homebtn_pnl->Padding = System::Windows::Forms::Padding(0, 0, 5, 0);
			this->homebtn_pnl->Size = System::Drawing::Size(240, 50);
			this->homebtn_pnl->TabIndex = 7;
			// 
			// homebtn_icon
			// 
			this->homebtn_icon->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"homebtn_icon.BackgroundImage")));
			this->homebtn_icon->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->homebtn_icon->ImageLocation = L"";
			this->homebtn_icon->Location = System::Drawing::Point(0, 0);
			this->homebtn_icon->Name = L"homebtn_icon";
			this->homebtn_icon->Size = System::Drawing::Size(50, 50);
			this->homebtn_icon->TabIndex = 4;
			this->homebtn_icon->TabStop = false;
			// 
			// home_btn
			// 
			this->home_btn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->home_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->home_btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->home_btn->FlatAppearance->BorderSize = 0;
			this->home_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->home_btn->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->home_btn->ForeColor = System::Drawing::SystemColors::Control;
			this->home_btn->Location = System::Drawing::Point(50, 0);
			this->home_btn->Margin = System::Windows::Forms::Padding(2);
			this->home_btn->Name = L"home_btn";
			this->home_btn->Size = System::Drawing::Size(185, 50);
			this->home_btn->TabIndex = 3;
			this->home_btn->Text = L"Home";
			this->home_btn->UseVisualStyleBackColor = false;
			this->home_btn->Click += gcnew System::EventHandler(this, &MainMenuForm::home_btn_Click);
			// 
			// teambtn_pnl
			// 
			this->teambtn_pnl->Controls->Add(this->teambtn_icon);
			this->teambtn_pnl->Controls->Add(this->loadTeam_btn);
			this->teambtn_pnl->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Small Semibol", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->teambtn_pnl->Location = System::Drawing::Point(5, 179);
			this->teambtn_pnl->Margin = System::Windows::Forms::Padding(5);
			this->teambtn_pnl->Name = L"teambtn_pnl";
			this->teambtn_pnl->Padding = System::Windows::Forms::Padding(0, 0, 5, 0);
			this->teambtn_pnl->Size = System::Drawing::Size(240, 50);
			this->teambtn_pnl->TabIndex = 8;
			// 
			// teambtn_icon
			// 
			this->teambtn_icon->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"teambtn_icon.BackgroundImage")));
			this->teambtn_icon->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->teambtn_icon->Location = System::Drawing::Point(0, 0);
			this->teambtn_icon->Name = L"teambtn_icon";
			this->teambtn_icon->Size = System::Drawing::Size(50, 50);
			this->teambtn_icon->TabIndex = 4;
			this->teambtn_icon->TabStop = false;
			// 
			// loadTeam_btn
			// 
			this->loadTeam_btn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->loadTeam_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->loadTeam_btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->loadTeam_btn->FlatAppearance->BorderSize = 0;
			this->loadTeam_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->loadTeam_btn->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->loadTeam_btn->ForeColor = System::Drawing::SystemColors::Control;
			this->loadTeam_btn->Location = System::Drawing::Point(50, 0);
			this->loadTeam_btn->Margin = System::Windows::Forms::Padding(2);
			this->loadTeam_btn->Name = L"loadTeam_btn";
			this->loadTeam_btn->Size = System::Drawing::Size(185, 50);
			this->loadTeam_btn->TabIndex = 3;
			this->loadTeam_btn->Text = L"Load Teams";
			this->loadTeam_btn->UseVisualStyleBackColor = false;
			this->loadTeam_btn->Click += gcnew System::EventHandler(this, &MainMenuForm::loadTeam_btn_Click);
			// 
			// schedulebtn_pnl
			// 
			this->schedulebtn_pnl->Controls->Add(this->schedulebtn_icon);
			this->schedulebtn_pnl->Controls->Add(this->schedule_btn);
			this->schedulebtn_pnl->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Small Semibol", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->schedulebtn_pnl->Location = System::Drawing::Point(5, 239);
			this->schedulebtn_pnl->Margin = System::Windows::Forms::Padding(5);
			this->schedulebtn_pnl->Name = L"schedulebtn_pnl";
			this->schedulebtn_pnl->Padding = System::Windows::Forms::Padding(0, 0, 5, 0);
			this->schedulebtn_pnl->Size = System::Drawing::Size(240, 50);
			this->schedulebtn_pnl->TabIndex = 9;
			// 
			// schedulebtn_icon
			// 
			this->schedulebtn_icon->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"schedulebtn_icon.BackgroundImage")));
			this->schedulebtn_icon->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->schedulebtn_icon->Location = System::Drawing::Point(0, 0);
			this->schedulebtn_icon->Name = L"schedulebtn_icon";
			this->schedulebtn_icon->Size = System::Drawing::Size(50, 50);
			this->schedulebtn_icon->TabIndex = 4;
			this->schedulebtn_icon->TabStop = false;
			// 
			// schedule_btn
			// 
			this->schedule_btn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->schedule_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->schedule_btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->schedule_btn->FlatAppearance->BorderSize = 0;
			this->schedule_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->schedule_btn->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->schedule_btn->ForeColor = System::Drawing::SystemColors::Control;
			this->schedule_btn->Location = System::Drawing::Point(50, 0);
			this->schedule_btn->Margin = System::Windows::Forms::Padding(2);
			this->schedule_btn->Name = L"schedule_btn";
			this->schedule_btn->Size = System::Drawing::Size(185, 50);
			this->schedule_btn->TabIndex = 3;
			this->schedule_btn->Text = L"View Schedule";
			this->schedule_btn->UseVisualStyleBackColor = false;
			this->schedule_btn->Click += gcnew System::EventHandler(this, &MainMenuForm::schedule_btn_Click);
			// 
			// simulatebtn_pnl
			// 
			this->simulatebtn_pnl->Controls->Add(this->simulatebtn_icon);
			this->simulatebtn_pnl->Controls->Add(this->simulate_btn);
			this->simulatebtn_pnl->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Small Semibol", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->simulatebtn_pnl->Location = System::Drawing::Point(5, 299);
			this->simulatebtn_pnl->Margin = System::Windows::Forms::Padding(5);
			this->simulatebtn_pnl->Name = L"simulatebtn_pnl";
			this->simulatebtn_pnl->Padding = System::Windows::Forms::Padding(0, 0, 5, 0);
			this->simulatebtn_pnl->Size = System::Drawing::Size(240, 50);
			this->simulatebtn_pnl->TabIndex = 10;
			// 
			// simulatebtn_icon
			// 
			this->simulatebtn_icon->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"simulatebtn_icon.BackgroundImage")));
			this->simulatebtn_icon->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->simulatebtn_icon->Location = System::Drawing::Point(0, 0);
			this->simulatebtn_icon->Name = L"simulatebtn_icon";
			this->simulatebtn_icon->Size = System::Drawing::Size(50, 50);
			this->simulatebtn_icon->TabIndex = 4;
			this->simulatebtn_icon->TabStop = false;
			// 
			// simulate_btn
			// 
			this->simulate_btn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->simulate_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->simulate_btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->simulate_btn->FlatAppearance->BorderSize = 0;
			this->simulate_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->simulate_btn->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->simulate_btn->ForeColor = System::Drawing::SystemColors::Control;
			this->simulate_btn->Location = System::Drawing::Point(50, 0);
			this->simulate_btn->Margin = System::Windows::Forms::Padding(2);
			this->simulate_btn->Name = L"simulate_btn";
			this->simulate_btn->Size = System::Drawing::Size(185, 50);
			this->simulate_btn->TabIndex = 3;
			this->simulate_btn->Text = L"Simulate Matches";
			this->simulate_btn->UseVisualStyleBackColor = false;
			this->simulate_btn->Click += gcnew System::EventHandler(this, &MainMenuForm::simulate_btn_Click);
			// 
			// rulesbtn_pnl
			// 
			this->rulesbtn_pnl->Controls->Add(this->rulesbtn_icon);
			this->rulesbtn_pnl->Controls->Add(this->rule_btn);
			this->rulesbtn_pnl->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Small Semibol", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->rulesbtn_pnl->Location = System::Drawing::Point(5, 359);
			this->rulesbtn_pnl->Margin = System::Windows::Forms::Padding(5);
			this->rulesbtn_pnl->Name = L"rulesbtn_pnl";
			this->rulesbtn_pnl->Padding = System::Windows::Forms::Padding(0, 0, 5, 0);
			this->rulesbtn_pnl->Size = System::Drawing::Size(240, 50);
			this->rulesbtn_pnl->TabIndex = 11;
			// 
			// rulesbtn_icon
			// 
			this->rulesbtn_icon->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"rulesbtn_icon.BackgroundImage")));
			this->rulesbtn_icon->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->rulesbtn_icon->Location = System::Drawing::Point(0, 0);
			this->rulesbtn_icon->Name = L"rulesbtn_icon";
			this->rulesbtn_icon->Size = System::Drawing::Size(50, 50);
			this->rulesbtn_icon->TabIndex = 4;
			this->rulesbtn_icon->TabStop = false;
			// 
			// rule_btn
			// 
			this->rule_btn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->rule_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->rule_btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->rule_btn->FlatAppearance->BorderSize = 0;
			this->rule_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->rule_btn->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rule_btn->ForeColor = System::Drawing::SystemColors::Control;
			this->rule_btn->Location = System::Drawing::Point(50, 0);
			this->rule_btn->Margin = System::Windows::Forms::Padding(2);
			this->rule_btn->Name = L"rule_btn";
			this->rule_btn->Size = System::Drawing::Size(185, 50);
			this->rule_btn->TabIndex = 3;
			this->rule_btn->Text = L"Tornament Rules";
			this->rule_btn->UseVisualStyleBackColor = false;
			this->rule_btn->Click += gcnew System::EventHandler(this, &MainMenuForm::rule_btn_Click);
			// 
			// MainMenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 27);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1278, 649);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->IsMdiContainer = true;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1300, 700);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(1300, 700);
			this->Name = L"MainMenuForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Competition Scheduler";
			this->Load += gcnew System::EventHandler(this, &MainMenuForm::MainMenuForm_Load);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->homebtn_pnl->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->homebtn_icon))->EndInit();
			this->teambtn_pnl->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->teambtn_icon))->EndInit();
			this->schedulebtn_pnl->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->schedulebtn_icon))->EndInit();
			this->simulatebtn_pnl->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->simulatebtn_icon))->EndInit();
			this->rulesbtn_pnl->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rulesbtn_icon))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	// Event handler for the home button
	private: System::Void home_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		// Close all the child forms in the MainMenuForm
		for each (Form ^ form in this->MdiChildren)
		{
			form->Close();
		}
		// Change heading label to Home
		heading_lbl->Text = "HOME";
	}
	// Event handler for the load team button
	private: System::Void loadTeam_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		// Create a new instance of the TeamForm
		TeamForm^ teamForm = gcnew TeamForm(&(*scheduler));
		// Set the parent form of the TeamForm to the MainMenuForm
		teamForm->MdiParent = this;
		// Display the TeamForm
		teamForm->Show();
		// Change heading label to Load Teams
		heading_lbl->Text = "LOAD TEAMS";
	}
	// Event handler for the schedule button
	private: System::Void schedule_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		// Create a new instance of the ScheduleForm
		ScheduleForm^ scheduleForm = gcnew ScheduleForm(&(*scheduler));
		// Set the parent form of the ScheduleForm to the MainMenuForm
		scheduleForm->MdiParent = this;
		// Display the ScheduleForm
		scheduleForm->Show();
		// Change heading label to View Schedule
		heading_lbl->Text = "VIEW SCHEDULE";
	}
	// Event handler for the simulate button
	private: System::Void simulate_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		// Create a new instance of the SimulateForm
		SimulateForm^ simulateForm = gcnew SimulateForm(&(*scheduler));
		// Set the parent form of the SimulateForm to the MainMenuForm
		simulateForm->MdiParent = this;
		// Display the SimulateForm
		simulateForm->Show();
		// Change heading label to Simulate Matches
		heading_lbl->Text = "SIMULATE MATCHES";
	}
	// Event handler for the rule button
	private: System::Void rule_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		// Create a new instance of the RulesForm
		RulesForm^ rulesForm = gcnew RulesForm();
		// Set the parent form of the RulesForm to the MainMenuForm
		rulesForm->MdiParent = this;
		// Display the RulesForm
		rulesForm->Show();
		// Change heading label to Tournament Rules
		heading_lbl->Text = "TOURNAMENT RULES";
	}
	private: System::Void MainMenuForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
