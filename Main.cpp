#include<iostream>
#include<stdio.h>
#include<string.h>


#define MAX_SHIPS_AMMOUNT 10

#define LEGAL 0
#define ILLEGAL -1

#define CAR_SIZE 5
#define BAT_SIZE 4
#define CRU_SIZE 3
#define DES_SIZE 2

#define SHIP_A 2
#define SHIP_A_ENGINE 3
#define SHIP_A_CANNON 4
#define SHIP_A_RADAR 5
#define SHIP_B 6
#define SHIP_B_ENGINE 7
#define SHIP_B_CANNON 8
#define SHIP_B_RADAR 9
#define REEF 10
#define DESTROYED 1
#define EMPTY 0
#define N 1
#define S 2
#define W 3
#define E 4

using namespace std;

struct ship_CAR {
        int px;
        int py;
        int DIRECTION;
        int ship_id;
        int called;
        char player;
};

struct ship_BAT {
        int px;
        int py;
        int DIRECTION;
        int ship_id;
        int called;
        char player;
};

struct ship_CRU {
        int px;
        int py;
        int DIRECTION;
        int ship_id;
        int called;
        char player;
};

struct ship_DES {
        int px;
        int py;
        int DIRECTION;
        int ship_id;
        int called;
        char player;
};

struct init_positions {
        int y1;
        int y2;
        int x1;
        int x2;
};

struct ships_number {
        int CAR_number_A;
        int BAT_number_A;
        int CRU_number_A;
        int DES_number_A;
        int CAR_number_B;
        int BAT_number_B;
        int CRU_number_B;
        int DES_number_B;
};

ship_CAR* create_CAR_A(int ship_id) {
        ship_CAR* new_ship = (ship_CAR*)malloc(sizeof(ship_CAR));
        new_ship->ship_id = ship_id;
        new_ship->called = 0;
        new_ship->player = 'A';
        return new_ship;
}
ship_BAT* create_BAT_A(int ship_id) {
        ship_BAT* new_ship = (ship_BAT*)malloc(sizeof(ship_BAT));
        new_ship->ship_id = ship_id;
        new_ship->called = 0;
        new_ship->player = 'A';
        return new_ship;
}
ship_CRU* create_CRU_A(int ship_id) {
        ship_CRU* new_ship = (ship_CRU*)malloc(sizeof(ship_CRU));
        new_ship->ship_id = ship_id;
        new_ship->called = 0;
        new_ship->player = 'A';
        return new_ship;
}
ship_DES* create_DES_A(int ship_id) {
        ship_DES* new_ship = (ship_DES*)malloc(sizeof(ship_DES));
        new_ship->ship_id = ship_id;
        new_ship->called = 0;
        new_ship->player = 'A';
        return new_ship;
}
ship_CAR* create_CAR_B(int ship_id) {
        ship_CAR* new_ship = (ship_CAR*)malloc(sizeof(ship_CAR));
        new_ship->ship_id = ship_id;
        new_ship->called = 0;
        new_ship->player = 'B';
        return new_ship;
}
ship_BAT* create_BAT_B(int ship_id) {
        ship_BAT* new_ship = (ship_BAT*)malloc(sizeof(ship_BAT));
        new_ship->ship_id = ship_id;
        new_ship->called = 0;
        new_ship->player = 'B';
        return new_ship;
}
ship_CRU* create_CRU_B(int ship_id) {
        ship_CRU* new_ship = (ship_CRU*)malloc(sizeof(ship_CRU));
        new_ship->ship_id = ship_id;
        new_ship->called = 0;
        new_ship->player = 'B';
        return new_ship;
}
ship_DES* create_DES_B(int ship_id) {
        ship_DES* new_ship = (ship_DES*)malloc(sizeof(ship_DES));
        new_ship->ship_id = ship_id;
        new_ship->called = 0;
        new_ship->player = 'B';
        return new_ship;
}

int set_direction(char direction)
{
        int DIRECTION = 0;
        if (direction == 'N')
                DIRECTION = 1;
        else if (direction == 'S')
                DIRECTION = 2;
        else if (direction == 'W')
                DIRECTION = 3;
        else if (direction == 'E')
                DIRECTION = 4;
        return DIRECTION;
}

int check_starting_position(int py, int px, int ship_size, int DIRECTION, char player, int SIZE_X, int SIZE_Y)
{
        if (player == 'A') {
                if (DIRECTION == N) {
                        if ((py >= 0) && (py + ship_size <= SIZE_Y / 2) && (px >= 0) && (px <= SIZE_X))
                                return LEGAL;
                        else
                                return ILLEGAL;
                }
                else if (DIRECTION == S) {
                        if ((py - ship_size >= 0) && (py <= SIZE_Y / 2) && (px >= 0) && (px <= SIZE_X))
                                return LEGAL;
                        else
                                return ILLEGAL;
                }
                else if (DIRECTION == W) {
                        if ((py >= 0) && (py <= SIZE_Y / 2) && (px >= 0) && (px + ship_size <= SIZE_X))
                                return LEGAL;
                        else
                                return ILLEGAL;
                }
                else if (DIRECTION == E) {
                        if ((py >= 0) && (py <= SIZE_Y / 2) && (px - ship_size >= 0) && (px <= SIZE_X))
                                return LEGAL;
                        else
                                return ILLEGAL;
                }
                else return ILLEGAL;
        }
        else if (player == 'B') {
                if (DIRECTION == N) {
                        if ((py >= SIZE_Y / 2) && (py + ship_size <= SIZE_Y) && (px >= 0) && (px <= SIZE_X))
                                return LEGAL;
                        else
                                return ILLEGAL;
                }
                else if (DIRECTION == S) {
                        if ((py - ship_size >= SIZE_Y / 2) && (py <= SIZE_Y) && (px >= 0) && (px <= SIZE_X))
                                return LEGAL;
                        else
                                return ILLEGAL;
                }
                else if (DIRECTION == W) {
                        if ((py >= SIZE_Y / 2) && (py <= SIZE_Y) && (px >= 0) && (px + ship_size <= SIZE_X))
                                return LEGAL;
                        else
                                return ILLEGAL;
                }
                else if (DIRECTION == E) {
                        if ((py >= SIZE_Y / 2) && (py <= SIZE_Y) && (px - ship_size >= 0) && (px <= SIZE_X))
                                return LEGAL;
                        else
                                return ILLEGAL;
                }
                else return ILLEGAL;
        }
        else
                return ILLEGAL;
}

void place_CAR_ship_command(int** board, char CAR_array_ship_command[5], int py, int px, int DIRECTION, char player, int ship_id, ship_CAR** array_of_CAR)
{
        int shipRadar = 0;
        int shipEngine = 0;
        int shipCannon = 0;
        int ship = 0;
        array_of_CAR[ship_id]->py = py;
        array_of_CAR[ship_id]->px = px;
        array_of_CAR[ship_id]->called = 1;
        array_of_CAR[ship_id]->DIRECTION = DIRECTION;
        if (player == 'A') {
                shipRadar = SHIP_A_RADAR;
                shipEngine = SHIP_A_ENGINE;
                shipCannon = SHIP_A_CANNON;
                ship = SHIP_A;
        }
        else if (player == 'B') {
                shipRadar = SHIP_B_RADAR;
                shipEngine = SHIP_B_ENGINE;
                shipCannon = SHIP_B_CANNON;
                ship = SHIP_B;
        }
        for (int i = 0; i < CAR_SIZE; i++) {
                if (CAR_array_ship_command[i] == '0') {
                        if (DIRECTION == N)
                                board[array_of_CAR[ship_id]->px][array_of_CAR[ship_id]->py + i] = DESTROYED;
                        if (DIRECTION == S)
                                board[array_of_CAR[ship_id]->px][array_of_CAR[ship_id]->py - i] = DESTROYED;
                        if (DIRECTION == W)
                                board[array_of_CAR[ship_id]->px + i][array_of_CAR[ship_id]->py] = DESTROYED;
                        if (DIRECTION == E)
                                board[array_of_CAR[ship_id]->px - i][array_of_CAR[ship_id]->py] = DESTROYED;
                }
                else if (CAR_array_ship_command[i] == '1') {
                        if (i == 0) {
                                if (DIRECTION == N)
                                        board[array_of_CAR[ship_id]->px][array_of_CAR[ship_id]->py + i] = shipRadar;
                                if (DIRECTION == S)
                                        board[array_of_CAR[ship_id]->px][array_of_CAR[ship_id]->py - i] = shipRadar;
                                if (DIRECTION == W)
                                        board[array_of_CAR[ship_id]->px + i][array_of_CAR[ship_id]->py] = shipRadar;
                                if (DIRECTION == E)
                                        board[array_of_CAR[ship_id]->px - i][array_of_CAR[ship_id]->py] = shipRadar;
                        }
                        else if (i == CAR_SIZE - 1) {
                                if (DIRECTION == N)
                                        board[array_of_CAR[ship_id]->px][array_of_CAR[ship_id]->py + i] = shipEngine;
                                if (DIRECTION == S)
                                        board[array_of_CAR[ship_id]->px][array_of_CAR[ship_id]->py - i] = shipEngine;
                                if (DIRECTION == W)
                                        board[array_of_CAR[ship_id]->px + i][array_of_CAR[ship_id]->py] = shipEngine;
                                if (DIRECTION == E)
                                        board[array_of_CAR[ship_id]->px - i][array_of_CAR[ship_id]->py] = shipEngine;
                        }
                        else if (i == 1) {
                                if (DIRECTION == N)
                                        board[array_of_CAR[ship_id]->px][array_of_CAR[ship_id]->py + i] = shipCannon;
                                if (DIRECTION == S)
                                        board[array_of_CAR[ship_id]->px][array_of_CAR[ship_id]->py - i] = shipCannon;
                                if (DIRECTION == W)
                                        board[array_of_CAR[ship_id]->px + i][array_of_CAR[ship_id]->py] = shipCannon;
                                if (DIRECTION == E)
                                        board[array_of_CAR[ship_id]->px - i][array_of_CAR[ship_id]->py] = shipCannon;
                        }
                        else {
                                if (DIRECTION == N)
                                        board[array_of_CAR[ship_id]->px][array_of_CAR[ship_id]->py + i] = ship;
                                if (DIRECTION == S)
                                        board[array_of_CAR[ship_id]->px][array_of_CAR[ship_id]->py - i] = ship;
                                if (DIRECTION == W)
                                        board[array_of_CAR[ship_id]->px + i][array_of_CAR[ship_id]->py] = ship;
                                if (DIRECTION == E)
                                        board[array_of_CAR[ship_id]->px - i][array_of_CAR[ship_id]->py] = ship;

                        }
                }
        }
}

