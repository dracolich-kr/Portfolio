#include <Pch.h>

bool SkillState::CanEnter(const SkillTriggerType trigger_type)
{
	return false;
}

void SkillState::OnEnter(const SkillTriggerType trigger_type)
{

}

void SkillState::OnLeave()
{

}

void SkillState::OnTransition(const SkillTriggerType trigger_type)
{

}

ErrorResult SkillState::Update(DeltaTime delta_time)
{
	return ErrorResult::Success;
}

void SkillStateRoot::OnEnter(const SkillTriggerType trigger_type)
{

}

void SkillStateRoot::OnLeave()
{

}

ErrorResult SkillStateRoot::Update(DeltaTime delta_time)
{
	return ErrorResult::Success;
}


void SkillStateInit::OnEnter(const SkillTriggerType trigger_type)
{

}

void SkillStateInit::OnLeave()
{

}

ErrorResult SkillStateInit::Update(DeltaTime delta_time)
{
	return ErrorResult::Success;
}

void SkillStateCast::OnEnter(const SkillTriggerType trigger_type)
{

}

void SkillStateCast::OnLeave()
{

}

ErrorResult SkillStateCast::Update(DeltaTime delta_time)
{
	return ErrorResult::Success;
}

void SkillStateShot::OnEnter(const SkillTriggerType trigger_type)
{

}

void SkillStateShot::OnLeave()
{

}

ErrorResult SkillStateShot::Update(DeltaTime delta_time)
{

	return ErrorResult::Success;
}

void SkillStateFinish::OnEnter(const SkillTriggerType trigger_type)
{

}

void SkillStateFinish::OnLeave()
{

}

ErrorResult SkillStateFinish::Update(DeltaTime delta_time)
{
	return ErrorResult::Success;
}

void SkillStateExit::OnEnter(const SkillTriggerType trigger_type)
{

}

void SkillStateExit::OnLeave()
{

}

ErrorResult SkillStateExit::Update(DeltaTime delta_time)
{

	return ErrorResult::Success;
}