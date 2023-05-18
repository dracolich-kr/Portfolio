#pragma once

namespace BehaviorTree
{
	enum class Result
	{
		// 성공
		  Success = 0
		// 실패
		, Failure = 1
		// 노드 진행 중
		, Running  = 2
	};

	__interface Node 
	{
		Result Work(DeltaTime delta_tick) PURE;
	};
}