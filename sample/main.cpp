#include<Dxlib.h>
#include<iostream>



int WINAPI WinMain (HINSTANCE, HINSTANCE, LPSTR, int)
{
	
	DxLib::SetMainWindowText(_T("2016187_金子翼"));
	ChangeWindowMode(true);
	SetGraphMode(960, 540, 32);
	DxLib_Init();

	

	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();
		DrawCircle(480, 270, 200, 0xffaaaa);

		ScreenFlip();
		
	}
	DxLib_End();

	//プログラムの終了
}