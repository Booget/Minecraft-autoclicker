
// menu.cpp //

#include <iostream> 
#include <vector> 
#include <string> 
#include <fstream> 
#include <windows.h> 
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <stdlib.h>

#include "menu.h"


void menu() {
	system("CLS"); // This is not best practice but works.
	
	SetConsoleTitleA("Booget Clicker");
	HWND hwndCmd = GetConsoleWindow();
	if (hwndCmd != NULL) { MoveWindow(hwndCmd, 340, 550, 340, 210, TRUE); }
	SetWindowLong(hwndCmd, GWL_STYLE, GetWindowLong(hwndCmd, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
	::SetWindowPos(hwndCmd, HWND_TOPMOST, 0, 0, 0, 0, SWP_DRAWFRAME | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
	::ShowWindow(hwndCmd, SW_NORMAL);

	std::cout << "            [Booget Clicker]\n\n";
	std::cout << "Averge CPS:                       [17]\n";
	std::cout << "Toggle Left Clicker Key:          [F9]\n";
	std::cout << "Toggle Right Clicker Key:        [F10]\n";
	std::cout << "Show Clicker Key:             [INSERT]\n\n";
	std::cout << "[LOG]~$ Loaded Clicker";

}
