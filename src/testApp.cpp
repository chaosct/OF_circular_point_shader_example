#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	font.loadFont("verdana.ttf", 14, true, true);
	bUseShader = false;
	discShader.load("shaders/disc.vert", "shaders/disc.frag");
	for (int i = 0; i< MAX_PARTICLES; i++)
	{
		part_size[i] = ofRandom(2,5);
	}
}

//--------------------------------------------------------------
void testApp::update(){


for (int i = 0; i< MAX_PARTICLES; i++)
{
	float & x = part_pos[i*2+0];
	float & y = part_pos[i*2+1];
	x = x+ofRandomf();
	y = y+ofRandomf();
	if (x < 0 or x > ofGetWidth())
	{
		x = ofRandom(0,ofGetWidth());
	}
	if (y < 0 or y > ofGetHeight())
	{
		y = ofRandom(0,ofGetHeight());
	}
}

}

//--------------------------------------------------------------
void testApp::draw(){

	ofSetColor(100,0,0);
	if(!bUseShader)
	{
		for (int i = 0; i< MAX_PARTICLES; i++)
		{
			float & x = part_pos[i*2+0];
			float & y = part_pos[i*2+1];
			float & size = part_size[i];
			ofCircle(x,y,size);
		}
	}
	else
	{
		discShader.begin();
		discShader.setUniform2f("windowSize",ofGetWidth(),ofGetHeight());
		discShader.setAttribute1fv("part_size",part_size);
		glPointSize(10);
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(2,GL_FLOAT,0,part_pos);
		glDrawArrays(GL_POINTS,0,MAX_PARTICLES);
		glDisableClientState(GL_VERTEX_ARRAY);
		discShader.end();
		glPointSize(1);
	}
	ofSetColor(0,0,0);
	font.drawString(ofToString(ofGetFrameRate()),20,20);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if(key == 's')
	{
		bUseShader = !bUseShader;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
