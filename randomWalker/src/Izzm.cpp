#include "Izzm.h"

Izzm::Izzm() {
	theta = 0.0001f;
}

void Izzm::setup(float _x, float _y, float _v)
{
	v = _v;
	pos = ofVec2f(_x, _y);
	vel = ofVec2f(_v, _v);
	acc = ofVec2f(0,sin(333));
}

void Izzm::update()
{
	vel += acc;
	pos += vel;
	vel.normalize();
	//acc *= v;
	theta += ofRadToDeg(v);
}

void Izzm::display()
{	
	ofRotate(theta / 333);
	ofPushMatrix();
	ofTranslate(pos.x, pos.y);
	ofRotate(theta / 333);
	ofSetLineWidth(v);
	ofSetColor(0,ofMap(pos.x, 0, ofGetWidth(), 0, ofMap(ofGetHeight(), 0, ofGetHeight() * 2, 0, 255)), ofMap(pos.x, 0, ofGetWidth(), 0, ofMap(ofGetHeight(), 0, ofGetHeight() * 2, 0, 255)),100);
	ofNoFill();
	ofEllipse(0,0, ofMap(pos.x,0,ofGetWidth(),3,11), ofMap(pos.y,0,ofGetHeight(),3,11));
	ofPopMatrix();

	ofPushMatrix();
	ofTranslate(pos.x, pos.y);
	ofRotate(theta/333);
	ofSetLineWidth(3);
	ofSetColor(ofMap(pos.x, 0, ofGetWidth(), 0, ofMap(ofGetHeight(),0,ofGetHeight()*2,0,255)), ofMap(ofGetHeight(), 0, ofGetHeight()*2, 0, ofMap(pos.y,0,1,0,10)), v*333);
	ofNoFill();
	ofRect(0, 0, v/pos.x, v*pos.y/333);
	ofPopMatrix();

	ofPushMatrix();
	ofTranslate(pos.x, pos.y);
	ofRotate(theta * -333*33*3);
	ofSetLineWidth(3);
	ofSetColor(ofMap(pos.x, 0, ofGetWidth(), 0, ofMap(ofGetHeight(), 0, ofGetHeight() * 2, 0, 255)), ofMap(ofGetHeight(), 0, ofGetHeight() * 2, 0, ofMap(pos.y, 0, 1, 0, 10)), v * 333,133);
	ofFill();
	ofRect(0, 0, v*13,v*13,v);
	ofPopMatrix();

	

}

void Izzm::edges()
{
	if (pos.x <= ofGetWidth()*0.3 || pos.x >= ofGetWidth()*0.7)
	{
		vel.x *= -1;
	}

	if (pos.y <= ofGetHeight()*0.3 || pos.y >= ofGetHeight()*0.7)
	{
		vel.y *= -1;
	}

	if (pos.y > ofGetHeight()*0.73)
	{
		pos.x = ofGetWidth() / 2;
		pos.y = ofGetHeight() / 2;
	}

}