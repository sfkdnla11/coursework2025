#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// виклик модулів
#include "sort.vector.h"
#include "common.h"

clock_t Select7_vec()
{
    int Min, Max;
    int L, R, imin, imax;
    clock_t time_start, time_stop;
    time_start = clock();

    L = 0;
    R = VECTOR_SIZE - 1;

    while (L < R)
    {
        Min = Vector[L];
        imin = L;
        Max = Vector[L];
        imax = L;

        for (int i = L + 1; i <= R; i++)
        {
            if (Vector[i] < Min)
            {
                Min = Vector[i];
                imin = i;
            }
            else if (Vector[i] > Max)
            {
                Max = Vector[i];
                imax = i;
            }
        }

        if (imin != L)
        {
            Vector[imin] = Vector[L];
            Vector[L] = Min;
        }

        if (imax != R)
        {
            if (imax == L)
            {
                Vector[imin] = Vector[R];
            }
            else
            {
                Vector[imax] = Vector[R];
            }
            Vector[R] = Max;
        }

        L++;
        R--;
    }

    time_stop = clock();
    return time_stop - time_start;
}

clock_t Select8_vec()
{
    int L, R, imin, imax, tmp;
    clock_t time_start, time_stop;
    time_start = clock();

    L = 0;
    R = VECTOR_SIZE - 1;

    while (L < R)
    {
        imin = L;
        imax = L;

        for (int i = L + 1; i <= R; i++)
        {
            if (Vector[i] < Vector[imin])
            {
                imin = i;
            }
            else if (Vector[i] > Vector[imax])
            {
                imax = i;
            }
        }

        if (imin != L)
        {
            tmp = Vector[imin];
            Vector[imin] = Vector[L];
            Vector[L] = tmp;
        }

        if (imax != R)
        {
            if (imax == L)
            {
                tmp = Vector[imin];
                Vector[imin] = Vector[R];
                Vector[R] = tmp;
            }
            else
            {
                tmp = Vector[imax];
                Vector[imax] = Vector[R];
                Vector[R] = tmp;
            }
        }

        L++;
        R--;
    }

    time_stop = clock();
    return time_stop - time_start;
}

clock_t Shell_2_vec()
{
    int tmp, t, j, k;
    clock_t time_start, time_stop;
    time_start = clock();

    if (VECTOR_SIZE < 4)
        t = 1;
    else
        t = (int)log2f((float)VECTOR_SIZE) - 1;

    int Stages[t];
    Stages[t - 1] = 1;
    for (int i = t - 2; i >= 0; i--)
        Stages[i] = 2 * Stages[i + 1] + 1;

    for (int p = 0; p < t; p++)
    {
        k = Stages[p];
        for (int i = k; i < VECTOR_SIZE; i++)
        {
            j = i;
            while (j >= k && Vector[j] < Vector[j - k])
            {
                tmp = Vector[j];
                Vector[j] = Vector[j - k];
                Vector[j - k] = tmp;
                j -= k;
            }
        }
    }

    time_stop = clock();
    return time_stop - time_start;
}
