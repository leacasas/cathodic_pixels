#include "RGBCell.h"
#include <ofMain.h>

RGBCell::RGBCell(){}

RGBCell::RGBCell(float x, float y, float d)
{
	this->position = ofVec2f(x * d, y * d);
	this->coordinates = ofVec2f(x, y);
	this->width = d / 3;
	this->height = d;
	this->r = this->lr = this->tr = 0;
	this->g = this->lg = this->tg = 0;
	this->b = this->lb = this->tb = 0;
	this->isChanging = false;
	this->endTime = this->startTime = this->currentTime = 0;
	this->state = 0;
	this->delay = 0;
}

void RGBCell::SetColors(float r, float g, float b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

void RGBCell::ChangeTo(float rr, float gg, float bb, int durationInSecs, int delayInSecs)
{
	this->isChanging = true;
	this->tr = rr;
	this->tg = gg;
	this->tb = bb;
	this->delay = delay;
	this->startTime = ofGetFrameNum();
	this->endTime = ofGetFrameNum() + 180;
	this->currentTime = 0;
}


void RGBCell::Update(int state)
{
	if (state == 0)
	{
		this->UpdateNoise(1, 1, 1);
	}
	else if (state == 1)
	{
		this->UpdateImage();
	}
	else if (state == 2)
	{
		this->UpdateImage();
	}
	else if (state == 3)
	{
		this->UpdateImage();
	}
	else if (state == 4)
	{
		this->UpdateImage();
	}
}

void RGBCell::UpdateImage()
{
	if (!this->isChanging) return;

	int f = ofGetFrameNum();

	if (f > this->endTime)
	{
		this->isChanging = false;
		return;
	}

	if (f >= this->startTime)
	{
		this->lr = this->r;
		this->lg = this->g;
		this->lb = this->b;
		this->r = this->GetAnimationValue(this->r, this->tr, this->startTime, this->endTime, f);
		this->g = this->GetAnimationValue(this->g, this->tg, this->startTime, this->endTime, f);
		this->b = this->GetAnimationValue(this->b, this->tb, this->startTime, this->endTime, f);
	}
}

float RGBCell::GetAnimationValue(float start, float end, int startTime, int endTime, int currentTime)
{
	float diff = end - start;
	float t = (currentTime - startTime) / (float)((endTime - startTime));
	float res = start + this->Calculate(t) * diff;
	return res;
}

float RGBCell::Calculate(float t)
{
	return 1 - (1 - (t * t)) * (1 - (t * t));
}

void RGBCell::UpdateNoise(float rr, float gg, float bb)
{
	float f = (ofGetElapsedTimeMillis() * 0.00075);
	float x = this->position.x / (ofGetHeight() / 4);
	float y = this->position.y / (ofGetWidth() / 4);
	this->r = (ofSignedNoise(x, y, 0, 0+f) / 2 + .5);this->r *= this->r * rr;
	this->g = (ofSignedNoise(x, y, 3, 3+f) / 2 + .5);this->g *= this->g * gg;
	this->b = (ofSignedNoise(x, y, 6, 6+f) / 2 + .5);this->b *= this->b * bb;
}

void RGBCell::Draw()
{
	ofSetColor(ofColor::red);
	ofDrawRectangle(this->position.x + this->width * 1, this->position.y + this->height, this->width, this->height * this->r);
	
	ofSetColor(ofColor::green);
	ofDrawRectangle(this->position.x + this->width * 2, this->position.y + this->height, this->width, this->height * this->g);

	ofSetColor(ofColor::blue);
	ofDrawRectangle(this->position.x + this->width * 3, this->position.y + this->height, this->width, this->height * this->b);
}

void RGBCell::Draw2()
{
	ofSetColor(ofColor::red);
	ofDrawRectangle(this->position.x + this->width, this->position.y + this->height * 1, this->height * this->r, this->width);

	ofSetColor(ofColor::green);
	ofDrawRectangle(this->position.x + this->width, this->position.y + this->height * 2, this->height * this->g, this->width);

	ofSetColor(ofColor::blue);
	ofDrawRectangle(this->position.x + this->width, this->position.y + this->height * 3, this->height * this->b, this->width);
}