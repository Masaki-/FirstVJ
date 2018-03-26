#include "Scene3.h"

static float angle;
static ofVec4f frame;


//--------------------------------------------------------------
void Scene3::setup(){
    
    
    ofEnableDepthTest();
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    fft.setup();
    fft.setNumFFTBins(16);
    fft.setNormalize(true);
    nBandsToGet = 1024;
    
    mySound.loadSound("Seiho - Plastic.mp3", 1024);
    
    mySound.setLoop(true);
    mySound.play();
    ofSoundUpdate();
    
    ofEnableDepthTest(); // 深度テストを有効に
    ofEnableSmoothing(); // 表示をスムースに // ライティングを有効に
    light.enable();
    // スポットライトを配置
    light.setSpotlight(); // 照明の位置
    light.setPosition(-100, 100, 100); // 環境反射光の色
    light.setAmbientColor(ofFloatColor(0.2, 0.2, 0.2, 1.0)); // 拡散反射光の色
    light.setDiffuseColor(ofFloatColor(0.5, 0.5, 1.0)); // 鏡面反射光の色
    light.setSpecularColor(ofFloatColor(1.0, 1.0, 1.0));
    
    
    
    
    angle = 0;
    //korg.setup();
    gui.setup("KORG nanoKONTROL2");
    gui.add(knob[0].setup("knob1", 0, 0, 127));
    gui.add(knob[1].setup("knob2", 0, 0, 127));
    gui.add(knob[2].setup("knob3", 0, 0, 127));
    gui.add(knob[3].setup("knob4", 0, 0, 127));
    gui.add(knob[4].setup("knob5", 0, 0, 127));
    gui.add(knob[5].setup("knob6", 0, 0, 127));
    gui.add(knob[6].setup("knob7", 0, 0, 127));
    gui.add(knob[7].setup("knob8", 0, 0, 127));
    
    gui.add(slider[0].setup("Slider1", 0, 0, 127));
    gui.add(slider[1].setup("Slider2", 0, 0, 127));
    gui.add(slider[2].setup("Slider3", 0, 0, 127));
    gui.add(slider[3].setup("Slider4", 0, 0, 127));
    gui.add(slider[4].setup("Slider5", 0, 0, 127));
    gui.add(slider[5].setup("Slider6", 0, 0, 127));
    gui.add(slider[6].setup("Slider7", 0, 0, 127));
    gui.add(slider[7].setup("Slider8", 0, 0, 127));
    
    // ofSetRectMode(OF_RECTMODE_CENTER);
    frame = ofVec4f(300, 200, 200, 200);
}

//--------------------------------------------------------------
void Scene3::update(){
    
    
    ofSoundUpdate();
    
    //fft = ofSoundGetSpectrum(nBandsToGet);
    
    //korg.update();
    
    
    for (int j = 0; j < 8; j++) {
        //knob[j] = korg.knobs[j];
        //slider[j] = korg.sliders[j];
    }
    
    fft.update();
    angle += 1;
    // ofRotateX(50);
    //ofRotateY(50);
}

//--------------------------------------------------------------
void Scene3::draw(){
    cam.begin();
    ofBackground(ofColor::fromHsb(fft.getLowVal()*400, fft.getMidVal()*1000, 300,300));
    // ::fromHsb(slider[4]*2,slider[5]*2,slider[6],175*2)
    
    //ofDrawRectangle(0, 0,-1000, ofGetWidth(), ofGetHeight());
    
    
    
    ofSetColor(255);
    ofPushMatrix();
    
    ofRotateX(angle);
    ofRotateY(angle);
    // 球
    sphere.set(fft.getHighVal()*1000, 16);// 半径と面の細かさ
    sphere.setPosition(0, 0, 0); // 位置
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
    ofPushMatrix();
    
    ofPushMatrix();
    ofRotateX(angle);
    ofRotateY(angle);
    // 球
    sphere.set(fft.getMidVal()*1000, 26);// 半径と面の細かさ
    ofSetColor(204,253,255);
    sphere.setPosition(0, 0, 0); // 位置
    sphere.drawWireframe(); // ワイヤーフレームを描画
    ofPopMatrix();
    
    
    sphere.set(100, 16); // 半径と面の細かさ
    sphere.setPosition(0, 0, 0); // 位置
    sphere.draw(); // 塗りつぶしで描画
    
    
    
    ofSetColor(0);
    // 低域、中域、高域の値を取得
    float lowValue = ofMap(fft.getLowVal(), 0, 1, 0, level);
    float midValue = ofMap(fft.getMidVal(), 0, 1, 0, level);
    float highValue = ofMap(fft.getHighVal(), 0, 1, 0, level);
    
    
    
    ofRotateZ(slider[0]| 50);
    ofRotateX(slider[1]| 50);
    ofRotateY(slider[2]|ofGetFrameNum());//U60u
    
    
    
    /* float shiftSpeed = 1.0;
     
     for (int i = 0; i < mesh.getVertices().size(); i++) {
     
     int noiseScale = 5 ;
     float noiseStrength = fft.getLowVal();
     float noiseX = ofMap(currentVertex[i].x, 0, ofGetWidth(), 0, noiseScale);
     float noiseY = ofMap(currentVertex[i].y, 0, ofGetWidth(), 0, noiseScale);
     float offset = ofNoise(noiseX + ofGetElapsedTimef() * shiftSpeed,
     noiseY + ofGetElapsedTimef() * shiftSpeed);
     currentVertex[i] = currentVertex[i].normalize() * (offset * fft.getLowVal() + ofGetWidth() / 6);
     mesh.setVertex(i, currentVertex[i]);
     }
     
     */
    
    
    tex.bind();
    ofRotateX(40);
    ofRotateY(180);
    ofSetColor(255);
    mesh.draw();
    tex.unbind();
    cam.end();
    
}
//--------------------------------------------------------------

void Scene3::createMesh(){
    mesh = ofSpherePrimitive(ofGetWidth(), 129).getMesh();
    for (int i = 0; i < mesh.getVertices().size(); i++) {
        ofVec2f texCoord = mesh.getTexCoord(i);
        texCoord.x *= tex.getWidth();
        texCoord.y = (1.0 - texCoord.y) * tex.getHeight();
        mesh.setTexCoord(i, texCoord);
        currentVertex.push_back(ofVec3f(mesh.getVertices()[i].x, mesh.getVertices()[i].y, mesh.getVertices()[i].z));
    }
}

//--------------------------------------------------------------
void Scene3::resolutionChanged(int & resolution){
    lowNoiseImg.allocate(resolution, resolution, OF_IMAGE_GRAYSCALE);
    midNoiseImg.allocate(resolution, resolution, OF_IMAGE_GRAYSCALE);
    highNoiseImg.allocate(resolution, resolution, OF_IMAGE_GRAYSCALE);
}
//--------------------------------------------------------------
void Scene3::keyPressed(int key){
    
}

//--------------------------------------------------------------
void Scene3::keyReleased(int key){
    
}

//--------------------------------------------------------------
void Scene3::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void Scene3::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Scene3::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Scene3::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Scene3::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void Scene3::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void Scene3::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void Scene3::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void Scene3::dragEvent(ofDragInfo dragInfo){
    
}
