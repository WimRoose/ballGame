#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0, 0, 0);
    ofSetFrameRate(30);
    t.setupVideo();

    for (int i=0; i<10; i++) {
        ball.x = ofRandomWidth();
        ball.y = ofRandomHeight();
        ball.vx = 5;
        ball.vy = 5;
        ball.radius = 20;
    }

}

//--------------------------------------------------------------
void testApp::update() {


int sec= (time(NULL) % 200) / 2;
cout << sec << endl;
        ball.x = ball.x + ball.vx;
        ball.y = ball.y + ball.vy;

        if (ball.x<0 || ball.x > 620) {
            ball.vx = -ball.vx;
        }

        if (ball.y<0 || ball.y > 460) {
            ball.vy = -ball.vy;
        }

        ofPoint p;
        p.set(ball.x,ball.y);
        if (t.checkInVector(p)) {

            ball.vx = -ball.vx;
            ball.vy = -ball.vy;

        };




}

//--------------------------------------------------------------
void testApp::draw(){

    t.drawVideo();
    t.findContours(true);
    ofSetColor(255, 255, 0);
    ofCircle(ball.x, ball.y, ball.radius);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
switch (key){
		case ' ':
			t.setBackGround();
			cout << "key pressed" << endl;
			break;
        case 'a':
            t.setTresHold(5);
            break;
        case 'q':
            t.setTresHold(-5);
            break;

	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}
