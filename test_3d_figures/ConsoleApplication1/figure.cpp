#include "figure.h"
#include <math.h>
#include <iostream>


circle::circle(float x, float y, float r)
{
	this->x = x;
	this->y = y;
	this->z = 0;
	this->r = r;
}

circle::circle() {};

space_point circle::point(float t)
{
	space_point answer;
	answer.x = this->r * cos(t) + this->x;
	answer.y = this->r * sin(t) + this->y;
	answer.z = 0;
	return answer;
}

space_point circle::vecctor(float t)
{
	space_point answer;
	answer.x = (-1) * this->r * sin(t) + this->x;
	answer.y = this->r * cos(t) + this->y;
	answer.z = 0;
	return answer;
}
void circle::send(float t)
{
	space_point answer = this->point(t);
	std::cout << "circle\npoint: x = " <<answer.x <<"\ty = "<<answer.y << "\tz= " << answer.z<< std::endl;
	answer = this->vecctor(t);
	std::cout << "vector: x = " << answer.x << "\ty = " << answer.y << "\tz= " << answer.z << std::endl << std::endl;
}



ellipse::ellipse(float x, float y, float r, float ry) : circle(x, y, r)
{
	this->ry = ry;
}

space_point ellipse::point(float t)
{
	space_point answer;
	answer.x = this->r * cos(t) + this->x;
	answer.y = this->ry * sin(t) + this ->y;
	answer.z = 0;
	return answer;
}

space_point ellipse::vecctor(float t)
{
	space_point answer;
	answer.x = (-1) * this->r * sin(t) + this->x;
	answer.y = this->ry * cos(t) + this->y;
	answer.z = 0;
	return answer;
}

void ellipse::send(float t)
{
	space_point answer = this->point(t);
	std::cout << "ellipse\npoint: x = " << answer.x << "\ty = " << answer.y << "\tz= " << answer.z << std::endl;
	answer = this->vecctor(t);
	std::cout << "vector: x = " << answer.x << "\ty = " << answer.y << "\tz= " << answer.z << std::endl<< std::endl;
}

spring::spring(float x, float y, float r, float step) : circle(x, y, r)
{
	this->step = step;
}

space_point spring::point(float t)
{
	space_point answer;
	answer.x = this->r * cos(t) + this->x;
	answer.y = this->r * sin(t) + this->y;
	answer.z = step * t;
	return answer;
}

space_point spring::vecctor(float t)
{
	space_point answer;
	answer.x = (-1) * this->r * sin(t) + this->x;
	answer.y = this->r * cos(t) + this->y;
	answer.z = this->step;
	return answer;
}
void spring::send(float t)
{
	space_point answer = this->point(t);
	std::cout << "spring\npoint: x = " << answer.x << "\ty = " << answer.y << "\tz= " << answer.z << std::endl;
	answer = this->vecctor(t);
	std::cout << "vector: x = " << answer.x << "\ty = " << answer.y << "\tz= " << answer.z << std::endl << std::endl;
}
