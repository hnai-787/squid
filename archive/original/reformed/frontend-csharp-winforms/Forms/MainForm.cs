using CompetitionScheduler.UI.Services;
using System.Data;
using System.Text.RegularExpressions;


namespace CompetitionScheduler.UI.Forms;

public sealed class MainForm : Form
{
    private readonly string _rootDir;
    private readonly string _sharedDataDir;
    private readonly string _outputDir;
    private readonly string _logoDir;
    private readonly string _teamsTxt;
    private readonly string _teamsCsv;
    private readonly string _matchesCsv;
    private readonly string _logsCsv;
    private readonly string _reportHtml;

    private readonly Panel _content = new() { Dock = DockStyle.Fill, BackColor = Theme.Bg };
    private readonly DataGridView _scheduleGrid = MakeGrid();
    private readonly DataGridView _logsGrid = MakeGrid();
    private readonly List<Button> _navButtons = new();

    private DataTable? _teamsTable;
    private DataTable? _matchesTable;
    private DataTable? _logsTable;

    public MainForm()
    {
        _rootDir = Path.GetFullPath(Path.Combine(AppContext.BaseDirectory, "..", "..", "..", "..", ".."));
        _sharedDataDir = Path.Combine(_rootDir, "shared-data");
        _outputDir = Path.Combine(_rootDir, "output");
        _logoDir = Path.Combine(_rootDir, "reformed", "frontend-csharp-winforms", "Resources", "Team Logos");
        _teamsTxt = Path.Combine(_sharedDataDir, "Teams.txt");
        _teamsCsv = Path.Combine(_outputDir, "teams-export.csv");
        _matchesCsv = Path.Combine(_outputDir, "matches.csv");
        _logsCsv = Path.Combine(_outputDir, "logs.csv");
        _reportHtml = Path.Combine(_outputDir, "Tournament-Report.html");

        Directory.CreateDirectory(_sharedDataDir);
        Directory.CreateDirectory(_outputDir);
        ClearSessionOutput();

        Text = "Competition Scheduler";
        Width = 1360;
        Height = 820;
        MinimumSize = new Size(1360, 820);
        MaximumSize = new Size(1360, 820);
        MaximizeBox = false;
        FormBorderStyle = FormBorderStyle.FixedSingle;
        StartPosition = FormStartPosition.CenterScreen;
        BackColor = Theme.Bg;
        Font = new Font("Segoe UI", 9);

        Controls.Add(_content);
        Controls.Add(CreateSidebar());
        ShowHome();
    }
    private void ClearSessionOutput()
    {
        string[] files =
        {
            _teamsCsv,
            _matchesCsv,
            _logsCsv,
            _reportHtml
        };

        foreach (string file in files)
        {
            try
            {
                if (File.Exists(file))
                {
                    File.Delete(file);
                }
            }
            catch
            {
                // Ignore locked/temporary file issues during startup.
            }
        }

        _teamsTable = null;
        _matchesTable = null;
        _logsTable = null;

        _scheduleGrid.DataSource = null;
        _logsGrid.DataSource = null;
    }

    private Panel CreateSidebar()
    {
        Panel side = new()
        {
            Dock = DockStyle.Left,
            Width = 240,
            BackColor = Theme.Sidebar,
            Padding = new Padding(18, 20, 18, 16)
        };

        Label brand = new()
        {
            Text = "Competition\nScheduler",
            ForeColor = Theme.Accent,
            Font = new Font("Segoe UI", 16, FontStyle.Bold),
            Dock = DockStyle.Top,
            Height = 86,
            TextAlign = ContentAlignment.MiddleLeft
        };

        Label sub = new()
        {
            Text = "Data Structures Project",
            ForeColor = Theme.Muted,
            Font = new Font("Segoe UI", 9),
            Dock = DockStyle.Top,
            Height = 28,
            TextAlign = ContentAlignment.MiddleLeft
        };

        Panel nav = new()
        {
            Dock = DockStyle.Top,
            Height = 292,
            Padding = new Padding(0, 24, 0, 0),
            BackColor = Theme.Sidebar
        };

        nav.Controls.Add(Nav("About", ShowAbout));
        nav.Controls.Add(Nav("Simulate Matches", ShowSimulate));
        nav.Controls.Add(Nav("View Schedule", ShowSchedule));
        nav.Controls.Add(Nav("Load Teams", ShowTeams));
        nav.Controls.Add(Nav("Home", ShowHome));

        Label footer = new()
        {
            Text = "C# WinForms + C++ DLL",
            ForeColor = Theme.Muted,
            Dock = DockStyle.Bottom,
            Height = 44,
            TextAlign = ContentAlignment.BottomLeft,
            Font = new Font("Segoe UI", 8)
        };

        side.Controls.Add(footer);
        side.Controls.Add(nav);
        side.Controls.Add(sub);
        side.Controls.Add(brand);
        return side;
    }

