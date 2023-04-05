#ifndef MAP_H
#define MAP_H

class map {
public:
	map(unsigned int width, unsigned int height);
	map(const map&) = default;
	map(map&&) = default;
	~map();
public:
	unsigned int _width;
	unsigned int _height;
};

#endif