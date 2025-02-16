#include <iostream>
using namespace std;

char maze[5][5] = {
    {'S', '.', '#', '.', 'E'},
    {'.', '#', '.', '#', '.'},
    {'.', '.', '.', '#', '.'},
    {'#', '#', '.', '.', '.'},
    {'.', '.', '.', '#', '.'}
};

int playerX = 0, playerY = 0;

void displayMaze() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == playerX && j == playerY) cout << "P ";
            else cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}

bool movePlayer(char move) {
    int newX = playerX, newY = playerY;

    if (move == 'w') newX--;
    else if (move == 's') newX++;
    else if (move == 'a') newY--;
    else if (move == 'd') newY++;

    if (newX >= 0 && newX < 5 && newY >= 0 && newY < 5 && maze[newX][newY] != '#') {
        playerX = newX;
        playerY = newY;
        if (maze[playerX][playerY] == 'E') {
            cout << "Congratulations! You reached the exit!\n";
            return true;
        }
    } else {
        cout << "Invalid move!\n";
    }
    return false;
}

int main() {
    char move;
    cout << "Welcome to the Maze Game! Use W/A/S/D to move. Reach 'E' to win!\n";

    while (true) {
        displayMaze();
        cout << "Enter move (W/A/S/D): ";
        cin >> move;
        if (movePlayer(move)) break;
    }

    return 0;
}
