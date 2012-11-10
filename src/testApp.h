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
				
        int fontsize;
    
        int depth;
    
        ofxExtrudedText text;
        ofxExtrudedText text2;
        ofxExtrudedText text3;

      
        bool rotation;
        
        ofxGameCamera camera;
    
        int drawtype;
   
        ofBuffer inputText;
    
        float rotationSpeed;
            
        float rotationValue;
    
        int fadeColorValue;
    
    std::vector<ofxExtrudedText> texts;
    
        void drawText(int _drawtype);
};
