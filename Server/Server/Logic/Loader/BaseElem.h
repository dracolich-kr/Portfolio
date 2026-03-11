#pragma once

class BaseElem abstract
	: public ICustomMemory
{
public:
	BaseElem(ElemIndex index) 
		: mIndex(index)
	{}
	virtual ~BaseElem() {}

protected:
	ElemIndex mIndex;
};
