#pragma once
#include <rapidjson/document.h>

using namespace rapidjson;

class JsonInfo
{
public:
	JsonInfo() {}
	JsonInfo(std::string& msg)
	{
		mRoot.Parse(msg.c_str(), msg.length());
	}

	JsonInfo(const char* msg, int32_t length)
	{
		mRoot.Parse(msg, length);
	}

	virtual ~JsonInfo() {}

	virtual void Parsing() PURE;

	// 쌓아넣은 데이터들을 문자열로 파싱 하는 함수
	// isPretty 엔터넣고 이쁘게 넣을지말지 결정
	std::string ToString(bool isPretty = false);

private:
	Document mRoot;
};