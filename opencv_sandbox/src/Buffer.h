/*
 * Buffer.h
 *
 *  Created on: Sep 8, 2017
 *      Author: hazim
 */

#include <iostream>
#include <thread>
#include <deque>
#include <mutex>
#include <chrono>
#include <condition_variable>
#include "Job.h"

#ifndef SRC_BUFFER_H_
#define SRC_BUFFER_H_

using namespace std;

class Buffer {
public:
	Buffer(int buf_size);
	void add(Job item);
	Job remove();
	virtual ~Buffer();
private:
	deque<Job> buffer_;
	std::mutex _mtx;
	std::condition_variable cond;
	unsigned int size_;
};

#endif /* SRC_BUFFER_H_ */
