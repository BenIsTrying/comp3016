#include <iostream>
#include <fstream>
#include <string>
#include<windows.h>
#include <conio.h>

using namespace std;

void map(string mapname);
void gameLoop();
void map();

int mapLength = 0;
string board[100][100];
int startingX = 0;
int startingY = 0;
string oldSpace = " ";
bool active = true;

int main() {

    cout << "This is a circuit game, you must move your icon (@) across the map using W A S D. \n"
        << "You must connect the I (input/start) to the O (output/end) by changing the empty spaces (shown as dashes -) to 'c' (for cable)\n"
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

    switch (choice) {
    case 1:
        mapLength = 6;
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
        system("cls");
        cout << "Invalid map number - Please enter a number listed\n\n";
        main();
    }
    gameLoop();
}

void map(string mapname) {

    cout << "Loading - " << mapname << "...\n" << endl;
    
    string myText;
    string temp;
    
    int x = 0;
    int y = 0;
    
    
    ifstream MyReadFile(mapname);

    for (int i =0; i < 13; i++){ //13 as it is currently the longest map in the y axis
       
        int num = 0;

        getline(MyReadFile, myText);
        //cout <<  myText;

        temp = myText;
        //cout << "\n" << temp[0] << temp.length() << "\n";

        while (num < temp.length()) {
            board[i][num] = temp[num];
            cout << board[i][num];
            num++;
        }
        cout << "\n";
    }  

    MyReadFile.close();


    
}

void map() {

    for (int i = 0; i < 13; i++) { //13 as it is currently the longest map in the y axis

        int num = 0;

        while (num < 40) {
            if (board[i][num] == "I") {
                startingX = num;
                startingY = i;
            }

            cout << board[i][num] << " ";
            num++;
        }
        cout << "\n";
    }
    
    
}

void gameLoop() {
    while (active != false) {

        system("cls");
        map();
        cout << "\ntime to play" << "\n\n";

        cout << "\n" << startingX << startingY;
        if (board[startingY][startingX] != "@") {
            oldSpace = board[startingY][startingX];
        }
        board[startingY][startingX] = "@";

        cout << "\n\n\n\nCurrent sqaur - " << oldSpace << "\n\n\n\n\n\n";

        char move = ' ';
        move = _getch();

        move = tolower(move);
        if (move == 'w' && board[startingY + 1][startingX] != "#") {
            board[startingY][startingX] = oldSpace;
            startingY++;
            board[startingY][startingX] = "@";
        }
        else if (move == 'a' && board[startingY][startingX - 1] != "#") {
            board[startingY][startingX] = oldSpace;
            startingX--;
            board[startingY][startingX] = "@";
        }
        else if (move == 's' && board[startingY - 1][startingX] != "#") {
            board[startingY][startingX] = oldSpace;
            startingY--;
            board[startingY][startingX] = "@";
        }
        else if (move == 'd' && board[startingY][startingX + 1] != "#") {
            board[startingY][startingX] = oldSpace;
            startingX++;
            board[startingY][startingX] = "@";
        }

    }

}