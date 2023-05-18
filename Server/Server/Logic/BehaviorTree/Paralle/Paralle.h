#pragma once

namespace BehaviorTree
{
	// 해당 연결된 순회를 무조건 돈다.
	class Paralle : public ControlFlow
	{
	public:
		Paralle() {}
		virtual ~Paralle() {}

		Result Work(DeltaTime delta_tick) override;

	private:

	};
}