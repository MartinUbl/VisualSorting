#ifndef VS_SORTING_H
#define VS_SORTING_H

#include <global.h>

void BubbleSort(std::vector<uint32> *vec);
void QuickSort(std::vector<uint32> *vec, uint32 from, uint32 to);
void SelectionSort(std::vector<uint32> *vec);

#endif
