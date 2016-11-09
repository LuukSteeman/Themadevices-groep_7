///Copyright Robert Bezem, Ricardo Bouwman, Jeroen van Hattem, Luuk Steeman

#pragma once

/**
    Class to get the PlayerID

    The jumper has to be configured acording to this table:

    ```
    +-----+----+----+----+----+----+----+----+
    | PIN | 42 | 43 | 44 | 45 | 46 | 47 | 48 |
    +-----+----+----+----+----+----+----+----+
    | 49  | 1  | 2  | 3  | 4  | 5  | 6  | 7  |
    +-----+----+----+----+----+----+----+----+
    | 50  | 8  | 9  | 10 | 11 | 12 | 13 | 14 |
    +-----+----+----+----+----+----+----+----+
    | 51  | 15 | 16 | 17 | 18 | 19 | 20 | 21 |
    +-----+----+----+----+----+----+----+----+
    | 52  | 22 | 23 | 24 | 25 | 26 | 27 | 28 |
    +-----+----+----+----+----+----+----+----+
    | 53  | 29 | 30 | 31 |    |    |    |    |
    +-----+----+----+----+----+----+----+----+
    ```

*/
class PlayerID
{
  public:
    /**
        Get player id

        This functions walks the pins and calculates the player id. 
        To see what pins have to be connected have a look at PlayerID

        @return the player id (1-31)
    */
    static int getID();
};
