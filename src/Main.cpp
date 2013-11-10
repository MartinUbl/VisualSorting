#include <global.h>
#include <ctime>

LRESULT CALLBACK MyWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    return sSimplyFlat->SFWndProc(hWnd, msg, wParam, lParam);
}

std::vector<uint32> sortableList;
bool halt;

void DrawingCallback()
{
    MSG msg;

    if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
    {
        if (msg.message != WM_QUIT)
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
            halt = true;
    }

    SF->BeforeDraw();

    DrawVector(&sortableList);

    SF->AfterDraw();

    if (halt)
        exit(0);
}

int main()
{
    halt = false;
    if (!sSimplyFlat->CreateMainWindow("VisualSorting", WIN_WIDTH, WIN_HEIGHT, 32, false, 60, &MyWndProc))
        return -1;

    srand((unsigned int)time(NULL));

    // 100x random 1-1000
    sortableList.resize(100);
    for (uint32 i = 0; i < 100; i++)
    {
        sortableList[i] = 1+rand()%1000;
        colored[i] = 0;
    }

    //BubbleSort(&sortableList);
    //QuickSort(&sortableList, 0, sortableList.size()-1);
    SelectionSort(&sortableList);

    while (!halt)
        DrawingCallback();

    return 0;
}
