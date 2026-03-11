#pragma once

class Rect
	: public ICustomMemory
{
public:
	Rect()
	{}

	Rect(List<Math::Vector3> points)
		: Rect()
	{
	}
	
	Rect(Math::Vector3 center, Math::Vector3 scale, Math::Vector3 toAxle, Float angle)
	{
		// Z 축 회전
		if (Math::Vector3::Forward == toAxle)
		{

		}
		// X 축 회전
		else if (Math::Vector3::Right == toAxle)
		{

		}

	}

	Vector<Math::Vector3>& GetBuffer() { return mPoints; }

private:
	Vector<Math::Vector3> mPoints;
};