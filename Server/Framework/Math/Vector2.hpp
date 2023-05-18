#pragma once

namespace Math
{
	Common::Vector2 Vector2::ToVector2()
	{
		return Common::Vector2(mX, mY);
	}

	Vector2 Vector2::Zero = Vector2(0.0F, 0.0F);
	Vector2 Vector2::One = Vector2(1.0F, 1.0F);
	Vector2 Vector2::Front = Vector2(1.0F, 0.0F);
	Vector2 Vector2::Back = Vector2(-1.0F, 0.0F);
	Vector2 Vector2::Right = Vector2(0.0F, 1.0F);
	Vector2 Vector2::Left = Vector2(0.0F, -1.0F);
	

}