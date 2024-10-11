#include <iostream>
#include <windows.h>

#include <string.h>
using namespace std;

BOOL callback(HWND hwnd, LPARAM l)
{
    TCHAR buf[256];
    GetClassName(hwnd, buf, 100);
    if (strstr(buf, "Notepad")) {
            SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
            return FALSE;
    }
    return TRUE;
}

int main()
{
    EnumWindows(callback, 0);
    return 0;
}
