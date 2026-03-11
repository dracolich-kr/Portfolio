#pragma once

namespace BehaviorTree
{
	// 노드를 순회하며 false를 만날떄까지 순회 한다.
	class Sequence : public ControlFlow
	{
	public:
		Sequence() {}
		virtual ~Sequence() {}

		Result Work(DeltaTime delta_tick) override;
	};
}