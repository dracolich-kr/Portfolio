#pragma once

enum class ItemType
{
	None = 0
	, Potion
	, Weapon
	, Shield
	, Max
};

enum class ExpaireType
{
	None = 0
	, 
};

class ItemElem
	: public BaseElem
{
public:
	ItemElem(ElemIndex index)
		: BaseElem(index)
	{}

	virtual ~ItemElem() 
	{
	}

private:
	
};

