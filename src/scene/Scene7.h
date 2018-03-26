//
//  Scene7.h
//  FirstVJ
//
//  Created by 柴田将希 on 2018/03/26.
//
//

#ifndef Scene7_h
#define Scene7_h

#include <stdio.h>

#endif /* Scene7_h */
#pragma once

#include "ofMain.h"

#include "sceneBase.hpp"

class Scene7 : public sceneBase{
    
public:
    void setup();
    void update();
    void draw();
    /*
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    */
    ofVboMesh particles;
    ofShader render, updatePos;
    ofEasyCam cam;
  
    ofVec3f emitterPos, prevEmitterPos;
    int particleNum, texRes;
    bool showTex;
};
