#pragma once

#include "ofMain.h"
#include "Izzm.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void mousePressed(int _x, int _y, int button);

		ofFbo fbo;
		float history;

		Izzm izzm;
		vector<Izzm*> izzms;
		int NUM_IZZM = 1;
};
