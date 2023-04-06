#include "snake.hpp"

snake::snake()
	:
	_direction(0.0f, 0.0f),
	_points(0),
	_position(0.0f, 0.0f) {
	this->_body.push_back(glm::vec2());
}

snake::~snake() {

}