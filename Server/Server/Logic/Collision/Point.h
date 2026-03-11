#pragma once

class Point
	: public ICustomMemory
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

	Math::Vector3& GetPos() { return mPoint; }

private:
	Math::Vector3 mPoint;
};