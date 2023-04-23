#include "functions.h"
int catch=0,perigos=0,p=0,num_matrix=0,aux_p=0,non_catch=0;

void rand_stance(player *st, int col,int row,char (*mat)[col],player *vet){//onde vai pra direita , colocar a condição de warp
	int value=rand()%7;
	switch (value)
	{
		case 0:
			if(st->y!=0){
				if(mat[st->x][st->y-1]=='#'){
					printf("\nPOSIÇÃO: (%hd %hd), é uma parede\n", st->x,(st->y-1));
					rand_stance(st,col,row,mat,vet);
				}
				else{
					st->y-=1;
					update_stance(st,col,mat,vet);
				}
			}
			else{
				rand_stance(st,col,row,mat,vet);
			}
			break;
		case 1:
			if(st->y!=(col-1)){
				if(mat[st->x][st->y+1]=='#'){
					printf("\nPOSIÇÃO: %hd %hd, é uma parede\n", st->x,(st->y+1));
					rand_stance(st,col,row,mat,vet);
				}
				else{
					st->y+=1;
					update_stance(st,col,mat,vet);
				}
			}
			else{
				rand_stance(st,col,row,mat,vet);
			}
			break;
		case 2:
			if(st->x!=0){
				if(mat[st->x-1][st->y]=='#'){
					printf("\nPOSIÇÃO: %hd %hd, é uma parede\n", (st->x-1),st->y);
					rand_stance(st,col,row,mat,vet);
				}
				else{
					st->x-=1;
					update_stance(st,col,mat,vet);	
				}
			}
			else{
				rand_stance(st,col,row,mat,vet);
			}
			break;
		case 3:
			if(st->x!=0 && st->y!=0){
				if(mat[st->x-1][st->y-1]=='#'){
					printf("\nPOSIÇÃO: %hd %hd, é uma parede\n", (st->x-1),(st->y-1));
					rand_stance(st,col,row,mat,vet);
				}
				else{
					st->x-=1;
					st->y-=1;
					update_stance(st,col,mat,vet);
				}
			}
			else{
				rand_stance(st,col,row,mat,vet);
			}
			break;
		case 4:
			if(st->x!=0 && st->y!=(col-1)){
				if(mat[st->x-1][st->y+1]=='#'){
					printf("\nPOSIÇÃO: %hd %hd, é uma parede\n", (st->x-1),(st->y+1));
					rand_stance(st,col,row,mat,vet);
				}
				else{
					st->x-=1;
					st->y+=1;
					update_stance(st,col,mat,vet);
				}
			}
			else{
				rand_stance(st,col,row,mat,vet);
			}
			break;
		case 5:
			if(st->x!=(row-1) && st->y!=(col-1)){	
				if(mat[st->x+1][st->y+1]=='#'){
					printf("\nPOSIÇÃO: %hd %hd, é uma parede\n", (st->x+1),(st->y+1));
					rand_stance(st,col,row,mat,vet);
				}
				else{
					st->x+=1;
					st->y+=1;
					update_stance(st,col,mat,vet);
				}
			}
			else{
				rand_stance(st,col,row,mat,vet);
			}
			break;
		case 6:
			if(st->x!=(row-1) && st->y!=0){	
				if(mat[st->x+1][st->y-1]=='#'){
					printf("\nPOSIÇÃO: %hd %hd, é uma parede\n", (st->x+1),(st->y-1));
					rand_stance(st,col,row,mat,vet);
				}
				else{
					st->x+=1;
					st->y-=1;
					update_stance(st,col,mat,vet);
				}
			}
			else{
				rand_stance(st,col,row,mat,vet);
			}
			break;
		case 7:
			if(st->x!=(row-1)){	
				if(mat[st->x+1][st->y]=='#'){
					printf("\nPOSIÇÃO: %hd %hd, é uma parede\n", (st->x+1),st->y);
					rand_stance(st,col,row,mat,vet);
				}
				else{
					st->x+=1;
					update_stance(st,col,mat,vet);	
				}
			}
			else{
				rand_stance(st,col,row,mat,vet);
			}
			break;
	}
}
void set_stance(player *st,int col,char (*mat)[col],player *vet){
	printf("\nDIGITE A POSIÇÃO INICIAL(linha,coluna):\n");
	scanf("%hhd %hhd", &st->x,&st->y);
	st->life=10;
	update_stance(st,col,mat,vet);
}

