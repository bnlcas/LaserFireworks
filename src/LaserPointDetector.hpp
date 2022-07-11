//
//  LaserPointDetector.hpp
//  LaserFireworks
//
//  Created by Benjamin Lucas on 7/10/22.
//

#ifndef LaserPointDetector_hpp
#define LaserPointDetector_hpp
#define CAM_WIDTH 640
#define CAM_HEIGHT 480


#include <stdio.h>
#include "ofMain.h"
#include "ofxOpenCv.h"
#include "opencv.hpp"
#include "ofxCv.h"
#include "SettingsGUI.hpp"

class LaserPointDetector{
public:
    LaserPointDetector(){}
    
    void Setup();
    
    bool Update();
 
    
    void Draw();
    
    glm::vec2 GetPointerTarget();
    
private:
    ofVideoGrabber vidGrabber;

    ofxCvColorImage colorImg;
    ofxCvGrayscaleImage redHue;
    
    glm::vec2 centerPoint;
    
    SettingsGUI _settingsGui;
};
#endif /* LaserPointDetector_hpp */
