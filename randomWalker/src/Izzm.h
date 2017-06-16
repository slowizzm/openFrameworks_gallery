#pragma once

#include "ofMain.h"

class Izzm
{

public:
	Izzm();
	void setup(float _x, float _y, float _v);
	void update();
	void display();
	void edges();

	ofVec2f pos, vel, acc;
	float v, theta;
};
