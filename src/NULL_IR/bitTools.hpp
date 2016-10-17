template <typename T>
static bool getBit(unsigned int position, T input)
{
    if (position > sizeof(input)*__CHAR_BIT__)
    { // call naar sizeof wordt weg geoptimaliseert en compile time berekent
        return false;
    }
    return (input >> (sizeof(input) - position)) & 1; //optimalisatie idem
}