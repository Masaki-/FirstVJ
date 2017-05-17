#include "avis3Scene.h"

static float angle;

//--------------------------------------------------------------
void avis3Scene::setup(){
    ofBackground(255);
    ofEnableDepthTest();
    
    fft.setup();
    fft.setNumFFTBins(16);
    fft.setNormalize(true);
    
    nBandsToGet = 1024;
    
    mySound.loadSound("Seiho - Plastic.mp3", 1024);
    
    mySound.setLoop(true);
    mySound.play();
    ofSoundUpdate();
    
    light.enable();
    
    int width = 1024;
    int height = 1024;
    unsigned char pixels[width * height];
    
    for (int i = 0; i < width * height; i++){
        pixels[i] = sin(i / 4000.0) * 127 + 127;
    }
    tex.loadData(pixels, width, height, GL_LUMINANCE);
    
    createMesh();
}

//--------------------------------------------------------------
void avis3Scene::update(){
    ofSoundUpdate();
    fft.update();
    float noiseScale = 6.0;
    float shiftSpeed = 1.0;
    float noiseStrength = fft.getMidVal()*500;
    for (int i = 0; i < mesh.getVertices().size(); i++) {
        float noiseX = ofMap(currentVertex[i].x, 0, ofGetWidth(), 0, noiseScale);
        float noiseY = ofMap(currentVertex[i].y, 0, ofGetWidth(), 0, noiseScale);
        float offset = ofNoise(noiseX + ofGetElapsedTimef() * shiftSpeed,
                               noiseY + ofGetElapsedTimef() * shiftSpeed);
        currentVertex[i] = currentVertex[i].normalize() * (offset * fft.getMidVal()*500 + ofGetWidth() / 7.0);
        mesh.setVertex(i, currentVertex[i]);
    }
    angle += 1;
    
}

//--------------------------------------------------------------
void avis3Scene::draw(){
    float lowValue = ofMap(fft.getLowVal(), 0, 1, 0, level);
    float midValue = ofMap(fft.getMidVal(), 0, 1, 0, level);
    float highValue = ofMap(fft.getHighVal(), 0, 1, 0, level);
    cam.begin();
    ofRotateX(angle);
    ofRotateY(angle);
    ofSetColor(255);
    tex.bind();
    mesh.draw();
    
    tex.unbind();
    
    
    ofPushMatrix();
    
    ofRotateX(angle);
    ofRotateY(angle);
    
    // 球
    sphere.set(fft.getHighVal()*1000, 16);// 半径と面の細かさ
    sphere.setPosition(0, 0, 0); // 位置
    ofSetColor(141,253,255);
    sphere.drawWireframe(); // ワイヤーフレームを描画
    ofPopMatrix();
    
    ofPushMatrix();
    
    ofRotateX(angle);
    ofRotateY(angle);
    // 球
    sphere.set(fft.getLowVal()*1000, 36);// 半径と面の細かさ
    ofSetColor(255,93,144);
    sphere.setPosition(0, 0, 0); // 位置
    sphere.drawWireframe(); // ワイヤーフレームを描画
    ofPopMatrix();
    
    
    
    
    
    cam.end();
}

//--------------------------------------------------------------
void avis3Scene::createMesh(){
    mesh = ofSpherePrimitive(ofGetWidth(), 128).getMesh();
    for (int i = 0; i < mesh.getVertices().size(); i++) {
        ofVec2f texCoord = mesh.getTexCoord(i);
        texCoord.x *= tex.getWidth();
        texCoord.y = (1.0 - texCoord.y) * tex.getHeight();
        mesh.setTexCoord(i, texCoord);
        currentVertex.push_back(ofVec3f(mesh.getVertices()[i].x, mesh.getVertices()[i].y, mesh.getVertices()[i].z));
    }
}
//--------------------------------------------------------------
void avis3Scene::keyPressed(int key){
    
}

//--------------------------------------------------------------
void avis3Scene::keyReleased(int key){
    
}

//--------------------------------------------------------------
void avis3Scene::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void avis3Scene::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void avis3Scene::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void avis3Scene::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void avis3Scene::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void avis3Scene::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void avis3Scene::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void avis3Scene::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void avis3Scene::dragEvent(ofDragInfo dragInfo){
    
}
