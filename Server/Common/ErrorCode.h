#pragma once

enum class ErrorResult : Int32
{
	Success = 0
	, Failed = 1
	, CommonBegin = 10'000
		, InvalidError
		, InitalizeFailed
		, InvalidParameter
		, AllocFailed
	, CommonEnd
		
	, NetworkBegin = 20'000
		, SocketAllocFailed
		, SocketDisconnect
		, SocketBindFailed
		, SocketFailed
	, NetworkEnd
	, DataBaseBegin = 30'000
		, NotFindDataBase
		, IsTranscationOn
		, NoData
	, DataBaseEnd

	, RedisBegin = 40'000
		, RedisNotFindKey
		, RedisInvalidParameter
	, RedisEnd 
	
	, ItemBegin = 50'000
		, CantFindItem
	, ItemEnd

	, SkillBegin = 60'000
	, SkillEnd
};



