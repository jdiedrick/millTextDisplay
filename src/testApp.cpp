/*
 
 Mill Text Display by Johann Diedrick, 2012
 
 based off of the ofxFontExtruder example by Rick Companje
 
 Camera controls (based on ofxGameCamera addon by James George):
 
 w - move forward
 s - move backwards
 a - move left
 d - move right
 
 q - tilt left
 r - tilt right
 
 e - boom up
 c - boom down
 
 t - turn text rotation on and off
 
 
 Things to do:
 -work on lightning
 -work on text manupuation in generating new texts to draw (need to research...)
 
 */

//boilerplate includes
#include "testApp.h"
using namespace std;
#include <iostream>

//--------------------------------------------------------------
void testApp::setup(){
    
    //set our framerate 
    ofSetFrameRate(60);
    
    //set our background color
    ofBackground(0);
    
    //initialize a font size
    int fontsize = 80;
    
    //initialize a "width" for our letters
    int depth = 10;
    
    //set up game camera
    camera.setup();
    
    //set up intial text to draw
    drawtype=1;
    
    
    
    //set rotation speed
    rotationSpeed = 0.5;
    
    //initalize rotation. lets start rotating first
    rotation = true;
    
    //pull in text from output.txt, which is generated from a python script
    inputText = ofBufferFromFile("../../python/output.txt");
    
    //this is jsut to test that we got our text into the program
    cout << inputText.getText() << endl;

    //uncomment this to use the text from output.txt
    //    text.init("STHeiti.ttf", fontsize, depth, inputText.getText());

    //intialize text objects with some text!
    text.init("STHeiti.ttf", fontsize, depth, "You hover \n your hand \n right above \n the black belt - \n that spinning animal, \n slicked with fat. \n You know \n that if it \n grips you - \n catches you - \n you will \n be pulled, \n first at \n the sleeve \n and then at \n the arm - \n wound right down \n to the belt \n and held \n at a high tension, \n just before \n the neck \n irrevocably torques. \n The foreman \n will shout, \n but it \n will take \n a full \n fifteen minutes \n before the machine \n will be \n turned off -");
    
    text2.init("STHeiti.ttf", fontsize, depth, "before the \n river will \n be dammed - \n before the \n waterwheel will \n be stopped. \n At that \n last second, \n there will \n be light - \n illuminating the \n work of history - \n millions of \n gears spinning \n in the dark - \n grinding \n older generations \n into dirt. \n At that moment, \n it will \n feel inevitable. \n You will \n pull your \n hand away \n from that belt. \n You will \n go back \n to work.");
    
    rotationValue = 0;
    
    fadeColorValue = 0;

}

//--------------------------------------------------------------
void testApp::update(){
    
    //here is where we change rotation and fade color value. 
    //pretty cludgly math but it does the trick...
    
    if (rotationValue==360.0) {
        
        rotationValue=0.0;
    }
    
    
    rotationValue  = rotationValue + rotationSpeed;
    
    fadeColorValue = (int)(((rotationValue-180.0)*255.0)/360.0) ;
    
    
    fadeColorValue = abs(fadeColorValue);
    
    fadeColorValue = ofMap(fadeColorValue, 0, 127, 0, 255);
    
    cout<<"Rotation: " << rotationValue << " Fade: " <<fadeColorValue<< " Drawing: " << drawtype << endl;
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    
    //begin camera
    camera.begin();
    
    //enable gl depth test
	glEnable(GL_DEPTH_TEST);
    
    //push our matrix
    ofPushMatrix();
    
    //rotate on y-axis. change rotation speed in ofRotateY()
    if(rotation)
        ofRotateY(rotationValue);

    
    //something here isn't right...need to debug
    if ( (float)rotationValue == 180.0  && (int)fadeColorValue  == 0){ 
        drawtype++;

       if(drawtype==3){
            drawtype=1;
        }
    
        
    }
    //translate to center of the screen...might need to change with new camera
    //ofTranslate(-ofGetWidth()/2, ofGetHeight()*2, -4000);
    ofTranslate(-ofGetWidth()/2, ofGetHeight()/2);
    
    //flip over y-axis
    ofScale(1, -1, 1);

    // Draw each letter separately so that we can make each face a different color
 
    //only fade text is fader is turned on (fader == true)
    
        
    //if drawtype is 1, draw first text
    if(drawtype == 1){
    for(int i=0; i<text.letters.size(); i++)
    {
        
        
        ofSetColor(fadeColorValue);
        text.letters[i].front.draw();
        
        ofSetColor(fadeColorValue);
        text.letters[i].side.draw();
        
        ofSetColor(0);
       // text.letters[i].side.drawWireframe();
        
        ofSetColor(fadeColorValue);
        text.letters[i].back.draw();

    }
    }
    
    
    //if drawtype is 2, draw second text
    if(drawtype == 2){
    
    for(int i=0; i<text2.letters.size(); i++)

    
    {
        ofSetColor(fadeColorValue);
        text2.letters[i].front.draw();
        
        ofSetColor(fadeColorValue);
        text2.letters[i].side.draw();
        
        ofSetColor(0);
        //text.letters[i].side.drawWireframe();
        
        ofSetColor(fadeColorValue);
        text2.letters[i].back.draw();
        
    }
    
    }
        
    
    
    //pop our matrix
    ofPopMatrix();
    
    //disable gl depth test
	glDisable(GL_DEPTH_TEST);
    

    //end our camera
    camera.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    //hit 't' to turn text rotation on or off
    if(key=='t')
        rotation = !rotation;

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}