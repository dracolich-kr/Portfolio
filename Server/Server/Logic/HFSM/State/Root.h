

namespace HFSM
{
	class Root : public State
	{
	public:
		Root(std::shared_ptr<Machine> machine)
			: State(machine, nullptr, StateType::Root)
		{}

	private:

	};
}