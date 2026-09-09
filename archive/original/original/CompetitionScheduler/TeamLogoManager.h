#pragma once

#include <Windows.h>
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Drawing;

public ref class TeamLogoManager abstract sealed
{
public:
    // Dictionary to store team logos (key: team ID, value: Image^)
    static Dictionary<int, Image^>^ TeamLogos = gcnew Dictionary<int, Image^>();

    // Method to load team logos from a specified directory
    static void LoadTeamLogos(String^ logosPath)
    {
        cli::array<String^>^ files = System::IO::Directory::GetFiles(logosPath);

        // Ensure at least 16 logos exist
        if (files->Length < 16)
        {
            throw gcnew InvalidOperationException("Insufficient logos in the directory.");
        }

        // Randomly assign logos to team IDs
        Random^ random = gcnew Random();
        for (int i = 0; i < 16; i++)
        {
            int randomIndex = random->Next(0, files->Length);

            // Load the logo and associate it with the team ID (1 to 16)
            TeamLogos->Add(i + 1, Image::FromFile(files[randomIndex]));

            // Remove the selected file to avoid duplicates
            files[randomIndex] = files[files->Length - 1];
            Array::Resize(files, files->Length - 1);
        }
    }

    // Method to get a team logo by index
    static Image^ GetTeamLogo(int teamId)
    {
        if (TeamLogos->ContainsKey(teamId))
        {
            return TeamLogos[teamId];
        }
        else
        {
            throw gcnew KeyNotFoundException("Team ID not found.");
        }
    }

    // Method to clear the team logos dictionary and free memory
    static void ClearTeamLogos()
    {
        for each (KeyValuePair<int, Image^> kvp in TeamLogos)
        {
            delete kvp.Value;  // Free memory used by the Image
        }
        TeamLogos->Clear();  // Clear the dictionary
    }
};
