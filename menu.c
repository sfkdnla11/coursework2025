#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <conio.h>

// виклик модулів
#include "common.h"
#include "table.h"
#include "measurement.h"
#include "menu.h"

void GotoXY(int X, int Y)     //для переміщення курсора текстового вікна на задані координати
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { X, Y };
    SetConsoleCursorPosition(hStdOut, coord);
}

void ConsoleCursorVisible(int show, short size)   // Функція для керування видимістю курсора у консолі

{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = show;
    structCursorInfo.dwSize = size;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}

void colour(int i)  // зміна кольору
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, i);
}


// MENU for ARR3d
void Menu_choose_sort_arr()  // меню для вибору сортування для масива
{
    system("cls");

    ConsoleCursorVisible(0, 100);
    const char* MenuOptions[] = {"Select 7", "Select 8", "Shell 2", "Back"};
    int numMenuOptions = sizeof(MenuOptions) / sizeof(MenuOptions[0]);

    int active_menu = 0;

    char key;
    while (1)
    {
        colour(13);
        GotoXY(45, 7);
        printf("ARR MENU");
        int x = 45, y = 9;
        GotoXY(x, y);

        for (int i = 0; i < numMenuOptions; i++)
        {
            GotoXY(x, y++);
            if (i == active_menu)
            {
                colour(5);
                printf("* %s * ",  MenuOptions[i]);
            }
            else
                printf("  %s   ", MenuOptions[i]);
            colour(13);
        }

        key = _getch();
        if (key == -32) key = _getch();
        switch (key)
        {
        case 27://
            exit(0);
        case 72:
            if (active_menu > 0)
                active_menu--;
            break;
        case 80:
            if (active_menu < numMenuOptions - 1)
                active_menu++;
            break;
        case 13://enter
            switch (active_menu)
            {
            case 0:
                Menu_choose_Select7_arr();  //виклик меню для сортування select7
                system("cls");
                break;
            case 1:
                Menu_choose_Select8_arr();   //виклик меню для сортування select8
                system("cls");
                break;
            case 2:
                Menu_choose_Shell2_arr();   //виклик меню для сортування shell2
                system("cls");
                break;
            case 3:
                return;
                break;
            }
            break;
        }
    }
}

void Menu_choose_Select7_arr()   // меню для сортування Select 7 для масива
{
    float Time;
    system("cls");

    ConsoleCursorVisible(0, 100);
    const char* MenuOptions[] = {"Ordered", "Random", "Back ordered", "Back"};
    int numMenuOptions = sizeof(MenuOptions) / sizeof(MenuOptions[0]);

    int active_menu = 0;

    char key;
    while (1)
    {
        colour(13);
        GotoXY(45, 7);
        printf("SELECT 7 for ARR");
        int x = 45, y = 9;
        GotoXY(x, y);

        for (int i = 0; i < numMenuOptions; i++)
        {
            GotoXY(x, y++);
            if (i == active_menu)
            {
                colour(5);
                printf("* %s * ",  MenuOptions[i]);
            }
            else
                printf("  %s   ", MenuOptions[i]);
            colour(13);
        }

        key = _getch();// Зчитуємо натиснуту клавішу без виводу на екран
        if (key == -32) key = _getch();
        switch (key)
        {
        case 27: // Клавіша Escape
            exit(0);
        case 72:// Стрілка вгору
            if (active_menu > 0)
                active_menu--;// Переміщення курсору меню вгору
            break;
        case 80:// Стрілка вниз
            if (active_menu < numMenuOptions - 1)
                active_menu++;// Переміщення курсору меню вниз
            break;
        case 13:// Клавіша Enter
            switch (active_menu)
            {
            case 0:
                system("cls");
                Select7_measurement_arr('o');//  заповнення масива "впорядкований"
                Time = MeasurementProcessing();
                printf ("\nOrdered array: P = %d, M = %d, N = %d was sorted by Select 7 algorithm. Time = %7.2f", P,M,N, Time);
                printf("\nPress Enter to return...");
                getchar();
                system("cls");// Очищення екрану
                break;
            case 1:
                system("cls");
                Select7_measurement_arr('r');    // заповнення масива "випадкові значення"
                Time = MeasurementProcessing();
                printf ("\nRandom array: P = %d, M = %d, N = %d was sorted by Select 7 algorithm. Time = %7.2f", P,M,N, Time);
                printf("\nPress Enter to return...");
                getchar();
                system("cls");
                break;
            case 2:
                system("cls");
                Select7_measurement_arr('b');    // заповнення масива "обернено впорядкований"

                Time = MeasurementProcessing();
                printf ("\nBack-ordered array: P = %d, M = %d, N = %d was sorted by Select 7 algorithm. Time = %7.2f", P,M,N, Time);
                printf("\nPress Enter to return...");
                getchar();
                system("cls");
                break;
            case 3:
                return;
                break;
            }
            break;
        }
    }
}

