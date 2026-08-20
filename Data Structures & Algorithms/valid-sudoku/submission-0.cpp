class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // hash sets ke arrays banao taaki seen nos ko track kar sake
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for(int r = 0; r<9; r++){
            for(int c = 0; c<9; c++){
                if(board[r][c] == '.'){
                    continue; // empty cells ko skip  karo
                }

                char val = board[r][c];

                // calc the 3x3 box index
                int box_index = (r / 3) * 3 + (c / 3);

                // agar num already row, col mei hai , then it is invalid
                if(rows[r].count(val) || cols[c].count(val) || boxes[box_index].count(val)){
                    return false;
                }

                // har ek set ko proper number do 
                rows[r].insert(val);
                cols[c].insert(val);
                boxes[box_index].insert(val);
            }
        }

        return true;
    }
};
