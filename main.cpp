#include <iostream>
#include<fstream>
#include "Admin.h"

/// -----------------------    PROGRAM SITE ONLINE -------------------------

///Admin: admin
///parola: parola

using namespace std;

int main() {
    int choice;
    bool gameOn = true;
    while (gameOn != false) {
        cout << "-----------   Welcome to WarShop   ------------------\n\n";
        cout << " 1 - Admin\n";
        cout << " 2 - User\n";
        cout << " 3 - Exit.\n";
        cout << " Enter your choice and press enter: ";

        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Go to the admin phase\n";      //For Admin

                Admin admin;
                admin.adminPhase(3);
                break;
            }
            case 2:
                cout << "Go to the user phase\n";
                Meniu meniu;                                //For User
                meniu.loginUser();
                break;
            case 3:
                cout << "-- End of Program. --\n";
                gameOn = false;
                break;
            default:
                cout << "Not a Valid Choice. \n";
                cout << "Choose again.\n";
                cout << " Enter your choice and press enter: ";
                cin >> choice;
                break;
        }

    }

    std::cout << '\n';
    std::cin.get();
    return 0;
}

