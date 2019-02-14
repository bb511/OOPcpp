#include "Checks.h"
#include "Display.h"

void displayCourses(vector<string> courseList){
    // Display the contents of the course list previoulsy given by the user.
    vector<string>::iterator i{courseList.begin()};
    while(i != courseList.end()){
        cout<<i[0]<<endl;
        i++;
    }
}

char convertToChar(int number){
    // Convert an integer into a char.
    string stringNumber{to_string(number)};
    char const *charNumber = stringNumber.c_str();
    return *charNumber;
}

void displayYearCourses(vector<string> courseList){
    // Display the courses in a certain year by looking
    // at the first digit in the course code.
    int year, sw{0}; vector<string>::iterator i{courseList.begin()};
    cout<<"Please choose a year: "; cin>>year;
    while(!checkYear(year)) cin>>year;

    while(i != courseList.end()){
        if(i[0][5] == convertToChar(year)) {cout<<i[0]<<endl; sw = 1;}
        i++;
    }
    if(sw == 0) cout<<"Sorry, no courses with this year.\n";
}

bool sortByTitle(string a, string b){
    // Sorts a vector of strings (containing the course codes and names)
    // alphabetically by course title.
    size_t secondSpace{a.find(" ", 6)};
    a = a.substr(secondSpace);
    secondSpace = b.find(" ", 6);
    b = b.substr(secondSpace);

    return a < b;
}

bool sortByCourseCode(string a, string b){
    // Sorts a vector of strings (containing the course codes and names)
    // in ascending order by course code.
    size_t firstSpace{a.find(" ")}; size_t secondSpace{a.find(" ", 6)};
    a = a.substr(firstSpace, secondSpace);
    firstSpace = b.find(" "); secondSpace = b.find(" ", 6);
    b = b.substr(firstSpace, secondSpace);

    return a < b;
}

void displayChoices(){
    // Display the options to the user after inserting all the data.
    cout<<endl;
    cout<<"Would you like to (give the number before the option):\n";
    cout<<"1. Display the courses.\n";
    cout<<"2. Display the courses in a year.\n";
    cout<<"3. Sort the courses by title.\n";
    cout<<"4. Sort the courses by course code.\n";
    cout<<"5. Exit.\n";
}

bool mainMenu(vector<string> &courseList){
    // Present a list of options to the user through which he can display
    // and manipulate the data he just typed in (course codes and names).
    displayChoices();
    unsigned int option; cin>>option;
    switch(option){
        case 1: displayCourses(courseList); break;
        case 2: displayYearCourses(courseList); break;
        case 3: sort(courseList.begin(), courseList.end(), sortByTitle);
                break;
        case 4: sort(courseList.begin(), courseList.end(), sortByCourseCode);
                break;
        case 5: return true;
        default: cout<<"Sorry, that is not a valid option.\n";
                 break;
    }

    return false;
}
