class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closestX = clamp(xCenter, x1, x2);
        int closestY = clamp(yCenter, y1, y2);
        
        int distanceX = closestX - xCenter;
        int distanceY = closestY - yCenter;
        
        return (distanceX * distanceX) + (distanceY * distanceY) <= (radius * radius);
    }
};