    private Button Nav(string text, Action action)
    {
        Button button = new()
        {
            Text = text,
            Dock = DockStyle.Top,
            Height = 44,
            FlatStyle = FlatStyle.Flat,
            ForeColor = Color.White,
            BackColor = Theme.Sidebar,
            Font = new Font("Segoe UI", 9, FontStyle.Bold),
            TextAlign = ContentAlignment.MiddleLeft,
            Padding = new Padding(14, 0, 0, 0)
        };

        button.FlatAppearance.BorderSize = 0;
        button.FlatAppearance.MouseOverBackColor = Theme.SidebarHover;
        button.Click += (_, _) =>
        {
            SetActiveNav(button);
            action();
        };

        _navButtons.Add(button);
        return button;
    }

    private void SetActiveNav(Button active)
    {
        foreach (Button button in _navButtons)
        {
            button.BackColor = button == active ? Theme.SidebarActive : Theme.Sidebar;
            button.ForeColor = button == active ? Theme.Accent : Color.White;
        }
    }

    private void CreatePage(string title, string subtitle, bool includeToolbar, out FlowLayoutPanel toolbar, out Panel body)
    {
        _content.Controls.Clear();

        TableLayoutPanel page = new()
        {
            Dock = DockStyle.Fill,
            RowCount = includeToolbar ? 3 : 2,
            ColumnCount = 1,
            BackColor = Theme.Bg
        };

        page.RowStyles.Add(new RowStyle(SizeType.Absolute, 92));

        if (includeToolbar)
        {
            page.RowStyles.Add(new RowStyle(SizeType.Absolute, 64));
            page.RowStyles.Add(new RowStyle(SizeType.Percent, 100));
        }
        else
        {
            page.RowStyles.Add(new RowStyle(SizeType.Percent, 100));
        }

        Panel header = new()
        {
            Dock = DockStyle.Fill,
            BackColor = Theme.Bg,
            Padding = new Padding(32, 16, 32, 8)
        };

        Label heading = new()
        {
            Text = title,
            Dock = DockStyle.Top,
            Height = 40,
            ForeColor = Theme.Accent,
            Font = new Font("Segoe UI", 19, FontStyle.Bold),
            TextAlign = ContentAlignment.MiddleLeft
        };

        Label sub = new()
        {
            Text = subtitle,
            Dock = DockStyle.Top,
            Height = 24,
            ForeColor = Theme.Muted,
            Font = new Font("Segoe UI", 9),
            TextAlign = ContentAlignment.MiddleLeft,
            Padding = new Padding(5, 0, 0, 0)
        };

        header.Controls.Add(sub);
        header.Controls.Add(heading);

        toolbar = new FlowLayoutPanel
        {
            Dock = DockStyle.Fill,
            BackColor = Theme.Bg,
            Padding = new Padding(28, 8, 28, 8),
            WrapContents = true,
            FlowDirection = FlowDirection.LeftToRight
        };

        body = new Panel
        {
            Dock = DockStyle.Fill,
            BackColor = Theme.Bg,
            Padding = new Padding(28, 8, 28, 28)
        };

        page.Controls.Add(header, 0, 0);

        if (includeToolbar)
        {
            page.Controls.Add(toolbar, 0, 1);
            page.Controls.Add(body, 0, 2);
        }
        else
        {
            page.Controls.Add(body, 0, 1);
        }

        _content.Controls.Add(page);
    }

