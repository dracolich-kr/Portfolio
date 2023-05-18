

class Line
	: ICustomMemory
{
public:
	Line(Math::Vector3 start, Math::Vector3 end)
		: mStart(start)
		, mEnd(end)
	{
	}

	const Math::Vector3& GetStart() { return mStart; }
	const Math::Vector3& GetEnd() { return mEnd; }

private:
	Math::Vector3 mStart;
	Math::Vector3 mEnd;
};