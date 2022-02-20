#pragma once

#include "ofMain.h"

class RGBCell
{
	public:
		ofVec2f coordinates;

		RGBCell();
		RGBCell(float x, float y, float d);
		void Draw();
		void Draw2();
		void Update(int state);
		void UpdateImage();
		void UpdateNoise(float rr, float gg, float bb);
		void SetColors(float r, float g, float b);
		void ChangeTo(float rr, float gg, float bb, int durationInSecs, int delayInSecs);
	
	private:
		ofVec2f position;
		float width, height;
		float r, g, b, lr, lg, lb, tr, tg, tb;
		int delay, startTime, endTime, currentTime, state;
		bool isChanging;

		float GetAnimationValue(float start, float end, int startTime, int endTime, int currentTime);
		float Calculate(float t);
};