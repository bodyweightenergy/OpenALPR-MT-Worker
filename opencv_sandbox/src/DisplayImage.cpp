/*
 * DisplayImage.cpp
 *
 *  Created on: Jun 9, 2017
 *      Author: hazim
 */

#include <thread>
#include <mutex>
#include <chrono>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include "opencv2/video.hpp"
#include <unistd.h>
#include "Buffer.h"
#include "Producer.h"
#include "Consumer.h"
#include "alpr.h"

using namespace std;
using namespace cv;
using namespace alpr;

vector<uchar> MatBytes(Mat mat);

int main(int argc, char **argv) {

	Alpr openalpr("us", "/usr/share/openalpr/config/openalpr.defaults.conf");

	// Optionally specify the top N possible plates to return (with confidences).  Default is 10
	openalpr.setTopN(5);

	// Optionally, provide the library with a region for pattern matching.  This improves accuracy by
	// comparing the plate text with the regional pattern.
	openalpr.setDefaultRegion("mo");

	// Make sure the library loaded before continuing.
	// For example, it could fail if the config/runtime_data is not found
	if (openalpr.isLoaded() == false) {
		std::cerr << "Error loading OpenALPR" << std::endl;
		return 1;
	}

	VideoCapture cap("/home/hazim/data/subaru.avi");
	if (!cap.isOpened()) {
		return -1;
	}

	int counter = 0;

	while (true) {
		// Get next video frame
		Mat frame;
		cap >> frame;
		cout << "frame: [" << frame.cols << ", " << frame.rows << ", " << frame.channels() << "]" << endl;
		if (!frame.empty()) {

			Job job(counter);
			job.Set_Frame(frame);
			// Recognize an image file.  You could alternatively provide the image bytes in-memory.
			alpr::AlprResults results = openalpr.recognize(frame.data,
					frame.channels(), frame.cols, frame.rows,
					vector<AlprRegionOfInterest>());
			job.Set_Results(results);

			// Iterate through the results.  There may be multiple plates in an image,
			// and each plate return sthe top N candidates.
			for (unsigned int i = 0; i < results.plates.size(); i++) {
				alpr::AlprPlateResult plate = results.plates[i];
				std::cout << "plate" << i << ": " << plate.topNPlates.size()
						<< " results" << std::endl;

				for (unsigned int k = 0; k < plate.topNPlates.size(); k++) {
					alpr::AlprPlate candidate = plate.topNPlates[k];
					std::cout << "    - " << candidate.characters
							<< "\t confidence: "
							<< candidate.overall_confidence;
					std::cout << "\t pattern_match: "
							<< candidate.matches_template << std::endl;
				}
			}
			cv::imshow("frame", frame);
			cv::waitKey(50);
			counter++;
		} else {
			break;
		}

	}

//	Producer prod1(buf1);
//	Producer prod2(buf1);
//	Consumer cons1(buf1);
//	Consumer cons2(buf1);
//
//	std::thread pro_thread1(&Producer::run, &prod1);
//	std::thread pro_thread2(&Producer::run, &prod2);
//	std::thread con_thread1(&Consumer::run, &cons1);
//	std::thread con_thread2(&Consumer::run, &cons2);
//
//	pro_thread1.join();
//	pro_thread2.join();
//	con_thread1.join();
//	con_thread2.join();

//	getchar();
	cv::destroyAllWindows();
	cout << "Program complete." << endl;
	return 0;
}

