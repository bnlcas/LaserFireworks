//
//  Firework.cpp
//  LaserFireworks
//
//  Created by Benjamin Lucas on 7/10/22.
//

#include "Firework.hpp"

void Firework::SetupFirework()
{
    for(int i = 1; i <= 9; i++){
        ofSoundPlayer sound;
        sound.load("bang_0" + std::to_string(i) + ".mp3");
        fireworkSounds.push_back(sound);
    }
    
    for(int i = 0; i < nPts; i++)
    {
        xPositions.push_back(0);
        yPositions.push_back(0);
    }
}


void Firework::UpdateFirework()
{
    if(isPlaying)
    {
        for(int i = 0; i < nPts; i ++)
        {
            yPositions[i] -= (velocity);
        }
        velocity += GRAVITY;
        if(velocity < 0 || yPositions[0] < y_0)
        {
            ExplodeFirework();
        }
    } else if(hasDetonated)
    {
        for(int i = 0; i < nPts; i ++)
        {
            int ind = (i * 5) % nPts;
            double theta = TAU * (double) ind / (double)nPts;
            xPositions[i] = x_0 + (int) ((double)detonationFrame * detonationVelocity * cos(theta));
            yPositions[i] = y_0 + (int) ((double)detonationFrame * detonationVelocity * sin(theta));
            detonationFrame += 1;
            if(detonationFrame > nDetonationFrames)
            {
                hasDetonated = false;
            }
        }
    }
}

void Firework::DrawFirework()
{
    if(isPlaying || hasDetonated)
    {
        for(int i = 0; i < nPts; i ++)
        {
            glm::vec2 position = glm::vec2(xPositions[i], yPositions[i]);
            ofDrawCircle(position, 3);
        }
    }
}

void Firework::ExplodeFirework()
{
    int randomSound =  (int)ofRandom(0,9);
    fireworkSounds[randomSound].play();
    isPlaying = false;
    hasDetonated = true;
    detonationFrame = 0;
}

void Firework::AddFirework(int x, int y)
{
    if(!isPlaying && ! hasDetonated)
    {
        hasDetonated = false;
        detonationFrame = 0;
        isPlaying = true;
        x_0 = x;
        y_0 = y;
        ofSetColor(150 + (int)ofRandom(100), 150 + (int)ofRandom(100), 150 + (int)ofRandom(100));
        for(int i = 0; i < nPts; i++)
        {
            xPositions[i] = x;
            yPositions[i] = ofGetHeight();
        }
        velocity = velocity_0;
    }
}
