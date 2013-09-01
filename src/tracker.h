#ifndef TRACKER_H
#define TRACKER_H
#include "ofxOpenCv.h"


class tracker
{
    public:
        tracker();
    void setupVideo();
    void findContours(bool showContours);
    void setBackGround();
    void getLines();
    void drawVideo();
    void drawReport();
    void setTresHold(int t);
    bool checkInVector(ofPoint p);


    ofVideoGrabber 		vidGrabber;
    ofxCvColorImage			colorImg;
    ofxCvGrayscaleImage 	grayImage;
	ofxCvGrayscaleImage 	grayBg;
	ofxCvGrayscaleImage 	grayDiff;
    ofxCvContourFinder 	contourFinder;
    int 				threshold;
	bool				Bakground;


    protected:
    private:
};

#endif // TRACKER_H

