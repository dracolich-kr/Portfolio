#pragma once

namespace BehaviorTree
{
	class ControlFlow abstract : public Node
	{
	public:
		ControlFlow()
			: mCurrent(mNodes.end())
		{
		}

		virtual ~ControlFlow() {}

		void Push(std::shared_ptr<Node> node)
		{
			mNodes.emplace_back(node);
		}

		List<std::shared_ptr<Node>>& GetNodes() { return mNodes; }
		void ResetCurrent() { mCurrent = mNodes.begin(); }
		void SetCurrent(List<std::shared_ptr<Node>>::iterator& temp) { mCurrent = temp; }
		const List<std::shared_ptr<Node>>::iterator& GetCurrent() const { return mCurrent; }

	protected:
		List<std::shared_ptr<Node>> mNodes;
		List<std::shared_ptr<Node>>::iterator mCurrent;
	};
}