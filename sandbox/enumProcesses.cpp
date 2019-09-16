/*
 *  main.cpp
 */

#include <stdio.h>
#include <tchar.h>

#include <windows.h>
#include <psapi.h>

void    GetProcessName(DWORD processId);

int    main(void)
{
    DWORD   aProcesses[1024];
    DWORD   cbNeeded;
    DWORD   cProcesses;
    unsigned int    i;

    if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
        return (1);
    cProcesses = cbNeeded / sizeof(DWORD);
    while (cProcesses--)
    {
        if (aProcesses[cProcesses])
            GetProcessName(aProcesses[cProcesses]);
    }
    return (0);
}

void    GetProcessName(DWORD processId)
{
    TCHAR   szProcessName[MAX_PATH] = TEXT("<unknown>");

    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | 
                        PROCESS_VM_READ, FALSE, processId);
    
    if (hProcess != NULL)
    {
        HMODULE hMod;
        DWORD   cbNeeded;

        if (EnumProcessModules(hProcess, &hMod,
            sizeof(hMod), &cbNeeded))
        {
            GetModuleBaseName(hProcess, hMod, szProcessName,
                sizeof(szProcessName) / sizeof(szProcessName[0]));
        }
    }
    _tprintf(TEXT("%s (PID: %u)\n"), szProcessName, processId);
    CloseHandle(hProcess);
}