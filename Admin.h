//
// Created by Tutu on 21/07/2020.

#include <iostream>
#include<conio.h>
#include<fstream>
#include<conio.h>
#include "Meniu.h"
#include "RemoveLine.h"

using namespace std;

class Admin {

public:
    ///         This is the Menu for Admin and Password
    int adminPhase(int numberOfAttemptings) {
        string passWord = "password";
        string passWordAttempt = "";

        string userName = "admin";
        string userNameAttempt = " ";

        cout<<"\t\t\t type:"<<"* admin *"<<"  for username\n";
        cout<<"Username: ";
        int ch;
        cin>>userNameAttempt;                                  ///Reading ...
        if (trim(userName) == trim(userNameAttempt)) {      ///Compare the username introduced with the program's username
            cout << "\n\n";

            cout<<"\t\t\t type:"<<"* password *"<<"  for password\n";

            cout << "Password:";

            ch = _getch();
            while (ch != 13 ) {                 /// It seems that my program doesn't display corectly with Clion but it works perfectly in CodeBlocks
                passWordAttempt.push_back(ch);
                cout << '*';
                ch=_getch();
            }
            if (passWordAttempt == passWord) {      /// Compare the password introduced with the program's password
                cout << "\n____Thats right___\n";
                numberOfAttemptings = 0;
                adminPhase2();                     /// Go to Menu
            } else {
                cout << "\nThats wrong\n" << numberOfAttemptings << "attemptings left\n";
                if(numberOfAttemptings!=0)
                {numberOfAttemptings--;                     //  Decrementing Attempts
                    adminPhase(numberOfAttemptings);}         //  Sending numberOfAttemptings -1 (Recursive method)
                else
                    return 0;                                       /// Returning main menu
            }

        }
        else {
            cout << "\nThe username is misspelled\n";//  if the username is misspelled
            passWordAttempt,userNameAttempt = "";
            return 0;
        }


        return 0;
    }

public: void adminPhase2()                                                   //Admin phase 2
    {   int choice1;
        bool gameOn1 = true;
        cout << "-----------   Welcome back,admin   ------------------\n\n";
        while (gameOn1 != false)
        {
            cout<<'\n';
            cout << " [1] - Add products\n";
            cout << " [2] - Display your products\n";
            cout << " [3] - Delete products\n";
            cout << " [4] - Go back to the main menu.\n";
            cout << "\n Enter your choice and press enter: ";

            cin >> choice1;                         //Enter choice
            cin.ignore(10, '\n');

            switch (choice1)
            {
                case 1:  {bool continuu=true;
                    ofstream produse;
                    produse.open("produse.txt",ios::app);       //Open folder produse.txt
                    while(true)
                    {float price;
                        string name,qu;
                        cout<<"(!MUST ME AN INTEGER!)\tEnter quantity: ";
                        cin>>qu;
                        produse<<left<<"Quantity:"<<qu<<"     ";
                        cout<<"(MUST ME AN STRING)\tEnter product: ";
                        cin>>name;
                        produse<<left<<"Name:"<<name<<"    Price:";     //Writing in the text file
                        cout<<"Enter price: ";
                        cin>>price;
                        produse<<left<<price<<"\n";
                        cout<<"\nPress 1 to continue:\n";
                        cout<<"Press 2 to go back:\n";
                        if(_getch()=='2')                   //Condition to continue
                        {   break;
                            produse.close();
                        }

                        }
                    produse.close();                    //Close the file
                    break;
                }
                case 3:{RemoveLine remove;
                    int notInDatabase = 0;
                    cout << "Please Enter the product you want to delete: ";

                    string deleteProduct="";
                    cin >> deleteProduct;

                    if(remove.removeLine("produse.txt", deleteProduct)==1){
                        continue;
                    }

                }
                case 4:{
                    gameOn1=false;              //Case of going back to menu
                    break;
                }
                case 2:{
                    string line;
                    ifstream myfile ("produse.txt");
                    if (myfile.is_open())
                    {
                        while (! myfile.eof() )
                        {
                            getline (myfile,line);          //Displaying products
                            cout << line << endl;
                        }
                        myfile.close();
                    }
                    else cout << "Unable to open file"; //Exception
                    break;
                }
                default:
                    cout << "\nNot a Valid Choice. \n"; //Exception
            }

        }
    };



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