void place_BAT_ship_command(int** board, char BAT_array_ship_command[5], int py, int px, int DIRECTION, char player, int ship_id, ship_BAT** array_of_BAT)
{
        int shipRadar = 0;
        int shipEngine = 0;
        int shipCannon = 0;
        int ship = 0;
        array_of_BAT[ship_id]->py = py;
        array_of_BAT[ship_id]->px = px;
        array_of_BAT[ship_id]->called = 1;
        array_of_BAT[ship_id]->DIRECTION = DIRECTION;
        if (player == 'A') {
                shipRadar = SHIP_A_RADAR;
                shipEngine = SHIP_A_ENGINE;
                shipCannon = SHIP_A_CANNON;
                ship = SHIP_A;
        }
        else if (player == 'B') {
                shipRadar = SHIP_B_RADAR;
                shipEngine = SHIP_B_ENGINE;
                shipCannon = SHIP_B_CANNON;
                ship = SHIP_B;
        }
        for (int i = 0; i < BAT_SIZE; i++) {
                if (BAT_array_ship_command[i] == '0') {
                        if (DIRECTION == N)
                                board[array_of_BAT[ship_id]->px][array_of_BAT[ship_id]->py + i] = DESTROYED;
                        if (DIRECTION == S)
                                board[array_of_BAT[ship_id]->px][array_of_BAT[ship_id]->py - i] = DESTROYED;
                        if (DIRECTION == W)
                                board[array_of_BAT[ship_id]->px + i][array_of_BAT[ship_id]->py] = DESTROYED;
                        if (DIRECTION == E)
                                board[array_of_BAT[ship_id]->px - i][array_of_BAT[ship_id]->py] = DESTROYED;
                }
                else if (BAT_array_ship_command[i] == '1') {
                        if (i == 0) {
                                if (DIRECTION == N)
                                        board[array_of_BAT[ship_id]->px][array_of_BAT[ship_id]->py + i] = shipRadar;
                                if (DIRECTION == S)
                                        board[array_of_BAT[ship_id]->px][array_of_BAT[ship_id]->py - i] = shipRadar;
                                if (DIRECTION == W)
                                        board[array_of_BAT[ship_id]->px + i][array_of_BAT[ship_id]->py] = shipRadar;
                                if (DIRECTION == E)
                                        board[array_of_BAT[ship_id]->px - i][array_of_BAT[ship_id]->py] = shipRadar;
                        }
                        else if (i == 1) {
                                if (DIRECTION == N)
                                        board[array_of_BAT[ship_id]->px][array_of_BAT[ship_id]->py + i] = shipCannon;
                                if (DIRECTION == S)
                                        board[array_of_BAT[ship_id]->px][array_of_BAT[ship_id]->py - i] = shipCannon;
                                if (DIRECTION == W)
                                        board[array_of_BAT[ship_id]->px + i][array_of_BAT[ship_id]->py] = shipCannon;
                                if (DIRECTION == E)
                                        board[array_of_BAT[ship_id]->px - i][array_of_BAT[ship_id]->py] = shipCannon;
                        }
                        else if (i == BAT_SIZE - 1) {
                                if (DIRECTION == N)
                                        board[array_of_BAT[ship_id]->px][array_of_BAT[ship_id]->py + i] = shipEngine;
                                if (DIRECTION == S)
                                        board[array_of_BAT[ship_id]->px][array_of_BAT[ship_id]->py - i] = shipEngine;
                                if (DIRECTION == W)
                                        board[array_of_BAT[ship_id]->px + i][array_of_BAT[ship_id]->py] = shipEngine;
                                if (DIRECTION == E)
                                        board[array_of_BAT[ship_id]->px - i][array_of_BAT[ship_id]->py] = shipEngine;
                        }
                        else {
                                if (DIRECTION == N)
                                        board[array_of_BAT[ship_id]->px][array_of_BAT[ship_id]->py + i] = ship;
                                if (DIRECTION == S)
                                        board[array_of_BAT[ship_id]->px][array_of_BAT[ship_id]->py - i] = ship;
                                if (DIRECTION == W)
                                        board[array_of_BAT[ship_id]->px + i][array_of_BAT[ship_id]->py] = ship;
                                if (DIRECTION == E)
                                        board[array_of_BAT[ship_id]->px - i][array_of_BAT[ship_id]->py] = ship;
                        }
                }
        }
}

void place_CRU_ship_command(int** board, char CRU_array_ship_command[5], int py, int px, int DIRECTION, char player, int ship_id, ship_CRU** array_of_CRU)
{
        int shipRadar = 0;
        int shipEngine = 0;
        int shipCannon = 0;
        array_of_CRU[ship_id]->py = py;
        array_of_CRU[ship_id]->px = px;
        array_of_CRU[ship_id]->called = 1;
        array_of_CRU[ship_id]->DIRECTION = DIRECTION;
        if (player == 'A') {
                shipRadar = SHIP_A_RADAR;
                shipEngine = SHIP_A_ENGINE;
                shipCannon = SHIP_A_CANNON;
        }
        else if (player == 'B') {
                shipRadar = SHIP_B_RADAR;
                shipEngine = SHIP_B_ENGINE;
                shipCannon = SHIP_B_CANNON;
        }
        for (int i = 0; i < CRU_SIZE; i++) {
                if (CRU_array_ship_command[i] == '0') {
                        if (DIRECTION == N)
                                board[array_of_CRU[ship_id]->px][array_of_CRU[ship_id]->py + i] = DESTROYED;
                        if (DIRECTION == S)
                                board[array_of_CRU[ship_id]->px][array_of_CRU[ship_id]->py - i] = DESTROYED;
                        if (DIRECTION == W)
                                board[array_of_CRU[ship_id]->px + i][array_of_CRU[ship_id]->py] = DESTROYED;
                        if (DIRECTION == E)
                                board[array_of_CRU[ship_id]->px - i][array_of_CRU[ship_id]->py] = DESTROYED;
                }
                else if (CRU_array_ship_command[i] == '1') {
                        if (i == 0) {
                                if (DIRECTION == N)
                                        board[array_of_CRU[ship_id]->px][array_of_CRU[ship_id]->py + i] = shipRadar;
                                if (DIRECTION == S)
                                        board[array_of_CRU[ship_id]->px][array_of_CRU[ship_id]->py - i] = shipRadar;
                                if (DIRECTION == W)
                                        board[array_of_CRU[ship_id]->px + i][array_of_CRU[ship_id]->py] = shipRadar;
                                if (DIRECTION == E)
                                        board[array_of_CRU[ship_id]->px - i][array_of_CRU[ship_id]->py] = shipRadar;
                        }
                        else if (i == 1) {
                                if (DIRECTION == N)
                                        board[array_of_CRU[ship_id]->px][array_of_CRU[ship_id]->py + i] = shipCannon;
                                if (DIRECTION == S)
                                        board[array_of_CRU[ship_id]->px][array_of_CRU[ship_id]->py - i] = shipCannon;
                                if (DIRECTION == W)
                                        board[array_of_CRU[ship_id]->px + i][array_of_CRU[ship_id]->py] = shipCannon;
                                if (DIRECTION == E)
                                        board[array_of_CRU[ship_id]->px - i][array_of_CRU[ship_id]->py] = shipCannon;
                        }
                        else if (i == CRU_SIZE - 1) {
                                if (DIRECTION == N)
                                        board[array_of_CRU[ship_id]->px][array_of_CRU[ship_id]->py + i] = shipEngine;
                                if (DIRECTION == S)
                                        board[array_of_CRU[ship_id]->px][array_of_CRU[ship_id]->py - i] = shipEngine;
                                if (DIRECTION == W)
                                        board[array_of_CRU[ship_id]->px + i][array_of_CRU[ship_id]->py] = shipEngine;
                                if (DIRECTION == E)
                                        board[array_of_CRU[ship_id]->px - i][array_of_CRU[ship_id]->py] = shipEngine;
                        }
                }
        }
}

void place_DES_ship_command(int** board, char DES_array_ship_command[5], int py, int px, int DIRECTION, char player, int ship_id, ship_DES** array_of_DES)
{
        int shipRadar = 0;
        int shipEngine = 0;
        array_of_DES[ship_id]->py = py;
        array_of_DES[ship_id]->px = px;
        array_of_DES[ship_id]->called = 1;
        array_of_DES[ship_id]->DIRECTION = DIRECTION;
        if (player == 'A') {
                shipRadar = SHIP_A_RADAR;
                shipEngine = SHIP_A_ENGINE;
        }
        else if (player == 'B') {
                shipRadar = SHIP_B_RADAR;
                shipEngine = SHIP_B_ENGINE;
        }
        for (int i = 0; i < CRU_SIZE; i++) {
                if (DES_array_ship_command[i] == '0') {
                        if (DIRECTION == N)
                                board[array_of_DES[ship_id]->px][array_of_DES[ship_id]->py + i] = DESTROYED;
                        else if (DIRECTION == S)
                                board[array_of_DES[ship_id]->px][array_of_DES[ship_id]->py - i] = DESTROYED;
                        else if (DIRECTION == W)
                                board[array_of_DES[ship_id]->px + i][array_of_DES[ship_id]->py] = DESTROYED;
                        else if (DIRECTION == E)
                                board[array_of_DES[ship_id]->px - i][array_of_DES[ship_id]->py] = DESTROYED;
                }
                else if (DES_array_ship_command[i] == '1') {
                        if (i == 0) {
                                if (DIRECTION == N)
                                        board[array_of_DES[ship_id]->px][array_of_DES[ship_id]->py + i] = shipRadar;
                                else if (DIRECTION == S)
                                        board[array_of_DES[ship_id]->px][array_of_DES[ship_id]->py - i] = shipRadar;
                                else if (DIRECTION == W)
                                        board[array_of_DES[ship_id]->px + i][array_of_DES[ship_id]->py] = shipRadar;
                                else if (DIRECTION == E)
                                        board[array_of_DES[ship_id]->px - i][array_of_DES[ship_id]->py] = shipRadar;
                        }
                        else if (i == 1) {
                                if (DIRECTION == N)
                                        board[array_of_DES[ship_id]->px][array_of_DES[ship_id]->py + i] = shipEngine;
                                if (DIRECTION == S)
                                        board[array_of_DES[ship_id]->px][array_of_DES[ship_id]->py - i] = shipEngine;
                                if (DIRECTION == W)
                                        board[array_of_DES[ship_id]->px + i][array_of_DES[ship_id]->py] = shipEngine;
                                if (DIRECTION == E)
                                        board[array_of_DES[ship_id]->px - i][array_of_DES[ship_id]->py] = shipEngine;
                        }
                }
        }
}