void Menu_choose_Select8_arr()  // меню для сортування Select8 для масива
{
    float Time;
    system("cls");

    ConsoleCursorVisible(0, 100);
    const char* MenuOptions[] = {"Ordered", "Random", "Back ordered", "Back"};
    int numMenuOptions = sizeof(MenuOptions) / sizeof(MenuOptions[0]);

    int active_menu = 0;

    char key;
    while (1)
    {
        colour(13);
        GotoXY(45, 7);
        printf("SELECT 8 for ARR");
        int x = 45, y = 9;
        GotoXY(x, y);

        for (int i = 0; i < numMenuOptions; i++)
        {
            GotoXY(x, y++);
            if (i == active_menu)
            {
                colour(5);
                printf("* %s * ",  MenuOptions[i]);
            }
            else
                printf("  %s   ", MenuOptions[i]);
            colour(13);
        }

        key = _getch();
        if (key == -32) key = _getch();
        switch (key)
        {
        case 27://escape
            exit(0);//loophole
        case 72:
            if (active_menu > 0)
                active_menu--;
            break;
        case 80:
            if (active_menu < numMenuOptions - 1)
                active_menu++;
            break;
        case 13://enter
            switch (active_menu)   // вибір заповнення
            {
            case 0:
                system("cls");
                Select8_measurement_arr('o');   //  заповнення масива "впорядкований"
                Time = MeasurementProcessing();
                printf ("\nOrdered array: P = %d, M = %d, N = %d was sorted by Select 8 algorithm. Time = %7.2f", P,M,N, Time);
                printf("\nPress Enter to return...");
                getchar();
                system("cls");
                break;
            case 1:
                system("cls");
                Select8_measurement_arr('r');   // заповнення масива "випадкові значення"
                Time = MeasurementProcessing();
                printf ("\nRandom array: P = %d, M = %d, N = %d was sorted by Select 8 algorithm. Time = %7.2f", P,M,N, Time);
                printf("\nPress Enter to return...");
                getchar();
                system("cls");
                break;
            case 2:
                system("cls");
                Select8_measurement_arr('b');    // заповнення масива "обернено впорядкований"
                Time = MeasurementProcessing();
                printf ("\nBack ordered array: P = %d, M = %d, N = %d was sorted by Select 8 algorithm. Time = %7.2f", P,M,N, Time);
                printf("\nPress Enter to return...");
                getchar();
                system("cls");
                break;
            case 3:
                return;
                break;
            }
            break;
        }
    }
}

