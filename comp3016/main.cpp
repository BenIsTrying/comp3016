#include <iostream>
#include <fstream>
#include <string>
#include<windows.h>
#include <conio.h>

using namespace std;
//void map1();
void map(string mapname);
void gameLoop();
int mapLength = 0;
string board[100][100];


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

void gameLoop() {

    system("cls");
    
    cout << "\ntime to play" << "\n\n";

    for (int i = 0; i < 13; i++) { //13 as it is currently the longest map in the y axis

        int num = 0;

        while (num < 40) {
            cout << board[i][num] << " ";
            num++;
        }
        cout << "\n";
    }
    

    
    
    

}