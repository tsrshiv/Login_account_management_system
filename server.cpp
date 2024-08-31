#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

class login_system {
    void waiting() {
        for (int i = 0; i < 10; i++) {
            Sleep(200);
            cout << "..";
        }
    }

private:
    string fname, password, name, pass, date, month, year, email, number;

public:
    void homepage();
    void menu();
    void details();
    void modify();
    void change_password();
    void delete_account();
    void exit_system();
};

void login_system::homepage() {
    system("cls");
    cout << "\n\t     ____________________________________________________________________________________________" << endl;
    cout << "\t    |                                                  \t\t\t\t\t        |";
    cout << "\n\t    |\t\t\t              CREATE, LOGIN & AUTHENTICATION                            |" << endl;
    cout << "\t    |                                                  \t\t\t\t\t        |";
    cout << "\n\t    |___________________________________________________________________________________________|" << endl << endl << endl;
    cout << "\n\t\t\t\t\t ______________________________________\n";
    cout << "\t\t\t\t\t|                                      |";
    cout << "\n\t\t\t\t\t|                HOMEPAGE              |";
    cout << "\n\t\t\t\t\t|______________________________________|";
    cout << "\n\t\t\t\t\t|                                      |";
    cout << "\n\t\t\t\t\t|Kindly select an option below:        |";
    cout << "\n\t\t\t\t\t|1. Create Account                     |";
    cout << "\n\t\t\t\t\t|2. Login                              |";
    cout << "\n\t\t\t\t\t|3. List of All Accounts               |";
    cout << "\n\t\t\t\t\t|4. Search Account By Name             |";
    cout << "\n\t\t\t\t\t|5. Exit                               |" << endl;
    cout << "\t\t\t\t\t|______________________________________|" << endl << endl;
    char x;
    cout << "\t\t\t\t\t-> ";
    cin >> x;
    switch (x) {
        case '1': {
            system("cls");
            cout << "\n\t\t\t\t ________________________________________\n";
            cout << "\t\t\t\t|                                        |";
            cout << "\n\t\t\t\t|               Create Account           |" << endl;
            cout << "\t\t\t\t|________________________________________|" << endl << endl;
            cout << "\t\t\t\t\tEnter User_Name: " << endl << "\t\t\t\t\t";
            cin >> fname;
            cout << endl << "\t\t\t\t\tEnter your Date of Birth-" << endl << "\t\t\t\t\tDay :  ";
            cin >> date;
            cout << "\t\t\t\t\tMonth : ";
            cin >> month;
            cout << "\t\t\t\t\tYear :  ";
            cin >> year;
            cout << endl << "\t\t\t\t\tEnter your Contact Details: " << endl << "\t\t\t\t\tPhone Number : ";
            cin >> number;
            cout << endl << "\t\t\t\t\tEnter Email Address: " << endl << "\t\t\t\t\t";
            cin >> email;
            cout << endl << "\t\t\t\t\tEnter password: " << endl << "\t\t\t\t\t";
            char ch;
            password = "";
            ch = _getch();
            while (ch != 13) {
                password.push_back(ch);
                cout << '*';
                ch = _getch();
            }
            fstream file;
            file.open("files", ios::app | ios::out);
            if (!file) {
                cout << "\t\t\t\t\tRegistration failed" << endl << "Try again later" << endl;
            } else {
                file << fname << " " << password << " " << number << " " << email << " " << date << " " << month << " " << year << "\n";
                cout << "\n\n\t\t\t\t\tAccount Created Successfully." << endl << "\n\t\t\t\t\t";
                file.close();
            }
            system("pause");
            homepage();
            break;
        }
        case '2': {
            system("cls");
            cout << "\n\t\t\t\t\t ______________________________________\n";
            cout << "\t\t\t\t\t|                                      |";
            cout << "\n\t\t\t\t\t|               LOGIN PAGE             |";
            cout << "\n\t\t\t\t\t|______________________________________|" << endl << endl;
            fstream file;
            file.open("files", ios::in);
            if (!file) {
                cout << "\t\t\t\t\t\tError! File not found" << endl;
                cout << "\n\t\t\t\t\t\t";
                system("pause");
                homepage();
            } else {
                char ch;
                name = "";
                pass = "";
                int flag = 0;
                cout << "\t\t\t\t\tEnter User_Name : ";
                cin >> name;
                cout << "\t\t\t\t\tEnter Password : ";
                ch = _getch();
                while (ch != 13) {
                    pass.push_back(ch);
                    cout << '*';
                    ch = _getch();
                }
                file >> fname >> password >> number >> email >> date >> month >> year;
                while (!file.eof()) {
                    if (name == fname && pass == password) {
                        flag = 1;
                        break;
                    }
                    file >> fname >> password >> number >> email >> date >> month >> year;
                }
                cout << "\n\t\t\t\t\tVerifying User Data" << endl << "\t\t\t\t\t";
                waiting();
                if (flag == 1) {
                    cout << endl << endl << "\t\t\t\t\tLogin Successful";
                    file.close();
                    Sleep(789);
                    menu();
                } else {
                    cout << endl << endl << "\t\t\t\t\tNo account exists with given credentials." << endl;
                    cout << "\n\t\t\t\t\t";
                    system("pause");
                    file.close();
                    homepage();
                }
            }
            break;
        }
        case '3': {
            int x = 1;
            system("cls");
            cout << "\n\t\t\t\t ______________________________________________" << endl;
            cout << "\t\t\t\t|                                              |";
            cout << "\n\t\t\t\t|             LIST OF ALL ACCOUNTS             |" << endl;
            cout << "\t\t\t\t|______________________________________________|" << endl << endl;
            fstream file;
            file.open("files", ios::in);
            if (!file) {
                cout << "\t\t\t\t\t Error! File not found" << endl;
            } else {
                file >> fname >> password >> number >> email >> date >> month >> year;
                while (!file.eof()) {
                    Sleep(66);
                    cout << "\t\t\t\t\t\t ______________" << endl;
                    cout << "\t\t\t\t\t\t|              |" << endl;
                    cout << "\t\t\t\t\t\t|   ACCOUNT " << x++ << "  |" << endl;
                    cout << "\t\t\t\t\t\t|______________|" << endl;
                    cout << endl << "\t\t\t\t\t 1. User_name = " << fname << endl;
                    cout << "\t\t\t\t\t 2. Contact = " << number << endl;
                    cout << "\t\t\t\t\t 3. Email = " << email << endl;
                    cout << "\t\t\t\t\t 4. Date of Birth = " << date << "/" << month << "/" << year << endl;
                    cout << "\t\t\t\t\t ------------------------------------" << endl << endl;
                    file >> fname >> password >> number >> email >> date >> month >> year;
                }
                cout << "\t\t\t\t\t Reached at end of the File" << endl;
            }
            file.close();
            cout << "\t\t\t\t\t ";
            system("pause");
            homepage();
            break;
        }
        case '4': {
            system("cls");
            cout << "\n\t\t\t\t ___________________________________________\n";
            cout << "\t\t\t\t|                                           |";
            cout << "\n\t\t\t\t|                SEARCH ACCOUNT             |" << endl;
            cout << "\t\t\t\t|___________________________________________|" << endl << endl;
            cout << "\t\t\t\t\tEnter User_Name: ";
            cin >> name;
            int found = 0;
            fstream file;
            file.open("files", ios::in);
            file >> fname >> password >> number >> email >> date >> month >> year;
            while (!file.eof()) {
                if (name == fname) {
                    Sleep(66);
                    cout << endl << "\t\t\t\t\t1. User_Name = " << fname << endl;
                    cout << "\t\t\t\t\t2. Email = " << email << endl;
                    cout << "\t\t\t\t\t3. Contact Details = " << number << endl;
                    cout << "\t\t\t\t\t4. Date of Birth = " << date << "/" << month << "/" << year << endl;
                    found = 1;
                    break;
                }
                file >> fname >> password >> number >> email >> date >> month >> year;
            }
            if (found == 0) {
                cout << "\t\t\t\t\tSorry! No Account Exist with this User_Name." << endl;
            }
            file.close();
            cout << "\n\t\t\t\t\t";
            system("pause");
            homepage();
            break;
        }
        case '5': {
            exit_system();
            break;
        }
        default: {
            homepage();
            break;
        }
    }
}

