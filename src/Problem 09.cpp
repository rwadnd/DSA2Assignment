#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Structure to represent a Trie node
struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode() {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
        isEndOfWord = false;
    }
};

// Function to insert a word into the Trie
void insertWord(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (char ch : word) {
        int index = ch - 'A';
        if (!node->children[index])
            node->children[index] = new TrieNode();
        node = node->children[index];
    }
    node->isEndOfWord = true;
}

// Function to perform DFS on the board to find words from the dictionary
void findWords(vector<vector<char>>& board, int i, int j, TrieNode* root, string& path, unordered_set<string>& words, vector<vector<bool>>& visited) {
    // Base case: If the current cell is out of bounds or already visited
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j])
        return;

    char ch = board[i][j];
    int index = ch - 'A';
    if (!root->children[index])
        return; // If there's no word with this prefix in the dictionary

    // Update the current path
    path += ch;
    visited[i][j] = true;

    if (root->children[index]->isEndOfWord)
        words.insert(path); // Add the word to the set of words found

    // Explore all 8 directions
    static int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    for (int k = 0; k < 8; k++)
        findWords(board, i + dx[k], j + dy[k], root->children[index], path, words, visited);

    // Backtrack: Remove the current character and mark the cell as unvisited
    path.pop_back();
    visited[i][j] = false;
}

vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
    vector<string> result;
    unordered_set<string> words;

    // Build the Trie from the dictionary
    TrieNode* root = new TrieNode();
    for (const string& word : dictionary)
        insertWord(root, word);

    int R = board.size(), C = board[0].size();
    vector<vector<bool>> visited(R, vector<bool>(C, false));

    // Perform DFS for each cell on the board
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            string path = "";
            findWords(board, i, j, root, path, words, visited);
        }
    }

    // Convert the set of words to a vector and return
    for (const string& word : words)
        result.push_back(word);

    return result;
}

int main() {
    // Example usage
    vector<vector<char>> board1 = { {'C', 'A', 'P'},
                                    {'A', 'N', 'D'},
                                    {'T', 'I', 'E'} };
    vector<string> dictionary1 = { "CAT" };
    vector<string> result1 = wordBoggle(board1, dictionary1);
    for (const string& word : result1)
        cout << word << " ";
    cout << endl;

    vector<vector<char>> board2 = { {'G', 'I', 'Z'},
                                    {'U', 'E', 'K'},
                                    {'Q', 'S', 'E'} };
    vector<string> dictionary2 = { "GEEKS", "FOR", "QUIZ", "GO" };
    vector<string> result2 = wordBoggle(board2, dictionary2);
    for (const string& word : result2)
        cout << word << " ";
    cout << endl;

    return 0;
}
