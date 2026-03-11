

class FieldItem
	: public FieldObject
{
public:
	FieldItem()
		: mItemId(0)
		, mCount(0)
	{}
	virtual ~FieldItem() {}

	ErrorResult Initalize();

	ErrorResult Update(DeltaTime delta) override;

private:
	ItemId mItemId;
	ItemCount mCount;

};