int check_too_close(int** board, char command[15], int ship_id, int px, int py, char direction, char type[5], int SIZE_X, int SIZE_Y)
{
        int DIRECTION = set_direction(direction);
        int illegal = 0;
        int ship_size = 0;
        if (strcmp(type, "CAR") == 0)
                ship_size = CAR_SIZE;
        if (strcmp(type, "BAT") == 0)
                ship_size = BAT_SIZE;
        if (strcmp(type, "CRU") == 0)
                ship_size = CRU_SIZE;
        if (strcmp(type, "DES") == 0)
                ship_size = DES_SIZE;
        for (int i = 0; i < ship_size; i++) {
                if (DIRECTION == N) {
                        if (px == 0 && py == 0) {
                                if (board[px][py + ship_size] != EMPTY && board[px][py + ship_size] != REEF)
                                        illegal++;
                                if (board[px + 1][py + i] != EMPTY && board[px + 1][py + i] != REEF)
                                        illegal++;
                        }
                        else if (px == SIZE_X - 1 && py == 0) {
                                if (board[px][py + ship_size] != EMPTY && board[px][py + ship_size] != REEF)
                                        illegal++;
                                if (board[px - 1][py + i] != EMPTY && board[px + 1][py + i] != REEF)
                                        illegal++;
                        }
                        else if (px > 0 && px < SIZE_X - 1 && py == 0) {
                                if (board[px][py + ship_size] != EMPTY && board[px][py + ship_size] != REEF)
                                        illegal++;
                                if (board[px - 1][py + i] != EMPTY && board[px - 1][py + i] != REEF)
                                        illegal++;
                                if (board[px + 1][py + i] != EMPTY && board[px + 1][py + i] != REEF)
                                        illegal++;
                        }
                        else if (px == 0 && py > 0 && py < SIZE_Y - 1) {
                                if (board[px + 1][py + i] != EMPTY && board[px + 1][py + i] != REEF)
                                        illegal++;
                                if (board[px][py - 1] != EMPTY && board[px][py - 1] != REEF)
                                        illegal++;
                                if (py + ship_size != SIZE_Y) {
                                        if (board[px][py + ship_size] != EMPTY && board[px][py + ship_size] != REEF)
                                                illegal++;
                                }
                        }
                        else if (px == SIZE_X - 1 && py > 0 && py < SIZE_Y - 1) {
                                if (board[px - 1][py + i] != EMPTY && board[px - 1][py + i] != REEF)
                                        illegal++;
                                if (board[px][py - 1] != EMPTY && board[px][py - 1] != REEF)
                                        illegal++;
                                if (py + ship_size != SIZE_Y) {
                                        if (board[px][py + ship_size] != EMPTY && board[px][py + ship_size] != REEF)
                                                illegal++;
                                }
                        }
                        else if (px > 0 && py > 0 && px < SIZE_X - 1 && py < SIZE_Y - 1) {
                                if (board[px - 1][py - 1 + i] != EMPTY && board[px - 1][py - 1 + i] != REEF)
                                        illegal++;
                                if (board[px + 1][py - 1 + i] != EMPTY && board[px + 1][py - 1 + i] != REEF)
                                        illegal++;
                                if (board[px][py - 1] != EMPTY && board[px][py - 1] != REEF)
                                        illegal++;
                                if (py + ship_size != SIZE_Y) {
                                        if (board[px][py + ship_size] != EMPTY && board[px][py + ship_size] != REEF)
                                                illegal++;
                                }
                        }
                }
                else if (DIRECTION == S) {
                        if (px == SIZE_X - 1 && py == SIZE_Y - 1) {
                                if (board[px][py - ship_size] != EMPTY && board[px][py - ship_size] != REEF)
                                        illegal++;
                                if (board[px - 1][py - i] != EMPTY && board[px - 1][py - i] != REEF)
                                        illegal++;
                        }
                        else if (px == 0 && py == SIZE_Y - 1) {
                                if (board[px][py - ship_size] != EMPTY && board[px][py - ship_size] != REEF)
                                        illegal++;
                                if (board[px + 1][py - i] != EMPTY && board[px + 1][py - i] != REEF)
                                        illegal++;
                        }
                        else if (px > 0 && px < SIZE_X - 1 && py == SIZE_Y - 1) {
                                if (board[px][py - ship_size] != EMPTY && board[px][py - ship_size] != REEF)
                                        illegal++;
                                if (board[px - 1][py - i] != EMPTY && board[px - 1][py - i] != REEF)
                                        illegal++;
                                if (board[px + 1][py - i] != EMPTY && board[px + 1][py - i] != REEF)
                                        illegal++;
                        }
                        else if (px == 0 && py > 0 && py < SIZE_Y - 1) {
                                if (board[px + 1][py - i] != EMPTY && board[px + 1][py - i] != REEF)
                                        illegal++;
                                if (board[px][py + 1] != EMPTY && board[px][py + 1] != REEF)
                                        illegal++;
                                if (py - ship_size + 1 != 0) {
                                        if (board[px][py - ship_size] != EMPTY && board[px][py - ship_size] != REEF)
                                                illegal++;
                                }
                        }
                        else if (px == SIZE_X - 1 && py > 0 && py < SIZE_Y - 1) {
                                if (board[px - 1][py - i] != EMPTY && board[px - 1][py - i] != REEF)
                                        illegal++;
                                if (board[px][py + 1] != EMPTY && board[px][py + 1] != REEF)
                                        illegal++;
                                if (py - ship_size + 1 != 0) {
                                        if (board[px][py - ship_size] != EMPTY && board[px][py - ship_size] != REEF)
                                                illegal++;
                                }
                        }
                        else if (px > 0 && py > 0 && px < SIZE_X - 1 && py < SIZE_Y - 1) {
                                if (board[px - 1][py + 1 - i] != EMPTY && board[px - 1][py + 1 - i] != REEF)
                                        illegal++;
                                if (board[px + 1][py + 1 - i] != EMPTY && board[px + 1][py + 1 - i] != REEF)
                                        illegal++;
                                if (board[px][py + 1] != EMPTY && board[px][py + 1] != REEF)
                                        illegal++;
                                if (py - ship_size + 1 != 0) {
                                        if (board[px][py - ship_size] != EMPTY && board[px][py - ship_size] != REEF)
                                                illegal++;
                                }
                        }
                }
                else if (DIRECTION == E) {
                        if (px == SIZE_X - 1 && py == 0) {
                                if (board[px - ship_size][py] != EMPTY && board[px - ship_size][py] != REEF)
                                        illegal++;
                                if (board[px - i][py + 1] != EMPTY && board[px - i][py + 1] != REEF)
                                        illegal++;
                        }
                        else if (px == SIZE_X - 1 && py > 0 && py < SIZE_Y - 1) {
                                if (board[px - ship_size][py] != EMPTY && board[px - ship_size][py] != REEF)
                                        illegal++;
                                if (board[px - i][py - 1] != EMPTY && board[px - i][py - 1] != REEF)
                                        illegal++;
                                if (board[px - i][py + 1] != EMPTY && board[px - i][py + 1] != REEF)
                                        illegal++;
                        }
                        else if (px == SIZE_X - 1 && py == SIZE_Y - 1) {
                                if (board[px - ship_size][py] != EMPTY && board[px - ship_size][py] != REEF)
                                        illegal++;
                                if (board[px - i][py - 1] != EMPTY && board[px - i][py - 1] != REEF)
                                        illegal++;
                        }
                        else if (px > 0 && px < SIZE_X - 1 && py == SIZE_Y - 1) {
                                if (board[px - i][py - 1] != EMPTY && board[px - i][py - 1] != REEF)
                                        illegal++;
                                if (board[px + 1][py] != EMPTY && board[px + 1][py] != REEF)
                                        illegal++;
                                if (px - ship_size + 1 != 0) {
                                        if (board[px - ship_size][py] != EMPTY && board[px - ship_size][py] != REEF)
                                                illegal++;
                                }
                        }
                        else if (px > 0 && px < SIZE_X - 1 && py == 0) {
                                if (board[px - i][py + 1] != EMPTY && board[px - i][py + 1] != REEF)
                                        illegal++;
                                if (board[px + 1][py] != EMPTY && board[px + 1][py] != REEF)
                                        illegal++;
                                if (px - ship_size + 1 != 0) {
                                        if (board[px - ship_size][py] != EMPTY && board[px - ship_size][py] != REEF)
                                                illegal++;
                                }
                        }
                        else if (px > 0 && py > 0 && px < SIZE_X - 1 && py < SIZE_Y - 1) {
                                if (board[px + 1 - i][py + 1] != EMPTY && board[px + 1 - i][py + 1] != REEF)
                                        illegal++;
                                if (board[px + 1 - i][py - 1] != EMPTY && board[px + 1 - i][py - 1] != REEF)
                                        illegal++;
                                if (board[px + 1][py] != EMPTY && board[px + 1][py] != REEF)
                                        illegal++;
                                if (px - ship_size + 1 != 0) {
                                        if (board[px - ship_size][py] != EMPTY && board[px - ship_size][py] != REEF)
                                                illegal++;
                                }
                        }
                }
                else if (DIRECTION == W) {
                        if (px == 0 && py == 0) {
                                if (board[px + ship_size][py] != EMPTY && board[px + ship_size][py] != REEF)
                                        illegal++;
                                if (board[px + i][py + 1] != EMPTY && board[px + i][py + 1] != REEF)
                                        illegal++;
                        }
                        else if (px == 0 && py > 0 && py < SIZE_Y) {
                                if (board[px + ship_size][py] != EMPTY && board[px + ship_size][py] != REEF)
                                        illegal++;
                                if (board[px + i][py - 1] != EMPTY && board[px + i][py - 1] != REEF)
                                        illegal++;
                                if (board[px + i][py + 1] != EMPTY && board[px + i][py + 1] != REEF)
                                        illegal++;
                        }
                        else if (px == 0 && py == SIZE_Y - 1) {
                                if (board[px + ship_size][py] != EMPTY && board[px + ship_size][py] != REEF)
                                        illegal++;
                                if (board[px + i][py - 1] != EMPTY && board[px + i][py - 1] != REEF)
                                        illegal++;
                        }
                        else if (px > 0 && px < SIZE_X - 1 && py == SIZE_Y) {
                                if (board[px + i][py - 1] != EMPTY && board[px + i][py - 1] != REEF)
                                        illegal++;
                                if (board[px - 1][py] != EMPTY && board[px - 1][py] != REEF)
                                        illegal++;
                                if (px + ship_size != SIZE_X) {
                                        if (board[px + ship_size][py] != EMPTY && board[px + ship_size][py] != REEF)
                                                illegal++;
                                }
                        }
                        else if (px > 0 && px < SIZE_X - 1 && py == 0) {
                                if (board[px + i][py + 1] != EMPTY && board[px + i][py + 1] != REEF)
                                        illegal++;
                                if (board[px - 1][py] != EMPTY && board[px - 1][py] != REEF)
                                        illegal++;
                                if (px + ship_size != SIZE_X) {
                                        if (board[px + ship_size][py] != EMPTY && board[px + ship_size][py] != REEF)
                                                illegal++;
                                }
                        }
                        else if (px > 0 && py > 0 && px < SIZE_X - 1 && py < SIZE_Y - 1) {
                                if (board[px - 1 + i][py + 1] != EMPTY && board[px - 1 + i][py + 1] != REEF)
                                        illegal++;
                                if (board[px - 1 + i][py - 1] != EMPTY && board[px - 1 + i][py - 1] != REEF)
                                        illegal++;
                                if (board[px - 1][py] != EMPTY && board[px - 1][py] != REEF)
                                        illegal++;
                                if (px + ship_size != SIZE_X) {
                                        if (board[px + ship_size][py] != EMPTY && board[px + ship_size][py] != REEF)
                                                illegal++;
                                }
                        }
                }
        }
        if (illegal != 0)
        {
                return ILLEGAL;
        }
        else return LEGAL;
}

