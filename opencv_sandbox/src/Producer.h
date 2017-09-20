/*
 * Producer.h
 *
 *  Created on: Sep 8, 2017
 *      Author: hazim
 */

#ifndef SRC_PRODUCER_H_
#define SRC_PRODUCER_H_

#include "Buffer.h"
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include "opencv2/video.hpp"

class Producer {
public:
	Producer();
	Producer(string capturePath, Buffer buffer);
	void run();
private:
    Buffer* _buffer;
    VideoCapture* _cap;
    void Init();
    bool InitCapture(string capturePath);
};


#endif /* SRC_PRODUCER_H_ */
