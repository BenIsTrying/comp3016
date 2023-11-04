#include <iostream>
#include <fstream>
#include <string>


using namespace std;
void map1();
void map2();
void map3();
void map4();
void map5();


int main() {

    
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

    cout << "map 1";
    char board[5][6];
    string myText;

    ifstream MyReadFile("map01.txt");

    while (getline(MyReadFile, myText)) {
        
        cout << myText;
        cout << "o";
        string temp[5] = { myText};
        cout << temp[0];

    }

   
    MyReadFile.close();


    

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