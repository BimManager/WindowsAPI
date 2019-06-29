/*
 *  create_file.c
 */

#include <windows.h>

int main(void)
{
    HANDLE  hFile;

    hFile = CreateFile(
        "foo.txt",
        GENERIC_READ | GENERIC_WRITE,
        FILE_SHARE_READ,
        NULL,
        CREATE_ALWAYS,
        0,
        NULL);
    if (hFile != NULL)
        CloseHandle(hFile);
    return (0);
}
