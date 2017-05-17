#pragma once

#include "ofMain.h"
#include "ofxProcessFFT.h"
#include "ofxGui.h"
#include "korg.h"
#include "ofxEasyFft.h"
#include "sceneBase.hpp"

class Scene3 : public sceneBase{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void addIcosphereVertices();
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void resolutionChanged(int & resolution);
    void createMesh();
    
    ofSpherePrimitive sphere; // 球プリミティブ
    ofEasyCam cam;
    ofMesh mesh;
    vector<ofVec3f> currentVertex;
    ofImage img;
    ofTexture tex;
    ofLight light;
    
    ofSoundPlayer mySound;
    
    double angle;//傾きの角度
    int nBandsToGet;
    //Korg korg;
    
    
    // FFT分析
    // GUI
    // 入力レベル調整
    ofxPanel gui;
    ofxSlider<int> knob[8];
    ofxSlider<int> slider[8];
    
    
    // float * fft;
    ProcessFFT fft;
    ofImage lowNoiseImg;
    ofImage midNoiseImg;
    ofImage highNoiseImg;
    
    ofxFloatSlider level;
    ofxIntSlider resolution;
    ofxFloatSlider noiseFrequency;
    
};
