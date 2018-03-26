//
//  Scene8.h
//  FirstVJ
//
//  Created by 柴田将希 on 2018/03/26.
//
//

#ifndef Scene8_h
#define Scene8_h

//#include <stdio.h>

#endif /* Scene8_h */
#pragma once

//
//  Scene6.h
//  FirstVJ
//
//  Created by √ä√º¬•√Å√Æ‚àû√Ç‚àû√ú√Ç‚àè√• on 2017/06/15.
//
//
#include <stdio.h>

#include "ofMain.h"
#include "ofxProcessFFT.h"
#include "ofxGui.h"
#include "ofxEasyFft.h"
#include "ofxPostGlitch.h"
#include "sceneBase.hpp"
#include "korg.h"
#include "ofxTrueTypeFontUC.h"
#define NUM 220
class Scene8 : public sceneBase{
    
public:
    void setup();
    void update();
    void draw();
   	void keyPressed(int key);
    void keyReleased(int key);
    void audioReceived (float * input, int bufferSize,
                        int nChannels);
    
    
    
    
    // ofImage cameraImage;
    
    //  ofVideoPlayer fingersMovie;
    ofxPostGlitch postGlitch;
    ofFbo buffer;
    Korg korg;
    
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
   // ofTrueTypeFont font;
    ofxTrueTypeFontUC font;
    int fontX; //フォントX軸の位置の宣言
    int fontY; //フォントY軸の位置の宣言
      char text[255]; //テキストデータの変数の宣言
    
    
    ofImage img1;
    ofImage img2;
    ofImage img3;
    ofBoxPrimitive box, mBox[NUM];
     
    int boxSize;
    float angle; //回転角度
    ofEasyCam cam;
    ProcessFFT fft;
    ofVec2f p, vec;
    
    ofImage BackgroundImage;
    ofImage lowNoiseImg;
    ofImage midNoiseImg;
    ofImage highNoiseImg;
    ofSoundPlayer sound;
    ofxFloatSlider level;
    ofSoundPlayer mySound;
    float *volume;
    float* fftSmoothed;
    int nBandsToGet;
    
    
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

