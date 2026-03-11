#pragma once

class Collision
{
public:
	static bool isCircleRectangle(Circle* circle, Rect* rect)
	{
		IF_RETURN(nullptr == circle, false);
		IF_RETURN(nullptr == rect, false);

        Int32 next = 0;
        for (int current = 0; current < rect->GetBuffer().size(); current++) 
        {
            next = current + 1;
            if (next == rect->GetBuffer().size()) 
                next = 0;

            Math::Vector3 vc = rect->GetBuffer()[current];    // c for "current"
            Math::Vector3 vn = rect->GetBuffer()[next];       // n for "next"

            bool collision = isLineCircle(&vc, &vn, circle);
            IF_RETURN(true == collision, true);

        }

		return false;
	}

    static bool isLineCircle(Math::Vector3* start, Math::Vector3* end, Circle* circle)
    {
        bool inside1 = isPointCircle(start, circle);
        bool inside2 = isPointCircle(end, circle);
        IF_RETURN(inside1 || inside2, true);

        // get length of the line
        float len = Math::ExCommon::Dist(start->GetX(), start->GetZ(), end->GetX(), end->GetZ());

        // get dot product of the line and circle
        auto point = circle->GetPoint();

        float dot = (((point.GetX() - start->GetX()) * (end->GetX() - start->GetX())) + ((point.GetZ() - start->GetZ()) * (end->GetZ() - start->GetZ()))) / (float)pow(len, 2);

        // find the closest point on the line
        float closestX = start->GetX() + (dot * (end->GetX() - start->GetX()));
        float closestY = start->GetZ() + (dot * (end->GetZ() - start->GetZ()));

        // is this point actually on the line segment?
        // if so keep going, but if not, return false
        bool onSegment = isLinePoint(start, end, closestX, closestY);
        IF_RETURN(false == onSegment, false);

        // get distance to closest point
        float distance = Math::ExCommon::Dist(start->GetX(), start->GetZ(), end->GetX(), end->GetZ());

        // is the circle on the line?
        IF_RETURN(distance <= circle->GetRadian(), true);

        return false;
    }

    static bool isLinePoint(Math::Vector3* start, Math::Vector3* end, float px, float py)
    {
        // get distance from the point to the two ends of the line
        float d1 = Math::ExCommon::Dist(px, py, start->GetX(), start->GetZ());
        float d2 = Math::ExCommon::Dist(px, py, end->GetX(), end->GetZ());

        // get the length of the lines
        float lineLen = Math::ExCommon::Dist(start->GetX(), start->GetZ(), end->GetX(), end->GetZ());

        float buffer = 0.1f;    // higher # = less accurate

        IF_RETURN(d1 + d2 >= lineLen - buffer && d1 + d2 <= lineLen + buffer, true);

        return false;
    }

    // POINT/CIRCLE
    static boolean isPointCircle(Math::Vector3* point, Circle* circle) 
    {
        float distX = point->GetX() - circle->GetPoint().GetX();
        float distZ = point->GetZ() - circle->GetPoint().GetZ();
        float distance = Math::ExCommon::Dist(point->GetX(), point->GetZ(), circle->GetPoint().GetX(), circle->GetPoint().GetZ());

        IF_RETURN(distance <= circle->GetRadian(), true);

        return false;
    }
};