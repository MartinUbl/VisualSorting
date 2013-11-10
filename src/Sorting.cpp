#include <global.h>

#define DRAW_DELAY_BUBBLE 1
#define DRAW_DELAY_QUICK 20
#define DRAW_DELAY_INSERTION 1

//
// general
//

void swap(std::vector<uint32> *vec, uint32 ind_a, uint32 ind_b)
{
    uint32 tmp = (*vec)[ind_a];
    (*vec)[ind_a] = (*vec)[ind_b];
    (*vec)[ind_b] = tmp;
}

// Bubble sort

void BubbleSort(std::vector<uint32> *vec)
{
    for (uint32 j = 0; j < vec->size()-1; j++)
    {
        for (uint32 i = 0; i < vec->size()-1; i++)
        {
            colored[i+1] = 0xFF0000FF;
            if ((*vec)[i] > (*vec)[i+1])
                swap(vec, i, i+1);

            DrawingCallback();
            Sleep(DRAW_DELAY_BUBBLE);
            colored[i+1] = 0;
        }
    }
}

// Quick sort

void QuickSort(std::vector<uint32> *vec, uint32 from, uint32 to)
{
    uint32 pivind = (uint32)ceil(((float)(from+to))/2.0f);
    uint32 pivot = (uint32)((*vec)[pivind]);

    colored[pivind] = 0x00FF00FF;

    uint32 li = from;
    uint32 ri = to;

    uint32 coli;

    do
    {
        while ((*vec)[li] < pivot && li < to)
            li++;
        while ((*vec)[ri] > pivot && ri > from)
            ri--;

        coli = li;
        colored[coli] = 0xFF0000FF;

        if (li <= ri)
        {
            swap(vec, li, ri);
            li++;
            ri--;
        }

        DrawingCallback();
        Sleep(DRAW_DELAY_QUICK);
        colored[coli] = 0;
    } while (li < ri);

    colored[pivind] = 0;

    if (ri > from)
        QuickSort(vec, from, ri);

    if (li < to)
        QuickSort(vec, li, to);
}

// Selection sort

void SelectionSort(std::vector<uint32> *vec)
{
    uint32 min;
    for (uint32 i = 0; i < vec->size()-1; i++)
    {
        min = i;

        for (uint32 j = i+1; j <= vec->size()-1; j++)
        {
            colored[j] = 0xFF0000FF;
            if ((*vec)[j] < ((*vec)[min]))
            {
                colored[min] = 0;
                min = j;
                colored[j] = 0x00FF00FF;
            }

            DrawingCallback();
            Sleep(DRAW_DELAY_INSERTION);

            if (min != j)
                colored[j] = 0;
        }

        colored[min] = 0;

        swap(vec, i, min);
    }
}
