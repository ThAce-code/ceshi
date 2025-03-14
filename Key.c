#include <Key.h>

unsigned char Key_Read()
{
	unsigned char temp = 0;
	P44 = 0;P42 = 1;P35 = 1;P34 = 1;
	if (P33 == 0) temp = 4;
	if (P32 == 0) temp = 5;
	if (P31 == 0) temp = 6;
	if (P30 == 0) temp = 7;
	P44 = 1;P42 = 0;P35 = 1;P34 = 1;
	if (P33 == 0) temp = 8;
	if (P32 == 0) temp = 9;
	if (P31 == 0) temp = 10;
	if (P30 == 0) temp = 11;
	P44 = 1;P42 = 1;P35 = 0;P34 = 1;
	if (P33 == 0) temp = 12;
	if (P32 == 0) temp = 13;
	if (P31 == 0) temp = 14;
	if (P30 == 0) temp = 15;
	P44 = 1;P42 = 1;P35 = 1;P34 = 0;
	if (P33 == 0) temp = 16;
	if (P32 == 0) temp = 17;
	if (P31 == 0) temp = 18;
	if (P30 == 0) temp = 19;
	
	return temp;
}

unsigned char Key_Read_BTN()
{
	unsigned char temp = 0;
	if(P33 == 0) temp = 4;
	if(P32 == 0) temp = 5;
	if(P31 == 0) temp = 6;
	if(P30 == 0) temp = 7;
	
	return temp;
}
/*
#include <Key.h>

unsigned int Key_Read()
{
	unsigned int temp = 0; // 16bit对应16个按键
	int row, col;

	for (col = 0; col < 4; col++)
	{
		P44 = (col != 0);
		P42 = (col != 1);
		P35 = (col != 2);
		P34 = (col != 3);

		for (row = 0; row < 4; row++)
		{
			if (!(P3 & (0x08 >> row))) // 第0行-P33 第1行-P32 第2行-P31 第3行-P30 顺序相反
				temp |= (1 << (col * 4 + row));
		}
	}
	return temp;
}*/
