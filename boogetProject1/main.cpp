
// main.cpp //

// Sleep that uses time for exact amounts, also sleeps the thread instead of the main process, we're not using threads so that part doesent matter. 
#define threadSleep(x) std::this_thread::sleep_for(std::chrono::milliseconds(x));

#include <iostream> 
#include <vector> 
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <stdlib.h>
#include <fstream> 
#include <windows.h> 
#include <chrono>
#include <thread>

#include "menu.h"

bool toggleClicker = true;
bool toggleRightClicker = true;

bool hideClicker = true;

int main() {
	HWND hwnd = FindWindowA("LWJGL", nullptr);
	
	if (hwnd == NULL) {
		std::cout << "Minecraft was not found!";
		Sleep(2000);
		return 0;
	}
	else {
		std::cout << "Minecraft was found!\n";
		std::cout << "Loading...\n";
		Sleep(2000); // Sleep cuz it looks cool
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
				threadSleep(30); 
				SendMessage(hwnd, WM_LBUTTONUP, 0, MAKELPARAM(pt.x, pt.y));
				threadSleep(30);
			}
		}
		// Right clicker
		if (!toggleRightClicker) {
			if (GetAsyncKeyState(VK_RBUTTON) < 0) {
				POINT pt;
				GetCursorPos(&pt);
				SendMessage(hwnd, WM_RBUTTONDOWN, MK_RBUTTON, MAKELPARAM(pt.x, pt.y));
				threadSleep(20);
				SendMessage(hwnd, WM_RBUTTONUP, 0, MAKELPARAM(pt.x, pt.y));
				threadSleep(20);
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
