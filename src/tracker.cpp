#include "tracker.h"

tracker::tracker()
{
    threshold = 80;
}

void tracker::setupVideo(){

    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(640,480);
    colorImg.allocate(640,480);
	grayImage.allocate(640,480);
	grayBg.allocate(640,480);
	grayDiff.allocate(640,480);

}
void tracker::setTresHold (int t) {

    threshold += t;
    cout << threshold << endl;

}
void tracker::drawReport(){
	// finally, a report:
	ofSetHexColor(0xffffff);
	stringstream reportStr;
	reportStr << "bg subtraction and blob detection" << endl
			  << "press ' ' to capture bg" << endl

			  << "num blobs found " << contourFinder.nBlobs << ", fps: " << ofGetFrameRate();

	ofDrawBitmapString(reportStr.str(), 20, 600);
}
void tracker::drawVideo(){

    // draw the incoming, the grayscale, the bg and the thresholded difference
	ofSetHexColor(0xffffff);
	//colorImg.draw(20,20);
	//grayImage.draw(360,20);
	grayImage.draw(0,0);
	//grayBg.draw(20,280);
	//grayDiff.draw(0,0);

}
void tracker::setBackGround()  {

    grayBg = grayImage;		// the = sign copys the pixels from grayImage into grayBg (operator overloading)
	cout << "New BG set" << endl;

}
void tracker::findContours(bool showContours)  {

    bool bNewFrame = false;
    vidGrabber.update();
	bNewFrame = vidGrabber.isFrameNew();


	if (bNewFrame){

		colorImg.setFromPixels(vidGrabber.getPixels(), 640,480);
	    grayImage = colorImg;


		// take the abs value of the difference between background and incoming and then threshold:
		grayDiff.absDiff(grayBg, grayImage);
		grayDiff.threshold(threshold);

		// find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
		// also, find holes is set to true so we will get interior contours as well....
		contourFinder.findContours(grayDiff, 20, (340*240), 2, false);	// find holes
        if (showContours) {
            for (int i = 0; i < contourFinder.nBlobs; i++){
                contourFinder.blobs[i].draw(0,0);
            }
        }

	}

}
void tracker::getLines() {

    /*
        int x1;int x2;int y1;int y2;
        int lowestX=1000;
        int highestX=0;
        int lowestY=1000;
        int highestY=0;
        for (int j=0;j<aP;j++) {

          int x = contourFinder.blobs[i].pts[j].x;
          int y = contourFinder.blobs[i].pts[j].y;
          if (x < lowestX) {lowestX = x;y1=y;}
          if (x > highestX) {highestX = x;y2=y;}
          if (y < lowestY) {lowestY = y;x1=x;}
          if (y > highestY) {highestY = y;x2=x;}

        }
        cout << lowestX << "," << highestX << "," << lowestY << "," << highestY << endl;

        ofSetHexColor(0xffffff);
        ofLine(lowestX+360,y1+540,x1+360,lowestY+540);
        ofLine(lowestX+360,y1+540,x2+360,highestY+540);
        ofLine(highestX+360,y2+540,x1+360,lowestY+540);
        ofLine(highestX+360,y2+540,x2+360,highestY+540);


        }
        */

}

bool tracker::checkInVector(ofPoint p)  {
bool hit=false;
for (int i = 0; i < contourFinder.nBlobs; i++){


        int aP = contourFinder.blobs[i].nPts;
        //cout << "Aantal points: " << aP << endl;
        for (int j=0;j<aP;j++) {

          int x = contourFinder.blobs[i].pts[j].x;
          int y = contourFinder.blobs[i].pts[j].y;
          if (ofDist(p.x,p.y,x,y)<20) {
          //if ((p.x == x) && (p.y == y)) {

            hit = true;
            cout << "Hit points: " << p.x << "," << p.y << endl;
          }

        }

}
return hit;

}
