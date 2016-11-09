///Copyright Robert Bezem, Ricardo Bouwman, Jeroen van Hattem, Luuk Steeman

#pragma once
static bool getBit(int position, short data)
{
    return (data >> (15-position))&1;
}
