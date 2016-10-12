/// @file
#ifndef INFRARED_HPP
#define INFRARED_HPP
#include "IRMessage.hpp"
#include "hwlib.hpp"
#include "rtos.hpp"

/// Infared
//
/// Create the variables and functions
class infrared : public rtos::task<>{
private:
    int state;
	int receive_pin;
	int id_value;
	int data_value;
public:
	infrared(int state, char *name);
	int check();
	int get_id();
	int get_data();
    void main();
	void init();
	void drive(int ir_value);
};

#endif //INFRARED_HPP