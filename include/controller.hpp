#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <glm/glm.hpp>
#include <iostream>
#include "snake.hpp"
#include "food.hpp"
#include "map.hpp"

class controller {
public:
	controller();
	controller(const controller&) = default;
	controller(controller&&) = default;
	~controller();
public:
	void input_update();
	void update();
private:
	glm::vec2 generate_food_position();
public:
	bool 								_keys[1024];
	map 								_map;
	snake 								_snake;
	food  								_food;
};

#endif