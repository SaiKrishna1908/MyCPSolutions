#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to generate all combinations of 8 positions out of 64
void generateCombinations(vector<int>& board, int start, int k, vector<int>& current, vector<vector<int>>& results) {
    if (current.size() == k) {
        results.push_back(current);
        return;
    }
    for (int i = start; i < board.size(); i++) {
        current.push_back(board[i]);
        generateCombinations(board, i + 1, k, current, results);
        current.pop_back();
    }
}

// Function to display a chessboard configuration
void displayBoard(const vector<int>& config) {
    vector<char> board(64, '.');
    for (int pos : config) {
        board[pos] = 'Q';
    }
    for (int i = 0; i < 64; i++) {
        cout << board[i] << " ";
        if ((i + 1) % 8 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

int main() {
    // Initialize board indices
    vector<int> board(64);
    for (int i = 0; i < 64; i++) {
        board[i] = i;
    }
    
    // Store results
    vector<vector<int>> results;
    vector<int> current;
    
    // Generate all combinations
    generateCombinations(board, 0, 8, current, results);
    
    // Display the first 5 configurations for demonstration
    int count = 0;
    for (const auto& config : results) {
        cout << "Configuration " << ++count << ":\n";
        displayBoard(config);
        if (count >= 5) break; // Show only the first 5 configurations
    }
    
    return 0;
}
