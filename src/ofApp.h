#pragma once

#include "ofMain.h"
#include "LaserPointDetector.hpp"
#include "Firework.hpp"


class ofApp : public ofBaseApp{

    public:
        void setup();
        void update();
        void draw();
        void mousePressed(int x, int y, int button);
    
        
    
        LaserPointDetector _laserPointDetector;
        Firework _fireworks;
};

