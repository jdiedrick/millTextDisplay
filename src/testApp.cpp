#include "testApp.h"
using namespace std;

#include <iostream>

//--------------------------------------------------------------
void testApp::setup(){

    ofSetFrameRate(60);
    ofBackground(0);

    int fontsize = 80;
    int depth = 20;
    
    
    camera.setup();
    drawtype=1;
    
    color1 = 0;
    color2 = 0;
    
    incrementer = 0.01;
    
    switch1 = false;
    switch2 = false;
    
    multiplier== 0.25; 
    
    rotation = true;
    
    inputText = ofBufferFromFile("../../python/output.txt");
    
    cout << inputText.getText() << endl;

    
    //    text.init("STHeiti.ttf", fontsize, depth, inputText.getText());

    text.init("STHeiti.ttf", fontsize, depth, "making a mill means \n afixing the wooden wheel \n just behind the dam");
    
    text2.init("STHeiti.ttf", fontsize, depth, "like slipping in the heart \n right behind the wooden cage \n of the breast");


}

//--------------------------------------------------------------
void testApp::update(){
    
    pointLight.setPosition(cos(ofGetElapsedTimef()*.6f) * 5 * 200 + ofGetWindowWidth(), 
						   sin(ofGetElapsedTimef()*.8f) * 200 * 2 + ofGetWindowHeight(), 
						   -cos(ofGetElapsedTimef()*.8f) * 200 * 2 + 0);
    
    spotLight.setOrientation( ofVec3f( 0, cos(ofGetElapsedTimef()) * RAD_TO_DEG, 0) );
	spotLight.setPosition( mouseX, mouseY, 200);
    
    

}

//--------------------------------------------------------------
void testApp::draw(){
    
  //  cam.begin();
    camera.begin();
    
    ofSetColor(200, 0, 100);
    
	glEnable(GL_DEPTH_TEST);
    ofPushMatrix();
   
   // light.setSpotlight();
    
    
  //  pointLight.enable();
//    spotLight.enable();

  //  pointLight.setSpecularColor(ofFloatColor(0, 0, 255));
    
   //ofTranslate(80, ofGetHeight()/2.0);
    
    if(rotation)
    ofRotateY(ofGetFrameNum()/2);
    
    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);

    //ofTranslate(0, text.getHeight()/2.0);
    
    // Just draw the filled-in meshes
    //text.draw();
    ofScale(1, -1, 1);

    // Draw each letter separately so that we can make each face a different color
 
    if(drawtype == 1){
    for(int i=0; i<text.letters.size(); i++)
    {
        
        
        ofSetColor(color1);
        text.letters[i].front.draw();
        
        ofSetColor(color1);
        text.letters[i].side.draw();
        
        ofSetColor(0);
       // text.letters[i].side.drawWireframe();
        
        ofSetColor(color1);
        text.letters[i].back.draw();
        
        if(color1<256 && switch1 == false){
        color1 = color1 + incrementer;
        }
        
        if(color1>255 && switch1 == false){
            color1 = color1 - incrementer;
            switch1 = true;
        }
        
        if(color1>0 && switch1 == true){
            color1 = color1 - incrementer;
        }
        
        if(color1<0 && switch1 == true){
            color1 = color1 + incrementer;
            switch1=false;
            drawtype=2;
        }
        
    }
    }
    
    
    if(drawtype == 2){
    
    for(int i=0; i<text2.letters.size(); i++)

    
    {
        ofSetColor(color2);
        text2.letters[i].front.draw();
        
        ofSetColor(color2);
        text2.letters[i].side.draw();
        
        ofSetColor(0);
        //text.letters[i].side.drawWireframe();
        
        ofSetColor(color2);
        text2.letters[i].back.draw();
        
        if(color2<256 && switch2 == false){
            color2 = color2 + incrementer;
        }
        
        if(color2>255 && switch2 == false){
            color2 = color2 - incrementer;
            switch2 = true;
        }
        
        if(color2>0 && switch2 == true){
            color2 = color2 - incrementer;
        }
        
        if(color2<0 && switch2 == true){
            color2 = color2 + incrementer;
            switch2=false;
            drawtype=1;
        }
        
    }
    
    }
    
  //  pointLight.disable();
  //  spotLight.disable();
    ofPopMatrix();
	glDisable(GL_DEPTH_TEST);
    

    //cam.end();
    camera.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
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