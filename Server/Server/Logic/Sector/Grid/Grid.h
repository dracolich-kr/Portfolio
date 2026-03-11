#pragma once 


class Grid
{
public:
	Grid() {}
	~Grid() {}

	ErrorResult Initaize();
	ErrorResult Release();

	ErrorResult BroadCast(Network::SharedPacket message);

	ErrorResult AddCell(CellIndex index) { mCells.push_back(index); }

private:
	GridIndex mGridIndex = 0;

	List<CellIndex> mCells;
	List<GridIndex> mNearGrids;

};