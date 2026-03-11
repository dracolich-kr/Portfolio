#include <Pch.h>

ErrorResult FieldItem::Initalize()
{

	return ErrorResult::Success;
}

ErrorResult FieldItem::Update(DeltaTime delta_time)
{
	auto result = FieldObject::Update(delta_time);
	IF_RETURN(result != ErrorResult::Success, ErrorResult::Failed);

	return ErrorResult::Success;
}