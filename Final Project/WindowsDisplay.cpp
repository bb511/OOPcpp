// Implementation of display methods.
// Kept in a separate file from the game classes (although easier to include
// there) since it is platform specific (windows only).
#include "windowsDisplay.h"

static int rows{0}, cols{0};

void maximizeConsole(){
    // Maximize the console window (only tested on uni computers).
    COORD screenBufferSize{1500, 300};
    HANDLE consoleHandle{GetStdHandle(STD_OUTPUT_HANDLE)};
    HWND consoleWindow{GetConsoleWindow()};

    SetConsoleScreenBufferSize(consoleHandle, screenBufferSize);
    ShowWindow(consoleWindow, SW_MAXIMIZE);
}

void getConsoleSize(){
    // Get the current size of the console window.
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void placeCursor(const size_t x, const size_t y) {
    // Place the cursor at a position (x,y) in the console.
    HANDLE consoleHandle{GetStdHandle(STD_OUTPUT_HANDLE)};
    COORD placeCursorHere;
    placeCursorHere.X = x;
    placeCursorHere.Y = y;
    SetConsoleCursorPosition(consoleHandle, placeCursorHere);
}

void centreText(size_t idx, size_t &indConst, char currChar){
    // Centre the text and make a 65 character limit for one line.
    if((idx%65 > 0 || idx%65 < 15) && idx > indConst * 65 && currChar == ' '){
        indConst++;
        std::cout << std::endl << std::setw(cols / 2 - 32 + idx % 65);
    }
}

void displayCentredText(std::string line, int rowsDown, bool animate){\
    // Show centred text in the console, animated or not.
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
    // Display a centred object (like a character ascii).
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
    // Clears the entire console window by filling it with spaces and
    // then restoring any attributes (like colors etc.).
    HANDLE consoleHandle;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count, cellCount;
    COORD homeCoords = {0, 0};

    consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    if (consoleHandle == INVALID_HANDLE_VALUE) return;
    if (!GetConsoleScreenBufferInfo(consoleHandle, &csbi)) return;
    cellCount = csbi.dwSize.X *csbi.dwSize.Y;
    if (!FillConsoleOutputCharacter(consoleHandle, (TCHAR) ' ', cellCount,
        homeCoords,&count)) return;
    if (!FillConsoleOutputAttribute(consoleHandle, csbi.wAttributes, cellCount,
        homeCoords, &count)) return;
    SetConsoleCursorPosition(consoleHandle, homeCoords);
}

void displayChoices(std::vector<std::string> choices){
    // Display the choices from a level in a neat fashion.
    size_t row{ 0 };
    for (auto const& choice : choices){
        displayCentredText(choice, row, false);
        displayCentredText("-----------------", row + 1, false);
        row += 2;
    }
}

int consoleX(){
    // Get the console X coordinate of the cursor.
    HANDLE consoleHandle;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    if (consoleHandle == INVALID_HANDLE_VALUE) return 0;
    if (!GetConsoleScreenBufferInfo(consoleHandle, &csbi)) return 0;

    return csbi.dwCursorPosition.X;
}

int consoleY(){
    // Get the console Y coordinate of the cursor.
    HANDLE consoleHandle;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    if (consoleHandle == INVALID_HANDLE_VALUE) return 0;
    if (!GetConsoleScreenBufferInfo(consoleHandle, &csbi)) return 0;

    return csbi.dwCursorPosition.Y;
}
