#pragma once

class ItemDict final
	: public Dict<ItemElem>
{
public:
	ItemDict() 
		: Dict(LoaderType::Item)
	{}

	~ItemDict() 
	{}

	ErrorResult Load(DefString path, DefString file_name) override;

private:

};

using SharedItemDict = std::shared_ptr<ItemDict>;