#pragma once

#include "ofMain.h"
#include "Izzm.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	ofFbo fbo;
	float history;

	Izzm izzm;
	vector<Izzm*> izzms;
	int NUM_IZZM = 42;

	ofImage bHole_top, bHole_bottom;

};
