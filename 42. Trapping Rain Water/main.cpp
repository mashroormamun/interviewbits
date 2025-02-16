class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> height_max_left(height.size());
        vector<int> height_max_right(height.size());
        
        int result = 0;
        
        for(int i=0;i<height.size();i++) {
            if(i==0) height_max_left[i]=0;
            else height_max_left[i] = height_max_left[i-1] > height[i-1] ? height_max_left[i-1] : height[i-1];
            
            int j=height.size()-1-i;
            if(j==height.size()-1) height_max_right[j]=0;
            else height_max_right[j] = height_max_right[j+1] > height[j+1] ? height_max_right[j+1] : height[j+1];
        }
        
        for(int i=0;i<height.size();i++) {
            int sum = min(height_max_right[i], height_max_left[i]) - height[i];
            
            result += sum<0 ? 0 : sum;
        }
        
        return result;
    }
};
