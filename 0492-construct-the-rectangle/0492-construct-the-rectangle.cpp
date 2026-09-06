class Solution {
public:
    int findWidth(int area, int w) {
        
        if (area % w == 0) {
            return w;
        }
        
        return findWidth(area, w - 1);
    }

    vector<int> constructRectangle(int area) {
      
        int w = sqrt(area);
        
        
        w = findWidth(area, w);
        
        // Length is area / width, and width is w
        return {area / w, w};
    }
};