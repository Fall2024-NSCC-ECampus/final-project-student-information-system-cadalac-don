#ifndef TYPES_H
#define TYPES_H
#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include "types.h"
#include <algorithm>
#include <cassert>
#include <functional>
#include <iterator>
#include <vector>
#endif TYPES_H

using namespace std;

/*
 *  These are most of the option from the main menu - excluding quit.
 *  Each function does what it is supposed to do in the parent class and child class.
 *  The parent class named StudentList deals with the students.
 */
class StudentList {
public:

   //Last Name, First Name, Student Number, Midterm 1, Midterm 2, Final Project
   vector<Student> students = {{"Peter","Vaughan",123,89,78, 66},{"Chris","H",99, 100,89, 99}};

   //Prints student info out here.
   void studentInfo() {
      for(Student& student : students){
         cout << student.firstName << " " << student.lastName << ", Student ID: " << student.studentNumber << endl;
         cout << "Midterm #1: " << student.midTermOne << endl << "Midterm #2: " << student.midTermTwo << endl << "Final Project: " << student.finalProject << endl << endl;
      }
   }

   /* Sorts out names here to be printed out elsewhere.
    * All the names are uppercase names to compare - otherwise there will errors.
    * Lowercase and uppercase is different so lower case is printed after all the uppercase is done.
    * To solve this problem, when we compare, make everything uppercase but print out the proper name
    */
   static bool sortNamesNow(const struct Student &lastName1, const struct Student &lastName2) {
      string last_1 = lastName1.lastName;
      string last_2 =  lastName2.lastName;
      string first_1 = lastName1.firstName;
      string first_2 = lastName2.firstName;

      transform(last_1.begin(), last_1.end(), last_1.begin(),::toupper);
      transform(last_2.begin(), last_2.end(), last_2.begin(),::toupper);
      transform(first_1.begin(), first_1.end(), first_1.begin(),::toupper);
      transform(first_2.begin(), first_2.end(), first_2.begin(),::toupper);

      return last_1 < last_2 || (last_1 == last_2 && first_1 < first_2);
   }

   //This prints out the sorted names in a formatted way
   void sortNames() {
      cout << "\nSorting names..." << endl;
      sort(students.begin(),students.end(),sortNamesNow);
      for(int ii=0;ii<students.size();ii++)
         cout<<"Student "<< ii+1 <<" [Last name, First Name] " << students[ii].lastName << ", " << students[ii].firstName <<endl;
   }

   //You can add a student info here to be added to the vector
   void addStudent() {
      Student student;

      cout << "Enter Student First Name: \n";
      cin.ignore();
      getline(cin, student.firstName);

      cout << "Enter Student Last Name: \n";
      getline(cin, student.lastName);
      //cin >> student.lastName;

      cout << "Enter Student Number: \n";
      cin >> student.studentNumber;
      while(true) {
         if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input! Please try again!\n";
            cout << "Enter Student Number: \n";
            cin >> student.studentNumber;
         }
         if(!cin.fail())
            break;
      }

