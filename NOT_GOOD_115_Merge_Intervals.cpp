/*
 * Merge Intervals
 * Total Accepted: 10408 Total Submissions: 51449
 *
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool earlier(Interval a, Interval b)
{
    if (a.start < b.start)
        return true;
    else if (a.start > b.start)
        return false;
    else // (a.start == b.start)
    {
        if (a.end < b.end)
            return true;
        else if (a.end > b.end)
            return false;
        else
            // (a.end == b.end)
            return true;
    }
}

class Solution
{
public:
    vector<Interval> merge(vector<Interval> &intervals)
    {
        while (true)
        {
            bool lastLoop = false;
            if (intervals.size() > 1000)
                sort(intervals.end() - 1000, intervals.end(), earlier);
            else
            {
                sort(intervals.begin(), intervals.end(), earlier);
                lastLoop = true;
            }

            int it = 0;
            if (intervals.size() > 1000)
                it = intervals.size() - 1000;
            while (it + 1 < intervals.size())
            {
                if (intervals[it].end >= intervals[it + 1].start)
                {
                    if (intervals[it].end < intervals[it + 1].end)
                        intervals[it].end = intervals[it + 1].end;
                    intervals.erase(intervals.begin() + it + 1);
                }
                else
                {
                    it++;
                }
            }
            if (lastLoop)
                break;
        }
        return intervals;
    }
};
