#ifndef game_HPP
#define game_HPP


/// game
//
/// Create the variables and functions
class game {
private:
    int state;
public:
	game(int state);
	void init();
	void forward(int force);
	void left(int force);
	void right(int force);
	void backward();
	void off();
};

#endif //game_HPP