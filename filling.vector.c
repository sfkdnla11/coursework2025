#include <stdio.h>
#include <stdlib.h>

// виклик модулів
#include "filling.vector.h"
#include "common.h"

void fillVector_ordered()  // заповнення вектору "впорядкований"
{
    for (int i = 0; i < VECTOR_SIZE; i++)
    {
        Vector[i] = i + 1;
    }
}

void fillVector_random() // заповнення вектору "випадкові значення"
{
    for (int i = 0; i < VECTOR_SIZE; i++)
    {
        Vector[i] = rand()%VECTOR_SIZE;
    }

}

void fillVector_back()   // заповнення вектору "обернено впорядкований"
{
    for (int i = 0; i < VECTOR_SIZE; i++)
    {
        Vector[i] = VECTOR_SIZE - i;
    }
}
