#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "object.h"

#define PL_WIDTH 24
//#define PL_HEIGHT 32
#define PL_HEIGHT 29

#define BLACK_WORLD 0
#define WHITE_WORLD 1

#define POS_X_INIT 960 * 0.25 
#define POS_Y_INIT 540 * 0.5-32

//TODO ジャンプ連続したら浮くので接地するまで次のジャンプ無効にする
//反転ジャンプ実装

class player
{
public:
	int pos_x, pos_y;
	int pl_gh;
	int anim_cnt, anim_x;
	int pl_speed;

	int y_prev, y_temp;
	int jcount, jtimer;

	int worldchange;

	bool jflg;
	bool wcflg;
	bool changef;

	player();
	
	void Jump();

	void Move(player*, block*);

	void setPlayerPos();

	void Draw();
};


#endif // !_PLAYER_H_

