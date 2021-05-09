#include "check.h"

bool check_color (string color)
{
    vector<string> colors {"black", "red", "blue", "green", "yellow"};
    bool flag=true;

    for(int i = 0; i < color.length(); i++)
    {
        color[i] = tolower(color[i]);

    }

    for (string x : colors)
    {
        if (color==x)
            flag=false;
    }

    return flag;
}
