#ifndef MEASUREMENT_H_INCLUDED
#define MEASUREMENT_H_INCLUDED
// �������� ������� ����� ���� ������ ���������
#define measurements_number 28
// ʳ������ ��������� ���������� �����
#define rejected_number 2
// ʳ������ ��������� ����� � ��������� ����������.
// ���� � ������� ������� ��������� �����
// � ������������� ����������.
#define min_max_number 3
#include <time.h>
// ����� ������� ���� ������ ���������
extern clock_t Res[measurements_number];
// ������� ������� � ����������� ������� �����
// ���� ������ ���������.
// ������� ���������� �������� ���� ������ ���������
float MeasurementProcessing();

void Select7_measurement_vec(char fil);
void Select8_measurement_vec(char fil);
void Shell_2_measurement_vec(char fil);

void Select7_measurement_arr(char fil);
void Select8_measurement_arr(char fil);
void Shell_2_measurement_arr(char fil);






#endif // MEASUREMENT_H_INCLUDED
