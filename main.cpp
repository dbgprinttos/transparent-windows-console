#include <Windows.h>
#include <iostream>

int main() {
	// title
	SetConsoleTitle(L"transparent windows terminal in cpp");

	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	// save con mode
	DWORD consoleMode;
	GetConsoleMode(hStdout, &consoleMode);

	// enables the asci stuff
	SetConsoleMode(hStdout, consoleMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

	HWND consoleWindow = GetConsoleWindow();

	SetLayeredWindowAttributes(consoleWindow, 0, 192, LWA_ALPHA);
	SetWindowLong(consoleWindow, GWL_EXSTYLE, GetWindowLong(consoleWindow, GWL_EXSTYLE) | WS_EX_LAYERED);

	const char* colors[] = {
		"\x1b[31m", // red
		"\x1b[33m", // yellow
		"\x1b[32m", // green 
		"\x1b[36m", // cyan
		"\x1b[34m", // blue
		"\x1b[35m", // magenta

	};
	const char* text = "--------";
	int colorCount = sizeof(colors) / sizeof(colors[0]);
		
	// printing (color)
	for (int i = 0; text[i] != '\0'; ++i) {
		std::cout << colors[i % colorCount] << text[i];

		}
		std::cout << "\x1b[0m" << std::endl; // resets



std::cin.get();
return 0;
}