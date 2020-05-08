## 寻找最长不重复子串
### 一、题目描述
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。（难度 中等）
```
示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

```

### 二、分析
举例分析
```
str = 'abcdefgabc'

题目要寻找最长的不重复的子串，可以理解为对str截取一段片段，

这个片段长度L >0 & L < len(str)，片段内部所有元素是不相等的。

对于这个片段可以理解为一个滑动窗口，i指向窗口开头，j指向窗口结尾

   abcdefgabc
   |     |
   i     j

j一直往后移，保存i，j区间没有重复字符，如果遇到重复字符，则记录此时区间长度
i向后移动一位，直到i到达字符串末尾。


开始 i=0，j=0，max_len = 0
1. i如果小于字符串长度，则后移一个字符。否则退出
2. j指向后一个字符，判断该字符是否在 unordered_set中。
3. 如果不在，则加入 unordered_set，并且转到2
4. 如果在，则调到1，并且记录当前j-i长度,与max_len比较，最大值写到max_len
循环结束则max_len 就是所求最长不重复子串长度

```


### 三、源代码

```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 哈希集合，记录每个字符是否出现过
        unordered_set<char> occ;
        int n = s.size();
        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rk = -1, ans = 0;
        // 枚举左指针的位置，初始值隐性地表示为 -1
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                // 不断地移动右指针 a b c d e f a
                //            |    |
                //            i   rk
                // 通过将 a、b、c、d、e、f 一个一个放入unordered_set 中，并且查看是否有重复，
                // 直到 最后一个 a放入后重复。
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复字符子串
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
```
