

class Rectangle
	: ICustomMemory
{
public:
	Rectangle() 
	{}

	Rectangle(List<std::shared_ptr<Math::Vector3>> points)
		: Rectangle()
	{
	}
	
	Rectangle(std::shared_ptr<Math::Vector3> center, std::shared_ptr<Math::Vector3> scale, std::shared_ptr<Math::Vector3> toAxle, Float angle)
	{
		
		// Z 축 회전
		if (Math::Vector3::Forward == *toAxle)
		{

		}
		// X 축 회전
		else if (Math::Vector3::Right == *toAxle)
		{

		}

	}

private:
	List<std::shared_ptr<Math::Vector3>> mPoints;
};