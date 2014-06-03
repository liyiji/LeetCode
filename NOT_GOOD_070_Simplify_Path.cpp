/*
 * Simplify Path
 * Total Accepted: 7043 Total Submissions: 35983
 *
 * Given an absolute path for a file (Unix-style), simplify it.
 *
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 *
 * click to show corner cases.
 * Corner Cases:
 *
 *     Did you consider the case where path = "/../"?
 *     In this case, you should return "/".
 *     Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
 *     In this case, you should ignore redundant slashes and return "/home/foo".
 */
class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string > vs;
        istringstream f(path);
        string s;
        while (getline(f, s, '/'))
        {
            vs.push_back(s);
        }

        size_t cur = 0;
        while (cur < vs.size())
        {
            if (vs[cur].size() == 0 || vs[cur] == ".")
            {
                vs.erase(vs.begin() + cur);
                continue;
            }
            else if (vs[cur] == "..")
            {
                if (cur == 0)
                {
                    vs.erase(vs.begin() + cur);
                }
                else
                {
                    vs.erase(vs.begin() + cur - 1, vs.begin() + cur + 1);
                    cur--;
                }
                continue;
            }
            else
            {
                cur++;
            }
        }

        string result;
        for (int i = 0; i < vs.size(); i++)
        {
            result.append("/");
            result.append(vs[i]);
        }
        if (result.size() == 0)
        {
            result.push_back('/');
        }

        return result;
    }
};
