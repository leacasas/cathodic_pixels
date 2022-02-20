#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	this->state = this->recframeNum = 0;
	this->recordEnabled = false;

	float size = 12;
	int rows = ofGetHeight() / size;
	int cols = ofGetWidth() / size;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			RGBCell c = RGBCell(j, i, size);
			float r = (ofSignedNoise(j * size / 6, i * size / 6, 0) / 2 + .5);
			float g = (ofSignedNoise(j * size / 6, i * size / 6, 2) / 2 + .5);
			float b = (ofSignedNoise(j * size / 6, i * size / 6, 4) / 2 + .5);
			c.SetColors(r, g, b);
			cells.push_back(c);
		}
	}
}

//--------------------------------------------------------------
void ofApp::update()
{
	size_t length = cells.size();
	for (size_t i = 0; i < length; i++)
	{
		cells[i].Update(this->state);
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(0);

	size_t length = cells.size();
	for (size_t i = 0; i < length; i++)
	{
		cells[i].Draw();
	}

	if (this->recordEnabled)
	{
		ofSaveScreen("frames/" + ofToString(this->recframeNum++) + ".png");
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
	if (key == 's')
		ofSaveScreen("screenshots/" + ofToString(ofGetFrameNum()) + ".png");

	if (key == 'C')
	{
		this->recordEnabled = !this->recordEnabled;
		this->recframeNum = 0;
	}

	if (key == 'r')
	{
		manager.setRedVal(1);
	}
	else if (key == 'g')
	{
		manager.setGreenVal(1);
	}
	else if (key == 'b')
	{
		manager.setBlueVal(1);
	}
	else if (key == 'R')
	{
		manager.setRedVal(0);
	}
	else if (key == 'G')
	{
		manager.setGreenVal(0);
	}
	else if (key == 'B')
	{
		manager.setBlueVal(0);
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	this->state++;

	if (this->state > 4)
		this->state = 0;

	if (this->state == 1)
	{
		img.load("girl_80.jpg");
	}
	else if (this->state == 2)
	{
		img.load("monalisa_80.jpg");
	}
	else if (this->state == 3)
	{
		img.load("vangogh_80.jpg");
	}
	else if (this->state == 4)
	{
		img.load("scream_80.jpg");
	}

	size_t length = cells.size();
	for (size_t i = 0; i < length; i++)
	{
		auto coords = cells[i].coordinates;
		ofColor color = img.getColor(coords.x, coords.y);
		cells[i].ChangeTo(color.r / 255.0, color.g / 255.0, color.b / 255.0, 5, 0);
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
