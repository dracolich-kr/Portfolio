#include <Pch.h>

ErrorResult LoadManager::Initalize()
{

	return ErrorResult::Success;
}

ErrorResult LoadManager::LoadDict(DefString path)
{
	auto loader = [=](std::shared_ptr<BaseDict> dict)
	{
		dict->Load(path, "file_name");
		mDicts.emplace(dict->GetType(), dict);
	};

	loader(MakeShared<ItemDict>());
	loader(MakeShared<SkillDict>());

	return ErrorResult::Success;
}

ItemElem* LoadManager::GetItemElem(ElemIndex index)
{
	auto dict = mDicts.find(LoaderType::Item);
	IF_RETURN(dict == mDicts.end(), nullptr);

	auto item_dict = std::static_pointer_cast<ItemDict>(dict->second);
	return item_dict->Find(index);
}


bool LoadManager::GetItemElem(ElemIndex index, OUT ItemElem** elem)
{
	auto dict = mDicts.find(LoaderType::Item);
	IF_RETURN(dict == mDicts.end(), false);

	auto item_dict = std::static_pointer_cast<ItemDict>(dict->second);
	return item_dict->Find(index, elem);
}

SkillElem* LoadManager::GetSkillElem(ElemIndex index)
{
	auto dict = mDicts.find(LoaderType::Skill);
	IF_RETURN(dict == mDicts.end(), nullptr);

	auto skill_dict = std::static_pointer_cast<SkillDict>(dict->second);
	return skill_dict->Find(index);
}


bool LoadManager::GetSkillElem(ElemIndex index, OUT SkillElem** elem)
{
	auto dict = mDicts.find(LoaderType::Skill);
	IF_RETURN(dict == mDicts.end(), false);

	auto item_dict = std::static_pointer_cast<SkillDict>(dict->second);
	return item_dict->Find(index, elem);
}