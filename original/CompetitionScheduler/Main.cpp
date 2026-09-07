#include "MainMenuForm.h"
#include "TeamForm.h"
#include "ScheduleForm.h"
#include "SimulateForm.h"
#include "RulesForm.h"
#include "TeamLogoManager.h"
#include "Scheduler.h"
#include <Windows.h>

using namespace CompetitionScheduler;
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::IO;

/// <summary>
/// The main entry point for the application.
/// </summary>

// Function Prototypes
void GetTeamsFilePath(String^ currentDirectory);

[STAThread]
void Main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Create instances of Schedule and Simulation
    Scheduler scheduler;

	// Get the path to the current directory
	String^ currentDirectory = System::IO::Path::GetDirectoryName(Application::ExecutablePath);

	// Load team logos from the specified directory
    TeamLogoManager::LoadTeamLogos(currentDirectory + "\\TeamLogos");

	// Get the teams file path, if it doesn't exist, create it
	GetTeamsFilePath(currentDirectory);


	
	// Create a new instance of the MainMenuForm and pass the team logos dictionary as a parameter
	Application::Run(gcnew CompetitionScheduler::MainMenuForm(&scheduler));
}

// Function to Get the teams file path, if it doesn't exist, create it
void GetTeamsFilePath(String^ teamFileDirectory)
{
	String^ teamsFilePath = teamFileDirectory + "\\Teams.txt";
	if (!System::IO::File::Exists(teamsFilePath))
	{
		System::IO::File::Create(teamsFilePath)->Close();
		// Write sample teams data into file 
		cli::array<String^>^ sampleTeams = {
			"Cyber Hunters, Alice Smith;David Johnson;Peggy Brown, 1",
			"Shadow Warriors, Eve Garcia;Oscar Martinez, 2",
			"Code Breakers, Bob Davis;Nina Clark;Victor Hall, 3",
			"Binary Bandits, Trent Williams;Alice Lopez;Eve Smith, 4",
			"Firewall Falcons, Wendy Brown;Victor Garcia, 5",
			"Trojan Ninjas, Nina Johnson;Trent Clark;David Miller, 6",
			"Crypto Knights, Peggy Martinez;Mallory Jones, 7",
			"Packet Predators, Oscar Davis;Alice Lopez;Wendy Brown, 8",
			"Data Defenders, Charlie Martinez;Victor Hall, 9",
			"Red Team Titans, Nina Miller;Eve Smith;Bob Williams, 10",
			"Blue Team Blazers, David Lopez;Oscar Martinez, 11",
			"Phishing Phantoms, Mallory Hall;Wendy Clark;Victor Johnson, 12",
			"Exploit Experts, Peggy Garcia;Nina Jones, 13",
			"Malware Marauders, Bob Brown;Charlie Martinez;Alice Clark, 14",
			"Steganography Squad, Trent Smith;Oscar Williams;Victor Lopez, 15",
			"Hackathon Heroes, Wendy Miller;David Johnson, 16"
		};
		System::IO::File::WriteAllLines(teamsFilePath, sampleTeams);
	}
}