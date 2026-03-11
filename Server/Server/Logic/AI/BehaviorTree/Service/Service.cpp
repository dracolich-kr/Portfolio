#include <Pch.h>

namespace BehaviorTree
{
	bool Service::CanWork(DeltaTime delta_time)
	{
		delta_time;

		return true;
	}

	void Service::Update(DeltaTime delta_time)
	{
		if (CanWork(delta_time) == false)
			return;
	}
}