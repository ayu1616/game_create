#include "DxLib.h"
#include "myfunc.h"

//bool checkHitBlock(player *p, block *stairs)
//{
//	switch (p->worldchange) {
//
//	case BLACK_WORLD:
//		for (int k = 0; k < 6; k++) {
//
//			int pl_lx = p->pos_x, pl_ly = p->pos_y, pl_w = PL_WIDTH, pl_h = PL_HEIGHT;
//			int bl_lx[6], bl_ly[6], bl_w = BLOCK_WIDTH, bl_h = BLOCK_HEIGHT;
//
//			for (int i = 0; i < 6; i++) {
//				bl_lx[i] = stairs[i].bl_x + stairs[i].set_x;
//				bl_ly[i] = stairs[i].bl_y + stairs[i].set_y;
//			}
//
//			if ((pl_lx + pl_w >= bl_lx[k] && pl_lx + pl_w <= bl_lx[k] + bl_w) &&
//				(pl_ly >= bl_ly[k] && pl_ly < bl_ly[k] + bl_h)
//				||
//				(pl_lx + pl_w >= bl_lx[k] && pl_lx + pl_w <= bl_lx[k] + bl_w) &&
//				(pl_ly + pl_h > bl_ly[k] + 1 && pl_ly + pl_h < bl_ly[k] + bl_h))
//			{
//				p->pos_x -= 5;
//				DrawFormatString(300, 50, 256, "pl_ry:%d,bl_ly[%d]:%d", pl_ly, k, bl_ly[k]);
//				//return true;
//			}
//			else {
//				if (p->jflg == false) {
//					p->pl_speed = 5;
//					p->pos_y += p->pl_speed;
//				}
//				if (p->pos_y >= POS_Y_INIT) {
//					p->pos_y = POS_Y_INIT;
//				}
//			}
//			DrawFormatString(300, 25, 256, "pl_ry:%d,bl_ly[%d]:%d:", pl_ly, 4, bl_ly[4]);
//
//			if ((pl_lx + pl_w - 1 > bl_lx[k] && pl_lx + pl_w - 1 < bl_lx[k] + bl_w) && (pl_ly + pl_h >= bl_ly[k] && pl_ly + pl_h <= bl_ly[k] + bl_h))
//			{
//				p->jflg = false, p->jcount = 0;
//				p->pl_speed = 0;
//				return true;
//				//DrawFormatString(300, 50, 256, "pl_ry:%d,bl_ly[%d]:%d", pl_ly, k, bl_ly[k]);
//			}
//		}
//		//return false;
//		break;
//	case WHITE_WORLD:
//		break;
//	}
//}

bool checkHitSideBlock(player *p, block *stairs)
{
	switch (p->worldchange) {

	case BLACK_WORLD:
		for (int k = 0; k < 6; k++) {

			int pl_lx = p->pos_x, pl_ly = p->pos_y, pl_w = PL_WIDTH, pl_h = PL_HEIGHT;
			int bl_lx[6], bl_ly[6], bl_w = BLOCK_WIDTH, bl_h = BLOCK_HEIGHT;

			for (int i = 0; i < 6; i++) {
				bl_lx[i] = stairs[i].bl_x + stairs[i].set_x;
				bl_ly[i] = stairs[i].bl_y + stairs[i].set_y;
			}

			if ((pl_lx + pl_w >= bl_lx[k] && pl_lx + pl_w <= bl_lx[k] + bl_w) &&
				(pl_ly >= bl_ly[k] && pl_ly < bl_ly[k] + bl_h)
				||
				(pl_lx + pl_w >= bl_lx[k] && pl_lx + pl_w <= bl_lx[k] + bl_w) &&
				(pl_ly + pl_h > bl_ly[k] + 1 && pl_ly + pl_h < bl_ly[k] + bl_h))
			{
				p->pos_x -= 50;
				DrawFormatString(300, 50, 256, "aaaaaaaaaaaaa");
				return true;
			}
			else 
			{
				DrawFormatString(300, 25, 256, "pl_ry:%d,bl_ly[%d]:%d:", pl_ly, 5, bl_ly[5]);

				return false;
			}
		}
		break;

	case WHITE_WORLD:
		return false;
		break;
	}
}

bool checkHitTopBlock(player *p, block *stairs)
{
	switch (p->worldchange) {

	case BLACK_WORLD:
		for (int k = 0; k < 6; k++) {

			int pl_lx = p->pos_x, pl_ly = p->pos_y, pl_w = PL_WIDTH, pl_h = PL_HEIGHT;
			int bl_lx[6], bl_ly[6], bl_w = BLOCK_WIDTH, bl_h = BLOCK_HEIGHT;

			for (int i = 0; i < 6; i++) {
				bl_lx[i] = stairs[i].bl_x + stairs[i].set_x;
				bl_ly[i] = stairs[i].bl_y + stairs[i].set_y;
			}

			if ((pl_lx + pl_w >= bl_lx[k] && pl_lx + pl_w <= bl_lx[k] + bl_w) &&
				(pl_ly >= bl_ly[k] && pl_ly < bl_ly[k] + bl_h)
				||
				(pl_lx + pl_w >= bl_lx[k] && pl_lx + pl_w <= bl_lx[k] + bl_w) &&
				(pl_ly + pl_h > bl_ly[k] + 1 && pl_ly + pl_h < bl_ly[k] + bl_h))
			{
				p->pos_x -= 50;
				DrawFormatString(300, 50, 256, "aaaaaaaaaaaaa");
				return true;
			}
			else
			{
				DrawFormatString(300, 25, 256, "pl_ry:%d,bl_ly[%d]:%d:", pl_ly, 5, bl_ly[5]);

				return false;
			}
		}
		break;

	case WHITE_WORLD:
		return false;
		break;
	}
}

