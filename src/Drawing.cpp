#include <global.h>

std::map<uint32, uint32> colored;

void DrawVector(std::vector<uint32> *vec)
{
    uint32 min = 1000;
    uint32 max = 0;

    for (uint32 i = 0; i < vec->size(); i++)
    {
        if ((*vec)[i] > max)
            max = (*vec)[i];
        if ((*vec)[i] < min)
            min = (*vec)[i];
    }

    float ratio = ((float)WIN_HEIGHT) / ((float)max);

    float step = ((float)WIN_WIDTH) / ((float)vec->size());
    float width = step - 1;

    float h;
    uint32 col;
    for (uint32 i = 0; i < vec->size(); i++)
    {
        h = floor(((*vec)[i])*ratio);

        col = colored[i];
        if (col == 0)
            col = MAKE_COLOR_RGBA(255,255,255,255);

        SF->Drawing->DrawRectangle((uint32)(i*step), (uint32)(WIN_HEIGHT-h), (uint32)(width), (uint32)(h), col);
    }
}
