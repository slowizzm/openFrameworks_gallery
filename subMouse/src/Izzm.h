#pragma once

#include "ofMain.h"

class Izzm
{

public:
	Izzm();
	void setup(float _x, float _y, float _v);
	void update();
	void display();
	
	ofVec2f pos, vel, acc, mouse;
	float dBait;
};
