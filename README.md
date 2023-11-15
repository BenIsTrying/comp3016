# Comp3016 CW1

This is a C++ command line game for comp 30016 CW1

## Visual Studio and Operating System version:

OS: Windows 11 Pro

IDE: visual Studio 2022

## How does it play?

This game is a basic maze/circuit puzzel game, the user must move across the board by manipulating their player icon **@** usign the **W** **A** **S** **D** keys.
The user starts on the **I** tile (input) and must connect this starting postion to the the **O** (output) by changing the enpty sqaurs to cables **C**.
Once the user has finished connecting these two points they must stand on the **O** for the board to be scanned and checked to see if they have won.
The users task is to get from **I** to **O** with the least amount of **C** cables used.

![comp3016 code terminal](https://github.com/BenIsTrying/comp3016/assets/91667148/8c348b57-0f82-40bb-8e79-5ea2072fe777)
 
## UML design diagram 

### Basic UML of board/gerneral play:
![comp3016 image uml01](https://github.com/BenIsTrying/comp3016/assets/91667148/3a811a22-7971-4c42-afda-6771a55e97e8)

### Leader board UML:

![comp3016 leader boarduml](https://github.com/BenIsTrying/comp3016/assets/91667148/f321c4b5-9fa8-4bb1-9eef-dd13fdc4dbd0)


## Exception handling and test cases

1. When begining the game the user is asked to select the map they wish to play, this is in a try catch as if the user does not give a real map number the system cannot run, so the code will catch the error and tell the user to select one the the listed numbers.
```
int choice = 0;
    cout << "Please Choose a map: \n1\t2\t3\t4\t5\n\n";
    cin >> choice;
    try {
        switch (choice) {
        case 1:
            //mapSolutions("map01_solved");
            map("map01.txt");
            break;
        case 2:
            //mapSolutions("map02_solved");
            map("map02.txt");
            break;
        case 3:
            //mapSolutions("map03_solved");
            map("map03.txt");
            break;
        case 4:
            //mapSolutions("map04_solved");
            map("map04.txt");
            break;
        case 5:
            //mapSolutions("map05_solved");
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
```

2. This code is getting and allocating the map to the array, it trys to allocate and if any errors occure then it trys reloading the function.

```
try {
        ifstream MyReadFile(mapname);

        for (int i = 0; i < 13; i++) { //13 as it is currently the longest map in the y axis

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
    catch (...) {
        cout << "error";
        map(mapname);
    }
```



## Further details that help us to understand how your prototype works. 

The way this project works is by reading exsternal text files that hold the data for the maps, this is then read and stored into an 2D array called board (this array size is 100 by 100) this is how the game is worked and used, the user controlls an icon **'@'** which starts by takin gthe postion of **I** on the board and manitpulating the **X** and **Y** values to move across the board.

```
 else if (move == 'w' && board[currentY - 1][currentX] != "#") {
            board[currentY][currentX] = oldSpace;
            currentY--; 
            oldSpace = board[currentY][currentX];
            board[currentY][currentX] = "@";
        }
```
This code above shows how the user can press the **'W'** key to move upwards on the board, once pressed it will minus from the Y value to move up a column (it has to be minus as Y value starts at zero when printing the top of the map). 

### checking if the user has won

Original the plan to check if the user has solved the map was to have another array of the solution then compare it to the current board, this would work but only in the most basic sense as it would mean the user could not exsperiment and has to follow one set solution, this would also make the leader board invalid as everyone who finished would alwasy have the same score.
To fix this i made a function that will start at the end possition and check for adjacent **'c'** tiles then follow them till they find the start postion, if it can reach if by using the path of **'c'** then th euser has solved the puzzel, if not it wait for the user to finish the puzzel and is activaated again when they land on the **'O'** sqaur.

```
while (won != 50) {
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
        won++;
    }
```

This is a C++ command line game for comp 30016 CW1, in this game the user will connect a start and end point like a cicuit, the soultion to each map/board will be the most efficent in terms of spaces.

## Youtube link

https://youtu.be/2vyaYTiw5bs


## link to the game git repository

https://github.com/BenIsTrying/comp3016.git
