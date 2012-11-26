ofxDmxUtils
=====================================

ofxDmxUtils are a set of methods to interact with lighting and robotic fixtures through the DMX protocol and ofxDMX.
(work in progress!)


Installation
------------
As with other OpenFrameworks add ons, just drop the folder into the `openFrameworks/addons/` folder.

Use
------------
static ofColor getColorAt(float _pct, ofImage &_imgSrc );
allows you to retrieve a color from a given image map,
this will allow you to create and use image gradients and color maps as a color source for your DMX fixture.
this method will automatically select the dimension it will navigate based on the largest image dimension.

static ofPoint setRotation(float _degPct, float _axisMax, int _fineStep = 3);
makes it easier to control some robotic fixtures rotation - where the rotation angle is controlled by two different channels for coarse and fine adjustments in order to get higher resolutions of control.
.x returns coarse control channel 
.y returns fine control channel
 
Known issues
------------
setRotation class is based on Chauvet's Intimidator moving head series (150/250),
should work fine with other models and brands with minor adjustments - pls see your specific model manual for fine step range adjustments.


Version history
------------
### Version 0.1 (Nov 2012):


