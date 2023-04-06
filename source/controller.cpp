#include "controller.hpp"
#include <GLFW/glfw3.h>
#include <iostream>
#include <random>

controller::controller(map *map, snake *snake)
	:
	_map(map),
	_snake(snake),
	_food() {
	this->_snake->_position = glm::vec2{
		static_cast<int>(this->_map->_width / 2),
		static_cast<int>(this->_map->_height / 2)
	};
	this->_snake->_direction = glm::vec2(0.0, 0.0);
	generate_food_position();
}

controller::~controller() {

}

void controller::input_update() {
	if (this->_keys[GLFW_KEY_W]) {
		this->_snake->_direction = glm::vec2(0.0f, -1.0f);
	}
	if (this->_keys[GLFW_KEY_S]) {
		this->_snake->_direction = glm::vec2(0.0f, 1.0f);
	}
	if (this->_keys[GLFW_KEY_A]) {
		this->_snake->_direction = glm::vec2(-1.0f, 0.0f);
	}
	if (this->_keys[GLFW_KEY_D]) {
		this->_snake->_direction = glm::vec2(1.0f, 0.0f);
	}
}

void controller::update() {
	this->_snake->_position.x += this->_snake->_direction.x;
	this->_snake->_position.y += this->_snake->_direction.y;

	if (this->_snake->_position.x < 0) {
		this->_snake->_position.x = this->_map->_width;
	}
	if (this->_snake->_position.x > this->_map->_width) {
		this->_snake->_position.x = 0;
	}
	if (this->_snake->_position.y < 0) {
		this->_snake->_position.y = this->_map->_height;
	}
	if (this->_snake->_position.y > this->_map->_height) {
		this->_snake->_position.y = 0;
	}

	if (this->_snake->_position == this->_food._position) {
		this->_snake->_body.push_back(glm::vec2());
		generate_food_position();
		this->_snake->_body.push_back(glm::vec2());
	}

	if (this->_snake->_body.size() > 2) {
		for (unsigned int i = 0; i < this->_snake->_body.size()-2; ++i) {
			this->_snake->_body[this->_snake->_body.size()-1-i] = this->_snake->_body[this->_snake->_body.size()-1-i-1];
		}
	}
	if (this->_snake->_body.size() > 1) {
		this->_snake->_body[1] = this->_snake->_body[0];
	}
	this->_snake->_body[0] = this->_snake->_position;
	
	for (unsigned int i = 0; i < this->_snake->_body.size(); ++i) {
		for (unsigned int j = 0; j < this->_snake->_body.size(); ++j) {
			if (i == j) {
				continue;
			}
			if (this->_snake->_body[i] == this->_snake->_body[j]) {
				this->_snake->_position = glm::vec2{
					static_cast<int>(this->_map->_width / 2),
					static_cast<int>(this->_map->_height / 2)
				};
				this->_snake->_direction = glm::vec2(0.0, 0.0);
				
				this->_snake->_body.clear();
				this->_snake->_body.push_back(glm::vec2());

				generate_food_position();
			}
		}
	}
}

void controller::generate_food_position() {
	std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> map_width_dist(1, this->_map->_width);
    std::uniform_int_distribution<int> map_height_dist(1, this->_map->_height);
    this->_food._position = glm::vec2(map_width_dist(mt), map_height_dist(mt));
	std::cout << "[RANDOM::INT] --> " << this->_food._position.x << ":" << this->_food._position.y << std::endl;
}