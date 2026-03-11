#include <Pch.h>

ErrorResult Skill::Initalize()
{
	auto root = MakeShared<SkillStateRoot>(*mMachine, nullptr, *this);
	mMachine = MakeShared<HFSM::Machine<SkillStateType, SkillTriggerType>>();
	mMachine->Init(std::static_pointer_cast<HFSM::State<SkillStateType, SkillTriggerType>>(root));

	auto init = MakeShared<SkillStateInit>(*mMachine, root, *this);
	init->AddTranscation(SkillStateType::Cast, SkillTriggerType::Timeout);
	mMachine->AddState(init);

	auto cast = MakeShared<SkillStateCast>(*mMachine, root, *this);
	cast->AddTranscation(SkillStateType::Shot, SkillTriggerType::Timeout);
	mMachine->AddState(cast);

	auto shot = MakeShared<SkillStateShot>(*mMachine, root, *this);
	shot->AddTranscation(SkillStateType::Finish, SkillTriggerType::Timeout);
	mMachine->AddState(shot);

	auto finish = MakeShared<SkillStateFinish>(*mMachine, shot, *this);
	finish->AddTranscation(SkillStateType::Exit, SkillTriggerType::Timeout);
	mMachine->AddState(finish);

	auto exit = MakeShared<SkillStateExit>(*mMachine, root, *this);
	mMachine->AddState(exit);

	mMachine->CalculateTransition();

	return ErrorResult::Success;
}