void Menu_choose_Shell2_arr()   // меню для сортування Shell_2 для масива
{
    float Time;
    system("cls");

    ConsoleCursorVisible(0, 100);
    const char* MenuOptions[] = {"Ordered", "Random", "Back ordered", "Back"};
    int numMenuOptions = sizeof(MenuOptions) / sizeof(MenuOptions[0]);

    int active_menu = 0;

    char key;
    while (1)
    {
        colour(13);
        GotoXY(45, 7);
        printf("SHELL 2 for ARR");
        int x = 45, y = 9;
        GotoXY(x, y);

        for (int i = 0; i < numMenuOptions; i++)
        {
            GotoXY(x, y++);
            if (i == active_menu)
            {
                colour(5);
                printf("* %s * ",  MenuOptions[i]);
            }
            else
                printf("  %s   ", MenuOptions[i]);
            colour(13);
        }

        key = _getch();
        if (key == -32) key = _getch();
        switch (key)
        {
        case 27:
            exit(0);
        case 72:
            if (active_menu > 0)
                active_menu--;
            break;
        case 80:
            if (active_menu < numMenuOptions - 1)
                active_menu++;
            break;
        case 13:
            switch (active_menu)    // вибір заповнення
            {
            case 0:
                system("cls");
                Shell_2_measurement_arr('o');     //  заповнення масива "впорядкований"
                Time = MeasurementProcessing();
                printf ("\nOrdered array: P = %d, M = %d, N = %d was sorted by SHELL 2 algorithm. Time = %7.2f", P,M,N, Time);
                printf("\nPress Enter to return...");
                getchar();
                system("cls");
                break;
            case 1:
                system("cls");
                Shell_2_measurement_arr('r');    // заповнення масива "випадкові значення"
                Time = MeasurementProcessing();
                printf ("\nRandom array: P = %d, M = %d, N = %d was sorted by SHELL 2 algorithm. Time = %7.2f", P,M,N, Time);
                printf("\nPress Enter to return...");
                getchar();
                system("cls");
                break;
            case 2:
                system("cls");
                Shell_2_measurement_arr('b');    // заповнення масива "обернено впорядкований"
                Time = MeasurementProcessing();
                printf ("\nBack ordered array: P = %d, M = %d, N = %d was sorted by SHELL 2 algorithm. Time = %7.2f", P,M,N, Time);
                printf("\nPress Enter to return...");
                getchar();
                system("cls");
                break;
            case 3:
                return;
                break;
            }
            break;
        }
    }
}

// VECTOR MENU//
void Menu_choose_sort_vec()  // меню для вибору сортування у векторі
{
    system("cls");

    ConsoleCursorVisible(0, 100);
    const char* MenuOptions[] = {"Select 7", "Select 8", "Shell 2", "Back"};
    int numMenuOptions = sizeof(MenuOptions) / sizeof(MenuOptions[0]);

    int active_menu = 0;

    char key;
    while (1)
    {
        colour(13);
        GotoXY(45, 7);
        printf("VECTOR MENU");
        int x = 45, y = 9;
        GotoXY(x, y);

        for (int i = 0; i < numMenuOptions; i++)
        {
            GotoXY(x, y++);
            if (i == active_menu)
            {
                colour(5);
                printf("* %s * ",  MenuOptions[i]);
            }
            else
                printf("  %s   ", MenuOptions[i]);
            colour(13);
        }

        key = _getch();
        if (key == -32) key = _getch();
        switch (key)
        {
        case 27:
            exit(0);
        case 72:
            if (active_menu > 0)
                active_menu--;
            break;
        case 80:
            if (active_menu < numMenuOptions - 1)
                active_menu++;
            break;
        case 13://enter
            switch (active_menu)
            {
            case 0:
                Menu_choose_Select7_vec();   // виклик меню для сортування Select 7
                system("cls");
                break;
            case 1:
                Menu_choose_Select8_vec();    // виклик меню для сортування Select_8
                system("cls");
                break;
            case 2:
                Menu_choose_Shell2_vec();    // виклик меню для сортування Shell_2
                system("cls");
                break;
            case 3:
                return;
                break;
            }
            break;
        }
    }
}

