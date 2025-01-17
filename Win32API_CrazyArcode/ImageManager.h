﻿#pragma once
#pragma comment(lib, "Msimg32.lib")
#include <fstream>
#include <algorithm>
#include "DataStruct.h"
#include <ctime>

using namespace std;

class ImageManager
{
private:
	ifstream fin;
	vector<pImageData> lobbyBitmap;
	vector<pImageData> InGameImageInfo;
	vector<pImageData> characterImageData;
	pImageData character[PLAYER_NUMBER + 2]{ NULL };	//선택한 캐릭터이미지둘을 넘겨줄때 사용.. +2는 trapped, die이미지데이터 넣을공간
	pImageData items;
	vector<CharacterStatsData> characterStatsData;	
	CharacterStatsData selectChraracterStat[PLAYER_NUMBER]{ NULL };		//선택한 캐릭터 스텟을 넘겨줄때 사용
	int redIndex = 0;
	int blueIndex = 0;

public:
	ImageManager();
	~ImageManager();

	void LoadImageData();
	void LoadTextImageData(const string path, vector<pImageData>& data);
	void LoadTextImageData(const string path, pImageData& data);		//단일 이미지 전용
	void LoadTextStatsData(const string path, vector<CharacterStatsData>& data);

	const vector<pImageData>& GetLobbyImageData() const;

	const vector<pImageData>& GetInGameImage() const;
	const pImageData* GetCharacterImageData(const SelectData& selectData);
	const pImageData GetItemImageData();

	const CharacterStatsData* GetCharacterStatsData(const SelectData& selectData);
};

