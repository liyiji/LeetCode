/*
 * Implement strStr()
 * Total Accepted: 13021 Total Submissions: 60827
 *
 * Implement strStr().
 *
 * Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
 */
class Solution
{
public:
    char *strStr(char *haystack, char *needle)
    {
        size_t stringSize = strlen(haystack);
        size_t patternSize = strlen(needle);
        if (stringSize < patternSize)
            return NULL;
        if (patternSize == 0)
            return haystack;

        if (stringSize == patternSize)
        {
            for (size_t i = 0; i < patternSize; i++)
            {
                if (haystack[i] != needle[i])
                    return NULL;
            }
            return haystack;
        }

        vector<int> specialVector(patternSize, 0);

        for (size_t i = 1; i < patternSize; i++)
        {
            for (size_t subLength = i; subLength > 0; subLength--)
            {
                bool b = true;
                for (size_t j = 0; j < subLength; j++)
                {
                    if (needle[j] != needle[i + 1 - subLength + j])
                    {
                        b = false;
                        break;
                    }
                }
                if (b)
                {
                    specialVector[i] = subLength;
                    break;
                }
            }
        }

        for (size_t i = 0; i <= stringSize - patternSize;)
        {
            size_t j = 0;
            bool b = true;
            for (; j < patternSize; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    b = false;
                    break;
                }
            }
            if (b || j == patternSize)
            {
                return haystack + i;
            }
            i += ((j == 0) ? 1 : (j - (specialVector.size() ? specialVector[j - 1] : 0)));
        }

        return NULL;
    }
};
