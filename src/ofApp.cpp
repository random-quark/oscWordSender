#include <iostream>
#include <string>

#include "ofApp.h"

void ofApp::sendMessage(string word) {
    ofxOscMessage m;
    m.setAddress("/word");
    m.addStringArg(word);
    sender.sendMessage(m, false);
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    font.load("arial.ttf", 100);
    
    host = ofGetEnv("HOST");
    if (host == "") throw "No HOST set in env var";
    port = std::stoi(ofGetEnv("PORT"));
    if (!port) throw "No PORT set in env var";
    sender.setup(host, port);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    font.drawString(word, ofGetWidth() / 2 - font.stringWidth(word) / 2, ofGetHeight() / 2);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == OF_KEY_RETURN) {
        sendMessage(word);
        word = "";
    } else {
        word += key;
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
