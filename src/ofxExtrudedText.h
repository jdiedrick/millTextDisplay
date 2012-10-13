//
//  ofxExtrudedText.h
//  emptyExample
//
//  Created by Jeffrey Crouse on 11/12/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#pragma once
#include "ofMain.h"
#include "ofxExtrudedLetter.h"

class ofxExtrudedText {
public:
    
    ofxExtrudedText();
    void init(string _fontfile, int _size, int _depth, string _text);
    void init(ofTrueTypeFont& _font, string _text);
    void draw();

    
    float getHeight()   {   return bbox.height;     }
    float getWidth()    {   return bbox.width;      }
    float getDepth()    {   return depth;           }
    
    vector<ofxExtrudedLetter> letters;
    
//protected:
    
    void makeMeshes(string _text);
    
    int depth;
    ofTrueTypeFont font;
    ofRectangle bbox;
    
};