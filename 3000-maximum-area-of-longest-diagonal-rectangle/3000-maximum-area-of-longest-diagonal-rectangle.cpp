class Solution {
private:
    // Helper function using recursion to traverse the 2D array
    void solve(const vector<vector<int>>& dimensions, int index, int& max_diag_sq, int& max_area) {
        
        if (index == dimensions.size()) {
            return;
        }
        
        int length = dimensions[index][0];
        int width = dimensions[index][1];
        
        
        int current_diag_sq = (length * length) + (width * width);
        int current_area = length * width;
       
        if (current_diag_sq > max_diag_sq) {
            max_diag_sq = current_diag_sq;
            max_area = current_area;
        } else if (current_diag_sq == max_diag_sq) {
            max_area = max(max_area, current_area);
        }
        
        
        solve(dimensions, index + 1, max_diag_sq, max_area);
    }

public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int max_area = 0;
        int max_diag_sq = 0;
        
        // Start recursion from index 0
        solve(dimensions, 0, max_diag_sq, max_area);
        
        return max_area;
    }
};