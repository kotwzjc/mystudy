/*
 * @Author: kotwzjc
 * @Github: https://github.com/kotwzjc
 * @Date: 2021-03-26 11:43:34
 * @LastEditors: kotwzjc
 * @LastEditTime: 2021-03-26 21:01:06
 */
/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 *
 * https://leetcode-cn.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (49.78%)
 * Likes:    1076
 * Dislikes: 0
 * Total Accepted:    230.9K
 * Total Submissions: 464K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * 将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
 * 
 * 比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
 * 
 * 请你实现这个将字符串进行指定行数变换的函数：
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "PAYPALISHIRING", numRows = 3
 * 输出："PAHNAPLSIIGYIR"
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "PAYPALISHIRING", numRows = 4
 * 输出："PINALSIGYAHRPI"
 * 解释：
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "A", numRows = 1
 * 输出："A"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 由英文字母（小写和大写）、',' 和 '.' 组成
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        // my solution
        /*
        if(numRows == 1) return s;
        int len = s.size();
        int index = 0;  
        int numColumns = (numRows - 1) * (len / (2 * numRows - 2));
        int tmp = len % (2 * numRows - 2);
        if(tmp > 0)
            if(tmp <= numRows) numColumns += 1;
            else numColumns += tmp - numRows + 1;
                
        vector<vector<char>> cvt(numRows, vector<char>(numColumns, '#'));
        for(int indexCol = 0; indexCol < numColumns; ++indexCol){
            if(indexCol % (numRows - 1) == 0)
                for(int indexRow = 0; indexRow < numRows; ++indexRow)
                {
                    cvt[indexRow][indexCol] = s[index++];
                    if(index == len) break;
                }
            
            else{
                int tempRow = 2 * numRows - index % (2 * numRows - 2) - 2;
                cvt[tempRow][indexCol] = s[index++];
            }
        }

        string ans;
        for(int indexRow = 0; indexRow < numRows; ++indexRow)
            for(int indexCol = 0; indexCol < numColumns; ++indexCol)
                if(cvt[indexRow][indexCol] != '#') ans += cvt[indexRow][indexCol];
        return ans;*/

        // 按行排序
        /*
        if(numRows == 1) return s;
        vector<string> rows(min(numRows, int(s.size())));
        int rowIndex = 0;
        int direction = 0;

        for(int i = 0; i < s.size(); ++i){
            if(direction == 0) rows[rowIndex++] += s[i];
            if(direction == 1) rows[rowIndex--] += s[i];

            if(rowIndex == numRows - 1 && direction == 0) direction = 1;
            else if(rowIndex == 0 && direction == 1) direction = 0;
        }

        string ans;
        for(int i = 0; i < rows.size(); ++i) ans += rows[i];
        return ans;*/

        // 按行访问
        if(numRows == 1) return s;

        string ans;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;

        for(int i = 0; i < numRows; ++i){
            for(int j = 0; j + i < n; j += cycleLen){
                ans += s[j + i];
                if(i != 0 && i != numRows - 1 && j + cycleLen - i < n) 
                    ans += s[j + cycleLen - i];
            }
        }

        return ans;
    }
};
// @lc code=end

