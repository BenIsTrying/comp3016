#include <iostream>
#include <fstream>
#include <string>
#include<windows.h>
#include <conio.h>

using namespace std;

void map(string mapname);
void mapSolutions(string solution);
void gameLoop();
void map();
void checkWin();
void leaderBoard();

int mapLength = 0;
string board[100][100];
string solvedBoard[100][100];
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
        mapSolutions("map01_solved");
        map("map01.txt");
        break;
    case 2:
        mapSolutions("map02_solved");
        map("map02.txt");
        break;
    case 3:
        mapSolutions("map03_solved");
        map("map03.txt");
        break;
    case 4:
        mapSolutions("map04_solved");
        map("map04.txt");
        break;
    case 5:
        mapSolutions("map05_solved");
        map("map05.txt");
        break;

    default:
        system("cls");
        cout << "Invalid map number - Please enter a number listed\n\n";
        main();
    }
    map();
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

void mapSolutions(string solution) {

    string myText;
    string temp;

    int x = 0;
    int y = 0;

    ifstream MyReadFile(solution);

    for (int i = 0; i < 13; i++) { //13 as it is currently the longest map in the y axis

        int num = 0;

        getline(MyReadFile, myText);
        //cout <<  myText;

        temp = myText;
        //cout << "\n" << temp[0] << temp.length() << "\n";

        while (num < temp.length()) {
            solvedBoard[i][num] = temp[num];
            cout << solvedBoard[i][num];
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
void checkWin() {

    int checkY = startingY;
    int checkX = startingX;
    bool won = false;
    string oldPos = "nothing";
    
    
    while (won != true) {
        if (board[checkY][checkX + 1] == "I" || board[checkY][checkX - 1] == "I" || board[checkY + 1][checkX] == "I" || board[checkY - 1][checkX] == "I") {
            active = true;
            won = true;
            leaderBoard();
        }
        else if (board[checkY][checkX + 1] == "c" && oldPos != "right") {
            checkX++;
            cout << "x++";
            oldPos = "right";
        }
        else if (board[checkY][checkX - 1] == "c" && oldPos != "left") {
            checkX--;
            cout << "x--";
            oldPos = "left";
        }
        else if (board[checkY - 1][checkX] == "c" && oldPos != "up") {
            checkY--;
            cout << "y--";
            oldPos = "up";
        }
        else if (board[checkY + 1][checkX] == "c" && oldPos != "down") {
            checkY++;
            cout << "y++";
            oldPos = "down";
        }

    }
    

}
void leaderBoard() {
    system("cls");

    string input;

    cout << "You win\n\n"
        << "play again?\t";
    cin >> input;
    if (input == "yes") {
        main();
    }
    else {
        cout << "goodbye";
    }

}

void gameLoop() {

    int currentX = startingX;
    int currentY = startingY;
    
    oldSpace = board[currentY][currentX];

    while (active != false) {

        system("cls");
        map();
        cout << "\ntime to play" << "\n\n";

        cout << "\nPos: " << currentX << " " << currentY;
        if (board[currentY][currentX] != "@") {
            oldSpace = board[currentY][currentX];
        }
        board[currentY][currentX] = "@";

        cout << "\n\n\n\nCurrent sqaur -> " << oldSpace << "\n\n\n\n\n\n";

        char move;
        move = _getch();

        move = tolower(move);
        if ((move == 'j' && board[currentY][currentX] != "I") && (move == 'j' && board[currentY][currentX] != "O") && (move == 'j' && board[currentY][currentX] != "#")) {
            board[currentY][currentX] = oldSpace;
            oldSpace = "c";
            board[currentY][currentX] = "@";
        }
        else if (move == 'w' && board[currentY - 1][currentX] != "#") {
            board[currentY][currentX] = oldSpace;
            currentY--; 
            oldSpace = board[currentY][currentX];
            board[currentY][currentX] = "@";
        }
        else if (move == 'a' && board[currentY][currentX - 1] != "#") {
            board[currentY][currentX] = oldSpace;
            currentX--;
            oldSpace = board[currentY][currentX];
            board[currentY][currentX] = "@";
        }
        else if (move == 's' && board[currentY + 1][currentX] != "#") {
            board[currentY][currentX] = oldSpace;
            currentY++;
            oldSpace = board[currentY][currentX];
            board[currentY][currentX] = "@";
        }
        else if (move == 'd' && board[currentY][currentX + 1] != "#") {
            board[currentY][currentX] = oldSpace;
            currentX++;
            oldSpace = board[currentY][currentX];
            board[currentY][currentX] = "@";
        }
        if (oldSpace == "O"){
            checkWin();
        }
    }

}