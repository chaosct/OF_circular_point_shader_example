#pragma once

#include "ofMain.h"

#define MAX_PARTICLES 10000

class testApp : public ofBaseApp{

	public:
		float part_pos[MAX_PARTICLES*2];
		float part_size[MAX_PARTICLES];
		ofTrueTypeFont font;
		bool bUseShader;
		ofShader discShader;

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
