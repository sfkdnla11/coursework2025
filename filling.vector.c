#include <stdio.h>
#include <stdlib.h>

// ������ ������
#include "filling.vector.h"
#include "common.h"

void fillVector_ordered()  // ���������� ������� "�������������"
{
    for (int i = 0; i < VECTOR_SIZE; i++)
    {
        Vector[i] = i + 1;
    }
}

void fillVector_random() // ���������� ������� "�������� ��������"
{
    for (int i = 0; i < VECTOR_SIZE; i++)
    {
        Vector[i] = rand()%VECTOR_SIZE;
    }

}

void fillVector_back()   // ���������� ������� "�������� �������������"
{
    for (int i = 0; i < VECTOR_SIZE; i++)
    {
        Vector[i] = VECTOR_SIZE - i;
    }
}
