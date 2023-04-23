#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H
#ifdef  _WIN64
    #include <Windows.h>
#else
    #include <unistd.h>
#endif
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>
#include<string.h>
#include<time.h>
#define BOLD_RED "\x1b[31;1m"
#define NO_COLOR "\x1b[0;0m"
#define BRIGHT_GREEN "\x1b[92;1m"
#define BRIGHT_BLUE "\x1b[94;1m"
#define sep "\n========================================================\n"

typedef struct{
    uint8_t x,y,life;
	int bag;
}player;

void set_stance(player *st,int col,char (*mat)[col],player *vet);
bool set_Maze(int col,int row,char (*mat)[col],FILE *arq);//pegar do input.data e operar uma matriz de cada vez
void print_Maze(int col,int row,char (*mat)[col],player *st);
void rand_stance(player *st, int col,int row,char (*mat)[col],player *vet);
void update_stance(player *st,int col,char (*mat)[col],player *vet);
int Checked_stances(player *vet,int N);
void Check_life(player *st);
void new_stance(player *st,int col,char (*mat)[col],player *vet);
void timer();
void loose(player *vet,int col,int row,int N);
void save_maze(int col,int row,char (*mat)[col],FILE *arq,FILE *arq2,int N);//salvar no outro arquivo e passar pra esse
void warp(int col,int row,char (*mat)[col],FILE *arq,FILE *arq2,int N,player *vet,player*st);
bool Win_Condition(player *st,int col);
void Win(player *vet,int col,int row,int N);
void set_init(player *st,int col,int row,char (*mat)[col],player *vet,FILE *arq);
void release(FILE *arq,FILE *arq2,int col,char (*mat)[col],player *st,player *vet);
int get_Num_matrix();
void check_vet(player *vet,int col,int row,int N);
#endif