void login_system::menu() {
    system("cls");
    cout << "\n\t\t\t\t\t ______________________________________\n";
    cout << "\t\t\t\t\t|                                      |";
    cout << "\n\t\t\t\t\t|               MAIN MENU              |" << endl;
    cout << "\t\t\t\t\t|______________________________________|" << endl;
    cout << "\n\t\t\t\t\t|                                      |";
    cout << "\n\t\t\t\t\t|   1. Account Details                 |";
    cout << "\n\t\t\t\t\t|   2. Modify Account                  |";
    cout << "\n\t\t\t\t\t|   3. Change Password                 |";
    cout << "\n\t\t\t\t\t|   4. Delete Account                  |";
    cout << "\n\t\t\t\t\t|   5. Exit                            |";
    cout << "\n\t\t\t\t\t|______________________________________|" << endl;
    char x;
    cout << "\n\t\t\t\t\t-> ";
    cin >> x;
    switch (x) {
        case '1': {
            details();
            break;
        }
        case '2': {
            modify();
            break;
        }
        case '3': {
            change_password();
            break;
        }
        case '4': {
            delete_account();
            break;
        }
        case '5': {
            exit_system();
            break;
        }
        default: {
            menu();
            break;
        }
    }
}

void login_system::details() {
    system("cls");
    fstream file;
    file.open("files", ios::in);
    if (!file) {
        cout << "\t\t\t\t\t Error! File not found" << endl;
        cout << "\n\t\t\t\t\t ";
        system("pause");
        menu();
    } else {
        cout << "\n\t\t\t\t\t ______________________________________\n";
        cout << "\t\t\t\t\t|                                      |";
        cout << "\n\t\t\t\t\t|           ACCOUNT DETAILS            |";
        cout << "\n\t\t\t\t\t|______________________________________|" << endl << endl;
        file >> fname >> password >> number >> email >> date >> month >> year;
        while (!file.eof()) {
            if (name == fname && pass == password) {
                cout << "\t\t\t\t\t_________________________________________" << endl;
                cout << "\t\t\t\t\t                                           " << endl;
                cout << "\t\t\t\t\t      1. User_Name = " << fname << endl;
                cout << "\t\t\t\t\t      2. Contact Details = " << number << endl;
                cout << "\t\t\t\t\t      3. Email = " << email << endl;
                cout << "\t\t\t\t\t      4. Date of Birth = " << date << "/" << month << "/" << year << endl;
                cout << "\t\t\t\t\t_________________________________________" << endl << endl;
            }
            file >> fname >> password >> number >> email >> date >> month >> year;
        }
        file.close();
    }
    cout << "\t\t\t\t\t ";
    system("pause");
    menu();
}

