
class Circle
	: ICustomMemory
{
public:
	Circle() 
		: mPoint(Math::Vector3::Zero)
		, mRadian(0.0F)
	{}
	virtual ~Circle() {}

private:
	Math::Vector3 mPoint;
	Float mRadian;
};