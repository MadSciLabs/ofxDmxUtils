//
//  ofxDmxUtils.cpp
//  OFX_DMX_UTILS
//
//  Created by Rui Pereira(rux) for MadSci-Labs @HAVASWW on 9/6/12.
//
//

#include "ofxDmxUtils.h"
    
// ----------------------------------
ofPoint ofxDmxUtils::setRotation(float _pct, float _axisMax, int _fineStep){
    ofPoint dmxChannels;
    
    float val    = _pct*255.0;
    int coarse   = floor(val);
    int fine     = round((val-coarse)*_axisMax/_fineStep);
    
    dmxChannels.set(coarse,fine);
    return dmxChannels;
    

}

// ----------------------------------
ofColor ofxDmxUtils::getColorAt(float _pct,  ofImage &_imgSrc){
    
    ofColor clr;
    ofPixels pixels = _imgSrc.getPixelsRef();
    
    // automatically choose the gradient direction based on the longest width/height image dimensions
    
    if (_imgSrc.width > _imgSrc.height) {
        
        clr= pixels.getColor(ofMap(_pct, 0.0, 1.0, 0, _imgSrc.width-1, true), 0);

    } else {
        
        clr= pixels.getColor(0,ofMap(_pct, 0.0, 1.0, 0, _imgSrc.height-1, true));

    }
    return clr;

    
}
