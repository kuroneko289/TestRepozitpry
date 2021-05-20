#include<Dxlib.h>
#include"GameBox.h"
#include<cmath>

bool IsHit(const Rect& rcA, const Rect& rcB)
{
	//1�܂�X�����𒲂ׂ�
	// 1-1���S�ƒ��S��X���W�̍����̐�Βl���Ƃ�
	// 1-2���ꂼ��̕��𑫂������̂�1-1���r����
	// 1-3���𑫂�������1-2��荷��1-1���ł����Ȃ�false��Ԃ�

	if (fabsf(rcA.center.x - rcB.center.x) > rcA.w + rcB.w)
	{
		return false;
	}

	if (fabsf(rcA.center.y - rcB.center.y) > rcA.h + rcB.h)
	{
		return false;
	}

	return true;
}

int WINAPI WinMain (HINSTANCE, HINSTANCE, LPSTR, int)
{
	
	SetMainWindowText(_T("2016187_���q��"));
	ChangeWindowMode(true);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	Rect rcA = { 100,100,75,75 };
	Rect rcB = { 400,200,75,125 };

	char keystate[256];

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();
		GetHitKeyStateAll(keystate);
		constexpr float speed = 4.0f;
		if (keystate[KEY_INPUT_RIGHT])
		{
			rcA.center.x += speed;
		}

		if (keystate[KEY_INPUT_LEFT])
		{
			rcA.center.x -= speed;
		}

		if (keystate[KEY_INPUT_UP])
		{
			rcA.center.y -= speed;
		}

		if (keystate[KEY_INPUT_DOWN])
		{
			rcA.center.y += speed;
		}

		UINT32 color = 0xffffff;

		if (IsHit(rcA, rcB))
		{
			color = 0xffaaaa;
			float diffX = rcB.center.x - rcA.center.x;
			float diffY = rcB.center.y - rcA.center.y;
			float signX = diffX < 0 ? -1.0f : 1.0f;
			float signY = diffY < 0 ? -1.0f : 1.0f;
			diffX = (rcA.w + rcB.w) - fabsf(rcA.center.x - rcB.center.x);
			diffY = (rcA.h + rcB.h) - fabsf(rcA.center.y - rcB.center.y);
			if (diffX < diffY)
			{
				rcA.center.x -= signX * diffX;
			}
			else
			{
				rcA.center.y -= signY * diffY;
			}
		}


		//�Z�`A  
		DrawBox(rcA.Left(), rcA.Top(),
			rcA.Right(), rcA.Bottom(), color, true);

		//�Z�`B  
		DrawBox(rcB.Left(), rcB.Top(),
			rcB.Right(), rcB.Bottom(), color, true);

		ScreenFlip();
	}
	DxLib_End();
	return 0;
	//�v���O�����̏I��
}