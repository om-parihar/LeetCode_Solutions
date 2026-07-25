// Last updated: 7/25/2026, 11:02:22 PM
class Solution {
public:
   bool binary(int row, vector<vector<int>>& matrix, int target) {
    int low = 0;
    int high = matrix[0].size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (matrix[row][mid] == target)
            return true;
        else if (matrix[row][mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return false;
}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;

    int m = matrix.size();

    for (int i = 0; i < m; i++) {
        if (matrix[i][0] > target) {
            if (i == 0) return false;
            return binary(i - 1, matrix, target);
        }
    }

    return binary(m - 1, matrix, target);
}
};