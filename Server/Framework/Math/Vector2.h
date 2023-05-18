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

	private:
		Float mX;
		Float mY;
	};

	using SharedVector2 = std::shared_ptr<Vector2>;
}

#include "Vector2.hpp"