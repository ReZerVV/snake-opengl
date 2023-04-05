#ifndef SNAKE_H
#define SHAKE_H

#include <vector>
#include <glm/glm.hpp>

class snake {
public:
	snake();
	snake(const snake&) = default;
	snake(snake&&) = default;
	~snake();
public:
	size_t size() const { 
		return this->_body.size();
	}
	void move(const glm::vec2& direction) {
		this->_direction = direction;
	}
public:
	std::vector<glm::vec2> 	_body;
	glm::vec2 				_direction;
	glm::vec2 				_position;
	size_t 					_points;
};

#endif