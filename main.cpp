#include<iostream>
using namespace std;
#include<cstdlib>
#include<conio.h>
#include<ctime>
#include<windows.h>
#include<vector>
#define WIDTH 50
#define HEIGHT 25
int x=10;int y=10;
#include "Sanke.h"
#include "Food.h"

Sanke snake({WIDTH/2,HEIGHT/2},1);
Food food;
int score; 
void board(){
	
	COORD snake_pos=snake.get_pos();
	COORD food_pos=food.get_pos();
	vector<COORD>snake_body=snake.get_body();
	
	cout<<"SCORE :"<<score<<"\n\n";
	for(int i=0 ; i<HEIGHT; i++){cout<<"\t\t#";
		for(int j=0; j<WIDTH-2; j++){
			if(i==0 || i==HEIGHT-1 )cout<<"#";
			else if(i==snake_pos.Y &&j+1==snake_pos.X)cout<<"0";
			else if(i==food_pos.Y &&j+1==food_pos.X)cout<<"*";
			else{
				bool isBody=false ; 
				for(int k=0; k<snake_body.size(); k++){
					if(i==snake_body[k].Y &&j+1==snake_body[k].X){
						cout<<"0";
						isBody=true; 
						break;
					}
				}
				if(!isBody)cout<<' ';
			}
		}
		cout<<"#\n";
		
	}	
}
int main(){
	score=0 ; 
	bool gameover=false;
	srand(time(NULL));
	food.gen_food();
	while(!gameover){
		
	board();
	x++;
	if(kbhit()){		
		switch(getch()){	
			case 'w':snake.change_dir('u');break; 
			case 'a':snake.change_dir('l');break; 
			case 's':snake.change_dir('d');break; 
			case 'd':snake.change_dir('r');break; 
		}
	}
	if(snake.eaten(food.get_pos())){
		food.gen_food();
		snake.grow();
		score=score+10;  
	}
	
	snake.move_snake();		
	if(snake.collided())gameover=true; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
	}
	
	return 0;
}
