#pragma once

struct space_point
{
	float x;
	float y;
	float z;
};
class circle
{
public:
	float z;
	float x;
	float y;
	float r;
	circle(float x, float y, float r);
	circle();

	virtual space_point point(float t);
	virtual space_point vecctor(float t);
	virtual void send(float t);

};

class ellipse :public circle
{
public:
	float ry;
	ellipse(float x, float y, float r, float ry);
	space_point point(float t) override;
	space_point vecctor(float t) override;
	void send(float t) override;

};
class spring : public circle
{
public:
  float step;
  spring(float x, float y, float r, float step);
  space_point point(float t) override;
  space_point vecctor(float t) override;
  void send(float t) override;

};

