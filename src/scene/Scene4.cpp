#include "Scene4.h"

//--------------------------------------------------------------
void Scene4::setup(){
    ofDisableDepthTest();
    ofDisableLighting();
    
    ofSetFrameRate(60);
    ofTrueTypeFont::setGlobalDpi(72);
    verdana.load("frabk.ttf", 100); // フォントのデータを指定する
    verdana.setLineHeight(24);       // 行間を指定する
    verdana.setLetterSpacing(1.0);   // 文字間を指定する
    fft.setup();
    fft.setNumFFTBins(16);
    fft.setNormalize(true);
   // nBandsToGet = 1024;

}

//--------------------------------------------------------------



//--------------------------------------------------------------
void Scene4::update(){
     fft.update();
   }

//--------------------------------------------------------------
void Scene4::draw(){

   
    shader.load("","shader.frag");
    shader.begin();
    shader.setUniform1f("u_time", ofGetElapsedTimef());
    shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    ofRect(0,0,ofGetWidth(), ofGetHeight());
    
    
    shader.end();
ofSetColor(0,0,0,100);
     ofRect(0,0,ofGetWidth(), ofGetHeight());
    
    ofSetColor(255,255,255); // 文字色を指定
    verdana.drawString("Techno is it!", ofGetWidth()/2-220, ofGetHeight()/2); // 文字とポジションを指定して描画
    
    
    //ofNoFill();
    ofPushMatrix();
    ofPushStyle();
    ofNoFill();
    ofSetLineWidth(2);
    ofRect(ofGetWidth()/2-300-fft.getLowVal()*200,ofGetHeight()/2-150-fft.getLowVal()*200,ofGetWidth()/2-250+fft.getLowVal()*400,ofGetHeight()/2-300+fft.getLowVal()*400);
    ofPopStyle();
    ofPopMatrix();
    
    ofPushMatrix();
    ofPushStyle();
    ofNoFill();
    ofSetLineWidth(6);
    ofRect(ofGetWidth()/2-300-fft.getMidVal()*300,ofGetHeight()/2-150-fft.getMidVal()*300,ofGetWidth()/2-250+fft.getMidVal()*600,ofGetHeight()/2-300+fft.getMidVal()*600);
    ofPopStyle();
    ofPopMatrix();
    
    ofPushMatrix();
    ofPushStyle();
    ofNoFill();
    ofSetLineWidth(10);
    ofRect(ofGetWidth()/2-300-fft.getHighVal()*400,ofGetHeight()/2-150-fft.getHighVal()*400,ofGetWidth()/2-250+fft.getHighVal()*800,ofGetHeight()/2-300+fft.getHighVal()*800);
    ofPopStyle();
    ofPopMatrix();
    
    float lowValue = ofMap(fft.getLowVal(), 0, 1, 0, level);
    float midValue = ofMap(fft.getMidVal(), 0, 1, 0, level);
    float highValue = ofMap(fft.getHighVal(), 0, 1, 0, level);
    

    
}

//--------------------------------------------------------------
void Scene4::keyPressed(int key){
    }

//--------------------------------------------------------------
void Scene4::keyReleased(int key){
    
}

//--------------------------------------------------------------
void Scene4::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void Scene4::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Scene4::mousePressed(int x, int y, int button){
   
}

//--------------------------------------------------------------
void Scene4::mouseReleased(int x, int y, int button){
   }

//--------------------------------------------------------------
void Scene4::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void Scene4::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void Scene4::dragEvent(ofDragInfo dragInfo){
    
}
