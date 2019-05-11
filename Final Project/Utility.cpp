#include "Utility.h"

double generateRandomNumber(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 1.0);
    return dis(gen);
}

void maximizeConsole(){
	COORD ScreenBufferSize{ 1500, 300 };
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	HWND ConsoleWindow = GetConsoleWindow();

	SetConsoleScreenBufferSize(ConsoleHandle, ScreenBufferSize);
	ShowWindow(ConsoleWindow, SW_MAXIMIZE);
}

static int rows{0}, cols{0};
void getConsoleSize(){
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void placeCursor(const size_t x, const size_t y) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD PlaceCursorHere;
	PlaceCursorHere.X = x;
	PlaceCursorHere.Y = y;
	SetConsoleCursorPosition(hConsole, PlaceCursorHere);
}

void centreText(size_t idx, size_t &indConst, char currChar){
	if((idx%65 > 0 || idx%65 < 15) && idx > indConst * 65 && currChar == ' '){
		indConst++;
		std::cout << std::endl << std::setw(cols / 2 - 32 + idx % 65);
	}
}

void displayCentredText(std::string line, int rowsDown, bool animate){
	size_t idx{0}, indConst{1}, trigger{0};
	if (line.length() > 65) placeCursor(cols / 2 - 32, rows / 2 + rowsDown);
	else placeCursor(cols/2 - line.length()/2, rows/2 + rowsDown);
	while(line[idx] != '\0'){
		centreText(idx, indConst, line[idx]);
		std::cout << line[idx]; 
		if (_kbhit()) { trigger = 1; _getch(); }
		if(animate && trigger == 0) Sleep(50);
		idx++;
	};
}

void displayCentredObject(std::string charAscii, int xpad, int ypad){
	size_t idx{0}, k{0};
	placeCursor(cols / 2 - 22 + xpad, rows / 5 + ypad);
	while(charAscii[idx] != '\0'){
		if(charAscii[idx] == '\n'){
			placeCursor(cols / 2 - 22 + xpad, rows / 5 + ypad + k);
			k++;
		}
		else
			std::cout<<charAscii[idx];
		idx++;
	}
}

void clearScreen(){
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(hStdOut, (TCHAR) ' ', cellCount,
		homeCoords,&count)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount,
		homeCoords, &count)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

int consoleX(){
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return 0;
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return 0;

	return csbi.dwCursorPosition.X;
}

int consoleY(){
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return 0;
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return 0;

	return csbi.dwCursorPosition.Y;
}

void timer(){
	int xCoord, yCoord;
	for (int i = 0; i < 300; i++){
		xCoord = consoleX(); yCoord = consoleY();
		placeCursor(0, 0);
		std::cout << 300-i<<"     ";
		placeCursor(xCoord, yCoord);
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	exit(1);
}

void displayChoices(std::vector<std::string> choices){
	size_t row{ 0 };
	for (auto const& choice : choices){
		displayCentredText(choice, row, false);
		displayCentredText("-----------------", row + 1, false);
		row += 2;
	}
}