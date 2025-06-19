#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// виклик модулів
#include "sort.arr.h"
#include "common.h"
#include <stdio.h>




clock_t Select7_arr() // Алгоритм сортування №7 методу прямого вибору
{
    int Min, Max;
    int L, R, imin, imax, A, summa;
    clock_t time_start, time_stop;
    time_start = clock();
    for (int k = 0; k < P; k++)
    {
        for (int j = 0; j < N; j++)
        {
            summa = 0;
            for (int i = 0; i < M; i++)
            {
                summa += Arr3D[k][i][j];
            }
            Sum[j] = summa;
        }

        L = 0;
        R = N - 1;
        while (L < R)
        {
            Min = Sum[L];
            imin = L;
            Max = Sum[L];
            imax = L;
            for (int i = L + 1; i <= R; i++)
            {
                if (Sum[i] < Min)
                {
                    Min = Sum[i];
                    imin = i;
                }
                else if (Sum[i] > Max)
                {
                    Max = Sum[i];
                    imax = i;
                }
            }
            if (imin != L)
            {
                Sum[imin] = Sum[L];
                Sum[L] = Min;
                for(int a=0; a<M; a++)
                {
                    A=Arr3D[k][a][imin];
                    Arr3D[k][a][imin]=Arr3D[k][a][L];
                    Arr3D[k][a][L]=A;
                }
            }
            if (imax != R)
            {
                if (imax == L)
                {
                    Sum[imin] = Sum[R];
                    for(int a=0; a<M; a++)
                    {
                        A=Arr3D[k][a][imin];
                        Arr3D[k][a][imin]=Arr3D[k][a][R];
                        Arr3D[k][a][R]=A;
                    }
                }
                else
                {
                    Sum[imax] = Sum[R];
                    for(int a=0; a<M; a++)
                    {
                        A=Arr3D[k][a][imax];
                        Arr3D[k][a][imax]=Arr3D[k][a][R];
                        Arr3D[k][a][R]=A;
                    }
                }
                Sum[R] = Max;
            }
            L++;
            R--;
        }
    }
    time_stop = clock();
    return time_stop - time_start;
}

clock_t Select8_arr() // Алгоритм сортування №8 методу прямого вибору
{
    int L, R, imin, imax, tmp, summa, A;
    clock_t time_start, time_stop;
    time_start = clock();
    for (int k = 0; k < P; k++)
    {
        for (int j = 0; j < N; j++)
        {
            summa = 0;
            for (int i = 0; i < M; i++)
            {
                summa += Arr3D[k][i][j];
            }
            Sum[j] = summa;
        }

        L = 0;
        R = N - 1;
        while (L < R)
        {
            imin = L;
            imax = L;
            for (int i = L + 1; i <= R; i++)
            {
                if (Sum[i] < Sum[imin])
                    imin = i;
                else if (Sum[i] > Sum[imax])
                    imax = i;
            }
            if (imin != L)
            {
                tmp = Sum[imin];
                Sum[imin] = Sum[L];
                Sum[L] = tmp;
                for(int a=0; a<M; a++)
                {
                    A=Arr3D[k][a][imin];
                    Arr3D[k][a][imin]=Arr3D[k][a][L];
                    Arr3D[k][a][L]=A;
                }

            }
            if (imax != R)
            {
                if (imax == L)
                {
                    tmp = Sum[imin];
                    Sum[imin] = Sum[R];
                    Sum[R] = tmp;
                    for(int a=0; a<M; a++)
                    {
                        A=Arr3D[k][a][imin];
                        Arr3D[k][a][imin]=Arr3D[k][a][R];
                        Arr3D[k][a][R]=A;
                    }

                }
                else
                {
                    tmp = Sum[imax];
                    Sum[imax] = Sum[R];
                    Sum[R] = tmp;
                    for(int a=0; a<M; a++)
                    {
                        A=Arr3D[k][a][imax];
                        Arr3D[k][a][imax]=Arr3D[k][a][R];
                        Arr3D[k][a][R]=A;
                    }

                }
            }
            L++;
            R--;
        }
    }

    time_stop = clock();
    return time_stop - time_start;
}

clock_t Shell_2_arr() // Алгоритм №2 методу сортування Шелла
{
    int tmp, t, y, r, A, summa;
    clock_t time_start, time_stop;
    time_start = clock();
    for (int k = 0; k < P; k++)
    {
        for (int j = 0; j < N; j++)
        {
            summa = 0;
            for (int i = 0; i < M; i++)
            {
                summa += Arr3D[k][i][j];
            }
            Sum[j] = summa;
        }

        if (N < 4)
            t = 1;
        else
            t = (int)log2f((float)N) - 1;
        int Stages[t];
        Stages[t - 1] = 1;
        for (int h = t - 2; h >= 0; h--)
            Stages[h] = 2 * Stages[h + 1] + 1;
        for (int p = 0; p < t; p++)
        {
            r = Stages[p];
            for (int h = r; h < N; h++)
            {
                y = h;
                while (y >= r && Sum[y] < Sum[y - r])
                {
                    tmp = Sum[y];
                    Sum[y] = Sum[y - r];
                    Sum[y - r] = tmp;
                    for(int a=0; a<M; a++)
                    {
                        A=Arr3D[k][a][y];
                        Arr3D[k][a][y]=Arr3D[k][a][y - r];
                        Arr3D[k][a][y - r]=A;
                    }
                    y = y - r;

                }
            }
        }
    }
    time_stop = clock();
    return time_stop - time_start;
}