void login_system::modify() {
    string old, temp, temp1, temp2, temp3, temp4, temp5, temp6;
    system("cls");
    cout << "\n\t\t\t\t\t ______________________________________\n";
    cout << "\t\t\t\t\t|                                      |";
    cout << "\n\t\t\t\t\t|             MODIFY ACCOUNT           |";
    cout << "\n\t\t\t\t\t|______________________________________|" << endl << endl;
    fstream file;
    cout << "\t\t\t\t\tEnter Current User_Name: ";
    cin >> old;
    cout << "\t\t\t\t\tEnter New User_Name: ";
    cin >> fname;
    cout << "\t\t\t\t\tEnter New Contact Number: ";
    cin >> number;
    cout << "\t\t\t\t\tEnter New Email: ";
    cin >> email;
    cout << "\t\t\t\t\tEnter New Date of Birth" << endl << "\t\t\t\t\tDay : ";
    cin >> date;
    cout << "\t\t\t\t\tMonth : ";
    cin >> month;
    cout << "\t\t\t\t\tYear : ";
    cin >> year;
    fstream file1;
    file.open("files", ios::in);
    file1.open("temp.txt", ios::app | ios::out);
    file >> temp >> password >> temp1 >> temp2 >> temp3 >> temp4 >> temp5;
    while (!file.eof()) {
        if (old == temp) {
            file1 << fname << " " << password << " " << number << " " << email << " " << date << " " << month << " " << year << "\n";
        } else {
            file1 << temp << " " << password << " " << temp1 << " " << temp2 << " " << temp3 << " " << temp4 << " " << temp5 << "\n";
        }
        file >> temp >> password >> temp1 >> temp2 >> temp3 >> temp4 >> temp5;
    }
    file.close();
    file1.close();
    remove("files");
    rename("temp.txt", "files");
    cout << "\n\t\t\t\t\tSuccessfully Modified" << endl;
    cout << "\n\t\t\t\t\t ";
    system("pause");
    menu();
}

