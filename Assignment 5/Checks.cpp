#include "Complex.h"
#include "Checks.h"
using namespace std;

bool checkStop(){
    // Check if the user typed stop when introducting data.
    string stopLine;
    if(!cin.fail()) return true;
    else{cin.clear(); getline(cin, stopLine);}
    transform(stopLine.begin(), stopLine.end(), stopLine.begin(), ::tolower);

    if(!stopLine.compare("stop")) throw runtime_error("Stopping...\n");
    else { cout<<"Invalid input, please try again!\n"; return false; }
}

bool checkIndex(size_t indexNumber, size_t upperLimit){
    if (indexNumber > 0 && indexNumber <= upperLimit) return true;
    cout<<"The index number has to be between the limits stated above!\n";
    return false;
}
