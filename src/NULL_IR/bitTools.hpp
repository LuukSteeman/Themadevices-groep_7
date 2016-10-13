namespace bittools
{
template <typename T>
static bool getBit(int position, T input)
{
    if (position > sizeof(input))
    { // call naar sizeof wordt weg geoptimaliseert en compile time berekent
        return false;
    }
    return (input >> (sizeof(input) - position)) & 1; //optimalisatie idem
}
}