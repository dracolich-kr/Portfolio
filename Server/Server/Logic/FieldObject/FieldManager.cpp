#include <Pch.h>

ErrorResult FieldManager::Initalize()
{

	return ErrorResult::Success;
}

ErrorResult FieldManager::Update(DeltaTime delta_time)
{
	List<FieldObjectId> del_list;

	for (auto obj : mObjects)
	{
		obj.second->Update(delta_time);

		if (obj.second->IsExpired() == true)
		{
			del_list.push_back(obj.second->GetId());
		}

		for (auto del_id : del_list)
		{
			mObjects.erase(del_id);
		}
	}

	return ErrorResult::Success;
}