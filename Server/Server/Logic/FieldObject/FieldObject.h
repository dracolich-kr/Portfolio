

class FieldObject
	: public IUpdate
{
public:
	FieldObject() {}
	virtual ~FieldObject() {}

	ErrorResult Update(DeltaTime delta) override;

private:

	FieldObjectId mId;

};