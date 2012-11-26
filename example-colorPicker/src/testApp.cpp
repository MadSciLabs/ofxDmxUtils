#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);

    // = = = setup DMX = = =
    DMX.connect(0);
    
    // load the image and setup a rectangle for bounds checking
    clrScheme.loadImage("clrScheme.jpg");
    imgRect.set(20, 20, clrScheme.width, clrScheme.height);
}

//--------------------------------------------------------------
void testApp::update(){
    
    DMX.setLevel(1, clr.r);
    DMX.setLevel(2, clr.g);
    DMX.setLevel(3, clr.b);
    
	DMX.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    
// draw the image map
    ofSetColor(255);
    clrScheme.draw(imgRect.x,imgRect.y, clrScheme.width, clrScheme.height);
//draw a rect in the bottom for the color picked feedback
    ofSetColor(clr);
    ofRect(imgRect.x, imgRect.y+ imgRect.height, imgRect.width, imgRect.width);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
 }

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

    // check if the mouse position is inside the image and if so selected the color for DMX
    if (imgRect.inside(x, y)) {
        float pct = ofMap(y, imgRect.y, imgRect.y +imgRect.height, 0.0, 1.0);
        clr = ofxDmxUtils::getColorAt(pct, clrScheme);
    }

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

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}