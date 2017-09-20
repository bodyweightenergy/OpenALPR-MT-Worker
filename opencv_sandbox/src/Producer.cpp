/*
 * Producer.cpp
 *
 *  Created on: Sep 8, 2017
 *      Author: hazim
 */

#include "Producer.h"

Producer::Producer() {
	Init();
}

void Producer::Init(){
	_buffer = 0;
	_cap = 0;
}

Producer::Producer(string capturePath, Buffer buffer) {
	Init();
	_buffer = &buffer;
	InitCapture(capturePath);
}

bool Producer::InitCapture(string capturePath){
	_cap = new VideoCapture(capturePath);
	if(!_cap->isOpened()){
		std::cerr << "Error loading OpenALPR" << std::endl;
		return false;
	} else {
		return true;
	}
}

void Producer::run(){
	unsigned int id = 0;
	while(true){
		cout << "Produced: " << id << "\n";
		Mat frame;
		_cap >> frame;

		// Check if frame is empty
		if(frame.empty()){
			cout << "Empty frame received. Quitting producer loop." << endl;
			break;
		}

		Job newJob(id);
		newJob.Set_Frame(frame);
		_buffer->add(newJob);
		id++;
	}
}

