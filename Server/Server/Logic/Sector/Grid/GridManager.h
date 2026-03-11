#pragma once

class GridManager
{
public:
	GridManager() {}
	virtual ~GridManager() {}

	ErrorResult Initalize();

private:
	Map<GridIndex, SharedGrid> mGrids;
};