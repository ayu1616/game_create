#ifndef _OBJECT_H_
#define _OBJECT_H_

//#include "player.h"

#define BLOCK_WIDTH  32
#define BLOCK_HEIGHT  32

#define SCROLL_SPEED 5

class block
{
public:
	int bl_x, bl_y;
	int bl_gh;
	int set_x, set_y;
	int world;
	bool exist;

	block();

	void Draw();
	void Move();
	void All();
	/*void drawStairs();*/
};

void setStairs(int cnt, int nowcnt, int world, block *stairs);
void drawStairs(block* stairs);
void resetStairs(block *stairs);
void setStairsAll(int cnt, int nowcnt, int world, block* stairs);
void changeWorld(block* stairs);

#endif // !_OBJECT_H_
