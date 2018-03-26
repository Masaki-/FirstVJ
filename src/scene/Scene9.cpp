//
//  Scene9.cpp
//  FirstVJ
//
//  Created by 柴田将希 on 2018/03/26.
//
//


#include "Scene9.h"
int effect_mode=3;

float x;
float y;
float x2;
float y2;
//float y1;
vector <ofPoint *> points;
//--------------------------------------------------------------
void Scene9::setup(){
      img1.load("images/A4.png");
    
    Futura.load("Futura Bold Italic font.ttf", 100); // フォントのデータを指定する
    Futura.setLineHeight(24);       // 行間を指定する
    Futura.setLetterSpacing(1.0);   // 文字間を指定する
    
    // Fonts
    ofTrueTypeFont::setGlobalDpi(72);
    
    /*
    kinect.setRegistration(true); // カメラ画像と深度カメラのずれを解消
    kinect.init(); // Kinect初期化
    kinect.open(); // Kinect開始
    */
    
    //バッファーのサイズを指定
    bufSize = 256;
    //画面の基本設
    ofBackground(0,0,0);
    ofSetColor(0,0,255);
    //サウンドストリームの初期化
   // ofSoundStreamSetup(0,2,this, 44100, bufSize, 5);
    //左右チャンネル音声の波形を格納する配列
    left = new float[bufSize];
    right = new float[bufSize];
    
    
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
    
    m.glScale(250,250,250);
    m.glRotate(20,0,0,1);
    
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
    gui.add(slider[7].setup("Slider8", 0, 0, 127));
}
//--------------------------------------------------------------

//--------------------------------------------------------------
void Scene9::update(){
  //  kinect.update();
    
    //ムービー再生を待機状態に
   // fingersMovie.update();
    
    korg.update();
    
    for (int j = 0; j < 8; j++) {
        knob[j] = korg.knobs[j];
        slider[j] = korg.sliders[j];
    }
}

//--------------------------------------------------------------
void Scene9::draw(){
    gui.draw();
    
    buffer.begin();
    
    drawByGL(&m);//多角形
    //  kinect.draw(0,0,ofGetWidth(),ofGetHeight());
    // img1.draw(0, 0);
    //fingersMovie.draw(0, 0, 1280, 720);
  
    //左チャンネル波形を描画
    
    
   
    
    // エフェクト選択
    //現在のモードに応じて、表示する映像を切り替え
    
    
    /* switch (key) {
     
     
     case '1':
     postGlitch.setFx(OFXPOSTGLITCH_SLITSCAN,ofGetKeyPressed());
     break;
     
     case '2':
     postGlitch.setFx(OFXPOSTGLITCH_SWELL,ofGetKeyPressed());
     break;
     }
     */
    // postGlitch.setFx(OFXPOSTGLITCH_SLITSCAN, ofGetKeyPressed());
    
    
    
    // ofSetColor(30, 200, 200); // 文字色を指定
    
    Futura.drawString("TAKEHISA",x,y);
    Futura.drawString("MASAKI",x2,y2);
    
    //  Futura.drawString("NEMUI", x,y); // 文字とポジションを指定して描画
    buffer.end();
    
    // エフェクトをかける
    
    postGlitch.generateFx();
    
    
    // FBOの内容を画面に描画
    buffer.draw(0,0);
    
    
    
}

void Scene9::drawByGL(ofMatrix4x4 * mat){
    
    ofNoFill();
    ofVec3f vec;
    
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < oi.size(); i++) {
        
        vec = ov[ oi[i] ] * *mat;
        glVertex3f(vec.x, vec.y, vec.z);
        
    }
    glEnd();
}
//--------------------------------------------------------------
void Scene9::audioReceived(float * input, int bufferSize,
                          int nChannels){
    //音声入力を配列に格納
    for (int i = 0; i < bufferSize; i++){
        left[i] = input[i*2];
        right[i] = input[i*2+1];
    }
}
//--------------------------------------------------------------
void Scene9::keyPressed(int key){
    
    if(key==99) // 'c' key
    {
        img1.draw(0,0
                  
                  
                  );
    }
    if(key==118) // 'v' key
    {
        img2.draw(190, 490, 20, 20);
    }
    
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
void Scene9::keyReleased(int key){
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
void Scene9::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void Scene9::mouseDragged(int x, int y, int button){
    //マウスをドラッグすると、ムービーのタイムラインを操作できる
    fingersMovie.setPosition((float)x / (float)ofGetWidth());
}

//--------------------------------------------------------------
void Scene9::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Scene9::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Scene9::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void Scene9::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void Scene9::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void Scene9::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void Scene9::dragEvent(ofDragInfo dragInfo){
    
}
