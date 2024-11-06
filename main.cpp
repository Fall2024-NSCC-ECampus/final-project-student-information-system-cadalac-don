#include <iostream>
#include "options.h"
#include "student.cpp"
#include <string>

using namespace std;

/*
 * The main code that calls on other code.
 * The decisions are made here before calling other code.
 * options.h is the main menu option
 * types.h is the list of datatypes for the vector in the student.cpp for the student info.
 * While-loop that is always true until exit is selected.
 * Each option works as outlined.
 */
int main() {
    string choice;
    StudentList students;
    startup startup;

    startup.data();

    while(true) {
        optionsList();
        cin >> choice;

        if(choice == "1") {
            //Complete - Print all the entered students
            cout << "\nPrint all Student Data.\n\n";
            students.studentInfo();
        }

        else if(choice == "2") {
            //Complete - includes error-handling of names
            cout << "\n2) Sort the list of students in alphabetical order of last name.\n";
            //People with the same last names, they will be sorted by their first name
            students.sortNames();
        }

        else if(choice == "3") {
            //Complete - Works without errors
            cout << "\nAdd a new student and add marks.\n\n";
            //Last Name, First Name, Student Number, Midterm 1, Midterm 2, Final Project
            students.addStudent();
        }

        else if(choice == "4") {
            //Complete - Works fine without any errors
            cout << "\nCalculate the letter grade of all students.\n\n";
            students.letterGrade();
        }

        else if(choice == "5") {
            // Complete - works without errors - finds everyone with the same name
            cout << "\nChange the information of the previous student. \n";
            string firstname,lastname;
            cout<< "Please enter the student First name: \n";
            cin>> firstname;
            cout<< "Please enter the student Last name: \n";
            cin>> lastname;
            students.studentInfoChange(firstname,lastname);
        }

        else if(choice == "6") {
            //Complete - works without errors
            cout << "\nPrint the data of a specific student. \n";
            string firstname,lastname;
            cout<< "Please enter the student First name: \n";
            cin>> firstname;
            cout<< "Please enter the student Last name: \n";
            cin>> lastname;
            students.PrintStudentInfo(firstname,lastname);
        }

        else if(choice == "7") {
            //Error-handling complete - works within scope
            cout << "\nRemove student from the list.\n";
            int listInt;

            while(true) {
                cout<< "Starting at Position +1\nPlease enter the student position: \n";
                cin>> listInt;
                if(cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid Input! Please try again!\n";
                    cout<< "Starting at Position #1\nPlease enter the student position: \n";
                    cin >> listInt;
                }
                if(listInt<1) {
                    cin.clear();
                    cout << "Invalid Input! Please enter a number higher than 0!\n";
                    continue;
                }
                if(!cin.fail())
                    break;
            }
            students.clearStudentInfo(listInt);
        }

        else if(choice == "8") {
            //Completed - Deleted all data and works fine without errors
            cout << "\nDelete All student data.\n";
            students.deleteStudent();
        }

        else if(choice == "9") {
            //Complete with error-handling - works with calculating grades, too!
            cout << "\n9) Change grading scheme.\n\n";
            //default is 25% for midterm #1 - 25% for midterm #2 - 50% for Final Project
            students.gradingScheme();
        }

        else if(choice == "10") {
            //Complete - exits with error handling
            exitOption();
        }

        else
            //Error-handling
            cout << "\nPlease enter a valid answer. \n";
    }
    return 0;
}