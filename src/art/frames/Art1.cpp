#include "Art1.h"

using namespace iFish;

Art1::Art1()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Concrete Art 1 init");
}

void Art1::update()
{

}

void Art1::draw()
{
	ofSetColor(ofFloatColor(250, 0, 0));

	//ofDrawCircle(ofPoint(400, 400), 30);

	for (int j = 0; j < points.size(); ++j)
	{
		ofDrawCircle(points[j], 5);
		if (j > 0) 
		{
			ofDrawLine(points[j - 1], points[j]);
		}
	}
}

Art1::~Art1()
{

}
