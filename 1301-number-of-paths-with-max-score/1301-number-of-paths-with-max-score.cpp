class Solution {
    int n;
    const int MOD = 1e9 + 7;
    vector<string> board;
    vector<vector<pair<int,int>>> memo;   // cache; first == INT_MIN means "not solved yet"

    pair<int,int> solve(int i, int j) {
        if (i < 0 || j < 0)      return {-1, 0};
        if (board[i][j] == 'X')  return {-1, 0};
        if (i == 0 && j == 0)    return {0, 1};

        if (memo[i][j].first != INT_MIN) return memo[i][j];   // <-- already computed, reuse

        int val = (board[i][j] == 'S') ? 0 : board[i][j] - '0';
        pair<int,int> up   = solve(i - 1, j);
        pair<int,int> left = solve(i, j - 1);
        pair<int,int> diag = solve(i - 1, j - 1);

        int best = max({up.first, left.first, diag.first});
        if (best == -1) return memo[i][j] = {-1, 0};

        int ways = 0;
        if (up.first   == best) ways = (ways + up.second)   % MOD;
        if (left.first == best) ways = (ways + left.second) % MOD;
        if (diag.first == best) ways = (ways + diag.second) % MOD;

        return memo[i][j] = {best + val, ways};   // <-- store before returning
    }
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        this->board = board;
        n = board.size();
        memo.assign(n, vector<pair<int,int>>(n, {INT_MIN, 0}));
        auto res = solve(n - 1, n - 1);
        if (res.first == -1) return {0, 0};
        return {res.first, res.second};
    }
};