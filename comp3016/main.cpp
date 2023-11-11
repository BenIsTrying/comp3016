#include <iostream>
#include <fstream>
#include <string>
#include<windows.h>
#include <conio.h>

using namespace std;
void map1();
void map(string mapname);
void gameLoop();
int mapLength = 0;



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
        map1();
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
void map1() {

    cout << "map 1" << endl;
    string board[6][5] = {
    { " ", " ", "#", "#", "#" },
    { " ", " ", "#", "O", "#" },
    { " ", " ", "#", "-", "#" },
    { "#", "#", "#", "-", "#" },
    { "#", "I", "-", "-", "#" },
    { "#", "#", "#", "#", "#" } 
    };


    int x = 0;
    int y = 0;

    

    for (int j = 0; j < 30; j++) {

        if (x >= 5) {
            cout << "\n";
            x = 0;
            y++;
        }
        else if (x >= 5 && y >= 6) {
            break;
        }
        cout << board[y][x] << " ";
        x++;
    }

    //


    

}
void map(string mapname) {

    cout << "Loading - " << mapname << "...\n" << endl;
    
    string myText;
    string temp;
    int num = 0;
    
    
    ifstream MyReadFile(mapname);

    for (int i =0; i < mapLength; i++){

        getline(MyReadFile, myText);

        cout <<  myText;
        cout << "\n";
    }  

    MyReadFile.close();
}

void gameLoop() {

    cout << "time to play";

}