int place_ships_in_state(int** board, char command[15], char type[5], int py, int px, char direction, char player, int ship_id, ship_CAR** array_of_CAR, ship_BAT** array_of_BAT, ship_CRU** array_of_CRU, ship_DES** array_of_DES, int SIZE_X, int SIZE_Y)
{
        int illegal = 0;
        int DIRECTION = set_direction(direction);
        if (strcmp(type, "CAR") == 0) {
                char CAR_array_ship_command[6];
                cin >> CAR_array_ship_command;
                if (check_too_close(board, command, ship_id, px, py, direction, type, SIZE_X, SIZE_Y) == ILLEGAL)
                {
                        cout << "INVALID OPERATION " << '"' << command << " " << player << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << " " << CAR_array_ship_command << '"' << ": PLACING SHIP TOO CLOSE TO OTHER SHIP" << endl;
                        exit(0);
                }
                place_CAR_ship_command(board, CAR_array_ship_command, py, px, DIRECTION, player, ship_id, array_of_CAR);
        }
        if (strcmp(type, "BAT") == 0) {
                char BAT_array_ship_command[6];
                cin >> BAT_array_ship_command;
                if (check_too_close(board, command, ship_id, px, py, direction, type, SIZE_X, SIZE_Y) == ILLEGAL)
                {
                        cout << "INVALID OPERATION " << '"' << command << " " << player << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << " " << BAT_array_ship_command << '"' << ": PLACING SHIP TOO CLOSE TO OTHER SHIP" << endl;
                        exit(0);
                }
                place_BAT_ship_command(board, BAT_array_ship_command, py, px, DIRECTION, player, ship_id, array_of_BAT);
        }
        if (strcmp(type, "CRU") == 0) {
                char CRU_array_ship_command[6];
                cin >> CRU_array_ship_command;
                if (check_too_close(board, command, ship_id, px, py, direction, type, SIZE_X, SIZE_Y) == ILLEGAL)
                {
                        cout << "INVALID OPERATION " << '"' << command << " " << player << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << " " << CRU_array_ship_command << '"' << ": PLACING SHIP TOO CLOSE TO OTHER SHIP" << endl;
                        exit(0);
                }
                place_CRU_ship_command(board, CRU_array_ship_command, py, px, DIRECTION, player, ship_id, array_of_CRU);
        }
        if (strcmp(type, "DES") == 0) {
                char DES_array_ship_command[6];
                cin >> DES_array_ship_command;
                if (check_too_close(board, command, ship_id, px, py, direction, type, SIZE_X, SIZE_Y) == ILLEGAL)
                {
                        cout << "INVALID OPERATION " << '"' << command << " " << player << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << " " << DES_array_ship_command << '"' << ": PLACING SHIP TOO CLOSE TO OTHER SHIP" << endl;
                        exit(0);
                }
                place_DES_ship_command(board, DES_array_ship_command, py, px, DIRECTION, player, ship_id, array_of_DES);
        }
                return LEGAL;
}

void place_CAR(int** board, int py, int px, int DIRECTION, char player, int ship_id, ship_CAR** array_of_CAR)
{
        int shipRadar = 0;
        int shipEngine = 0;
        int shipCannon = 0;
        int ship = 0;
        array_of_CAR[ship_id]->py = py;
        array_of_CAR[ship_id]->px = px;
        array_of_CAR[ship_id]->called = 1;
        array_of_CAR[ship_id]->DIRECTION = DIRECTION;
        if (player == 'A') {
                shipRadar = SHIP_A_RADAR;
                shipEngine = SHIP_A_ENGINE;
                shipCannon = SHIP_A_CANNON;
                ship = SHIP_A;
        }
        else if (player == 'B') {
                shipRadar = SHIP_B_RADAR;
                shipEngine = SHIP_B_ENGINE;
                shipCannon = SHIP_B_CANNON;
                ship = SHIP_B;
        }
        for (int i = 0; i < CAR_SIZE; i++) {
                if (i == 0)
                        board[array_of_CAR[ship_id]->px][array_of_CAR[ship_id]->py] = shipRadar;
                else if (i == CAR_SIZE - 1) {
                        if (DIRECTION == N)
                                board[array_of_CAR[ship_id]->px][array_of_CAR[ship_id]->py + i] = shipEngine;
                        if (DIRECTION == S)
                                board[array_of_CAR[ship_id]->px][array_of_CAR[ship_id]->py - i] = shipEngine;
                        if (DIRECTION == W)
                                board[array_of_CAR[ship_id]->px + i][array_of_CAR[ship_id]->py] = shipEngine;
                        if (DIRECTION == E)
                                board[array_of_CAR[ship_id]->px - i][array_of_CAR[ship_id]->py] = shipEngine;
                }
                else if (i == 1) {
                        if (DIRECTION == N)
                                board[array_of_CAR[ship_id]->px][array_of_CAR[ship_id]->py + i] = shipCannon;
                        if (DIRECTION == S)
                                board[array_of_CAR[ship_id]->px][array_of_CAR[ship_id]->py - i] = shipCannon;
                        if (DIRECTION == W)
                                board[array_of_CAR[ship_id]->px + i][array_of_CAR[ship_id]->py] = shipCannon;
                        if (DIRECTION == E)
                                board[array_of_CAR[ship_id]->px - i][array_of_CAR[ship_id]->py] = shipCannon;
                }
                else {
                        if (DIRECTION == N)
                                board[array_of_CAR[ship_id]->px][array_of_CAR[ship_id]->py + i] = ship;
                        if (DIRECTION == S)
                                board[array_of_CAR[ship_id]->px][array_of_CAR[ship_id]->py - i] = ship;
                        if (DIRECTION == W)
                                board[array_of_CAR[ship_id]->px + i][array_of_CAR[ship_id]->py] = ship;
                        if (DIRECTION == E)
                                board[array_of_CAR[ship_id]->px - i][array_of_CAR[ship_id]->py] = ship;
                }
        }
}

void place_BAT(int** board, int py, int px, int DIRECTION, char player, int ship_id, ship_BAT** array_of_BAT)
{
        int shipRadar = 0;
        int shipEngine = 0;
        int shipCannon = 0;
        int ship = 0;
        array_of_BAT[ship_id]->py = py;
        array_of_BAT[ship_id]->px = px;
        array_of_BAT[ship_id]->called = 1;
        array_of_BAT[ship_id]->DIRECTION = DIRECTION;
        if (player == 'A') {
                shipRadar = SHIP_A_RADAR;
                shipEngine = SHIP_A_ENGINE;
                shipCannon = SHIP_A_CANNON;
                ship = SHIP_A;
        }
        else if (player == 'B') {
                shipRadar = SHIP_B_RADAR;
                shipEngine = SHIP_B_ENGINE;
                shipCannon = SHIP_B_CANNON;
                ship = SHIP_B;
        }
        for (int i = 0; i < BAT_SIZE; i++) {
                if (i == 0)
                        board[array_of_BAT[ship_id]->px][array_of_BAT[ship_id]->py + i] = shipRadar;
                else if (i == 1) {
                        if (DIRECTION == N)
                                board[array_of_BAT[ship_id]->px][array_of_BAT[ship_id]->py + i] = shipCannon;
                        if (DIRECTION == S)
                                board[array_of_BAT[ship_id]->px][array_of_BAT[ship_id]->py - i] = shipCannon;
                        if (DIRECTION == W)
                                board[array_of_BAT[ship_id]->px + i][array_of_BAT[ship_id]->py] = shipCannon;
                        if (DIRECTION == E)
                                board[array_of_BAT[ship_id]->px - i][array_of_BAT[ship_id]->py] = shipCannon;
                }
                else if (i == BAT_SIZE - 1) {
                        if (DIRECTION == N)
                                board[array_of_BAT[ship_id]->px][array_of_BAT[ship_id]->py + i] = shipEngine;
                        if (DIRECTION == S)
                                board[array_of_BAT[ship_id]->px][array_of_BAT[ship_id]->py - i] = shipEngine;
                        if (DIRECTION == W)
                                board[array_of_BAT[ship_id]->px + i][array_of_BAT[ship_id]->py] = shipEngine;
                        if (DIRECTION == E)
                                board[array_of_BAT[ship_id]->px - i][array_of_BAT[ship_id]->py] = shipEngine;
                }
                else {
                        if (DIRECTION == N)
                                board[array_of_BAT[ship_id]->px][array_of_BAT[ship_id]->py + i] = ship;
                        if (DIRECTION == S)
                                board[array_of_BAT[ship_id]->px][array_of_BAT[ship_id]->py - i] = ship;
                        if (DIRECTION == W)
                                board[array_of_BAT[ship_id]->px + i][array_of_BAT[ship_id]->py] = ship;
                        if (DIRECTION == E)
                                board[array_of_BAT[ship_id]->px - i][array_of_BAT[ship_id]->py] = ship;
                }
        }
}

