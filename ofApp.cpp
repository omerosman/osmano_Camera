#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	camWidth = 320;
	camHeight = 240;

	vidGrabber.setVerbose(true);
	vidGrabber.setDeviceID(0);
	vidGrabber.setDesiredFrameRate(60);
	vidGrabber.initGrabber(camWidth, camHeight);

	vidInverted.allocate(camWidth, camHeight, OF_PIXELS_RGB);
	vidTexture.allocate(vidInverted);

}

//--------------------------------------------------------------
void ofApp::update(){
	vidGrabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(ofColor::white);
	vidGrabber.draw(2 * camWidth + 60, 20);
	vidGrabber.draw(camWidth + 20, 20, -camWidth, camHeight);
	vidGrabber.draw(camWidth + 20, 2 * camHeight + 40, -camWidth, -camHeight);
	vidGrabber.draw(2 * camWidth + 60, 2 * camHeight + 40, camWidth, -camHeight);

	vidTexture.draw(camWidth + 40, 20);
	vidTexture.draw(camWidth + 40, 2*camHeight + 40, camWidth, -camHeight);


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	
	if (key == 'x') {
		if (vidGrabber.isFrameNew()) {
			ofPixels & pixels = vidGrabber.getPixels();
			for (size_t i = 0; i < pixels.size(); i++) {
				//invert the color of the pixel
				vidInverted[i] = 255 - pixels[i];
			}
			//load the inverted pixels
			vidTexture.loadData(vidInverted);
		}
	}

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
