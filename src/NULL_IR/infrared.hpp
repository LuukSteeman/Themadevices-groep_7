/// @file
#ifndef INFRARED_HPP
#define INFRARED_HPP

/// Infared
//
/// Create the variables and functions
class infrared{
private:
    int state;
	int receive_pin;
	int id_value;
	int data_value;
public:
	infrared(int state);
	void init();
	int check();
	int get_id();
	int get_data();
	void drive(int ir_value);
};

#endif //INFRARED_HPP