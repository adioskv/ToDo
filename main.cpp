#include "tasks.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main()
{
    cout << "-----------------TODO v1.0-----------------" << endl;
    char loop = 'y';

    cout << "Enter path to your \' myTODO \' folder\n(You can type D to use default folder)\nPATH: ";
    string path;
    getline(cin, path);

    Tasks* t = nullptr;
    if (path == "D") 
    {
        t = new Tasks;
    }
    else 
    {
        while (!(filesystem::exists(path + "\\myTODO")))
        {
            cout << "PATH : \"" << path << "\" does not exist.\n"
                << "Do you want to enter path again?(y/n): ";
            char ans;
            while (!(cin >> ans) || tolower(ans) != 'y' && tolower(ans) != 'n' || cin.peek() != '\n')
            {
                cin.clear();
                while (cin.get() != '\n');
                cout << "Wrong input! try again: ";
            }
            if (tolower(ans) == 'n')
            {
                std::cout << "exiting...\n";
                std::exit(EXIT_FAILURE);
            }
            else
            {
                string path;
                cout << "Enter new path to folder with \"myTODO\" folder: ";
                cin.ignore();
                getline(cin, path);
            }
        }

        t = new Tasks(path);
    }
    system("cls");
    while (loop == 'y')
    {
        t->show_all();
        cout << "1 - show {x} folder; 2 - change path; 3 - exit; \nEnter your choice: ";
        int ch;
        while (!(cin >> ch) || cin.peek() != '\n' || ch > 3 || ch < 1)
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "wrong input.\ntry again: ";
        }
        switch (ch)
        {
        case 1:
            int choice;
            cout << "Enter group number: ";
            while (!(cin >> choice) || cin.peek() != '\n' || ch < 0 || ch > t->get_size())
            {
                cin.clear();
                while (cin.get() != '\n');
                cout << "wrong input.";
            }
            system("cls");
            t->show_folder(choice);
            cout << "1 - show file {x}; 2 - go back;\nEnter your choice: ";
            int c;
            while (!(cin >> c) || cin.peek() != '\n' || c > 2 || c < 1)
            {
                cin.clear();
                while (cin.get() != '\n');
                cout << "wrong input.\ntry again: ";
            }
            if (c == 1)
            {
                cout << "Enter number of file: ";
                int num;
                while (!(cin >> num) || cin.peek() != '\n' || c > 2 || c < 1)
                {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "wrong input.\ntry again: ";
                }
                system("cls");
                t->show_file(choice, num);
                cin.ignore();
                cin.get();
                system("cls");
            }
            else 
            {
                break;
            }
            break;
        case 2:
            cout << "Enter new path:";
            cin.ignore();
            getline(cin, path);
            while (!(filesystem::exists(path + "\\myTODO")))
            {
                cout << "PATH : \"" << path << "\" does not exist.\n"
                    << "Do you want to enter path again?(y/n): ";
                char ans;
                while (!(cin >> ans) || tolower(ans) != 'y' && tolower(ans) != 'n' || cin.peek() != '\n')
                {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "Wrong input! try again: ";
                }

                if (tolower(ans) == 'n')
                {
                    std::cout << "exiting...\n";
                    std::exit(EXIT_FAILURE);
                }
                else
                {
                    string path;
                    cout << "Enter new path to folder with \"myTODO\" folder: ";
                    cin.ignore();
                    getline(cin, path);
                }
            }
            t->setPath(path);
            system("cls");
            break;
        case 3:
            system("cls");
            cout << "\nBye!\n";
            std::exit(EXIT_SUCCESS);
            break;
        }
    }
    return 0;
}