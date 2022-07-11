//
//  SettingsGUI.hpp
//  LaserFireworks
//
//  Created by Benjamin Lucas on 7/10/22.
//

#ifndef SettingsGUI_hpp
#define SettingsGUI_hpp

#include <stdio.h>
#include "ofxGui.h"

class SettingsGUI
{
public:
    SettingsGUI(){}
    
    void Setup(){
        //GUI:
        _gui.setup();
        _gui.add(_brightessThreshold.set("BrightnessThresh", 255, 0.0, 255));
        _gui.add(_xOffset.set("X-Offset", 0, -500, 500));
        _gui.add(_yOffset.set("Y-Offset", 0, -500, 500));
        _gui.add(_xScale.set("X-Scale", 1, 0, 2.5));
        _gui.add(_yScale.set("Y-Scale", 1, 0, 2.5));
        _gui.add(_showPreview.set("Show Preview", false));
    };
    
    void Draw()
    {
        _gui.draw();
    }
    
    float GetBrightnessThreshold()
    {
        return _brightessThreshold.get();
    }
    
    float GetXOffset()
    {
        return _xOffset.get();
    }
    
    float GetYOffset()
    {
        return _yOffset.get();
    }
    
    float GetXScale()
    {
        return _xScale.get();
    }
    
    float GetYScale()
    {
        return _yScale.get();
    }
    
    bool GetShowPreview()
    {
        return _showPreview.get();
    }
    
private:
    ofxPanel _gui;

    ofParameter<float> _brightessThreshold;
    ofParameter<float> _xOffset;
    ofParameter<float> _yOffset;
    ofParameter<float> _xScale;
    ofParameter<float> _yScale;
    ofParameter<bool> _showPreview;
};

#endif /* SettingsGUI_hpp */
