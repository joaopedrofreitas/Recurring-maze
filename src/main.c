#include "functions.h"

int main(void){
FILE *arq,*arq2;
int row,col,N;
player *st = malloc(sizeof(*st));
player *vet;
srand(time(NULL));
arq = fopen("dataset/input.data", "r");
arq2=fopen("dataset/pathing.data","w");
if(arq==NULL){printf("ERROR");return(1);}
fscanf(arq, "%d %d %d",&row,&col,&N);
printf("row: %d, col: %d, N: %d ", row,col,N);
char (*mat)[col]=malloc(sizeof(char[row][col]));
vet=(player*)malloc((row*col*N)*sizeof(player));

set_init(st,col,row,mat,vet,arq);
while(1)
{
	printf(sep);
	rand_stance(st,col,row,mat,vet);
	Check_life(st);
	print_Maze(col,row,mat,st);
	if(st->life==0){
		loose(vet,col,row,N);
	}
	if(get_Num_matrix()==(N-1)){
		if(Win_Condition(st,col)){
			Win(vet,col,row,N);
		}
	}
	if(st->y==(col-1)){
		warp(col,row,mat,arq,arq2,N,vet,st);
	}
	printf("\nVIDA: %hhd\n",st->life);
	printf(sep);
	timer();
}
release(arq,arq2,col,mat,st,vet);
return 0;
}