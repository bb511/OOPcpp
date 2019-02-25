#include "Menu.h"
#include "ComplexList.h"
#include "Checks.h"
using namespace std;

void greetingsInstructions(){
    cout<<"Hello and welcome to this simple complex number program.\n";
    cout<<"Please input, on one line, the real part followed by the imaginary ";
    cout<<"part of a complex number.\n";
    cout<<"Please type \"stop\" to end the input phase.\n\n";
}

void mainMenuInstructions(){
    cout<<"\nPlease type the corresponding number to select an option.\n";
    cout<<"1. Show all complex numbers you introduced.\n";
    cout<<"2. Select a complex number and display further options.\n";
    cout<<"3. Select multiple complex numbers and display fruther options.\n";
    cout<<"4. Quit.\n";
}

void selectOneInstructions(){
    cout<<"\nPlease choose how to manipulate the complex number you selected.\n";
    cout<<"1. Display real part.\n";
    cout<<"2. Display imaginary part.\n";
    cout<<"3. Display modulus.\n";
    cout<<"4. Display argument.\n";
    cout<<"5. Display conjugate.\n";
    cout<<"6. Go back.\n";
}

void selectMultipleInstructions(){
    cout<<"\nPlease choose how to manipulate the complex number you selected.\n";
    cout<<"1. Add the numbers and display result.\n";
    cout<<"2. Subtract two numbers and display result.\n";
    cout<<"3. Multiply the numbers and display result.\n";
    cout<<"4. Divide two numbers and display result.\n";
    cout<<"5. Go back.\n";
}

bool selectOneMenu(vector<complex> numberList){
    displayNumbers(numberList);
    complex chosenNumber{selectNumber(numberList)};
    selectOneInstructions(); size_t option;
    while(cin>>option){
        switch(option){
            case 1: cout<<"Real part: "<<chosenNumber.getReal()<<endl; break;
            case 2: cout<<"Imaginary part: "<<chosenNumber.getImag()<<endl; break;
            case 3: cout<<"Modulus: "<<chosenNumber.modulus()<<endl; break;
            case 4: cout<<"Argument: "<<chosenNumber.argument()<<endl; break;
            case 5: cout<<"Conjugate: "<<chosenNumber.conjugate()<<endl; break;
            case 6: return false;
            default: cout<<"Sorry, that is not an option!\n"; break;
        }
    }
    return true;
}

bool selectMultipleMenu(vector<complex> numberList){
    vector<complex> subNumberList{selectNumbers(numberList)};
    cout<<"\n\nYou have selected:"; displayNumbers(subNumberList);
    selectMultipleInstructions(); size_t option;
    while(true){
        cout<<"Select another option: "; cin>>option;
        switch(option){
            case 1: addNumbers(subNumberList); break;
            case 2: subtractNumbers(subNumberList); break;
            case 3: multiplyNumbers(subNumberList); break;
            case 4: divideNumbers(subNumberList); break;
            case 5: return false;
            default: cout<<"Sorry, that is not an option!\n"; break;
        }
    }
    return true;
}


bool mainMenu(vector<complex> numberList){
    mainMenuInstructions();
    size_t option; cin>>option;
    switch(option){
        case 1: displayNumbers(numberList); break;
        case 2: while(selectOneMenu(numberList)); break;
        case 3: while(selectMultipleMenu(numberList)); break;
        case 4: return false;
        default: cout<<"Sorry, that is not a valid option!\n"; break;
    }
    return true;
}
