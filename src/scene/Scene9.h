//
//  Scene9.h
//  FirstVJ
//
//  Created by 柴田将希 on 2018/03/26.
//
//

#ifndef Scene9_h
#define Scene9_h

#include <stdio.h>

#endif /* Scene9_h */
#pragma once


//#include "ofxKinect.h"

#include "ofMain.h"
#include "ofxProcessFFT.h"
#include "ofxGui.h"
#include "ofxEasyFft.h"
#include "ofxPostGlitch.h"
#include "sceneBase.hpp"
#include "korg.h"
#include "ofxTrueTypeFontUC.h"
class Scene9 : public sceneBase{
    
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
    
    void audioReceived (float * input, int bufferSize,
                        int nChannels);
   // ofxKinect kinect;
    ofImage cameraImage;
    
    ofVideoPlayer fingersMovie;
    ofxPostGlitch postGlitch;
    ofFbo buffer;
    Korg korg;
    ofxTrueTypeFontUC font;
    ofxPanel gui;
    ofxSlider<int> knob[8];
    ofxSlider<int> slider[8];
    
    int sampleRate; //サンプリング周波数
    float pan; //定位
    float amp; //音量
    float phase; //位相
    float frequency; //周波数
    
    int bufSize; //バッファーサイズ
    float * left; //左チャンネルのサンプル
    float * right; //右チャンネルのサンプル
    ofTrueTypeFont Futura;
    
    ofImage img1;
    ofImage img2;
    ofImage img3;
    
    void drawByGL(ofMatrix4x4 * mat);
    void createOctaByMesh(ofMatrix4x4 * mat);
    void createOctaByVbo(ofMatrix4x4 * mat);
    void createOctaByVboMesh(ofMatrix4x4 * mat);
    
    ofMatrix4x4 m;
    ofMesh mesh;
    ofVbo vbo;
    ofVboMesh vboMesh;
    
    vector<ofVec3f> ov = {
        ofVec3f(1,0,0), ofVec3f(-1,0,0), ofVec3f(0,1,0),
        ofVec3f(0,-1,0), ofVec3f(0,0,1), ofVec3f(0,0,-1)
    };
    vector<unsigned> oi = {
        0, 2, 4, 0, 4, 3, 0, 3, 5, 0, 5, 2,
        1, 2, 5, 1, 5, 3, 1, 3, 4, 1, 4, 2
    };
    
    
};
