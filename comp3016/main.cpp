#include <iostream>
#include <fstream>
#include <string>
#include<windows.h>
#include <conio.h>

using namespace std;
void map1();
void map2();
void map3();
void map4();
void map5();


int main() {

    cout << "This is a circuit game, you must move your icon (@) across the map using W A S D. \n"
        << "You must connect the I (input/start) to the O (output/end) by changing the empty spaces (shown as dashes -) to 'c' (for cable)\n"
        << "\n\nKey:\n"
        << "@ = Player icon denoting the current position\n"
        << "- = Empty space waiting to be changed to cable\n"
        << "c = Cable use this to connect the begining and end of the circuit\n"
        << "I = input where the power comes from\n"
        << "O = output where the power needs to go\n\n" << endl;

        Sleep(10000);

    int choice = 0;
    cout << "Please Choose a map: \n1\t2\t3\t4\t5\n\n";
    cin >> choice;

    switch (choice) {
    case 1:
        map1();
        break;
    case 2:
        map2();
        break;
    case 3:
        map3();
        break;
    case 4:
        map4();
        break;
    case 5:
        map5();
        break;

    default:
        system("cls");
        cout << "Invalid map number - Please enter a number listed\n\n";
        main();
    }

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


    string myText;
    string temp;
    int num = 0;
    int x = 0;
    int y = 0;

    /*ifstream MyReadFile("map01.txt");

    for (int i =0; i < 6; i++){

        getline(MyReadFile, myText);
        
        board[0][num] = myText.at(0);
        board[1][num] = myText.at(1);
        board[2][num] = myText.at(2);
        board[3][num] = myText.at(3);
        board[4][num] = myText.at(4);
        num++;

        cout << "\n\t\t " << myText[0];
    }  */

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

    //MyReadFile.close();


    

}
void map2() {

    cout << "map 2";

}
void map3() {
    
    cout << "map 3";

}
void map4() {

    cout << "map 4";

}
void map5() {

    cout << "map 5";

}