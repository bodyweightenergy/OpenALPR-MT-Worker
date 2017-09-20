/*
 * Consumer.h
 *
 *  Created on: Sep 9, 2017
 *      Author: hazim
 */

#ifndef SRC_CONSUMER_H_
#define SRC_CONSUMER_H_

#include "Buffer.h"
#include "alpr.h"
#include "Job.h"

using namespace alpr;

class Consumer {
public:
	Consumer();
	Consumer(Buffer);
	void run();
private:
	Buffer* _buffer;
	Alpr* _reader;
	bool _readerLoaded;
	void Init();
};

#endif /* SRC_CONSUMER_H_ */
