#include <Pch.h>

void AsioThread::Work()
{
	//std::cout << "asio thread start :" << this->GetIndex() << std::endl;
	mContext->run();
	std::cout << "asio thread end :" << this->GetIndex() << std::endl;
}