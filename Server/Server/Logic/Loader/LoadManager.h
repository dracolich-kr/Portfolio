#pragma once

class LoadManager 
	: public Singleton<LoadManager>

{
private:
	friend Singleton<LoadManager>;

	LoadManager() {}
public:
	virtual ~LoadManager()
	{}
	virtual ErrorResult Initalize() override;

	ErrorResult LoadDict(DefString path);

	ItemElem* GetItemElem(ElemIndex index);
	bool GetItemElem(ElemIndex index, OUT ItemElem** elem);

	SkillElem* GetSkillElem(ElemIndex index);
	bool GetSkillElem(ElemIndex index, OUT SkillElem** elem);

private:
	Map<LoaderType, std::shared_ptr<BaseDict>> mDicts;
};