void login_system::change_password() {
    string temp, temp1, temp2, temp3, temp4, temp5, temp6;
    system("cls");
    cout << "\n\t\t\t\t\t ______________________________________\n";
    cout << "\t\t\t\t\t|                                      |";
    cout << "\n\t\t\t\t\t|          CHANGE PASSWORD             |";
    cout << "\n\t\t\t\t\t|______________________________________|" << endl << endl;
    fstream file, file1;
    file.open("files", ios::in);
    file1.open("temp.txt", ios::app | ios::out);
    cout << "\t\t\t\t\tEnter User_Name: ";
    cin >> name;
    cout << "\t\t\t\t\tEnter New Password: ";
    char ch;
    password = "";
    ch = _getch();
    while (ch != 13) {
        password.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    file >> temp >> pass >> temp1 >> temp2 >> temp3 >> temp4 >> temp5;
    while (!file.eof()) {
        if (name == temp) {
            file1 << temp << " " << password << " " << temp1 << " " << temp2 << " " << temp3 << " " << temp4 << " " << temp5 << "\n";
        } else {
            file1 << temp << " " << pass << " " << temp1 << " " << temp2 << " " << temp3 << " " << temp4 << " " << temp5 << "\n";
        }
        file >> temp >> pass >> temp1 >> temp2 >> temp3 >> temp4 >> temp5;
    }
    file.close();
    file1.close();
    remove("files");
    rename("temp.txt", "files");
    cout << "\n\t\t\t\t\tSuccessfully Changed" << endl;
    cout << "\n\t\t\t\t\t ";
    system("pause");
    menu();
}

void login_system::delete_account() {
    string temp, temp1, temp2, temp3, temp4, temp5, temp6;
    system("cls");
    cout << "\n\t\t\t\t\t ______________________________________\n";
    cout << "\t\t\t\t\t|                                      |";
    cout << "\n\t\t\t\t\t|             DELETE ACCOUNT           |";
    cout << "\n\t\t\t\t\t|______________________________________|" << endl << endl;
    fstream file, file1;
    file.open("files", ios::in);
    file1.open("temp.txt", ios::app | ios::out);
    cout << "\t\t\t\t\tEnter User_Name: ";
    cin >> name;
    file >> temp >> password >> temp1 >> temp2 >> temp3 >> temp4 >> temp5;
    while (!file.eof()) {
        if (name != temp) {
            file1 << temp << " " << password << " " << temp1 << " " << temp2 << " " << temp3 << " " << temp4 << " " << temp5 << "\n";
        }
        file >> temp >> password >> temp1 >> temp2 >> temp3 >> temp4 >> temp5;
    }
    file.close();
    file1.close();
    remove("files");
    rename("temp.txt", "files");
    cout << "\n\t\t\t\t\tSuccessfully Deleted" << endl;
    cout << "\n\t\t\t\t\t ";
    system("pause");
    homepage();
}

void login_system::exit_system() {
    system("cls");
    cout << "\n\n\t\t\t\t\tYou successfully exited the system." << endl;
    exit(0);
}

int main() {
    system("cls");
    login_system log;
    log.homepage();
}
