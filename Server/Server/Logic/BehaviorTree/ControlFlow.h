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

		std::list<std::shared_ptr<Node>>& GetNodes() { return mNodes; }
		void ResetCurrent() { mCurrent = mNodes.begin(); }
		void SetCurrent(std::list<std::shared_ptr<Node>>::iterator& temp) { mCurrent = temp; }
		const std::list<std::shared_ptr<Node>>::iterator& GetCurrent() const { return mCurrent; }

	protected:
		std::list<std::shared_ptr<Node>> mNodes;
		std::list<std::shared_ptr<Node>>::iterator mCurrent;
	};
}