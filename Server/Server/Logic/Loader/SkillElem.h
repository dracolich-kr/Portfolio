#pragma once

class SkillElem
	: public BaseElem
{
public:
	SkillElem(ElemIndex index) 
		: BaseElem(index)
	{}
	virtual ~SkillElem() {}

	const Int32 GetRange() { return mRange; }

private:
	Int32 mRange;
	Int32 mCoolTime;
};
