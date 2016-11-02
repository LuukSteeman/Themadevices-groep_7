template <typename T>
static bool getBit(int position, T input)
{
    if (position > sizeof(input)*8)
    { // call naar sizeof wordt weg geoptimaliseert en compile time berekent
        return false;
    }
    return (input >> (sizeof(input) - position)) & 1;
}
int main(){
	getBit(1,(short)8);
	return 0;
}
