//
// Created by Tutu on 21/07/2020.
//
#include "loginAsUser.h"
#include <iostream>
#include<conio.h>
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

class Meniu {
public:
    void loginUser() {
        int choice2;
        bool gameOn2 = true;
        while (gameOn2 != false)           ///The Second Menu
        {
            cout << "\n";
            cout << "  [1] - New user \n ";
            cout << " [2] - Login as user \n ";
            cout << " [3] - Exit \n";
            cout << "\n Enter your choice and press enter: ";
            cin >> choice2;                   // Pick option
            cin.ignore(10, '\n');           // End when you press enter
            switch (choice2) {
                case 1: {
                    int numberOfCharacters = 0;
                    ofstream users;                 //file user
                    users.open("users.txt", ios::app);       //open file "user.txt"
                    string name1, password;
                    cout << "Enter username here: ";
                    cin >> name1;                             //Reading name
                    users << left << name1 << " ";                //Reading name in the file: user.txt
                    cout << "Enter your password: ";          //And password
                    password = "";
                    while (true) {
                        char ch1 = (char) _getch();                //{
                        while (ch1 != 13) {
                            numberOfCharacters++;
                            password.push_back(ch1);       //Reading characters and displaying "*"
                            cout << '*';
                            ch1 = _getch();
                        }                               //}
                        if (numberOfCharacters <= 8) {
                            password = "";
                            numberOfCharacters = 1;
                            cout
                                    << "\nThe password should contain at least 8 characters: \n";        //Verifing if the password should contain at least 8 character
                            cout << "!Try again! \n";
                            cout << "Enter your password: ";
                        } else break;                                                                 // If not try again
                    }

                    users << password << "\n";
                    users.close();                                                          //Reading the password and closing file
                    break;
                }
                case 2: {
                    int numberOfCharactersInPassword = 0;
                    string findUser = "", line1 = "", passwordAttempt = "", passwordRight = "";
                    ifstream find1;
                    find1.open("users.txt");        //open the file user.txt
                    cout<<"Default: \t Enter * cosmin * to see the program running\n";
                    cout << " User: ";
                    cin >> findUser;
                    while (getline(find1,line1))
                    {
                        if(line1.find(findUser)!=std::string::npos)

                            for(int i=0;i<line1.length();i++)                   //searhing for the line with the correct user and password
                            {if(line1[i]==' ')
                                    numberOfCharactersInPassword=1;
                                if(numberOfCharactersInPassword==1)
                                {
                                    passwordRight.append(sizeof(char),line1[i]);
                                }
                            }

                    }
                    cout<<"Default: \tEnter * 123456789 * to see the program running \n";
                    cout << "\n Password: ";
                    numberOfCharactersInPassword = 1;                     // Number of characters initieted with 1;
                    bool n = true;
                    while (n) {
                        char ch1 = _getch();
                        do {
                            numberOfCharactersInPassword++;               //For every character, increments
                            passwordAttempt.push_back(ch1);
                            cout << '*';
                            ch1 = _getch();
                        } while (ch1 != 13);
                        if (numberOfCharactersInPassword <= 8) {
                            passwordAttempt = "";
                            numberOfCharactersInPassword = 1;
                            cout << "\nThe password should contain at least 8 characters: \n";
                            cout
                                    << "!Try again! \n";                                                 //  Return if the password has les that 8 characters
                            cout << "Enter your password: ";
                            break;
                        } else n=false;
                    }

                    passwordRight.erase (passwordRight.begin(), passwordRight.begin()+1);//It needs to be trimed
                    trim(passwordRight);
                    trim(passwordAttempt);

                    if (passwordRight == passwordAttempt)                                                 //If the passwords match, go to the next menu
                    {
                        LoginAsUser login1;
                        login1.loginAsUser();
                    } else {
                        cout << "\n Password or user incorect\n Try again!\n";
                        find1.close();                                                                  // If the passwords do not match, go back && close the user.txt
                        break;
                    }
                    find1.close();                                                                      //If it succeded , go back
                    break;
                }
                case 3: {
                    gameOn2 = false;                          //Go back
                    break;
                }
                default:
                    cout << "\nNot a Valid Choice. \n";         //Enter a valid choice


            }

        }

    }
public: string trim( string& str)                      /// A function for triming strings
    {
        size_t first = str.find_first_not_of(' ');
        if (string::npos == first)
        {
            return str;
        }
        size_t last = str.find_last_not_of(' ');
        return str.substr(first, (last - first + 1));
    };

};