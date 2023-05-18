#pragma once

namespace Math
{
	Common::Vector3 Vector3::ToVector3()
	{
		return Common::Vector3(mX, mY, mZ);
	}

	Vector3 Vector3::Zero = Vector3(0.0F, 0.0F, 0.0F);
	Vector3 Vector3::One = Vector3(1.0F, 1.0F, 1.0F);
	Vector3 Vector3::Forward = Vector3(0.0F, 0.0F, 1.0F);
	Vector3 Vector3::Back = Vector3(0.0F, 0.0F, -1.0F);
	Vector3 Vector3::Up = Vector3(0.0F, 1.0F, 0.0F);
	Vector3 Vector3::Down = Vector3(0.0F, -1.0F, 0.0F);
	Vector3 Vector3::Left = Vector3(-1.0F, 0.0F, 0.0F);
	Vector3 Vector3::Right = Vector3(1.0F, 0.0F, 0.0F);
}