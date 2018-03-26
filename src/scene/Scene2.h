#pragma once

#include "ofMain.h"
#include "korg.h"
#include "ofxGui.h"
#include "ofxProcessFFT.h"
#include "ofxEasyFft.h"
#include "sceneBase.hpp"

class Scene2 : public sceneBase{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofSoundPlayer mySound;
    
    
    ProcessFFT fft;
    ofImage lowNoiseImg;
    ofImage midNoiseImg;
    ofImage highNoiseImg;
    
    ofxFloatSlider level;
    ofxIntSlider resolution;
    ofxFloatSlider noiseFrequency;

    int nBandsToGet;
    
    ofSpherePrimitive mSphere[200];
    float rad;
    
    Korg korg;
    
    ofxPanel gui;
    ofxSlider<int> knob[8];
    ofxSlider<int> slider[8];
};
