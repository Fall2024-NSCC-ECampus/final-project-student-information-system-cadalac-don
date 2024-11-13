#ifndef OPTIONS_H
#define OPTIONS_H
#endif //OPTIONS_H
using namespace std;

/*
 * The main menu list
 * This is used regularly.
 */
void optionsList() {

    cout << "\n______________________________________________________________________________\n";
    cout << "1) Print all Student Data\n";
    cout << "2) Sort the list of students in alphabetical order of last name\n";
    cout << "3) Add a new student and add marks\n";
    cout << "4) Calculate the letter grade of all students\n";
    cout << "5) Change the information of the previous student\n";
    cout << "6) Print the data of a specific student\n";
    cout << "7) Remove student from the list\n";
    cout << "8) Delete All student data\n";
    cout << "9) Change grading scheme\n";
    cout << "10) Exit \n";
    cout << "______________________________________________________________________________\n";
};

/*
 * Exit feature can be used multiple times if they do not completely exit the program.
 * This gives the user the option to reconsider leaving the app.
 * It does not fit with anything in the classes.
 */
void exitOption() {
    char response;
    while(true) {
        cout << "\nAre you sure you want to exit? [Y/N]\n";
        cin >> response;

        if(response == 'Y' || response == 'y') {
            cout << "Exiting\n";
            exit(0);
        }
        if (response == 'N' || response == 'n') {
            cout << "Continue the program\n";
            break;
        }
        else {
            cout << "Invalid - Try again...\n";
        }
    }
};