void place_CRU(int** board, int py, int px, int DIRECTION, char player, int ship_id, ship_CRU** array_of_CRU)
{
        int shipRadar = 0;
        int shipEngine = 0;
        int shipCannon = 0;
        array_of_CRU[ship_id]->py = py;
        array_of_CRU[ship_id]->px = px;
        array_of_CRU[ship_id]->called = 1;
        array_of_CRU[ship_id]->DIRECTION = DIRECTION;
        if (player == 'A') {
                shipRadar = SHIP_A_RADAR;
                shipEngine = SHIP_A_ENGINE;
                shipCannon = SHIP_A_CANNON;
        }
        else if (player == 'B') {
                shipRadar = SHIP_B_RADAR;
                shipEngine = SHIP_B_ENGINE;
                shipCannon = SHIP_B_CANNON;
        }
        for (int i = 0; i < CRU_SIZE; i++) {
                if (i == 0)
                        board[array_of_CRU[ship_id]->px][array_of_CRU[ship_id]->py + i] = shipRadar;
                else if (i == 1) {
                        if (DIRECTION == N)
                                board[array_of_CRU[ship_id]->px][array_of_CRU[ship_id]->py + i] = shipCannon;
                        if (DIRECTION == S)
                                board[array_of_CRU[ship_id]->px][array_of_CRU[ship_id]->py - i] = shipCannon;
                        if (DIRECTION == W)
                                board[array_of_CRU[ship_id]->px + i][array_of_CRU[ship_id]->py] = shipCannon;
                        if (DIRECTION == E)
                                board[array_of_CRU[ship_id]->px - i][array_of_CRU[ship_id]->py] = shipCannon;
                }
                else if (i == CRU_SIZE - 1) {
                        if (DIRECTION == N)
                                board[array_of_CRU[ship_id]->px][array_of_CRU[ship_id]->py + i] = shipEngine;
                        if (DIRECTION == S)
                                board[array_of_CRU[ship_id]->px][array_of_CRU[ship_id]->py - i] = shipEngine;
                        if (DIRECTION == W)
                                board[array_of_CRU[ship_id]->px + i][array_of_CRU[ship_id]->py] = shipEngine;
                        if (DIRECTION == E)
                                board[array_of_CRU[ship_id]->px - i][array_of_CRU[ship_id]->py] = shipEngine;
                }
        }
}

void place_DES(int** board, int py, int px, int DIRECTION, char player, int ship_id, ship_DES** array_of_DES)
{
        int shipRadar = 0;
        int shipEngine = 0;
        array_of_DES[ship_id]->py = py;
        array_of_DES[ship_id]->px = px;
        array_of_DES[ship_id]->called = 1;
        array_of_DES[ship_id]->DIRECTION = DIRECTION;
        if (player == 'A') {
                shipRadar = SHIP_A_RADAR;
                shipEngine = SHIP_A_ENGINE;
        }
        else if (player == 'B') {
                shipRadar = SHIP_B_RADAR;
                shipEngine = SHIP_B_ENGINE;
        }

        for (int i = 0; i < DES_SIZE; i++) {
                if (i == 0)
                        board[array_of_DES[ship_id]->px][array_of_DES[ship_id]->py + i] = shipRadar;
                else if (i == 1) {
                        if (DIRECTION == N)
                                board[array_of_DES[ship_id]->px][array_of_DES[ship_id]->py + i] = shipEngine;
                        if (DIRECTION == S)
                                board[array_of_DES[ship_id]->px][array_of_DES[ship_id]->py - i] = shipEngine;
                        if (DIRECTION == W)
                                board[array_of_DES[ship_id]->px + i][array_of_DES[ship_id]->py] = shipEngine;
                        if (DIRECTION == E)
                                board[array_of_DES[ship_id]->px - i][array_of_DES[ship_id]->py] = shipEngine;
                }
        }
}

void print_board(int** board, int SIZE_X, int SIZE_Y)
{
        for (int i = 0; i < SIZE_Y; i++) {
                for (int j = 0; j < SIZE_X; j++) {
                        if (board[j][i] == EMPTY)
                                cout << " ";
                        else if (board[j][i] == SHIP_A)
                                cout << '+';
                        else if (board[j][i] == SHIP_B)
                                cout << '+';
                        else if (board[j][i] == DESTROYED)
                                cout << 'x';
                        else if (board[j][i] == SHIP_A_ENGINE)
                                cout << '+';
                        else if (board[j][i] == SHIP_A_CANNON)
                                cout << '+';
                        else if (board[j][i] == SHIP_A_RADAR)
                                cout << '+';
                        else if (board[j][i] == SHIP_B_ENGINE)
                                cout << '+';
                        else if (board[j][i] == SHIP_B_CANNON)
                                cout << '+';
                        else if (board[j][i] == SHIP_B_RADAR)
                                cout << '+';
                }
                cout << endl;
        }
}

void clear_board(int** board, int SIZE_X, int SIZE_Y)
{
        for (int i = 0; i < SIZE_X; i++) {
                for (int j = 0; j < SIZE_Y; j++) {
                        board[i][j] = EMPTY;
                }
        }
}

int parts_left_A(int** board, int SIZE_X, int SIZE_Y)
{
        int parts_of_A = 0;
        for (int i = 0; i < SIZE_Y; i++) {
                for (int j = 0; j < SIZE_X; j++) {
                        if (board[j][i] == SHIP_A)
                                parts_of_A++;
                        else if (board[j][i] == SHIP_A_ENGINE)
                                parts_of_A++;
                        else if (board[j][i] == SHIP_A_CANNON)
                                parts_of_A++;
                        else if (board[j][i] == SHIP_A_RADAR)
                                parts_of_A++;
                }
        }
        return parts_of_A;
}

int parts_left_B(int** board, int SIZE_X, int SIZE_Y)
{
        int parts_of_B = 0;
        for (int i = 0; i < SIZE_Y; i++) {
                for (int j = 0; j < SIZE_X; j++) {
                        if (board[j][i] == SHIP_B)
                                parts_of_B++;
                        else if (board[j][i] == SHIP_B_ENGINE)
                                parts_of_B++;
                        else if (board[j][i] == SHIP_B_CANNON)
                                parts_of_B++;
                        else if (board[j][i] == SHIP_B_RADAR)
                                parts_of_B++;
                }
        }
        return parts_of_B;
}

int check_reef(int** board, int px, int py, int DIRECTION, char type[5])
{
        int illegal = 0;
        int ship_size = 0;
        if (strcmp(type, "CAR") == 0)
                ship_size = CAR_SIZE;
        if (strcmp(type, "BAT") == 0)
                ship_size = BAT_SIZE;
        if (strcmp(type, "CRU") == 0)
                ship_size = CRU_SIZE;
        if (strcmp(type, "DES") == 0)
                ship_size = DES_SIZE;
        if (DIRECTION == N) {
                for (int i = 0; i < ship_size; i++) {
                        if (board[px][py + i] == REEF)
                                illegal++;
                }
                if (illegal != 0)
                        return ILLEGAL;
                else
                        return LEGAL;
        }
        else if (DIRECTION == S) {
                for (int i = 0; i < ship_size; i++) {
                        if (board[px][py - i] == REEF)
                                illegal++;
                }
                if (illegal != 0)
                        return ILLEGAL;
                else
                        return LEGAL;
        }
        else if (DIRECTION == W) {
                for (int i = 0; i < ship_size; i++) {
                        if (board[px + i][py] == REEF)
                                illegal++;
                }
                if (illegal != 0)
                        return ILLEGAL;
                else
                        return LEGAL;
        }
        else if (DIRECTION == E) {
                for (int i = 0; i < ship_size; i++) {
                        if (board[px - i][py] == REEF)
                                illegal++;
                }
                if (illegal != 0)
                        return ILLEGAL;
                else
                        return LEGAL;
        }
        else
                return LEGAL;
}

void all_ships_of_class_check(char command[15], char player, int py, int px, char direction, int ship_id, char type[5], ships_number* counter, ships_number number)
{
        if (player == 'A')
        {

                if (strcmp(type, "CAR") == 0)
                        counter->CAR_number_A++;
                if (strcmp(type, "BAT") == 0)
                        counter->BAT_number_A++;
                if (strcmp(type, "CRU") == 0)
                        counter->CRU_number_A++;
                if (strcmp(type, "DES") == 0)
                        counter->DES_number_A++;
                if (counter->CAR_number_A > number.CAR_number_A || counter->BAT_number_A > number.BAT_number_A || counter->CRU_number_A > number.CRU_number_A || counter->DES_number_A > number.DES_number_A) {
                        cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << '"' << ": ALL SHIPS OF THE CLASS ALREADY SET" << endl;
                        exit(0);
                }
        }
        else if (player == 'B')
        {
                if (strcmp(type, "CAR") == 0)
                        counter->CAR_number_B++;
                if (strcmp(type, "BAT") == 0)
                        counter->BAT_number_B++;
                if (strcmp(type, "CRU") == 0)
                        counter->CRU_number_B++;
                if (strcmp(type, "DES") == 0)
                        counter->DES_number_B++;
                if (counter->CAR_number_B > number.CAR_number_B || counter->BAT_number_B > number.BAT_number_B || counter->CRU_number_B > number.CRU_number_B || counter->DES_number_B > number.DES_number_B) {
                        cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << '"' << ": ALL SHIPS OF THE CLASS ALREADY SET" << endl;
                        exit(0);
                }
        }
}

int ships_amount_A(int ships_number_A, ships_number counter)
{
        ships_number_A = counter.CAR_number_A + counter.BAT_number_A + counter.CRU_number_A + counter.DES_number_A;
        return ships_number_A;
}

int ships_amount_B(int ships_number_B, ships_number counter)
{
        ships_number_B = counter.CAR_number_B + counter.BAT_number_B + counter.CRU_number_B + counter.DES_number_B;
        return ships_number_B;
}

int check_init_position(char player, int py, int px, init_positions playerA, init_positions playerB, int ship_size, int DIRECTION)
{
        if (player == 'A') {
                if (DIRECTION == N) {
                        if ((py >= playerA.y1) && (py + ship_size <= playerA.y2 + 1) && (px >= playerA.x1) && (px <= playerA.x2 + 1))
                                return LEGAL;
                        else
                                return ILLEGAL;
                }
                else if (DIRECTION == S) {
                        if ((py - ship_size >= playerA.y1) && (py <= playerA.y2 + 1) && (px >= playerA.x1) && (px <= playerA.x2 + 1))
                                return LEGAL;
                        else
                                return ILLEGAL;
                }
                else if (DIRECTION == W) {
                        if ((py >= playerA.y1) && (py <= playerA.y2 + 1) && (px >= playerA.x1) && (px + ship_size <= playerA.x2 + 1))
                                return LEGAL;
                        else
                                return ILLEGAL;
                }
                else if (DIRECTION == E) {
                        if ((py >= playerA.y1) && (py <= playerA.y2 + 1) && (px - ship_size >= playerA.x1) && (px <= playerA.x2 + 1))
                                return LEGAL;
                        else
                                return ILLEGAL;
                }
                else return ILLEGAL;
        }
        else if (player == 'B') {
                if (DIRECTION == N) {
                        if ((py >= playerB.y1) && (py + ship_size <= playerB.y2 + 1) && (px >= playerB.x1) && (px <= playerB.x2 + 1))
                                return LEGAL;
                        else
                                return ILLEGAL;
                }
                else if (DIRECTION == S) {
                        if ((py - ship_size >= playerB.y1) && (py <= playerB.y2 + 1) && (px >= playerB.x1) && (px <= playerB.x2 + 1))
                                return LEGAL;
                        else
                                return ILLEGAL;
                }
                else if (DIRECTION == W) {
                        if ((py >= playerB.y1) && (py <= playerB.y2 + 1) && (px >= playerB.x1) && (px + ship_size <= px <= playerB.x2 + 1))
                                return LEGAL;
                        else
                                return ILLEGAL;
                }
                else if (DIRECTION == E) {
                        if ((py >= playerB.y1) && (py <= playerB.y2 + 1) && (px - ship_size >= playerB.x1) && (px <= playerB.x2 + 1))
                                return LEGAL;
                        else
                                return ILLEGAL;
                }
                else return ILLEGAL;
        }
        else
                return ILLEGAL;
}

