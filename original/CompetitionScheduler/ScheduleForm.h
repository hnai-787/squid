#pragma once
#include "Scheduler.h"

namespace CompetitionScheduler {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for ScheduleForm
    /// </summary>
    public ref class ScheduleForm : public System::Windows::Forms::Form
    {
    public:
		Scheduler* scheduler;
    private: System::Windows::Forms::Button^ reset_btn;
    public:
        int currentRound = 0;

        ScheduleForm(Scheduler* scheduler)
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
        ~ScheduleForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::DataGridView^ scheduleDataGrid;
    protected:

    protected:





    private: System::Windows::Forms::Panel^ bg_pnl;
    private: System::Windows::Forms::Button^ nextRound_btn;
    private: System::Windows::Forms::Button^ simulateMatches_btn;



    private: System::Windows::Forms::DataGridViewTextBoxColumn^ MatchNo;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Team1;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Team2;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ DateTime;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Status;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Winner;
    private: System::Windows::Forms::Label^ round_label;

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
        void InitializeComponent(void)
        {
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            this->scheduleDataGrid = (gcnew System::Windows::Forms::DataGridView());
            this->MatchNo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->Team1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->Team2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->DateTime = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->Status = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->Winner = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->bg_pnl = (gcnew System::Windows::Forms::Panel());
            this->reset_btn = (gcnew System::Windows::Forms::Button());
            this->round_label = (gcnew System::Windows::Forms::Label());
            this->nextRound_btn = (gcnew System::Windows::Forms::Button());
            this->simulateMatches_btn = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->scheduleDataGrid))->BeginInit();
            this->bg_pnl->SuspendLayout();
            this->SuspendLayout();
            // 
            // scheduleDataGrid
            // 
            this->scheduleDataGrid->AllowUserToAddRows = false;
            this->scheduleDataGrid->AllowUserToDeleteRows = false;
            this->scheduleDataGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->scheduleDataGrid->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)));
            dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
            dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display", 12, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
            dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
            dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->scheduleDataGrid->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
            this->scheduleDataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->scheduleDataGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
                this->MatchNo,
                    this->Team1, this->Team2, this->DateTime, this->Status, this->Winner
            });
            this->scheduleDataGrid->Dock = System::Windows::Forms::DockStyle::Fill;
            this->scheduleDataGrid->Location = System::Drawing::Point(0, 90);
            this->scheduleDataGrid->MultiSelect = false;
            this->scheduleDataGrid->Name = L"scheduleDataGrid";
            this->scheduleDataGrid->ReadOnly = true;
            dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Control;
            dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display", 12, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
            dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
            dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->scheduleDataGrid->RowHeadersDefaultCellStyle = dataGridViewCellStyle2;
            this->scheduleDataGrid->RowHeadersVisible = false;
            this->scheduleDataGrid->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToDisplayedHeaders;
            this->scheduleDataGrid->RowTemplate->DefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            this->scheduleDataGrid->RowTemplate->DefaultCellStyle->Padding = System::Windows::Forms::Padding(1);
            this->scheduleDataGrid->RowTemplate->DefaultCellStyle->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->scheduleDataGrid->RowTemplate->Height = 34;
            this->scheduleDataGrid->Size = System::Drawing::Size(1025, 562);
            this->scheduleDataGrid->TabIndex = 13;
            // 
            // MatchNo
            // 
            this->MatchNo->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
            this->MatchNo->HeaderText = L"Match No.";
            this->MatchNo->MinimumWidth = 6;
            this->MatchNo->Name = L"MatchNo";
            this->MatchNo->ReadOnly = true;
            this->MatchNo->Width = 133;
            // 
            // Team1
            // 
            this->Team1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->Team1->HeaderText = L"Team 1";
            this->Team1->MinimumWidth = 6;
            this->Team1->Name = L"Team1";
            this->Team1->ReadOnly = true;
            // 
            // Team2
            // 
            this->Team2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->Team2->HeaderText = L"Team 2";
            this->Team2->MinimumWidth = 6;
            this->Team2->Name = L"Team2";
            this->Team2->ReadOnly = true;
            // 
            // DateTime
            // 
            this->DateTime->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->DateTime->HeaderText = L"Date & Time";
            this->DateTime->MinimumWidth = 6;
            this->DateTime->Name = L"DateTime";
            this->DateTime->ReadOnly = true;
            // 
            // Status
            // 
            this->Status->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->Status->HeaderText = L"Status";
            this->Status->MinimumWidth = 6;
            this->Status->Name = L"Status";
            this->Status->ReadOnly = true;
            // 
            // Winner
            // 
            this->Winner->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->Winner->HeaderText = L"Winner";
            this->Winner->MinimumWidth = 6;
            this->Winner->Name = L"Winner";
            this->Winner->ReadOnly = true;
            // 
            // bg_pnl
            // 
            this->bg_pnl->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(30)));
            this->bg_pnl->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->bg_pnl->Controls->Add(this->reset_btn);
            this->bg_pnl->Controls->Add(this->round_label);
            this->bg_pnl->Controls->Add(this->nextRound_btn);
            this->bg_pnl->Controls->Add(this->simulateMatches_btn);
            this->bg_pnl->Dock = System::Windows::Forms::DockStyle::Top;
            this->bg_pnl->Location = System::Drawing::Point(0, 0);
            this->bg_pnl->Name = L"bg_pnl";
            this->bg_pnl->Size = System::Drawing::Size(1025, 90);
            this->bg_pnl->TabIndex = 12;
            // 
            // reset_btn
            // 
            this->reset_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(221)),
                static_cast<System::Int32>(static_cast<System::Byte>(171)));
            this->reset_btn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)));
            this->reset_btn->FlatAppearance->BorderSize = 0;
            this->reset_btn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(254)));
            this->reset_btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(221)),
                static_cast<System::Int32>(static_cast<System::Byte>(126)), static_cast<System::Int32>(static_cast<System::Byte>(254)));
            this->reset_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->reset_btn->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Small Semibol", 10.2F, System::Drawing::FontStyle::Bold,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->reset_btn->Location = System::Drawing::Point(439, 18);
            this->reset_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->reset_btn->Name = L"reset_btn";
            this->reset_btn->Size = System::Drawing::Size(180, 50);
            this->reset_btn->TabIndex = 5;
            this->reset_btn->Text = L"Restart Tournament";
            this->reset_btn->UseVisualStyleBackColor = false;
            this->reset_btn->Click += gcnew System::EventHandler(this, &ScheduleForm::reset_btn_Click);
            // 
            // round_label
            // 
            this->round_label->AutoSize = true;
            this->round_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Small Semibol", 24, System::Drawing::FontStyle::Bold,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->round_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(221)),
                static_cast<System::Int32>(static_cast<System::Byte>(171)));
            this->round_label->Location = System::Drawing::Point(12, 15);
            this->round_label->Name = L"round_label";
            this->round_label->Size = System::Drawing::Size(403, 53);
            this->round_label->TabIndex = 4;
            this->round_label->Text = L"Pre-liminarry Round";
            // 
            // nextRound_btn
            // 
            this->nextRound_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(221)),
                static_cast<System::Int32>(static_cast<System::Byte>(171)));
            this->nextRound_btn->Cursor = System::Windows::Forms::Cursors::Hand;
            this->nextRound_btn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)));
            this->nextRound_btn->FlatAppearance->BorderSize = 0;
            this->nextRound_btn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(254)));
            this->nextRound_btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(221)),
                static_cast<System::Int32>(static_cast<System::Byte>(126)), static_cast<System::Int32>(static_cast<System::Byte>(254)));
            this->nextRound_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->nextRound_btn->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Small Semibol", 10.2F, System::Drawing::FontStyle::Bold,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->nextRound_btn->Location = System::Drawing::Point(853, 18);
            this->nextRound_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->nextRound_btn->Name = L"nextRound_btn";
            this->nextRound_btn->Size = System::Drawing::Size(160, 50);
            this->nextRound_btn->TabIndex = 3;
            this->nextRound_btn->Text = L"Next Round";
            this->nextRound_btn->UseVisualStyleBackColor = false;
            this->nextRound_btn->Click += gcnew System::EventHandler(this, &ScheduleForm::nextRound_btn_Click);
            // 
            // simulateMatches_btn
            // 
            this->simulateMatches_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)),
                static_cast<System::Int32>(static_cast<System::Byte>(221)), static_cast<System::Int32>(static_cast<System::Byte>(171)));
            this->simulateMatches_btn->Enabled = false;
            this->simulateMatches_btn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)));
            this->simulateMatches_btn->FlatAppearance->BorderSize = 0;
            this->simulateMatches_btn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(254)));
            this->simulateMatches_btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(221)),
                static_cast<System::Int32>(static_cast<System::Byte>(126)), static_cast<System::Int32>(static_cast<System::Byte>(254)));
            this->simulateMatches_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->simulateMatches_btn->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Small Semibol", 10.2F, System::Drawing::FontStyle::Bold,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->simulateMatches_btn->Location = System::Drawing::Point(656, 18);
            this->simulateMatches_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->simulateMatches_btn->Name = L"simulateMatches_btn";
            this->simulateMatches_btn->Size = System::Drawing::Size(160, 50);
            this->simulateMatches_btn->TabIndex = 1;
            this->simulateMatches_btn->Text = L"Simulate Matches";
            this->simulateMatches_btn->UseVisualStyleBackColor = false;
            this->simulateMatches_btn->Click += gcnew System::EventHandler(this, &ScheduleForm::simulateMatches_btn_Click);
            // 
            // ScheduleForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(11, 27);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(30)));
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->ClientSize = System::Drawing::Size(1025, 652);
            this->ControlBox = false;
            this->Controls->Add(this->scheduleDataGrid);
            this->Controls->Add(this->bg_pnl);
            this->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->MaximizeBox = false;
            this->MaximumSize = System::Drawing::Size(1025, 652);
            this->MinimizeBox = false;
            this->MinimumSize = System::Drawing::Size(1025, 652);
            this->Name = L"ScheduleForm";
            this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
            this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
            this->Text = L"Competition Scheduler - Schedule Matches";
            this->Load += gcnew System::EventHandler(this, &ScheduleForm::ScheduleForm_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->scheduleDataGrid))->EndInit();
            this->bg_pnl->ResumeLayout(false);
            this->bg_pnl->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion

    // Method to update the schedule data grid from the scheduler
    void updateSchedule() {
        scheduleDataGrid->Rows->Clear();

        int matchNo = 1;
        for (Match* match : scheduler->getMatches()) {
            String^ matchNoStr = matchNo.ToString();
            String^ team1 = gcnew String(match->getTeam1()->getTeamName().c_str());
            String^ team2 = gcnew String(match->getTeam2()->getTeamName().c_str());
            String^ dateTime = gcnew String(match->getDate().c_str());
            String^ status = match->getStatus() ? "Completed" : "Scheduled";
            String^ winner = match->getWinner() ? gcnew String(match->getWinner()->getTeamName().c_str()) : "TBD";

            cli::array<String^>^ row = { matchNoStr, team1, team2, dateTime, status, winner };
            scheduleDataGrid->Rows->Add(row);
            matchNo++;
        }
    }

    private: System::Void nextRound_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		// Check if teams are loaded before proceeding
		if (scheduler->getTeams().size() == 0) {
			MessageBox::Show("Please load teams before proceeding to next round.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Proceed to next round implementation
        currentRound++;
        if (currentRound == 1) {
            round_label->Text = "Round 1";
            scheduler->round1();
            simulateMatches_btn->Enabled = true;
        }
		else if (currentRound == 2) {
			round_label->Text = "Round 2";
			scheduler->round2();
            simulateMatches_btn->Enabled = true;
		}
		else if (currentRound == 3) {
			round_label->Text = "Semi-Final";
			scheduler->semiFinal();
            simulateMatches_btn->Enabled = true;
		}
		else if (currentRound == 4) {
			round_label->Text = "Final";
			scheduler->finalRound();
            simulateMatches_btn->Enabled = true;
		}
        else {
            MessageBox::Show("Tournament has ended. No more rounds to schedule.");
            simulateMatches_btn->Enabled = false;
        }

        nextRound_btn->Enabled = false;
		updateSchedule();
    }

    private: System::Void simulateMatches_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		scheduler->simulateMatches();
		updateSchedule();
		simulateMatches_btn->Enabled = false;
		nextRound_btn->Enabled = true;
    }

    private: System::Void ScheduleForm_Load(System::Object^ sender, System::EventArgs^ e) {
	    updateSchedule();
    }
    private: System::Void reset_btn_Click(System::Object^ sender, System::EventArgs^ e) {
        scheduler->resetTournament();
		currentRound = 0;
		round_label->Text = "Pre-liminarry Round";
		simulateMatches_btn->Enabled = false;
		nextRound_btn->Enabled = true;
		updateSchedule();
    }
};
}
