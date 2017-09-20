/*
 * Job.cpp
 *
 *  Created on: Sep 9, 2017
 *      Author: hazim
 */

#include "Job.h"

Job::Job(int ID) : _id(ID) {}

Job::Job(int ID, Mat frame) : _id(ID), _frame(frame) {}

Job::~Job() {
	// TODO Auto-generated destructor stub
}

int Job::Get_ID() {
	return _id;
}

Mat Job::Get_Frame() {
	return _frame;
}
AlprResults Job::Get_Results() {
	return _results;
}
void Job::Set_Frame(Mat frame) {
	_frame = frame;
}
void Job::Set_Results(AlprResults results) {
	_results = results;
}
