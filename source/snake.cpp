#include "snake.hpp"

snake::snake()
	:
	_direction(0.0f, 0.0f),
	_points(0) {
	this->_body.push_back(glm::vec2(0.0f, 0.0f));
}

snake::~snake() {

}