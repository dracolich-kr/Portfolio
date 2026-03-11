#pragma once

class Position
{
public:
	Position() 
		: mLookAt(0)
		, mPosition()
	{}

	virtual ~Position() {}

	void SetLookAt(Float angle) { mLookAt = angle; }
	const Float GetLookAt() { return mLookAt; }

	void SetPosition(Common::Vector3 pos) { mPosition = pos; }
	const Common::Vector3 GetPosition() { return mPosition; }

private:
	Common::Vector3 mPosition;
	Float mLookAt;
};