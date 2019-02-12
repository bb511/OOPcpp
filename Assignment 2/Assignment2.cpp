/*
Title: Assignment 2
Author: Patrick Odagiu
Date: 08/02/2019

Program that reads in a 1D list of data and calculates its mean, standard
deviation and standard error in the mean.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <cctype>
#include <math.h>
using namespace std;

ifstream openFile(string fileName){
    // Opens the data file and checks if it has been opened correctly.
    ifstream dataFile(fileName);
    if(!dataFile.good())
        throw runtime_error("Error: could not open file. "
                            "Maybe check if the name is ok?");
    return dataFile;
}

unsigned int getNumberOfPoints(ifstream &dataFile){
    // Counts and returns the number of data points in a data file.
    dataFile.unsetf(ios_base::skipws);
    unsigned pointCount = count(istream_iterator<char>(dataFile),
                                istream_iterator<char>(),
                                '\n');
    dataFile.clear(); dataFile.seekg(0, ios::beg);
    dataFile.setf(ios_base::skipws);
    return pointCount;
}

double readPoint(ifstream &dataFile){
    // Checks if the input data is OK and also if the next input is OK.
    // Returns a warning if next input is wrong type.
    double dataPoint; dataFile>>dataPoint;
    bool condition = (dataFile.fail() && !dataFile.eof());
    if(condition) cout<<"Warning: data file contains a word!\n";
    while(dataFile.fail() && !dataFile.eof()){
        dataFile.clear();
        dataFile.ignore(numeric_limits<streamsize>::max(), '\n');
        dataFile>>dataPoint;
    }
    return dataPoint;
}

double* readData(ifstream &dataFile, unsigned int pointsNumber){
    // Reads the data and stores it in an array.
    unsigned int i{0}; double* data = new double[pointsNumber-1];
    if(data == nullptr) throw runtime_error("Error: memory could not be alloc");

    while(i < pointsNumber){ data[i] = readPoint(dataFile); i++; }
    dataFile.close();
    return data;
}

double computeMean(double* data){
    // Computes the mean of the data.
    unsigned int i{0}; double sum{0};
    while(data[i] > pow(10, -200)) {sum += data[i]; i++;}
    return sum/i;
}

double computeSTD(double* data, double mean){
    // Computes the mean of the data.
    unsigned int i{0}; double sum{0};
    while(data[i] > pow(10, -200)) {sum += pow(data[i] - mean, 2); i++;}
    return sqrt(sum/(i-1));
}

int main(){
    string fileName; cout<<"Please give file name: "; cin>>fileName;
    ifstream dataFile{openFile(fileName)};
    unsigned pointsNumber{getNumberOfPoints(dataFile)};
    double* data{readData(dataFile, pointsNumber)};
    double mean{computeMean(data)}; double STD{computeSTD(data, mean)};
    double STDE{STD/sqrt(pointsNumber)};

    cout<<"Mean: "<<mean<<endl; cout<<"STD: "<<STD<<endl;
    cout<<"Standard error in the mean: "<<STDE<<endl;
}
