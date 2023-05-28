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

ErrorResult SkillState::Update(DeltaTime delta_time)
{
	return ErrorResult::Success;
}

void SkillRootState::OnEnter(const SkillTriggerType trigger_type)
{

}

void SkillRootState::OnLeave()
{

}

ErrorResult SkillRootState::Update(DeltaTime delta_time)
{
	return ErrorResult::Success;
}


void SkillInitState::OnEnter(const SkillTriggerType trigger_type)
{

}

void SkillInitState::OnLeave()
{

}

ErrorResult SkillInitState::Update(DeltaTime delta_time)
{
	return ErrorResult::Success;
}

void SkillCastState::OnEnter(const SkillTriggerType trigger_type)
{

}

void SkillCastState::OnLeave()
{

}

ErrorResult SkillCastState::Update(DeltaTime delta_time)
{
	return ErrorResult::Success;
}

void SkillShotState::OnEnter(const SkillTriggerType trigger_type)
{

}

void SkillShotState::OnLeave()
{

}

ErrorResult SkillShotState::Update(DeltaTime delta_time)
{

	return ErrorResult::Success;
}

void SkillFinishState::OnEnter(const SkillTriggerType trigger_type)
{

}

void SkillFinishState::OnLeave()
{

}

ErrorResult SkillFinishState::Update(DeltaTime delta_time)
{
	return ErrorResult::Success;
}

void SkillExitState::OnEnter(const SkillTriggerType trigger_type)
{

}

void SkillExitState::OnLeave()
{

}

ErrorResult SkillExitState::Update(DeltaTime delta_time)
{

	return ErrorResult::Success;
}