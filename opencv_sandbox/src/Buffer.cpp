/*
 * Buffer.cpp
 *
 *  Created on: Sep 8, 2017
 *      Author: hazim
 */

#include "Buffer.h"

 Buffer::Buffer(int buf_size) {
	 size_ = buf_size;
}

Buffer::~Buffer() {
	buffer_.clear();
}

void Buffer::add(Job item)
{
	while (true) {
	            std::unique_lock<std::mutex> locker(_mtx);
	            cond.wait(locker, [this](){return buffer_.size() < size_;});
	            buffer_.push_back(item);
	            locker.unlock();
	            cond.notify_all();
	            std::cout << "Buffer Add: " << item.Get_ID() << "\n";
	            return;
	        }
}


Job Buffer::remove()
{
	while (true)
	        {
	            std::unique_lock<std::mutex> locker(_mtx);
	            cond.wait(locker, [this](){return buffer_.size() > 0;});
	            Job back = buffer_.back();
	            buffer_.pop_back();
	            locker.unlock();
	            cond.notify_all();
	            std::cout << "Buffer Remove: " << back.Get_ID() << "\n";
	            return back;
	        }
}



