//
//  LaserPointDetector.cpp
//  LaserFireworks
//
//  Created by Benjamin Lucas on 7/10/22.
//

#include "LaserPointDetector.hpp"

void LaserPointDetector::Setup()
{
    _settingsGui.Setup();

    vector<ofVideoDevice> devices = vidGrabber.listDevices();
    
    for(size_t i = 0; i < devices.size(); i++){
        if(devices[i].bAvailable){
            //log the device
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
        }else{
            //log the device and note it as unavailable
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
        }
    }
    
    vidGrabber.setDeviceID(2);//devices.size()-1);
    vidGrabber.setDesiredFrameRate(30);
    
    vidGrabber.initGrabber(CAM_WIDTH, CAM_HEIGHT);

    colorImg.allocate(CAM_WIDTH, CAM_HEIGHT);
    redHue.allocate(CAM_WIDTH, CAM_HEIGHT);
}

bool LaserPointDetector::Update()
{
    centerPoint = glm::vec2(_settingsGui.GetXOffset(), _settingsGui.GetYOffset());
    vidGrabber.update();
    if (vidGrabber.isFrameNew()){
        colorImg.setFromPixels(vidGrabber.getPixels());
        redHue.setFromPixels(vidGrabber.getPixels().getChannel(0));
        
        //ofPixels pix = vidGrabber.getPixels();
                
        cv::Mat tmp = ofxCv::toCv(redHue);
        double a,maxVal;
        cv::Point p1, maxLoc;
        
        cv::minMaxLoc(tmp, &a, &maxVal, &p1, &maxLoc);
        centerPoint.x =  _settingsGui.GetXOffset() + _settingsGui.GetXScale() * ((float)ofGetWidth() / (float)CAM_WIDTH) * maxLoc.x;
        centerPoint.y = _settingsGui.GetYOffset() + _settingsGui.GetYScale() * ((float)ofGetHeight() / (float)CAM_HEIGHT) * maxLoc.y;
        
        if(_settingsGui.GetShowPreview())
        {
        unsigned char * pix = colorImg.getPixels().getData();
          
        //for a 3 channel rgb image
        for(int i = 0; i < colorImg.width * colorImg.height * 3; i++){
            pix[i] = (pix[i]/4); //this makes sure it doesn't go over 255 as it will wrap to 0 otherwise.
            }
        }
        //ofLogNotice() << maxVal;
        if(maxVal > _settingsGui.GetBrightnessThreshold())
        {
            return true;
        }
    }
    return false;
}

void LaserPointDetector::Draw()
{
    if(_settingsGui.GetShowPreview())
    {
        colorImg.draw(0,0, ofGetWidth(), ofGetHeight());
        ofDrawCircle(centerPoint, 5);
    }
    _settingsGui.Draw();
}

glm::vec2 LaserPointDetector::GetPointerTarget()
{
    return centerPoint;
}
