// Source : https://leetcode.com/problems/word-search
// Date : 2026-01-17

/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.



Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false


Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.


*/
class Solution {
public:
    using Position = std::pair<int, int>;

    std::vector<Position> visitedPositions;
    std::vector<Position> directionOffsets = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

    bool isInBounds(const Position& pos, const std::vector<std::vector<char>>& board) const
    {
        return !(pos.first < 0 || pos.second < 0 ||
            pos.first >= static_cast<int>(board.size()) || pos.second >= static_cast<int>(board[0].size()));
    }

    bool isVisited(int row, int col) const
    {
        return std::find(visitedPositions.begin(), visitedPositions.end(),
            Position(row, col)) != visitedPositions.end();
    }

    bool dfsSearch(int row, int col, int index, const std::string& word, const std::vector<std::vector<char>>& board)
    {
        if (index == static_cast<int>(word.size()))
            return true;

        if (!isInBounds({ row, col }, board))
            return false;
        if (isVisited(row, col))
            return false;
        if (board[row][col] != word[index])
            return false;

        visitedPositions.push_back({ row, col });

        for (int d = 0; d < static_cast<int>(directionOffsets.size()); ++d)
        {
            int nextRow = row + directionOffsets[d].first;
            int nextCol = col + directionOffsets[d].second;

            if (dfsSearch(nextRow, nextCol, index + 1, word, board))
                return true;
        }

        visitedPositions.pop_back();
        return false;
    }

    bool exist(const std::vector<std::vector<char>>& board, const std::string& word)
    {
        for (int r = 0; r < static_cast<int>(board.size()); ++r)
        {
            for (int c = 0; c < static_cast<int>(board[0].size()); ++c)
            {
                if (board[r][c] == word[0])
                {
                    visitedPositions.clear();
                    if (dfsSearch(r, c, 0, word, board))
                        return true;
                }
            }
        }
        return false;
    }
};