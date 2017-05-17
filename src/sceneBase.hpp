//
//  sceneBase.hpp
//  FirstVJ
//
//  Created by 柴田将希 on 2017/05/16.
//
//

#ifndef sceneBase_hpp
#define sceneBase_hpp

#include "ofMain.h"

class sceneBase {
    public:
        explicit sceneBase(void);
        virtual ~sceneBase(void);
        virtual void setup(void);
        virtual void exit(void);
        virtual void update(void);
        virtual void draw(void);
        
        virtual void keyPressed(int key);
        virtual void keyReleased(int key);
        virtual void mouseMoved(int x, int y );
        virtual void mouseDragged(int x, int y, int button);
        virtual void mousePressed(int x, int y, int button);
        virtual void mouseReleased(int x, int y, int button);
        virtual void mouseEntered(int x, int y);
        virtual void mouseExited(int x, int y);
        virtual void windowResized(int w, int h);
        virtual void dragEvent(ofDragInfo dragInfo);
        virtual void gotMessage(ofMessage msg);
};

#endif
