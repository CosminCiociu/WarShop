//
// Created by Tutu on 22/07/2020.
//


#include<fstream>
#include <iostream>
using namespace std;
                          //This is a function that gets the name of the file and the line that you want to delete
class RemoveLine {

public:
    int removeLine(char *sourcefile, string name) {

        string line;
        ifstream myfile;
        myfile.open(sourcefile);
        ofstream temp;
        temp.open("temp.txt");
        int curLine;
        while (getline(myfile, line)) {
            curLine++;
            if (line.find(name, 0) == string::npos) {           //Finds the line and ignore writing it in the temp file
                cout << "found: " << name << " line: " << curLine << endl;
                temp << line << endl;
            }
        }
        cout << "The record with the name " << name << " has been deleted if it exsisted" << endl;
        myfile.close();
        temp.close();
        remove(sourcefile);                         //remove and replace the temp file with your file
        rename("temp.txt", sourcefile);
        return 0;

    }
};
