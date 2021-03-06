#include "DxLib.h"

#include "player.h"
#include "object.h"
#include "myfunc.h"

//block *bl = new block();
//player *pl = new player();

player::player()
{
	pl_gh = LoadGraph("Data/Image/player.png");
	pos_x = (int)(POS_X_INIT)+300;
	pos_y = (int)(POS_Y_INIT);

	//pl_speed = pos_x;

	anim_x = 0; anim_cnt = 0;
	y_prev = 0, y_temp = 0;
	jcount = 0, jtimer = 0;

	worldchange = BLACK_WORLD;

	jflg = false;
	wcflg = false;
	changef = false;
}

void player::Jump()
{
	//ジャンプ処理
	switch (worldchange) {

	case BLACK_WORLD:
		//checkHitBlock(pos_x, pos_y, p);
		if (jflg == true) {

			y_temp = pos_y;
			pos_y += (pos_y - y_prev) + 1;
			y_prev = y_temp;

			if (pos_y <= 150 && changef == false)
				wcflg = true;

			if (pos_y >= POS_Y_INIT/* && changef == false*/) {
				if (wcflg == true && changef == false) {
					worldchange = WHITE_WORLD;
					changef = true;
				}
				else {
					pos_y = POS_Y_INIT;
					jcount = 2, jflg = false;
				}
			}
		}

		if (jcount >= 2) {
			jtimer++;
			//次のジャンプまでの間隔をのばす//
			if (jtimer >= 11)
				jtimer = 0, jcount = 0;
		}

		if (CheckHitKey(KEY_INPUT_SPACE) && jflg == false && jcount == 0) {
			jcount = 1;
			jflg = true, changef = false;
			y_prev = pos_y;
			pos_y -= 15;
		}
		if (CheckHitKey(KEY_INPUT_NUMPADENTER))
			worldchange = WHITE_WORLD;

		break;

	case WHITE_WORLD:
		//checkHitBlock(pos_x, pos_y, p);
		if (jflg == true) {

			y_temp = pos_y;
			pos_y += (pos_y - y_prev) - 1;
			y_prev = y_temp;

			if (pos_y >= 250 && changef == false)
				wcflg = false;

			if (pos_y <= POS_Y_INIT) {
				if (wcflg == false && changef == false) {
					worldchange = BLACK_WORLD;
					changef = true;
				}
				else {
					pos_y = POS_Y_INIT + 32;
					jcount = 2, jflg = false;
				}
			}
		}

		if (jcount >= 2) {
			jtimer++;
			//次のジャンプまでの間隔をのばす//
			if (jtimer >= 11)
				jtimer = 0, jcount = 0;
		}

		if (CheckHitKey(KEY_INPUT_SPACE) && jflg == false && jcount == 0) {
			jcount = 1;
			jflg = true, changef = false;
			y_prev = pos_y;
			pos_y += 15;
		}

		if (CheckHitKey(KEY_INPUT_NUMPADENTER))
			worldchange = BLACK_WORLD;
		break;
	}
}

void player::Move(player *pl,block *bl)
{
	if (checkHitSideBlock(pl, bl)) {
		pl->pos_x -= 100;
	}
	else {

	}
}

void player::setPlayerPos()
{
	if (jflg == false)
	{

		if (worldchange == 0)
		{
			//if (!checkHitSideBlock(pl, bl)) {

				pos_x = (int)(POS_X_INIT);
				pos_y = (int)(POS_Y_INIT);
			//}
		}
		else
		{
			//if (!checkHitSideBlock(pl, bl)) {
				pos_x = (int)(POS_X_INIT);
				pos_y = (int)(POS_Y_INIT)+32;
			//}
		}
	}
}

void player::Draw()
{
	//タイトル画面用アニメーションになるかも？
	anim_cnt++;
	anim_x = anim_cnt / 10 % 4;
	if (worldchange == BLACK_WORLD) {
		DrawRectGraph(pos_x, pos_y, 32 * anim_x, 0, 32, 32, pl_gh, true);
	}
	else {
		DrawRectGraph(pos_x, pos_y, 32 * anim_x, 32, 32, 32, pl_gh, true);
	}
	DrawFormatString(300, 100, 256, "pos_x:%d,pos_y:%d,world:%d,change:%d,%d,%d", pos_x, pos_y, worldchange, changef,jflg,jcount);

}

