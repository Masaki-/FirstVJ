#include "ofApp.h"
#include "myScene1.hpp"
#include "scene/avis3Scene.h"
#include "scene/Scene2.h"
#include "scene/Scene3.h"
#include "scene/Scene4.h"
#include "scene/Scene5.h"
#include "scene/Scene6.h"
#include "scene/Scene7.h"
#include "scene/Scene8.h"
#include "scene/Scene9.h"
//--------------------------------------------------------------
void ofApp::setup(){
    _scene = NULL;
    changeScene(0);
    return;
}

void ofApp::exit(){
    if (_scene != NULL) {
        _scene->exit();
        delete _scene;
        _scene = NULL;
    }
    return;
}

//--------------------------------------------------------------
void ofApp::update(){
    if (_scene != NULL) {
        _scene->update();
    }
    return;
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (_scene != NULL) {
        ofPushView();
        ofPushMatrix();
        ofPushStyle();
        _scene->draw();
        ofPopStyle();
        ofPopMatrix();
        ofPopView();
    }
    return;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            changeScene(key - '1');
            break;
        case '0':
            changeScene(9);
            break;
        default:
            if (_scene != NULL) {
                _scene->keyPressed(key);
            }
            break;
    }
    return;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (_scene != NULL) {
        _scene->keyReleased(key);
    }
    return;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    if (_scene != NULL) {
        _scene->mouseMoved(x, y);
    }
    return;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if (_scene != NULL) {
        _scene->mouseDragged(x, y, button);
    }
    return;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (_scene != NULL) {
        _scene->mousePressed(x, y, button);
    }
    return;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if (_scene != NULL) {
        _scene->mouseReleased(x, y, button);
    }
    return;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    if (_scene != NULL) {
        _scene->mouseEntered(x, y);
    }
    return;
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    if (_scene != NULL) {
        _scene->mouseExited(x, y);
    }
    return;
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    if (_scene != NULL) {
        _scene->windowResized(w, h);
    }
    return;
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    if (_scene != NULL) {
        _scene->gotMessage(msg);
    }
    return;
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    if (_scene != NULL) {
        _scene->dragEvent(dragInfo);
    }
    return;
}

void ofApp::changeScene(int index){
    if (-1 <= index && index < 9) {
        if (_scene != NULL) {
            _scene->exit();
            delete _scene;
            _scene = NULL;
        }
        cout << "change scene: " << index << endl;
        ofSetFrameRate(60);
        ofSetVerticalSync(true);
        ofSetBackgroundAuto(true);
        ofBackground(255, 255, 255);
        ofSetupGraphicDefaults();
        switch (index) {
            case 0:
                _scene = new myScene1(ofColor(0, 0, 255));
                break;
            case 1:
                _scene = new avis3Scene;
                break;
            case 2:
                _scene = new Scene2;
                break;
            case 3:
                _scene = new Scene3;
                break;
            case 4:
                _scene = new Scene4;
                break;
            case 5:
                _scene = new Scene5;
                break;
                
            case 6:
                _scene = new Scene6;
                break;
            case 7:
                _scene = new Scene7;
                break;
            case 8:
                _scene = new Scene8;
                break;
          
            
            default:
                break;
        }
        if (_scene != NULL) {
            _scene->setup();
        }
    }
    return;
}
