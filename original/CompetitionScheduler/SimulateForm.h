#pragma once
#include "Scheduler.h"
#include "Match.h"
#include "TeamLogoManager.h"

namespace CompetitionScheduler {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for SimulateForm
    /// </summary>
    public ref class SimulateForm : public System::Windows::Forms::Form
    {
    public:
		Scheduler* scheduler;

        SimulateForm(Scheduler* scheduler)
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
        ~SimulateForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel5;
    private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel4;
    private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel3;
    private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel2;
    private: System::Windows::Forms::Panel^ match15_panel;














    private: System::Windows::Forms::Panel^ panel72;
    private: System::Windows::Forms::Label^ match15_team2_rank;

    private: System::Windows::Forms::Label^ match15_team2;
    private: System::Windows::Forms::PictureBox^ match15_teamlogo2;


    private: System::Windows::Forms::Panel^ panel73;
    private: System::Windows::Forms::Label^ match15_team1_rank;

    private: System::Windows::Forms::Label^ match15_team1;
    private: System::Windows::Forms::PictureBox^ match15_teamlogo1;


    private: System::Windows::Forms::Panel^ panel74;
    private: System::Windows::Forms::Panel^ panel75;
    private: System::Windows::Forms::Label^ match15_date;

    private: System::Windows::Forms::Label^ match15_label;

    private: System::Windows::Forms::Panel^ match13_panel;

    private: System::Windows::Forms::Panel^ panel62;
    private: System::Windows::Forms::Label^ match13_team2_rank;

    private: System::Windows::Forms::Label^ match13_team2;
    private: System::Windows::Forms::PictureBox^ match13_teamlogo2;


    private: System::Windows::Forms::Panel^ panel63;
    private: System::Windows::Forms::Label^ match13_team1_rank;

    private: System::Windows::Forms::Label^ match13_team1;
    private: System::Windows::Forms::PictureBox^ match13_teamlogo1;


    private: System::Windows::Forms::Panel^ panel64;
    private: System::Windows::Forms::Panel^ panel65;
    private: System::Windows::Forms::Label^ match13_date;

    private: System::Windows::Forms::Label^ match13_label;

    private: System::Windows::Forms::Panel^ match14_panel;

    private: System::Windows::Forms::Panel^ panel67;
    private: System::Windows::Forms::Label^ match14_team2_rank;

    private: System::Windows::Forms::Label^ match14_team2;
    private: System::Windows::Forms::PictureBox^ match14_teamlogo2;


    private: System::Windows::Forms::Panel^ panel68;
    private: System::Windows::Forms::Label^ match14_team1_rank;

    private: System::Windows::Forms::Label^ match14_team1;
private: System::Windows::Forms::PictureBox^ match14_teamlogo1;


    private: System::Windows::Forms::Panel^ panel69;
    private: System::Windows::Forms::Panel^ panel70;
    private: System::Windows::Forms::Label^ match14_date;

    private: System::Windows::Forms::Label^ match14_label;

    private: System::Windows::Forms::Panel^ match9_panel;

    private: System::Windows::Forms::Panel^ panel42;
private: System::Windows::Forms::Label^ match9_team2_rank;

    private: System::Windows::Forms::Label^ match9_team2;
private: System::Windows::Forms::PictureBox^ match9_teamlogo2;


    private: System::Windows::Forms::Panel^ panel43;
private: System::Windows::Forms::Label^ match9_team1_rank;

private: System::Windows::Forms::Label^ match9_team1;
private: System::Windows::Forms::PictureBox^ match9_teamlogo1;


    private: System::Windows::Forms::Panel^ panel44;
    private: System::Windows::Forms::Panel^ panel45;
private: System::Windows::Forms::Label^ match9_date;

private: System::Windows::Forms::Label^ match9_label;

    private: System::Windows::Forms::Panel^ match10_panel;

    private: System::Windows::Forms::Panel^ panel47;
private: System::Windows::Forms::Label^ match10_team2_rank;

private: System::Windows::Forms::Label^ match10_team2;
private: System::Windows::Forms::PictureBox^ match10_teamlogo2;


    private: System::Windows::Forms::Panel^ panel48;
private: System::Windows::Forms::Label^ match10_team1_rank;

private: System::Windows::Forms::Label^ match10_team1;
private: System::Windows::Forms::PictureBox^ match10_teamlogo1;


    private: System::Windows::Forms::Panel^ panel49;
    private: System::Windows::Forms::Panel^ panel50;
private: System::Windows::Forms::Label^ match10_date;

private: System::Windows::Forms::Label^ match10_label;

private: System::Windows::Forms::Panel^ match11_panel;

    private: System::Windows::Forms::Panel^ panel52;
private: System::Windows::Forms::Label^ match11_team2_rank;

private: System::Windows::Forms::Label^ match11_team2;
private: System::Windows::Forms::PictureBox^ match11_teamlogo2;


    private: System::Windows::Forms::Panel^ panel53;
private: System::Windows::Forms::Label^ match11_team1_rank;

private: System::Windows::Forms::Label^ match11_team1;
private: System::Windows::Forms::PictureBox^ match11_teamlogo1;


    private: System::Windows::Forms::Panel^ panel54;
    private: System::Windows::Forms::Panel^ panel55;
private: System::Windows::Forms::Label^ match11_date;

private: System::Windows::Forms::Label^ matc11_label;

private: System::Windows::Forms::Panel^ match12_panel;

    private: System::Windows::Forms::Panel^ panel57;
private: System::Windows::Forms::Label^ match12_team2_rank;

private: System::Windows::Forms::Label^ match12_team2;
private: System::Windows::Forms::PictureBox^ match12_teamlogo2;


    private: System::Windows::Forms::Panel^ panel58;
private: System::Windows::Forms::Label^ match12_team1_rank;

private: System::Windows::Forms::Label^ match12_team1;
private: System::Windows::Forms::PictureBox^ match12_teamlogo1;


    private: System::Windows::Forms::Panel^ panel59;
    private: System::Windows::Forms::Panel^ panel60;
private: System::Windows::Forms::Label^ match12_date;

private: System::Windows::Forms::Label^ match12_label;

private: System::Windows::Forms::Panel^ match1_panel;

private: System::Windows::Forms::Panel^ panel5;
private: System::Windows::Forms::Label^ match1_team2_rank;

private: System::Windows::Forms::Label^ match1_team2;
private: System::Windows::Forms::PictureBox^ match1_teamlogo2;


private: System::Windows::Forms::Panel^ panel4;
private: System::Windows::Forms::Label^ match1_team1_rank;

private: System::Windows::Forms::Label^ match1_team1;
private: System::Windows::Forms::PictureBox^ match1_teamlogo1;


private: System::Windows::Forms::Panel^ panel2;
private: System::Windows::Forms::Panel^ panel3;
private: System::Windows::Forms::Label^ match1_date;

private: System::Windows::Forms::Label^ match1_label;

private: System::Windows::Forms::Panel^ match2_panel;

private: System::Windows::Forms::Panel^ panel7;
private: System::Windows::Forms::Label^ match2_team2_rank;

private: System::Windows::Forms::Label^ match2_team2;
private: System::Windows::Forms::PictureBox^ match2_teamlogo2;


private: System::Windows::Forms::Panel^ panel8;
private: System::Windows::Forms::Label^ match2_team1_rank;

private: System::Windows::Forms::Label^ match2_team1;
private: System::Windows::Forms::PictureBox^ match2_teamlogo1;


private: System::Windows::Forms::Panel^ panel9;
private: System::Windows::Forms::Panel^ panel10;
private: System::Windows::Forms::Label^ match2_date;

private: System::Windows::Forms::Label^ match2_label;

private: System::Windows::Forms::Panel^ match3_panel;

private: System::Windows::Forms::Panel^ panel12;
private: System::Windows::Forms::Label^ match3_team2_rank;

private: System::Windows::Forms::Label^ match3_team2;
private: System::Windows::Forms::PictureBox^ match3_teamlogo2;


private: System::Windows::Forms::Panel^ panel13;
private: System::Windows::Forms::Label^ match3_team1_rank;

private: System::Windows::Forms::Label^ match3_team1;
private: System::Windows::Forms::PictureBox^ match3_teamlogo1;


private: System::Windows::Forms::Panel^ panel14;
private: System::Windows::Forms::Panel^ panel15;
private: System::Windows::Forms::Label^ match3_date;

private: System::Windows::Forms::Label^ match3_label;

private: System::Windows::Forms::Panel^ match4_panel;

private: System::Windows::Forms::Panel^ panel17;
private: System::Windows::Forms::Label^ match4_team2_rank;

private: System::Windows::Forms::Label^ match4_team2;
private: System::Windows::Forms::PictureBox^ match4_teamlogo2;


private: System::Windows::Forms::Panel^ panel18;
private: System::Windows::Forms::Label^ match4_team1_rank;

private: System::Windows::Forms::Label^ match4_team1;
private: System::Windows::Forms::PictureBox^ match4_teamlogo1;


private: System::Windows::Forms::Panel^ panel19;
private: System::Windows::Forms::Panel^ panel20;
private: System::Windows::Forms::Label^ match4_date;

private: System::Windows::Forms::Label^ match4_label;

private: System::Windows::Forms::Panel^ match5_panel;

private: System::Windows::Forms::Panel^ panel22;
private: System::Windows::Forms::Label^ match5_team2_rank;

private: System::Windows::Forms::Label^ match5_team2;
private: System::Windows::Forms::PictureBox^ match5_teamlogo2;


private: System::Windows::Forms::Panel^ panel23;
private: System::Windows::Forms::Label^ match5_team1_rank;

private: System::Windows::Forms::Label^ match5_team1;
private: System::Windows::Forms::PictureBox^ match5_teamlogo1;


private: System::Windows::Forms::Panel^ panel24;
private: System::Windows::Forms::Panel^ panel25;
private: System::Windows::Forms::Label^ match5_date;

private: System::Windows::Forms::Label^ match5_label;

private: System::Windows::Forms::Panel^ match6_panel;

private: System::Windows::Forms::Panel^ panel27;
private: System::Windows::Forms::Label^ match6_team2_rank;

private: System::Windows::Forms::Label^ match6_team2;
private: System::Windows::Forms::PictureBox^ match6_teamlogo2;


private: System::Windows::Forms::Panel^ panel28;
private: System::Windows::Forms::Label^ match6_team1_rank;

private: System::Windows::Forms::Label^ match6_team1;
private: System::Windows::Forms::PictureBox^ match6_teamlogo1;


private: System::Windows::Forms::Panel^ panel29;
private: System::Windows::Forms::Panel^ panel30;
private: System::Windows::Forms::Label^ match6_date;

private: System::Windows::Forms::Label^ match6_label;

private: System::Windows::Forms::Panel^ match7_panel;

private: System::Windows::Forms::Panel^ panel32;
private: System::Windows::Forms::Label^ match7_team2_rank;

private: System::Windows::Forms::Label^ match7_team2;
private: System::Windows::Forms::PictureBox^ match7_teamlogo2;


private: System::Windows::Forms::Panel^ panel33;
private: System::Windows::Forms::Label^ match7_team1_rank;

private: System::Windows::Forms::Label^ match7_team1;
private: System::Windows::Forms::PictureBox^ match7_teamlogo1;


private: System::Windows::Forms::Panel^ panel34;
private: System::Windows::Forms::Panel^ panel35;
private: System::Windows::Forms::Label^ match7_date;

private: System::Windows::Forms::Label^ match7_label;

private: System::Windows::Forms::Panel^ match8_panel;

private: System::Windows::Forms::Panel^ panel37;
private: System::Windows::Forms::Label^ match8_team2_rank;

private: System::Windows::Forms::Label^ match8_team2;
private: System::Windows::Forms::PictureBox^ match8_teamlogo2;


private: System::Windows::Forms::Panel^ panel38;
private: System::Windows::Forms::Label^ match8_team1_rank;

private: System::Windows::Forms::Label^ match8_team1;
private: System::Windows::Forms::PictureBox^ match8_teamlogo1;


private: System::Windows::Forms::Panel^ panel39;
private: System::Windows::Forms::Panel^ panel40;
private: System::Windows::Forms::Label^ match8_date;

private: System::Windows::Forms::Label^ match8_label;

private: System::Windows::Forms::Panel^ winner_panel;

private: System::Windows::Forms::Panel^ panel11;
private: System::Windows::Forms::Label^ winner_rank;

private: System::Windows::Forms::Label^ winner_team;
private: System::Windows::Forms::PictureBox^ winner_teamlogo;


private: System::Windows::Forms::Panel^ panel16;
private: System::Windows::Forms::Panel^ panel21;
private: System::Windows::Forms::Label^ winner_label;


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
            this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->flowLayoutPanel5 = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->winner_panel = (gcnew System::Windows::Forms::Panel());
            this->panel11 = (gcnew System::Windows::Forms::Panel());
            this->winner_rank = (gcnew System::Windows::Forms::Label());
            this->winner_team = (gcnew System::Windows::Forms::Label());
            this->winner_teamlogo = (gcnew System::Windows::Forms::PictureBox());
            this->panel16 = (gcnew System::Windows::Forms::Panel());
            this->panel21 = (gcnew System::Windows::Forms::Panel());
            this->winner_label = (gcnew System::Windows::Forms::Label());
            this->match15_panel = (gcnew System::Windows::Forms::Panel());
            this->panel72 = (gcnew System::Windows::Forms::Panel());
            this->match15_team2_rank = (gcnew System::Windows::Forms::Label());
            this->match15_team2 = (gcnew System::Windows::Forms::Label());
            this->match15_teamlogo2 = (gcnew System::Windows::Forms::PictureBox());
            this->panel73 = (gcnew System::Windows::Forms::Panel());
            this->match15_team1_rank = (gcnew System::Windows::Forms::Label());
            this->match15_team1 = (gcnew System::Windows::Forms::Label());
            this->match15_teamlogo1 = (gcnew System::Windows::Forms::PictureBox());
            this->panel74 = (gcnew System::Windows::Forms::Panel());
            this->panel75 = (gcnew System::Windows::Forms::Panel());
            this->match15_date = (gcnew System::Windows::Forms::Label());
            this->match15_label = (gcnew System::Windows::Forms::Label());
            this->flowLayoutPanel4 = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->match13_panel = (gcnew System::Windows::Forms::Panel());
            this->panel62 = (gcnew System::Windows::Forms::Panel());
            this->match13_team2_rank = (gcnew System::Windows::Forms::Label());
            this->match13_team2 = (gcnew System::Windows::Forms::Label());
            this->match13_teamlogo2 = (gcnew System::Windows::Forms::PictureBox());
            this->panel63 = (gcnew System::Windows::Forms::Panel());
            this->match13_team1_rank = (gcnew System::Windows::Forms::Label());
            this->match13_team1 = (gcnew System::Windows::Forms::Label());
            this->match13_teamlogo1 = (gcnew System::Windows::Forms::PictureBox());
            this->panel64 = (gcnew System::Windows::Forms::Panel());
            this->panel65 = (gcnew System::Windows::Forms::Panel());
            this->match13_date = (gcnew System::Windows::Forms::Label());
            this->match13_label = (gcnew System::Windows::Forms::Label());
            this->match14_panel = (gcnew System::Windows::Forms::Panel());
            this->panel67 = (gcnew System::Windows::Forms::Panel());
            this->match14_team2_rank = (gcnew System::Windows::Forms::Label());
            this->match14_team2 = (gcnew System::Windows::Forms::Label());
            this->match14_teamlogo2 = (gcnew System::Windows::Forms::PictureBox());
            this->panel68 = (gcnew System::Windows::Forms::Panel());
            this->match14_team1_rank = (gcnew System::Windows::Forms::Label());
            this->match14_team1 = (gcnew System::Windows::Forms::Label());
            this->match14_teamlogo1 = (gcnew System::Windows::Forms::PictureBox());
            this->panel69 = (gcnew System::Windows::Forms::Panel());
            this->panel70 = (gcnew System::Windows::Forms::Panel());
            this->match14_date = (gcnew System::Windows::Forms::Label());
            this->match14_label = (gcnew System::Windows::Forms::Label());
            this->flowLayoutPanel3 = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->match9_panel = (gcnew System::Windows::Forms::Panel());
            this->panel42 = (gcnew System::Windows::Forms::Panel());
            this->match9_team2_rank = (gcnew System::Windows::Forms::Label());
            this->match9_team2 = (gcnew System::Windows::Forms::Label());
            this->match9_teamlogo2 = (gcnew System::Windows::Forms::PictureBox());
            this->panel43 = (gcnew System::Windows::Forms::Panel());
            this->match9_team1_rank = (gcnew System::Windows::Forms::Label());
            this->match9_team1 = (gcnew System::Windows::Forms::Label());
            this->match9_teamlogo1 = (gcnew System::Windows::Forms::PictureBox());
            this->panel44 = (gcnew System::Windows::Forms::Panel());
            this->panel45 = (gcnew System::Windows::Forms::Panel());
            this->match9_date = (gcnew System::Windows::Forms::Label());
            this->match9_label = (gcnew System::Windows::Forms::Label());
            this->match10_panel = (gcnew System::Windows::Forms::Panel());
            this->panel47 = (gcnew System::Windows::Forms::Panel());
            this->match10_team2_rank = (gcnew System::Windows::Forms::Label());
            this->match10_team2 = (gcnew System::Windows::Forms::Label());
            this->match10_teamlogo2 = (gcnew System::Windows::Forms::PictureBox());
            this->panel48 = (gcnew System::Windows::Forms::Panel());
            this->match10_team1_rank = (gcnew System::Windows::Forms::Label());
            this->match10_team1 = (gcnew System::Windows::Forms::Label());
            this->match10_teamlogo1 = (gcnew System::Windows::Forms::PictureBox());
            this->panel49 = (gcnew System::Windows::Forms::Panel());
            this->panel50 = (gcnew System::Windows::Forms::Panel());
            this->match10_date = (gcnew System::Windows::Forms::Label());
            this->match10_label = (gcnew System::Windows::Forms::Label());
            this->match11_panel = (gcnew System::Windows::Forms::Panel());
            this->panel52 = (gcnew System::Windows::Forms::Panel());
            this->match11_team2_rank = (gcnew System::Windows::Forms::Label());
            this->match11_team2 = (gcnew System::Windows::Forms::Label());
            this->match11_teamlogo2 = (gcnew System::Windows::Forms::PictureBox());
            this->panel53 = (gcnew System::Windows::Forms::Panel());
            this->match11_team1_rank = (gcnew System::Windows::Forms::Label());
            this->match11_team1 = (gcnew System::Windows::Forms::Label());
            this->match11_teamlogo1 = (gcnew System::Windows::Forms::PictureBox());
            this->panel54 = (gcnew System::Windows::Forms::Panel());
            this->panel55 = (gcnew System::Windows::Forms::Panel());
            this->match11_date = (gcnew System::Windows::Forms::Label());
            this->matc11_label = (gcnew System::Windows::Forms::Label());
            this->match12_panel = (gcnew System::Windows::Forms::Panel());
            this->panel57 = (gcnew System::Windows::Forms::Panel());
            this->match12_team2_rank = (gcnew System::Windows::Forms::Label());
            this->match12_team2 = (gcnew System::Windows::Forms::Label());
            this->match12_teamlogo2 = (gcnew System::Windows::Forms::PictureBox());
            this->panel58 = (gcnew System::Windows::Forms::Panel());
            this->match12_team1_rank = (gcnew System::Windows::Forms::Label());
            this->match12_team1 = (gcnew System::Windows::Forms::Label());
            this->match12_teamlogo1 = (gcnew System::Windows::Forms::PictureBox());
            this->panel59 = (gcnew System::Windows::Forms::Panel());
            this->panel60 = (gcnew System::Windows::Forms::Panel());
            this->match12_date = (gcnew System::Windows::Forms::Label());
            this->match12_label = (gcnew System::Windows::Forms::Label());
            this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->match1_panel = (gcnew System::Windows::Forms::Panel());
            this->panel5 = (gcnew System::Windows::Forms::Panel());
            this->match1_team2_rank = (gcnew System::Windows::Forms::Label());
            this->match1_team2 = (gcnew System::Windows::Forms::Label());
            this->match1_teamlogo2 = (gcnew System::Windows::Forms::PictureBox());
            this->panel4 = (gcnew System::Windows::Forms::Panel());
            this->match1_team1_rank = (gcnew System::Windows::Forms::Label());
            this->match1_team1 = (gcnew System::Windows::Forms::Label());
            this->match1_teamlogo1 = (gcnew System::Windows::Forms::PictureBox());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->panel3 = (gcnew System::Windows::Forms::Panel());
            this->match1_date = (gcnew System::Windows::Forms::Label());
            this->match1_label = (gcnew System::Windows::Forms::Label());
            this->match2_panel = (gcnew System::Windows::Forms::Panel());
            this->panel7 = (gcnew System::Windows::Forms::Panel());
            this->match2_team2_rank = (gcnew System::Windows::Forms::Label());
            this->match2_team2 = (gcnew System::Windows::Forms::Label());
            this->match2_teamlogo2 = (gcnew System::Windows::Forms::PictureBox());
            this->panel8 = (gcnew System::Windows::Forms::Panel());
            this->match2_team1_rank = (gcnew System::Windows::Forms::Label());
            this->match2_team1 = (gcnew System::Windows::Forms::Label());
            this->match2_teamlogo1 = (gcnew System::Windows::Forms::PictureBox());
            this->panel9 = (gcnew System::Windows::Forms::Panel());
            this->panel10 = (gcnew System::Windows::Forms::Panel());
            this->match2_date = (gcnew System::Windows::Forms::Label());
            this->match2_label = (gcnew System::Windows::Forms::Label());
            this->match3_panel = (gcnew System::Windows::Forms::Panel());
            this->panel12 = (gcnew System::Windows::Forms::Panel());
            this->match3_team2_rank = (gcnew System::Windows::Forms::Label());
            this->match3_team2 = (gcnew System::Windows::Forms::Label());
            this->match3_teamlogo2 = (gcnew System::Windows::Forms::PictureBox());
            this->panel13 = (gcnew System::Windows::Forms::Panel());
            this->match3_team1_rank = (gcnew System::Windows::Forms::Label());
            this->match3_team1 = (gcnew System::Windows::Forms::Label());
            this->match3_teamlogo1 = (gcnew System::Windows::Forms::PictureBox());
            this->panel14 = (gcnew System::Windows::Forms::Panel());
            this->panel15 = (gcnew System::Windows::Forms::Panel());
            this->match3_date = (gcnew System::Windows::Forms::Label());
            this->match3_label = (gcnew System::Windows::Forms::Label());
            this->match4_panel = (gcnew System::Windows::Forms::Panel());
            this->panel17 = (gcnew System::Windows::Forms::Panel());
            this->match4_team2_rank = (gcnew System::Windows::Forms::Label());
            this->match4_team2 = (gcnew System::Windows::Forms::Label());
            this->match4_teamlogo2 = (gcnew System::Windows::Forms::PictureBox());
            this->panel18 = (gcnew System::Windows::Forms::Panel());
            this->match4_team1_rank = (gcnew System::Windows::Forms::Label());
            this->match4_team1 = (gcnew System::Windows::Forms::Label());
            this->match4_teamlogo1 = (gcnew System::Windows::Forms::PictureBox());
            this->panel19 = (gcnew System::Windows::Forms::Panel());
            this->panel20 = (gcnew System::Windows::Forms::Panel());
            this->match4_date = (gcnew System::Windows::Forms::Label());
            this->match4_label = (gcnew System::Windows::Forms::Label());
            this->match5_panel = (gcnew System::Windows::Forms::Panel());
            this->panel22 = (gcnew System::Windows::Forms::Panel());
            this->match5_team2_rank = (gcnew System::Windows::Forms::Label());
            this->match5_team2 = (gcnew System::Windows::Forms::Label());
            this->match5_teamlogo2 = (gcnew System::Windows::Forms::PictureBox());
            this->panel23 = (gcnew System::Windows::Forms::Panel());
            this->match5_team1_rank = (gcnew System::Windows::Forms::Label());
            this->match5_team1 = (gcnew System::Windows::Forms::Label());
            this->match5_teamlogo1 = (gcnew System::Windows::Forms::PictureBox());
            this->panel24 = (gcnew System::Windows::Forms::Panel());
            this->panel25 = (gcnew System::Windows::Forms::Panel());
            this->match5_date = (gcnew System::Windows::Forms::Label());
            this->match5_label = (gcnew System::Windows::Forms::Label());
            this->match6_panel = (gcnew System::Windows::Forms::Panel());
            this->panel27 = (gcnew System::Windows::Forms::Panel());
            this->match6_team2_rank = (gcnew System::Windows::Forms::Label());
            this->match6_team2 = (gcnew System::Windows::Forms::Label());
            this->match6_teamlogo2 = (gcnew System::Windows::Forms::PictureBox());
            this->panel28 = (gcnew System::Windows::Forms::Panel());
            this->match6_team1_rank = (gcnew System::Windows::Forms::Label());
            this->match6_team1 = (gcnew System::Windows::Forms::Label());
            this->match6_teamlogo1 = (gcnew System::Windows::Forms::PictureBox());
            this->panel29 = (gcnew System::Windows::Forms::Panel());
            this->panel30 = (gcnew System::Windows::Forms::Panel());
            this->match6_date = (gcnew System::Windows::Forms::Label());
            this->match6_label = (gcnew System::Windows::Forms::Label());
            this->match7_panel = (gcnew System::Windows::Forms::Panel());
            this->panel32 = (gcnew System::Windows::Forms::Panel());
            this->match7_team2_rank = (gcnew System::Windows::Forms::Label());
            this->match7_team2 = (gcnew System::Windows::Forms::Label());
            this->match7_teamlogo2 = (gcnew System::Windows::Forms::PictureBox());
            this->panel33 = (gcnew System::Windows::Forms::Panel());
            this->match7_team1_rank = (gcnew System::Windows::Forms::Label());
            this->match7_team1 = (gcnew System::Windows::Forms::Label());
            this->match7_teamlogo1 = (gcnew System::Windows::Forms::PictureBox());
            this->panel34 = (gcnew System::Windows::Forms::Panel());
            this->panel35 = (gcnew System::Windows::Forms::Panel());
            this->match7_date = (gcnew System::Windows::Forms::Label());
            this->match7_label = (gcnew System::Windows::Forms::Label());
            this->match8_panel = (gcnew System::Windows::Forms::Panel());
            this->panel37 = (gcnew System::Windows::Forms::Panel());
            this->match8_team2_rank = (gcnew System::Windows::Forms::Label());
            this->match8_team2 = (gcnew System::Windows::Forms::Label());
            this->match8_teamlogo2 = (gcnew System::Windows::Forms::PictureBox());
            this->panel38 = (gcnew System::Windows::Forms::Panel());
            this->match8_team1_rank = (gcnew System::Windows::Forms::Label());
            this->match8_team1 = (gcnew System::Windows::Forms::Label());
            this->match8_teamlogo1 = (gcnew System::Windows::Forms::PictureBox());
            this->panel39 = (gcnew System::Windows::Forms::Panel());
            this->panel40 = (gcnew System::Windows::Forms::Panel());
            this->match8_date = (gcnew System::Windows::Forms::Label());
            this->match8_label = (gcnew System::Windows::Forms::Label());
            this->flowLayoutPanel1->SuspendLayout();
            this->tableLayoutPanel1->SuspendLayout();
            this->flowLayoutPanel5->SuspendLayout();
            this->winner_panel->SuspendLayout();
            this->panel11->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->winner_teamlogo))->BeginInit();
            this->panel16->SuspendLayout();
            this->match15_panel->SuspendLayout();
            this->panel72->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match15_teamlogo2))->BeginInit();
            this->panel73->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match15_teamlogo1))->BeginInit();
            this->panel74->SuspendLayout();
            this->flowLayoutPanel4->SuspendLayout();
            this->match13_panel->SuspendLayout();
            this->panel62->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match13_teamlogo2))->BeginInit();
            this->panel63->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match13_teamlogo1))->BeginInit();
            this->panel64->SuspendLayout();
            this->match14_panel->SuspendLayout();
            this->panel67->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match14_teamlogo2))->BeginInit();
            this->panel68->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match14_teamlogo1))->BeginInit();
            this->panel69->SuspendLayout();
            this->flowLayoutPanel3->SuspendLayout();
            this->match9_panel->SuspendLayout();
            this->panel42->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match9_teamlogo2))->BeginInit();
            this->panel43->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match9_teamlogo1))->BeginInit();
            this->panel44->SuspendLayout();
            this->match10_panel->SuspendLayout();
            this->panel47->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match10_teamlogo2))->BeginInit();
            this->panel48->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match10_teamlogo1))->BeginInit();
            this->panel49->SuspendLayout();
            this->match11_panel->SuspendLayout();
            this->panel52->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match11_teamlogo2))->BeginInit();
            this->panel53->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match11_teamlogo1))->BeginInit();
            this->panel54->SuspendLayout();
            this->match12_panel->SuspendLayout();
            this->panel57->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match12_teamlogo2))->BeginInit();
            this->panel58->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match12_teamlogo1))->BeginInit();
            this->panel59->SuspendLayout();
            this->flowLayoutPanel2->SuspendLayout();
            this->match1_panel->SuspendLayout();
            this->panel5->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match1_teamlogo2))->BeginInit();
            this->panel4->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match1_teamlogo1))->BeginInit();
            this->panel2->SuspendLayout();
            this->match2_panel->SuspendLayout();
            this->panel7->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match2_teamlogo2))->BeginInit();
            this->panel8->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match2_teamlogo1))->BeginInit();
            this->panel9->SuspendLayout();
            this->match3_panel->SuspendLayout();
            this->panel12->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match3_teamlogo2))->BeginInit();
            this->panel13->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match3_teamlogo1))->BeginInit();
            this->panel14->SuspendLayout();
            this->match4_panel->SuspendLayout();
            this->panel17->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match4_teamlogo2))->BeginInit();
            this->panel18->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match4_teamlogo1))->BeginInit();
            this->panel19->SuspendLayout();
            this->match5_panel->SuspendLayout();
            this->panel22->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match5_teamlogo2))->BeginInit();
            this->panel23->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match5_teamlogo1))->BeginInit();
            this->panel24->SuspendLayout();
            this->match6_panel->SuspendLayout();
            this->panel27->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match6_teamlogo2))->BeginInit();
            this->panel28->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match6_teamlogo1))->BeginInit();
            this->panel29->SuspendLayout();
            this->match7_panel->SuspendLayout();
            this->panel32->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match7_teamlogo2))->BeginInit();
            this->panel33->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match7_teamlogo1))->BeginInit();
            this->panel34->SuspendLayout();
            this->match8_panel->SuspendLayout();
            this->panel37->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match8_teamlogo2))->BeginInit();
            this->panel38->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match8_teamlogo1))->BeginInit();
            this->panel39->SuspendLayout();
            this->SuspendLayout();
            // 
            // flowLayoutPanel1
            // 
            this->flowLayoutPanel1->Controls->Add(this->label1);
            this->flowLayoutPanel1->Controls->Add(this->label2);
            this->flowLayoutPanel1->Controls->Add(this->label3);
            this->flowLayoutPanel1->Controls->Add(this->label4);
            this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Top;
            this->flowLayoutPanel1->Location = System::Drawing::Point(0, 0);
            this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
            this->flowLayoutPanel1->Size = System::Drawing::Size(1010, 50);
            this->flowLayoutPanel1->TabIndex = 0;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Small", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(221)),
                static_cast<System::Int32>(static_cast<System::Byte>(171)));
            this->label1->Location = System::Drawing::Point(80, 10);
            this->label1->Margin = System::Windows::Forms::Padding(80, 10, 3, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(124, 37);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Round 1";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Small", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(221)),
                static_cast<System::Int32>(static_cast<System::Byte>(171)));
            this->label2->Location = System::Drawing::Point(337, 10);
            this->label2->Margin = System::Windows::Forms::Padding(130, 10, 3, 0);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(128, 37);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Round 2";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Small", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(221)),
                static_cast<System::Int32>(static_cast<System::Byte>(171)));
            this->label3->Location = System::Drawing::Point(618, 10);
            this->label3->Margin = System::Windows::Forms::Padding(150, 10, 3, 0);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(172, 37);
            this->label3->TabIndex = 2;
            this->label3->Text = L"Semi-Finals";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Small", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(221)),
                static_cast<System::Int32>(static_cast<System::Byte>(171)));
            this->label4->Location = System::Drawing::Point(170, 57);
            this->label4->Margin = System::Windows::Forms::Padding(170, 10, 3, 0);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(94, 37);
            this->label4->TabIndex = 3;
            this->label4->Text = L"Finals";
            // 
            // tableLayoutPanel1
            // 
            this->tableLayoutPanel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)));
            this->tableLayoutPanel1->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
            this->tableLayoutPanel1->ColumnCount = 4;
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                25)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                25)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                25)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                25)));
            this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel5, 3, 0);
            this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel4, 2, 0);
            this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel3, 1, 0);
            this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel2, 0, 0);
            this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel1->Location = System::Drawing::Point(0, 50);
            this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
            this->tableLayoutPanel1->RowCount = 1;
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->tableLayoutPanel1->Size = System::Drawing::Size(1010, 968);
            this->tableLayoutPanel1->TabIndex = 1;
            // 
            // flowLayoutPanel5
            // 
            this->flowLayoutPanel5->Controls->Add(this->winner_panel);
            this->flowLayoutPanel5->Controls->Add(this->match15_panel);
            this->flowLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
            this->flowLayoutPanel5->Location = System::Drawing::Point(760, 4);
            this->flowLayoutPanel5->Name = L"flowLayoutPanel5";
            this->flowLayoutPanel5->Size = System::Drawing::Size(246, 960);
            this->flowLayoutPanel5->TabIndex = 3;
            // 
            // winner_panel
            // 
            this->winner_panel->BackColor = System::Drawing::Color::Goldenrod;
            this->winner_panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->winner_panel->Controls->Add(this->panel11);
            this->winner_panel->Controls->Add(this->panel16);
            this->winner_panel->Location = System::Drawing::Point(3, 50);
            this->winner_panel->Margin = System::Windows::Forms::Padding(3, 50, 3, 3);
            this->winner_panel->Name = L"winner_panel";
            this->winner_panel->Size = System::Drawing::Size(246, 80);
            this->winner_panel->TabIndex = 5;
            this->winner_panel->Visible = false;
            // 
            // panel11
            // 
            this->panel11->Controls->Add(this->winner_rank);
            this->panel11->Controls->Add(this->winner_team);
            this->panel11->Controls->Add(this->winner_teamlogo);
            this->panel11->Location = System::Drawing::Point(0, 30);
            this->panel11->Name = L"panel11";
            this->panel11->Size = System::Drawing::Size(246, 40);
            this->panel11->TabIndex = 1;
            // 
            // winner_rank
            // 
            this->winner_rank->AutoSize = true;
            this->winner_rank->ForeColor = System::Drawing::SystemColors::ControlText;
            this->winner_rank->Location = System::Drawing::Point(211, 3);
            this->winner_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->winner_rank->Name = L"winner_rank";
            this->winner_rank->Size = System::Drawing::Size(19, 27);
            this->winner_rank->TabIndex = 2;
            this->winner_rank->Text = L"1";
            // 
            // winner_team
            // 
            this->winner_team->AutoSize = true;
            this->winner_team->ForeColor = System::Drawing::SystemColors::ControlText;
            this->winner_team->Location = System::Drawing::Point(77, 3);
            this->winner_team->Name = L"winner_team";
            this->winner_team->Size = System::Drawing::Size(74, 27);
            this->winner_team->TabIndex = 1;
            this->winner_team->Text = L"Winner";
            // 
            // winner_teamlogo
            // 
            this->winner_teamlogo->Location = System::Drawing::Point(5, 1);
            this->winner_teamlogo->Name = L"winner_teamlogo";
            this->winner_teamlogo->Size = System::Drawing::Size(64, 34);
            this->winner_teamlogo->TabIndex = 0;
            this->winner_teamlogo->TabStop = false;
            // 
            // panel16
            // 
            this->panel16->BackColor = System::Drawing::Color::DarkGoldenrod;
            this->panel16->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panel16->Controls->Add(this->panel21);
            this->panel16->Controls->Add(this->winner_label);
            this->panel16->Location = System::Drawing::Point(0, 0);
            this->panel16->Name = L"panel16";
            this->panel16->Size = System::Drawing::Size(246, 27);
            this->panel16->TabIndex = 0;
            // 
            // panel21
            // 
            this->panel21->Location = System::Drawing::Point(2, 29);
            this->panel21->Name = L"panel21";
            this->panel21->Size = System::Drawing::Size(240, 29);
            this->panel21->TabIndex = 1;
            // 
            // winner_label
            // 
            this->winner_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->winner_label->AutoSize = true;
            this->winner_label->ForeColor = System::Drawing::SystemColors::WindowText;
            this->winner_label->Location = System::Drawing::Point(89, -1);
            this->winner_label->Name = L"winner_label";
            this->winner_label->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->winner_label->Size = System::Drawing::Size(74, 27);
            this->winner_label->TabIndex = 1;
            this->winner_label->Text = L"Winner";
            this->winner_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // match15_panel
            // 
            this->match15_panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->match15_panel->Controls->Add(this->panel72);
            this->match15_panel->Controls->Add(this->panel73);
            this->match15_panel->Controls->Add(this->panel74);
            this->match15_panel->Location = System::Drawing::Point(3, 373);
            this->match15_panel->Margin = System::Windows::Forms::Padding(3, 240, 3, 3);
            this->match15_panel->Name = L"match15_panel";
            this->match15_panel->Size = System::Drawing::Size(246, 120);
            this->match15_panel->TabIndex = 4;
            // 
            // panel72
            // 
            this->panel72->Controls->Add(this->match15_team2_rank);
            this->panel72->Controls->Add(this->match15_team2);
            this->panel72->Controls->Add(this->match15_teamlogo2);
            this->panel72->Location = System::Drawing::Point(0, 70);
            this->panel72->Name = L"panel72";
            this->panel72->Size = System::Drawing::Size(246, 40);
            this->panel72->TabIndex = 2;
            // 
            // match15_team2_rank
            // 
            this->match15_team2_rank->AutoSize = true;
            this->match15_team2_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match15_team2_rank->Location = System::Drawing::Point(211, 7);
            this->match15_team2_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match15_team2_rank->Name = L"match15_team2_rank";
            this->match15_team2_rank->Size = System::Drawing::Size(23, 27);
            this->match15_team2_rank->TabIndex = 3;
            this->match15_team2_rank->Text = L"2";
            // 
            // match15_team2
            // 
            this->match15_team2->AutoSize = true;
            this->match15_team2->ForeColor = System::Drawing::SystemColors::Control;
            this->match15_team2->Location = System::Drawing::Point(77, 7);
            this->match15_team2->Name = L"match15_team2";
            this->match15_team2->Size = System::Drawing::Size(68, 27);
            this->match15_team2->TabIndex = 2;
            this->match15_team2->Text = L"Team2";
            // 
            // match15_teamlogo2
            // 
            this->match15_teamlogo2->Location = System::Drawing::Point(7, 6);
            this->match15_teamlogo2->Name = L"match15_teamlogo2";
            this->match15_teamlogo2->Size = System::Drawing::Size(64, 34);
            this->match15_teamlogo2->TabIndex = 1;
            this->match15_teamlogo2->TabStop = false;
            // 
            // panel73
            // 
            this->panel73->Controls->Add(this->match15_team1_rank);
            this->panel73->Controls->Add(this->match15_team1);
            this->panel73->Controls->Add(this->match15_teamlogo1);
            this->panel73->Location = System::Drawing::Point(0, 30);
            this->panel73->Name = L"panel73";
            this->panel73->Size = System::Drawing::Size(246, 40);
            this->panel73->TabIndex = 1;
            // 
            // match15_team1_rank
            // 
            this->match15_team1_rank->AutoSize = true;
            this->match15_team1_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match15_team1_rank->Location = System::Drawing::Point(211, 3);
            this->match15_team1_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match15_team1_rank->Name = L"match15_team1_rank";
            this->match15_team1_rank->Size = System::Drawing::Size(19, 27);
            this->match15_team1_rank->TabIndex = 2;
            this->match15_team1_rank->Text = L"1";
            // 
            // match15_team1
            // 
            this->match15_team1->AutoSize = true;
            this->match15_team1->ForeColor = System::Drawing::SystemColors::Control;
            this->match15_team1->Location = System::Drawing::Point(77, 3);
            this->match15_team1->Name = L"match15_team1";
            this->match15_team1->Size = System::Drawing::Size(64, 27);
            this->match15_team1->TabIndex = 1;
            this->match15_team1->Text = L"Team1";
            // 
            // match15_teamlogo1
            // 
            this->match15_teamlogo1->Location = System::Drawing::Point(7, 3);
            this->match15_teamlogo1->Name = L"match15_teamlogo1";
            this->match15_teamlogo1->Size = System::Drawing::Size(64, 34);
            this->match15_teamlogo1->TabIndex = 0;
            this->match15_teamlogo1->TabStop = false;
            // 
            // panel74
            // 
            this->panel74->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->panel74->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panel74->Controls->Add(this->panel75);
            this->panel74->Controls->Add(this->match15_date);
            this->panel74->Controls->Add(this->match15_label);
            this->panel74->Location = System::Drawing::Point(0, 0);
            this->panel74->Name = L"panel74";
            this->panel74->Size = System::Drawing::Size(246, 27);
            this->panel74->TabIndex = 0;
            // 
            // panel75
            // 
            this->panel75->Location = System::Drawing::Point(2, 29);
            this->panel75->Name = L"panel75";
            this->panel75->Size = System::Drawing::Size(240, 29);
            this->panel75->TabIndex = 1;
            // 
            // match15_date
            // 
            this->match15_date->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->match15_date->AutoSize = true;
            this->match15_date->ForeColor = System::Drawing::SystemColors::Control;
            this->match15_date->Location = System::Drawing::Point(116, -1);
            this->match15_date->Name = L"match15_date";
            this->match15_date->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->match15_date->Size = System::Drawing::Size(129, 27);
            this->match15_date->TabIndex = 1;
            this->match15_date->Text = L"01 NOV | 8:00";
            this->match15_date->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // match15_label
            // 
            this->match15_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->match15_label->AutoSize = true;
            this->match15_label->ForeColor = System::Drawing::SystemColors::Control;
            this->match15_label->Location = System::Drawing::Point(4, 0);
            this->match15_label->Name = L"match15_label";
            this->match15_label->Size = System::Drawing::Size(91, 27);
            this->match15_label->TabIndex = 0;
            this->match15_label->Text = L"Match 15";
            this->match15_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // flowLayoutPanel4
            // 
            this->flowLayoutPanel4->Controls->Add(this->match13_panel);
            this->flowLayoutPanel4->Controls->Add(this->match14_panel);
            this->flowLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
            this->flowLayoutPanel4->Location = System::Drawing::Point(508, 4);
            this->flowLayoutPanel4->Name = L"flowLayoutPanel4";
            this->flowLayoutPanel4->Size = System::Drawing::Size(245, 960);
            this->flowLayoutPanel4->TabIndex = 2;
            // 
            // match13_panel
            // 
            this->match13_panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->match13_panel->Controls->Add(this->panel62);
            this->match13_panel->Controls->Add(this->panel63);
            this->match13_panel->Controls->Add(this->panel64);
            this->match13_panel->Location = System::Drawing::Point(3, 160);
            this->match13_panel->Margin = System::Windows::Forms::Padding(3, 160, 3, 3);
            this->match13_panel->Name = L"match13_panel";
            this->match13_panel->Size = System::Drawing::Size(246, 120);
            this->match13_panel->TabIndex = 3;
            // 
            // panel62
            // 
            this->panel62->Controls->Add(this->match13_team2_rank);
            this->panel62->Controls->Add(this->match13_team2);
            this->panel62->Controls->Add(this->match13_teamlogo2);
            this->panel62->Location = System::Drawing::Point(0, 70);
            this->panel62->Name = L"panel62";
            this->panel62->Size = System::Drawing::Size(246, 40);
            this->panel62->TabIndex = 2;
            // 
            // match13_team2_rank
            // 
            this->match13_team2_rank->AutoSize = true;
            this->match13_team2_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match13_team2_rank->Location = System::Drawing::Point(211, 7);
            this->match13_team2_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match13_team2_rank->Name = L"match13_team2_rank";
            this->match13_team2_rank->Size = System::Drawing::Size(23, 27);
            this->match13_team2_rank->TabIndex = 3;
            this->match13_team2_rank->Text = L"2";
            // 
            // match13_team2
            // 
            this->match13_team2->AutoSize = true;
            this->match13_team2->ForeColor = System::Drawing::SystemColors::Control;
            this->match13_team2->Location = System::Drawing::Point(77, 7);
            this->match13_team2->Name = L"match13_team2";
            this->match13_team2->Size = System::Drawing::Size(68, 27);
            this->match13_team2->TabIndex = 2;
            this->match13_team2->Text = L"Team2";
            // 
            // match13_teamlogo2
            // 
            this->match13_teamlogo2->Location = System::Drawing::Point(7, 6);
            this->match13_teamlogo2->Name = L"match13_teamlogo2";
            this->match13_teamlogo2->Size = System::Drawing::Size(64, 34);
            this->match13_teamlogo2->TabIndex = 1;
            this->match13_teamlogo2->TabStop = false;
            // 
            // panel63
            // 
            this->panel63->Controls->Add(this->match13_team1_rank);
            this->panel63->Controls->Add(this->match13_team1);
            this->panel63->Controls->Add(this->match13_teamlogo1);
            this->panel63->Location = System::Drawing::Point(0, 30);
            this->panel63->Name = L"panel63";
            this->panel63->Size = System::Drawing::Size(246, 40);
            this->panel63->TabIndex = 1;
            // 
            // match13_team1_rank
            // 
            this->match13_team1_rank->AutoSize = true;
            this->match13_team1_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match13_team1_rank->Location = System::Drawing::Point(211, 3);
            this->match13_team1_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match13_team1_rank->Name = L"match13_team1_rank";
            this->match13_team1_rank->Size = System::Drawing::Size(19, 27);
            this->match13_team1_rank->TabIndex = 2;
            this->match13_team1_rank->Text = L"1";
            // 
            // match13_team1
            // 
            this->match13_team1->AutoSize = true;
            this->match13_team1->ForeColor = System::Drawing::SystemColors::Control;
            this->match13_team1->Location = System::Drawing::Point(77, 2);
            this->match13_team1->Name = L"match13_team1";
            this->match13_team1->Size = System::Drawing::Size(64, 27);
            this->match13_team1->TabIndex = 1;
            this->match13_team1->Text = L"Team1";
            // 
            // match13_teamlogo1
            // 
            this->match13_teamlogo1->Location = System::Drawing::Point(7, 3);
            this->match13_teamlogo1->Name = L"match13_teamlogo1";
            this->match13_teamlogo1->Size = System::Drawing::Size(64, 34);
            this->match13_teamlogo1->TabIndex = 0;
            this->match13_teamlogo1->TabStop = false;
            // 
            // panel64
            // 
            this->panel64->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->panel64->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panel64->Controls->Add(this->panel65);
            this->panel64->Controls->Add(this->match13_date);
            this->panel64->Controls->Add(this->match13_label);
            this->panel64->Location = System::Drawing::Point(0, 0);
            this->panel64->Name = L"panel64";
            this->panel64->Size = System::Drawing::Size(246, 27);
            this->panel64->TabIndex = 0;
            // 
            // panel65
            // 
            this->panel65->Location = System::Drawing::Point(2, 29);
            this->panel65->Name = L"panel65";
            this->panel65->Size = System::Drawing::Size(240, 29);
            this->panel65->TabIndex = 1;
            // 
            // match13_date
            // 
            this->match13_date->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->match13_date->AutoSize = true;
            this->match13_date->ForeColor = System::Drawing::SystemColors::Control;
            this->match13_date->Location = System::Drawing::Point(116, -1);
            this->match13_date->Name = L"match13_date";
            this->match13_date->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->match13_date->Size = System::Drawing::Size(129, 27);
            this->match13_date->TabIndex = 1;
            this->match13_date->Text = L"01 NOV | 8:00";
            this->match13_date->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // match13_label
            // 
            this->match13_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->match13_label->AutoSize = true;
            this->match13_label->ForeColor = System::Drawing::SystemColors::Control;
            this->match13_label->Location = System::Drawing::Point(4, 0);
            this->match13_label->Name = L"match13_label";
            this->match13_label->Size = System::Drawing::Size(91, 27);
            this->match13_label->TabIndex = 0;
            this->match13_label->Text = L"Match 13";
            this->match13_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // match14_panel
            // 
            this->match14_panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->match14_panel->Controls->Add(this->panel67);
            this->match14_panel->Controls->Add(this->panel68);
            this->match14_panel->Controls->Add(this->panel69);
            this->match14_panel->Location = System::Drawing::Point(3, 613);
            this->match14_panel->Margin = System::Windows::Forms::Padding(3, 330, 3, 3);
            this->match14_panel->Name = L"match14_panel";
            this->match14_panel->Size = System::Drawing::Size(246, 120);
            this->match14_panel->TabIndex = 4;
            // 
            // panel67
            // 
            this->panel67->Controls->Add(this->match14_team2_rank);
            this->panel67->Controls->Add(this->match14_team2);
            this->panel67->Controls->Add(this->match14_teamlogo2);
            this->panel67->Location = System::Drawing::Point(0, 70);
            this->panel67->Name = L"panel67";
            this->panel67->Size = System::Drawing::Size(246, 40);
            this->panel67->TabIndex = 2;
            // 
            // match14_team2_rank
            // 
            this->match14_team2_rank->AutoSize = true;
            this->match14_team2_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match14_team2_rank->Location = System::Drawing::Point(211, 7);
            this->match14_team2_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match14_team2_rank->Name = L"match14_team2_rank";
            this->match14_team2_rank->Size = System::Drawing::Size(23, 27);
            this->match14_team2_rank->TabIndex = 3;
            this->match14_team2_rank->Text = L"2";
            // 
            // match14_team2
            // 
            this->match14_team2->AutoSize = true;
            this->match14_team2->ForeColor = System::Drawing::SystemColors::Control;
            this->match14_team2->Location = System::Drawing::Point(77, 7);
            this->match14_team2->Name = L"match14_team2";
            this->match14_team2->Size = System::Drawing::Size(68, 27);
            this->match14_team2->TabIndex = 2;
            this->match14_team2->Text = L"Team2";
            // 
            // match14_teamlogo2
            // 
            this->match14_teamlogo2->Location = System::Drawing::Point(7, 6);
            this->match14_teamlogo2->Name = L"match14_teamlogo2";
            this->match14_teamlogo2->Size = System::Drawing::Size(64, 34);
            this->match14_teamlogo2->TabIndex = 1;
            this->match14_teamlogo2->TabStop = false;
            // 
            // panel68
            // 
            this->panel68->Controls->Add(this->match14_team1_rank);
            this->panel68->Controls->Add(this->match14_team1);
            this->panel68->Controls->Add(this->match14_teamlogo1);
            this->panel68->Location = System::Drawing::Point(0, 30);
            this->panel68->Name = L"panel68";
            this->panel68->Size = System::Drawing::Size(246, 40);
            this->panel68->TabIndex = 1;
            // 
            // match14_team1_rank
            // 
            this->match14_team1_rank->AutoSize = true;
            this->match14_team1_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match14_team1_rank->Location = System::Drawing::Point(211, 3);
            this->match14_team1_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match14_team1_rank->Name = L"match14_team1_rank";
            this->match14_team1_rank->Size = System::Drawing::Size(19, 27);
            this->match14_team1_rank->TabIndex = 2;
            this->match14_team1_rank->Text = L"1";
            // 
            // match14_team1
            // 
            this->match14_team1->AutoSize = true;
            this->match14_team1->ForeColor = System::Drawing::SystemColors::Control;
            this->match14_team1->Location = System::Drawing::Point(77, 2);
            this->match14_team1->Name = L"match14_team1";
            this->match14_team1->Size = System::Drawing::Size(64, 27);
            this->match14_team1->TabIndex = 1;
            this->match14_team1->Text = L"Team1";
            // 
            // match14_teamlogo1
            // 
            this->match14_teamlogo1->Location = System::Drawing::Point(7, 3);
            this->match14_teamlogo1->Name = L"match14_teamlogo1";
            this->match14_teamlogo1->Size = System::Drawing::Size(64, 34);
            this->match14_teamlogo1->TabIndex = 0;
            this->match14_teamlogo1->TabStop = false;
            // 
            // panel69
            // 
            this->panel69->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->panel69->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panel69->Controls->Add(this->panel70);
            this->panel69->Controls->Add(this->match14_date);
            this->panel69->Controls->Add(this->match14_label);
            this->panel69->Location = System::Drawing::Point(0, 0);
            this->panel69->Name = L"panel69";
            this->panel69->Size = System::Drawing::Size(246, 27);
            this->panel69->TabIndex = 0;
            // 
            // panel70
            // 
            this->panel70->Location = System::Drawing::Point(2, 29);
            this->panel70->Name = L"panel70";
            this->panel70->Size = System::Drawing::Size(240, 29);
            this->panel70->TabIndex = 1;
            // 
            // match14_date
            // 
            this->match14_date->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->match14_date->AutoSize = true;
            this->match14_date->ForeColor = System::Drawing::SystemColors::Control;
            this->match14_date->Location = System::Drawing::Point(116, -1);
            this->match14_date->Name = L"match14_date";
            this->match14_date->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->match14_date->Size = System::Drawing::Size(129, 27);
            this->match14_date->TabIndex = 1;
            this->match14_date->Text = L"01 NOV | 8:00";
            this->match14_date->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // match14_label
            // 
            this->match14_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->match14_label->AutoSize = true;
            this->match14_label->ForeColor = System::Drawing::SystemColors::Control;
            this->match14_label->Location = System::Drawing::Point(4, 0);
            this->match14_label->Name = L"match14_label";
            this->match14_label->Size = System::Drawing::Size(91, 27);
            this->match14_label->TabIndex = 0;
            this->match14_label->Text = L"Match 14";
            this->match14_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // flowLayoutPanel3
            // 
            this->flowLayoutPanel3->Controls->Add(this->match9_panel);
            this->flowLayoutPanel3->Controls->Add(this->match10_panel);
            this->flowLayoutPanel3->Controls->Add(this->match11_panel);
            this->flowLayoutPanel3->Controls->Add(this->match12_panel);
            this->flowLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
            this->flowLayoutPanel3->Location = System::Drawing::Point(256, 4);
            this->flowLayoutPanel3->Name = L"flowLayoutPanel3";
            this->flowLayoutPanel3->Size = System::Drawing::Size(245, 960);
            this->flowLayoutPanel3->TabIndex = 1;
            // 
            // match9_panel
            // 
            this->match9_panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->match9_panel->Controls->Add(this->panel42);
            this->match9_panel->Controls->Add(this->panel43);
            this->match9_panel->Controls->Add(this->panel44);
            this->match9_panel->Location = System::Drawing::Point(3, 50);
            this->match9_panel->Margin = System::Windows::Forms::Padding(3, 50, 3, 3);
            this->match9_panel->Name = L"match9_panel";
            this->match9_panel->Size = System::Drawing::Size(246, 120);
            this->match9_panel->TabIndex = 1;
            // 
            // panel42
            // 
            this->panel42->Controls->Add(this->match9_team2_rank);
            this->panel42->Controls->Add(this->match9_team2);
            this->panel42->Controls->Add(this->match9_teamlogo2);
            this->panel42->Location = System::Drawing::Point(0, 70);
            this->panel42->Name = L"panel42";
            this->panel42->Size = System::Drawing::Size(246, 40);
            this->panel42->TabIndex = 2;
            // 
            // match9_team2_rank
            // 
            this->match9_team2_rank->AutoSize = true;
            this->match9_team2_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match9_team2_rank->Location = System::Drawing::Point(211, 7);
            this->match9_team2_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match9_team2_rank->Name = L"match9_team2_rank";
            this->match9_team2_rank->Size = System::Drawing::Size(23, 27);
            this->match9_team2_rank->TabIndex = 3;
            this->match9_team2_rank->Text = L"2";
            // 
            // match9_team2
            // 
            this->match9_team2->AutoSize = true;
            this->match9_team2->ForeColor = System::Drawing::SystemColors::Control;
            this->match9_team2->Location = System::Drawing::Point(75, 7);
            this->match9_team2->Name = L"match9_team2";
            this->match9_team2->Size = System::Drawing::Size(68, 27);
            this->match9_team2->TabIndex = 2;
            this->match9_team2->Text = L"Team2";
            // 
            // match9_teamlogo2
            // 
            this->match9_teamlogo2->Location = System::Drawing::Point(7, 6);
            this->match9_teamlogo2->Name = L"match9_teamlogo2";
            this->match9_teamlogo2->Size = System::Drawing::Size(64, 34);
            this->match9_teamlogo2->TabIndex = 1;
            this->match9_teamlogo2->TabStop = false;
            // 
            // panel43
            // 
            this->panel43->Controls->Add(this->match9_team1_rank);
            this->panel43->Controls->Add(this->match9_team1);
            this->panel43->Controls->Add(this->match9_teamlogo1);
            this->panel43->Location = System::Drawing::Point(0, 30);
            this->panel43->Name = L"panel43";
            this->panel43->Size = System::Drawing::Size(246, 40);
            this->panel43->TabIndex = 1;
            // 
            // match9_team1_rank
            // 
            this->match9_team1_rank->AutoSize = true;
            this->match9_team1_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match9_team1_rank->Location = System::Drawing::Point(211, 3);
            this->match9_team1_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match9_team1_rank->Name = L"match9_team1_rank";
            this->match9_team1_rank->Size = System::Drawing::Size(19, 27);
            this->match9_team1_rank->TabIndex = 2;
            this->match9_team1_rank->Text = L"1";
            // 
            // match9_team1
            // 
            this->match9_team1->AutoSize = true;
            this->match9_team1->ForeColor = System::Drawing::SystemColors::Control;
            this->match9_team1->Location = System::Drawing::Point(75, 3);
            this->match9_team1->Name = L"match9_team1";
            this->match9_team1->Size = System::Drawing::Size(64, 27);
            this->match9_team1->TabIndex = 1;
            this->match9_team1->Text = L"Team1";
            // 
            // match9_teamlogo1
            // 
            this->match9_teamlogo1->Location = System::Drawing::Point(7, 3);
            this->match9_teamlogo1->Name = L"match9_teamlogo1";
            this->match9_teamlogo1->Size = System::Drawing::Size(64, 34);
            this->match9_teamlogo1->TabIndex = 0;
            this->match9_teamlogo1->TabStop = false;
            // 
            // panel44
            // 
            this->panel44->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->panel44->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panel44->Controls->Add(this->panel45);
            this->panel44->Controls->Add(this->match9_date);
            this->panel44->Controls->Add(this->match9_label);
            this->panel44->Location = System::Drawing::Point(0, 0);
            this->panel44->Name = L"panel44";
            this->panel44->Size = System::Drawing::Size(246, 27);
            this->panel44->TabIndex = 0;
            // 
            // panel45
            // 
            this->panel45->Location = System::Drawing::Point(2, 29);
            this->panel45->Name = L"panel45";
            this->panel45->Size = System::Drawing::Size(240, 29);
            this->panel45->TabIndex = 1;
            // 
            // match9_date
            // 
            this->match9_date->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->match9_date->AutoSize = true;
            this->match9_date->ForeColor = System::Drawing::SystemColors::Control;
            this->match9_date->Location = System::Drawing::Point(116, -1);
            this->match9_date->Name = L"match9_date";
            this->match9_date->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->match9_date->Size = System::Drawing::Size(129, 27);
            this->match9_date->TabIndex = 1;
            this->match9_date->Text = L"01 NOV | 8:00";
            this->match9_date->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // match9_label
            // 
            this->match9_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->match9_label->AutoSize = true;
            this->match9_label->ForeColor = System::Drawing::SystemColors::Control;
            this->match9_label->Location = System::Drawing::Point(4, 0);
            this->match9_label->Name = L"match9_label";
            this->match9_label->Size = System::Drawing::Size(84, 27);
            this->match9_label->TabIndex = 0;
            this->match9_label->Text = L"Match 9";
            this->match9_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // match10_panel
            // 
            this->match10_panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->match10_panel->Controls->Add(this->panel47);
            this->match10_panel->Controls->Add(this->panel48);
            this->match10_panel->Controls->Add(this->panel49);
            this->match10_panel->Location = System::Drawing::Point(3, 278);
            this->match10_panel->Margin = System::Windows::Forms::Padding(3, 105, 3, 3);
            this->match10_panel->Name = L"match10_panel";
            this->match10_panel->Size = System::Drawing::Size(246, 120);
            this->match10_panel->TabIndex = 2;
            // 
            // panel47
            // 
            this->panel47->Controls->Add(this->match10_team2_rank);
            this->panel47->Controls->Add(this->match10_team2);
            this->panel47->Controls->Add(this->match10_teamlogo2);
            this->panel47->Location = System::Drawing::Point(0, 70);
            this->panel47->Name = L"panel47";
            this->panel47->Size = System::Drawing::Size(246, 40);
            this->panel47->TabIndex = 2;
            // 
            // match10_team2_rank
            // 
            this->match10_team2_rank->AutoSize = true;
            this->match10_team2_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match10_team2_rank->Location = System::Drawing::Point(211, 7);
            this->match10_team2_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match10_team2_rank->Name = L"match10_team2_rank";
            this->match10_team2_rank->Size = System::Drawing::Size(23, 27);
            this->match10_team2_rank->TabIndex = 3;
            this->match10_team2_rank->Text = L"2";
            // 
            // match10_team2
            // 
            this->match10_team2->AutoSize = true;
            this->match10_team2->ForeColor = System::Drawing::SystemColors::Control;
            this->match10_team2->Location = System::Drawing::Point(75, 7);
            this->match10_team2->Name = L"match10_team2";
            this->match10_team2->Size = System::Drawing::Size(68, 27);
            this->match10_team2->TabIndex = 2;
            this->match10_team2->Text = L"Team2";
            // 
            // match10_teamlogo2
            // 
            this->match10_teamlogo2->Location = System::Drawing::Point(7, 6);
            this->match10_teamlogo2->Name = L"match10_teamlogo2";
            this->match10_teamlogo2->Size = System::Drawing::Size(64, 34);
            this->match10_teamlogo2->TabIndex = 1;
            this->match10_teamlogo2->TabStop = false;
            // 
            // panel48
            // 
            this->panel48->Controls->Add(this->match10_team1_rank);
            this->panel48->Controls->Add(this->match10_team1);
            this->panel48->Controls->Add(this->match10_teamlogo1);
            this->panel48->Location = System::Drawing::Point(0, 30);
            this->panel48->Name = L"panel48";
            this->panel48->Size = System::Drawing::Size(246, 40);
            this->panel48->TabIndex = 1;
            // 
            // match10_team1_rank
            // 
            this->match10_team1_rank->AutoSize = true;
            this->match10_team1_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match10_team1_rank->Location = System::Drawing::Point(211, 3);
            this->match10_team1_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match10_team1_rank->Name = L"match10_team1_rank";
            this->match10_team1_rank->Size = System::Drawing::Size(19, 27);
            this->match10_team1_rank->TabIndex = 2;
            this->match10_team1_rank->Text = L"1";
            // 
            // match10_team1
            // 
            this->match10_team1->AutoSize = true;
            this->match10_team1->ForeColor = System::Drawing::SystemColors::Control;
            this->match10_team1->Location = System::Drawing::Point(75, 3);
            this->match10_team1->Name = L"match10_team1";
            this->match10_team1->Size = System::Drawing::Size(64, 27);
            this->match10_team1->TabIndex = 1;
            this->match10_team1->Text = L"Team1";
            // 
            // match10_teamlogo1
            // 
            this->match10_teamlogo1->Location = System::Drawing::Point(7, 3);
            this->match10_teamlogo1->Name = L"match10_teamlogo1";
            this->match10_teamlogo1->Size = System::Drawing::Size(64, 34);
            this->match10_teamlogo1->TabIndex = 0;
            this->match10_teamlogo1->TabStop = false;
            // 
            // panel49
            // 
            this->panel49->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->panel49->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panel49->Controls->Add(this->panel50);
            this->panel49->Controls->Add(this->match10_date);
            this->panel49->Controls->Add(this->match10_label);
            this->panel49->Location = System::Drawing::Point(0, 0);
            this->panel49->Name = L"panel49";
            this->panel49->Size = System::Drawing::Size(246, 27);
            this->panel49->TabIndex = 0;
            // 
            // panel50
            // 
            this->panel50->Location = System::Drawing::Point(2, 29);
            this->panel50->Name = L"panel50";
            this->panel50->Size = System::Drawing::Size(240, 29);
            this->panel50->TabIndex = 1;
            // 
            // match10_date
            // 
            this->match10_date->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->match10_date->AutoSize = true;
            this->match10_date->ForeColor = System::Drawing::SystemColors::Control;
            this->match10_date->Location = System::Drawing::Point(116, -1);
            this->match10_date->Name = L"match10_date";
            this->match10_date->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->match10_date->Size = System::Drawing::Size(129, 27);
            this->match10_date->TabIndex = 1;
            this->match10_date->Text = L"01 NOV | 8:00";
            this->match10_date->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // match10_label
            // 
            this->match10_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->match10_label->AutoSize = true;
            this->match10_label->ForeColor = System::Drawing::SystemColors::Control;
            this->match10_label->Location = System::Drawing::Point(4, 0);
            this->match10_label->Name = L"match10_label";
            this->match10_label->Size = System::Drawing::Size(91, 27);
            this->match10_label->TabIndex = 0;
            this->match10_label->Text = L"Match 10";
            this->match10_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // match11_panel
            // 
            this->match11_panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->match11_panel->Controls->Add(this->panel52);
            this->match11_panel->Controls->Add(this->panel53);
            this->match11_panel->Controls->Add(this->panel54);
            this->match11_panel->Location = System::Drawing::Point(3, 506);
            this->match11_panel->Margin = System::Windows::Forms::Padding(3, 105, 3, 3);
            this->match11_panel->Name = L"match11_panel";
            this->match11_panel->Size = System::Drawing::Size(246, 120);
            this->match11_panel->TabIndex = 3;
            // 
            // panel52
            // 
            this->panel52->Controls->Add(this->match11_team2_rank);
            this->panel52->Controls->Add(this->match11_team2);
            this->panel52->Controls->Add(this->match11_teamlogo2);
            this->panel52->Location = System::Drawing::Point(0, 70);
            this->panel52->Name = L"panel52";
            this->panel52->Size = System::Drawing::Size(246, 40);
            this->panel52->TabIndex = 2;
            // 
            // match11_team2_rank
            // 
            this->match11_team2_rank->AutoSize = true;
            this->match11_team2_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match11_team2_rank->Location = System::Drawing::Point(211, 7);
            this->match11_team2_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match11_team2_rank->Name = L"match11_team2_rank";
            this->match11_team2_rank->Size = System::Drawing::Size(23, 27);
            this->match11_team2_rank->TabIndex = 3;
            this->match11_team2_rank->Text = L"2";
            // 
            // match11_team2
            // 
            this->match11_team2->AutoSize = true;
            this->match11_team2->ForeColor = System::Drawing::SystemColors::Control;
            this->match11_team2->Location = System::Drawing::Point(75, 7);
            this->match11_team2->Name = L"match11_team2";
            this->match11_team2->Size = System::Drawing::Size(68, 27);
            this->match11_team2->TabIndex = 2;
            this->match11_team2->Text = L"Team2";
            // 
            // match11_teamlogo2
            // 
            this->match11_teamlogo2->Location = System::Drawing::Point(7, 6);
            this->match11_teamlogo2->Name = L"match11_teamlogo2";
            this->match11_teamlogo2->Size = System::Drawing::Size(64, 34);
            this->match11_teamlogo2->TabIndex = 1;
            this->match11_teamlogo2->TabStop = false;
            // 
            // panel53
            // 
            this->panel53->Controls->Add(this->match11_team1_rank);
            this->panel53->Controls->Add(this->match11_team1);
            this->panel53->Controls->Add(this->match11_teamlogo1);
            this->panel53->Location = System::Drawing::Point(0, 30);
            this->panel53->Name = L"panel53";
            this->panel53->Size = System::Drawing::Size(246, 40);
            this->panel53->TabIndex = 1;
            // 
            // match11_team1_rank
            // 
            this->match11_team1_rank->AutoSize = true;
            this->match11_team1_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match11_team1_rank->Location = System::Drawing::Point(211, 3);
            this->match11_team1_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match11_team1_rank->Name = L"match11_team1_rank";
            this->match11_team1_rank->Size = System::Drawing::Size(19, 27);
            this->match11_team1_rank->TabIndex = 2;
            this->match11_team1_rank->Text = L"1";
            // 
            // match11_team1
            // 
            this->match11_team1->AutoSize = true;
            this->match11_team1->ForeColor = System::Drawing::SystemColors::Control;
            this->match11_team1->Location = System::Drawing::Point(75, 3);
            this->match11_team1->Name = L"match11_team1";
            this->match11_team1->Size = System::Drawing::Size(64, 27);
            this->match11_team1->TabIndex = 1;
            this->match11_team1->Text = L"Team1";
            // 
            // match11_teamlogo1
            // 
            this->match11_teamlogo1->Location = System::Drawing::Point(7, 3);
            this->match11_teamlogo1->Name = L"match11_teamlogo1";
            this->match11_teamlogo1->Size = System::Drawing::Size(64, 34);
            this->match11_teamlogo1->TabIndex = 0;
            this->match11_teamlogo1->TabStop = false;
            // 
            // panel54
            // 
            this->panel54->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->panel54->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panel54->Controls->Add(this->panel55);
            this->panel54->Controls->Add(this->match11_date);
            this->panel54->Controls->Add(this->matc11_label);
            this->panel54->Location = System::Drawing::Point(0, 0);
            this->panel54->Name = L"panel54";
            this->panel54->Size = System::Drawing::Size(246, 27);
            this->panel54->TabIndex = 0;
            // 
            // panel55
            // 
            this->panel55->Location = System::Drawing::Point(2, 29);
            this->panel55->Name = L"panel55";
            this->panel55->Size = System::Drawing::Size(240, 29);
            this->panel55->TabIndex = 1;
            // 
            // match11_date
            // 
            this->match11_date->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->match11_date->AutoSize = true;
            this->match11_date->ForeColor = System::Drawing::SystemColors::Control;
            this->match11_date->Location = System::Drawing::Point(116, -1);
            this->match11_date->Name = L"match11_date";
            this->match11_date->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->match11_date->Size = System::Drawing::Size(129, 27);
            this->match11_date->TabIndex = 1;
            this->match11_date->Text = L"01 NOV | 8:00";
            this->match11_date->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // matc11_label
            // 
            this->matc11_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->matc11_label->AutoSize = true;
            this->matc11_label->ForeColor = System::Drawing::SystemColors::Control;
            this->matc11_label->Location = System::Drawing::Point(4, 0);
            this->matc11_label->Name = L"matc11_label";
            this->matc11_label->Size = System::Drawing::Size(87, 27);
            this->matc11_label->TabIndex = 0;
            this->matc11_label->Text = L"Match 11";
            this->matc11_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // match12_panel
            // 
            this->match12_panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->match12_panel->Controls->Add(this->panel57);
            this->match12_panel->Controls->Add(this->panel58);
            this->match12_panel->Controls->Add(this->panel59);
            this->match12_panel->Location = System::Drawing::Point(3, 734);
            this->match12_panel->Margin = System::Windows::Forms::Padding(3, 105, 3, 3);
            this->match12_panel->Name = L"match12_panel";
            this->match12_panel->Size = System::Drawing::Size(246, 120);
            this->match12_panel->TabIndex = 4;
            // 
            // panel57
            // 
            this->panel57->Controls->Add(this->match12_team2_rank);
            this->panel57->Controls->Add(this->match12_team2);
            this->panel57->Controls->Add(this->match12_teamlogo2);
            this->panel57->Location = System::Drawing::Point(0, 70);
            this->panel57->Name = L"panel57";
            this->panel57->Size = System::Drawing::Size(246, 40);
            this->panel57->TabIndex = 2;
            // 
            // match12_team2_rank
            // 
            this->match12_team2_rank->AutoSize = true;
            this->match12_team2_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match12_team2_rank->Location = System::Drawing::Point(211, 7);
            this->match12_team2_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match12_team2_rank->Name = L"match12_team2_rank";
            this->match12_team2_rank->Size = System::Drawing::Size(23, 27);
            this->match12_team2_rank->TabIndex = 3;
            this->match12_team2_rank->Text = L"2";
            // 
            // match12_team2
            // 
            this->match12_team2->AutoSize = true;
            this->match12_team2->ForeColor = System::Drawing::SystemColors::Control;
            this->match12_team2->Location = System::Drawing::Point(75, 7);
            this->match12_team2->Name = L"match12_team2";
            this->match12_team2->Size = System::Drawing::Size(68, 27);
            this->match12_team2->TabIndex = 2;
            this->match12_team2->Text = L"Team2";
            // 
            // match12_teamlogo2
            // 
            this->match12_teamlogo2->Location = System::Drawing::Point(7, 6);
            this->match12_teamlogo2->Name = L"match12_teamlogo2";
            this->match12_teamlogo2->Size = System::Drawing::Size(64, 34);
            this->match12_teamlogo2->TabIndex = 1;
            this->match12_teamlogo2->TabStop = false;
            // 
            // panel58
            // 
            this->panel58->Controls->Add(this->match12_team1_rank);
            this->panel58->Controls->Add(this->match12_team1);
            this->panel58->Controls->Add(this->match12_teamlogo1);
            this->panel58->Location = System::Drawing::Point(0, 30);
            this->panel58->Name = L"panel58";
            this->panel58->Size = System::Drawing::Size(246, 40);
            this->panel58->TabIndex = 1;
            // 
            // match12_team1_rank
            // 
            this->match12_team1_rank->AutoSize = true;
            this->match12_team1_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match12_team1_rank->Location = System::Drawing::Point(211, 3);
            this->match12_team1_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match12_team1_rank->Name = L"match12_team1_rank";
            this->match12_team1_rank->Size = System::Drawing::Size(19, 27);
            this->match12_team1_rank->TabIndex = 2;
            this->match12_team1_rank->Text = L"1";
            // 
            // match12_team1
            // 
            this->match12_team1->AutoSize = true;
            this->match12_team1->ForeColor = System::Drawing::SystemColors::Control;
            this->match12_team1->Location = System::Drawing::Point(75, 3);
            this->match12_team1->Name = L"match12_team1";
            this->match12_team1->Size = System::Drawing::Size(64, 27);
            this->match12_team1->TabIndex = 1;
            this->match12_team1->Text = L"Team1";
            // 
            // match12_teamlogo1
            // 
            this->match12_teamlogo1->Location = System::Drawing::Point(7, 3);
            this->match12_teamlogo1->Name = L"match12_teamlogo1";
            this->match12_teamlogo1->Size = System::Drawing::Size(64, 34);
            this->match12_teamlogo1->TabIndex = 0;
            this->match12_teamlogo1->TabStop = false;
            // 
            // panel59
            // 
            this->panel59->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->panel59->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panel59->Controls->Add(this->panel60);
            this->panel59->Controls->Add(this->match12_date);
            this->panel59->Controls->Add(this->match12_label);
            this->panel59->Location = System::Drawing::Point(0, 0);
            this->panel59->Name = L"panel59";
            this->panel59->Size = System::Drawing::Size(246, 27);
            this->panel59->TabIndex = 0;
            // 
            // panel60
            // 
            this->panel60->Location = System::Drawing::Point(2, 29);
            this->panel60->Name = L"panel60";
            this->panel60->Size = System::Drawing::Size(240, 29);
            this->panel60->TabIndex = 1;
            // 
            // match12_date
            // 
            this->match12_date->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->match12_date->AutoSize = true;
            this->match12_date->ForeColor = System::Drawing::SystemColors::Control;
            this->match12_date->Location = System::Drawing::Point(116, -1);
            this->match12_date->Name = L"match12_date";
            this->match12_date->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->match12_date->Size = System::Drawing::Size(129, 27);
            this->match12_date->TabIndex = 1;
            this->match12_date->Text = L"01 NOV | 8:00";
            this->match12_date->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // match12_label
            // 
            this->match12_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->match12_label->AutoSize = true;
            this->match12_label->ForeColor = System::Drawing::SystemColors::Control;
            this->match12_label->Location = System::Drawing::Point(4, 0);
            this->match12_label->Name = L"match12_label";
            this->match12_label->Size = System::Drawing::Size(91, 27);
            this->match12_label->TabIndex = 0;
            this->match12_label->Text = L"Match 12";
            this->match12_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // flowLayoutPanel2
            // 
            this->flowLayoutPanel2->Controls->Add(this->match1_panel);
            this->flowLayoutPanel2->Controls->Add(this->match2_panel);
            this->flowLayoutPanel2->Controls->Add(this->match3_panel);
            this->flowLayoutPanel2->Controls->Add(this->match4_panel);
            this->flowLayoutPanel2->Controls->Add(this->match5_panel);
            this->flowLayoutPanel2->Controls->Add(this->match6_panel);
            this->flowLayoutPanel2->Controls->Add(this->match7_panel);
            this->flowLayoutPanel2->Controls->Add(this->match8_panel);
            this->flowLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->flowLayoutPanel2->Location = System::Drawing::Point(4, 4);
            this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
            this->flowLayoutPanel2->Size = System::Drawing::Size(245, 960);
            this->flowLayoutPanel2->TabIndex = 0;
            // 
            // match1_panel
            // 
            this->match1_panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->match1_panel->Controls->Add(this->panel5);
            this->match1_panel->Controls->Add(this->panel4);
            this->match1_panel->Controls->Add(this->panel2);
            this->match1_panel->Location = System::Drawing::Point(3, 3);
            this->match1_panel->Name = L"match1_panel";
            this->match1_panel->Size = System::Drawing::Size(246, 113);
            this->match1_panel->TabIndex = 0;
            // 
            // panel5
            // 
            this->panel5->Controls->Add(this->match1_team2_rank);
            this->panel5->Controls->Add(this->match1_team2);
            this->panel5->Controls->Add(this->match1_teamlogo2);
            this->panel5->Location = System::Drawing::Point(0, 65);
            this->panel5->Name = L"panel5";
            this->panel5->Size = System::Drawing::Size(246, 35);
            this->panel5->TabIndex = 2;
            // 
            // match1_team2_rank
            // 
            this->match1_team2_rank->AutoSize = true;
            this->match1_team2_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match1_team2_rank->Location = System::Drawing::Point(211, 7);
            this->match1_team2_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match1_team2_rank->Name = L"match1_team2_rank";
            this->match1_team2_rank->Size = System::Drawing::Size(23, 27);
            this->match1_team2_rank->TabIndex = 3;
            this->match1_team2_rank->Text = L"2";
            // 
            // match1_team2
            // 
            this->match1_team2->AutoSize = true;
            this->match1_team2->ForeColor = System::Drawing::SystemColors::Control;
            this->match1_team2->Location = System::Drawing::Point(74, 7);
            this->match1_team2->Name = L"match1_team2";
            this->match1_team2->Size = System::Drawing::Size(68, 27);
            this->match1_team2->TabIndex = 2;
            this->match1_team2->Text = L"Team2";
            // 
            // match1_teamlogo2
            // 
            this->match1_teamlogo2->Location = System::Drawing::Point(7, 0);
            this->match1_teamlogo2->Name = L"match1_teamlogo2";
            this->match1_teamlogo2->Size = System::Drawing::Size(64, 35);
            this->match1_teamlogo2->TabIndex = 1;
            this->match1_teamlogo2->TabStop = false;
            // 
            // panel4
            // 
            this->panel4->Controls->Add(this->match1_team1_rank);
            this->panel4->Controls->Add(this->match1_team1);
            this->panel4->Controls->Add(this->match1_teamlogo1);
            this->panel4->Location = System::Drawing::Point(0, 30);
            this->panel4->Name = L"panel4";
            this->panel4->Size = System::Drawing::Size(246, 35);
            this->panel4->TabIndex = 1;
            // 
            // match1_team1_rank
            // 
            this->match1_team1_rank->AutoSize = true;
            this->match1_team1_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match1_team1_rank->Location = System::Drawing::Point(211, 3);
            this->match1_team1_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match1_team1_rank->Name = L"match1_team1_rank";
            this->match1_team1_rank->Size = System::Drawing::Size(19, 27);
            this->match1_team1_rank->TabIndex = 2;
            this->match1_team1_rank->Text = L"1";
            // 
            // match1_team1
            // 
            this->match1_team1->AutoSize = true;
            this->match1_team1->ForeColor = System::Drawing::SystemColors::Control;
            this->match1_team1->Location = System::Drawing::Point(74, 2);
            this->match1_team1->Name = L"match1_team1";
            this->match1_team1->Size = System::Drawing::Size(64, 27);
            this->match1_team1->TabIndex = 1;
            this->match1_team1->Text = L"Team1";
            // 
            // match1_teamlogo1
            // 
            this->match1_teamlogo1->Location = System::Drawing::Point(7, 0);
            this->match1_teamlogo1->Name = L"match1_teamlogo1";
            this->match1_teamlogo1->Size = System::Drawing::Size(64, 35);
            this->match1_teamlogo1->TabIndex = 0;
            this->match1_teamlogo1->TabStop = false;
            // 
            // panel2
            // 
            this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panel2->Controls->Add(this->panel3);
            this->panel2->Controls->Add(this->match1_date);
            this->panel2->Controls->Add(this->match1_label);
            this->panel2->Location = System::Drawing::Point(0, 0);
            this->panel2->Name = L"panel2";
            this->panel2->Size = System::Drawing::Size(246, 27);
            this->panel2->TabIndex = 0;
            // 
            // panel3
            // 
            this->panel3->Location = System::Drawing::Point(2, 29);
            this->panel3->Name = L"panel3";
            this->panel3->Size = System::Drawing::Size(240, 29);
            this->panel3->TabIndex = 1;
            // 
            // match1_date
            // 
            this->match1_date->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->match1_date->AutoSize = true;
            this->match1_date->ForeColor = System::Drawing::SystemColors::Control;
            this->match1_date->Location = System::Drawing::Point(116, -1);
            this->match1_date->Name = L"match1_date";
            this->match1_date->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->match1_date->Size = System::Drawing::Size(129, 27);
            this->match1_date->TabIndex = 1;
            this->match1_date->Text = L"01 NOV | 8:00";
            this->match1_date->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // match1_label
            // 
            this->match1_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->match1_label->AutoSize = true;
            this->match1_label->ForeColor = System::Drawing::SystemColors::Control;
            this->match1_label->Location = System::Drawing::Point(4, 0);
            this->match1_label->Name = L"match1_label";
            this->match1_label->Size = System::Drawing::Size(80, 27);
            this->match1_label->TabIndex = 0;
            this->match1_label->Text = L"Match 1";
            this->match1_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // match2_panel
            // 
            this->match2_panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->match2_panel->Controls->Add(this->panel7);
            this->match2_panel->Controls->Add(this->panel8);
            this->match2_panel->Controls->Add(this->panel9);
            this->match2_panel->Location = System::Drawing::Point(3, 122);
            this->match2_panel->Name = L"match2_panel";
            this->match2_panel->Size = System::Drawing::Size(246, 113);
            this->match2_panel->TabIndex = 1;
            // 
            // panel7
            // 
            this->panel7->Controls->Add(this->match2_team2_rank);
            this->panel7->Controls->Add(this->match2_team2);
            this->panel7->Controls->Add(this->match2_teamlogo2);
            this->panel7->Location = System::Drawing::Point(0, 65);
            this->panel7->Name = L"panel7";
            this->panel7->Size = System::Drawing::Size(246, 35);
            this->panel7->TabIndex = 2;
            // 
            // match2_team2_rank
            // 
            this->match2_team2_rank->AutoSize = true;
            this->match2_team2_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match2_team2_rank->Location = System::Drawing::Point(211, 7);
            this->match2_team2_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match2_team2_rank->Name = L"match2_team2_rank";
            this->match2_team2_rank->Size = System::Drawing::Size(23, 27);
            this->match2_team2_rank->TabIndex = 3;
            this->match2_team2_rank->Text = L"2";
            // 
            // match2_team2
            // 
            this->match2_team2->AutoSize = true;
            this->match2_team2->ForeColor = System::Drawing::SystemColors::Control;
            this->match2_team2->Location = System::Drawing::Point(74, 7);
            this->match2_team2->Name = L"match2_team2";
            this->match2_team2->Size = System::Drawing::Size(68, 27);
            this->match2_team2->TabIndex = 2;
            this->match2_team2->Text = L"Team2";
            // 
            // match2_teamlogo2
            // 
            this->match2_teamlogo2->Location = System::Drawing::Point(7, 0);
            this->match2_teamlogo2->Name = L"match2_teamlogo2";
            this->match2_teamlogo2->Size = System::Drawing::Size(64, 35);
            this->match2_teamlogo2->TabIndex = 1;
            this->match2_teamlogo2->TabStop = false;
            // 
            // panel8
            // 
            this->panel8->Controls->Add(this->match2_team1_rank);
            this->panel8->Controls->Add(this->match2_team1);
            this->panel8->Controls->Add(this->match2_teamlogo1);
            this->panel8->Location = System::Drawing::Point(0, 30);
            this->panel8->Name = L"panel8";
            this->panel8->Size = System::Drawing::Size(246, 35);
            this->panel8->TabIndex = 1;
            // 
            // match2_team1_rank
            // 
            this->match2_team1_rank->AutoSize = true;
            this->match2_team1_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match2_team1_rank->Location = System::Drawing::Point(211, 3);
            this->match2_team1_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match2_team1_rank->Name = L"match2_team1_rank";
            this->match2_team1_rank->Size = System::Drawing::Size(19, 27);
            this->match2_team1_rank->TabIndex = 2;
            this->match2_team1_rank->Text = L"1";
            // 
            // match2_team1
            // 
            this->match2_team1->AutoSize = true;
            this->match2_team1->ForeColor = System::Drawing::SystemColors::Control;
            this->match2_team1->Location = System::Drawing::Point(74, 3);
            this->match2_team1->Name = L"match2_team1";
            this->match2_team1->Size = System::Drawing::Size(64, 27);
            this->match2_team1->TabIndex = 1;
            this->match2_team1->Text = L"Team1";
            // 
            // match2_teamlogo1
            // 
            this->match2_teamlogo1->Location = System::Drawing::Point(7, 0);
            this->match2_teamlogo1->Name = L"match2_teamlogo1";
            this->match2_teamlogo1->Size = System::Drawing::Size(64, 35);
            this->match2_teamlogo1->TabIndex = 0;
            this->match2_teamlogo1->TabStop = false;
            // 
            // panel9
            // 
            this->panel9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->panel9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panel9->Controls->Add(this->panel10);
            this->panel9->Controls->Add(this->match2_date);
            this->panel9->Controls->Add(this->match2_label);
            this->panel9->Location = System::Drawing::Point(0, 0);
            this->panel9->Name = L"panel9";
            this->panel9->Size = System::Drawing::Size(246, 27);
            this->panel9->TabIndex = 0;
            // 
            // panel10
            // 
            this->panel10->Location = System::Drawing::Point(2, 29);
            this->panel10->Name = L"panel10";
            this->panel10->Size = System::Drawing::Size(240, 29);
            this->panel10->TabIndex = 1;
            // 
            // match2_date
            // 
            this->match2_date->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->match2_date->AutoSize = true;
            this->match2_date->ForeColor = System::Drawing::SystemColors::Control;
            this->match2_date->Location = System::Drawing::Point(116, -1);
            this->match2_date->Name = L"match2_date";
            this->match2_date->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->match2_date->Size = System::Drawing::Size(129, 27);
            this->match2_date->TabIndex = 1;
            this->match2_date->Text = L"01 NOV | 8:00";
            this->match2_date->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // match2_label
            // 
            this->match2_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->match2_label->AutoSize = true;
            this->match2_label->ForeColor = System::Drawing::SystemColors::Control;
            this->match2_label->Location = System::Drawing::Point(4, 0);
            this->match2_label->Name = L"match2_label";
            this->match2_label->Size = System::Drawing::Size(84, 27);
            this->match2_label->TabIndex = 0;
            this->match2_label->Text = L"Match 2";
            this->match2_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // match3_panel
            // 
            this->match3_panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->match3_panel->Controls->Add(this->panel12);
            this->match3_panel->Controls->Add(this->panel13);
            this->match3_panel->Controls->Add(this->panel14);
            this->match3_panel->Location = System::Drawing::Point(3, 241);
            this->match3_panel->Name = L"match3_panel";
            this->match3_panel->Size = System::Drawing::Size(246, 113);
            this->match3_panel->TabIndex = 2;
            // 
            // panel12
            // 
            this->panel12->Controls->Add(this->match3_team2_rank);
            this->panel12->Controls->Add(this->match3_team2);
            this->panel12->Controls->Add(this->match3_teamlogo2);
            this->panel12->Location = System::Drawing::Point(0, 65);
            this->panel12->Name = L"panel12";
            this->panel12->Size = System::Drawing::Size(246, 35);
            this->panel12->TabIndex = 2;
            // 
            // match3_team2_rank
            // 
            this->match3_team2_rank->AutoSize = true;
            this->match3_team2_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match3_team2_rank->Location = System::Drawing::Point(211, 7);
            this->match3_team2_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match3_team2_rank->Name = L"match3_team2_rank";
            this->match3_team2_rank->Size = System::Drawing::Size(23, 27);
            this->match3_team2_rank->TabIndex = 3;
            this->match3_team2_rank->Text = L"2";
            // 
            // match3_team2
            // 
            this->match3_team2->AutoSize = true;
            this->match3_team2->ForeColor = System::Drawing::SystemColors::Control;
            this->match3_team2->Location = System::Drawing::Point(74, 4);
            this->match3_team2->Name = L"match3_team2";
            this->match3_team2->Size = System::Drawing::Size(68, 27);
            this->match3_team2->TabIndex = 2;
            this->match3_team2->Text = L"Team2";
            // 
            // match3_teamlogo2
            // 
            this->match3_teamlogo2->Location = System::Drawing::Point(7, 0);
            this->match3_teamlogo2->Name = L"match3_teamlogo2";
            this->match3_teamlogo2->Size = System::Drawing::Size(64, 35);
            this->match3_teamlogo2->TabIndex = 1;
            this->match3_teamlogo2->TabStop = false;
            // 
            // panel13
            // 
            this->panel13->Controls->Add(this->match3_team1_rank);
            this->panel13->Controls->Add(this->match3_team1);
            this->panel13->Controls->Add(this->match3_teamlogo1);
            this->panel13->Location = System::Drawing::Point(0, 30);
            this->panel13->Name = L"panel13";
            this->panel13->Size = System::Drawing::Size(246, 35);
            this->panel13->TabIndex = 1;
            // 
            // match3_team1_rank
            // 
            this->match3_team1_rank->AutoSize = true;
            this->match3_team1_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match3_team1_rank->Location = System::Drawing::Point(211, 3);
            this->match3_team1_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match3_team1_rank->Name = L"match3_team1_rank";
            this->match3_team1_rank->Size = System::Drawing::Size(19, 27);
            this->match3_team1_rank->TabIndex = 2;
            this->match3_team1_rank->Text = L"1";
            // 
            // match3_team1
            // 
            this->match3_team1->AutoSize = true;
            this->match3_team1->ForeColor = System::Drawing::SystemColors::Control;
            this->match3_team1->Location = System::Drawing::Point(74, 3);
            this->match3_team1->Name = L"match3_team1";
            this->match3_team1->Size = System::Drawing::Size(64, 27);
            this->match3_team1->TabIndex = 1;
            this->match3_team1->Text = L"Team1";
            // 
            // match3_teamlogo1
            // 
            this->match3_teamlogo1->Location = System::Drawing::Point(7, 0);
            this->match3_teamlogo1->Name = L"match3_teamlogo1";
            this->match3_teamlogo1->Size = System::Drawing::Size(64, 35);
            this->match3_teamlogo1->TabIndex = 0;
            this->match3_teamlogo1->TabStop = false;
            // 
            // panel14
            // 
            this->panel14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->panel14->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panel14->Controls->Add(this->panel15);
            this->panel14->Controls->Add(this->match3_date);
            this->panel14->Controls->Add(this->match3_label);
            this->panel14->Location = System::Drawing::Point(0, 0);
            this->panel14->Name = L"panel14";
            this->panel14->Size = System::Drawing::Size(246, 27);
            this->panel14->TabIndex = 0;
            // 
            // panel15
            // 
            this->panel15->Location = System::Drawing::Point(2, 29);
            this->panel15->Name = L"panel15";
            this->panel15->Size = System::Drawing::Size(240, 29);
            this->panel15->TabIndex = 1;
            // 
            // match3_date
            // 
            this->match3_date->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->match3_date->AutoSize = true;
            this->match3_date->ForeColor = System::Drawing::SystemColors::Control;
            this->match3_date->Location = System::Drawing::Point(116, -1);
            this->match3_date->Name = L"match3_date";
            this->match3_date->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->match3_date->Size = System::Drawing::Size(129, 27);
            this->match3_date->TabIndex = 1;
            this->match3_date->Text = L"01 NOV | 8:00";
            this->match3_date->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // match3_label
            // 
            this->match3_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->match3_label->AutoSize = true;
            this->match3_label->ForeColor = System::Drawing::SystemColors::Control;
            this->match3_label->Location = System::Drawing::Point(4, 0);
            this->match3_label->Name = L"match3_label";
            this->match3_label->Size = System::Drawing::Size(84, 27);
            this->match3_label->TabIndex = 0;
            this->match3_label->Text = L"Match 3";
            this->match3_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // match4_panel
            // 
            this->match4_panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->match4_panel->Controls->Add(this->panel17);
            this->match4_panel->Controls->Add(this->panel18);
            this->match4_panel->Controls->Add(this->panel19);
            this->match4_panel->Location = System::Drawing::Point(3, 360);
            this->match4_panel->Name = L"match4_panel";
            this->match4_panel->Size = System::Drawing::Size(246, 113);
            this->match4_panel->TabIndex = 3;
            // 
            // panel17
            // 
            this->panel17->Controls->Add(this->match4_team2_rank);
            this->panel17->Controls->Add(this->match4_team2);
            this->panel17->Controls->Add(this->match4_teamlogo2);
            this->panel17->Location = System::Drawing::Point(0, 65);
            this->panel17->Name = L"panel17";
            this->panel17->Size = System::Drawing::Size(246, 35);
            this->panel17->TabIndex = 2;
            // 
            // match4_team2_rank
            // 
            this->match4_team2_rank->AutoSize = true;
            this->match4_team2_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match4_team2_rank->Location = System::Drawing::Point(211, 7);
            this->match4_team2_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match4_team2_rank->Name = L"match4_team2_rank";
            this->match4_team2_rank->Size = System::Drawing::Size(23, 27);
            this->match4_team2_rank->TabIndex = 3;
            this->match4_team2_rank->Text = L"2";
            // 
            // match4_team2
            // 
            this->match4_team2->AutoSize = true;
            this->match4_team2->ForeColor = System::Drawing::SystemColors::Control;
            this->match4_team2->Location = System::Drawing::Point(74, 8);
            this->match4_team2->Name = L"match4_team2";
            this->match4_team2->Size = System::Drawing::Size(68, 27);
            this->match4_team2->TabIndex = 2;
            this->match4_team2->Text = L"Team2";
            // 
            // match4_teamlogo2
            // 
            this->match4_teamlogo2->Location = System::Drawing::Point(7, 0);
            this->match4_teamlogo2->Name = L"match4_teamlogo2";
            this->match4_teamlogo2->Size = System::Drawing::Size(64, 35);
            this->match4_teamlogo2->TabIndex = 1;
            this->match4_teamlogo2->TabStop = false;
            // 
            // panel18
            // 
            this->panel18->Controls->Add(this->match4_team1_rank);
            this->panel18->Controls->Add(this->match4_team1);
            this->panel18->Controls->Add(this->match4_teamlogo1);
            this->panel18->Location = System::Drawing::Point(0, 30);
            this->panel18->Name = L"panel18";
            this->panel18->Size = System::Drawing::Size(246, 35);
            this->panel18->TabIndex = 1;
            // 
            // match4_team1_rank
            // 
            this->match4_team1_rank->AutoSize = true;
            this->match4_team1_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match4_team1_rank->Location = System::Drawing::Point(211, 3);
            this->match4_team1_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match4_team1_rank->Name = L"match4_team1_rank";
            this->match4_team1_rank->Size = System::Drawing::Size(19, 27);
            this->match4_team1_rank->TabIndex = 2;
            this->match4_team1_rank->Text = L"1";
            // 
            // match4_team1
            // 
            this->match4_team1->AutoSize = true;
            this->match4_team1->ForeColor = System::Drawing::SystemColors::Control;
            this->match4_team1->Location = System::Drawing::Point(74, 2);
            this->match4_team1->Name = L"match4_team1";
            this->match4_team1->Size = System::Drawing::Size(64, 27);
            this->match4_team1->TabIndex = 1;
            this->match4_team1->Text = L"Team1";
            // 
            // match4_teamlogo1
            // 
            this->match4_teamlogo1->Location = System::Drawing::Point(7, 0);
            this->match4_teamlogo1->Name = L"match4_teamlogo1";
            this->match4_teamlogo1->Size = System::Drawing::Size(64, 35);
            this->match4_teamlogo1->TabIndex = 0;
            this->match4_teamlogo1->TabStop = false;
            // 
            // panel19
            // 
            this->panel19->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->panel19->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panel19->Controls->Add(this->panel20);
            this->panel19->Controls->Add(this->match4_date);
            this->panel19->Controls->Add(this->match4_label);
            this->panel19->Location = System::Drawing::Point(0, 0);
            this->panel19->Name = L"panel19";
            this->panel19->Size = System::Drawing::Size(246, 27);
            this->panel19->TabIndex = 0;
            // 
            // panel20
            // 
            this->panel20->Location = System::Drawing::Point(2, 29);
            this->panel20->Name = L"panel20";
            this->panel20->Size = System::Drawing::Size(240, 29);
            this->panel20->TabIndex = 1;
            // 
            // match4_date
            // 
            this->match4_date->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->match4_date->AutoSize = true;
            this->match4_date->ForeColor = System::Drawing::SystemColors::Control;
            this->match4_date->Location = System::Drawing::Point(116, -1);
            this->match4_date->Name = L"match4_date";
            this->match4_date->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->match4_date->Size = System::Drawing::Size(129, 27);
            this->match4_date->TabIndex = 1;
            this->match4_date->Text = L"01 NOV | 8:00";
            this->match4_date->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // match4_label
            // 
            this->match4_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->match4_label->AutoSize = true;
            this->match4_label->ForeColor = System::Drawing::SystemColors::Control;
            this->match4_label->Location = System::Drawing::Point(4, 0);
            this->match4_label->Name = L"match4_label";
            this->match4_label->Size = System::Drawing::Size(84, 27);
            this->match4_label->TabIndex = 0;
            this->match4_label->Text = L"Match 4";
            this->match4_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // match5_panel
            // 
            this->match5_panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->match5_panel->Controls->Add(this->panel22);
            this->match5_panel->Controls->Add(this->panel23);
            this->match5_panel->Controls->Add(this->panel24);
            this->match5_panel->Location = System::Drawing::Point(3, 479);
            this->match5_panel->Name = L"match5_panel";
            this->match5_panel->Size = System::Drawing::Size(246, 113);
            this->match5_panel->TabIndex = 4;
            // 
            // panel22
            // 
            this->panel22->Controls->Add(this->match5_team2_rank);
            this->panel22->Controls->Add(this->match5_team2);
            this->panel22->Controls->Add(this->match5_teamlogo2);
            this->panel22->Location = System::Drawing::Point(0, 65);
            this->panel22->Name = L"panel22";
            this->panel22->Size = System::Drawing::Size(246, 35);
            this->panel22->TabIndex = 2;
            // 
            // match5_team2_rank
            // 
            this->match5_team2_rank->AutoSize = true;
            this->match5_team2_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match5_team2_rank->Location = System::Drawing::Point(211, 7);
            this->match5_team2_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match5_team2_rank->Name = L"match5_team2_rank";
            this->match5_team2_rank->Size = System::Drawing::Size(23, 27);
            this->match5_team2_rank->TabIndex = 3;
            this->match5_team2_rank->Text = L"2";
            // 
            // match5_team2
            // 
            this->match5_team2->AutoSize = true;
            this->match5_team2->ForeColor = System::Drawing::SystemColors::Control;
            this->match5_team2->Location = System::Drawing::Point(74, 7);
            this->match5_team2->Name = L"match5_team2";
            this->match5_team2->Size = System::Drawing::Size(68, 27);
            this->match5_team2->TabIndex = 2;
            this->match5_team2->Text = L"Team2";
            // 
            // match5_teamlogo2
            // 
            this->match5_teamlogo2->Location = System::Drawing::Point(7, 0);
            this->match5_teamlogo2->Name = L"match5_teamlogo2";
            this->match5_teamlogo2->Size = System::Drawing::Size(64, 35);
            this->match5_teamlogo2->TabIndex = 1;
            this->match5_teamlogo2->TabStop = false;
            // 
            // panel23
            // 
            this->panel23->Controls->Add(this->match5_team1_rank);
            this->panel23->Controls->Add(this->match5_team1);
            this->panel23->Controls->Add(this->match5_teamlogo1);
            this->panel23->Location = System::Drawing::Point(0, 30);
            this->panel23->Name = L"panel23";
            this->panel23->Size = System::Drawing::Size(246, 35);
            this->panel23->TabIndex = 1;
            // 
            // match5_team1_rank
            // 
            this->match5_team1_rank->AutoSize = true;
            this->match5_team1_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match5_team1_rank->Location = System::Drawing::Point(211, 3);
            this->match5_team1_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match5_team1_rank->Name = L"match5_team1_rank";
            this->match5_team1_rank->Size = System::Drawing::Size(19, 27);
            this->match5_team1_rank->TabIndex = 2;
            this->match5_team1_rank->Text = L"1";
            // 
            // match5_team1
            // 
            this->match5_team1->AutoSize = true;
            this->match5_team1->ForeColor = System::Drawing::SystemColors::Control;
            this->match5_team1->Location = System::Drawing::Point(74, 3);
            this->match5_team1->Name = L"match5_team1";
            this->match5_team1->Size = System::Drawing::Size(64, 27);
            this->match5_team1->TabIndex = 1;
            this->match5_team1->Text = L"Team1";
            // 
            // match5_teamlogo1
            // 
            this->match5_teamlogo1->Location = System::Drawing::Point(7, 0);
            this->match5_teamlogo1->Name = L"match5_teamlogo1";
            this->match5_teamlogo1->Size = System::Drawing::Size(64, 35);
            this->match5_teamlogo1->TabIndex = 0;
            this->match5_teamlogo1->TabStop = false;
            // 
            // panel24
            // 
            this->panel24->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->panel24->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panel24->Controls->Add(this->panel25);
            this->panel24->Controls->Add(this->match5_date);
            this->panel24->Controls->Add(this->match5_label);
            this->panel24->Location = System::Drawing::Point(0, 0);
            this->panel24->Name = L"panel24";
            this->panel24->Size = System::Drawing::Size(246, 27);
            this->panel24->TabIndex = 0;
            // 
            // panel25
            // 
            this->panel25->Location = System::Drawing::Point(2, 29);
            this->panel25->Name = L"panel25";
            this->panel25->Size = System::Drawing::Size(240, 29);
            this->panel25->TabIndex = 1;
            // 
            // match5_date
            // 
            this->match5_date->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->match5_date->AutoSize = true;
            this->match5_date->ForeColor = System::Drawing::SystemColors::Control;
            this->match5_date->Location = System::Drawing::Point(116, -1);
            this->match5_date->Name = L"match5_date";
            this->match5_date->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->match5_date->Size = System::Drawing::Size(129, 27);
            this->match5_date->TabIndex = 1;
            this->match5_date->Text = L"01 NOV | 8:00";
            this->match5_date->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // match5_label
            // 
            this->match5_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->match5_label->AutoSize = true;
            this->match5_label->ForeColor = System::Drawing::SystemColors::Control;
            this->match5_label->Location = System::Drawing::Point(4, 0);
            this->match5_label->Name = L"match5_label";
            this->match5_label->Size = System::Drawing::Size(84, 27);
            this->match5_label->TabIndex = 0;
            this->match5_label->Text = L"Match 5";
            this->match5_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // match6_panel
            // 
            this->match6_panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->match6_panel->Controls->Add(this->panel27);
            this->match6_panel->Controls->Add(this->panel28);
            this->match6_panel->Controls->Add(this->panel29);
            this->match6_panel->Location = System::Drawing::Point(3, 598);
            this->match6_panel->Name = L"match6_panel";
            this->match6_panel->Size = System::Drawing::Size(246, 113);
            this->match6_panel->TabIndex = 5;
            // 
            // panel27
            // 
            this->panel27->Controls->Add(this->match6_team2_rank);
            this->panel27->Controls->Add(this->match6_team2);
            this->panel27->Controls->Add(this->match6_teamlogo2);
            this->panel27->Location = System::Drawing::Point(0, 65);
            this->panel27->Name = L"panel27";
            this->panel27->Size = System::Drawing::Size(246, 35);
            this->panel27->TabIndex = 2;
            // 
            // match6_team2_rank
            // 
            this->match6_team2_rank->AutoSize = true;
            this->match6_team2_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match6_team2_rank->Location = System::Drawing::Point(211, 7);
            this->match6_team2_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match6_team2_rank->Name = L"match6_team2_rank";
            this->match6_team2_rank->Size = System::Drawing::Size(23, 27);
            this->match6_team2_rank->TabIndex = 3;
            this->match6_team2_rank->Text = L"2";
            // 
            // match6_team2
            // 
            this->match6_team2->AutoSize = true;
            this->match6_team2->ForeColor = System::Drawing::SystemColors::Control;
            this->match6_team2->Location = System::Drawing::Point(74, 7);
            this->match6_team2->Name = L"match6_team2";
            this->match6_team2->Size = System::Drawing::Size(68, 27);
            this->match6_team2->TabIndex = 2;
            this->match6_team2->Text = L"Team2";
            // 
            // match6_teamlogo2
            // 
            this->match6_teamlogo2->Location = System::Drawing::Point(7, 0);
            this->match6_teamlogo2->Name = L"match6_teamlogo2";
            this->match6_teamlogo2->Size = System::Drawing::Size(64, 35);
            this->match6_teamlogo2->TabIndex = 1;
            this->match6_teamlogo2->TabStop = false;
            // 
            // panel28
            // 
            this->panel28->Controls->Add(this->match6_team1_rank);
            this->panel28->Controls->Add(this->match6_team1);
            this->panel28->Controls->Add(this->match6_teamlogo1);
            this->panel28->Location = System::Drawing::Point(0, 30);
            this->panel28->Name = L"panel28";
            this->panel28->Size = System::Drawing::Size(246, 35);
            this->panel28->TabIndex = 1;
            // 
            // match6_team1_rank
            // 
            this->match6_team1_rank->AutoSize = true;
            this->match6_team1_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match6_team1_rank->Location = System::Drawing::Point(211, 3);
            this->match6_team1_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match6_team1_rank->Name = L"match6_team1_rank";
            this->match6_team1_rank->Size = System::Drawing::Size(19, 27);
            this->match6_team1_rank->TabIndex = 2;
            this->match6_team1_rank->Text = L"1";
            // 
            // match6_team1
            // 
            this->match6_team1->AutoSize = true;
            this->match6_team1->ForeColor = System::Drawing::SystemColors::Control;
            this->match6_team1->Location = System::Drawing::Point(74, 3);
            this->match6_team1->Name = L"match6_team1";
            this->match6_team1->Size = System::Drawing::Size(64, 27);
            this->match6_team1->TabIndex = 1;
            this->match6_team1->Text = L"Team1";
            // 
            // match6_teamlogo1
            // 
            this->match6_teamlogo1->Location = System::Drawing::Point(7, 0);
            this->match6_teamlogo1->Name = L"match6_teamlogo1";
            this->match6_teamlogo1->Size = System::Drawing::Size(64, 35);
            this->match6_teamlogo1->TabIndex = 0;
            this->match6_teamlogo1->TabStop = false;
            // 
            // panel29
            // 
            this->panel29->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->panel29->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panel29->Controls->Add(this->panel30);
            this->panel29->Controls->Add(this->match6_date);
            this->panel29->Controls->Add(this->match6_label);
            this->panel29->Location = System::Drawing::Point(0, 0);
            this->panel29->Name = L"panel29";
            this->panel29->Size = System::Drawing::Size(246, 27);
            this->panel29->TabIndex = 0;
            // 
            // panel30
            // 
            this->panel30->Location = System::Drawing::Point(2, 29);
            this->panel30->Name = L"panel30";
            this->panel30->Size = System::Drawing::Size(240, 29);
            this->panel30->TabIndex = 1;
            // 
            // match6_date
            // 
            this->match6_date->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->match6_date->AutoSize = true;
            this->match6_date->ForeColor = System::Drawing::SystemColors::Control;
            this->match6_date->Location = System::Drawing::Point(116, -1);
            this->match6_date->Name = L"match6_date";
            this->match6_date->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->match6_date->Size = System::Drawing::Size(129, 27);
            this->match6_date->TabIndex = 1;
            this->match6_date->Text = L"01 NOV | 8:00";
            this->match6_date->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // match6_label
            // 
            this->match6_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->match6_label->AutoSize = true;
            this->match6_label->ForeColor = System::Drawing::SystemColors::Control;
            this->match6_label->Location = System::Drawing::Point(4, 0);
            this->match6_label->Name = L"match6_label";
            this->match6_label->Size = System::Drawing::Size(84, 27);
            this->match6_label->TabIndex = 0;
            this->match6_label->Text = L"Match 6";
            this->match6_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // match7_panel
            // 
            this->match7_panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->match7_panel->Controls->Add(this->panel32);
            this->match7_panel->Controls->Add(this->panel33);
            this->match7_panel->Controls->Add(this->panel34);
            this->match7_panel->Location = System::Drawing::Point(3, 717);
            this->match7_panel->Name = L"match7_panel";
            this->match7_panel->Size = System::Drawing::Size(246, 113);
            this->match7_panel->TabIndex = 6;
            // 
            // panel32
            // 
            this->panel32->Controls->Add(this->match7_team2_rank);
            this->panel32->Controls->Add(this->match7_team2);
            this->panel32->Controls->Add(this->match7_teamlogo2);
            this->panel32->Location = System::Drawing::Point(0, 65);
            this->panel32->Name = L"panel32";
            this->panel32->Size = System::Drawing::Size(246, 35);
            this->panel32->TabIndex = 2;
            // 
            // match7_team2_rank
            // 
            this->match7_team2_rank->AutoSize = true;
            this->match7_team2_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match7_team2_rank->Location = System::Drawing::Point(211, 7);
            this->match7_team2_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match7_team2_rank->Name = L"match7_team2_rank";
            this->match7_team2_rank->Size = System::Drawing::Size(23, 27);
            this->match7_team2_rank->TabIndex = 3;
            this->match7_team2_rank->Text = L"2";
            // 
            // match7_team2
            // 
            this->match7_team2->AutoSize = true;
            this->match7_team2->ForeColor = System::Drawing::SystemColors::Control;
            this->match7_team2->Location = System::Drawing::Point(74, 8);
            this->match7_team2->Name = L"match7_team2";
            this->match7_team2->Size = System::Drawing::Size(68, 27);
            this->match7_team2->TabIndex = 2;
            this->match7_team2->Text = L"Team2";
            // 
            // match7_teamlogo2
            // 
            this->match7_teamlogo2->Location = System::Drawing::Point(7, 0);
            this->match7_teamlogo2->Name = L"match7_teamlogo2";
            this->match7_teamlogo2->Size = System::Drawing::Size(64, 35);
            this->match7_teamlogo2->TabIndex = 1;
            this->match7_teamlogo2->TabStop = false;
            // 
            // panel33
            // 
            this->panel33->Controls->Add(this->match7_team1_rank);
            this->panel33->Controls->Add(this->match7_team1);
            this->panel33->Controls->Add(this->match7_teamlogo1);
            this->panel33->Location = System::Drawing::Point(0, 30);
            this->panel33->Name = L"panel33";
            this->panel33->Size = System::Drawing::Size(246, 35);
            this->panel33->TabIndex = 1;
            // 
            // match7_team1_rank
            // 
            this->match7_team1_rank->AutoSize = true;
            this->match7_team1_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match7_team1_rank->Location = System::Drawing::Point(211, 3);
            this->match7_team1_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match7_team1_rank->Name = L"match7_team1_rank";
            this->match7_team1_rank->Size = System::Drawing::Size(19, 27);
            this->match7_team1_rank->TabIndex = 2;
            this->match7_team1_rank->Text = L"1";
            // 
            // match7_team1
            // 
            this->match7_team1->AutoSize = true;
            this->match7_team1->ForeColor = System::Drawing::SystemColors::Control;
            this->match7_team1->Location = System::Drawing::Point(74, 3);
            this->match7_team1->Name = L"match7_team1";
            this->match7_team1->Size = System::Drawing::Size(64, 27);
            this->match7_team1->TabIndex = 1;
            this->match7_team1->Text = L"Team1";
            // 
            // match7_teamlogo1
            // 
            this->match7_teamlogo1->Location = System::Drawing::Point(7, 0);
            this->match7_teamlogo1->Name = L"match7_teamlogo1";
            this->match7_teamlogo1->Size = System::Drawing::Size(64, 35);
            this->match7_teamlogo1->TabIndex = 0;
            this->match7_teamlogo1->TabStop = false;
            // 
            // panel34
            // 
            this->panel34->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->panel34->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panel34->Controls->Add(this->panel35);
            this->panel34->Controls->Add(this->match7_date);
            this->panel34->Controls->Add(this->match7_label);
            this->panel34->Location = System::Drawing::Point(0, 0);
            this->panel34->Name = L"panel34";
            this->panel34->Size = System::Drawing::Size(246, 27);
            this->panel34->TabIndex = 0;
            // 
            // panel35
            // 
            this->panel35->Location = System::Drawing::Point(2, 29);
            this->panel35->Name = L"panel35";
            this->panel35->Size = System::Drawing::Size(240, 29);
            this->panel35->TabIndex = 1;
            // 
            // match7_date
            // 
            this->match7_date->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->match7_date->AutoSize = true;
            this->match7_date->ForeColor = System::Drawing::SystemColors::Control;
            this->match7_date->Location = System::Drawing::Point(116, -1);
            this->match7_date->Name = L"match7_date";
            this->match7_date->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->match7_date->Size = System::Drawing::Size(129, 27);
            this->match7_date->TabIndex = 1;
            this->match7_date->Text = L"01 NOV | 8:00";
            this->match7_date->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // match7_label
            // 
            this->match7_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->match7_label->AutoSize = true;
            this->match7_label->ForeColor = System::Drawing::SystemColors::Control;
            this->match7_label->Location = System::Drawing::Point(4, 0);
            this->match7_label->Name = L"match7_label";
            this->match7_label->Size = System::Drawing::Size(84, 27);
            this->match7_label->TabIndex = 0;
            this->match7_label->Text = L"Match 7";
            this->match7_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // match8_panel
            // 
            this->match8_panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->match8_panel->Controls->Add(this->panel37);
            this->match8_panel->Controls->Add(this->panel38);
            this->match8_panel->Controls->Add(this->panel39);
            this->match8_panel->Location = System::Drawing::Point(3, 836);
            this->match8_panel->Name = L"match8_panel";
            this->match8_panel->Size = System::Drawing::Size(246, 113);
            this->match8_panel->TabIndex = 7;
            // 
            // panel37
            // 
            this->panel37->Controls->Add(this->match8_team2_rank);
            this->panel37->Controls->Add(this->match8_team2);
            this->panel37->Controls->Add(this->match8_teamlogo2);
            this->panel37->Location = System::Drawing::Point(0, 65);
            this->panel37->Name = L"panel37";
            this->panel37->Size = System::Drawing::Size(246, 35);
            this->panel37->TabIndex = 2;
            // 
            // match8_team2_rank
            // 
            this->match8_team2_rank->AutoSize = true;
            this->match8_team2_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match8_team2_rank->Location = System::Drawing::Point(211, 7);
            this->match8_team2_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match8_team2_rank->Name = L"match8_team2_rank";
            this->match8_team2_rank->Size = System::Drawing::Size(23, 27);
            this->match8_team2_rank->TabIndex = 3;
            this->match8_team2_rank->Text = L"2";
            // 
            // match8_team2
            // 
            this->match8_team2->AutoSize = true;
            this->match8_team2->ForeColor = System::Drawing::SystemColors::Control;
            this->match8_team2->Location = System::Drawing::Point(74, 8);
            this->match8_team2->Name = L"match8_team2";
            this->match8_team2->Size = System::Drawing::Size(68, 27);
            this->match8_team2->TabIndex = 2;
            this->match8_team2->Text = L"Team2";
            // 
            // match8_teamlogo2
            // 
            this->match8_teamlogo2->Location = System::Drawing::Point(7, 0);
            this->match8_teamlogo2->Name = L"match8_teamlogo2";
            this->match8_teamlogo2->Size = System::Drawing::Size(64, 35);
            this->match8_teamlogo2->TabIndex = 1;
            this->match8_teamlogo2->TabStop = false;
            // 
            // panel38
            // 
            this->panel38->Controls->Add(this->match8_team1_rank);
            this->panel38->Controls->Add(this->match8_team1);
            this->panel38->Controls->Add(this->match8_teamlogo1);
            this->panel38->Location = System::Drawing::Point(0, 30);
            this->panel38->Name = L"panel38";
            this->panel38->Size = System::Drawing::Size(246, 35);
            this->panel38->TabIndex = 1;
            // 
            // match8_team1_rank
            // 
            this->match8_team1_rank->AutoSize = true;
            this->match8_team1_rank->ForeColor = System::Drawing::SystemColors::Control;
            this->match8_team1_rank->Location = System::Drawing::Point(211, 3);
            this->match8_team1_rank->Margin = System::Windows::Forms::Padding(0, 10, 10, 0);
            this->match8_team1_rank->Name = L"match8_team1_rank";
            this->match8_team1_rank->Size = System::Drawing::Size(19, 27);
            this->match8_team1_rank->TabIndex = 2;
            this->match8_team1_rank->Text = L"1";
            // 
            // match8_team1
            // 
            this->match8_team1->AutoSize = true;
            this->match8_team1->ForeColor = System::Drawing::SystemColors::Control;
            this->match8_team1->Location = System::Drawing::Point(74, 3);
            this->match8_team1->Name = L"match8_team1";
            this->match8_team1->Size = System::Drawing::Size(64, 27);
            this->match8_team1->TabIndex = 1;
            this->match8_team1->Text = L"Team1";
            // 
            // match8_teamlogo1
            // 
            this->match8_teamlogo1->Location = System::Drawing::Point(7, 0);
            this->match8_teamlogo1->Name = L"match8_teamlogo1";
            this->match8_teamlogo1->Size = System::Drawing::Size(64, 35);
            this->match8_teamlogo1->TabIndex = 0;
            this->match8_teamlogo1->TabStop = false;
            // 
            // panel39
            // 
            this->panel39->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->panel39->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panel39->Controls->Add(this->panel40);
            this->panel39->Controls->Add(this->match8_date);
            this->panel39->Controls->Add(this->match8_label);
            this->panel39->Location = System::Drawing::Point(0, 0);
            this->panel39->Name = L"panel39";
            this->panel39->Size = System::Drawing::Size(246, 27);
            this->panel39->TabIndex = 0;
            // 
            // panel40
            // 
            this->panel40->Location = System::Drawing::Point(2, 29);
            this->panel40->Name = L"panel40";
            this->panel40->Size = System::Drawing::Size(240, 29);
            this->panel40->TabIndex = 1;
            // 
            // match8_date
            // 
            this->match8_date->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->match8_date->AutoSize = true;
            this->match8_date->ForeColor = System::Drawing::SystemColors::Control;
            this->match8_date->Location = System::Drawing::Point(116, -1);
            this->match8_date->Name = L"match8_date";
            this->match8_date->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->match8_date->Size = System::Drawing::Size(129, 27);
            this->match8_date->TabIndex = 1;
            this->match8_date->Text = L"01 NOV | 8:00";
            this->match8_date->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // match8_label
            // 
            this->match8_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->match8_label->AutoSize = true;
            this->match8_label->ForeColor = System::Drawing::SystemColors::Control;
            this->match8_label->Location = System::Drawing::Point(4, 0);
            this->match8_label->Name = L"match8_label";
            this->match8_label->Size = System::Drawing::Size(84, 27);
            this->match8_label->TabIndex = 0;
            this->match8_label->Text = L"Match 8";
            this->match8_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // SimulateForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(11, 27);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(30)));
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->ClientSize = System::Drawing::Size(1010, 1018);
            this->ControlBox = false;
            this->Controls->Add(this->tableLayoutPanel1);
            this->Controls->Add(this->flowLayoutPanel1);
            this->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->MaximizeBox = false;
            this->MaximumSize = System::Drawing::Size(1010, 1018);
            this->MinimizeBox = false;
            this->MinimumSize = System::Drawing::Size(1010, 1018);
            this->Name = L"SimulateForm";
            this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
            this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
            this->Text = L"Competition Scheduler - Simulate Matches";
            this->Load += gcnew System::EventHandler(this, &SimulateForm::SimulateForm_Load);
            this->flowLayoutPanel1->ResumeLayout(false);
            this->flowLayoutPanel1->PerformLayout();
            this->tableLayoutPanel1->ResumeLayout(false);
            this->flowLayoutPanel5->ResumeLayout(false);
            this->winner_panel->ResumeLayout(false);
            this->panel11->ResumeLayout(false);
            this->panel11->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->winner_teamlogo))->EndInit();
            this->panel16->ResumeLayout(false);
            this->panel16->PerformLayout();
            this->match15_panel->ResumeLayout(false);
            this->panel72->ResumeLayout(false);
            this->panel72->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match15_teamlogo2))->EndInit();
            this->panel73->ResumeLayout(false);
            this->panel73->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match15_teamlogo1))->EndInit();
            this->panel74->ResumeLayout(false);
            this->panel74->PerformLayout();
            this->flowLayoutPanel4->ResumeLayout(false);
            this->match13_panel->ResumeLayout(false);
            this->panel62->ResumeLayout(false);
            this->panel62->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match13_teamlogo2))->EndInit();
            this->panel63->ResumeLayout(false);
            this->panel63->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match13_teamlogo1))->EndInit();
            this->panel64->ResumeLayout(false);
            this->panel64->PerformLayout();
            this->match14_panel->ResumeLayout(false);
            this->panel67->ResumeLayout(false);
            this->panel67->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match14_teamlogo2))->EndInit();
            this->panel68->ResumeLayout(false);
            this->panel68->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match14_teamlogo1))->EndInit();
            this->panel69->ResumeLayout(false);
            this->panel69->PerformLayout();
            this->flowLayoutPanel3->ResumeLayout(false);
            this->match9_panel->ResumeLayout(false);
            this->panel42->ResumeLayout(false);
            this->panel42->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match9_teamlogo2))->EndInit();
            this->panel43->ResumeLayout(false);
            this->panel43->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match9_teamlogo1))->EndInit();
            this->panel44->ResumeLayout(false);
            this->panel44->PerformLayout();
            this->match10_panel->ResumeLayout(false);
            this->panel47->ResumeLayout(false);
            this->panel47->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match10_teamlogo2))->EndInit();
            this->panel48->ResumeLayout(false);
            this->panel48->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match10_teamlogo1))->EndInit();
            this->panel49->ResumeLayout(false);
            this->panel49->PerformLayout();
            this->match11_panel->ResumeLayout(false);
            this->panel52->ResumeLayout(false);
            this->panel52->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match11_teamlogo2))->EndInit();
            this->panel53->ResumeLayout(false);
            this->panel53->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match11_teamlogo1))->EndInit();
            this->panel54->ResumeLayout(false);
            this->panel54->PerformLayout();
            this->match12_panel->ResumeLayout(false);
            this->panel57->ResumeLayout(false);
            this->panel57->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match12_teamlogo2))->EndInit();
            this->panel58->ResumeLayout(false);
            this->panel58->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match12_teamlogo1))->EndInit();
            this->panel59->ResumeLayout(false);
            this->panel59->PerformLayout();
            this->flowLayoutPanel2->ResumeLayout(false);
            this->match1_panel->ResumeLayout(false);
            this->panel5->ResumeLayout(false);
            this->panel5->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match1_teamlogo2))->EndInit();
            this->panel4->ResumeLayout(false);
            this->panel4->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match1_teamlogo1))->EndInit();
            this->panel2->ResumeLayout(false);
            this->panel2->PerformLayout();
            this->match2_panel->ResumeLayout(false);
            this->panel7->ResumeLayout(false);
            this->panel7->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match2_teamlogo2))->EndInit();
            this->panel8->ResumeLayout(false);
            this->panel8->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match2_teamlogo1))->EndInit();
            this->panel9->ResumeLayout(false);
            this->panel9->PerformLayout();
            this->match3_panel->ResumeLayout(false);
            this->panel12->ResumeLayout(false);
            this->panel12->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match3_teamlogo2))->EndInit();
            this->panel13->ResumeLayout(false);
            this->panel13->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match3_teamlogo1))->EndInit();
            this->panel14->ResumeLayout(false);
            this->panel14->PerformLayout();
            this->match4_panel->ResumeLayout(false);
            this->panel17->ResumeLayout(false);
            this->panel17->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match4_teamlogo2))->EndInit();
            this->panel18->ResumeLayout(false);
            this->panel18->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match4_teamlogo1))->EndInit();
            this->panel19->ResumeLayout(false);
            this->panel19->PerformLayout();
            this->match5_panel->ResumeLayout(false);
            this->panel22->ResumeLayout(false);
            this->panel22->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match5_teamlogo2))->EndInit();
            this->panel23->ResumeLayout(false);
            this->panel23->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match5_teamlogo1))->EndInit();
            this->panel24->ResumeLayout(false);
            this->panel24->PerformLayout();
            this->match6_panel->ResumeLayout(false);
            this->panel27->ResumeLayout(false);
            this->panel27->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match6_teamlogo2))->EndInit();
            this->panel28->ResumeLayout(false);
            this->panel28->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match6_teamlogo1))->EndInit();
            this->panel29->ResumeLayout(false);
            this->panel29->PerformLayout();
            this->match7_panel->ResumeLayout(false);
            this->panel32->ResumeLayout(false);
            this->panel32->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match7_teamlogo2))->EndInit();
            this->panel33->ResumeLayout(false);
            this->panel33->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match7_teamlogo1))->EndInit();
            this->panel34->ResumeLayout(false);
            this->panel34->PerformLayout();
            this->match8_panel->ResumeLayout(false);
            this->panel37->ResumeLayout(false);
            this->panel37->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match8_teamlogo2))->EndInit();
            this->panel38->ResumeLayout(false);
            this->panel38->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->match8_teamlogo1))->EndInit();
            this->panel39->ResumeLayout(false);
            this->panel39->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion
	// Method to resize the image to the specified width and height
    System::Drawing::Image^ ResizeImage(System::Drawing::Image^ originalImage, int width, int height) {
        // Create a new Bitmap with the desired size
        System::Drawing::Bitmap^ resizedImage = gcnew System::Drawing::Bitmap(width, height);

        // Create a Graphics object to perform the resizing operation
        System::Drawing::Graphics^ graphics = System::Drawing::Graphics::FromImage(resizedImage);

        // Set interpolation mode for better image quality when resizing
        graphics->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::HighQualityBicubic;

        // Draw the original image onto the resized bitmap with the new dimensions
        graphics->DrawImage(originalImage, 0, 0, width, height);

        // Return the resized image
        return resizedImage;
    }

    // Method to update all the labels using the data from the scheduler matches
    void updateLabels() {
        // Resize image to 32x32
        System::Drawing::Image^ resizedImage;

        // Match 1
        match1_team1->Text = gcnew String(scheduler->getMatch(0)->getTeam1()->getTeamName().c_str());
        match1_team2->Text = gcnew String(scheduler->getMatch(0)->getTeam2()->getTeamName().c_str());
        match1_date->Text = gcnew String(scheduler->getMatch(0)->getDate().c_str());
        // Resize team 1 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(0)->getTeam1()->getTeamId()), 32, 32);
        match1_teamlogo1->Image = resizedImage;
        // Resize team 2 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(0)->getTeam2()->getTeamId()), 32, 32);
        match1_teamlogo2->Image = resizedImage;

        match1_team1_rank->Text = gcnew String(std::to_string(scheduler->getMatch(0)->getTeam1()->getRank()).c_str());
        match1_team2_rank->Text = gcnew String(std::to_string(scheduler->getMatch(0)->getTeam2()->getRank()).c_str());

        // Match 2
        match2_team1->Text = gcnew String(scheduler->getMatch(1)->getTeam1()->getTeamName().c_str());
        match2_team2->Text = gcnew String(scheduler->getMatch(1)->getTeam2()->getTeamName().c_str());
        match2_date->Text = gcnew String(scheduler->getMatch(1)->getDate().c_str());
        match2_team1_rank->Text = gcnew String(std::to_string(scheduler->getMatch(1)->getTeam1()->getRank()).c_str());
        match2_team2_rank->Text = gcnew String(std::to_string(scheduler->getMatch(1)->getTeam2()->getRank()).c_str());
        // Resize team 1 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(1)->getTeam1()->getTeamId()), 32, 32);
        match2_teamlogo1->Image = resizedImage;
        // Resize team 2 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(1)->getTeam2()->getTeamId()), 32, 32);
        match2_teamlogo2->Image = resizedImage;

        // Match 3
        match3_team1->Text = gcnew String(scheduler->getMatch(2)->getTeam1()->getTeamName().c_str());
        match3_team2->Text = gcnew String(scheduler->getMatch(2)->getTeam2()->getTeamName().c_str());
        match3_date->Text = gcnew String(scheduler->getMatch(2)->getDate().c_str());
        match3_team1_rank->Text = gcnew String(std::to_string(scheduler->getMatch(2)->getTeam1()->getRank()).c_str());
        match3_team2_rank->Text = gcnew String(std::to_string(scheduler->getMatch(2)->getTeam2()->getRank()).c_str());
        // Resize team 1 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(2)->getTeam1()->getTeamId()), 32, 32);
        match3_teamlogo1->Image = resizedImage;
        // Resize team 2 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(2)->getTeam2()->getTeamId()), 32, 32);
        match3_teamlogo2->Image = resizedImage;

        // Match 4
        match4_team1->Text = gcnew String(scheduler->getMatch(3)->getTeam1()->getTeamName().c_str());
        match4_team2->Text = gcnew String(scheduler->getMatch(3)->getTeam2()->getTeamName().c_str());
        match4_date->Text = gcnew String(scheduler->getMatch(3)->getDate().c_str());
        match4_team1_rank->Text = gcnew String(std::to_string(scheduler->getMatch(3)->getTeam1()->getRank()).c_str());
        match4_team2_rank->Text = gcnew String(std::to_string(scheduler->getMatch(3)->getTeam2()->getRank()).c_str());
        // Resize team 1 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(3)->getTeam1()->getTeamId()), 32, 32);
        match4_teamlogo1->Image = resizedImage;
        // Resize team 2 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(3)->getTeam2()->getTeamId()), 32, 32);
        match4_teamlogo2->Image = resizedImage;

        // Match 5
        match5_team1->Text = gcnew String(scheduler->getMatch(4)->getTeam1()->getTeamName().c_str());
        match5_team2->Text = gcnew String(scheduler->getMatch(4)->getTeam2()->getTeamName().c_str());
        match5_date->Text = gcnew String(scheduler->getMatch(4)->getDate().c_str());
        match5_team1_rank->Text = gcnew String(std::to_string(scheduler->getMatch(4)->getTeam1()->getRank()).c_str());
        match5_team2_rank->Text = gcnew String(std::to_string(scheduler->getMatch(4)->getTeam2()->getRank()).c_str());
        // Resize team 1 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(4)->getTeam1()->getTeamId()), 32, 32);
        match5_teamlogo1->Image = resizedImage;
        // Resize team 2 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(4)->getTeam2()->getTeamId()), 32, 32);
        match5_teamlogo2->Image = resizedImage;

        // Match 6
        match6_team1->Text = gcnew String(scheduler->getMatch(5)->getTeam1()->getTeamName().c_str());
        match6_team2->Text = gcnew String(scheduler->getMatch(5)->getTeam2()->getTeamName().c_str());
        match6_date->Text = gcnew String(scheduler->getMatch(5)->getDate().c_str());
        match6_team1_rank->Text = gcnew String(std::to_string(scheduler->getMatch(5)->getTeam1()->getRank()).c_str());
        match6_team2_rank->Text = gcnew String(std::to_string(scheduler->getMatch(5)->getTeam2()->getRank()).c_str());
        // Resize team 1 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(5)->getTeam1()->getTeamId()), 32, 32);
        match6_teamlogo1->Image = resizedImage;
        // Resize team 2 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(5)->getTeam2()->getTeamId()), 32, 32);
        match6_teamlogo2->Image = resizedImage;

        // Match 7
        match7_team1->Text = gcnew String(scheduler->getMatch(6)->getTeam1()->getTeamName().c_str());
        match7_team2->Text = gcnew String(scheduler->getMatch(6)->getTeam2()->getTeamName().c_str());
        match7_date->Text = gcnew String(scheduler->getMatch(6)->getDate().c_str());
        match7_team1_rank->Text = gcnew String(std::to_string(scheduler->getMatch(6)->getTeam1()->getRank()).c_str());
        match7_team2_rank->Text = gcnew String(std::to_string(scheduler->getMatch(6)->getTeam2()->getRank()).c_str());
        // Resize team 1 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(6)->getTeam1()->getTeamId()), 32, 32);
        match7_teamlogo1->Image = resizedImage;
        // Resize team 2 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(6)->getTeam2()->getTeamId()), 32, 32);
        match7_teamlogo2->Image = resizedImage;

        // Match 8
        match8_team1->Text = gcnew String(scheduler->getMatch(7)->getTeam1()->getTeamName().c_str());
        match8_team2->Text = gcnew String(scheduler->getMatch(7)->getTeam2()->getTeamName().c_str());
        match8_date->Text = gcnew String(scheduler->getMatch(7)->getDate().c_str());
        match8_team1_rank->Text = gcnew String(std::to_string(scheduler->getMatch(7)->getTeam1()->getRank()).c_str());
        match8_team2_rank->Text = gcnew String(std::to_string(scheduler->getMatch(7)->getTeam2()->getRank()).c_str());
        // Resize team 1 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(7)->getTeam1()->getTeamId()), 32, 32);
        match8_teamlogo1->Image = resizedImage;
        // Resize team 2 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(7)->getTeam2()->getTeamId()), 32, 32);
        match8_teamlogo2->Image = resizedImage;

        // Match 9
        match9_team1->Text = gcnew String(scheduler->getMatch(8)->getTeam1()->getTeamName().c_str());
        match9_team2->Text = gcnew String(scheduler->getMatch(8)->getTeam2()->getTeamName().c_str());
        match9_date->Text = gcnew String(scheduler->getMatch(8)->getDate().c_str());
        match9_team1_rank->Text = gcnew String(std::to_string(scheduler->getMatch(8)->getTeam1()->getRank()).c_str());
        match9_team2_rank->Text = gcnew String(std::to_string(scheduler->getMatch(8)->getTeam2()->getRank()).c_str());
        // Resize team 1 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(8)->getTeam1()->getTeamId()), 32, 32);
        match9_teamlogo1->Image = resizedImage;
        // Resize team 2 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(8)->getTeam2()->getTeamId()), 32, 32);
        match9_teamlogo2->Image = resizedImage;

        // Match 10
        match10_team1->Text = gcnew String(scheduler->getMatch(9)->getTeam1()->getTeamName().c_str());
        match10_team2->Text = gcnew String(scheduler->getMatch(9)->getTeam2()->getTeamName().c_str());
        match10_date->Text = gcnew String(scheduler->getMatch(9)->getDate().c_str());
        match10_team1_rank->Text = gcnew String(std::to_string(scheduler->getMatch(9)->getTeam1()->getRank()).c_str());
        match10_team2_rank->Text = gcnew String(std::to_string(scheduler->getMatch(9)->getTeam2()->getRank()).c_str());
        // Resize team 1 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(9)->getTeam1()->getTeamId()), 32, 32);
        match10_teamlogo1->Image = resizedImage;
        // Resize team 2 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(9)->getTeam2()->getTeamId()), 32, 32);
        match10_teamlogo2->Image = resizedImage;

        // Match 11
        match11_team1->Text = gcnew String(scheduler->getMatch(10)->getTeam1()->getTeamName().c_str());
        match11_team2->Text = gcnew String(scheduler->getMatch(10)->getTeam2()->getTeamName().c_str());
        match11_date->Text = gcnew String(scheduler->getMatch(10)->getDate().c_str());
        match11_team1_rank->Text = gcnew String(std::to_string(scheduler->getMatch(10)->getTeam1()->getRank()).c_str());
        match11_team2_rank->Text = gcnew String(std::to_string(scheduler->getMatch(10)->getTeam2()->getRank()).c_str());
        // Resize team 1 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(10)->getTeam1()->getTeamId()), 32, 32);
        match11_teamlogo1->Image = resizedImage;
        // Resize team 2 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(10)->getTeam2()->getTeamId()), 32, 32);
        match11_teamlogo2->Image = resizedImage;

        // Match 12
        match12_team1->Text = gcnew String(scheduler->getMatch(11)->getTeam1()->getTeamName().c_str());
        match12_team2->Text = gcnew String(scheduler->getMatch(11)->getTeam2()->getTeamName().c_str());
        match12_date->Text = gcnew String(scheduler->getMatch(11)->getDate().c_str());
        match12_team1_rank->Text = gcnew String(std::to_string(scheduler->getMatch(11)->getTeam1()->getRank()).c_str());
        match12_team2_rank->Text = gcnew String(std::to_string(scheduler->getMatch(11)->getTeam2()->getRank()).c_str());
        // Resize team 1 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(11)->getTeam1()->getTeamId()), 32, 32);
        match12_teamlogo1->Image = resizedImage;
        // Resize team 2 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(11)->getTeam2()->getTeamId()), 32, 32);
        match12_teamlogo2->Image = resizedImage;

        // Match 13
        match13_team1->Text = gcnew String(scheduler->getMatch(12)->getTeam1()->getTeamName().c_str());
        match13_team2->Text = gcnew String(scheduler->getMatch(12)->getTeam2()->getTeamName().c_str());
        match13_date->Text = gcnew String(scheduler->getMatch(12)->getDate().c_str());
        match13_team1_rank->Text = gcnew String(std::to_string(scheduler->getMatch(12)->getTeam1()->getRank()).c_str());
        match13_team2_rank->Text = gcnew String(std::to_string(scheduler->getMatch(12)->getTeam2()->getRank()).c_str());
        // Resize team 1 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(12)->getTeam1()->getTeamId()), 32, 32);
        match13_teamlogo1->Image = resizedImage;
        // Resize team 2 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(12)->getTeam2()->getTeamId()), 32, 32);
        match13_teamlogo2->Image = resizedImage;

        // Match 14
        match14_team1->Text = gcnew String(scheduler->getMatch(13)->getTeam1()->getTeamName().c_str());
        match14_team2->Text = gcnew String(scheduler->getMatch(13)->getTeam2()->getTeamName().c_str());
        match14_date->Text = gcnew String(scheduler->getMatch(13)->getDate().c_str());
        match14_team1_rank->Text = gcnew String(std::to_string(scheduler->getMatch(13)->getTeam1()->getRank()).c_str());
        match14_team2_rank->Text = gcnew String(std::to_string(scheduler->getMatch(13)->getTeam2()->getRank()).c_str());
        // Resize team 1 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(13)->getTeam1()->getTeamId()), 32, 32);
        match14_teamlogo1->Image = resizedImage;
        // Resize team 2 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(13)->getTeam2()->getTeamId()), 32, 32);
        match14_teamlogo2->Image = resizedImage;

        // Match 15
        match15_team1->Text = gcnew String(scheduler->getMatch(14)->getTeam1()->getTeamName().c_str());
        match15_team2->Text = gcnew String(scheduler->getMatch(14)->getTeam2()->getTeamName().c_str());
        match15_date->Text = gcnew String(scheduler->getMatch(14)->getDate().c_str());
        match15_team1_rank->Text = gcnew String(std::to_string(scheduler->getMatch(14)->getTeam1()->getRank()).c_str());
        match15_team2_rank->Text = gcnew String(std::to_string(scheduler->getMatch(14)->getTeam2()->getRank()).c_str());
        // Resize team 1 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(14)->getTeam1()->getTeamId()), 32, 32);
        match15_teamlogo1->Image = resizedImage;
        // Resize team 2 image to 32x32
        resizedImage = ResizeImage(TeamLogoManager::GetTeamLogo(scheduler->getMatch(14)->getTeam2()->getTeamId()), 32, 32);
        match15_teamlogo2->Image = resizedImage;

        // Winner
        winner_team->Text = gcnew String(scheduler->getMatch(14)->getWinner()->getTeamName().c_str());
        winner_teamlogo->Image = TeamLogoManager::GetTeamLogo(scheduler->getMatch(14)->getWinner()->getTeamId());
        // Resize the winner's team logo to 32x32
        winner_teamlogo->Image = ResizeImage(winner_teamlogo->Image, 32, 32);
		// Update the winner's rank
        winner_rank->Text = gcnew String(std::to_string(scheduler->getMatch(14)->getWinner()->getRank()).c_str());
    }

	// Method to update the winner panel
	private: System::Void SimulateForm_Load(System::Object^ sender, System::EventArgs^ e) {
		// Check if the scheduler is not null or matches are not empty
        if (scheduler == nullptr) {
			MessageBox::Show("Scheduler is not initialized. Please go back and generate the schedule first.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }
		else if (scheduler->getMatches().size() < 15) {
			MessageBox::Show("Matches are not generated. Please go back and generate the schedule first.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		// Update all the labels
		updateLabels();

        // Enable the winner panel
        winner_panel->Visible = true;
    }
    };
}
