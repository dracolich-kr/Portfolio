#pragma once

namespace BehaviorTree
{
	// 노드를 순회 하며 True를 만날 때까지 순회 한다.
	class Selector : public ControlFlow
	{
	public:
		Selector() {}
		virtual ~Selector() {}

		Result Work(DeltaTime delta_tick) override;

	private:

	};
}