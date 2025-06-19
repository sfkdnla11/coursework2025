#include <stdio.h>
#include <stdlib.h>

// ������ ������
#include "filling.arr.h"
#include "common.h"

void fill_ordered_arr() // ���������� ������ "�������������"
{
    int number=0;
    for (int k=0; k<P; k++)
    {
        for (int j=0; j<N; j++)
        {
            for (int i=0; i<M; i++)
            {
                Arr3D[k][i][j] = number++;
            }
        }
    }

}

void fill_random_arr()   // ���������� ������ "�������� ��������"
{
    for (int k=0; k<P; k++)
    {
        for (int j=0; j<N; j++)
        {
            for (int i=0; i<M; i++)
            {
                Arr3D[k][i][j] = rand() % (P*M*N);
            }
        }
    }

}

void fill_back_arr()    // ���������� ������ "�������� �������������"
{
    int number = P*M*N;
    for (int k=0; k<P; k++)
    {
        for (int j=0; j<N; j++)
        {
            for (int i=0; i<M; i++)
            {
                Arr3D[k][i][j] = number--;
            }
        }
    }
}
