#ifndef FOOD_H
#define FOOD_H

#include <glm/glm.hpp>

class food {
public:
	food();
	food(const food&) = default;
	food(food&&) = default;
	~food();
public:
	glm::vec2 _position;
};

#endif