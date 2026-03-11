#pragma once

namespace Math
{
	class Vector2
		: public ICustomMemory
	{
	public:
		static Vector2 Zero;
		static Vector2 One;
		static Vector2 Front;
		static Vector2 Back;
		static Vector2 Left;
		static Vector2 Right;

		// 내적
		static Float Dot(Vector2 point1, Vector2 point2)
		{
			return (point1.GetX() * point2.GetX()) + (point1.GetY() * point2.GetY());
		}

		// 크로스
		static Float Cross(Vector2 point1, Vector2 point2)
		{
			return (point1.GetX() * point2.GetY() - point1.GetY() * point2.GetX());
		}

		static Float Distance(Vector2 point1, Vector2 point2)
		{
			return (point1 - point2).Length();
		}

	public:
		Vector2(Float x = 0.0F, Float y = 0.0F)
			: mX(x)
			, mY(y)
		{}

		Vector2(Common::Vector2 vec)
			: mX(vec.x())
			, mY(vec.y())
		{}

		~Vector2() {}

		Common::Vector2 ToVector2();

		const Float& GetX() { return mX; }
		const Float& GetY() { return mY; }

		Vector2 operator-=(Vector2& value)
		{
			return Vector2(this->mX - value.mX, this->mY - value.mY);
		}

		Vector2 operator+=(Vector2& value)
		{
			return Vector2(this->mX + value.mX, this->mY + value.mY);
		}

		Vector2 operator-(Vector2& value)
		{
			return Vector2(this->mX - value.mX, this->mY - value.mY);
		}

		Vector2 operator*(Float value)
		{
			return Vector2(this->mX * value, this->mY * value);
		}

		Vector2 operator/(Float value)
		{
			return Vector2(this->mX / value, this->mY / value);
		}

		bool operator==(Vector2& value)
		{
			return value.mX == this->mX &&
				value.mY == this->mY;
		}

		// 길이
		Float Length()
		{
			return sqrtf((mX * mX) + (mY * mY));
		}

		// 벡터 크기
		Float Magnitude()
		{
			return sqrtf(powf(mX, 2) + powf(mY, 2));
		}

		Vector2 Normalrize()
		{
			Float magnitude = this->Magnitude();
			return Vector2(this->mX / magnitude, this->mY / magnitude);
		}

		void RotateBy(double angle)
		{
			Float cos = (Float)std::cos(angle);
			Float sin = (Float)std::sin(angle);
			Float rx = mX * cos - mY * sin;

			mY = mX * sin + mY * cos;
			mX = rx;
		}

	private:
		Float mX;
		Float mY;
	};

	using SharedVector2 = std::shared_ptr<Vector2>;
}

#include "Vector2.hpp"