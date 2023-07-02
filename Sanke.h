#ifndef SANKE_H
#define SANKE_H
#include<windows.h>
#define WIDTH 50
#define HEIGHT 25
#include<vector>
using namespace std; 
class Sanke
{
	private:
		COORD pos;
		int len; 
		int vel; 
		char direction ;
		vector<COORD>body; 
		
	public:
		Sanke(COORD pos,int vel);
		void change_dir(char dir);
		void move_snake();									
		COORD get_pos();
		
		bool eaten(COORD food_pos);
		void grow();
		bool collided();
		vector<COORD>get_body(); 
};

#endif
