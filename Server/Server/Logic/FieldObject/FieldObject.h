
enum class LifeCycleType
{
	None
	, Infinity
	, 
};

class FieldObject
	: public IUpdate
{
public:
	FieldObject() 
		: mId(0)
		, mExpairTime()
		, mPosition()
	{}
	virtual ~FieldObject() {}

	ErrorResult Initalize();
	ErrorResult Update(DeltaTime delta_time) override;

	bool IsExpired();

	const FieldObjectId& GetId() { return mId; }
	const Position& GetPosition() { return mPosition; }

private:
	FieldObjectId mId;
	TickTimer mExpairTime;
	Position mPosition;
};