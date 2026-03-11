#include <Pch.h>

ErrorResult CombatObject::Initalize()
{
	mAttribute = MakeShared<Attribute>(*this);
	mSkillManager = MakeShared<SkillManager>(*this);

	mAttribute->Initalize();
	mSkillManager->Initalize();

	InitHFSM();

	return ErrorResult::Success;
}

ErrorResult CombatObject::Release()
{
	return ErrorResult::Success;
}

ErrorResult CombatObject::Update(DeltaTime delta)
{
	ErrorResult result = Entity::Update(delta);
	IF_RETURN(result != ErrorResult::Success, result);

	return result;
}
