#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H
#include "Queue.h"
#include "QueueException.h"
#include <iostream>

template <class T>
class QueueArray : public Queue<T>
{
public:
	QueueArray(int size = 512) :
		head_(0),
		tail_(0),
		maxSize_(size),
		size_(0)
	{
		try
		{
			if (size <= 0)
			{
				throw WrongQueueSize();
			}
			queue_ = new T[size];
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	QueueArray(const QueueArray<T>&) = delete;
	QueueArray(QueueArray<T>&& src) :
		queue_(src.queue_),
		head_(src.head_),
		tail_(src.tail_),
		maxSize_(src.maxSize_),
		size_(src.size_)
	{
		src.queue_ = nullptr;
		src.head_ = 0;
		src.tail_ = 0;
		src.maxSize_ = 0;
		src.size_ = 0;
	}
	QueueArray& operator=(const QueueArray<T>&) = delete;
	QueueArray& operator=(QueueArray<T>&& src);
	~QueueArray()
	{
		delete[] queue_;
	}
	void enQueue(const T&) override;
	T deQueue() override;
	bool isEmpty() override;
	int size();
private:
	T* queue_;
	int head_;
	int tail_;
	int maxSize_;
	int size_;
};

#endif

template<class T>
inline QueueArray<T>& QueueArray<T>::operator=(QueueArray<T>&& src)
{
	delete[] queue_;
	queue_ = src.queue_;
	head_ = src.head_;
	tail_ = src.tail_;
	maxSize_ = src.maxSize_;
	size_ = src.size_;
	src.queue_ = nullptr;
	src.head_ = 0;
	src.tail_ = 0;
	src.maxSize_ = 0;
	src.size_ = 0;
}

template<class T>
void QueueArray<T>::enQueue(const T& element)
{
	if (size_ == maxSize_)
		throw QueueOverflow();
	queue_[tail_] = element;
	++size_;
	if (tail_ == maxSize_ - 1)
		tail_ = 0;
	else
		++tail_;
}

template<class T>
T QueueArray<T>::deQueue()
{
	if (size_ == 0)
		throw QueueUnderflow();
	T element = queue_[head_];
	--size_;
	if (head_ == maxSize_ - 1)
		head_ = 0;
	else
		++head_;
	return element;
}

template<class T>
bool QueueArray<T>::isEmpty()
{
	return size_ == 0;
}

template<class T>
int QueueArray<T>::size()
{
	return size_;
}
