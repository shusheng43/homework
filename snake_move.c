#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SNAKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'

void snakeMove();
void put_money(void);
void output(void);
void gameover(void);

char map[12][13] =
   {"************",
    "*XXXXH     *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "************"};

int snakeX[SNAKE_MAX_LENGTH]={1, 2, 3, 4, 5};
int snakeY[SNAKE_MAX_LENGTH]={1, 1, 1, 1, 1};
int snakeLength = 5;
int hp = 1;
int dx = 0, dy = 0, count = 0;

void snakeMove() {
    int i = 0;
    char ch;
    ch = getchar();
    switch (ch) {
    case'A':
        dx = -1;
        dy = 0;
        if (map[snakeY[snakeLength - 1] + dy][snakeX[snakeLength - 1] + dx] == SNAKE_BODY || map[snakeY[snakeLength - 1] + dy][snakeX[snakeLength - 1] + dx] == WALL_CELL) {
            hp = 0;
        } else if(map[snakeY[snakeLength - 1] + dy][snakeX[snakeLength - 1] + dx] == SNAKE_FOOD) {
            snakeLength++;
            snakeX[snakeLength - 1] = snakeX[snakeLength - 2] + dx;
            snakeY[snakeLength - 1] = snakeY[snakeLength - 2] + dy;
            map[snakeY[snakeLength - 2]][snakeX[snakeLength - 2]] = SNAKE_BODY;
            map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1]] = SNAKE_HEAD;
            count = 1;
        } else {
            map[snakeY[0]][snakeX[0]] = BLANK_CELL;
            map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1]] = SNAKE_BODY;
            for (i = 0; i < snakeLength - 1; i++) {
                snakeX[i] = snakeX[i + 1];
                snakeY[i] = snakeY[i + 1];
            }
            snakeX[i] --;
            map[snakeY[i]][snakeX[i]] = SNAKE_HEAD;
            count = 0;
        }
        break;
    case'D':
        dx = 1;
        dy = 0;
        if (map[snakeY[snakeLength - 1] + dy][snakeX[snakeLength - 1] + dx] == SNAKE_BODY || map[snakeY[snakeLength - 1] + dy][snakeX[snakeLength - 1] + dx] == WALL_CELL) {
            hp = 0;
        } else if (map[snakeY[snakeLength - 1] + dy][snakeX[snakeLength - 1] + dx] == SNAKE_FOOD) {
            snakeLength++;
            snakeX[snakeLength - 1] = snakeX[snakeLength - 2] + dx;
            snakeY[snakeLength - 1] = snakeY[snakeLength - 2] + dy;
            map[snakeY[snakeLength - 2]][snakeX[snakeLength - 2]] = SNAKE_BODY;
            map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1]] = SNAKE_HEAD;
            count = 1;
        } else {
            map[snakeY[0]][snakeX[0]] = BLANK_CELL;
            map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1]] = SNAKE_BODY;
            for (i = 0; i < snakeLength - 1; i++) {
                snakeX[i] = snakeX[i + 1];
                snakeY[i] = snakeY[i + 1];
            }
            snakeX[i] ++;
            map[snakeY[i]][snakeX[i]] = SNAKE_HEAD;
            count = 0;
        }
        break;
    case'W':
        dy = -1;
        dx = 0;
        if (map[snakeY[snakeLength - 1] + dy][snakeX[snakeLength - 1] + dx] == SNAKE_BODY || map[snakeY[snakeLength - 1] + dy][snakeX[snakeLength - 1] + dx] == WALL_CELL) {
            hp = 0;
        } else if(map[snakeY[snakeLength - 1] + dy][snakeX[snakeLength - 1] + dx] == SNAKE_FOOD) {
            snakeLength++;
            snakeX[snakeLength - 1] = snakeX[snakeLength - 2] + dx;
            snakeY[snakeLength - 1] = snakeY[snakeLength - 2] + dy;
            map[snakeY[snakeLength - 2]][snakeX[snakeLength - 2]] = SNAKE_BODY;
            map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1]] = SNAKE_HEAD;
            count = 1;
        } else {
            map[snakeY[0]][snakeX[0]] = BLANK_CELL;
            map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1]] = SNAKE_BODY;
            for (i = 0; i < snakeLength - 1; i++) {
                snakeX[i] = snakeX[i + 1];
                snakeY[i] = snakeY[i + 1];
            }
            snakeY[i] --;
            map[snakeY[i]][snakeX[i]] = SNAKE_HEAD;
            count = 0;
        }
        break;
    case'S':
        dy = 1;
        dx = 0;
        if (map[snakeY[snakeLength - 1] + dy][snakeX[snakeLength - 1] + dx] == SNAKE_BODY || map[snakeY[snakeLength - 1] + dy][snakeX[snakeLength - 1] + dx] == WALL_CELL) {
            hp = 0;
        } else if(map[snakeY[snakeLength - 1] + dy][snakeX[snakeLength - 1] + dx] == SNAKE_FOOD) {
            snakeLength++;
            snakeX[snakeLength - 1] = snakeX[snakeLength - 2] + dx;
            snakeY[snakeLength - 1] = snakeY[snakeLength - 2] + dy;
            map[snakeY[snakeLength - 2]][snakeX[snakeLength - 2]] = SNAKE_BODY;
            map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1]] = SNAKE_HEAD;
            count = 1;
        } else {
            map[snakeY[0]][snakeX[0]] = BLANK_CELL;
            map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1]] = SNAKE_BODY;
            for (i = 0; i < snakeLength - 1; i++) {
                snakeX[i] = snakeX[i + 1];
                snakeY[i] = snakeY[i + 1];
            }
            snakeY[i] ++;
            map[snakeY[i]][snakeX[i]] = SNAKE_HEAD;
            count = 0;
        }
        if (snakeLength >= SNAKE_MAX_LENGTH) {
            hp = 0;
        }
        break;
}
}

void put_Money() {
    int x, y;
    while(map[y][x] != BLANK_CELL) {
        x = rand()%11;
        y = rand()%11;
    }
    map[y][x] = SNAKE_FOOD;
}

void output() {
    int count;
    system("cls");
    for (count = 0; count < 12; count++) {
        printf("%s\n", map[count]);
    }
}

void gameover() {
    system("cls");
    printf("   gameover!\n");
}

int main() {
	printf("Hello! Welcome to greedy snake!\n\nPress any key to start the game!\n\nW-up  S-down\n\nA-left  D-right");
    getch();
	output();
    put_Money();
    while (hp) {
        snakeMove(dx, dy);
        if (count == 1) {
            put_Money();
            count= 0; 
        }
        if (hp == 0) {
            break;
        }
        output();
    }
    gameover();
    system("pause");
    return 0;
}
