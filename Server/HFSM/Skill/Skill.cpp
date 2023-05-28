#include <Pch.h>

ErrorResult Skill::InitHFSM()
{
	auto root = std::make_shared<SkillRootState>(mMachine, nullptr, this->shared_from_this());
	mMachine = std::make_shared<HFSM::Machine<SkillStateType, SkillTriggerType>>();
	mMachine->Init(std::static_pointer_cast<HFSM::State<SkillStateType, SkillTriggerType>>(root));

	auto init = std::make_shared<SkillInitState>(mMachine, root, this->shared_from_this());
	init->AddTranscation(SkillStateType::Cast, SkillTriggerType::Timeout);
	mMachine->AddState(init);

	auto cast = std::make_shared<SkillCastState>(mMachine, root, this->shared_from_this());
	cast->AddTranscation(SkillStateType::Shot, SkillTriggerType::Timeout);
	mMachine->AddState(cast);

	auto shot = std::make_shared<SkillShotState>(mMachine, root, this->shared_from_this());
	shot->AddTranscation(SkillStateType::Finish, SkillTriggerType::Timeout);
	mMachine->AddState(shot);

	auto finish = std::make_shared<SkillFinishState>(mMachine, root, this->shared_from_this());
	finish->AddTranscation(SkillStateType::Exit, SkillTriggerType::Timeout);
	mMachine->AddState(finish);

	auto exit = std::make_shared<SkillExitState>(mMachine, root, this->shared_from_this());
	mMachine->AddState(exit);

	mMachine->CalcTransition();

	return ErrorResult::Success;
}

void Skill::Release()
{
	//mEffects.clear();
	//mMachine->Release();
	//mCombatObject = nullptr;
}