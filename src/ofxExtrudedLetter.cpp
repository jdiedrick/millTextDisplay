//
//  ofxExtrudedLetter.cpp
//  emptyExample
//
//  Created by Jeffrey Crouse on 11/12/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "ofxExtrudedLetter.h"


// ------------------------------
void ofxExtrudedLetter::draw()
{
    front.draw();
    back.draw();
    side.draw();
}


// ------------------------------
void ofxExtrudedLetter::setup(ofTTFCharacter letter, float depth) 
{
    lines = letter.getOutline();
    front = letter.getTessellation();
    back = front;
    
    ofVec3f* v = back.getVerticesPointer();
    for(int j=0; j< back.getNumVertices(); j++)
    {
        v[j].z -= depth;
    }
    
    for(int j=0; j<lines.size(); j++)
    {
        vector<ofPoint> points = lines[j].getVertices();
        int k;
        for(k=0; k<points.size()-1; k++)
        {
            ofPoint p1 = points[k+0];
            ofPoint p2 = points[k+1];
            
            side.addVertex(p1);
            side.addVertex(p2);
            side.addVertex(ofPoint(p1.x, p1.y, p1.z-depth));
            
            side.addVertex(ofPoint(p1.x, p1.y, p1.z-depth));
            side.addVertex(ofPoint(p2.x, p2.y, p2.z-depth));
            side.addVertex(p2);
        }
        
        ofPoint p1 = points[k];
        ofPoint p2 = points[0];
        
        side.addVertex(p1);
        side.addVertex(p2);
        side.addVertex(ofPoint(p1.x, p1.y, p1.z-depth));
        
        side.addVertex(ofPoint(p1.x, p1.y, p1.z-depth));
        side.addVertex(ofPoint(p2.x, p2.y, p2.z-depth));
        side.addVertex(p2);
    }
}