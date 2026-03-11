#include <Pch.h>

ErrorResult ItemDict::Load(DefString path, DefString file_name)
{
	for (Int32 index = 0; index < 20; index++)
	{
		ItemElem* elem = new ItemElem(index + 1);
		mElems.emplace(index + 1, elem);
	}

	return ErrorResult::Success;
}