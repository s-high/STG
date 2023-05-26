#include "DxLib.h"
#include "CKeyFacade.h"
#include "CSceneManager.h"

// WinMain
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
				   LPSTR lpCmdLine, int nCmdShow) {
	// screen init
	SetGraphMode(960, 640, 16);
	ChangeWindowMode(TRUE);
	SetMainWindowText("SPACE SHOOTING");
	SetUseDisplayIndex(2);

	// DxLib init
	if (DxLib_Init() == -1) return -1;

	CSceneManager ISceneManager = CSceneManager();

	SetDrawScreen(DX_SCREEN_BACK);

	int const FRAME_PER_SECOND = 60;

	// loop
	while (1) {
		// init
		ClearDrawScreen();
		SetBackgroundColor(255, 255, 255);


		// code =================
		CKeyFacade::getInstance()->upDate();
		ISceneManager.doScene();
		Sleep(int(1000 / FRAME_PER_SECOND));
		// End ==============================

		// end
		ScreenFlip();
		if (ProcessMessage() < 0) break;
		if (CheckHitKey(KEY_INPUT_LALT) && CheckHitKey(KEY_INPUT_RALT))break;
	}

	DxLib_End();
	return 0;
}