#pragma once

#include "ofMain.h"
#include "Izzm.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofFbo fbo;
		float history;

		Izzm izzm;

		
};
