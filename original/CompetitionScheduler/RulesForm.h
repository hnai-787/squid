#pragma once

namespace CompetitionScheduler {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for RulesForm
    /// </summary>
    public ref class RulesForm : public System::Windows::Forms::Form
    {
    public:
        RulesForm(void)
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
        ~RulesForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::RichTextBox^ rules_rtb;
    protected:

    protected:

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
            this->rules_rtb = (gcnew System::Windows::Forms::RichTextBox());
            this->SuspendLayout();
            // 
            // rules_rtb
            // 
            this->rules_rtb->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(30)));
            this->rules_rtb->Dock = System::Windows::Forms::DockStyle::Fill;
            this->rules_rtb->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Small Semibol", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->rules_rtb->ForeColor = System::Drawing::SystemColors::Control;
            this->rules_rtb->Location = System::Drawing::Point(0, 0);
            this->rules_rtb->Name = L"rules_rtb";
            this->rules_rtb->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
            this->rules_rtb->Size = System::Drawing::Size(1025, 652);
            this->rules_rtb->TabIndex = 0;
            this->rules_rtb->Text = L"";
            // 
            // RulesForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(11, 27);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(30)));
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->ClientSize = System::Drawing::Size(1025, 652);
            this->ControlBox = false;
            this->Controls->Add(this->rules_rtb);
            this->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->MaximizeBox = false;
            this->MaximumSize = System::Drawing::Size(1025, 652);
            this->MinimizeBox = false;
            this->MinimumSize = System::Drawing::Size(1025, 652);
            this->Name = L"RulesForm";
            this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
            this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
            this->Text = L"Competition Scheduler - Rules";
            this->Load += gcnew System::EventHandler(this, &RulesForm::RulesForm_Load);
            this->ResumeLayout(false);

        }
#pragma endregion

		// Load the rules into the RichTextBox
    private: System::Void RulesForm_Load(System::Object^ sender, System::EventArgs^ e) {
        // Clear any existing text
        this->rules_rtb->Clear();

        // Add title
        this->rules_rtb->SelectionFont = gcnew System::Drawing::Font(L"Segoe UI", 16, FontStyle::Bold);
        this->rules_rtb->AppendText("  Competition Rules\n\n");

        // Add rule categories
        this->rules_rtb->SelectionFont = gcnew System::Drawing::Font(L"Segoe UI", 14, FontStyle::Bold);
        this->rules_rtb->AppendText("  1. Team Composition\n");
        this->rules_rtb->SelectionFont = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
        this->rules_rtb->AppendText(
            "  - Each team must consist of 1 to 4 members.\n"
            "  - Teams must register their team name, members, and rank before the competition begins.\n\n"
        );

        this->rules_rtb->SelectionFont = gcnew System::Drawing::Font(L"Segoe UI", 14, FontStyle::Bold);
        this->rules_rtb->AppendText("  2. Match Format\n");
        this->rules_rtb->SelectionFont = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
        this->rules_rtb->AppendText(
            "  - The competition follows a knockout format.\n"
            "  - Round 1: All 16 teams will compete, divided into Group A and Group B.\n"
            "  - Subsequent rounds will randomly pair winners.\n\n"
        );

        this->rules_rtb->SelectionFont = gcnew System::Drawing::Font(L"Segoe UI", 14, FontStyle::Bold);
        this->rules_rtb->AppendText("  3. Match Rules\n");
        this->rules_rtb->SelectionFont = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
        this->rules_rtb->AppendText(
            "  - Each match will have two teams competing head-to-head.\n"
            "  - The team with the highest score or the fastest completion time will be declared the winner.\n"
            "  - In the case of a tie, a tie-breaker round will be conducted.\n\n"
        );

        this->rules_rtb->SelectionFont = gcnew System::Drawing::Font(L"Segoe UI", 14, FontStyle::Bold);
        this->rules_rtb->AppendText("  4. Conduct and Fair Play\n");
        this->rules_rtb->SelectionFont = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
        this->rules_rtb->AppendText(
            "  - Teams must adhere to ethical hacking guidelines during the competition.\n"
            "  - Any team caught using unauthorized tools or methods will be disqualified.\n"
            "  - Collaboration between teams or external assistance is strictly prohibited.\n\n"
        );
    }
    };
}
