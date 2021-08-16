
// main.cpp //

#include <iostream> 
#include <vector> 
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <stdlib.h>
#include <fstream> 
#include <windows.h> 

#include "menu.h"

bool toggleClicker = true;
bool toggleRightClicker = true;

bool hideClicker = true;

int main() {
	HWND hwnd = FindWindowA(NULL, "Lunar Client (1.8.9-61b802d/master)");
	if (hwnd == NULL) {
		std::cout << "Lunar client was not found!";
		Sleep(2000);
		return 0;
	}
	else {
		std::cout << "Lunar client was found!\n";
		std::cout << "Loading...\n";
		Sleep(2000);
		menu();
	}
	

	while (1) {
		// Toggle keys
		if (GetAsyncKeyState(VK_F10) & 1) {
			toggleRightClicker = !toggleRightClicker;
		}
		if (GetAsyncKeyState(VK_F9) & 1) {
			toggleClicker = !toggleClicker;
		}

		// Left clicker
		if (!toggleClicker) {
			if (GetAsyncKeyState(VK_LBUTTON) < 0) {
				POINT pt;
				GetCursorPos(&pt);
				SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(pt.x, pt.y));
				Sleep(30);
				SendMessage(hwnd, WM_LBUTTONUP, 0, MAKELPARAM(pt.x, pt.y));
				Sleep(30);
			}
		}
		// Right clicker
		if (!toggleRightClicker) {
			if (GetAsyncKeyState(VK_RBUTTON) < 0) {
				POINT pt;
				GetCursorPos(&pt);
				SendMessage(hwnd, WM_RBUTTONDOWN, MK_RBUTTON, MAKELPARAM(pt.x, pt.y));
				Sleep(20);
				SendMessage(hwnd, WM_RBUTTONUP, 0, MAKELPARAM(pt.x, pt.y));
				Sleep(20);
			}
		}

		// Hide console
		if (GetAsyncKeyState(VK_INSERT) & 1) {
			hideClicker = !hideClicker;
			if (!hideClicker) {
				::ShowWindow(::GetConsoleWindow(), SW_HIDE);
			}
			else if (hideClicker) {
				::ShowWindow(::GetConsoleWindow(), SW_SHOW);
			}
		}
	}
}