#include "setup_task.hpp"

int main(){
	char pressed_key;

	read_channel();

	pressed_key = get_key();

	std::cout << pressed_key;

}