/*
 * Insert Interval
 * Total Accepted: 9290 Total Submissions: 46382
 *
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their start times.
 *
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 *
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 *
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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
class Solution
{
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
    {
        vector < Interval > result;
        if (intervals.size() == 0)
        {
            result.push_back(newInterval);
            return result;
        }

        int it = 0;
        while (true)
        {
            if (it >= intervals.size() || newInterval.start >= newInterval.end)
                break;

            if (newInterval.end < intervals[it].start)
            {
                result.push_back(newInterval);
                break;
            }
            else if (newInterval.end == intervals[it].start)
            {
                intervals[it].start = newInterval.start;
                break;
            }
            else // (newInterval.end > intervals[it].start)
            {
                if (newInterval.end <= intervals[it].end)
                {
                    intervals[it].start = min(intervals[it].start, newInterval.start);
                    break;
                }
                else // (newInterval.end > intervals[it].end)
                {
                    if (newInterval.start < intervals[it].end)
                    {
                        intervals[it].start = min(intervals[it].start, newInterval.start);
                        break;
                    }
                    else // (newInterval.start >= intervals[it].end)
                    {
                        result.push_back(intervals[it]);
                        continue;
                    }
                }
            }
        }

        for (int i = it; i < intervals.size(); i++)
        {
            result.push_back(intervals[i]);
        }

        for (int i = 1; i < result.size();)
        {
            if (result[i - 1].end == result[i].start)
            {
                result[i - 1].end = result[i].end;
                result.erase(result.begin() + i - 1);
            }
            else
            {
                i++;
            }
        }

        return result;
    }
};
