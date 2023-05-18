#pragma once

// 서버에 연결을 할 때 사용하는 소켓.

class ClientSocket : public UserSocket
{
public:
	virtual ErrorResult Connect(DefString ip, Port port) override;
	virtual ErrorResult Disconnect() override;

private:

};