bool set_Maze(int col,int row,char (*mat)[col],FILE *arq){
	char c;
	printf("\n");
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(fscanf(arq,"%c",&c)==EOF){
				return 0;	
			}
			else if(c=='\r' || c=='\n' || c==' '){
				j--;
			}
			else{
				mat[i][j]=c;
			}
		}
	}
	return 1;
}
void print_Maze(int col,int row,char  (*mat)[col],player *st){
printf("\n");
for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				if(i==st->x && j==st->y){
					printf(BRIGHT_GREEN"%3c"NO_COLOR,mat[i][j]);	
				}
				else	
				printf("%3c",mat[i][j]);
			}
		printf("\n");
	}
	printf("\n");
}

void update_stance(player *st,int col,char (*mat)[col],player *vet){
	if(mat[st->x][st->y]=='*'){
		printf("-POSIÇÃO: %hd %hd, é uma area perigosa\n", st->x,st->y);
		catch=0;
		st->life-=1;
		perigos++;
		vet[p].x=st->x;
		vet[p].y=st->y;
		vet[p].bag=num_matrix;
		p++;
		non_catch++;
		aux_p++;
	}
	else if(mat[st->x][st->y]!='0'){
		printf("-POSIÇÃO: (%hd %hd): %c\n", st->x,st->y,mat[st->x][st->y]);
		st->bag+=1;
		mat[st->x][st->y]-=1;
		printf("-POSIÇÃO DEPOIS DE SER CONSUMIDA: (%hd %hd): %c\n", st->x,st->y,mat[st->x][st->y]);
		catch=1;
		vet[p].x=st->x;
		vet[p].y=st->y;
		vet[p].bag=num_matrix;
		p++;
		non_catch=0;//se eu pegar 1 , zero os numero de não pego
		aux_p++;
	}
	else{
		printf("-POSIÇÃO: (%hd %hd): %c, É igual a 0\n", st->x,st->y,mat[st->x][st->y]);
		catch=0;
		vet[p].x=st->x;
		vet[p].y=st->y;
		vet[p].bag=num_matrix;
		p++;
		non_catch++;
		aux_p++;
	}
}

int Checked_stances(player *vet,int N){
	int x=0,y=0,matrix_num=0,aux=0;
	for(int i=0;i<p;i++){
		x=vet[i].x;y=vet[i].y;matrix_num=vet[i].bag;aux=i;
		if(vet[i].bag==-1){
			vet[i].bag=0;
		}
		for(int i=0;i<p;i++){
			if(vet[i].x==x && vet[i].y==y && vet[i].bag==matrix_num && i!=aux){
				p--;
			}
		}
		matrix_num++;
		if(matrix_num==(N-1)){
			matrix_num=0;
		}
	}
	return p;
}

void Check_life(player *st){
	if((st->bag)%4 == 0 && catch == 1 && st->life != 10){
		printf("\nMais uma vida!!\n");
		st->life++;
	}
}

void timer(){
	#ifdef  _WIN64
		Sleep(6000);
	#else
		sleep(6);
	#endif
	system("clear");
}

void new_stance(player *st,int col,char (*mat)[col],player *vet){
	for(int i=0;i<col;i++){
		if(mat[0][i]!='#'){
			st->y=i;
			st->x=0;
			break;
		}
	}
	update_stance(st,col,mat,vet);
}

