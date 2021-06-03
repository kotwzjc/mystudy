/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 *
 * https://leetcode-cn.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (66.96%)
 * Likes:    843
 * Dislikes: 0
 * Total Accepted:    82.5K
 * Total Submissions: 123.1K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * 编写一个程序，通过填充空格来解决数独问题。
 * 
 * 数独的解法需 遵循如下规则：
 * 
 * 
 * 数字 1-9 在每一行只能出现一次。
 * 数字 1-9 在每一列只能出现一次。
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
 * 
 * 
 * 数独部分空格内已填入了数字，空白格用 '.' 表示。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：board =
 * [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
 * 
 * 输出：[["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
 * 解释：输入的数独如上图所示，唯一有效的解决方案如下所示：
 * 
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * board.length == 9
 * board[i].length == 9
 * board[i][j] 是一位数字或者 '.'
 * 题目数据 保证 输入数独仅有一个解
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
private:
    int wows[9];
    bool valid;
    vector<pair<int, int>> spaces;

public:
    void dfs(vector<vector<char>>& board, int pos) {
        if (pos == spaces.size()) {
            valid = true;
            return;
        }

        auto [i, j] = spaces[pos];
        for (int digit = 0; digit < 9 && !valid; ++digit) {
            int box_index = (i / 3) * 3 + j / 3;
            int line = 0x1 << digit;
            int column = 0x1 << 9 << digit;
            int box = 0x1 << 9 << 9 << digit;
            
            if ((wows[i] & line) == 0 && (wows[j] & column) == 0 && (wows[box_index] & box) == 0) {
                wows[i] |= line;
                wows[j] |= column;
                wows[box_index] |= box;
                board[i][j] = digit + '1';

                dfs(board, pos + 1);

                wows[i] ^= line;
                wows[j] ^= column;
                wows[box_index] ^= box;
            }
        }
    }
    // my solution
    /*
    bool dfs(vector<vector<char>>& board, vector<pair<int, int>> spaces, int idx, vector<vector<int>>& rows, vector<vector<int>>& columns, vector<vector<int>>& boxes) {
        if (idx == spaces.size()) return true;
        auto [i, j] = spaces[idx];

        for (int k = 0; k < 9; ++k) {
            int box_index = (i / 3) * 3 + j / 3;
            if (rows[i][k] == 1 || columns[j][k] == 1 || boxes[box_index][k] == 1) continue;

            rows[i][k]++;
            columns[j][k]++;
            boxes[box_index][k]++;
            board[i][j] = k + '1';
            if (dfs(board, spaces, idx + 1, rows, columns, boxes)) return true;
            rows[i][k]--;
            columns[j][k]--;
            boxes[box_index][k]--;
        }

        return false;
    }*/

    void solveSudoku(vector<vector<char>>& board) {
        // my solution
        /*
        vector<vector<int>> rows(9, vector<int>(9, 0));
        vector<vector<int>> columns(9, vector<int>(9, 0));
        vector<vector<int>> boxes(9, vector<int>(9, 0));
        vector<pair<int, int>> spaces;


        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') spaces.emplace_back(i, j);
                else {
                    int tmp = board[i][j] - '1';
                    int box_index = (i / 3) * 3 + j / 3;

                    rows[i][tmp]++;
                    columns[j][tmp]++;
                    boxes[box_index][tmp]++;
                }
            }
        }

        dfs(board, spaces, 0, rows, columns, boxes);*/

        // 位运算优化
        /*
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') spaces.emplace_back(i, j);
                else {
                    int digit = board[i][j] - '1';
                    int box_index = (i / 3) * 3 + j / 3;
                    int line = 0x1 << digit;
                    int column = 0x1 << 9 << digit;
                    int box = 0x1 << 9 << 9 << digit;

                    wows[i] |= line;
                    wows[j] |= column;
                    wows[box_index] |= box;
                }
            }
        }

        dfs(board, 0);*/

        // 枚举优化
        valid = false;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int digit = board[i][j] - '1';
                    int box_index = (i / 3) * 3 + j / 3;
                    int line = 0x1 << digit;
                    int column = 0x1 << 9 << digit;
                    int box = 0x1 << 9 << 9 << digit;

                    wows[i] |= line;
                    wows[j] |= column;
                    wows[box_index] |= box;
                }
            }
        }

        while (true) {
            bool modified = false;
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    if (board[i][j] == '.') {
                        int box_index = (i / 3) * 3 + j / 3;
                        int line = wows[i] & 0x1FF;
                        int column = (wows[j] >> 9) & 0x1FF;
                        int box = (wows[box_index] >> 18) & 0x1FF;
                        int mask = (line | column | box) ^ 0x1FF;

                        if ((mask & (mask - 1)) == 0) {
                            int digit = __builtin_ctz(mask);
                            line = 0x1 << digit;
                            column = 0x1 << 9 << digit;
                            box = 0x1 << 9 << 9 << digit;
                            wows[i] |= line;
                            wows[j] |= column;
                            wows[box_index] |= box;
                            board[i][j] = digit + '1';
                            modified = true;
                        }
                    }
                }
            }
            if (!modified) break;
        }

        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board[i][j] == '.') spaces.emplace_back(i, j);
        
        dfs(board, 0);
    }
};
// @lc code=end

