//
//  Scene7.cpp
//  FirstVJ
//
//  Created by 柴田将希 on 2018/03/26.
//
//

#include "Scene7.h"
float xNoise;
float yNoise;
static float angle;
//--------------------------------------------------------------
void Scene7::setup() {
    
    ofSetFrameRate(30);
    ofBackground(39);
    ofSetWindowTitle("Insta");
    
    ofNoFill();
    ofSetColor(239, 39, 39, 139);
    // ofSetColor(39, 239, 39, 139);
    // ofSetColor(39, 39, 239, 139);
    
    ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
    xNoise = 0.2;
    yNoise = 0.2;
}

//--------------------------------------------------------------
void Scene7::update() {
    xNoise += 0.1;
    yNoise += 0.1;}

//--------------------------------------------------------------
void Scene7::draw() {
    
    ofTranslate(ofGetWidth() / 2+ofNoise(xNoise)*50, ofGetHeight() / 2);
    
    float radius = 100;
    for (int deg_param = 0; deg_param < 360 * 3; deg_param += 1) {
        
        float deg = deg_param + 0.5;
        float x = radius * cos(deg * DEG_TO_RAD);
        float y = radius * sin(deg * DEG_TO_RAD);
        
        
        ofPushMatrix();
        ofTranslate(x, y);
        
        ofBeginShape();
        float line_y = 0;
        while (line_y > -ofGetHeight() / 2 - y) {
            
            float noise_value = ofNoise(x * 0.005, y * 0.005, line_y * 0.0005 + ofGetFrameNum() * 0.035);
            if (noise_value < 0.55) {
                
                break;
            }
            
            float line_x = ofMap(noise_value, 0, 1, -ofGetWidth(), ofGetWidth());
            if (line_y == 0) {
                
                ofTranslate(-line_x, 0);
            }
            ofVertex(line_x,line_y);
           // ofVertex(ofPoint(line_x,line_y));
            
            line_y -= ofMap(noise_value, 0, 1, 0, 1.5);
        }
        ofRotate(angle);
        ofEndShape();
        ofPopMatrix();
    }
    
}

//--------------------------------------------------------------
/*
int main() {
    
    ofSetupOpenGL(720, 720, OF_WINDOW);
    ofRunApp(new ofApp());
}
*/
