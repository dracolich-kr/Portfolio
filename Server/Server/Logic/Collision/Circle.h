#pragma once

class Circle
	: public ICustomMemory
{
public:
	Circle() 
		: mPoint(Math::Vector3::Zero)
		, mRadian(0.0F)
	{}

	Circle(Math::Vector3 point, Float radian)
		: mPoint(point)
		, mRadian(radian)
	{}

	virtual ~Circle() {}

	Math::Vector3 GetPoint() { return mPoint; }
	const Float& GetRadian() { return mRadian; }

private:
	Math::Vector3 mPoint;
	Float mRadian;
};