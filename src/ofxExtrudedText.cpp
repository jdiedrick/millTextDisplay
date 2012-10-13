//
//  ofxExtrudedText.cpp
//  emptyExample
//
//  Created by Jeffrey Crouse on 11/12/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "ofxExtrudedText.h"


// ------------------------------
ofxExtrudedText::ofxExtrudedText() 
{
    depth = 50;
}

// ------------------------------
void ofxExtrudedText::init(string _fontfile, int _size, int _depth, string _text)
{
    font.loadFont(_fontfile, _size, true, true, true);
    depth = _depth;
    makeMeshes(_text);
}

// ------------------------------
void ofxExtrudedText::init(ofTrueTypeFont& _font, string _text)
{
    makeMeshes(_text);
}

// ------------------------------
void ofxExtrudedText::draw()
{
    for(int i=0; i<letters.size(); i++)
    {
        letters[i].draw();
    }
}


// ------------------------------
void ofxExtrudedText::makeMeshes(string _text)
{
    letters.clear();
    bbox = font.getStringBoundingBox(_text, 0, 0);
    
    vector<ofTTFCharacter> letterPaths = font.getStringAsPoints(_text);
    for(int i=0; i<letterPaths.size(); i++)
    {
        ofxExtrudedLetter letter;
        letter.setup(letterPaths[i], depth);
        
        letters.push_back(letter);
    }
}

