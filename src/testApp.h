#pragma once

#include "ofMain.h"
#include "ofxExtrudedText.h"
#include "ofxGameCamera.h"
#include "ofxXmlSettings.h"


class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        ofxExtrudedText text;
        ofxExtrudedText text2;

        float color1;
        float color2; 
    
        float incrementer; 
    
        bool switch1;
        bool switch2;
    
        bool rotation;
        
        ofxGameCamera camera;
    
        int drawtype;
   
        ofBuffer inputText;
    
        float rotationSpeed;
        
        bool fader;
    
        float rotationValue;
    
        int fadeColorValue;
};
