#pragma once 

using GridIndex = Int32;

class Grid
{
public:
	Grid() {}
	~Grid() {}

	void BroadCast();

private:
	GridIndex mGridIndex = 0;
	List<std::shared_ptr<Cell>> mCells;
	List<std::shared_ptr<Grid>> mNearGrids;

};