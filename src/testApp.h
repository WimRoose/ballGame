#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "tracker.h"

struct Ball {
    int x;
    int y;
    int vx;
    int vy;
    int radius;
};


class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();


    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    bool				bLearnBakground;
    tracker t;

    Ball ball;

};

#endif
