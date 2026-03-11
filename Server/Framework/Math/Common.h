
namespace Math
{
	constexpr double PI = 3.14159265358979;

	class ExCommon
	{
	public:
		// 180 -> 0.304042
		static Bool toRadian(Float degree, /*OUT*/ Float& radian)
		{
			radian = degree * (Float)PI / 180;
			return true;
		}

		// 0.30402 -> 180
		static Bool toDegree(Float radian, /*OUT*/ Float& degree)
		{
			degree = radian * 180 / (Float)PI;
			return true;
		}


		static Float Dist(Float x1, Float y1, Float x2, Float y2)
		{
			float distX = x1 - x2;
			float distY = y1 - y2;

			return sqrt((distX * distX) + (distY * distY));
		}
	};
};