#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending();
    ofSetCircleResolution(100);
    
    width = ofGetWidth();
    height = ofGetHeight();
    
    fluid.allocate(width, height, 0.5);
    
    fluid.dissipation = 0.99;
    fluid.velocityDissipation = 0.99;
    
    fluid.setGravity(ofVec2f(0.0,0.0));
    fluid.begin();
    ofSetColor(0,0);
    ofSetColor(255);
    ofDrawCircle(width*0.5, height*0.35, 40);
    fluid.end();
    fluid.setUseObstacles(false);
    
    for(int i = 0; i < 50; i ++) {
        particle p;
        particles.push_back(p);
    }
    
    music.load("1.mp3");
    music.setLoop(true);
    //music.play();
    
    nBandsToGet = 128;
    
    fftSmoothed.assign(nBandsToGet, 0.0);
}

//--------------------------------------------------------------
void ofApp::update(){
    float * fft = ofSoundGetSpectrum(nBandsToGet);
    
    for(int i = 0; i < nBandsToGet; i++) {
        fftSmoothed[i] *= 0.9f;
        if(fftSmoothed[i] < fft[i]) fftSmoothed[i] = fft[i];
    }
    
    float max = 0;
    for(int i = 0; i < nBandsToGet; i ++) {
        if(max < fft[i]) {
            max = fft[i];
        }
    }
    
    cout << fft[0] <<endl;
    
    if (max > .2) {
        for(int i = 0; i < particles.size(); i++) {
            particles[i].update();
            fluid.addTemporalForce(particles[i].loc,particles[i].vel,particles[i].color, 14.0f);
        }
    } else {
        for(int i = 0; i < particles.size(); i++) {
            particles[i].update();
        }
    }
    
    ofSetWindowTitle("FrameRate : " + ofToString(ofGetFrameRate()));
    fluid.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::gray, ofColor::black, OF_GRADIENT_LINEAR);
    
    fluid.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    music.play();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}