void loose(player *st,player *vet,int col,int row,int N){
	printf(BOLD_RED"\nFIM DE JOGO\nDERROTA\n"NO_COLOR);
	printf("\n\n");
	catch=Checked_stances(vet,N);
	printf(sep);
	printf(BRIGHT_BLUE"\t\t-STATS-"NO_COLOR);
	printf("\nPERIGOS: %d\nQUANTIDADE DE ITENS COLETADOS: %u\nNUMERO DE POSIÇÕES CAMINHADAS: %d\nNUMERO DE POSIÇÕES NÃO CAMINHADAS: %d\n", perigos,st->bag,catch,((row*col*N)-catch));
	printf(sep);
	exit(1);
}

void save_maze(int col,int row,char (*mat)[col],FILE *arq,FILE *arq2,int N){
		if(num_matrix!=N){
			for (int i=0;i<row;i++){
				for (int j=0;j<col;j++){
					fprintf(arq2,"%c ", mat[i][j]); 
				}
				fprintf(arq2,"\n");
			}
			fprintf(arq2,"\n");
			fclose(arq2);
			arq2=fopen("dataset/pathing.data","a+");
		}
		if(num_matrix==(N-1) || num_matrix==N){
			char c;
			fclose(arq2);
			fclose(arq);
			num_matrix=0;
			arq = fopen("dataset/input.data", "w");
			arq2 = fopen("dataset/pathing.data","r");
			while(num_matrix!=N){
				for(int i=0;i<row;i++){
					for(int j=0;j<col;j++){
						fscanf(arq2,"%c",&c);
						if(c=='\r' || c=='\n' || c==' '){
							j--;
						}
						else{
							mat[i][j]=c;
						}
					}
				}
				for (int i=0;i<row;i++){
					for (int j=0;j<col;j++){
						fprintf(arq,"%c ", mat[i][j]); 
					}
					fprintf(arq,"\n");
				}
				fprintf(arq,"\n");
				fclose(arq);
				arq = fopen("dataset/input.data", "a+");
				num_matrix++;
		}
		fclose(arq2);
		fclose(arq);
		arq = fopen("dataset/input.data", "r");
		arq2=fopen("dataset/pathing.data","w");
		num_matrix=-1;
		aux_p=0;
}
}

void warp(int col,int row,char (*mat)[col],FILE *arq,FILE *arq2,int N,player *vet,player *st){

save_maze(col,row,mat,arq,arq2,N);
set_Maze(col,row,mat,arq);
num_matrix++;
printf("PASSOU PARA OUTRA MATRIZ");
new_stance(st,col,mat,vet);//lembrar de zerar num matrix,e aux_p

}

bool Win_Condition(player *st,int col){
	if((non_catch==aux_p) && st->y==(col-1)){//se o numero de não pegos for igual ao numero de passos dados no mapa todo(todas as matrizes), todas vez q ele volta pra 1° zera o aux_p
		return 1;
	}
	return 0;
}

void Win(player *st,player *vet,int col,int row,int N){
	printf(BRIGHT_GREEN"\nFIM DE JOGO\nVITORIA\n"NO_COLOR);
	printf("\n\n");
	catch=Checked_stances(vet,N);
	printf(sep);
	printf(BRIGHT_BLUE"\t\t-STATS-"NO_COLOR);
	printf("\nPERIGOS: %d\nQUANTIDADE DE ITENS COLETADOS: %u\nNUMERO DE POSIÇÕES CAMINHADAS: %d\nNUMERO DE POSIÇÕES NÃO CAMINHADAS: %d\n", perigos,st->bag,catch,((row*col*N)-catch));
	printf(sep);
	exit(1);
}

void set_init(player *st,int col,int row,char (*mat)[col],player *vet,FILE *arq){
	set_Maze(col,row,mat,arq);
	set_stance(st,col,mat,vet);
}

void release(FILE *arq,FILE *arq2,int col,char (*mat)[col],player *st,player *vet){
fclose(arq2);
fclose(arq);
free(mat);
free(st);
free(vet);

}

int get_Num_matrix(){
	return num_matrix;
}