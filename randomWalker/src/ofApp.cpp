#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofBlendMode(ADD);
	
	//NUM_IZZM = 100;
	ofSetBackgroundAuto(false);

	for (int j = 0; j < NUM_IZZM; j++)
	{
		Izzm* i = new Izzm();
		izzms.push_back(i);
		i->setup(ofRandom(ofGetWidth()/2-33,ofGetWidth()/2+33), ofGetHeight() / 2, sin(ofRandom(9000)));
	}

	int w = ofGetWidth();
	int h = ofGetHeight();
	fbo.allocate(w, h, GL_RGBA32F_ARB);

	fbo.begin();
	ofClear(255, 255, 255);
	fbo.end();

	history = 0.995;

	bHole_top.load("bHole_top.png");
	bHole_bottom.load("bHole_bottom.png");
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
	ofBackground(0, 0, 0);
	ofEnableAlphaBlending();
	ofSetColor(103, 0, 0); // a dark red  
	bHole_top.draw(0, 0);
	ofDisableAlphaBlending();

	fbo.begin();
	ofEnableAlphaBlending();
	float alpha = (1 - history) * 9000;
	ofSetColor(157, 157, 157, alpha);
	ofFill();
	ofRect(0, 0, ofGetWidth(), ofGetHeight());

	ofDisableAlphaBlending();

	for (Izzm* i : izzms)
	{
		i->display();
	}
	fbo.end();

	fbo.draw(0, 0);
	ofEnableAlphaBlending();
	ofSetColor(127, 0, 0); // a dark red  
	bHole_bottom.draw(0, 0);
	ofDisableAlphaBlending();
}

