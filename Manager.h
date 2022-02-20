#pragma once
class Manager
{
	public:
		bool change;
		float changefactor;

		float getRedVal();
		float getGreenVal();
		float getBlueVal();

		void setRedVal(float val);
		void setGreenVal(float val);
		void setBlueVal(float val);

	private:
		float rr, gg, bb;
};