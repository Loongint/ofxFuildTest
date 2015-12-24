#include "ofMain.h"

class particle{

	public:
    
    particle();
    void update();
    void display();
    
    ofPoint loc, vel, acc;
    ofFloatColor color;
};
