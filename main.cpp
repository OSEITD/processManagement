#include <iostream>
#include <windows.h>

int main() {
    const int numProcesses = 5;
    STARTUPINFO si[numProcesses];
    PROCESS_INFORMATION pi[numProcesses];

    for (int i = 0; i < numProcesses; ++i) 
    {
        ZeroMemory(&si[i], sizeof(STARTUPINFO));
        si[i].cb = sizeof(STARTUPINFO);

        CreateProcess(
            nullptr,                // Module name (use nullptr to run the same program)
            const_cast<LPSTR>("notepad.exe"), // Command line (executable name)
            nullptr,                // Process handle not inheritable
            nullptr,                // Thread handle not inheritable
            FALSE,     // Set handle inheritance to FALSE
            0,       // No creation flags
            nullptr, // Use parent's environment block
            nullptr, // Use parent's starting directory
            &si[i], // Pointer to STARTUPINFO structure
            &pi[i] // Pointer to PROCESS_INFORMATION structure
        );
    }

    return 0;
}

