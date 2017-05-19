#include<iostream>
#include<stdio.h>
#include<stdlib.h>

/**A simple modification to a tic_tac_toe game makes it interesting 
@author Sandipan Sikdar
**/

void display(char (*a)[3]){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			std::cout<< a[i][j] << " ";
		std::cout<<std::endl;
	}
}

bool valid(int x, int y){
	if(x>y)
		return true;
	else	return false;
}

int bid(int bid_1,int chip_1,int p){
	std::cout << "player "<< p<< " enter your bid" << std::endl;
	std::cin >> bid_1;
	while(valid(bid_1,chip_1)){
		std::cout << "please enter a valid bid, you have "<< chip_1 << " chips" << std::endl;
		std::cin >> bid_1;
	}
	return bid_1;	
}

bool check_col(char p,char (*a)[3]){
	int cnt;
	for(int i=0;i<3;i++){
		cnt = 0;
		for(int j=0;j<3;j++){
			if(a[j][i]==p)
				cnt++;
		}
		if(cnt==3)
			return true;
	}
	return false;
}

bool check_row(char p,char (*a)[3]){
	int cnt;
	for(int i=0;i<3;i++){
		cnt = 0;
		for(int j=0;j<3;j++){
			if(a[i][j]==p)
				cnt++;
		}
		if(cnt==3)
			return true;
	}
	return false;
}

bool check_diag(char p,char (*a)[3]){
	int cnt = 0;
	for(int i=0;i<3;i++){
		if(a[i][i]==p)
			cnt++;
	}
	if(cnt==3)
		return true;
	cnt = 0;
	int i = 0,j = 2;
	for(;i<3;){
		if(a[i][j]==p)
			cnt++;
		i++;
		j--;
	}
	if(cnt==3)
		return true;
	return false;	
}

bool check(char p,char (*a)[3]){
	if(check_col(p,a))
		return true;
	if(check_row(p,a))
		return true;
	if(check_diag(p,a))
		return true;
	return false;
}


bool win(int x,char (*a)[3]){
	char pat;
	if(x==1){
		pat = 'X';
		return check(pat,a);
	}
	else{
		pat = 'O';
		return check(pat,a);
	}
}

int main(int argc, char *argv[]){
	char mat[3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};
	int bid_1,bid_2,x,y;
	int chip_1 = 100, chip_2 = 100;
	int move = 9;
	while(move>0){
		std::cout<< "player 1 has "<<chip_1<<" chips" << std::endl;
		std::cout<< "player 2 has "<<chip_2<<" chips" << std::endl;
		bid_1 = bid(bid_1,chip_1);
		bid_2 = bid(bid_2,chip_2);
		while(bid_1==bid_2){
			std::cout<<"you have put in the same bid, so you have to rebid" << std::endl;
			bid_1 = bid(bid_1,chip_1,1);
			bid_2 = bid(bid_2,chip_2,2);
		}
		if(bid_1>bid_2){
			chip_1-=bid_1;
			chip_2+=bid_1;
			std::cout << "player 1 has won, please give your move, specify the position row,column" << std::endl;
			std::cin >> x >> y;
			mat[x][y]='X';
		}
		else{
			chip_2-=bid_2;
			chip_1+=bid_2;
			std::cout << "player 2 has won, please give your move, specify the position row,column" << std::endl;
			std::cin >> x >> y;
			mat[x][y]='O';
		}
		display(mat);
		if(win(1,mat)){
			std::cout<<"Player 1 has won" << std::endl;
			break;
		}
		else if(win(2,mat)){
			std::cout<<"Player 2 has won" << std::endl;
			break;
		}
		else	move--;
	}
	return 0;
	if(move==0)
		std::cout<<"the match is a draw"<< std::endl;
}
