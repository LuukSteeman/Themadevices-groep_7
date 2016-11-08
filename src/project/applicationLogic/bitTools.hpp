#pragma once
/**
    Returns the bit value of a specific position in a short.
    @param position The postion of the bit that should be returned (count from 0).
    @param data The data the bit should be returned from.
*/
static bool getBit(int position, short data)
{
    return (data >> (15 - position)) & 1;
}