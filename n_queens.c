#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int size;
int* board;
int cnt=0;
int abs(int a){
	return a<0?-a:a;
}
void print_board(){
	int i,j;
	printf("Solution %d is \n",++cnt);
	for(i=0;i<size;i++){ for (j=0;j<size;j++) if(board[i]==j) printf("Q "); else printf("0 "); printf("\n");}
	printf("\n");
}
bool check_safe(int k,int y){
	int i;
	for(i=0;i<k;i++) if(board[i]==y || abs(i-k)==abs(y-board[i])) return false;
	return true;
}
void n_queens(int k){
	int i;
	if(k==size){
		print_board();
		return ;
	}
	for(i=0;i<size;i++){
		if(check_safe(k,i)){
			board[k]=i;
			n_queens(k+1);
		}
	}
}
void main(){
	printf("Enter the size of the chess board\n");
	scanf("%d",&size);
	board=(int *)malloc(sizeof(int)*size);
	n_queens(0);
	if(cnt==0) printf("There exists no solution\n");
	free(board);
}


