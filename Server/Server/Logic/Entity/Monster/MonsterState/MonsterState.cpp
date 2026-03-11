#include <Pch.h>

bool MonsterState::CanEnter(const TriggerType trigger_type)
{
	return false;
}

void MonsterState::OnEnter(const TriggerType trigger_type)
{

}

void MonsterState::OnLeave()
{

}

void MonsterState::OnTransition(const TriggerType trigger_type)
{

}

ErrorResult MonsterState::Update(DeltaTime delta_time)
{

	return ErrorResult::Success;
}

void MonsterStateRoot::OnEnter(const TriggerType trigger_type)
{

}

void MonsterStateRoot::OnLeave()
{

}

ErrorResult MonsterStateRoot::Update(DeltaTime delta_time)
{

	return ErrorResult::Success;
}

void MonsterStateSpawn::OnEnter(const TriggerType trigger_type)
{

}

void MonsterStateSpawn::OnLeave()
{

}

ErrorResult MonsterStateSpawn::Update(DeltaTime delta_time)
{

	return ErrorResult::Success;
}