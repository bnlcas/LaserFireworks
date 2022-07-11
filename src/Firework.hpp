//
//  Firework.hpp
//  LaserFireworks
//
//  Created by Benjamin Lucas on 7/10/22.
//

#ifndef Firework_hpp
#define Firework_hpp
#define PI 3.14159265358979323846
#define TAU 6.28318530718

#include <stdio.h>
#include <cmath>
#include "ofMain.h"

class Firework
{
public:
    Firework(){};
    
    void SetupFirework();
    
    void UpdateFirework();
    
    void DrawFirework();
    
    void ExplodeFirework();
    
    void AddFirework(int x, int y);
    
private:
    bool isPlaying = false;
    const int nPts = 23;
    const int GRAVITY = -1;
    const int velocity_0 = 30;
    int velocity = 0;
    double detonationVelocity = 0.8;
    int nDetonationFrames = 180;
    int detonationFrame = 0;

    bool hasDetonated = false;
    int x_0;
    int y_0;
    vector<ofSoundPlayer> fireworkSounds;
    vector<int> xPositions;
    vector<int> yPositions;
};
#endif /* Firework_hpp */
