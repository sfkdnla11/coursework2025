#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ������ ������
#include "common.h"
#include "measurement.h"
#include "filling.arr.h"
#include "filling.vector.h"
#include "sort.arr.h"
#include "sort.vector.h"

void table()
{
    float Ordered, Random, Back_Ordered;

    printf("\t\t\t  Table for the array: P = %d, M = %d, N = %d\n\n", P, M, N);
    printf("\t\t\tOrdered\t\t\tRandom Ordered\t\tBack Ordered\n\n");

    // Shell_2 (�����)
    Shell_2_measurement_arr('o');
    Ordered = MeasurementProcessing();
    Shell_2_measurement_arr('r');
    Random = MeasurementProcessing();
    Shell_2_measurement_arr('b');
    Back_Ordered = MeasurementProcessing();
    printf("Shell_2\t\t\t%f\t\t%f\t\t%f\n\n", Ordered, Random, Back_Ordered);

    // Select7 (�����)
    Select7_measurement_arr('o');
    Ordered = MeasurementProcessing();
    Select7_measurement_arr('r');
    Random = MeasurementProcessing();
    Select7_measurement_arr('b');
    Back_Ordered = MeasurementProcessing();
    printf("Select7\t\t\t%f\t\t%f\t\t%f\n\n", Ordered, Random, Back_Ordered);

    // Select8 (�����)
    Select8_measurement_arr('o');
    Ordered = MeasurementProcessing();
    Select8_measurement_arr('r');
    Random = MeasurementProcessing();
    Select8_measurement_arr('b');
    Back_Ordered = MeasurementProcessing();
    printf("Select8\t\t\t%f\t\t%f\t\t%f\n\n", Ordered, Random, Back_Ordered);

    // ������� ��� �������
    printf("\t\t\t\t  Table for the vector: N = %d\n\n", VECTOR_SIZE);
    printf("\t\t\tOrdered\t\t\tRandom Ordered\t\tBack Ordered\n\n");

    // Shell_2 (������)
    Shell_2_measurement_vec('o');
    Ordered = MeasurementProcessing();
    Shell_2_measurement_vec('r');
    Random = MeasurementProcessing();
    Shell_2_measurement_vec('b');
    Back_Ordered = MeasurementProcessing();
    printf("Shell_2\t\t\t%f\t\t%f\t\t%f\n\n", Ordered, Random, Back_Ordered);

    // Select7 (������)
    Select7_measurement_vec('o');
    Ordered = MeasurementProcessing();
    Select7_measurement_vec('r');
    Random = MeasurementProcessing();
    Select7_measurement_vec('b');
    Back_Ordered = MeasurementProcessing();
    printf("Select7\t\t\t%f\t\t%f\t\t%f\n\n", Ordered, Random, Back_Ordered);

    // Select8 (������)
    Select8_measurement_vec('o');
    Ordered = MeasurementProcessing();
    Select8_measurement_vec('r');
    Random = MeasurementProcessing();
    Select8_measurement_vec('b');
    Back_Ordered = MeasurementProcessing();
    printf("Select8\t\t\t%f\t\t%f\t\t%f\n\n", Ordered, Random, Back_Ordered);
}
