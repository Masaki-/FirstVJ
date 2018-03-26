//
//  Scene6.cpp
//  FirstVJ
//
//  Created by 柴田将希 on 2017/06/15.
//
//

#include "Scene6.h"

//#include "stdio.h"

int effect_mode=3;

float x;
float y;
float x2;
float y2;
//float y1;
vector <ofPoint *> points;
//--------------------------------------------------------------
void Scene6::setup(){
    //画面の基本設
   // ofBackground(255,255,255);
    //ofSetColor(0,0,255);
    img1.load("images/_MG_0393.JPG");
    img2.load("images/IMG_1384.PNG");
    
    fft.setup();
    fft.setNumFFTBins(16);
    fft.setNormalize(true);
    

    ofSetFrameRate(60);
    ofSetVerticalSync(true);
   //ofEnableAlphaBlending();
    
   
    
    fftSmoothed = new float[8192];
    for (int i=0; i<8192; i++){
        fftSmoothed[i] = 0;
    }
    nBandsToGet = 560;
    
    
    boxSize = 6;
    for (int i=0; i<NUM; i++) {
        
        mBox[i].setPosition(ofRandom(-500,500), ofRandom(-500,500), ofRandom(-500,500));
        mBox[i].set(boxSize);
    }

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    x=300;
    y=200;
    x2=300;
    y2=200;
    Futura.load("Futura Bold Italic font.ttf", 100); // フォントのデータを指定する
    Futura.setLineHeight(24);       // 行間を指定する
    Futura.setLetterSpacing(1.0);   // 文字間を指定する
    
    // Fonts
    ofTrueTypeFont::setGlobalDpi(72);
    
    
   
    
    
    //バッファーのサイズを指定
    bufSize = 256;

    //サウンドストリームの初期化
   // ofSoundStreamSetup(0,2,this, 44100, bufSize, 5);
    
    //画面の基本設定
    ofBackground(0,0,0);
    ofEnableSmoothing();
    //画面の混色の設定を加算合成にする
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    //ムービーデータを読込む
    //fingersMovie.loadMovie("D.A.N. - Zidane (Official Video).mp4");
    //ムービーの再生開始
    //fingersMovie.play();
    
    buffer.allocate(1024*2, 768*2);     // バッファ確保
    
    postGlitch.setup(&buffer);      // fboのポインタを渡す
    
    korg.setup();
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
    gui.add(slider[7].setup("Slider8", 0, 0, 127));}
//--------------------------------------------------------------

//--------------------------------------------------------------
void Scene6::update(){
 
    korg.update();
  
          fft.update();
   
    
    for (int j = 0; j < 8; j++) {
        knob[j] = korg.knobs[j];
        slider[j] = korg.sliders[j];
    }
}

