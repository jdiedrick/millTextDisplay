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
    
    //maybe smoother graphics...maybe
    ofSetVerticalSync(true);
    
    //check for our working directory
    system("pwd");
    
    //set our framerate 
    ofSetFrameRate(60);
    
    //set our background color
    ofBackground(0);
    
    //initialize a font size
    fontsize = 80;
    
    //initialize a "width" for our letters
    depth = 10;
    
    //set up game camera
    camera.setup();
    
    //set up intial text to draw
    drawtype=0;
    
    
    
    //set rotation speed
    rotationSpeed = 5.0;
    
    //initalize rotation. lets start rotating first
    rotation = true;
    
    //pull in text from output.txt, which is generated from a python script
    inputText = ofBufferFromFile(ofToDataPath("output.txt"));
    
    //this is jsut to test that we got our text into the program
    cout << inputText.getText() << endl;

    //uncomment this to use the text from output.txt
    //    text.init("STHeiti.ttf", fontsize, depth, inputText.getText());

    //intialize text objects with some text!
    
   // text.init("STHeiti.ttf", fontsize, depth, inputText);
    
    
    //add your new text here, make sure to add it to your .h file
    text.init("STHeiti.ttf", fontsize, depth, "You hover \n your hand \n right above \n the black belt - \n that spinning animal, \n slicked with fat. \n You know \n that if it \n grips you - \n catches you - \n you will \n be pulled, \n first at \n the sleeve \n and then at \n the arm - \n wound right down \n to the belt \n and held \n at a high tension, \n just before \n the neck \n irrevocably torques. \n The foreman \n will shout, \n but it \n will take \n a full \n fifteen minutes \n before the machine \n will be \n turned off -");
    
    text2.init("STHeiti.ttf", fontsize, depth, "before the \n river will \n be dammed - \n before the \n waterwheel will \n be stopped. \n At that \n last second, \n there will \n be light - \n illuminating the \n work of history - \n millions of \n gears spinning \n in the dark - \n grinding \n older generations \n into dirt. \n At that moment, \n it will \n feel inevitable. \n You will \n pull your \n hand away \n from that belt. \n You will \n go back \n to work.");
    
    text3.init("STHeiti.ttf", fontsize, depth, "three three three three");
    
    texts.push_back(text);
    texts.push_back(text2);
    texts.push_back(text3);
    
    //sets initial rotation value. don't change this!
    rotationValue = 0;
    
    //sets initial fade color value. don't change this!
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
    
    //something here isn't right...need to debug
    if ( (float)rotationValue == 180.0  && (int)fadeColorValue  == 0){
        drawtype++;
        
        string pythonpath = ofToDataPath("mode2.py");
        
        string inputpath = ofToDataPath("input.txt");
        
        //string pythoncommand =  "python " + pythonpath + inputpath;
        
        //run the python script again
        //system(pythoncommand);
//        char cmd[8192];
//        sprintf(cmd,"bash --login -c 'python %1$s %2$s'", pythonpath.c_str(), inputpath.c_str());
//        system(cmd); 
        
      //  string cmd = "python "+pythonpath+" "+inputpath;
       // system(cmd.c_str());
        
        //  system("python "+ofToDataPath("scriptname.py input.txt", true));
        //load in the new text
        inputText = ofBufferFromFile(ofToDataPath("output.txt"));
        text.init("STHeiti.ttf", fontsize, depth, inputText);
        
        
        if(drawtype==texts.size()){
            drawtype=0;
        }
        
        
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    //begin camera
    camera.begin();

    //turn this on to change axis of rotation
    //offsets axis of rotation
    ofTranslate(1000,0,0);

    //enable gl depth test
	glEnable(GL_DEPTH_TEST);
    
    //push our matrix
    ofPushMatrix();

    //rotate on y-axis. change rotation speed in ofRotateY()
    if(rotation)
        ofRotateY(rotationValue);
    
    //turn ths off if you want to change axis of rotation
    //translate to center of the screen...might need to change with new camera
    ofTranslate(-ofGetWidth()/2, ofGetHeight()/2);
    
    //flip over y-axis
    ofScale(1, -1, 1);
    
    //draw our text
    drawText(drawtype);
    
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

void testApp::drawText(int _drawtype){
    
    drawtype = _drawtype;
    
    
        for (int j=0; j<texts[drawtype].letters.size(); j++){
            
            ofSetColor(fadeColorValue);
            texts[drawtype].letters[j].front.draw();
            
            ofSetColor(fadeColorValue);
            texts[drawtype].letters[j].side.draw();
            
            ofSetColor(fadeColorValue);
            texts[drawtype].letters[j].back.draw();
        }
    
    
    
}
