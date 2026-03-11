#include "Pch.h"

namespace BehaviorTree
{
	Result Selector::Work(DeltaTime delta_tick)
	{
		Result result = Result::Failure;

		if (mCurrent == mNodes.end())
			ResetCurrent();

		for(;mCurrent != mNodes.end(); ++mCurrent)
		{
			result = mCurrent->get()->Work(delta_tick);
			switch (result)
			{
			case Result::Running:
			case Result::Success:
				return result;
			case Result::Failure:
			default:
				break;
			}
		}

		return Result::Failure;
	}
}