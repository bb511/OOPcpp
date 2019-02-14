/*
Title: Assignment 3
Author: Patrick Odagiu

Simple program that reads in course codes and names inputted by the user
and stores them in a vector of strings. The user can then display this vector,
sort it with respect to the course code or title and display all the courses
in a certain year.
*/

#include <sstream>
#include <vector>
#include "Checks.h"
#include "Display.h"
using namespace std;

void greetingInstructions(){
    // Displays a greeting and a set of instructions for the user.
    cout<<"Hello and welcome to this simple course storer.\n";
    cout<<"Type \"stop\" whenever you would like to finish inputting.\n";
    cout<<"Please give course numbers and the titles one by one: ";
}

string generateCourseString(int courseNumber, string courseTitle){
    // Generates the course string to be stored in a vector
    // using a string stream.
    ostringstream courseString;
    courseString<<"PHYS "<<courseNumber<<" "<<courseTitle;
    return courseString.str();
}

string readUserInput(){
    //Reads the user input.
    string courseTitle{"0"}; int courseNumber{0};
    while(true){
        cin>>courseNumber; cin>>ws; getline(cin, courseTitle);
        if(checkStop()) return "stopped";
        if(checkNumber(courseNumber) && checkTitle(courseTitle)) break;
    }
    return generateCourseString(courseNumber, courseTitle);
}

void populateVector(vector<string> &courseList){
    // Populate the course list with courses.
    string userInput;
    while(true){
        userInput = readUserInput();
        if(!userInput.compare("stopped")) break;
        courseList.push_back(userInput);
        cout<<"OK!\n";
    }
}

int main(){
    vector<string> courseList;
    greetingInstructions();
    populateVector(courseList);
    bool stop{mainMenu(courseList)};
    while(!stop) stop = mainMenu(courseList);
    return 0;
}
