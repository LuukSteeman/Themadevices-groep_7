#ifndef TEXT_HPP
#define TEXT_HPP

#include "../interface/gui.hpp"

class text : public GUI {
private:
	auto w;
	auto text;
public:
	text(hwlib::window & w, auto text):
		w(w), 
		text(text)
	{}

	void draw() override;

	void update() override;
};

#endif