#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	izzm = Izzm();
	izzm.setup(ofGetWidth() / 2, ofGetHeight() / 2, 0.1);
	
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
	
	izzm.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(42, 0, 33);

	fbo.begin();
	ofEnableAlphaBlending();
	float alpha = (1 - history) * 3333;
	ofSetColor(157, 157, 157, alpha);
	ofFill();
	ofRect(0, 0, ofGetWidth(), ofGetHeight());

	ofDisableAlphaBlending();
	
	izzm.display();
	
	fbo.end();

	fbo.draw(0, 0);
	
}

