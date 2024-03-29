﻿#include <iostream>
#include "mylib.h"
#define MAX 100
using namespace std;
int sl = 7;
//================ khu vuc khai bao nguyen mau ham ============
void ve_tuong_tren();
void ve_tuong_duoi();
void ve_tuong_phai();
void ve_tuong_duoi();
void ve_tuong();
void khoi_tao_ran(int toadox[], int toadoy[]);
void xoa_du_lieu_cu(int toadox[], int toadoy[]);
void ve_ran(int toadox[], int toadoy[]);
void xu_ly_ran(int toadox[], int toadoy[], int x, int y, int& xqua, int& yqua);
void them(int a[], int x);
void xoa(int a[], int vt);
bool kt_ran_cham_tuong(int x0, int y0);
bool kt_ran_cham_duoi(int toadox[], int toadoy[]);
bool kt_ran(int toadox[], int toadoy[]);
void tao_qua(int& xqua, int& yqua, int toadox[], int toadoy[]);
bool kt_ran_de_qua(int xqua, int yqua, int toadox[], int toadoy[]);
bool kt_ran_an_qua(int xqua, int yqua, int x0, int y0);
//============= ham main - xu ly chinh ==============
int main()
{
	//---------------
	bool gameover = false;
	int toadox[MAX], toadoy[MAX];
	ve_tuong();
	khoi_tao_ran(toadox, toadoy);
	ve_ran(toadox, toadoy);
	//===================== kiem tra va tao qua ==============
	srand(time(NULL));
	int xqua = 0, yqua = 0;
	//tao qua
	tao_qua(xqua, yqua, toadox, toadoy);
	int x = 50, y = 13;// dinh hinh vi tri can di chuyen cho ran
	int check = 2;
	while (gameover == false)
	{
		//system("cls");
		//========= backspace
		xoa_du_lieu_cu(toadox, toadoy);
		// 0 : di xuong
		//1: di len
		//2: qua phai
		//3: trai
		//========= dieu khien
		if (_kbhit())
		{
			char kitu = _getch();
			if (kitu == -32)
			{
				kitu = _getch();
				if (kitu == 72 && check != 0)//di len
				{
					check = 1;
				}
				else if (kitu == 80 && check != 1)//di xuong
				{
					check = 0;
				}
				else if (kitu == 77 && check != 3)//di phai
				{
					check = 2;
				}
				else if (kitu == 75 && check != 2)//di trai
				{
					check = 3;
				}
			}
		}
		//========= thuc hien di chuyen
		if (check == 0)
		{
			y++;//di xuong
		}
		else if (check == 1)
		{
			y--;//di len
		}
		else if (check == 2)
		{
			x++;//di qua phai
		}
		else if (check == 3)
		{
			x--;//di qua trai	
		}
		xu_ly_ran(toadox, toadoy, x, y, xqua, yqua);
		//========== kiem tra =========
		gameover = kt_ran(toadox, toadoy);
		Sleep(150);
	}
	_getch();
	return 0;
}
//============ khu vuc dinh nghia ham =============
void ve_ran(int toadox[], int toadoy[])
{
	for (int i = 0; i < sl; i++)
	{
		gotoXY(toadox[i], toadoy[i]);
		if (i == 0)
		{
			cout << "0";
		}
		else
		{
			cout << "o";
		}
	}
}
void xu_ly_ran(int toadox[], int toadoy[], int x, int y, int& xqua, int& yqua)
{
	//b1: them toa do moi vao dau mang
	them(toadox, x);
	them(toadoy, y);
	if (kt_ran_an_qua(xqua, yqua, toadox[0], toadoy[0]) == false)
	{
		//b2: xoa toa do cuoi mang
		xoa(toadox, sl - 1);
		xoa(toadoy, sl - 1);

	}
	else
	{
		tao_qua(xqua, yqua, toadox, toadoy);
	}
	//b3: ve ran
	ve_ran(toadox, toadoy);
}
void them(int a[], int x)
{
	for (int i = sl; i > 0; i--)
	{
		a[i] = a[i - 1];
	}
	a[0] = x;
	sl++;
}
void xoa(int a[], int vt)
{
	for (int i = vt; i < sl; i++)
	{
		a[i] = a[i + 1];
	}
	sl--;
}
bool kt_ran_cham_tuong(int x0, int y0)
{
	//ran cham tuong tren
	if (y0 == 1 && (x0 >= 10 && x0 <= 100))
	{
		return true;//gameover
	}
	//ran cham tuong duoi
	else if (y0 == 26 && (x0 >= 10 && x0 <= 100))
	{
		return true;//gameover
	}
	//ran cham tuong phai
	else if (x0 == 100 && (y0 >= 1 && y0 <= 26))
	{
		return true;//gameover
	}
	//ran cham tuong trai
	else if (x0 == 10 && (y0 >= 1 && y0 <= 26))
	{
		return true;//gameover
	}
	return false;
}
bool kt_ran_cham_duoi(int toadox[], int toadoy[])
{
	for (int i = 1; i < sl; i++)
	{
		if ((toadox[0] == toadox[i]) && (toadoy[0] == toadoy[i]))
		{
			return true;//gameover
		}
	}
	return false;
}
