#include "idJumper.hpp"
#include <hwlib.hpp>

//+------+----+----+----+----+----+----+----+
//| PIN || 42 | 43 | 44 | 45 | 46 | 47 | 48 |
//+======+====+====+====+====+====+====+====+
//| 49  || 1  | 2  | 3  | 4  | 5  | 6  | 7  |
//+------+----+----+----+----+----+----+----+
//| 50  || 8  | 9  | 10 | 11 | 12 | 13 | 14 |
//+------+----+----+----+----+----+----+----+
//| 51  || 15 | 16 | 17 | 18 | 19 | 20 | 21 |
//+------+----+----+----+----+----+----+----+
//| 52  || 22 | 23 | 24 | 25 | 26 | 27 | 28 |
//+------+----+----+----+----+----+----+----+
//| 53  || 29 | 30 | 31 |    |    |    |    |
//+------+----+----+----+----+----+----+----+

int idJumper::getID()
{
    for (int x = 1; x <= 7; x++)
    {
        auto xpin = hwlib::target::pin_out((hwlib::target::pins)(x + 41));
        xpin.set(1);
        for (int y = 1; y <= 5; y++)
        {
            auto ypin = hwlib::target::pin_in((hwlib::target::pins)(y + 48));
            hwlib::cout << "testing: " << x << " " << x + 41 << "," << y << " " << y + 48 << "\n";
            hwlib::wait_ms(50);
            if (!ypin.get())
            {
                xpin.set(0);
                int id = x + ((y - 1) * 7);
                hwlib::cout << "xval: " << x << " yval: " << y << "\n";
                return id;
            }
        }
        xpin.set(0);
    }
    return 0;
}