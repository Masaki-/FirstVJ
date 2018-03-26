//
//  myScene1.hpp
//  FirstVJ
//
//  Created by 柴田将希 on 2017/05/16.
//
//

#ifndef myScene1_hpp
#define myScene1_hpp

#include "ofMain.h"
#include "sceneBase.hpp"

class myScene1 : public sceneBase {
    private:
        ofColor _color;
    
    public:
        myScene1(ofColor const& color);
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
};

#endif
