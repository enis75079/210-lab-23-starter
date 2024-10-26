/*

lab23: Goat Manager 3001
COMSC-210
Naveen Islam
IDE: vscode

*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again = true;
    list<Goat> goats;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    while (again == true) {
        int userNum = main_menu();
        if (userNum == 1) {
            add_goat(goats, names, colors);
        } else if (userNum == 2) {
            delete_goat(goats);
        } else if (userNum == 3) {
            display_trip(goats);
        } else if (userNum == 4) {
            again = false;
        } else {
            cout << "unexpected value. program will reset." << endl;
            again = false;
        }
    }

    return 0;
}

// main menu function. outputs menu and obtains users selection dependent on an int value input
int main_menu() {
    int userNum = 0;
    while(userNum != 4) {
        cout << "*** GOAT MANAGER 3001 ***" << endl;
        cout << "[1] Add a goat" << endl;
        cout << "[2] Delete a goat" << endl;
        cout << "[3] List goats" << endl;
        cout << "[4] Quit" << endl;
        cout << "Choice --> ";
        cin >> userNum;
    }
    return userNum;  
}

void add_goat(list<Goat> &goats, string goatNames[], string goatColors[]) {
    int nameNum = rand() % SZ_NAMES;
    string goatName = goatNames[nameNum];

    int colorNum = rand() % SZ_COLORS;
    string goatColor = goatColors[colorNum];

    int age = rand() % MAX_AGE;
    Goat newGoat(goatName, age, goatColor);
    goats.push_back(newGoat);
}

int select_goat(list<Goat> &goats) {
    int i = 0;    
    int userNum = 0;
    for (const Goat &x : goats) {
        cout << "[" << i++ << "] " << x << endl;
    }
    cin >> userNum;
    return userNum;
}

void delete_goat(list<Goat> &goats) {
    if (goats.empty()) {
        return;
    }
}

void display_trip(list<Goat> goats) {
    for (Goat &goat : goats) {
        cout << goat.get_name() << " ";
    }
    for (Goat &goat : goats) {
        cout << "(" << goat.get_age() << ", ";
    }
    for (Goat &goat : goats) {
        cout << goat.get_color()<< ")" << endl;
    }
}