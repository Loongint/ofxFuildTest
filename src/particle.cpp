#include "particle.h"

particle::particle() {
    loc = ofPoint(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
    vel = ofPoint(0,0);
    acc = ofPoint(ofRandom(-10, 10), ofRandom(-10, 10));
    color = ofFloatColor(ofRandom(.5),ofRandom(.5), ofRandom(.5));
}

void particle::update() {
    loc += vel;
    
    if((loc.x < 0) || (loc.x > ofGetWidth())) {
        vel.x = -vel.x;
        acc.x = -acc.x;
    }
    if((loc.y < 0) || (loc.y > ofGetHeight())) {
        vel.y = -vel.y;
        acc.y = -acc.y;
    }
    
    vel += acc;
    if(vel.x > 10) {
        vel.x = 10;
    }
    if(vel.y < -10) {
        vel.y = -10;
    }
    if(vel.x < -10) {
        vel.x = -10;
    }
    if(vel.y > 10) {
        vel.y = 10;
    }
    
    acc.x *= ofRandom(-5, 5);
    acc.y *= ofRandom(-5, 5);
}

void particle::display() {
    ofSetColor(255);
    ofDrawCircle(loc, 2);
}