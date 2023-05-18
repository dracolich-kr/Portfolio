#pragma once

class GridManager
{
public:
	GridManager() {}
	virtual ~GridManager() {}

private:
	Map<GridIndex, Grid> mGrids;
};