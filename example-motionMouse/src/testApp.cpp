#include "testApp.h"



//--------------------------------------------------------------
void testApp::setup() {
    
  // setup DMX
    DMX.connect();

    // these settings are for a Moving head light - Chauvet Intimidator 250
    // http://www.chauvetlighting.com/intimidator-spot-led-250
    //
    // for more info pls check manual at:
    // http://www.chauvetlighting.com/products/manuals/Intimidator_Spot_LED_250_QRG_Rev8_ML_WO.pdf

    // setup active Gobo
    activeGobo = 24;
    
    panMax = 540;
    tiltMax = 270;
    
    
    
    // some DMX channels
    DMX.setLevel(6, 0);                                     // set color wheel (0-127) or cycle speed (128-255)
    DMX.setLevel(11, 4);                                    // shutter (0-3 blackout; 4 - 7 open; 8-215 strobe)
    DMX.setLevel(10, 255);                                  // dimmer 0-255
    DMX.setLevel(7, activeGobo);                            // choose gobo
    DMX.setLevel(12, 0);                                    // control functions
    DMX.setLevel(9, 0);                                     // set prism
    DMX.setLevel(8, 0);                                     //set gobo rotation (0-63 indexing), 64-147 rotation speed. +inverse
    DMX.update();
    
    
    string info;

        // set dmx to follow mouse
        //
        //  scale mouse position to moving head wider angles of motion
        panScaled = ofMap(mouseX, 0, ofGetWidth(), 0.5, 0.5,true);
        tiltScaled = ofMap(mouseY, 0,ofGetHeight(), 0.5, 0.0,true);
        
        // using ofxDmxUtils setrotation to calculate the fine and coarse channels for each axys (pan/tilt)
        DMX.setLevel(1, ofxDmxUtils::setRotation(panScaled, panMax).x);
        DMX.setLevel(2, ofxDmxUtils::setRotation(panScaled, panMax).y);
        
        DMX.setLevel(3, ofxDmxUtils::setRotation(tiltScaled, tiltMax).x);
        DMX.setLevel(4, ofxDmxUtils::setRotation(tiltScaled, tiltMax).y);
        
        info += "hand X: " + ofToString(handPosition.x) + "  scaled: " + ofToString(panScaled) + "\nhand Y: "+ ofToString(handPosition.y)+ "  scaled: " + ofToString(tiltScaled);
    
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){

    
    // draw some info regarding hand pos and scaled values
	ofSetColor(0, 255, 0);
	ofDrawBitmapString(info, 20, ofGetHeight()-20);
}


//--------------------------------------------------------------
void testApp::exit(){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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