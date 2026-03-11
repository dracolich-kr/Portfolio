#include <Pch.h>

namespace BehaviorTree
{
	Result Paralle::Work(DeltaTime delta_tick)
	{
		Result result = Result::Failure;

		if (mCurrent == mNodes.end())
			ResetCurrent();

		for (; mCurrent != mNodes.end(); ++mCurrent)
		{
			result = mCurrent->get()->Work(delta_tick);

			switch (result)
			{
			case Result::Running:
				return result;
			case Result::Success:
			case Result::Failure:
			default:
				break;
			}
		}

		return Result::Success;
	}
}