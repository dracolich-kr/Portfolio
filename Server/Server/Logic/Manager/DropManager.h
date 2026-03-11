#pragma once

class DropManager
	: public Singleton<DropManager>
{
	friend Singleton<ThreadManager>;
public:
	DropManager() {}
	virtual ~DropManager() {}

	ErrorResult Initlize();

private:

};