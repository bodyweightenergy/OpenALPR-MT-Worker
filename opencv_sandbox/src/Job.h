/*
 * Job.h
 *
 *  Created on: Sep 9, 2017
 *      Author: hazim
 */

#ifndef SRC_JOB_H_
#define SRC_JOB_H_

#include <unistd.h>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include "opencv2/video.hpp"
#include "alpr.h"

using namespace cv;
using namespace alpr;

class Job {
public:
	Job(int id);
	Job(int id, Mat frame);
	virtual ~Job();
	int Get_ID();
	Mat Get_Frame();
	AlprResults Get_Results();
	void Set_Frame(Mat frame);
	void Set_Results(AlprResults results);
private:
	int _id;
	Mat _frame;
	AlprResults _results;
};


#endif /* SRC_JOB_H_ */