void place_ship(int** board, char command[15], int py, int px, char type[5], char direction, const char player, int ship_id, ship_CAR** array_of_CAR, ship_BAT** array_of_BAT, ship_CRU** array_of_CRU, ship_DES** array_of_DES, int init_position_A, int init_position_B, init_positions playerA, init_positions playerB, int SIZE_X, int SIZE_Y, ships_number counter, ships_number number)
{
        int DIRECTION = set_direction(direction);
        if (player == 'A') {
                if (strcmp(type, "CAR") == 0)
                        counter.CAR_number_A++;
                if (strcmp(type, "BAT") == 0)
                        counter.BAT_number_A++;
                if (strcmp(type, "CRU") == 0)
                        counter.CRU_number_A++;
                if (strcmp(type, "DES") == 0)
                        counter.DES_number_A++;
                if (init_position_A == 1) {
                        if (strcmp(type, "CAR") == 0) {
                                if (check_init_position(player, py, px, playerA, playerB, CAR_SIZE, DIRECTION) == LEGAL) {
                                        for (int i = 0; i < number.CAR_number_A; i++) {
                                                if (ship_id == array_of_CAR[i]->ship_id)
                                                        place_CAR(board, py, px, DIRECTION, player, ship_id, array_of_CAR);
                                        }
                                        array_of_CAR[ship_id]->called = 1;
                                }
                                else {
                                        cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << '"' << ": NOT IN STARTING POSITION" << endl;
                                        exit(0);
                                }
                        }
                        else if (strcmp(type, "BAT") == 0) {
                                if (check_init_position(player, py, px, playerA, playerB, BAT_SIZE, DIRECTION) == LEGAL) {
                                        for (int i = 0; i < number.BAT_number_A; i++) {
                                                if (ship_id == array_of_BAT[i]->ship_id)
                                                        place_BAT(board, py, px, DIRECTION, player, ship_id, array_of_BAT);
                                        }
                                        array_of_BAT[ship_id]->called = 1;
                                }
                                else {
                                        cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << '"' << ": NOT IN STARTING POSITION" << endl;
                                        exit(0);
                                };
                        }
                        else if (strcmp(type, "CRU") == 0) {
                                if (check_init_position(player, py, px, playerA, playerB, CRU_SIZE, DIRECTION) == LEGAL) {
                                        for (int i = 0; i < number.CRU_number_A; i++) {
                                                if (ship_id == array_of_CRU[i]->ship_id)
                                                        place_CRU(board, py, px, DIRECTION, player, ship_id, array_of_CRU);
                                        }
                                        array_of_CRU[ship_id]->called = 1;
                                }
                                else {
                                        cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << '"' << ": NOT IN STARTING POSITION" << endl;
                                        exit(0);
                                }
                        }
                        else if (strcmp(type, "DES") == 0) {
                                if (check_init_position(player, py, px, playerA, playerB, DES_SIZE, DIRECTION) == LEGAL) {
                                        for (int i = 0; i < number.DES_number_A; i++) {
                                                if (ship_id == array_of_DES[i]->ship_id)
                                                        place_DES(board, py, px, DIRECTION, player, ship_id, array_of_DES);
                                        }
                                        array_of_DES[ship_id]->called = 1;
                                }
                                else {
                                        cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << '"' << ": NOT IN STARTING POSITION" << endl;
                                        exit(0);
                                }
                        }
                }
                else if (init_position_A == 0) {
                        if (strcmp(type, "CAR") == 0) {
                                if (check_starting_position(py, px, CAR_SIZE, DIRECTION, player, SIZE_X, SIZE_Y) == LEGAL) {
                                        for (int i = 0; i < number.CAR_number_A; i++) {
                                                if (ship_id == array_of_CAR[i]->ship_id)
                                                        place_CAR(board, py, px, DIRECTION, player, ship_id, array_of_CAR);
                                        }
                                        array_of_CAR[ship_id]->called = 1;
                                }
                                else {
                                        cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << '"' << ": NOT IN STARTING POSITION" << endl;
                                        exit(0);
                                }
                        }
                        else if (strcmp(type, "BAT") == 0) {
                                if (check_starting_position(py, px, BAT_SIZE, DIRECTION, player, SIZE_X, SIZE_Y) == LEGAL) {
                                        for (int i = 0; i < number.BAT_number_A; i++) {
                                                if (ship_id == array_of_BAT[i]->ship_id)
                                                        place_BAT(board, py, px, DIRECTION, player, ship_id, array_of_BAT);
                                        }
                                        array_of_BAT[ship_id]->called = 1;
                                }
                                else {
                                        cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << '"' << ": NOT IN STARTING POSITION" << endl;
                                        exit(0);
                                }
                        }
                        else if (strcmp(type, "CRU") == 0) {
                                if (check_starting_position(py, px, CRU_SIZE, DIRECTION, player, SIZE_X, SIZE_Y) == LEGAL) {
                                        for (int i = 0; i < number.CRU_number_A; i++) {
                                                if (ship_id == array_of_CRU[i]->ship_id)
                                                        place_CRU(board, py, px, DIRECTION, player, ship_id, array_of_CRU);
                                        }
                                        array_of_CRU[ship_id]->called = 1;
                                }
                                else {
                                        cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << '"' << ": NOT IN STARTING POSITION" << endl;
                                        exit(0);
                                }
                        }
                        else if (strcmp(type, "DES") == 0) {
                                if (check_starting_position(py, px, DES_SIZE, DIRECTION, player, SIZE_X, SIZE_Y) == LEGAL) {
                                        for (int i = 0; i < number.DES_number_A; i++) {
                                                if (ship_id == array_of_DES[i]->ship_id)
                                                        place_DES(board, py, px, DIRECTION, player, ship_id, array_of_DES);
                                        }
                                        array_of_DES[ship_id]->called = 1;
                                }
                                else {
                                        cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << '"' << ": NOT IN STARTING POSITION" << endl;
                                        exit(0);
                                }
                        }
                }
        }
        else if (player == 'B') {
                if (strcmp(type, "CAR") == 0)
                        counter.CAR_number_B++;
                if (strcmp(type, "BAT") == 0)
                        counter.BAT_number_B++;
                if (strcmp(type, "CRU") == 0)
                        counter.CRU_number_B++;
                if (strcmp(type, "DES") == 0)
                        counter.DES_number_B++;
                if (init_position_B == 1) {
                        if (strcmp(type, "CAR") == 0) {
                                if (check_init_position(player, py, px, playerA, playerB, CAR_SIZE, DIRECTION) == LEGAL) {
                                        for (int i = 0; i < number.CAR_number_B; i++) {
                                                if (ship_id == array_of_CAR[i]->ship_id)
                                                        place_CAR(board, py, px, DIRECTION, player, ship_id, array_of_CAR);
                                        }
                                        array_of_CAR[ship_id]->called = 1;
                                }
                                else {
                                        cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << '"' << ": NOT IN STARTING POSITION" << endl;
                                        exit(0);
                                }
                        }
                        else if (strcmp(type, "BAT") == 0) {
                                if (check_init_position(player, py, px, playerA, playerB, CAR_SIZE, DIRECTION) == LEGAL) {
                                        for (int i = 0; i < number.BAT_number_B; i++) {
                                                if (ship_id == array_of_BAT[i]->ship_id)
                                                        place_BAT(board, py, px, DIRECTION, player, ship_id, array_of_BAT);
                                        }
                                        array_of_BAT[ship_id]->called = 1;
                                }
                                else {
                                        cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << '"' << ": NOT IN STARTING POSITION" << endl;
                                        exit(0);
                                }
                        }
                        else if (strcmp(type, "CRU") == 0) {
                                if (check_init_position(player, py, px, playerA, playerB, CAR_SIZE, DIRECTION) == LEGAL) {
                                        for (int i = 0; i < number.CRU_number_B; i++) {
                                                if (ship_id == array_of_CRU[i]->ship_id)
                                                        place_CRU(board, py, px, DIRECTION, player, ship_id, array_of_CRU);
                                        }
                                }
                                else {
                                        cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << '"' << ": NOT IN STARTING POSITION" << endl;
                                        exit(0);
                                }
                        }
                        else if (strcmp(type, "DES") == 0) {
                                if (check_init_position(player, py, px, playerA, playerB, CAR_SIZE, DIRECTION) == LEGAL) {
                                        for (int i = 0; i < number.DES_number_B; i++) {
                                                if (ship_id == array_of_DES[i]->ship_id)
                                                        place_DES(board, py, px, DIRECTION, player, ship_id, array_of_DES);
                                        }
                                        array_of_DES[ship_id]->called = 1;
                                }
                                else {
                                        cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << '"' << ": NOT IN STARTING POSITION" << endl;
                                        exit(0);
                                }
                        }
                }
                else if (init_position_B == 0) {
                        if (strcmp(type, "CAR") == 0) {
                                if (check_starting_position(py, px, DES_SIZE, DIRECTION, player, SIZE_X, SIZE_Y) == LEGAL) {
                                        for (int i = 0; i < number.CAR_number_B; i++) {
                                                if (ship_id == array_of_CAR[i]->ship_id)
                                                        place_CAR(board, py, px, DIRECTION, player, ship_id, array_of_CAR);
                                        }
                                        array_of_CAR[ship_id]->called = 1;
                                }
                                else {
                                        cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << '"' << ": NOT IN STARTING POSITION" << endl;
                                        exit(0);
                                }
                        }
                        else if (strcmp(type, "BAT") == 0) {
                                if (check_starting_position(py, px, DES_SIZE, DIRECTION, player, SIZE_X, SIZE_Y) == LEGAL) {
                                        for (int i = 0; i < number.BAT_number_B; i++) {
                                                if (ship_id == array_of_BAT[i]->ship_id)
                                                        place_BAT(board, py, px, DIRECTION, player, ship_id, array_of_BAT);
                                        }
                                        array_of_BAT[ship_id]->called = 1;
                                }
                                else {
                                        cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << '"' << ": NOT IN STARTING POSITION" << endl;
                                        exit(0);
                                }
                        }
                        else if (strcmp(type, "CRU") == 0) {
                                if (check_starting_position(py, px, DES_SIZE, DIRECTION, player, SIZE_X, SIZE_Y) == LEGAL) {
                                        for (int i = 0; i < number.CRU_number_B; i++) {
                                                if (ship_id == array_of_CRU[i]->ship_id)
                                                        place_CRU(board, py, px, DIRECTION, player, ship_id, array_of_CRU);
                                        }
                                        array_of_CRU[ship_id]->called = 1;
                                }
                                else {
                                        cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << '"' << ": NOT IN STARTING POSITION" << endl;
                                        exit(0);
                                }
                        }
                        else if (strcmp(type, "DES") == 0) {
                                if (check_starting_position(py, px, DES_SIZE, DIRECTION, player, SIZE_X, SIZE_Y) == LEGAL) {
                                        for (int i = 0; i < number.DES_number_B; i++) {
                                                if (ship_id == array_of_DES[i]->ship_id)
                                                        place_DES(board, py, px, DIRECTION, player, ship_id, array_of_DES);
                                        }
                                        array_of_DES[ship_id]->called = 1;
                                }
                                else {
                                        cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << '"' << ": NOT IN STARTING POSITION" << endl;
                                        exit(0);
                                }
                        }
                }
        }
}

