class Solution {
public:
    bool winnerOfGame(string colors) {
         int aliceMoves = 0, bobMoves = 0;
    
    for (int i = 1; i < colors.size() - 1; ++i) {
        if (colors[i-1] == colors[i] && colors[i] == colors[i+1]) {
            if (colors[i] == 'A') ++aliceMoves;
            else if (colors[i] == 'B') ++bobMoves;
        }
    }

    return aliceMoves > bobMoves;

    }
};