    private void ShowHome()
    {
        ReloadTables();
        CreatePage("Dashboard", "Overview of the 16-team competition scheduler", false, out _, out Panel body);

        TableLayoutPanel layout = new()
        {
            Dock = DockStyle.Fill,
            RowCount = 3,
            ColumnCount = 1,
            BackColor = Theme.Bg
        };

        layout.RowStyles.Add(new RowStyle(SizeType.Percent, 35));
        layout.RowStyles.Add(new RowStyle(SizeType.Percent, 35));
        layout.RowStyles.Add(new RowStyle(SizeType.Percent, 30));

        Panel hero = CardPanel();
        hero.Padding = new Padding(34, 26, 34, 26);

        Label title = new()
        {
            Text = "Cyberthon Competition Scheduler",
            Dock = DockStyle.Top,
            Height = 56,
            ForeColor = Color.White,
            Font = new Font("Segoe UI", 24, FontStyle.Bold),
            TextAlign = ContentAlignment.MiddleLeft
        };

        Label subtitle = new()
        {
            Text = "16-team tournament scheduling system reformed with a C++ DLL backend and WinForms frontend",
            Dock = DockStyle.Top,
            Height = 32,
            ForeColor = Theme.Muted,
            Font = new Font("Segoe UI", 10),
            TextAlign = ContentAlignment.MiddleLeft,
            Padding = new Padding(5, 0, 0, 0)
        };

        Label workflow = new()
        {
            Text = "Load Teams -> Generate Schedule -> Simulate Matches -> Export Report",
            Dock = DockStyle.Bottom,
            Height = 36,
            ForeColor = Theme.Accent,
            Font = new Font("Segoe UI", 10, FontStyle.Bold),
            TextAlign = ContentAlignment.MiddleLeft,
            Padding = new Padding(5, 0, 0, 0)
        };

        hero.Controls.Add(workflow);
        hero.Controls.Add(subtitle);
        hero.Controls.Add(title);

        TableLayoutPanel stats = new()
        {
            Dock = DockStyle.Fill,
            ColumnCount = 4,
            RowCount = 1,
            BackColor = Theme.Bg,
            Padding = new Padding(0, 12, 0, 8)
        };

        for (int i = 0; i < 4; i++)
        {
            stats.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 25));
        }

        stats.Controls.Add(StatCard("Teams", CountRows(_teamsTable).ToString(), "Loaded teams"), 0, 0);
        stats.Controls.Add(StatCard("Matches", CountRows(_matchesTable).ToString(), "Scheduled matches"), 1, 0);
        stats.Controls.Add(StatCard("Completed", CompletedCount().ToString(), "Finished matches"), 2, 0);
        stats.Controls.Add(StatCard("State", StateText(), "Tournament state"), 3, 0);

        Panel note = CardPanel();
        note.Padding = new Padding(26);

        Label noteText = new()
        {
            Text = "Original identity preserved: GUI workflow, 16-team bracket, rank-based scheduling, match simulation, and C++ data structures logic.",
            Dock = DockStyle.Fill,
            ForeColor = Theme.Muted,
            Font = new Font("Segoe UI", 11),
            TextAlign = ContentAlignment.TopLeft
        };

        note.Controls.Add(noteText);

        layout.Controls.Add(hero, 0, 0);
        layout.Controls.Add(stats, 0, 1);
        layout.Controls.Add(note, 0, 2);
        body.Controls.Add(layout);
    }

    private void ShowTeams()
    {
        ReloadTables();
        CreatePage("Load Teams", "Load and review the fixed 16 participating teams.", true, out FlowLayoutPanel toolbar, out Panel body);

        toolbar.Controls.Add(ActionButton("Load Teams", () =>
        {
            NativeScheduler.LoadTeamsFile(_teamsTxt);
            NativeScheduler.ExportTeamsFile(_teamsCsv);
            ReloadTables();
            ShowTeams();
            MessageBox.Show("Teams loaded successfully.");
        }));

        toolbar.Controls.Add(ActionButton("Open Team File", () =>
        {
            System.Diagnostics.Process.Start(new System.Diagnostics.ProcessStartInfo("notepad.exe", _teamsTxt) { UseShellExecute = true });
        }));

        toolbar.Controls.Add(ActionButton("Browse Team File", () =>
        {
            using OpenFileDialog dialog = new() { Filter = "Team Files|*.txt;*.csv|All Files|*.*" };

            if (dialog.ShowDialog() == DialogResult.OK)
            {
                NativeScheduler.LoadTeamsFile(dialog.FileName);
                NativeScheduler.ExportTeamsFile(_teamsCsv);
                ReloadTables();
                ShowTeams();
            }
        }));

        if (_teamsTable == null || _teamsTable.Rows.Count == 0)
        {
            body.Controls.Add(EmptyState("No teams loaded yet", "Click \"Load Teams\" to import the default 16-team file."));
            return;
        }

        body.Controls.Add(BuildTeamCards4x4());
    }

    private TableLayoutPanel BuildTeamCards4x4()
    {
        TableLayoutPanel grid = new()
        {
            Dock = DockStyle.Fill,
            ColumnCount = 4,
            RowCount = 4,
            BackColor = Theme.Bg,
            Padding = new Padding(0)
        };

        for (int c = 0; c < 4; c++)
        {
            grid.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 25));
        }

        for (int r = 0; r < 4; r++)
        {
            grid.RowStyles.Add(new RowStyle(SizeType.Percent, 25));
        }

        if (_teamsTable == null) return grid;

        int index = 0;
        foreach (DataRow row in _teamsTable.Rows)
        {
            if (index >= 16) break;
            grid.Controls.Add(TeamCard(row), index % 4, index / 4);
            index++;
        }

        return grid;
    }

    private Panel TeamCard(DataRow row)
    {
        Panel outer = new()
        {
            Dock = DockStyle.Fill,
            BackColor = Theme.Bg,
            Padding = new Padding(7)
        };

        Panel card = new()
        {
            Dock = DockStyle.Fill,
            BackColor = Theme.Card,
            Padding = new Padding(14)
        };

        PictureBox logo = LogoBox(Convert.ToString(row["TeamLogo"]) ?? "");
        logo.Dock = DockStyle.Left;
        logo.Width = 62;

        Panel textArea = new()
        {
            Dock = DockStyle.Fill,
            BackColor = Theme.Card,
            Padding = new Padding(12, 0, 0, 0)
        };

        Label teamName = new()
        {
            Text = Convert.ToString(row["TeamName"]) ?? "",
            Dock = DockStyle.Top,
            Height = 27,
            ForeColor = Color.White,
            Font = new Font("Segoe UI", 11, FontStyle.Bold),
            TextAlign = ContentAlignment.MiddleLeft
        };

        Label rank = new()
        {
            Text = $"Rank {row["TeamRank"]}",
            Dock = DockStyle.Top,
            Height = 22,
            ForeColor = Theme.Accent,
            Font = new Font("Segoe UI", 9, FontStyle.Bold),
            TextAlign = ContentAlignment.MiddleLeft
        };

        Label members = new()
        {
            Text = Convert.ToString(row["TeamMembers"]) ?? "",
            Dock = DockStyle.Fill,
            ForeColor = Theme.Muted,
            Font = new Font("Segoe UI", 8),
            TextAlign = ContentAlignment.TopLeft
        };

        textArea.Controls.Add(members);
        textArea.Controls.Add(rank);
        textArea.Controls.Add(teamName);

        card.Controls.Add(textArea);
        card.Controls.Add(logo);
        outer.Controls.Add(card);

        return outer;
    }

    private void ShowSchedule()
    {
        ReloadTables();
        CreatePage("View Schedule", "Generate rounds, review match status, and track backend events.", true, out FlowLayoutPanel toolbar, out Panel body);

        toolbar.Controls.Add(ActionButton("Generate Schedule", () =>
        {
            NativeScheduler.GenerateScheduleFile(_matchesCsv, _logsCsv);
            ReloadTables();
            ShowSchedule();
        }));


        toolbar.Controls.Add(ActionButton("Set Team 1 as Winner", () => SetSelectedWinner(true)));
        toolbar.Controls.Add(ActionButton("Set Team 2 as Winner", () => SetSelectedWinner(false)));

        toolbar.Controls.Add(ActionButton("Reset Tournament", () =>
        {
            NativeScheduler.Reset(_matchesCsv, _logsCsv);
            ReloadTables();
            ShowSchedule();
        }));

        if (_matchesTable == null || _matchesTable.Rows.Count == 0)
        {
            body.Controls.Add(EmptyState("No schedule generated yet", "Load teams first, then click \"Generate Schedule\"."));
            return;
        }

        PrepareScheduleView();

        body.Controls.Add(SectionPanel(_scheduleGrid));
    }

    private void PrepareScheduleView()
    {
        if (_matchesTable == null) return;

        DataTable display = new();
        display.Columns.Add("Round");
        display.Columns.Add("Match");
        display.Columns.Add("Team 1");
        display.Columns.Add("Team 2");
        display.Columns.Add("Date");
        display.Columns.Add("Time");
        display.Columns.Add("Status");
        display.Columns.Add("Winner");

        foreach (DataRow row in _matchesTable.Rows)
        {
            string team1 = Convert.ToString(row["Team1"]) == "TBD"
                ? "TBD"
                : $"{row["Team1"]} (R{row["Team1Rank"]})";

            string team2 = Convert.ToString(row["Team2"]) == "TBD"
                ? "TBD"
                : $"{row["Team2"]} (R{row["Team2Rank"]})";

            display.Rows.Add(
                row["Round"],
                $"Match {row["MatchNo"]}",
                team1,
                team2,
                row["Date"],
                row["Time"],
                row["Status"],
                row["Winner"]
            );
        }

        _scheduleGrid.DataSource = display;
        _scheduleGrid.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
    }

    private void ShowSimulate()
    {
        ReloadTables();
        CreatePage("Simulate Matches", "Visual fixed 16-team bracket for automatic simulation and report export.", true, out FlowLayoutPanel toolbar, out Panel body);

        toolbar.Controls.Add(ActionButton("Simulate Current Round", () =>
        {
            NativeScheduler.SimulateRound(_matchesCsv, _logsCsv);
            ReloadTables();
            ShowSimulate();
        }));

        toolbar.Controls.Add(ActionButton("Simulate Full Tournament", () =>
        {
            NativeScheduler.SimulateTournament(_matchesCsv, _logsCsv);
            ReloadTables();
            ShowSimulate();
        }));

        toolbar.Controls.Add(ActionButton("Export Report", () =>
        {
            NativeScheduler.ExportReportFile(_reportHtml);
            MessageBox.Show("HTML report exported:\n" + _reportHtml);
        }));

        if (_matchesTable == null || _matchesTable.Rows.Count == 0)
        {
            body.Controls.Add(EmptyState("Generate Schedule first", "Open View Schedule, load teams if needed, then click \"Generate Schedule\"."));
            return;
        }

        body.Controls.Add(BuildBracket());
    }

    private TableLayoutPanel BuildBracket()
    {
        TableLayoutPanel bracket = new()
        {
            Dock = DockStyle.Fill,
            ColumnCount = 5,
            RowCount = 1,
            BackColor = Theme.Bg
        };

        for (int c = 0; c < 5; c++)
        {
            bracket.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 20));
        }

        string[] titles = { "Round 1", "Round 2", "Semi-Finals", "Finals", "Winner" };

        for (int i = 0; i < 5; i++)
        {
            TableLayoutPanel column = new()
            {
                Dock = DockStyle.Fill,
                RowCount = 10,
                ColumnCount = 1,
                BackColor = Theme.Bg,
                Padding = new Padding(4)
            };

            column.RowStyles.Add(new RowStyle(SizeType.Absolute, 38));
            for (int r = 1; r < 10; r++)
            {
                column.RowStyles.Add(new RowStyle(SizeType.Percent, 100f / 9f));
            }

            column.Controls.Add(new Label
            {
                Text = titles[i],
                Dock = DockStyle.Fill,
                ForeColor = Theme.Accent,
                Font = new Font("Segoe UI", 11, FontStyle.Bold),
                TextAlign = ContentAlignment.MiddleCenter
            }, 0, 0);

            if (i < 4)
            {
                List<DataRow> rows = MatchesForColumn(i);
                for (int r = 0; r < rows.Count; r++)
                {
                    column.Controls.Add(MatchCard(rows[r]), 0, r + 1);
                }
            }
            else
            {
                Panel holder = new()
                {
                    Dock = DockStyle.Fill,
                    BackColor = Theme.Bg,
                    Padding = new Padding(6, 82, 6, 6)
                };

                holder.Controls.Add(WinnerCard());
                column.Controls.Add(holder, 0, 1);
                column.SetRowSpan(holder, 9);
            }

            bracket.Controls.Add(column, i, 0);
        }

        return bracket;
    }

    private List<DataRow> MatchesForColumn(int index)
    {
        List<DataRow> rows = new();
        if (_matchesTable == null) return rows;

        foreach (DataRow row in _matchesTable.Rows)
        {
            string round = Convert.ToString(row["Round"]) ?? "";
            bool belongs = index switch
            {
                0 => round == "Preliminary Round",
                1 => round == "Round 2",
                2 => round == "Semi-Finals",
                3 => round == "Finals",
                _ => false
            };

            if (belongs) rows.Add(row);
        }

        return rows;
    }

    private Panel MatchCard(DataRow row)
    {
        string team1 = Convert.ToString(row["Team1"]) ?? "TBD";
        string team2 = Convert.ToString(row["Team2"]) ?? "TBD";
        string winner = Convert.ToString(row["Winner"]) ?? "TBD";
        string status = Convert.ToString(row["Status"]) ?? "Pending";

        bool completed = status == "Completed";
        bool pending = team1 == "TBD" || team2 == "TBD";

        Panel outer = new()
        {
            Dock = DockStyle.Fill,
            BackColor = Theme.Bg,
            Padding = new Padding(3)
        };

        Panel card = new()
        {
            Dock = DockStyle.Fill,
            BackColor = completed ? Theme.SuccessCard : Theme.Card,
            Padding = new Padding(6)
        };

        string text;

        if (completed)
        {
            text = $"Match {row["MatchNo"]}\nWinner: {winner}";
        }
        else if (pending)
        {
            text = $"Match {row["MatchNo"]}\nAwaiting winners";
        }
        else
        {
            text = $"Match {row["MatchNo"]}\n{team1} vs {team2}";
        }

        Label label = new()
        {
            Text = text,
            Dock = DockStyle.Fill,
            ForeColor = completed ? Color.Gold : Color.White,
            Font = new Font("Segoe UI", 7, FontStyle.Bold),
            TextAlign = ContentAlignment.MiddleLeft,
            AutoEllipsis = true
        };

        card.Controls.Add(label);
        outer.Controls.Add(card);
        return outer;
    }

    private Panel WinnerCard()
    {
        string winner = "TBD";

        if (_matchesTable != null)
        {
            foreach (DataRow row in _matchesTable.Rows)
            {
                if ((Convert.ToString(row["Round"]) ?? "") == "Finals" &&
                    Convert.ToString(row["Status"]) == "Completed")
                {
                    winner = Convert.ToString(row["Winner"]) ?? "TBD";
                }
            }
        }

        Panel card = new()
        {
            Dock = DockStyle.Top,
            Height = 125,
            BackColor = Theme.Gold,
            Padding = new Padding(14)
        };

        Label label = new()
        {
            Text = "Champion\n\n" + winner,
            Dock = DockStyle.Fill,
            ForeColor = Color.White,
            Font = new Font("Segoe UI", 12, FontStyle.Bold),
            TextAlign = ContentAlignment.MiddleCenter
        };

        card.Controls.Add(label);
        return card;
    }

    private void ShowAbout()
    {
        ReloadTables();
        CreatePage("About", "Tournament rules, data structures, and system activity.", false, out _, out Panel body);

        TableLayoutPanel layout = new()
        {
            Dock = DockStyle.Fill,
            ColumnCount = 1,
            RowCount = 3,
            BackColor = Theme.Bg
        };

        layout.RowStyles.Add(new RowStyle(SizeType.Percent, 32));
        layout.RowStyles.Add(new RowStyle(SizeType.Percent, 28));
        layout.RowStyles.Add(new RowStyle(SizeType.Percent, 40));

        layout.Controls.Add(InfoCard("Tournament Rules",
            "- Exactly 16 teams participate.\n" +
            "- Teams are ranked before scheduling.\n" +
            "- Round 1 creates 8 matches.\n" +
            "- Winners progress to Round 2, Semi-Finals, and Finals.\n" +
            "- A new round cannot be generated until all current matches are complete.\n" +
            "- Winners can be selected manually from the schedule or simulated automatically."), 0, 0);

        layout.Controls.Add(InfoCard("Data Structures Used",
            "- vector: stores teams and matches.\n" +
            "- queue: pairs teams during round generation.\n" +
            "- sorting: applies rank-based scheduling.\n" +
            "- classes/structs: represent Team and Match records.\n" +
            "- BST: documented as a future enhancement."), 0, 1);

        layout.Controls.Add(EventLogCard(), 0, 2);

        body.Controls.Add(layout);
    }

    private Panel InfoCard(string title, string text)
    {
        Panel outer = new()
        {
            Dock = DockStyle.Fill,
            BackColor = Theme.Bg,
            Padding = new Padding(0, 0, 0, 10)
        };

        Panel card = new()
        {
            Dock = DockStyle.Fill,
            BackColor = Theme.Card,
            Padding = new Padding(22)
        };

        Label titleLabel = new()
        {
            Text = title,
            Dock = DockStyle.Top,
            Height = 30,
            ForeColor = Theme.Accent,
            Font = new Font("Segoe UI", 12, FontStyle.Bold)
        };

        Label body = new()
        {
            Text = text,
            Dock = DockStyle.Fill,
            ForeColor = Color.White,
            Font = new Font("Segoe UI", 10),
            TextAlign = ContentAlignment.TopLeft
        };

        card.Controls.Add(body);
        card.Controls.Add(titleLabel);
        outer.Controls.Add(card);
        return outer;
    }


    private Panel EventLogCard()
    {
        Panel outer = new()
        {
            Dock = DockStyle.Fill,
            BackColor = Theme.Bg,
            Padding = new Padding(0, 0, 0, 10)
        };

        Panel card = new()
        {
            Dock = DockStyle.Fill,
            BackColor = Theme.Card,
            Padding = new Padding(18)
        };

        Label title = new()
        {
            Text = "System Event Log",
            Dock = DockStyle.Top,
            Height = 30,
            ForeColor = Theme.Accent,
            Font = new Font("Segoe UI", 12, FontStyle.Bold)
        };

        if (_logsTable == null || _logsTable.Rows.Count == 0)
        {
            Label empty = new()
            {
                Text = "No events recorded yet. Load teams and generate a schedule to create activity logs.",
                Dock = DockStyle.Fill,
                ForeColor = Theme.Muted,
                Font = new Font("Segoe UI", 10),
                TextAlign = ContentAlignment.MiddleLeft
            };

            card.Controls.Add(empty);
        }
        else
        {
            card.Controls.Add(_logsGrid);
        }

        card.Controls.Add(title);
        outer.Controls.Add(card);
        return outer;
    }

    private void SetSelectedWinner(bool team1)
    {
        if (_scheduleGrid.CurrentRow == null || _matchesTable == null)
        {
            MessageBox.Show("Select a match from the schedule page first.");
            return;
        }

        int selectedIndex = _scheduleGrid.CurrentRow.Index;

        if (selectedIndex < 0 || selectedIndex >= _matchesTable.Rows.Count)
        {
            MessageBox.Show("Invalid match selection.");
            return;
        }

        DataRow rawRow = _matchesTable.Rows[selectedIndex];

        int matchId = Convert.ToInt32(rawRow["MatchNo"]);
        int winnerId = Convert.ToInt32(rawRow[team1 ? "Team1No" : "Team2No"]);

        if (winnerId == 0)
        {
            MessageBox.Show("This match is not ready yet. Complete earlier matches first.");
            return;
        }

        NativeScheduler.SetWinner(matchId, winnerId, _matchesCsv, _logsCsv);
        ReloadTables();
        ShowSchedule();
    }

    private void ReloadTables()
    {
        if (File.Exists(_teamsCsv))
        {
            _teamsTable = LoadCsv(_teamsCsv);
        }

        if (File.Exists(_matchesCsv))
        {
            _matchesTable = LoadCsv(_matchesCsv);
            _scheduleGrid.DataSource = _matchesTable;
        }

        if (File.Exists(_logsCsv))
        {
            _logsTable = LoadCsv(_logsCsv);
            _logsGrid.DataSource = _logsTable;
        }
    }

    private PictureBox LogoBox(string logoText)
    {
        int id = 1;
        var m = Regex.Match(logoText, @"\d+");

        if (m.Success)
        {
            int.TryParse(m.Value, out id);
        }

        string path = Path.Combine(_logoDir, $"team{id}.png");

        PictureBox picture = new()
        {
            SizeMode = PictureBoxSizeMode.Zoom,
            BackColor = Color.Transparent,
            Padding = new Padding(4)
        };

        if (File.Exists(path))
        {
            try { picture.Image = Image.FromFile(path); }
            catch { }
        }

        return picture;
    }

    private static Button ActionButton(string text, Action action)
    {
        Button button = new()
        {
            Text = text,
            AutoSize = true,
            Width = Math.Max(130, text.Length * 9),
            Height = 38,
            Margin = new Padding(5),
            Padding = new Padding(12, 0, 12, 0),
            BackColor = Theme.Accent,
            ForeColor = Color.Black,
            FlatStyle = FlatStyle.Flat,
            Font = new Font("Segoe UI", 9, FontStyle.Bold)
        };

        button.FlatAppearance.BorderSize = 0;
        button.FlatAppearance.MouseOverBackColor = Theme.AccentSoft;
        button.Click += (_, _) =>
        {
            try { action(); }
            catch (Exception ex) { MessageBox.Show(ex.Message, "Operation Failed", MessageBoxButtons.OK, MessageBoxIcon.Warning); }
        };

        return button;
    }

    private static DataGridView MakeGrid()
    {
        DataGridView grid = new()
        {
            Dock = DockStyle.Fill,
            ReadOnly = true,
            AllowUserToAddRows = false,
            AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill,
            SelectionMode = DataGridViewSelectionMode.FullRowSelect,
            MultiSelect = false,
            BackgroundColor = Theme.Grid,
            BorderStyle = BorderStyle.None,
            EnableHeadersVisualStyles = false,
            RowHeadersVisible = false,
            AllowUserToResizeRows = false
        };

        grid.ColumnHeadersDefaultCellStyle.BackColor = Color.FromArgb(38, 38, 38);
        grid.ColumnHeadersDefaultCellStyle.ForeColor = Color.White;
        grid.ColumnHeadersDefaultCellStyle.Font = new Font("Segoe UI", 9, FontStyle.Bold);
        grid.ColumnHeadersHeight = 30;
        grid.RowTemplate.Height = 26;
        grid.DefaultCellStyle.BackColor = Theme.Grid;
        grid.DefaultCellStyle.ForeColor = Color.White;
        grid.DefaultCellStyle.SelectionBackColor = Theme.Accent;
        grid.DefaultCellStyle.SelectionForeColor = Color.Black;
        grid.AlternatingRowsDefaultCellStyle.BackColor = Color.FromArgb(24, 24, 24);
        grid.GridColor = Color.FromArgb(48, 48, 48);
        return grid;
    }

    private static DataTable LoadCsv(string path)
    {
        DataTable table = new();

        if (!File.Exists(path)) return table;

        string[] lines = File.ReadAllLines(path);

        if (lines.Length == 0) return table;

        foreach (string h in lines[0].Split(','))
        {
            table.Columns.Add(h);
        }

        for (int i = 1; i < lines.Length; i++)
        {
            if (string.IsNullOrWhiteSpace(lines[i])) continue;

            string[] cells = lines[i].Split(',');

            if (cells.Length < table.Columns.Count)
            {
                Array.Resize(ref cells, table.Columns.Count);
            }

            table.Rows.Add(cells.Take(table.Columns.Count).ToArray());
        }

        return table;
    }

    private static Panel CardPanel()
    {
        return new Panel
        {
            Dock = DockStyle.Fill,
            BackColor = Theme.Card,
            Margin = new Padding(0, 0, 0, 10)
        };
    }

    private static Panel SectionPanel(Control child)
    {
        Panel panel = new()
        {
            Dock = DockStyle.Fill,
            BackColor = Theme.Card,
            Padding = new Padding(12),
            Margin = new Padding(0, 0, 0, 10)
        };

        panel.Controls.Add(child);
        return panel;
    }

    private static Panel EmptyState(string title, string message)
    {
        Panel panel = new()
        {
            Dock = DockStyle.Fill,
            BackColor = Theme.Card,
            Padding = new Padding(30)
        };

        Label titleLabel = new()
        {
            Text = title,
            Dock = DockStyle.Top,
            Height = 48,
            ForeColor = Theme.Accent,
            Font = new Font("Segoe UI", 16, FontStyle.Bold),
            TextAlign = ContentAlignment.BottomCenter
        };

        Label messageLabel = new()
        {
            Text = message,
            Dock = DockStyle.Top,
            Height = 70,
            ForeColor = Theme.Muted,
            Font = new Font("Segoe UI", 11),
            TextAlign = ContentAlignment.TopCenter,
            Padding = new Padding(0, 8, 0, 0)
        };

        panel.Controls.Add(messageLabel);
        panel.Controls.Add(titleLabel);
        return panel;
    }

    private static Panel StatCard(string title, string value, string caption)
    {
        Panel outer = new()
        {
            Dock = DockStyle.Fill,
            BackColor = Theme.Bg,
            Padding = new Padding(6)
        };

        Panel card = new()
        {
            Dock = DockStyle.Fill,
            BackColor = Theme.Card,
            Padding = new Padding(50)
        };

        Label number = new()
        {
            Text = value,
            Dock = DockStyle.Top,
            Height = 42,
            ForeColor = Theme.Accent,
            Font = new Font("Segoe UI", value.Length >= 8 ? 15 : 20, FontStyle.Bold),
            TextAlign = ContentAlignment.MiddleCenter,
        };

        Label label = new()
        {
            Text = title,
            Dock = DockStyle.Top,
            Height = 24,
            ForeColor = Color.White,
            Font = new Font("Segoe UI", 9, FontStyle.Bold),
            TextAlign = ContentAlignment.MiddleCenter
        };

        Label cap = new()
        {
            Text = caption,
            Dock = DockStyle.Top,
            Height = 24,
            ForeColor = Theme.Muted,
            Font = new Font("Segoe UI", 8),
            TextAlign = ContentAlignment.MiddleCenter
        };

        card.Controls.Add(cap);
        card.Controls.Add(label);
        card.Controls.Add(number);
        outer.Controls.Add(card);
        return outer;
    }

    private int CountRows(DataTable? table) => table?.Rows.Count ?? 0;

    private int CompletedCount()
    {
        if (_matchesTable == null) return 0;

        int count = 0;
        foreach (DataRow row in _matchesTable.Rows)
        {
            if (Convert.ToString(row["Status"]) == "Completed")
            {
                count++;
            }
        }

        return count;
    }

    private string StateText()
    {
        int state = NativeScheduler.State();

        return state switch
        {
            0 => "Not Started",
            1 => "Round 1",
            2 => "Round 2",
            3 => "Semi-Finals",
            4 => "Finals",
            5 => "Complete",
            _ => "Unknown"
        };
    }

    private static class Theme
    {
        public static readonly Color Bg = Color.FromArgb(15, 17, 19);
        public static readonly Color Sidebar = Color.FromArgb(8, 10, 12);
        public static readonly Color SidebarHover = Color.FromArgb(22, 28, 31);
        public static readonly Color SidebarActive = Color.FromArgb(24, 33, 36);
        public static readonly Color Card = Color.FromArgb(26, 29, 31);
        public static readonly Color Grid = Color.FromArgb(21, 23, 25);
        public static readonly Color SuccessCard = Color.FromArgb(31, 52, 43);
        public static readonly Color Gold = Color.FromArgb(146, 111, 18);
        public static readonly Color Accent = Color.FromArgb(83, 235, 177);
        public static readonly Color AccentSoft = Color.FromArgb(116, 245, 199);
        public static readonly Color Muted = Color.FromArgb(180, 187, 194);
    }
}
