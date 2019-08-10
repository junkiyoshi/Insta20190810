#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(3);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(90);

	auto radius = 100;
	vector<glm::vec3> locations;

	for (auto i = 0; i < 6; i++) {

		auto z = ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.003), 0, 1, -150, 150);
		for (auto deg = 0; deg < 360; deg += 10) {

			locations.push_back(glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), z));
		}
	}

	for (auto& location : locations) {

		ofDrawSphere(location, 3);

		for (auto& other : locations) {

			float distance = glm::distance(location, other);
			if (distance < 35) {

				ofDrawLine(location, other);
			}
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}