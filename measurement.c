#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// виклик модулів
#include "common.h"
#include "measurement.h"
#include "filling.arr.h"
#include "filling.vector.h"
#include "sort.arr.h"
#include "sort.vector.h"

clock_t Res[measurements_number];

// функція обробки і усереднення значень вимірів часу роботи алгоритма
float MeasurementProcessing()
{
    long int Sum;
    float AverageValue;
    clock_t buf;
    int L = rejected_number, R = measurements_number - 1;
    int k = rejected_number;
    for (int j=0; j < min_max_number; j++)
    {
        for (int i = L; i < R; i++)
        {
            if (Res[i] > Res[i + 1])
            {
                buf = Res[i];
                Res[i] = Res[i + 1];
                Res[i + 1] = buf;
                k = i;
            }
        }
        R = k;
        for (int i = R - 1; i >= L; i--)
        {
            if (Res[i] > Res[i + 1])
            {
                buf = Res[i];
                Res[i] = Res[i + 1];
                Res[i + 1] = buf;
                k = i;
            }
        }
        L = k + 1;
    }
    Sum=0;
    for (int i = rejected_number + min_max_number; i < measurements_number - min_max_number; i++)
        Sum = Sum + Res[i];
    AverageValue = (float)Sum/(float)(measurements_number - 2*min_max_number - rejected_number);

    printf("");
    return AverageValue;
}

// Для Масива Arr3D
void Select7_measurement_arr(char fil) // функція для заповнення масиву вимірів часу (Select7, масив)
{
    for (int i = 0; i < measurements_number; i++)
    {
        if (fil == 'o')
        {
            application_RAM();
            fill_ordered_arr();
            Res[i] = Select7_arr();
            free_RAM();
        }
        else if (fil == 'r')
        {
            application_RAM();
            fill_random_arr();
            Res[i] = Select7_arr();
            free_RAM();
        }
        else if (fil == 'b')
        {
            application_RAM();
            fill_back_arr();
            Res[i] = Select7_arr();
            free_RAM();
        }
    }
}
void Select7_measurement_vec(char fil) // функція для заповнення масиву вимірів часу (Select7, вектор)
{
    for (int i = 0; i < measurements_number; i++)
    {
        if (fil == 'o')
        {
            fillVector_ordered();
            Res[i] = Select7_vec();
        }
        else if (fil == 'r')
        {
            fillVector_random();
            Res[i] = Select7_vec();
        }
        else if (fil == 'b')
        {
            fillVector_back();
            Res[i] = Select7_vec();
        }
    }
}


void Select8_measurement_arr(char fil) // функція для заповнення масиву вимірів часу (Select8, масив)
{
    for (int i = 0; i < measurements_number; i++)
    {
        if (fil == 'o')
        {
            application_RAM();
            fill_ordered_arr();
            Res[i] = Select8_arr();
            free_RAM();
        }
        else if (fil == 'r')
        {
            application_RAM();
            fill_random_arr();
            Res[i] = Select8_arr();
            free_RAM();
        }
        else if (fil == 'b')
        {
            application_RAM();
            fill_back_arr();
            Res[i] = Select8_arr();
            free_RAM();
        }
    }
}
void Select8_measurement_vec(char fil) // функція для заповнення масиву вимірів часу (Select8, вектор)
{
    for (int i = 0; i < measurements_number; i++)
    {
        if (fil == 'o')
        {
            application_RAM();
            fillVector_ordered();
            Res[i] = Select8_vec();
            free_RAM();
        }
        else if (fil == 'r')
        {
            application_RAM();
            fillVector_random();
            Res[i] = Select8_vec();
            free_RAM();
        }
        else if (fil == 'b')
        {
            application_RAM();
            fillVector_back();
            Res[i] = Select8_vec();
            free_RAM();
        }
    }
}

void Shell_2_measurement_arr(char fil)   //функція для заповнення масиву вимірів часу (для №2 методу сортування Шелла, масив)
{
    for (int i = 0; i < measurements_number; i++)
    {
        if (fil == 'o')
        {
            application_RAM();
            fill_ordered_arr();
            Res[i] = Shell_2_arr();
            free_RAM();
        }
        else if (fil == 'r')
        {
            application_RAM();
            fill_random_arr();
            Res[i] = Shell_2_arr();
            free_RAM();
        }
        else if (fil == 'b')
        {
            application_RAM();
            fill_back_arr();
            Res[i] = Shell_2_arr();
            free_RAM();
        }
    }
}
void Shell_2_measurement_vec(char fil)  //функція для заповнення масиву вимірів часу (для №2 методу сортування Шелла, вектор)
{

    if (fil == 'o')
    {
        for (int i = 0; i < measurements_number; i++)
        {
            fillVector_ordered();
            Res[i] = Shell_2_vec();
        }
    }
    else if (fil == 'r')
    {
        for (int i = 0; i < measurements_number; i++)
        {
            fillVector_random();
            Res[i] = Shell_2_vec();
        }
    }
    else if (fil == 'b')
    {
        for (int i = 0; i < measurements_number; i++)
        {
            fillVector_back();
            Res[i] = Shell_2_vec();
        }
    }
}

