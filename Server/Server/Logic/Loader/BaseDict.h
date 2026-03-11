#pragma once

class BaseDict abstract
{
public:
	BaseDict(LoaderType type)
		: mType(type)
	{}

	virtual ErrorResult Load(DefString path, DefString file_name) PURE;
	const LoaderType& GetType() { return mType; }
protected:
	LoaderType mType;
};

template<class TElem>
class Dict abstract
	: public BaseDict
{
public:
	Dict(LoaderType type)
		: BaseDict(type)
	{
		static_assert(std::is_base_of<BaseElem, TElem>::value, "is not Base Elem");
	}
	virtual ~Dict() {}

	bool Find(ElemIndex index, OUT TElem** output)
	{
		auto elem = mElems.find(index);
		IF_RETURN(elem == mElems.end(), false);

		*output = elem->second;
		return true;
	}

	TElem* Find(ElemIndex index)
	{
		auto elem = mElems.find(index);
		IF_RETURN(elem == mElems.end(), nullptr);
		return elem->second;
	}

protected:
	Map<ElemIndex, TElem*> mElems;
};

template<class TElem>
using SharedDict = std::shared_ptr<Dict<TElem>>;