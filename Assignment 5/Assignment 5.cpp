#include "Assignment 5.h"
#include "Complex.h"
#include "Menu.h"
using namespace std;

complex getUserInput(){
    // Reads in the user input and returns a tuple.
    complex userInput;
    while(true){
        cin>>userInput; if(checkStop()) break;
    }
    return userInput;
}

void populateNumbers(vector<complex> &numberList){
    complex uIn;
    while(true){
        try{ uIn = getUserInput(); }
        catch(const exception& e){ cout<<e.what(); break; }
        numberList.push_back(uIn);
        cout<<"Copy of complex number stored!\n";
    }
}

int main(){
    vector<complex> numberList;
    greetingsInstructions();
    populateNumbers(numberList); cout<<endl;
    while(mainMenu(numberList));
    return 0;
}