      while(true) {
         cout << "Enter Student's 1st Midterm (0-100): \n";
         cin.ignore();
         cin >> student.midTermOne;
         if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input! Please try again!\n";
            cout << "Enter Student's 1st Midterm (0-100): \n";
            cin >> student.midTermOne;
         }
         if(student.midTermOne < 0 || student.midTermOne > 100) {
            cout << "Number must be between 0 and 100!\n";
            continue;
         }
         if(!cin.fail())
            break;
      }

      while(true) {
         cout << "Enter Student's 2nd Midterm (0-100): \n";
         cin.ignore();
         cin >> student.midTermTwo;
         if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input! Please try again!\n";
            cout << "Enter Student's 2nd Midterm (0-100): \n";
            cin >> student.midTermTwo;
         }
         if(student.midTermTwo < 0 || student.midTermTwo > 100) {
            cout << "Number must be between 0 and 100!\n";
            continue;
         }
         if(!cin.fail())
            break;
      }

      while(true) {
         cout << "Enter Student's Final: \n";
         cin.ignore();
         cin >> student.finalProject;
         if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input! Please try again!\n";
            cout << "Enter Student's Final (0-100): \n";
            cin >> student.finalProject;
         }
         if(student.finalProject< 0 || student.finalProject > 100) {
            cout << "Number must be between 0 and 100!\n";
            continue;
         }
         if(!cin.fail())
            break;
      }
      students.push_back(student);
   }

   /* Change the names of students already in the vector.
    * If there are multiple people with the same exact name, this handles that.
    * I think there should be more class time to simplify error-handling because this function is long.
    * However, I did a lot of self-learning and I did learn a lot about error-handling.
    */
   void studentInfoChange(const string& firstName, const string& lastName) {
      int count = 0;
      string choice;

      for(Student& student : students)
      {
         if(student.firstName==firstName && student.lastName == lastName)
         {
            cout<< "\nA student is found!"<<endl;
            cout << student.firstName << " " << student.lastName << ", Student ID: " << student.studentNumber << endl;
            cout << "Midterm #1: " << student.midTermOne << endl << "Midterm #2: " << student.midTermTwo << endl << "Final Project: " << student.finalProject << endl << endl;

            while(true) {
               cout << "Modify this student? (Y/N)\n";
               cin >> choice;

               if(choice == "Y" || choice == "y")
                  break;

               if(choice == "N" || choice == "n")
                  break;

               else
                  cout << "Invalid\n";
            }

            //if there is another student with the same name, this will find it
            if(choice == "N" || choice == "n")
               continue;

            cout << "Enter Student First Name: \n";
            cin.ignore();
            getline(cin, student.firstName);
            cout << "Enter Student Last Name: \n";
            getline(cin, student.lastName);

            cout << "Enter Student Number: \n";
            cin >> student.studentNumber;
            while(true) {
            if(cin.fail()) {
               cin.clear();
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
               cout << "Invalid Input! Please try again!\n";
               cout << "Enter Student Number: \n";
               cin >> student.studentNumber;
            }
            if(!cin.fail())
               break;
            }

            while(true) {
               cout << "Enter Student's 1st Midterm (0-100): \n";
               cin.ignore();
               cin >> student.midTermOne;
            if(cin.fail()) {
               cin.clear();
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
               cout << "Invalid Input! Please try again!\n";
               cout << "Enter Student's 1st Midterm (0-100): \n";
               cin >> student.midTermOne;
            }
            if(student.midTermOne < 0 || student.midTermOne > 100) {
               cout << "Number must be between 0 and 100!\n";
               continue;
            }
            if(!cin.fail())
               break;
            }

         while(true) {
            cout << "Enter Student's 2nd Midterm (0-100): \n";
            cin.ignore();
            cin >> student.midTermTwo;
            if(cin.fail()) {
               cin.clear();
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
               cout << "Invalid Input! Please try again!\n";
               cout << "Enter Student's 2nd Midterm (0-100): \n";
               cin >> student.midTermTwo;
            }
            if(student.midTermTwo < 0 || student.midTermTwo > 100) {
               cout << "Number must be between 0 and 100!\n";
               continue;
            }
            if(!cin.fail())
               break;
         }

         while(true) {
            cout << "Enter Student's Final: \n";
            cin.ignore();
            cin >> student.finalProject;
            if(cin.fail()) {
               cin.clear();
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
               cout << "Invalid Input! Please try again!\n";
               cout << "Enter Student's Final (0-100): \n";
               cin >> student.finalProject;
            }
            if(student.finalProject< 0 || student.finalProject > 100) {
               cout << "Number must be between 0 and 100!\n";
               continue;
            }
            if(!cin.fail())
               break;
         }
      count++;
      }

      }
      if(count==0)
         cout<<"\nStudent not found "<<endl;
   }

   //This prints the student that needs to be found. Otherwise, it will be error-handled
   void PrintStudentInfo(const string& firstName, const string& lastName){
      int count = 0;
      for(Student& student : students)
      {
         if(student.firstName==firstName && student.lastName == lastName)
         {
            cout<< "\nThe student is found!"<<endl;
            cout << student.firstName << " " << student.lastName << ", Student ID: " << student.studentNumber << endl;
            cout << "Midterm #1: " << student.midTermOne << endl << "Midterm #2: " << student.midTermTwo << endl << "Final Project: " << student.finalProject << endl << endl;
            count++;
         }
      }
      if(count==0)
         cout<<"\nStudent not found "<<endl;
   }

   // clears one particular student data - perfect function length.
   void clearStudentInfo(int listInt) {
      cout<< "\nThe position is found!\nStudent will be cleared if there is any data!"<<endl;
      students.erase(students.begin()+listInt-1);
   }

   // clears all student data - perfect function length.
   void deleteStudent() {
      students.erase(students.begin(), students.end());
      cout << "All Info Deleted\n\n";
   }

   //these are the default values and percentage weights
   double midterm1 = 25;
   double midterm2 = 25;
   double finals = 50;
   string choice;
   int grade;

   //This finds out the letter grade of a student.
   void letterGrade() {
      Student student;
      for(Student& studentData : students) {
         cout << studentData.firstName << " " << studentData.lastName << endl;
         cout << "Midterm #1: " << studentData.midTermOne << endl << "Midterm #2: " << studentData.midTermTwo << endl << "Final Project: " << studentData.finalProject << endl;

         grade = ((studentData.midTermOne * (midterm1/100)) + (studentData.midTermTwo * (midterm2/100)) + (studentData.finalProject*(finals/100)));
         cout << "Final Grade: " << grade << endl;

         if(grade >= 90 && grade <= 100)
            cout << "Grade Letter A" << endl << endl;

         else if(grade >= 80 && grade < 90)
            cout << "Grade Letter B" << endl << endl;

         else if(grade >= 70 && grade < 80)
            cout << "Grade Letter C" << endl << endl;

         else if(grade >= 60 && grade < 70)
            cout << "Grade Letter D" << endl << endl;

         else if(grade < 60)
            cout << "Grade Letter F" << endl << endl;
      }
   }

   //The user can change the grading scheme here.
   void gradingScheme() {
      //default is 25% for midterm #1 - 25% for midterm #2 - 50% for Final Project
      cout << "Current grading scheme: \nMidterm #1 % Weight: " << midterm1 << "\nMidterm #2 % Weight: " << midterm2 << "\nFinal Project % Weight: " << finals << endl;

      while(true) {
         cout << "Change Grading Scheme? [Y/N]\n";
         cin >> choice;
         if(choice == "Y" || choice == "y") {
            while(true) {
               cout << "\nMin percentage 5% \nMax percentage 40%:\nMidterm #1 New % Weight:" << endl;
               cin >> midterm1;
               if(cin.fail()) {
                  cin.clear();
                  cin.ignore(numeric_limits<streamsize>::max(), '\n');
                  cout << "Invalid Input! Please try again!\n";
                  cout << "Enter Student's 1st Midterm (0-100): \n";
                  cin >> midterm1;
               }
               if(midterm1 < 5 || midterm1 > 40) {
                  cout << "Number must be between 5 and 40!\n";
                  continue;
               }
               if(!cin.fail())
                  break;
            }
            while(true) {
               cout << "\nMin percentage 5% \nMax percentage 40%:\nMidterm #2 New % Weight:" << endl;
               cin >> midterm2;
               if(cin.fail()) {
                  cin.clear();
                  cin.ignore(numeric_limits<streamsize>::max(), '\n');
                  cout << "Invalid Input! Please try again!\n";
                  cout << "Enter Student's 2st Midterm (0-100): \n";
                  cin >> midterm2;
               }
               if(midterm2 < 5 || midterm2 > 40) {
                  cout << "Number must be between 5 and 40!\n";
                  continue;
               }
               if(!cin.fail())
                  break;
            }

            cout << "\nFinal Project New % Weight Will Be Calculated " << endl;
            finals = 100 - midterm1 - midterm2;
            cout << "Current grading scheme: \nMidterm #1 % Weight: " << midterm1 << "\nMidterm #2 % Weight: " << midterm2 << "\nFinal Project % Weight: " << finals << "\n\n";
            break;
         }

         if(choice == "N" || choice == "n") {
            cout << "Scheme Not Changed\n\n";
            break;
         }
         else
            cout << "Invalid Choice!" << endl;
      }
   }
};

class startup : public Student {
public:

   static void data() {
      cout << "\n\n\nLoading Program";
   }
};