//--------------------------------------------------------------
void Scene6::draw(){
   
    
    buffer.begin();
    
  
 
    // エフェクト選択
    //現在のモードに応じて、表示する映像を切り替え
    

    // postGlitch.setFx(OFXPOSTGLITCH_SLITSCAN, ofGetKeyPressed());
    
    
    
    // ofSetColor(30, 200, 200); // 文字色を指定
    
    img1.draw(0,0,ofGetWidth(),ofGetHeight());
    ofSetColor(0,0,0,2*slider[0]);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    //  Futura.drawString("NEMUI", x,y); // 文字とポジションを指定して描画
    ofSetColor(0,0,0);
    Futura.drawString("RIRIKO",x,y);
    Futura.drawString("×MASSY",x2,y2);
    
    buffer.end();
    
    // エフェクトをかける
    
    postGlitch.generateFx();
    
    
    // FBOの内容を画面に描画
    buffer.draw(0,0);
    

   
    
    
    
    int start_x = 200;
    int base_y = 500;
    float width = (float)(800);
      gui.draw();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    for (int i=0; i<nBandsToGet; i+=5){
        ofPushMatrix();
      //  ofSetColor(255,255,255);
       ofSetColor(ofColor(ofColor::fromHsb((float)255/nBandsToGet*i, 200, 255)));
        float length = 300 * fft.getMidVal();
        ofRotateZ(i);
        ofDrawRectangle(0, 250, 5, length);
        ofPopMatrix();
        
        
        
    }
    
    
    
    
    
   // vec.set(mouseX-p.x, mouseY-p.y);
    
    cam.begin();
    
    ofPushMatrix();
    
    ofRotateY(ofGetFrameNum());
    
    int alpha = abs(vec.x) + abs(vec.y);
    
    ofSetColor(ofColor::fromHsb(ofGetFrameNum()%255, 255, 255), 255 - alpha);
    
    for (int i=0; i<NUM; i++) {
        mBox[i].draw();
    }
    
    ofPopMatrix();
    ofSetColor(0,0,0, (ofGetFrameNum()*6)%120);
    
    box.setPosition(0, 0, 0);
    box.set(150);
    //box.draw();
    
    ofSetColor(255, 255, 255, 255);
    // box.drawWireframe();
    
    cam.end();
    
   // p.x = mouseX;
   // p.y = mouseY;
    
    float lowValue = ofMap(fft.getLowVal(), 0, 1, 0, level);
    float midValue = ofMap(fft.getMidVal(), 0, 1, 0, level);
    float highValue = ofMap(fft.getHighVal(), 0, 1, 0, level);
    
}
//--------------------------------------------------------------
void Scene6::audioReceived(float * input, int bufferSize,
                          int nChannels){
    //音声入力を配列に格納
    for (int i = 0; i < bufferSize; i++){
        left[i] = input[i*2];
        right[i] = input[i*2+1];
    }
}
//--------------------------------------------------------------
void Scene6::keyPressed(int key){

    
    //キー入力でモード切り替え
    if (key == 'q') postGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, true);
    if (key == 'w') postGlitch.setFx(OFXPOSTGLITCH_GLOW			, true);
    if (key == 'e') postGlitch.setFx(OFXPOSTGLITCH_SHAKER			, true);
    if (key == 'r') postGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER		, true);
    if (key == 't') postGlitch.setFx(OFXPOSTGLITCH_TWIST			, true);
    if (key == 'y') postGlitch.setFx(OFXPOSTGLITCH_OUTLINE		, true);
    if (key == 'u') postGlitch.setFx(OFXPOSTGLITCH_NOISE			, true);
    if (key == 'i') postGlitch.setFx(OFXPOSTGLITCH_SLITSCAN		, true);
    if (key == 'o') postGlitch.setFx(OFXPOSTGLITCH_SWELL			, true);
    if (key == 'p') postGlitch.setFx(OFXPOSTGLITCH_INVERT			, true);
    
    if (key == 'a') postGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, true);
    if (key == 's') postGlitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, true);
    if (key == 'd') postGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE	, true);
    if (key == 'f') postGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, true);
    if (key == 'g') postGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, true);
    if (key == 'h') postGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT	, true);
    if (key == 'j') postGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, true);
    
    if(key==122) // 'z' key
    {
        x=ofRandom(1240);
        y=ofRandom(720);
    }
    if(key==120) // 'x' key
    {
        x2=ofRandom(1240);
        y2=ofRandom(720);
    }
    
}

//--------------------------------------------------------------
void Scene6::keyReleased(int key){
    if (key == 'q') postGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, false);
    if (key == 'w') postGlitch.setFx(OFXPOSTGLITCH_GLOW			, false);
    if (key == 'e') postGlitch.setFx(OFXPOSTGLITCH_SHAKER			, false);
    if (key == 'r') postGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER		, false);
    if (key == 't') postGlitch.setFx(OFXPOSTGLITCH_TWIST			, false);
    if (key == 'y') postGlitch.setFx(OFXPOSTGLITCH_OUTLINE		, false);
    if (key == 'u') postGlitch.setFx(OFXPOSTGLITCH_NOISE			, false);
    if (key == 'i') postGlitch.setFx(OFXPOSTGLITCH_SLITSCAN		, false);
    if (key == 'o') postGlitch.setFx(OFXPOSTGLITCH_SWELL			, false);
    if (key == 'p') postGlitch.setFx(OFXPOSTGLITCH_INVERT			, false);
    
    if (key == 'a') postGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, false);
    if (key == 's') postGlitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, false);
    if (key == 'd') postGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE	, false);
    if (key == 'f') postGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, false);
    if (key == 'g') postGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, false);
    if (key == 'h') postGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT	, false);
    if (key == 'j') postGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, false);
    
}

//--------------------------------------------------------------

