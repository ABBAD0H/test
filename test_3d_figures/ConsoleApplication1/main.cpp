#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <omp.h>
#include "figure.h"
#define pi 3.1415926535


void main()
{
	srand(time(NULL));
	std::vector<circle*> box;			//Генерация фигур
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

	for (auto it = box.begin(); it != box.end(); it++)		//вывод векторов и точек при t=pi/4
		(*it)->send((pi / 4));


	std::vector<circle*> circle_box;								//Фильтрация по кругам
	for (auto it = box.begin(); it != box.end(); it++) 
	{
		if (typeid(**it) == typeid(circle)) 
		{
			circle_box.push_back(*it);
		}
	}
	
	sort(circle_box.begin(), circle_box.end(), [](const circle* p1, const circle* p2) //сортировка по радиусам
	{
		return p1->r < p2->r;
	});



	float radius_sum = 0;									//Подсчет суммы радиусов
	#pragma omp parallel for reduction(+:radius_sum)
	for (int i = 0; i < circle_box.size(); i++)
	{
		radius_sum += circle_box[i]->r;
	}

	box.clear();
	circle_box.clear();
	return;
}