int already_present_check(char type[5], int ship_id, ship_CAR** array_of_CAR, ship_BAT** array_of_BAT, ship_CRU** array_of_CRU, ship_DES** array_of_DES)
{
        for (int i = 0; i < MAX_SHIPS_AMMOUNT; i++) {
                if (strcmp(type, "CAR") == 0) {
                        if (array_of_CAR[i]->ship_id == ship_id && array_of_CAR[i]->called == 1)
                                return ILLEGAL;
                }
                else if (strcmp(type, "BAT") == 0) {
                        if (array_of_BAT[i]->ship_id == ship_id && array_of_BAT[i]->called == 1)
                                return ILLEGAL;
                }
                else if (strcmp(type, "CRU") == 0) {
                        if (array_of_CRU[i]->ship_id == ship_id && array_of_CRU[i]->called == 1)
                                return ILLEGAL;
                }
                else if (strcmp(type, "DES") == 0) {
                        if (array_of_DES[i]->ship_id == ship_id && array_of_DES[i]->called == 1)
                                return ILLEGAL;
                }
                else return ILLEGAL;
        }
        return LEGAL;
}

int shoot_check(int py, int px, int SIZE_X, int SIZE_Y)
{
        if (py >= 0 && py <= SIZE_Y && px >= 0 && px <= SIZE_X)
                return LEGAL;
        else return ILLEGAL;
}

int place_both_ships_in_state(int** board, int px, int py, int direction, int ship_id, char type[5], char player, char command[15], int ships_number_A, int ships_number_B, int A_turn, int B_turn, ship_CAR** array_of_CAR_A, ship_BAT** array_of_BAT_A, ship_CRU** array_of_CRU_A, ship_DES** array_of_DES_A, ship_CAR** array_of_CAR_B, ship_BAT** array_of_BAT_B, ship_CRU** array_of_CRU_B, ship_DES** array_of_DES_B, int  SIZE_X, int SIZE_Y, ships_number counter, ships_number number)
{
        if (player == 'A') {
                if (already_present_check(type, ship_id, array_of_CAR_A, array_of_BAT_A, array_of_CRU_A, array_of_DES_A) == ILLEGAL) {
                        cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << '"' << ": SHIP ALREADY PRESENT" << endl;
                        exit(0);
                }
                if (place_ships_in_state(board, command, type, py, px, direction, player, ship_id, array_of_CAR_A, array_of_BAT_A, array_of_CRU_A, array_of_DES_A, SIZE_X, SIZE_Y) == ILLEGAL)
                        return ILLEGAL;
                else {
                        return LEGAL;
                }
        }
        else if (player == 'B') {
                if (already_present_check(type, ship_id, array_of_CAR_B, array_of_BAT_B, array_of_CRU_B, array_of_DES_B) == ILLEGAL) {
                        cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << '"' << ": SHIP ALREADY PRESENT" << endl;
                        exit(0);
                }
                if (place_ships_in_state(board, command, type, py, px, direction, player, ship_id, array_of_CAR_B, array_of_BAT_B, array_of_CRU_B, array_of_DES_B, SIZE_X, SIZE_Y) == ILLEGAL)
                        return ILLEGAL;
                else {
                        return LEGAL;
                }
        }
        else
                return ILLEGAL;
}

void change_size(int* SIZE_Y, int* SIZE_X, int*** board)
{
        int new_SIZE_Y;
        int new_SIZE_X;
        cin >> new_SIZE_Y;
        cin >> new_SIZE_X;

        int** new_board = (int**)malloc(sizeof(int*) * new_SIZE_X);

        for (int i = 0; i < new_SIZE_X; i++)
        {
                new_board[i] = (int*)malloc(sizeof(int) * new_SIZE_Y);
        }
        int min_x;
        if (*SIZE_X > new_SIZE_X)
                min_x = new_SIZE_X;
        else
                min_x = *SIZE_X;
        int min_y;
        if (*SIZE_Y > new_SIZE_Y)
                min_y = new_SIZE_Y;
        else
                min_y = *SIZE_Y;

        for (int i = 0; i < min_x; i++) {
                for (int j = 0; j < min_y; j++)
                {
                        new_board[i][j] = (*board)[i][j];
                }
                free((*board)[i]);
        }
        free(*board);
        *board = new_board;
        *SIZE_X = new_SIZE_X;
        *SIZE_Y = new_SIZE_Y;
}

void shoot(int** board, int px, int py)
{
        if (board[px][py] == SHIP_A || board[px][py] == SHIP_A_CANNON || board[px][py] == SHIP_A_ENGINE || board[px][py] == SHIP_A_RADAR || board[px][py] == SHIP_B || board[px][py] == SHIP_B_CANNON || board[px][py] == SHIP_B_ENGINE || board[px][py] == SHIP_B_RADAR)
                board[px][py] = DESTROYED;
}

void print_board_advanced(int** board, int SIZE_X, int SIZE_Y)
{
        if (SIZE_X < 11) {
                cout << "  ";
                for (int i = 0; i < SIZE_X; i++)
                        cout << i;
        }
        else {
                cout << "  ";
                for (int i = 0; i < SIZE_X; i++)
                {
                        cout << i / 10;
                }
                cout << endl;
                cout << "  ";
                for (int i = 0; i < SIZE_X; i++)
                {
                        cout << i % 10;
                }
        }
        cout << endl;
        for (int i = 0; i < SIZE_Y; i++) {
                if (i < 10)
                        cout << '0' << i;
                else
                        cout << i;
                for (int j = 0; j < SIZE_X; j++) {
                        if (board[j][i] == EMPTY)
                                cout << " ";
                        else if (board[j][i] == SHIP_A)
                                cout << '+';
                        else if (board[j][i] == SHIP_B)
                                cout << '+';
                        else if (board[j][i] == DESTROYED)
                                cout << 'x';
                        else if (board[j][i] == SHIP_A_ENGINE)
                                cout << '%';
                        else if (board[j][i] == SHIP_A_CANNON)
                                cout << '!';
                        else if (board[j][i] == SHIP_A_RADAR)
                                cout << '@';
                        else if (board[j][i] == SHIP_B_ENGINE)
                                cout << '%';
                        else if (board[j][i] == SHIP_B_CANNON)
                                cout << '!';
                        else if (board[j][i] == SHIP_B_RADAR)
                                cout << '@';
                }
                cout << endl;
        }
        cout << endl;
        cout << "PARTS REMAINING:: A : " << parts_left_A(board, SIZE_X, SIZE_Y) << " B : " << parts_left_B(board, SIZE_X, SIZE_Y) << endl;
}

void placeReef(int** board, int SIZE_X, int SIZE_Y, char command[15])
{
        int x, y;
        cin >> y;
        cin >> x;
        if (x > SIZE_X - 1 || x < 0 || y<0 || y>SIZE_Y - 1) {
                cout << "INVALID OPERATION " << '"' << command << " " << y << " " << x << " " << '"' << ": REEF IS NOT PLACED ON BOARD" << endl;
                exit(0);
        }
        board[x][y] = REEF;
}

void set_fleet(ships_number* counter)
{
        char player;
        cin >> player;
        if (player == 'A') {
                cin >> counter->CAR_number_A;
                cin >> counter->BAT_number_A;
                cin >> counter->CRU_number_A;
                cin >> counter->DES_number_A;
        }
        else if (player == 'B') {
                cin >> counter->CAR_number_B;
                cin >> counter->BAT_number_B;
                cin >> counter->CRU_number_B;
                cin >> counter->DES_number_B;
        }
}

