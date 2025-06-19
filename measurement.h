#ifndef MEASUREMENT_H_INCLUDED
#define MEASUREMENT_H_INCLUDED
// Загальна кількість вимірів часу роботи алгоритма
#define measurements_number 28
// Кількість відкинутих початкових вимірів
#define rejected_number 2
// Кількість відкинутих вимірів з мінімільними значеннями.
// Вона ж дорівнює кількості відкинутих вимірів
// з максимальними значеннями.
#define min_max_number 3
#include <time.h>
// Масив значень часу роботи алгоритма
extern clock_t Res[measurements_number];
// Функція обробки і усереднення значень вимірів
// часу роботи алгоритма.
// Повертає усереднене значення часу роботи алгоритма
float MeasurementProcessing();

void Select7_measurement_vec(char fil);
void Select8_measurement_vec(char fil);
void Shell_2_measurement_vec(char fil);

void Select7_measurement_arr(char fil);
void Select8_measurement_arr(char fil);
void Shell_2_measurement_arr(char fil);






#endif // MEASUREMENT_H_INCLUDED
