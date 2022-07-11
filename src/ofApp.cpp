#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    _laserPointDetector.Setup();
    _fireworks.SetupFirework();
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(10,10,10);

    bool isPointDetected = _laserPointDetector.Update();
    if(isPointDetected)
    {
        glm::vec2 laserPoint = _laserPointDetector.GetPointerTarget();
        _fireworks.AddFirework(laserPoint.x, laserPoint.y);
    }
    _fireworks.UpdateFirework();
}

//--------------------------------------------------------------
void ofApp::draw(){

    _laserPointDetector.Draw();
    _fireworks.DrawFirework();
}



//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){    
    _fireworks.AddFirework(x,y);
}
