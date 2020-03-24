#include "stdafx.h"
#include "MapManager.h"


MapManager::MapManager()
{

}


MapManager::~MapManager()
{

}

HRESULT MapManager::init()
{
#pragma region Scene
	SCENEMANAGER->addScene("Main", new MainMenu);
	SCENEMANAGER->addScene("Map_01", new Map_01);
	SCENEMANAGER->addScene("Map_02", new Map_02);
	SCENEMANAGER->addScene("Map_03", new Map_03);
	SCENEMANAGER->addScene("Map_04", new Map_04);
	SCENEMANAGER->addScene("Map_05", new Map_05);
	SCENEMANAGER->addScene("Map_06", new Map_06);
	SCENEMANAGER->addScene("Map_07", new Map_07);
	SCENEMANAGER->addScene("Map_08", new Map_08);
	SCENEMANAGER->addScene("Map_08_1", new Map_08_1);
	SCENEMANAGER->addScene("Map_09", new Map_09);
	SCENEMANAGER->addScene("Map_10", new Map_10);
	SCENEMANAGER->addScene("Map_11", new Map_11);
	SCENEMANAGER->addScene("Map_12", new Map_12);
	SCENEMANAGER->addScene("Map_13", new Map_13);
	SCENEMANAGER->addScene("Map_13_1", new Map_13_1);
	SCENEMANAGER->addScene("Map_14", new Map_14);
	SCENEMANAGER->addScene("Map_15", new Map_15);
	SCENEMANAGER->addScene("Map_16", new Map_16);
#pragma endregion 

#pragma region Image
	//Map Image
	IMAGEMANAGER->addImage("TestMap_01", "Image/MapImage/Map_01.bmp", 1536, 2142, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("TestMap_02", "Image/MapImage/Map_02.bmp", 6649, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("TestMap_03", "Image/MapImage/Map_03.bmp", 2304, 1389, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("TestMap_04", "Image/MapImage/Map_04.bmp", 5699, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("TestMap_05", "Image/MapImage/Map_05.bmp", 1024, 1852, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("TestMap_06", "Image/MapImage/Map_06.bmp", 1024, 2856, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("TestMap_07", "Image/MapImage/Map_07.bmp", 1024, 828, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("TestMap_08", "Image/MapImage/Map_08.bmp", 1536, 2142, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("TestMap_08_1", "Image/MapImage/Map_08-1.bmp", 1024, 828, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("TestMap_09", "Image/MapImage/Map_09.bmp", 1024, 831, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("TestMap_10", "Image/MapImage/Map_10.bmp", 2849, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("TestMap_11", "Image/MapImage/Map_11.bmp", 2304, 1389, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("TestMap_12", "Image/MapImage/Map_12.bmp", 1024, 2876, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("TestMap_13", "Image/MapImage/Map_13.bmp", 1024, 4924, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("TestMap_13_1", "Image/MapImage/Map_13-1.bmp", 1024, 828, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("TestMap_14", "Image/MapImage/Map_14.bmp", 3072, 1389, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("TestMap_15", "Image/MapImage/Map_15.bmp", 3799, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("TestMap_16", "Image/MapImage/Map_16.bmp", 3180, 768, true, RGB(255, 0, 255));

	//Loop render Image
	IMAGEMANAGER->addImage("Map_01_Cloud", "Image/BackGroundImage/Map_01_Cloud_Loop.bmp", 3072, 2142, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("Map_02_BackGround", "Image/BackGroundImage/Map_02_BackGround.bmp", 6649, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Map_02_Cloud", "Image/BackGroundImage/Map_02_Cloud_Loop.bmp", 6649, 768, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Map_04_Cloud", "Image/BackGroundImage/Map_04_Cloud.bmp", 5698, 768, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("Map_04_BackGround", "Image/BackGroundImage/Map_04_BackGround.bmp", 5698, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Map_05_Cloud", "Image/BackGroundImage/Map_05_Cloud.bmp", 2656, 1852, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("Map_07_Cloud", "Image/BackGroundImage/Map_07_Cloud.bmp", 1024, 828, false, RGB(0, 0, 0));

	//Object Image
	IMAGEMANAGER->addFrameImage("BlueCandle", "Image/ObjectImage/Candlelight.bmp", 42, 54, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("AlchemiFire", "Image/ObjectImage/Alchemi_Fire.bmp", 252, 90, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("TorchLight", "Image/ObjectImage/TorchLight.bmp", 208, 76, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Map_13_Object", "Image/MapImage/Map_13_1 ob.bmp", 172, 216, true, RGB(255, 0, 255));

	//PixelMap Image
	IMAGEMANAGER->addImage("Map_01_Pixel",   "Image/PixelMap/Map_01.bmp",   1536, 2142,  false, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("Map_02_Pixel",   "Image/PixelMap/Map_02.bmp",   6649, 768, false, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("Map_03_Pixel",   "Image/PixelMap/Map_03.bmp",   2304, 1389, false, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("Map_04_Pixel",   "Image/PixelMap/Map_04.bmp",   5699, 768, false, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("Map_05_Pixel",   "Image/PixelMap/Map_05.bmp",   1024, 1852, false, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("Map_06_Pixel",   "Image/PixelMap/Map_06.bmp",   1024, 2856, false, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("Map_07_Pixel",   "Image/PixelMap/Map_07.bmp",   1024, 828, false, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("Map_08_Pixel",   "Image/PixelMap/Map_08.bmp",   1536, 2142, false, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("Map_08_1_Pixel", "Image/PixelMap/Map_09.bmp",   1024, 828, false, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("Map_09_Pixel",   "Image/PixelMap/Map_10.bmp",   1024, 831, false, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("Map_10_Pixel",   "Image/PixelMap/Map_11.bmp",   2849, 768, false, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("Map_11_Pixel",   "Image/PixelMap/Map_12.bmp",   2304, 1389, false, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("Map_12_Pixel",   "Image/PixelMap/Map_13.bmp",   1024, 2876, false, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("Map_13_Pixel",   "Image/PixelMap/Map_14.bmp",   1024, 4924, false, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("Map_13_1_Pixel", "Image/PixelMap/Map_14_1.bmp", 1024, 828, false, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("Map_14_Pixel",   "Image/PixelMap/Map_15.bmp",   3072, 1389, false, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("Map_15_Pixel",   "Image/PixelMap/Map_16.bmp",   3799, 768, false, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("Map_16_Pixel",   "Image/PixelMap/Map_17.bmp",   3180, 768, false, RGB(255, 255, 255));

	//UI Image
	IMAGEMANAGER->addImage("Main_Background", "Image/UIImage/Main_Background.bmp", 1024, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Main_Logo", "Image/UIImage/Main_Logo.bmp", 911, 412, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Main_Konami", "Image/UIImage/Main_Konami.bmp", 960, 35, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Main_Pressbutton", "Image/UIImage/Main_PressButton.bmp", 712, 25, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Main_StartLight", "Image/UIImage/Main_StartLight.bmp", 1024, 768, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("Main_StartButton", "Image/UIImage/Main_StartButton.bmp", 421, 44, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Main_ExitButton", "Image/UIImage/Main_ExitButton.bmp", 372, 44, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Main_SelectBat", "Image/UIImage/Main_SelectBat.bmp", 153, 48, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Character_Hud", "Image/UIImage/character_Interface.bmp", 390, 113, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Character_Hud_02", "Image/UIImage/character_Interface_State.bmp", 406, 58, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("UIStart", "Image/UIImage/Ui_Start.bmp", 1024, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Interface_Equip", "Image/UIImage/Character_Interface_Equip.bmp", 1024, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Interface_Spells", "Image/UIImage/Character_Interface_Spells.bmp", 1024, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Interface_Relics", "Image/UIImage/Character_Interface_Relics.bmp", 1024, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Interface_Familiars", "Image/UIImage/Character_Interface_Familiars.bmp", 1024, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Equip_info", "Image/UIImage/Interface_EquipInfo.bmp", 1024, 768, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Spells_info", "Image/UIImage/Interface_Spells.bmp", 1024, 768, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Relics_info", "Image/UIImage/Interface_Relics.bmp", 1024, 768, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Familiars_info", "Image/UIImage/Interface_Familiars.bmp", 1024, 768, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Select_Bar_01", "Image/UIImage/Choose_Bar_01.bmp", 291, 34, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Select_Bar_02", "Image/UIImage/Choose_Bar_02.bmp", 350, 37, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("MiniMap", "Image/UIImage/MiniMap.bmp", 1024, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Item_Name_01", "Image/UIImage/Sword.bmp", 85, 17, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Item_Name_02", "Image/UIImage/Firebrand.bmp", 140, 17, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Number_01", "Image/UIImage/NumberImage/Num1.bmp", 13, 28, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Number_02", "Image/UIImage/NumberImage/Num2.bmp", 15, 28, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Number_03", "Image/UIImage/NumberImage/Num3.bmp", 15, 28, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Number_04", "Image/UIImage/NumberImage/Num4.bmp", 15, 28, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Number_05", "Image/UIImage/NumberImage/Num5.bmp", 15, 28, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Number_06", "Image/UIImage/NumberImage/Num6.bmp", 15, 28, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Number_07", "Image/UIImage/NumberImage/Num7.bmp", 15, 28, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Number_08", "Image/UIImage/NumberImage/Num8.bmp", 15, 28, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Number_09", "Image/UIImage/NumberImage/Num9.bmp", 15, 28, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Number_00", "Image/UIImage/NumberImage/Num0.bmp", 15, 28, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("DamageNum_00", "Image/UIImage/DamageNumber/Num0.bmp", 13, 18, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("DamageNum_01", "Image/UIImage/DamageNumber/Num1.bmp", 13, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("DamageNum_02", "Image/UIImage/DamageNumber/Num2.bmp", 13, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("DamageNum_03", "Image/UIImage/DamageNumber/Num3.bmp", 13, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("DamageNum_04", "Image/UIImage/DamageNumber/Num4.bmp", 13, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("DamageNum_05", "Image/UIImage/DamageNumber/Num5.bmp", 13, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("DamageNum_06", "Image/UIImage/DamageNumber/Num6.bmp", 13, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("DamageNum_07", "Image/UIImage/DamageNumber/Num7.bmp", 13, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("DamageNum_08", "Image/UIImage/DamageNumber/Num8.bmp", 13, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("DamageNum_09", "Image/UIImage/DamageNumber/Num9.bmp", 13, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("EDamageNum_00", "Image/UIImage/DamageNumber/Num0R.bmp", 13, 18, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("EDamageNum_01", "Image/UIImage/DamageNumber/Num1R.bmp", 13, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("EDamageNum_02", "Image/UIImage/DamageNumber/Num2R.bmp", 13, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("EDamageNum_03", "Image/UIImage/DamageNumber/Num3R.bmp", 13, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("EDamageNum_04", "Image/UIImage/DamageNumber/Num4R.bmp", 13, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("EDamageNum_05", "Image/UIImage/DamageNumber/Num5R.bmp", 13, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("EDamageNum_06", "Image/UIImage/DamageNumber/Num6R.bmp", 13, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("EDamageNum_07", "Image/UIImage/DamageNumber/Num7R.bmp", 13, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("EDamageNum_08", "Image/UIImage/DamageNumber/Num8R.bmp", 13, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("EDamageNum_09", "Image/UIImage/DamageNumber/Num9R.bmp", 13, 20, true, RGB(255, 0, 255));

	//EffectImage
	EFFECTMANAGER->addEffect("getItem", "Image/EffectImage/Light_01.bmp", 186, 62, 62, 62, 1, 0.2f, 5);
	EFFECTMANAGER->addEffect("Attack_Effect_01", "Image/EffectImage/Attack_01_Effect.bmp", 120, 30, 30, 30, 1, 0.2f, 5);
	EFFECTMANAGER->addEffect("Attack_Effect_02", "Image/EffectImage/Attack_02_Effect.bmp", 120, 30, 30, 30, 1, 0.2f, 5);
	EFFECTMANAGER->addEffect("Dead_01", "Image/EffectImage/Death_01.bmp", 1240, 128, 124, 128, 1, 0.2f, 5);
	EFFECTMANAGER->addEffect("Dead_02", "Image/EffectImage/Death_02.bmp", 924, 128, 132, 128, 1, 0.2f, 5);
	EFFECTMANAGER->addEffect("Dead_03", "Image/EffectImage/Death_03.bmp", 816, 99, 102, 99, 1, 0.2f, 5);
	EFFECTMANAGER->addEffect("Dead_04", "Image/EffectImage/Death_04.bmp", 1320, 253, 165, 253, 1, 0.2f, 5);
	EFFECTMANAGER->addEffect("Dead_05", "Image/EffectImage/Death_05.bmp", 476, 33, 34, 33, 1, 0.2f, 5);

#pragma endregion

	SCENEMANAGER->changeScene("Main");
	_sceneChange = 1;

	cout << " Current Scene Number : " << _sceneChange << endl;


	return S_OK;
}

void MapManager::update()
{
	SCENEMANAGER->update();


	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		_sceneChange++;
	
		string sceneNum = to_string(_sceneChange);
	
		if (_sceneChange > 9) SCENEMANAGER->changeScene("Map_" + sceneNum);
		else
		{
			SCENEMANAGER->changeScene("Map_0" + sceneNum);
		}

		cout << " Current Scene Number : " <<  _sceneChange << endl;
		if (_sceneChange > 16) _sceneChange = 0;


	}

	if (KEYMANAGER->isOnceKeyDown('O'))
	{
		SCENEMANAGER->changeScene("Map_08_1");
	}

	//if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	//{
	//	POINT pos;
	//	::GetCursorPos(&pos);  //마우스 포인터 좌표 가져와줌
	//	::ScreenToClient(_hWnd, &pos); // api창안에서만 가져올수있게 보정
	//	//카메라 DC 좌표 얻기.
	//	cout << "WorldDC X : " << pos.x + CAMERAMANAGER->get_CameraX() << "," << "WorldDC Y : "  << pos.y + CAMERAMANAGER->get_CameraY() << endl;
	//	//MemDC 좌표 얻기.
	//	//cout << "MemDC " << "X : " << pos.x << ","<< "Y : " << pos.y << endl;
	//}
}

void MapManager::release()
{
	SCENEMANAGER->release();
}

void MapManager::render()
{
	SCENEMANAGER->render();

}
