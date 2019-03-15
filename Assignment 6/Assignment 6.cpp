/*
Title: Matrix class
Author: Denis-Patrick Odagiu

Simple dynamic matrix class. Addition, multiplication and determinant operations
are defined. All the methods in the class are demonstrated in the main.
*/

#include "Assignment 6.h"
#include "Matrix.h"
using namespace std;

int main(){
    // Demonstration of methods in class matrix.
    cout<<"Default constructor:\n";
    matrix m1; cout<<m1<<endl;

    cout<<"Parametrized constructor:";
    const int m{2},n{2}; matrix m2(m,n);
    m2(1,1) = 1; m2(1,2) = 2; m2(2,1) = 1; m2(2,2) = 4;
    cout<<m2<<endl<<endl;

    cout<<"Deep copy by assignment:";

    cout<<"Initialise matrix m3: ";
    matrix m3(m,n); cout<<m3<<endl;
    cout<<"Copy m2 into m3: ";
    m3=m2; cout<<m3<<endl;
    cout<<"Change m2 and display m2 and m3 respectively: ";
    m2(1,1) = 5; cout<<m2<<endl<<"---"<<m3<<endl<<endl;

    cout<<"Deep copy by constructor: \n";
    cout<<"Initialise m4 with m2: ";
    matrix m4(m2); cout<<m4<<endl;
    cout<<"Change m2 again and display both m2 and m4 respectively: ";
    m2(2,1) = 7; cout<<m2<<endl<<"---"<<m4<<endl<<endl;

    cout<<"Move assignment demonstration:\n";
    matrix m6; m6 = move(m2); cout<<m2<<endl<<"---"<<m6<<endl<<endl;

    cout<<"Move constructor demonstration:\n";
    matrix m8(move(m4)); cout<<m4<<endl<<"---"<<m8<<endl<<endl;

    cout<<"Matrices:";
    cout<<m6<<endl<<"---"<<m3<<endl;
    cout<<"Their sum: ";
    matrix sum{m6+m3}; cout<<sum<<endl;
    cout<<"Their difference: ";
    matrix difference{m6-m3}; cout<<difference<<endl;
    cout<<"Their product: ";
    matrix product{m6*m3}; cout<<product<<endl;

    cout<<"Input a 3x3 matrix...\n";
    matrix m7(3,3); cin>>m7; cout<<m7<<endl;
    cout<<"The determinant of the matrix you declared: "<<m7.determinant();


    cout<<"\n\n\n\n\nWE SMART!\n"
          "⠁⠁⠁⠁⠁⠁⠐⢶⣶⣶⣶⣤⣤⡀⠁⠁⣠⣀⣀⠁⠁⠁⠁⠁⠁⠁⠁⠁⠁⠁\n"
          "⠁⠁⠁⠁⠁⠁⠁⠁⠙⢿⣯⣠⣶⣦⣤⣤⣌⣛⠻⢇⣠⣤⣤⠁⠁⠁⠁⠁⠁⠁\n"
          "⠁⠁⠁⠁⠁⠁⠁⠁⠁⠁⠻⣿⣿⣿⡟⢉⡤⢤⣤⣤⡍⠛⢡⢖⣥⣶⣦⣀⠁⠁\n"
          "⠁⠁⠁⠁⠁⠁⠁⠁⠁⠁⣠⣿⣿⣿⡏⣭⣶⣿⣿⠟⢿⣦⡡⣿⣿⡇⠁⡙⣷⡀\n"
          "⠁⠁⠁⠁⠁⠁⠁⣀⣴⣿⣿⣿⣿⣿⣿⡞⣿⣿⡟⢀⡀⣿⣿⢻⣿⣿⣀⣁⣿⠏\n"
          "⠁⠁⠁⢀⣠⣶⣿⣿⣿⣿⣿⣿⣿⣿⣟⢰⢻⣿⣇⣈⣴⣿⠟⢨⣛⠛⠛⠉⠁⠁\n"
          "⠁⣠⣶⣿⣿⡟⢋⠤⣤⠘⢿⣿⣧⡙⠻⠌⠒⠙⠛⢛⣫⣥⣿⣦⡈⠉⣡⣴⣾⠇\n"
          "⢰⣿⣿⣿⣿⠁⡇⠁⠙⠷⣤⡙⠻⢿⣿⣶⣶⣶⣿⣿⣿⣿⣿⣿⣿⠿⠟⠋⠁⠁\n"
          "⠘⣿⣿⣿⣿⣆⠻⣄⠁⣀⡀⠉⠙⠒⠂⠉⠍⠉⠉⠉⠉⣩⣍⣁⣂⡈⠠⠂⠁⠁\n"
          "⠁⠘⢿⣿⣿⣿⣦⡉⠳⢬⣛⠷⢦⡄⠁⠁⠁⠁⠁⣀⣼⣿⣿⠿⠛⠋⠁⠁⠁⠁\n"
          "⠁⠁⠁⠉⠻⢿⣿⣿⣷⣦⣬⣍⣓⡒⠒⣒⣂⣠⡬⠽⠓⠂⠁⠁⠁⠁⠁⠁\n";

    return 0;
}
