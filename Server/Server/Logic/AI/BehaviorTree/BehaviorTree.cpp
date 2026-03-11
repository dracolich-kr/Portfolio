#include <Pch.h>

namespace BehaviorTree
{
	Result Root::Work(DeltaTime delta_tick)
	{
		Result result = Result::Success;

		if (mCurrent == mNodes.end())
			ResetCurrent();

		for (; mCurrent != mNodes.end(); ++mCurrent)
		{
			result = mCurrent->get()->Work(delta_tick);
			switch (result)
			{
			case Result::Failure:
			case Result::Running:
				return result;
			case Result::Success:
			default:
				break;
			}
		}

		return Result::Success;
	}

	ErrorResult Root::Load(DefString file_name)
	{
		file_name;

		return ErrorResult::Success;
	}

	ErrorResult Root::LoadXML(DefString file_name)
	{
		file_name;

		return ErrorResult::Success;
	}


	ErrorResult Save(DefString file_name)
	{
		file_name;

		return ErrorResult::Success;
	}
};