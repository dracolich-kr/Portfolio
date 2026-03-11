#pragma once

using CellIndex = Int32;

class CellManager
{
public:
	CellManager(CellSize x = 0, CellSize y = 0)
		: mSizeX(x)
		, mSizeY(y)
	{}

	virtual ~CellManager() {}

	ErrorResult Initalize();
	ErrorResult Release();

	Int32 GenerateIndex() { return mIndex++; }

	CellIndex Find(Math::Vector3 pos);


private:
	CellSize mSizeX;
	CellSize mSizeY;

	CellIndex mIndex = 0;

	Map<CellIndex, SharedCell> mCells;
};