
class FieldObjectKeyGenerator
	: public KeyGenerator<FieldObjectId>
{
public:
	FieldObjectKeyGenerator()
	{}

	virtual ~FieldObjectKeyGenerator() {}

	FieldObjectId Generate() override;

private:

};