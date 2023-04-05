#include "controller.hpp"
#include <GLFW/glfw3.h>
#include <iostream>
#include <random>

controller::controller()
	:
	_map(10, 10),
	_snake(),
	_food() {

}

controller::~controller() {

}

void controller::input_update() {
	if (this->_keys[GLFW_KEY_W]) {
		this->_snake._direction.y = -1;
	}
    if (this->_keys[GLFW_KEY_S]) {
    	this->_snake._direction.y = 1;
    }
    if (this->_keys[GLFW_KEY_A]) {
    	this->_snake._direction.x = -1;
    }
    if (this->_keys[GLFW_KEY_D]) {
    	this->_snake._direction.x = 1;
    }
}

void controller::update() {
	this->_snake._position.x += this->_snake._direction.x;
	this->_snake._position.y += this->_snake._direction.y;
	// Check a snake position.
	//std::cout << "[SNAKE::POS] --> " << this->_snake._position.x << ":" << this->_snake._position.y << std::endl;
	for (std::vector<glm::vec2>::iterator it = this->_snake._body.begin(); it != this->_snake._body.end(); ++it) {
		if (it == this->_snake._body.begin()) {
			*it = this->_snake._position;
		} else {
			(*it).x = (*(it-1)).x - 1;
			(*it).y = (*(it-1)).y - 1;
		}
	}
	if (false) {
		generate_food_position();
		this->_snake._body.push_back(glm::vec2((this->_snake._body.end()-1)->x - 1, (this->_snake._body.end()-1)->y - 1));
	}
}

glm::vec2 controller::generate_food_position() {
	std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> map_width_dist(0, this->_map._width);
    std::uniform_int_distribution<int> map_height_dist(0, this->_map._height);
    this->_food._position = glm::vec2(map_width_dist(mt), map_height_dist(mt));
	std::cout << "[RANDOM::INT] --> " << this->_food._position.x << ":" << this->_food._position.y << std::endl;
}