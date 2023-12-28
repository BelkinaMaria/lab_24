#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include "game.h"


#define N 10
#define M 15
// ���� �����:
// 0 - ��������
// 1 - �����
// 2 - �����������
// 3 - ������
int map[N][M] = {
    {0, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0,   0, 0, 0, 0, 3,   0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0,   0, 0, 0, 0, 3,   0, 0, 0, 0, 0},
    {0, 0, 0, 3, 3,   3, 3, 0, 0, 0,   3, 3, 0, 0, 0},
    {0, 0, 0, 0, 0,   0, 3, 0, 0, 0,   3, 3, 0, 0, 0},

    {0, 0, 0, 0, 0,   0, 3, 3, 3, 0,   0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0,   0, 0, 0, 3, 0,   2, 0, 0, 2, 0},
    {0, 0, 0, 0, 0,   0, 0, 2, 0, 0,   2, 0, 0, 2, 0},
    {0, 0, 0, 0, 0,   0, 2, 2, 2, 2,   2, 2, 2, 2, 0},
    {0, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 0, 0, 0, 0}
};

#define WIDTH 30
#define HEIGHT 20

void drawMap(HDC hdc) {
    // ����� ��� ������� ����
    HBRUSH hBrushEmptyCell = CreateSolidBrush(RGB(200, 200, 200)); // �����
    // ����� ��� ���� � �������
    HBRUSH hBrushGold = CreateSolidBrush(RGB(255, 255, 0)); // ������
    // ����� ��� �����
    HBRUSH hBrushWall = CreateSolidBrush(RGB(0, 0, 0)); // ������
    // ����� ��� ������
    HBRUSH hBrushMan = CreateSolidBrush(RGB(0, 0, 255)); // �����

    // ���� �����:
    // 0 - ��������
    // 1 - �����
    // 2 - �����������
    // 3 - ������
    HBRUSH brush[4] = { hBrushEmptyCell, hBrushMan, hBrushWall, hBrushGold };
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {

            int x1 = j * WIDTH;
            int x2 = (j + 1) * WIDTH;
            int y1 = i * HEIGHT;
            int y2 = (i + 1) * HEIGHT;

            RECT r = { x1, y1, x2, y2 };
            FillRect(hdc, &r, brush[map[i][j]]);
        }
    }


    // ��� ����� �������!!!
    for (i = 0; i < 4; i++)
        DeleteObject(brush[i]);
}

int steps = 0;
int gold = 0;

//�����
void Left() {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 1; j < M; j++) {
            if (map[i][j] == 1) { // ���� � map[i][j]  �����
                if (map[i][j - 1] == 0) { // ���� ����� �� ������ - ������ ������
                    map[i][j - 1] = 1;
                    map[i][j] = 0;
                    steps++;
                }
                else if (map[i][j - 1] == 3) {// ���� ����� �� ������ - ������
                    map[i][j - 1] = 1;
                    map[i][j] = 0;
                    steps++;
                    gold++;
                }
            }
        }
    }
}

//������
void Right() {
    int i, j;

    for (i = 0; i < N; i++) {

        for (j = M - 2; j >= 0; j--) {

            if (map[i][j] == 1) { // ���� � map[i][j]  �����
                if (map[i][j + 1] == 0) {
                    map[i][j + 1] = 1;
                    map[i][j] = 0;
                    steps++;
                }
                else if (map[i][j + 1] == 3) {
                    map[i][j + 1] = 1;
                    map[i][j] = 0;
                    steps++;
                    gold++;
                }
            }
        }
    }
}

//�����
void Up() {
    int i, j;

    for (i = 1; i < N; i++) {

        for (j = 0; j < M; j++) {

            if (map[i][j] == 1) { // ���� � map[i][j]  �����
                if (map[i - 1][j] == 0) {
                    map[i - 1][j] = 1;
                    map[i][j] = 0;
                    steps++;
                }
                else if (map[i - 1][j] == 3) {
                    map[i - 1][j] = 1;
                    map[i][j] = 0;
                    steps++;
                    gold++;
                }
            }
        }
    }
}

//����
void Down() {
    int i, j;

    for (i = N - 2; i >= 0; i--) {

        for (j = 0; j < M; j++) {

            if (map[i][j] == 1) { // ���� � map[i][j]  �����
                if (map[i + 1][j] == 0) {
                    map[i + 1][j] = 1;
                    map[i][j] = 0;
                    steps++;
                }
                else if (map[i + 1][j] == 3) {
                    map[i + 1][j] = 1;
                    map[i][j] = 0;
                    steps++;
                    gold++;
                }
            }
        }
    }
}

//���������.
void Save() {
    //�������� ����
    FILE* fout;
    fout = fopen("C:\\Users\\casey\\OneDrive\\������� ����\\������\\��������������������������������������\\21\\file\\game.txt", "wt");
    if (fout == NULL) {
        printf("�������� ���� �� ��������.");
        return;
    }

    fprintf(fout, "%d ", N);
    fprintf(fout, "%d\n", M);
    int i, j;

    for (i = 0; i < N; i++) {

        for (j = 0; j < M; j++) {
            fprintf(fout, "%d ", map[i][j]);
        }
        fprintf(fout, "\n");
    }

    fprintf(fout, "%d ", steps);
    fprintf(fout, "%d", gold);

    fclose(fout);
}

//���������.
void Load() {
    //������� ����
    FILE* fin;
    fin = fopen("C:\\Users\\casey\\OneDrive\\������� ����\\������\\��������������������������������������\\21\\file\\game.txt", "rt");
    if (fin == NULL) {
        printf("������� ���� �� ��������.");
        return;
    }

    int n, m;
    fscanf(fin, "%d", &n);
    fscanf(fin, "%d", &m);
    int i, j;

    for (i = 0; i < n; i++) {

        for (j = 0; j < m; j++) {
            fscanf(fin, "%d", &map[i][j]);
        }

    }

    fscanf(fin, "%d", &steps);
    fscanf(fin, "%d", &gold);

    fclose(fin);
}

void createWallL() {
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < M; j++) {
            if (map[i][j] == 1)
                map[i][j - 1] = 2;
        }
    }
}

void createGoldR() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M - 1; j++) {
            if (map[i][j] == 1)
                map[i][j + 1] = 3;
        }
    }
}

void deleteWallU() {
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            if (map[i][j] == 1 and map[i - 1][j] == 2)
                map[i - 1][j] = 0;
        }
    }
}

void deleteGoldD() {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 1; j < M; j++) {
            if (map[i][j] == 1 and map[i + 1][j] == 3)
                map[i + 1][j] = 0;
        }
    }
}

void doMidasHand(int i, int j) {
    if (map[i][j] == 2) {
        map[i][j] = 3;
        if (i > 0) doMidasHand(i - 1, j);
        if (i < N - 1) doMidasHand(i + 1, j);
        if (j > 0) doMidasHand(i, j - 1);
        if (j < M - 1) doMidasHand(i, j + 1);

    }
}

void midasHandToRight() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++){
            if (map[i][j] == 1 && map[i][j + 1] == 2) {
                doMidasHand(i, j + 1);
            }
        }
    }
}