#pragma once

class ItemKeyGenerator
	: public KeyGenerator<ItemId>
{
public:
	ItemKeyGenerator()
	{}
	virtual ~ItemKeyGenerator() {}

	ItemId Generate() override;
private:

};