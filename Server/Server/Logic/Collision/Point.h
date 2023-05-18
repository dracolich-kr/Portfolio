

class Point
	: ICustomMemory
{
public:
	Point(Float x, Float y, Float z)
		: mPoint(x,y,z)
	{
	}

	Point(Math::Vector3 vec)
		: mPoint(vec)
	{
	}

	virtual ~Point() {}

private:
	Math::Vector3 mPoint;
};