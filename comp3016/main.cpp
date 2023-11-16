#include <iostream>
#include <fstream>
#include <string>
#include<windows.h>
#include <conio.h>
#include <thread>


using namespace std;

void map(string mapname);
void gameLoop();
void map();
void checkWin();
void leaderBoard();



bool active = true;
int cableUsed = 0;

class boardClass {

public://this is where all data with the board is stored/from.
string board[100][100];
int mapLength = 0;
int startingX = 0;
int startingY = 0;
string oldSpace = " ";

};
boardClass myObj;

int main() {

    cout << "This is a circuit/mase game, you must move your icon (@) across the map using 'W' 'A' 'S' 'D'. And 'J' for changing the empty spaces to a cable\n"
        << "You must connect the I (input/start) to the O (output/end) by changing the empty spaces (shown as dashes -) to 'c' (for cable)\n"
        << "\nTo Win you must be on the 'O' sqaur\n"
        << "\n\nKey:\n"
        << "@ = Player icon denoting the current position\n"
        << "- = Empty space waiting to be changed to cable\n"
        << "c = Cable use this to connect the begining and end of the circuit\n"
        << "I = input where the power comes from\n"
        << "O = output where the power needs to go\n\n" << endl;

        //Sleep(10000);

    int choice = 0;
    cout << "Please Choose a map: \n1\t2\t3\t4\t5\n\n";
    cin >> choice;
    try {
        switch (choice) {
        case 1:
            map("map01.txt");
            break;
        case 2:
            map("map02.txt");
            break;
        case 3:
            map("map03.txt");
            break;
        case 4:
            map("map04.txt");
            break;
        case 5:
            map("map05.txt");
            break;

        default:
            throw (choice);
        }
        map();
        gameLoop();
    }
    catch (int choice) {
        system("cls");
        cout << "Invalid map number - Please enter a number listed\n\n";
        main();

    }

}

void map(string mapname) {

    cout << "Loading - " << mapname << "...\n" << endl;
    
    string myText;
    string temp;
    
    int x = 0;
    int y = 0;
    
    try {
        ifstream MyReadFile(mapname);

        for (int i = 0; i < 13; i++) { //13 as it is currently the longest map in the y axis

            int num = 0;

            getline(MyReadFile, myText);
            //cout <<  myText;

            temp = myText;
            //cout << "\n" << temp[0] << temp.length() << "\n";

            while (num < temp.length()) {
                myObj.board[i][num] = temp[num];
                cout << myObj.board[i][num];
                num++;
            }
            cout << "\n";
        }

        MyReadFile.close();

    }
    catch (...) {
        cout << "error";
        map(mapname);
    }
}

void map() {

    for (int i = 0; i < 13; i++) { //13 as it is currently the longest map in the y axis

        int num = 0;

        while (num < 40) {
            if (myObj.board[i][num] == "I") {
                myObj.startingX = num;
                myObj.startingY = i;
            }

            cout << myObj.board[i][num] << " ";
            num++;
        }
        cout << "\n";
    }
    
    
}
void checkWin() {

    int checkY = myObj.startingY;
    int checkX = myObj.startingX;
    int won = 0;
    string oldPos = "nothing";
    
    
    while (won != 50) {
        if (myObj.board[checkY][checkX + 1] == "I" || myObj.board[checkY][checkX - 1] == "I" || myObj.board[checkY + 1][checkX] == "I" || myObj.board[checkY - 1][checkX] == "I") {
            active = true;
            won = true;
            leaderBoard();
        }
        else if (myObj.board[checkY][checkX + 1] == "c" && oldPos != "right") {
            checkX++;
            cout << "x++";
            oldPos = "right";
        }
        else if (myObj.board[checkY][checkX - 1] == "c" && oldPos != "left") {
            checkX--;
            cout << "x--";
            oldPos = "left";
        }
        else if (myObj.board[checkY - 1][checkX] == "c" && oldPos != "up") {
            checkY--;
            cout << "y--";
            oldPos = "up";
        }
        else if (myObj.board[checkY + 1][checkX] == "c" && oldPos != "down") {
            checkY++;
            cout << "y++";
            oldPos = "down";
        }
        won++;
    }
    

}
void leaderBoard() {
    system("cls");

    string input;

    cout << "You win\n\n"
        << "Amount of cable used: " << cableUsed;
    
    
    ofstream myfile;
    myfile.open("leaderboard.txt", ofstream::app);
    string name;
    cout << "\n\nplease give your name: ";
    cin >> name;
    myfile << "\n" << name << " : " << cableUsed;
    myfile.close();


        
    string myText;

    ifstream MyReadFile("leaderboard.txt");

    for (int i = 0; i < 10; i++) { //show the 10 on the leaderboard

        getline(MyReadFile, myText);
        cout <<myText << "\n";
    }

    MyReadFile.close();
    
    
    
    cout << "\n\nPlay again? (yes/no)\t";
    cin >> input;
    if (input != "yes") {
        cout << "goodbye\n\n\n\n";
        exit(0);
    }
    else if (input == "yes") {
        main();
    }

}

void gameLoop() {

    int currentX = myObj.startingX;
    int currentY = myObj.startingY;
    cableUsed = 0;
    
    myObj.oldSpace = myObj.board[currentY][currentX];

    while (active != false) {

        system("cls");
        map();
        cout << "\ntime to play" << "\n\n";

        cout << "\nPos: " << currentX << " " << currentY;
        if (myObj.board[currentY][currentX] != "@") {
            myObj.oldSpace = myObj.board[currentY][currentX];
        }
        myObj.board[currentY][currentX] = "@";

        cout << "\n\n\n\nCurrent sqaur -> " << myObj.oldSpace << "\n\n\n\n\n\n";

        char move;
        move = _getch();

        move = tolower(move);
        if ((move == 'j') && (myObj.oldSpace != "I") && (myObj.oldSpace != "O") && (myObj.oldSpace != "#")) {
            myObj.board[currentY][currentX] = myObj.oldSpace;
            myObj.oldSpace = "c";
            myObj.board[currentY][currentX] = "@";
            cableUsed++;
        }
        else if (move == 'w' && myObj.board[currentY - 1][currentX] != "#") {
            myObj.board[currentY][currentX] = myObj.oldSpace;
            currentY--; 
            myObj.oldSpace = myObj.board[currentY][currentX];
            myObj.board[currentY][currentX] = "@";
        }
        else if (move == 'a' && myObj.board[currentY][currentX - 1] != "#") {
            myObj.board[currentY][currentX] = myObj.oldSpace;
            currentX--;
            myObj.oldSpace = myObj.board[currentY][currentX];
            myObj.board[currentY][currentX] = "@";
        }
        else if (move == 's' && myObj.board[currentY + 1][currentX] != "#") {
            myObj.board[currentY][currentX] = myObj.oldSpace;
            currentY++;
            myObj.oldSpace = myObj.board[currentY][currentX];
            myObj.board[currentY][currentX] = "@";
        }
        else if (move == 'd' && myObj.board[currentY][currentX + 1] != "#") {
            myObj.board[currentY][currentX] = myObj.oldSpace;
            currentX++;
            myObj.oldSpace = myObj.board[currentY][currentX];
            myObj.board[currentY][currentX] = "@";
        }
        if (myObj.oldSpace == "O"){
            checkWin();
        }
    }

}