#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool mainMenu(vector<string> &courseList);
void displayChoices();
void displayCourses(vector<string> courseList);
void displayYearCourses(vector<string> courseList);
bool sortByTitle(string a, string b);
bool sortByCourseCode(string a, string b);

#endif
