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

## A link to the Video (unlisted YouTube) 

## link to the game git repository

https://github.com/BenIsTrying/comp3016.git
