#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <omp.h>
#include "figure.h"
#define pi 3.1415926535
using namespace std;

void main()
{
	srand(time(NULL));
	vector<circle*> box;			//Generating shapes
	for (int i = 0; i < 10; i++)
	{
		unsigned short choise = rand() % 3 + 1;
		switch (choise)
		{
			case 1:
			{
				float x, y, r;
				x = rand() % 11 - 5;
				y = rand() % 11 - 5;
				r = rand() % 10 + 1;
				box.push_back(new circle(x,y,r));
				break;
			}
			case 2:
			{
				float x, y, r1, r2;
				x = rand() % 11 - 5;
				y = rand() % 11 - 5;
				r1 = rand() % 10 + 1;
				r2 = rand() % 10 + 1;
				box.push_back(new ellipse(x,y,r1,r2));
				break;
			}
			case 3:
			{
				float x, y, r, step;
				x = rand() % 11 - 5;
				y = rand() % 11 - 5;
				r = rand() % 10 + 1;
				step = (rand() % 11 - 5)/(2*pi);
				box.push_back(new spring(x, y, r, step));
				break;
			}
		}
	}

	for (auto it = box.begin(); it != box.end(); it++)		//output of vectors and points at t=pi/4
		(*it)->send((pi / 4));


	vector<circle*> circle_box;								//Filtering circles
	for (auto it = box.begin(); it != box.end(); it++) 
	{
		if (typeid(**it) == typeid(circle)) 
		{
			circle_box.push_back(*it);
		}
	}
	
	sort(circle_box.begin(), circle_box.end(), [](const circle* p1, const circle* p2) //sorting by radii
	{
		return p1->r < p2->r;
	});



	float radius_sum = 0;									//Calculating the sum of radii
	#pragma omp parallel for reduction(+:radius_sum)
	for (int i = 0; i < circle_box.size(); i++)
	{
		radius_sum += circle_box[i]->r;
	}
	spring test(0, 0, 1,(1/(2*pi)));
	space_point aa = test.point(0);
	aa = test.point((2 * pi));
	box.clear();
	circle_box.clear();
	return;
}
