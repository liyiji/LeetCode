/*
 * Text Justification
 * Total Accepted: 4979 Total Submissions: 36065
 *
 * Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
 *
 * You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.
 *
 * Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
 *
 * For the last line of text, it should be left justified and no extra space is inserted between words.
 *
 * For example,
 * words: ["This", "is", "an", "example", "of", "text", "justification."]
 * L: 16.
 *
 * Return the formatted lines as:
 *
 * [
 *    "This    is    an",
 *    "example  of text",
 *    "justification.  "
 * ]
 *
 * Note: Each word is guaranteed not to exceed L in length.
 *
 * click to show corner cases.
 * Corner Cases:
 *
 *     A line other than the last line might contain only one word. What should you do in this case?
 *     In this case, that line should be left-justified.
 */
class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int L)
    {
        vector<string > result;

        int start = 0;
        int end = -1;
        int subLength = 0;
        while (true)
        {
            start = end + 1;
            end = -1;
            subLength = 0;
            if (start >= words.size())
                break;

            for (int i = start; i < words.size(); i++)
            {
                if (subLength <= L + 1)
                {
                    end = i;
                    subLength = subLength + words[i].size() + 1;
                    if (subLength > L + 1 && (end - start > 0))
                    {
                        end--;
                        subLength = subLength - words[i].size() - 1;
                        break;
                    }
                }
            }

            subLength--;
            if (subLength <= 0)
            {
                if (words.size() != 0 && result.size() == 0)
                {
                    result.push_back(string(L, ' '));
                }
                break;
            }

            if (end == words.size() - 1)
            {
                string sub;
                for (int i = start; i <= end; i++)
                {
                    sub.append(words[i]);
                    if (i < end)
                    {
                        sub.append(" ");
                    }
                }
                while (sub.size() < L)
                {
                    sub.push_back(' ');
                }
                result.push_back(sub);
            }
            else
            {
                int nGapCount = end - start;
                int excessSpace = L - subLength;
                if (nGapCount == 0)
                {
                    string sub = words[start];
                    while (sub.size() < L)
                    {
                        sub.push_back(' ');
                    }
                    result.push_back(sub);
                }
                else
                {
                    string sub;
                    int addForEach = excessSpace / nGapCount;
                    int remainSpace = excessSpace - (addForEach * nGapCount);

                    sub.append(words[start]);
                    for (int i = 0; i < remainSpace; i++)
                    {
                        sub.append(string(addForEach + 2, ' '));
                        sub.append(words[start + i + 1]);
                    }
                    for (int i = 0; i < nGapCount - remainSpace; i++)
                    {
                        sub.append(string(addForEach + 1, ' '));
                        sub.append(words[start + remainSpace + i + 1]);
                    }
                    result.push_back(sub);
                }
            }
        }

        return result;
    }
};
