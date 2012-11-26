#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"

#include "ofxDmx.h"
#include "ofxDmxUtils.h"

class testApp : public ofBaseApp{

public:
    
	void setup();
	void update();
	void draw();
    void exit();
    
	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
    
    // DMX stuff
    ofxDmx DMX;
    int activeGobo;
    
    float panMax;
    float tiltMax;
    
    float panScaled;
    float tiltScaled;

};

#endif
