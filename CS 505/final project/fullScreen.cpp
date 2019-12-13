#include <windows.h>

void MaximizeOutputWindow()
{
    HWND consoleWindow = GetConsoleWindow(); //This gets the value Windows uses to identify your output window
    ShowWindow(consoleWindow, SW_MAXIMIZE); // his mimics clicking on its' maximize button
}