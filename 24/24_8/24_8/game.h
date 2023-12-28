#pragma once
#include <windows.h>

void drawMap(HDC hdc);

void Left();
void Right();
void Up();
void Down();

void Save();
void Load();

void createWallL();
void createGoldR();
void deleteWallU();
void deleteGoldD();

void midasHandToRight();