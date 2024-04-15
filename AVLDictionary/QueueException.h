#ifndef QUEUEEXCEPTION_H
#define QUEUEEXCEPTION_H
#include <exception>

class QueueOverflow : public std::exception
{
public:
	QueueOverflow() :
		reason_("Queue Overflow\n")
	{}
	const char* what() const
	{
		return reason_;
	}
private:
	const char* reason_;
};

class QueueUnderflow : public std::exception
{
public:
	QueueUnderflow() :
		reason_("Queue Underflow\n")
	{}
	const char* what() const
	{
		return reason_;
	}
private:
	const char* reason_;
};

class WrongQueueSize : public std::exception
{
public:
	WrongQueueSize() :
		reason_("Wrong Queue Size\n")
	{}
	const char* what() const
	{
		return reason_;
	}
private:
	const char* reason_;
};

#endif
