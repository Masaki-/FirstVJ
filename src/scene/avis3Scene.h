#pragma once

#include "ofMain.h"
#include "ofxProcessFFT.h"
#include "ofxGui.h"
#include "sceneBase.hpp"

class avis3Scene : public sceneBase {
    
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
    void createMesh();
    
    ofEasyCam cam;
    ofMesh mesh;
    vector<ofVec3f> currentVertex;
    ofImage img;
    ofTexture tex;
    ofLight light;
    ofSpherePrimitive sphere; // 球プリミティブ
    ofSoundPlayer mySound;
    float * Fft;
    ProcessFFT fft;
    ofImage lowNoiseImg;
    ofImage midNoiseImg;
    ofImage highNoiseImg;
    int nBandsToGet;
    ofxFloatSlider level;
};
