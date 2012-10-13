//
//  ofxExtrudedLetter.h
//  emptyExample
//
//  Created by Jeffrey Crouse on 11/12/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
#pragma once
#include "ofMain.h"

class ofxExtrudedLetter {
public:
    ofMesh front;
    ofMesh back;
    ofMesh side;
    vector<ofPolyline> lines;
    
    void setup(ofTTFCharacter letter, float depth);
    void draw();
    
};

