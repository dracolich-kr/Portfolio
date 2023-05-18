#pragma once 

using CellIndex = Int32;
using CellSize = Int32;

class Grid;

enum class NearType
{
	TopLeft = 0
	, Top = 1
	, TopRight = 2
	, Left = 3
	, Right = 4
	, BottomLeft = 5
	, Bottom = 6
	, BottomRight = 7
};

class Cell
{
public:
	Cell() 
		: mIndex(0)
	{}

	virtual ~Cell() {}

	void BroadCast(Packet message);

private:
	CellIndex mIndex;

	Math::Vector3 mPosition;

	List<std::shared_ptr<Cell>> mNearCells;
	List<std::shared_ptr<Entity>> mEntitys;

	std::shared_ptr<Grid> mParentGrid;
};