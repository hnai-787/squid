#pragma once
#include "TeamLogoManager.h"
#include <string>
#include <msclr/marshal_cppstd.h>
#include "Scheduler.h"
#include "Team.h"
#include <Windows.h>

namespace CompetitionScheduler {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

    /// <summary>
    /// Summary for TeamForm
    /// </summary>
    public ref class TeamForm : public System::Windows::Forms::Form
    {
    public:
		String^ TeamFilePath = Application::StartupPath + "\\Teams.txt";
        Scheduler* scheduler;

        TeamForm(Scheduler* scheduler)
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
        ~TeamForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Panel^ bg_pnl;
    protected:
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::TextBox^ teamFilePath;
    private: System::Windows::Forms::Button^ browse_btn;
    private: System::Windows::Forms::Button^ openTeamFile_btn;
    private: System::Windows::Forms::Button^ loadTeam_btn;
    private: System::Windows::Forms::DataGridView^ teamDataGrid;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ TeamNo;
    private: System::Windows::Forms::DataGridViewImageColumn^ TeamLogo;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ TeamName;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ TeamMembers;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ TeamRank;

    protected:
        // Function to load data from teamFile and store it in schedule class
		void LoadTeamsFromFile(String^ teamFilePath) {
			// Read the file and display it line by line.
			StreamReader^ file = gcnew StreamReader(teamFilePath);
			String^ line;
			vector<Team*> teams;
			int teamNo = 1;
			while ((line = file->ReadLine()) != nullptr) {
				cli::array<String^>^ teamData = line->Split(',');
				String^ teamName = teamData[0];
                cli::array<String^>^ members = teamData[1]->Split(';');
				int rank = Convert::ToInt32(teamData[2]);
				vector<string> membersList;
				for each (String ^ member in members) {
					membersList.push_back(msclr::interop::marshal_as<string>(member));
				}
				teams.push_back(new Team(teamNo++ ,msclr::interop::marshal_as<string>(teamName), membersList, rank));
			}
			scheduler->addTeams(teams);
			file->Close();
		}

		// Function to display teams in the DataGridView
		void DisplayTeams() {
			teamDataGrid->Rows->Clear();
			int teamNo = 1;
			for each (Team * team in scheduler->getTeams()) {
				teamDataGrid->Rows->Add(teamNo, TeamLogoManager::GetTeamLogo(teamNo), gcnew String(team->getTeamName().c_str()), gcnew String(team->getMembers().c_str()), team->getRank());
				teamNo++;
			}
		}

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
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            this->bg_pnl = (gcnew System::Windows::Forms::Panel());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->teamFilePath = (gcnew System::Windows::Forms::TextBox());
            this->browse_btn = (gcnew System::Windows::Forms::Button());
            this->openTeamFile_btn = (gcnew System::Windows::Forms::Button());
            this->loadTeam_btn = (gcnew System::Windows::Forms::Button());
            this->teamDataGrid = (gcnew System::Windows::Forms::DataGridView());
            this->TeamNo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->TeamLogo = (gcnew System::Windows::Forms::DataGridViewImageColumn());
            this->TeamName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->TeamMembers = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->TeamRank = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->bg_pnl->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->teamDataGrid))->BeginInit();
            this->SuspendLayout();
            // 
            // bg_pnl
            // 
            this->bg_pnl->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(30)));
            this->bg_pnl->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->bg_pnl->Controls->Add(this->label1);
            this->bg_pnl->Controls->Add(this->teamFilePath);
            this->bg_pnl->Controls->Add(this->browse_btn);
            this->bg_pnl->Controls->Add(this->openTeamFile_btn);
            this->bg_pnl->Controls->Add(this->loadTeam_btn);
            this->bg_pnl->Dock = System::Windows::Forms::DockStyle::Top;
            this->bg_pnl->Location = System::Drawing::Point(0, 0);
            this->bg_pnl->Name = L"bg_pnl";
            this->bg_pnl->Size = System::Drawing::Size(1025, 90);
            this->bg_pnl->TabIndex = 10;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Small", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->ForeColor = System::Drawing::SystemColors::Control;
            this->label1->Location = System::Drawing::Point(334, 10);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(120, 22);
            this->label1->TabIndex = 5;
            this->label1->Text = L"Team File Path";
            // 
            // teamFilePath
            // 
            this->teamFilePath->Cursor = System::Windows::Forms::Cursors::No;
            this->teamFilePath->Location = System::Drawing::Point(334, 34);
            this->teamFilePath->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->teamFilePath->Name = L"teamFilePath";
            this->teamFilePath->ReadOnly = true;
            this->teamFilePath->Size = System::Drawing::Size(523, 34);
            this->teamFilePath->TabIndex = 4;
            this->teamFilePath->TextChanged += gcnew System::EventHandler(this, &TeamForm::teamFilePath_TextChanged);
            // 
            // browse_btn
            // 
            this->browse_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(221)),
                static_cast<System::Int32>(static_cast<System::Byte>(171)));
            this->browse_btn->Cursor = System::Windows::Forms::Cursors::Hand;
            this->browse_btn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)));
            this->browse_btn->FlatAppearance->BorderSize = 0;
            this->browse_btn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(254)));
            this->browse_btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(221)),
                static_cast<System::Int32>(static_cast<System::Byte>(126)), static_cast<System::Int32>(static_cast<System::Byte>(254)));
            this->browse_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->browse_btn->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Small Semibol", 10.2F, System::Drawing::FontStyle::Bold,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->browse_btn->Location = System::Drawing::Point(863, 18);
            this->browse_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->browse_btn->Name = L"browse_btn";
            this->browse_btn->Size = System::Drawing::Size(150, 50);
            this->browse_btn->TabIndex = 3;
            this->browse_btn->Text = L"Browse";
            this->browse_btn->UseVisualStyleBackColor = false;
            this->browse_btn->Click += gcnew System::EventHandler(this, &TeamForm::browse_btn_Click);
            // 
            // openTeamFile_btn
            // 
            this->openTeamFile_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(221)),
                static_cast<System::Int32>(static_cast<System::Byte>(171)));
            this->openTeamFile_btn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)));
            this->openTeamFile_btn->FlatAppearance->BorderSize = 0;
            this->openTeamFile_btn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(254)));
            this->openTeamFile_btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(221)),
                static_cast<System::Int32>(static_cast<System::Byte>(126)), static_cast<System::Int32>(static_cast<System::Byte>(254)));
            this->openTeamFile_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->openTeamFile_btn->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Small Semibol", 10.2F, System::Drawing::FontStyle::Bold,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->openTeamFile_btn->Location = System::Drawing::Point(178, 18);
            this->openTeamFile_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->openTeamFile_btn->Name = L"openTeamFile_btn";
            this->openTeamFile_btn->Size = System::Drawing::Size(150, 50);
            this->openTeamFile_btn->TabIndex = 1;
            this->openTeamFile_btn->Text = L"Open Team File";
            this->openTeamFile_btn->UseVisualStyleBackColor = false;
            this->openTeamFile_btn->Click += gcnew System::EventHandler(this, &TeamForm::openTeamFile_btn_Click);
            // 
            // loadTeam_btn
            // 
            this->loadTeam_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(221)),
                static_cast<System::Int32>(static_cast<System::Byte>(171)));
            this->loadTeam_btn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)));
            this->loadTeam_btn->FlatAppearance->BorderSize = 0;
            this->loadTeam_btn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(254)));
            this->loadTeam_btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(221)),
                static_cast<System::Int32>(static_cast<System::Byte>(126)), static_cast<System::Int32>(static_cast<System::Byte>(254)));
            this->loadTeam_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->loadTeam_btn->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Small Semibol", 10.2F, System::Drawing::FontStyle::Bold,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->loadTeam_btn->Location = System::Drawing::Point(12, 18);
            this->loadTeam_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->loadTeam_btn->Name = L"loadTeam_btn";
            this->loadTeam_btn->Size = System::Drawing::Size(150, 50);
            this->loadTeam_btn->TabIndex = 1;
            this->loadTeam_btn->Text = L"Load Teams";
            this->loadTeam_btn->UseVisualStyleBackColor = false;
            this->loadTeam_btn->Click += gcnew System::EventHandler(this, &TeamForm::loadTeam_btn_Click);
            // 
            // teamDataGrid
            // 
            this->teamDataGrid->AllowUserToAddRows = false;
            this->teamDataGrid->AllowUserToDeleteRows = false;
            this->teamDataGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->teamDataGrid->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)));
            dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
            dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display", 12, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
            dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
            dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->teamDataGrid->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
            this->teamDataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->teamDataGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
                this->TeamNo,
                    this->TeamLogo, this->TeamName, this->TeamMembers, this->TeamRank
            });
            this->teamDataGrid->Dock = System::Windows::Forms::DockStyle::Fill;
            this->teamDataGrid->Location = System::Drawing::Point(0, 90);
            this->teamDataGrid->MultiSelect = false;
            this->teamDataGrid->Name = L"teamDataGrid";
            this->teamDataGrid->ReadOnly = true;
            dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle6->BackColor = System::Drawing::SystemColors::Control;
            dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display", 12, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            dataGridViewCellStyle6->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle6->SelectionBackColor = System::Drawing::SystemColors::Highlight;
            dataGridViewCellStyle6->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
            dataGridViewCellStyle6->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->teamDataGrid->RowHeadersDefaultCellStyle = dataGridViewCellStyle6;
            this->teamDataGrid->RowHeadersVisible = false;
            this->teamDataGrid->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToDisplayedHeaders;
            this->teamDataGrid->RowTemplate->DefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            this->teamDataGrid->RowTemplate->DefaultCellStyle->Padding = System::Windows::Forms::Padding(1);
            this->teamDataGrid->RowTemplate->DefaultCellStyle->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->teamDataGrid->RowTemplate->Height = 75;
            this->teamDataGrid->Size = System::Drawing::Size(1025, 562);
            this->teamDataGrid->TabIndex = 11;
            // 
            // TeamNo
            // 
            this->TeamNo->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
            dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            this->TeamNo->DefaultCellStyle = dataGridViewCellStyle2;
            this->TeamNo->HeaderText = L"Team No.";
            this->TeamNo->MinimumWidth = 6;
            this->TeamNo->Name = L"TeamNo";
            this->TeamNo->ReadOnly = true;
            this->TeamNo->Width = 122;
            // 
            // TeamLogo
            // 
            this->TeamLogo->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
            this->TeamLogo->HeaderText = L"Team Logo";
            this->TeamLogo->MinimumWidth = 6;
            this->TeamLogo->Name = L"TeamLogo";
            this->TeamLogo->ReadOnly = true;
            this->TeamLogo->Width = 113;
            // 
            // TeamName
            // 
            this->TeamName->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            this->TeamName->DefaultCellStyle = dataGridViewCellStyle3;
            this->TeamName->HeaderText = L"Team Name";
            this->TeamName->MinimumWidth = 6;
            this->TeamName->Name = L"TeamName";
            this->TeamName->ReadOnly = true;
            this->TeamName->Resizable = System::Windows::Forms::DataGridViewTriState::True;
            this->TeamName->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
            // 
            // TeamMembers
            // 
            this->TeamMembers->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            this->TeamMembers->DefaultCellStyle = dataGridViewCellStyle4;
            this->TeamMembers->HeaderText = L"Team Members";
            this->TeamMembers->MinimumWidth = 6;
            this->TeamMembers->Name = L"TeamMembers";
            this->TeamMembers->ReadOnly = true;
            this->TeamMembers->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
            // 
            // TeamRank
            // 
            this->TeamRank->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
            dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            this->TeamRank->DefaultCellStyle = dataGridViewCellStyle5;
            this->TeamRank->HeaderText = L"Team Rank";
            this->TeamRank->MinimumWidth = 6;
            this->TeamRank->Name = L"TeamRank";
            this->TeamRank->ReadOnly = true;
            this->TeamRank->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
            this->TeamRank->Width = 111;
            // 
            // TeamForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(11, 27);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(30)));
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->ClientSize = System::Drawing::Size(1025, 652);
            this->Controls->Add(this->teamDataGrid);
            this->Controls->Add(this->bg_pnl);
            this->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->MaximizeBox = false;
            this->MaximumSize = System::Drawing::Size(1025, 652);
            this->MinimizeBox = false;
            this->MinimumSize = System::Drawing::Size(1025, 652);
            this->Name = L"TeamForm";
            this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
            this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
            this->Text = L"Competition Scheduler - Team Management";
            this->Load += gcnew System::EventHandler(this, &TeamForm::TeamForm_Load);
            this->bg_pnl->ResumeLayout(false);
            this->bg_pnl->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->teamDataGrid))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion
	// Event handler for the form load event
    private: System::Void TeamForm_Load(System::Object^ sender, System::EventArgs^ e) {
        // Set team file path label to Global team file path
        teamFilePath->Text = TeamFilePath;
        DisplayTeams();  // Display the teams in the DataGridView
    }

	// Event handlers for the browse button
    private: System::Void browse_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		// Create a new instance of the OpenFileDialog
		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
		// Set the file filter to only allow .csv files
		openFileDialog->Filter = "Text Files (*.txt)|*.txt";
		// Set the initial directory to the current directory
		openFileDialog->InitialDirectory = Application::ExecutablePath;
		// Show the dialog and check if the user selected a file
        if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			// Set the text of the teamFilePath text box to the file path of the selected file
            TeamFilePath = openFileDialog->FileName;
			teamFilePath->Text = openFileDialog->FileName;
        }
    }    

	// Event handlers for the open team file button
    private: System::Void openTeamFile_btn_Click(System::Object^ sender, System::EventArgs^ e) {
        // Check if the file path is empty
        if (teamFilePath->Text->Length == 0) {
            // Show error message if the file path is empty
            MessageBox::Show("Please select a team file", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        else {
            // Open the selected team file
			System::Diagnostics::Process::Start(teamFilePath->Text);
        }
    }

	// Event handler for the load team button
    private: System::Void loadTeam_btn_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ filePath = teamFilePath->Text;  // Get the file path from the TextBox
		if (File::Exists(filePath)) {  // Check if the file exists
			LoadTeamsFromFile(filePath);  // Load teams from the file
			DisplayTeams();  // Display the teams in the DataGridView

			// Show success message
			MessageBox::Show("Teams loaded successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

			// Disable the Load Team button
			loadTeam_btn->Enabled = false;
		}
		else {
			// Show error message if the file does not exist
			MessageBox::Show("The selected file does not exist", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
    private: System::Void teamFilePath_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (teamFilePath->Text->Length > 0) {
			loadTeam_btn->Enabled = true;
		}
		else {
			loadTeam_btn->Enabled = false;
		}
    }
};
}
