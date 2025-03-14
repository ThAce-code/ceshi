#include <ultrasound.h>
#include "intrins.h"

sbit Tx = P1 ^ 0;
sbit Rx = P1 ^ 1;

void Delay12us() //@12.000MHz
{
	unsigned char i;

	_nop_();
	_nop_();
	i = 38;
	while (--i);
}

void Ut_Wave_Init() // ��������ʼ������ ����8��40Mhz�ķ����ź�
{
	unsigned char i;
	for (i = 0; i < 8; i++)
	{
		Tx = 1;
		Delay12us();
		Tx = 0;
		Delay12us();
	}
}

unsigned char Ut_Wave_Data()
{
    unsigned int time;
    CH = CL = 0; // ���PCA�Ĵ�������ֵ
    CCON = 0;    // ��ʼ��PCA���ƼĴ���/PCA��ʱ��ֹͣ/���CF/

    EA = 0;           // �ر����ж�
    Ut_Wave_Init();   // ���ͳ����������ź�
    EA = 1;           // �������ж�
    CR = 1;           // PCA��ʼ����
    while (Rx && !CF); // TF1
            // �ȴ�����
    CR = 0;           // PCAֹͣ����
    if (CF == 0)
    {
        time = CH << 8 | CL; // ��λΪ����
        // L=V*T/2
        return (time * 0.017); // ���صĵ�λ��cm
    }
    else
    {
        CF = 0;
        return 0;
    }
}