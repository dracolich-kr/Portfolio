#pragma once 

namespace DataBase
{
	class Result
	{
	public:
		Result()
		{
		}

		virtual ~Result() 
		{
		}

		virtual ErrorResult onResult() PURE;

	private:

	};
}