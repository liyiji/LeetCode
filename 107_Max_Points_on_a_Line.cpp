/*
 * Max Points on a Line
 * Total Accepted: 11390 Total Submissions: 108168
 *
 * Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 */
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution
{
public:
// Tips: In LeetCode OJ system, point1 and point2 could actually be the same point
    int maxPoints(vector<Point> &points)
    {
        if (points.size() <= 2)
            return points.size();

        int result = 2;
        int tmpResult = 2;
        for (size_t i1 = 0; i1 + result < points.size(); i1++)
        {
            Point p1 = points[i1];
            for (size_t i2 = i1 + 1; i2 + result - 1 < points.size(); i2++)
            {
                Point p2 = points[i2];
                if (samePoint(p1, p2))
                {
                    if (i2 + result < points.size())
                        continue;
                }

                tmpResult = 2;
                for (size_t itmp = i1 + 1; itmp < i2; itmp++)
                {
                    if (samePoint(p1, points[itmp]))
                        tmpResult++;
                }
                for (size_t i3 = i2 + 1; i3 < points.size(); i3++)
                {
                    Point p3 = points[i3];
                    if (sameLine(p1, p2, p3))
                    {
                        tmpResult++;
                    }
                }
                result = max(result, tmpResult);
            }
        }

        return result;
    }

    bool sameLine(const Point &p1, const Point &p2, const Point &p3)
    {
        if (samePoint(p1, p2) || samePoint(p1, p3) || samePoint(p2, p3))
            return true;

        if ((p2.y - p1.y) * (p3.x - p1.x) == (p3.y - p1.y) * (p2.x - p1.x))
        {
            if (p1.x == p2.x && p1.x == p3.x)
            {
                return true;
            }

            if (p1.y == p2.y && p1.y == p3.y)
            {
                return true;
            }

            if (p1.x == p2.x || p1.x == p3.x || p2.x == p3.x || p1.y == p2.y || p1.y == p3.y || p2.y == p3.y)
                return false;

            return true;
        }
        else
        {
            return false;
        }
    }

    bool samePoint(const Point &p1, const Point &p2)
    {
        if (p1.x == p2.x && p1.y == p2.y)
            return true;
        return false;
    }
};
