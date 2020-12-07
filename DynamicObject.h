﻿#pragma once
#include "Obj.h"

class DynamicObject : public Obj
{
protected:
	int hNumber{ 0 };		//가로이미지수
	int vNumber{ 0 };		//세로이미지수
	POINT cursorPos{ 0,0 };		//현재 마우스위치값저장할변수
	int imageNumber{ 0 };		//연속된 이미지중에 출력할 이미지 번호

	int imageWidth{ 0 };	//이미지 하나의 가로 길이
	int imageHeight{ 0 };	//이미지 하나의 세로 길이

	int printhNumber{ 0 };	//출력될 이미지 가로 번호
	int printvNumber{ 0 };	//출력될 이미지 세로 번호
public:
	DynamicObject();		//이거 나중에 삭제
	DynamicObject(const string name, const ObjectData::POSITION pos, const ObjectData::SIZE size, int hNumber, int vNumber, HBITMAP hBitmap);
	virtual ~DynamicObject();
	virtual void Input() = 0;
	virtual void Update() = 0;
	virtual void Render(HDC hDC, HDC memDc) = 0;

};

