#pragma once
static bool getBit(int position, short data){
    return (data >> (15-position))&1;
}