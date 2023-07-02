#include "Sanke.h"
Sanke::Sanke(COORD pos,int vel){
	this->pos=pos;
	this->vel=vel; 
	len=1; 
	direction='n';
	body.push_back(pos);
}
void Sanke::change_dir(char dir){
	direction =dir;
}
vector<COORD>Sanke::get_body(){
return body; }
void Sanke::move_snake(){
	switch(direction){
		case 'u':pos.Y-=vel;break;  
		case 'd':pos.Y+=vel;break; 
		case 'l':pos.X-=vel;break; 
		case 'r':pos.X+=vel;break; 
	}
	body.push_back(pos);
	if(body.size()>len)body.erase(body.begin());
}
COORD Sanke::get_pos(){return pos; }

bool Sanke::eaten(COORD food_pos){
	if(food_pos.X==pos.X && food_pos.Y==pos.Y)return true; 
	return false;
}
void Sanke::grow(){len++; }
bool Sanke::collided(){
	if(pos.X<1 || pos.Y<1 ||pos.X>WIDTH -2 ||pos.Y>HEIGHT-2 )return true;
	return false; 
	
}