void Menu_choose_Select7_vec()  //Select 7 for VECTOR//
{
    float Time;
    system("cls");

    ConsoleCursorVisible(0, 100);
    const char* MenuOptions[] = {"Ordered", "Random", "Back ordered", "Back"};
    int numMenuOptions = sizeof(MenuOptions) / sizeof(MenuOptions[0]);

    int active_menu = 0;

    char key;
    while (1)
    {
        colour(13);
        GotoXY(45, 7);
        printf("Select 7 for VECTOR");
        int x = 45, y = 9;
        GotoXY(x, y);

        for (int i = 0; i < numMenuOptions; i++)
        {
            GotoXY(x, y++);
            if (i == active_menu)
            {
                colour(5);
                printf("* %s * ",  MenuOptions[i]);
            }
            else
                printf("  %s   ", MenuOptions[i]);
            colour(13);
        }

        key = _getch();
        if (key == -32) key = _getch();
        switch (key)
        {
        case 27:
            exit(0);
        case 72:
            if (active_menu > 0)
                active_menu--;
            break;
        case 80:
            if (active_menu < numMenuOptions - 1)
                active_menu++;
            break;
        case 13://enter
            switch (active_menu)
            {
            case 0:
                system("cls");
                Select7_measurement_vec('o');
                Time = MeasurementProcessing();
                printf("\nOrder array: Vector = %d was sorted by Select 7 algorithm. Time = %7.2f\n", VECTOR_SIZE, Time);
                printf("Press Enter to return...");
                getchar();
                system("cls");
                break;
            case 1:
                system("cls");
                Select7_measurement_vec('r');
                Time = MeasurementProcessing();
                printf("\nRandom array: Vector = %d was sorted by Select 7 algorithm. Time = %7.2f\n", VECTOR_SIZE, Time);
                printf("Press Enter to return...");
                getchar();
                system("cls");
                break;
            case 2:
                system("cls");
                Select7_measurement_vec('b');
                Time = MeasurementProcessing();
                printf("\nBack order array: Vector = %d was sorted by Select 7 algorithm. Time = %7.2f\n", VECTOR_SIZE, Time);
                printf("Press Enter to return...");
                getchar();
                system("cls");
                break;
            case 3:
                return;
                break;
            }
            break;
        }
    }
}

void Menu_choose_Select8_vec() //SELECT 8 for VECTOR//
{
    float Time;
    system("cls");

    ConsoleCursorVisible(0, 100);
    const char* MenuOptions[] = {"Ordered", "Random", "Back ordered", "Back"};
    int numMenuOptions = sizeof(MenuOptions) / sizeof(MenuOptions[0]);

    int active_menu = 0;

    char key;
    while (1)
    {
        colour(13);
        GotoXY(45, 7);
        printf("Select 8 for VECTOR");
        int x = 45, y = 9;
        GotoXY(x, y);

        for (int i = 0; i < numMenuOptions; i++)
        {
            GotoXY(x, y++);
            if (i == active_menu)
            {
                colour(5);
                printf("* %s * ",  MenuOptions[i]);
            }
            else
                printf("  %s   ", MenuOptions[i]);
            colour(13);
        }

        key = _getch();
        if (key == -32) key = _getch();
        switch (key)
        {
        case 27:
            exit(0);
        case 72:
            if (active_menu > 0)
                active_menu--;
            break;
        case 80:
            if (active_menu < numMenuOptions - 1)
                active_menu++;
            break;
        case 13://enter
            switch (active_menu)
            {
            case 0:
                system("cls");
                printf("Please, wait");
                Select8_measurement_vec('o');
                Time = MeasurementProcessing();
                printf("\nOrder array: Vector = %d was sorted by Select 8 algorithm. Time = %7.2f\n", VECTOR_SIZE, Time);
                printf("Press Enter to return...");
                getchar();
                system("cls");
                break;

            case 1:
                system("cls");
                Select8_measurement_vec('r');
                Time = MeasurementProcessing();
                printf("\nRandom array: Vector = %d was sorted by Select 8 algorithm. Time = %7.2f\n", VECTOR_SIZE, Time);
                printf("Press Enter to return...");
                getchar();
                system("cls");
                break;

            case 2:
                system("cls");
                Select8_measurement_vec('b');
                Time = MeasurementProcessing();
                printf("\nBack order array: Vector = %d was sorted by Select 8 algorithm. Time = %7.2f\n", VECTOR_SIZE, Time);
                printf("Press Enter to return...");
                getchar();
                system("cls");
                break;

            case 3:
                return;
                break;
            }
            break;
        }
    }
}


