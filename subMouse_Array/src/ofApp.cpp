#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofBlendMode(ADD);

	for (int j = 0; j < NUM_IZZM; j++)
	{
		Izzm* i = new Izzm();
		izzms.push_back(i);
		i->setup(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0.1);
	}
	
	int w = ofGetWidth();
	int h = ofGetHeight();
	fbo.allocate(w, h, GL_RGBA32F_ARB);

	fbo.begin();
	ofClear(255, 255, 255);
	fbo.end();

	history = 0.995;
}

//--------------------------------------------------------------
void ofApp::update() {
	
	for (Izzm* i : izzms)
	{
		i->update();
		i->edges();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(42 - izzm.dBait, 0, 33 + izzm.dBait);

	fbo.begin();
	ofEnableAlphaBlending();
	float alpha = (1 - history) * 3333;
	ofSetColor(142, 0, 133, alpha);
	ofFill();
	ofRect(0, 0, ofGetWidth(), ofGetHeight());

	ofDisableAlphaBlending();
	
	for (Izzm* i : izzms)
	{
		i->display();
	}
	
	fbo.end();

	fbo.draw(0, 0);
	
}

void ofApp::mousePressed(int _x, int _y, int button)
{
	
		Izzm* i = new Izzm();
		izzms.push_back(i);
		i->setup(izzm.mouse.x, izzm.mouse.y, 0.1);

		if (izzms.size() >= 7) 
		{
			izzms.erase(izzms.begin());
		}
	
}

