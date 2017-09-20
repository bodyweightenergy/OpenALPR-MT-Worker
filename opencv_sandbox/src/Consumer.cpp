/*
 * Consumer.cpp
 *
 *  Created on: Sep 9, 2017
 *      Author: hazim
 */

#include "Consumer.h"

Consumer::Consumer() {
	Init();
}

Consumer::Consumer(Buffer buffer) {
	Init();
	_buffer = &buffer;
}

void Consumer::Init() {
	_buffer = 0;
	_reader = new Alpr("us",
			"/usr/share/openalpr/config/openalpr.defaults.conf");
	_reader->setDefaultRegion("mo");
	_reader->setTopN(5);
	_readerLoaded = _reader->isLoaded();
	if (!_readerLoaded) {
		std::cerr << "Error loading OpenALPR" << std::endl;
	}
}

void Consumer::run() {
	while (true) {
		Job job = _buffer->remove();
		Mat frame = job.Get_Frame();
		if (_readerLoaded && !frame.empty()) {
			AlprResults results = _reader->recognize(frame.data,
					frame.channels(), frame.cols, frame.rows,
					vector<AlprRegionOfInterest>());
			job.Set_Results(results);
		}
		cout << "Consumed: " << job.Get_ID();
		if (job.Get_Results().plates.size() > 0) {
			cout << " found " << job.Get_Results().plates.size() << " plates.";
		}
		cout << "\n";
	}
}

