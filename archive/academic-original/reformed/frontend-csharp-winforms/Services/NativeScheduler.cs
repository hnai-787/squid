using System.Runtime.InteropServices;
using System.Text;

namespace CompetitionScheduler.UI.Services;

internal static class NativeScheduler
{
    private const string DllName = "CompetitionSchedulerBackend.dll";

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    private static extern int LoadTeams(string teamFilePath);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    private static extern int GenerateSchedule(string matchesCsvPath, string logCsvPath);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    private static extern int SetMatchWinner(int matchId, int winnerTeamId, string matchesCsvPath, string logCsvPath);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    private static extern int SimulateCurrentRound(string matchesCsvPath, string logCsvPath);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    private static extern int SimulateFullTournament(string matchesCsvPath, string logCsvPath);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    private static extern int ResetTournament(string matchesCsvPath, string logCsvPath);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    private static extern int ExportTeams(string teamsCsvPath);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    private static extern int ExportReport(string reportHtmlPath);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    private static extern int GetTournamentState();

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    private static extern int SchedulerGetLastError(StringBuilder buffer, int bufferSize);

    private static string LastError()
    {
        StringBuilder buffer = new(2048);
        SchedulerGetLastError(buffer, buffer.Capacity);
        return buffer.ToString();
    }

    private static void Ok(int result)
    {
        if (result == 0)
        {
            string error = LastError();
            throw new InvalidOperationException(string.IsNullOrWhiteSpace(error) ? "Native backend operation failed." : error);
        }
    }

    public static void LoadTeamsFile(string path) => Ok(LoadTeams(path));
    public static void GenerateScheduleFile(string matches, string logs) => Ok(GenerateSchedule(matches, logs));
    public static void SetWinner(int matchId, int winnerTeamId, string matches, string logs) => Ok(SetMatchWinner(matchId, winnerTeamId, matches, logs));
    public static void SimulateRound(string matches, string logs) => Ok(SimulateCurrentRound(matches, logs));
    public static void SimulateTournament(string matches, string logs) => Ok(SimulateFullTournament(matches, logs));
    public static void Reset(string matches, string logs) => Ok(ResetTournament(matches, logs));
    public static void ExportTeamsFile(string path) => Ok(ExportTeams(path));
    public static void ExportReportFile(string path) => Ok(ExportReport(path));
    public static int State() => GetTournamentState();
}
