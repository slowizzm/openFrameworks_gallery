#include "Izzm.h"

Izzm::Izzm()
{
	
}

void Izzm::setup(float _x, float _y, float _v)
{
	pos = ofVec2f(_x, _y);
	vel = ofVec2f(0,0);
	acc = ofVec2f(0,0);
}

void Izzm::update()
{
	mouse = ofVec2f(ofGetMouseX(), ofGetMouseY());
	dBait = ofDist(pos.x, pos.y, mouse.x, mouse.y);
	
	acc = mouse -= pos;
	acc *= ofMap(dBait, 0,ofGetWidth()*2,0.00003,33);
	acc.limit(33);
	vel.normalize();
	vel += acc;
	pos += vel;
	

	
}

void Izzm::display()
{
	if (dBait < 3) 
	{
		ofSetLineWidth(3);
		ofSetColor(255 - dBait, 33, 133 + dBait);
		ofNoFill();
		ofRect(pos.x, pos.y, dBait,dBait);
	}
	else
	{
		ofSetLineWidth(3);
		ofSetColor(255-dBait,33,133+dBait);
		ofNoFill();
		ofSetColor(255, 255, 0);
		ofFill();
		ofEllipse(pos.x, pos.y, dBait/33,dBait/33);
	}
}

void Izzm::edges()
{
	if (pos.x <= 0 || pos.x >= ofGetWidth())
	{
		vel.x *= -1;
	}

	if (pos.y <= 0 || pos.y >= ofGetHeight())
	{
		vel.y *= -1;
	}
}