void Menu_choose_Shell2_vec() //SHELL 2 for VECTOR//
{
    float Time;
    system("cls");

    ConsoleCursorVisible(0, 100);
    const char* MenuOptions[] = {"Ordered", "Random", "Back ordered", "Back"};
    int numMenuOptions = sizeof(MenuOptions) / sizeof(MenuOptions[0]);

    int active_menu = 0;

    char key;
    while (1)
    {
        colour(13);
        GotoXY(45, 7);
        printf("SHELL 2 for VECTOR");
        int x = 45, y = 9;
        GotoXY(x, y);

        for (int i = 0; i < numMenuOptions; i++)
        {
            GotoXY(x, y++);
            if (i == active_menu)
            {
                colour(5);
                printf("* %s * ",  MenuOptions[i]);
            }
            else
                printf("  %s   ", MenuOptions[i]);
            colour(13);
        }

        key = _getch();
        if (key == -32) key = _getch();
        switch (key)
        {
        case 27:
            exit(0);
        case 72:
            if (active_menu > 0)
                active_menu--;
            break;
        case 80:
            if (active_menu < numMenuOptions - 1)
                active_menu++;
            break;
        case 13:
            switch (active_menu)
            {
            case 0:
                system("cls");
                Shell_2_measurement_vec('o');
                Time = MeasurementProcessing();
                printf("\nOrder array: Vector = %d was sorted by SHELL 2 algorithm. Time = %7.2f\n", VECTOR_SIZE, Time);
                printf("Press Enter to return...");
                getchar();
                system("cls");
                break;
            case 1:
                system("cls");
                Shell_2_measurement_vec('r');
                Time = MeasurementProcessing();
                printf("\nRandom array: Vector = %d was sorted by SHELL 2 algorithm. Time = %7.2f\n", VECTOR_SIZE, Time);
                printf("Press Enter to return...");
                getchar();
                system("cls");
                break;
            case 2:
                system("cls");
                Shell_2_measurement_vec('b');
                Time = MeasurementProcessing();
                printf("\nBack order array: Vector = %d was sorted by SHELL 2 algorithm. Time = %7.2f\n", VECTOR_SIZE, Time);
                printf("Press Enter to return...");
                getchar();
                system("cls");
                break;
            case 3:
                return;
                break;
            }
            break;
        }
    }
}

//MAIN MENU//

void menu()   // головне меню
{
    system("cls");

    ConsoleCursorVisible(0, 100);
    const char* menuOptions[] = {"Arr3D","Vector","Table","Exit"};
    int numOptions = sizeof(menuOptions) / sizeof(menuOptions[0]);

    int active_menu = 0;

    char key;
    while (1)
    {
        colour(13);
        GotoXY(45, 7);
        printf("MAIN MENU");
        int x = 45, y = 9;
        GotoXY(x, y);

        for (int i = 0; i < numOptions; i++)
        {
            GotoXY(x, y++);
            if (i == active_menu)
            {
                colour(5);
                printf("* %s * ",  menuOptions[i]);
            }
            else
                printf("  %s   ", menuOptions[i]);
            colour(13);
        }

        key = _getch();
        if (key == -32) key = _getch();
        switch (key)
        {
        case 27://escape
            exit(0);//loophole
        case 72:
            if (active_menu > 0)
                active_menu--;
            break;
        case 80:
            if (active_menu < numOptions - 1)
                active_menu++;
            break;
        case 13://enter
            switch (active_menu)
            {
            case 0:
                colour(13);
                system("CLS");
                GotoXY(x, y);
                Menu_choose_sort_arr();   // перехід до меню для масива
                system("cls");
                break;
            case 1:
                colour(13);
                system("CLS");
                Menu_choose_sort_vec();  // перехід до меню для вектора
                _getch();
                system("CLS");
                break;
            case 2:
                colour(13);
                system("CLS");
                table();   // виклик таблиці
                _getch();
                system("CLS");
                break;
            case 3:
                colour(13);
                GotoXY(45, 16);
                exit(0);
                break;
            }
            break;
        }
    }
}
