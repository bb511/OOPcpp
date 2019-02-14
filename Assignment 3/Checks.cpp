#include "Checks.h"

bool checkStop(){
    // Check if the user typed stop when introducting data.
    string stopLine;
    if(cin.fail()) {cin.clear(); getline(cin, stopLine);}
    transform(stopLine.begin(), stopLine.end(), stopLine.begin(), ::tolower);
    if(!stopLine.compare("stop")) return true;
    return false;
}

bool checkNumber(int courseNumber){
    // Check if the user inputted a valid course number.
    bool condition1{courseNumber == 0};
    bool condition2{courseNumber < 0};
    if(condition1 || condition2){
        cout<<"The course number you gave is not valid! Please try agane: ";
        return false;
    }
    return true;
}

bool validString(string courseTitle){
    // Check if a string contains only numbers and return true if it does.
    return courseTitle.find_first_not_of("0123456789") == string::npos;
}

bool checkTitle(string courseTitle){
    // Check if the course name given by the user is valid.
    bool condition1{validString(courseTitle)};
    if(condition1){
        cout<<"The course title you gave is not valid! Please try agane: ";
        return false;
    }
    return true;
}

bool checkYear(int year){
    // Check if the year given by the user is a valid year.
    bool condition1{year < 0 && year > 9};
    bool condition2{cin.fail() || cin.peek() != '\n'};
    if(condition1 || condition2){
        cout<<"Sorry, your input was not valid, please try again: ";
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}
