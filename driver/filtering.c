#include "filtering.h"
#define N 5 // �˲����ڴ�С

pdata float median_data_array[N] = {0};    // ������ֵ�˲��Ĵ�������
pdata unsigned char median_index = 0;      // ��ǰ���ݵ���������ֵ�˲���
pdata unsigned char median_data_count = 0; // ��ֵ�˲�����ǰ���е���������

// ��ֵ�˲�������
// ������new_data - �µ���������
// ����ֵ���˲��������
float Median_Filter(float new_data)
{
  float sorted_data[N];
  float temp;
  unsigned char i, j;

  median_data_array[median_index] = new_data; // �洢�����ݵ���ֵ�˲�����
  median_index = (median_index + 1) % N;      // ��������
  if (median_data_count < N)
    median_data_count++; // ������ֵ�˲������������ݵ�����

  // �������ݵ���ʱ����
  for (i = 0; i < median_data_count; i++)
  {
    sorted_data[i] = median_data_array[i];
  }

  // ð������
  for (i = 0; i < median_data_count - 1; i++)
  {
    for (j = 0; j < median_data_count - i - 1; j++)
    {
      if (sorted_data[j] > sorted_data[j + 1])
      {
        // ����Ԫ��λ��
        temp = sorted_data[j];
        sorted_data[j] = sorted_data[j + 1];
        sorted_data[j + 1] = temp;
      }
    }
  }
  return sorted_data[median_data_count / 2]; // ������ֵ
}

pdata unsigned char mean_data_array[N] = {0}; // ���ڻ���ƽ���˲��Ĵ�������
pdata float mean_sum = 0.0f;                  // ����ƽ���˲�����ǰ���ݺ�
pdata unsigned char mean_index = 0;           // ��ǰ���ݵ�����������ƽ���˲���
pdata unsigned char mean_data_count = 0;      // ����ƽ���˲�����ǰ���е���������

// ����ƽ���˲�������
// ������new_data - �µ���������
// ����ֵ���˲��������
float Moving_Average_Filter(unsigned char new_data)
{
  mean_sum -= mean_data_array[mean_index]; // ��ȥ����ƽ�������б��滻������ֵ
  mean_data_array[mean_index] = new_data;  // �������ݴ��뻬��ƽ������
  mean_sum += new_data;                    // ���´��������ݵ��ܺ�
  mean_index = (mean_index + 1) % N;       // ��������
  if (mean_data_count < N)
    mean_data_count++;               // ���ӻ���ƽ���˲������������ݵ�����
  return mean_sum / mean_data_count; // ����ƽ��ֵ
}
