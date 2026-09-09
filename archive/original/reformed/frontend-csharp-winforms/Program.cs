using CompetitionScheduler.UI.Forms;

namespace CompetitionScheduler.UI;

internal static class Program
{
    [STAThread]
    private static void Main()
    {
        ApplicationConfiguration.Initialize();
        Application.Run(new MainForm());
    }
}
