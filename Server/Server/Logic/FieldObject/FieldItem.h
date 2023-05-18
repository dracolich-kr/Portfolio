

class FieldItem
	: public FieldObject
{
public:
	FieldItem() {}
	virtual ~FieldItem() {}

	ErrorResult Update(DeltaTime delta) override;

private:

};