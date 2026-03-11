#pragma once

class SkillDict
	: public Dict<SkillElem>
{
public:
	SkillDict()
		: Dict(LoaderType::Skill)
	{}

	~SkillDict()
	{}

	virtual ErrorResult Load(DefString path, DefString file_name) override;

private:

};

using SharedSkillDict = std::shared_ptr<SkillDict>;