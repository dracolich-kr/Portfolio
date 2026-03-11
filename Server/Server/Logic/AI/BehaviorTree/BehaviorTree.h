#pragma once

namespace BehaviorTree
{
	// º»Ã¼
	class Root : public ControlFlow
	{
	public:
		Root() {}
		virtual ~Root() {}

		Result Work(DeltaTime delta_tick) override;

		ErrorResult Load(DefString file_name);
		ErrorResult LoadXML(DefString file_name);

		ErrorResult Save(DefString file_name);
	private:

	};
}