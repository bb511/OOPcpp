#include "ComplexList.h"
using namespace std;

complex selectNumber(vector<complex> numberList){
    // Select a complex number from a list and return it.
    size_t indexNumber;
    cout<<"Please type a number from 1 to "<<numberList.size()<<" to select: ";
    while(true){
        cin>>indexNumber;
        if(checkStop() && checkIndex(indexNumber, numberList.size())) break;
    }
    return numberList[indexNumber-1];
}

vector<complex> selectNumbers(vector<complex> numberList){
    // Select multiple complex numbers from a list and return a vector of them.
    vector<complex> subNumberList;
    cout<<"\nPlease type \"stop\" when you want to end inputting numbers.";
    displayNumbers(numberList);
    while(true){
        try{ subNumberList.push_back(selectNumber(numberList));}
        catch(const exception& e){ cout<<e.what(); break; }
    }
    return subNumberList;
}

void displayNumbers(vector<complex> numberList){
    // Display all the numbers in a list of complex numbers.
    cout<<endl;
    for(size_t i=1; i<=numberList.size(); i++)
        cout<<i<<". "<<numberList[i-1]<<endl;
}
void addNumbers(vector<complex> numberList){
    // Add all the numbers in a list of complex numbers.
    complex sum;
    for(size_t i=0; i<numberList.size(); i++)
        sum = sum + numberList[i];
    cout<<"The sum of all complex numbers you selected is: "<<sum<<endl;
}
void subtractNumbers(vector<complex> numberList){
    // Select two numbers from a list of complex numbers and subtract them.
    displayNumbers(numberList);
    cout<<"Please select the first and second number you want to subtract.\n";
    complex firstChoice{selectNumber(numberList)};
    complex secondChoice{selectNumber(numberList)};
    complex difference{firstChoice - secondChoice};
    cout<<"The difference of the complex numbers you selected is: "<<difference<<endl;
}
void multiplyNumbers(vector<complex> numberList){
    // Multiply all numbers in a list of complex numbers.
    complex product{numberList[0]};
    for(size_t i=1; i<numberList.size(); i++)
        product = product * numberList[i];
    cout<<"\nThe product of all complex numbers you selected is: "<<product<<endl;
}
void divideNumbers(vector<complex> numberList){
    // Select two numbers from a list of complex numbers and divide them.
    displayNumbers(numberList);
    cout<<"Please select the first and second number you want to divide.\n";
    complex firstChoice{selectNumber(numberList)};
    complex secondChoice{selectNumber(numberList)};
    complex ratio{firstChoice - secondChoice};
    cout<<"\nThe ratio of the complex numbers you selected is: "<<ratio<<endl;
}
