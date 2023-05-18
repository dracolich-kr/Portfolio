#pragma once

enum class ErrorResult : Int32
{
	Success = 0
	, Failed = 1
	, CommonBegin = 100'000
		, InvalidError
		, InitalizeFailed
		, AllocFailed
	, CommonEnd

	, NetworkBegin = 200'000
		, SocketAllocFailed
		, SocketDisconnect
		, SocketBindFailed
		, SocketFailed
	, NetworkEnd
	, DataBaseBegin = 300'000
		, NotFindDataBase
		, IsTranscationOn
		, NoData
	, DataBaseEnd

	, RedisBegin = 400'000
		, RedisNotFindKey
		, RedisInvalidParameter
	, RedisEnd 
};



