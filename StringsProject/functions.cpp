#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;


bool Menu() {
    int option;
    string welcome = R"(    _     _     _     _              _                  
    | |   (_)   | |   | |            | |                 
    | |__  _  __| | __| | ___ _ __   | |_ ___  __ _ _ __ 
    | '_ \| |/ _` |/ _` |/ _ \ '_ \  | __/ _ \/ _` | '__|
    | | | | | (_| | (_| |  __/ | | | | ||  __/ (_| | |   
    |_| |_|_|\__,_|\__,_|\___|_| |_|  \__\___|\__,_|_|   )";

    cout << welcome;
    cout << "------" << endl;
    cout << "1.   Start playing" << endl;
    cout << "2.   Show results" << endl;
    cout << "3.   Continue playing" << endl;
    cout << "4.   Stop playing" << endl;
    cout << "------" << endl;
    cin >> option;
    switch (option)
    {
    case 1:

        return true;
        break;
    case 2:

        return true;
        break;
    case 3:
        return true;
        break;
    }
    return false;
}