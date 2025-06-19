#include <stdio.h>
#include <stdlib.h>

// виклик модулів
#include "filling.arr.h"
#include "common.h"

void fill_ordered_arr() // заповнення масива "впорядкований"
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

void fill_random_arr()   // заповнення масива "випадкові значення"
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

void fill_back_arr()    // заповнення масива "обернено впорядкований"
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
