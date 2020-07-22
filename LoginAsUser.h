//
// Created by Tutu on 21/07/2020.
//

#ifndef PROJECT2_LOGINASUSER_H
#define PROJECT2_LOGINASUSER_H

#include <iostream>
#include <fstream>

using namespace std;

class LoginAsUser {
public: void loginAsUser(){

        ///--------------- MENIU -----------

        int choice;
        bool gameOn = true;
        while(gameOn!=false)
        {
            cout<<"\n";
            cout << "  [1] - Buy a product: \n ";
            cout << " [2] - !Complains!: \n ";
            cout << " [3] - Display products: \n" ;
            cout << "  [4] - Go previously: \n" ;
            cout << "\n Enter your choice and press enter: ";
            cin>>choice;
            cin.ignore(10, '\n');
            switch (choice)
            {
                case 1:
                {   string searchProduct;
                    string line;

                    ifstream fin;
                    fin.open("produse.txt");    //open produse
                    ofstream temp;
                    temp.open("temp.txt");      //Create temporary file
                    cout<<"Default: \t Enter * Portocale * to see the program running \n";
                    cout<<" Which product you want to buy? ";
                    cin>>searchProduct;         //Select product
                    while (getline(fin,line))
                    {
                        if (line.find(searchProduct) != std::string::npos)  //find the line
                        {
                            int c=line[9]-'0';          //Go to position after "Quantity"
                            c--;                           //Decrenebt Quantity
                            line[9]=c+'0';
                        }
                        temp<<line<<endl;
                        remove("produse.txt");              //delete folder produse
                        rename("temp.txt","produse.txt");   //rename folder to temp -> produse
                    }
                    temp.close();
                    fin.close();            //close files
                    remove("produse.txt");
                    rename("temp.txt","produse.txt");
                    break;
                }
                case 2:
                {
                    ofstream fin;
                    fin.open("complains.txt");
                    cout<<"\n Enter your complain here: \n";       ///Ennter text
                    char data[100];
                    cin.getline(data, 100);
                    fin<<data<<endl;
                    cout<<"\n Your complain is written,you will receive an answer in a short time \n";
                                //Friendly message
                    fin.close();
                    break;
                }
                case 4:
                {
                    gameOn=false;
                    break;          //go back
                }
                case 3:
                {string line;
                    ifstream myfile ("produse.txt");
                    if (myfile.is_open())
                    {
                        while (! myfile.eof() )
                        {
                            getline (myfile,line);      //Display products
                            cout << line << endl;
                        }
                        myfile.close();
                    }
                    else cout << "Unable to open file"; //Exception
                    break;

                }
            }
        }
    }

    };


#endif //PROJECT2_LOGINASUSER_H