int main()
{
        int SIZE_X = 10;
        int SIZE_Y = 21;
        int** board = (int**)malloc(sizeof(int*) * SIZE_X);
        for (int i = 0; i < SIZE_X; i++)
        {
                board[i] = (int*)malloc(sizeof(int) * SIZE_Y);
        }
        ships_number number;
        number.CAR_number_A = number.CAR_number_B = 1;
        number.BAT_number_A = number.BAT_number_B = 2;
        number.CRU_number_A = number.CRU_number_B = 3;
        number.DES_number_A = number.DES_number_B = 4;
        ships_number counter;
        counter.CAR_number_A = counter.CAR_number_B = 0;
        counter.BAT_number_A = counter.BAT_number_B = 0;
        counter.CRU_number_A = counter.CRU_number_B = 0;
        counter.DES_number_A = counter.DES_number_B = 0;
        int A_turn = 0;
        int B_turn = 0;
        int init_position_A = 0;
        int init_position_B = 0;
        int ships_number_A = 10;
        int ships_number_B = 10;
        int player_turn = 0;
        char command[15];
        char player;
        int px;
        int py;
        char direction;
        int ship_id;
        char type[5];
        int array[MAX_SHIPS_AMMOUNT];
        for (int i = 0; i < MAX_SHIPS_AMMOUNT; i++)
        {
                array[i] = i;
        }
        ship_CAR* array_of_CAR_A[MAX_SHIPS_AMMOUNT];
        ship_BAT* array_of_BAT_A[MAX_SHIPS_AMMOUNT];
        ship_CRU* array_of_CRU_A[MAX_SHIPS_AMMOUNT];
        ship_DES* array_of_DES_A[MAX_SHIPS_AMMOUNT];
        ship_CAR* array_of_CAR_B[MAX_SHIPS_AMMOUNT];
        ship_BAT* array_of_BAT_B[MAX_SHIPS_AMMOUNT];
        ship_CRU* array_of_CRU_B[MAX_SHIPS_AMMOUNT];
        ship_DES* array_of_DES_B[MAX_SHIPS_AMMOUNT];
        struct init_positions playerB;
        struct init_positions playerA;
        playerA.x1 = playerA.x2 = playerA.y1 = playerA.y2 = 0;
        playerB.x1 = playerB.x2 = playerB.y1 = playerB.y2 = 0;
        for (int i = 0; i < MAX_SHIPS_AMMOUNT; i++)
        {
                ship_id = array[i];
                array_of_CAR_A[i] = create_CAR_A(ship_id);
                array_of_BAT_A[i] = create_BAT_A(ship_id);
                array_of_CRU_A[i] = create_CRU_A(ship_id);
                array_of_DES_A[i] = create_DES_A(ship_id);
                array_of_CAR_B[i] = create_CAR_B(ship_id);
                array_of_BAT_B[i] = create_BAT_B(ship_id);
                array_of_CRU_B[i] = create_CRU_B(ship_id);
                array_of_DES_B[i] = create_DES_B(ship_id);
        }
        clear_board(board, SIZE_X, SIZE_Y);
        while (cin >> command) {
                if (strcmp(command, "[state]") == 0) {
                        while (cin >> command) {
                                if (strcmp(command, "BOARD_SIZE") == 0) {
                                        change_size(&SIZE_Y, &SIZE_X, &board);
                                        clear_board(board, SIZE_X, SIZE_Y);
                                }
                                if (strcmp(command, "REEF") == 0)
                                        placeReef(board, SIZE_X, SIZE_Y, command);
                                else if (strcmp(command, "INIT_POSITION") == 0) {
                                        cin >> player;
                                        if (player == 'A') {
                                                init_position_A = 1;
                                                cin >> playerA.y1 >> playerA.x1 >> playerA.y2 >> playerA.x2;
                                        }
                                        else if (player == 'B') {
                                                init_position_B = 1;
                                                cin >> playerB.y1 >> playerB.x1 >> playerB.y2 >> playerB.x2;
                                        }
                                }
                                else if (strcmp(command, "SHIP") == 0) {
                                        cin >> player;
                                        if (player == 'A') {
                                                ships_number_A--;
                                                A_turn++;
                                        }
                                        else if (player == 'B')
                                        {
                                                ships_number_B--;
                                                B_turn++;
                                        }
                                        cin >> py;
                                        cin >> px;
                                        cin >> direction;
                                        cin >> ship_id;
                                        cin >> type;
                                        all_ships_of_class_check(command, player, px, py, direction, ship_id, type, &counter, number);
                                        if (place_both_ships_in_state(board, px, py, direction, ship_id, type, player, command, ships_number_A, ships_number_B, A_turn, B_turn, array_of_CAR_A, array_of_BAT_A, array_of_CRU_A, array_of_DES_A, array_of_CAR_B, array_of_BAT_B, array_of_CRU_B, array_of_DES_B, SIZE_X, SIZE_Y, counter, number) == ILLEGAL)
                                                return 0;
                                }
                                else if (strcmp(command, "NEXT_PLAYER") == 0) {
                                        cin >> command;
                                        if (strcmp(command, "A") == 0)
                                                player_turn = 0;
                                        if (strcmp(command, "B") == 0)
                                                player_turn = 1;
                                }
                                else if (strcmp(command, "SET_FLEET") == 0) {
                                        set_fleet(&number);
                                        ships_number_A = ships_amount_A(ships_number_A, number);
                                        ships_number_B = ships_amount_B(ships_number_B, number);
                                }
                                else if (strcmp(command, "PRINT") == 0) {
                                        cin >> command;
                                        if (strcmp(command, "0") == 0) {
                                                print_board(board, SIZE_X, SIZE_Y);
                                                cout << endl;
                                                cout << "PARTS REMAINING:: A : " << parts_left_A(board, SIZE_X, SIZE_Y) << " B : " << parts_left_B(board, SIZE_X, SIZE_Y) << endl;
                                        }
                                        else if (strcmp(command, "1") == 0)
                                                print_board_advanced(board, SIZE_X, SIZE_Y);
                                }
                                else if (strcmp(command, "[state]") == 0)
                                        break;
                        }
                }
                else if (strcmp(command, "[playerA]") == 0) {
                        char player = 'A';
                        if (player_turn % 2 == 0) {
                                player_turn++;
                                while (cin >> command) {
                                        if (strcmp(command, "PLACE_SHIP") == 0) {
                                                cin >> py;
                                                cin >> px;
                                                cin >> direction;
                                                cin >> ship_id;
                                                cin >> type;
                                                int DIRECTION = set_direction(direction);
                                                if (px < SIZE_X && py < SIZE_Y) {
                                                        if (check_reef(board, px, py, DIRECTION, type) == ILLEGAL) {
                                                                cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << '"' << ": PLACING SHIP ON REEF" << endl;
                                                                return 0;
                                                        }
                                                }
                                                if (check_too_close(board, command, ship_id, px, py, direction, type, SIZE_X, SIZE_Y) == ILLEGAL)
                                                {
                                                        cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << '"' << ": PLACING SHIP TOO CLOSE TO OTHER SHIP" << endl;
                                                        return 0;
                                                }
                                                if (already_present_check(type, ship_id, array_of_CAR_A, array_of_BAT_A, array_of_CRU_A, array_of_DES_A) == ILLEGAL) {
                                                        cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << '"' << ": SHIP ALREADY PRESENT" << endl;
                                                        return 0;
                                                }
                                                all_ships_of_class_check(command, player, py, px, direction, ship_id, type, &counter, number);
                                                place_ship(board, command, py, px, type, direction, player, ship_id, array_of_CAR_A, array_of_BAT_A, array_of_CRU_A, array_of_DES_A, init_position_A, init_position_B, playerA, playerB, SIZE_X, SIZE_Y, counter, number);
                                                ships_number_A--;
                                                A_turn++;
                                        }
                                        else if (strcmp(command, "SHOOT") == 0) {
                                                cin >> py;
                                                cin >> px;
                                                if (shoot_check(py, px, SIZE_X, SIZE_Y) == ILLEGAL) {
                                                        cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << '"' << ": FIELD DOES NOT EXIST" << endl;
                                                        return 0;
                                                }
                                                if (ships_number_A != 0 || ships_number_B != 0) {
                                                        cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << '"' << ": NOT ALL SHIPS PLACED" << endl;
                                                        return 0;
                                                }
                                                else {
                                                        shoot(board, px, py);
                                                }
                                        }
                                        else if (strcmp(command, "[playerA]") == 0) {
                                                if (parts_left_A(board, SIZE_X, SIZE_Y) == 0 && A_turn > 0 && B_turn > 0) {
                                                        cout << "B won" << endl;
                                                        return 0;
                                                }
                                                else if (parts_left_B(board, SIZE_X, SIZE_Y) == 0 && A_turn > 0 && B_turn > 0) {
                                                        cout << "A won" << endl;
                                                        return 0;
                                                }
                                                break;
                                        }
                                }
                        }
                        else {
                                cout << "INVALID OPERATION " << '"' << command << " " << '"' << ": THE OTHER PLAYER EXPECTED" << endl;
                                return 0;
                        }
                }
                else if (strcmp(command, "[playerB]") == 0) {
                        if (player_turn % 2 == 1) {
                                char player = 'B';
                                player_turn++;
                                while (cin >> command) {
                                        if (strcmp(command, "PLACE_SHIP") == 0) {

                                                cin >> py;
                                                cin >> px;
                                                cin >> direction;
                                                cin >> ship_id;
                                                cin >> type;
                                                int DIRECTION = set_direction(direction);
                                                if (px < SIZE_X && py < SIZE_Y) {
                                                        if (check_reef(board, px, py, DIRECTION, type) == ILLEGAL) {
                                                                cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << '"' << ": PLACING SHIP ON REEF" << endl;
                                                                return 0;
                                                        }
                                                }
                                                if (check_too_close(board, command, ship_id, px, py, direction, type, SIZE_X, SIZE_Y) == ILLEGAL)
                                                {
                                                        cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << '"' << ": PLACING SHIP TOO CLOSE TO OTHER SHIP" << endl;
                                                        return 0;
                                                }
                                                if (already_present_check(type, ship_id, array_of_CAR_B, array_of_BAT_B, array_of_CRU_B, array_of_DES_B) == ILLEGAL) {
                                                        cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << " " << direction << " " << ship_id << " " << type << '"' << ": SHIP ALREADY PRESENT" << endl;
                                                        return 0;
                                                }
                                                all_ships_of_class_check(command, player, py, px, direction, ship_id, type, &counter, number);
                                                place_ship(board, command, py, px, type, direction, player, ship_id, array_of_CAR_A, array_of_BAT_A, array_of_CRU_A, array_of_DES_A, init_position_A, init_position_B, playerA, playerB, SIZE_X, SIZE_Y, counter, number);
                                                ships_number_B--;
                                                B_turn++;
                                        }
                                        else if (strcmp(command, "SHOOT") == 0) {
                                                cin >> py;
                                                cin >> px;
                                                if (shoot_check(py, px, SIZE_X, SIZE_Y) == ILLEGAL) {
                                                        cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << '"' << ": FIELD DOES NOT EXIST" << endl;
                                                        return 0;
                                                }
                                                if (ships_number_A != 0 || ships_number_B != 0) {
                                                        cout << "INVALID OPERATION " << '"' << command << " " << py << " " << px << '"' << ": NOT ALL SHIPS PLACED" << endl;
                                                        return 0;
                                                }
                                                else {
                                                        shoot(board, px, py);
                                                }
                                        }
                                        else if (strcmp(command, "[playerB]") == 0) {
                                                if (parts_left_A(board, SIZE_X, SIZE_Y) == 0 && A_turn > 0 && B_turn > 0) {
                                                        cout << "B won" << endl;
                                                        return 0;
                                                }
                                                else if (parts_left_B(board, SIZE_X, SIZE_Y) == 0 && A_turn > 0 && B_turn > 0) {
                                                        cout << "A won" << endl;
                                                        return 0;
                                                }
                                                break;
                                        }
                                }
                        }
                        else {
                                cout << "INVALID OPERATION " << '"' << command << " " << '"' << ": THE OTHER PLAYER EXPECTED" << endl;
                                return 0;
                        }
                }
        }
        return 0;
}
