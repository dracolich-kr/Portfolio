#pragma once

namespace Math
{
	class Vector3
		: public ICustomMemory
	{
	public:
		static Vector3 Zero;
		static Vector3 One;
		static Vector3 Forward;
		static Vector3 Back;
		static Vector3 Up;
		static Vector3 Down;
		static Vector3 Left;
		static Vector3 Right;

		// 내적
		static Float Dot(Vector3 point1, Vector3 point2)
		{
			return (point1.GetX() * point2.GetX()) + (point1.GetY() * point2.GetY()) + (point1.GetZ() * point2.GetZ());
		}

		// 크로스
		static Vector3 Cross(Vector3 point1, Vector3 point2)
		{
			return Vector3((point1.GetY() * point2.GetZ()) - (point1.GetZ() * point2.GetY()), 
						   (point1.GetZ() * point2.GetX()) - (point1.GetX() * point2.GetZ()), 
						   (point1.GetX() * point2.GetY()) - (point1.GetY() * point2.GetX()));
		}

		static Float Distance(Vector3 point1, Vector3 point2)
		{
			return (point1 - point2).Length();
		}

	public:
		Vector3(Float x = 0.0F, Float y = 0.0F, Float z = 0.0F)
			: mX(x)
			, mY(y)
			, mZ(z)
		{}

		Vector3(Common::Vector3 vec)
			: mX(vec.x())
			, mY(vec.y())
			, mZ(vec.z())
		{}

		~Vector3() {}

		Common::Vector3 ToVector3();

		const Float& GetX() { return mX; }
		const Float& GetY() { return mY; }
		const Float& GetZ() { return mZ; }

		Vector3 operator-=(Vector3& value)
		{
			return Vector3(this->mX - value.mX, this->mY - value.mY, this->mZ - value.mZ);
		}

		Vector3 operator+=(Vector3& value)
		{
			return Vector3(this->mX + value.mX, this->mY + value.mY, this->mZ + value.mZ);
		}

		Vector3 operator-(Vector3& value)
		{
			return Vector3(this->mX - value.mX, this->mY - value.mY, this->mZ - value.mZ);
		}

		Vector3 operator*(Float value)
		{
			return Vector3(this->mX * value, this->mY * value, this->mZ * value);
		}

		Vector3 operator/(Float value)
		{
			return Vector3(this->mX / value, this->mY / value, this->mZ / value);
		}

		bool operator==(Vector3& value)
		{
			return value.mX == this->mX &&
				   value.mY == this->mY &&
				   value.mZ == this->mZ;
		}

		// 길이
		Float Length()
		{
			return sqrtf((mX * mX) + (mY * mY) + (mZ * mZ));
		}

		// 벡터 크기
		Float Magnitude()
		{
			return sqrtf(powf(mX, 2) + powf(mY, 2) + powf(mZ, 2));
		}

		Vector3 Normalrize()
		{
			Float magnitude = this->Magnitude();
			return Vector3(this->mX / magnitude, this->mY / magnitude, this->mZ / magnitude);
		}

	private:
		Float mX;
		Float mY;
		Float mZ;
	};

	using SharedVector3 = std::shared_ptr<Vector3>;
}

#include "Vector3.hpp"

