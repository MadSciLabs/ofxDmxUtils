//
//  ofxDmxUtils.h
//  OFX_DMX_UTILS
//
//  Created by Rui Pereira(rux) for MadSci-Labs @HAVASWW on 9/6/12.
//
//

#ifndef ofxDmxUtils_h
#define ofxDmxUtils_h

#include "ofMain.h"

class ofxDmxUtils{
public:

    // the Rotation settings are based on the Chauvet Moving head light - Chauvet Intimidator 250 / 150
    // http://www.chauvetlighting.com/    //
    // for more info pls check manuals at:
    // http://www.chauvetlighting.com/products/manuals/Intimidator_Spot_LED_250_QRG_Rev8_ML_WO.pdf
    // http://www.chauvetlighting.com/products/generic/Intimidator_Spot_LED_150_QRG_Rev1_ML_WO.pdf

    static ofPoint setRotation(float _pct, float _axisMax, int _fineStep = 3);
    
    static ofColor getColorAt(float _pct, ofImage &_imgSrc );

};

#endif