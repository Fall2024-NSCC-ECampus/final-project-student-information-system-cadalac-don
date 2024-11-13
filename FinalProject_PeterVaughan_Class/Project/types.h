#ifndef TYPES_H
#define TYPES_H
#include <string>

#endif TYPES_H

using namespace std;

/*
 * This is the struct for the vector.
 * I learned a lot about structs for this project.
 */
typedef struct Student {
    //Last Name, First Name, Student Number, Midterm 1, Midterm 2, Final Project
    string firstName;
    string lastName;
    int studentNumber;
    int midTermOne;
    int midTermTwo;
    int finalProject;

}Student;