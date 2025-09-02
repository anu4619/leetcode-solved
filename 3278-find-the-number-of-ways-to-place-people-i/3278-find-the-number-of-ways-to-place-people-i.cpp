class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int count=0;
    for(int i=0;i<points.size();i++)
    {
        int ax=points[i][0];
        int ay=points[i][1];
        for(int j=0;j<points.size();j++){
            if (i == j) continue;
        int bx=points[j][0];
        int by=points[j][1];
        bool isUpperLeft = (ax < bx && ay > by);
                bool isHorizontalLine = (ay == by && ax < bx);
                bool isVerticalLine   = (ax == bx && ay > by);
        if(isUpperLeft || isHorizontalLine || isVerticalLine){
            bool valid= true;

        
        for(int k=0;k<points.size();k++)
        {
            if(i==k||j==k) continue;
            int kx=points[k][0],ky=points[k][1];
            if(ax<=kx && kx<=bx && by<=ky && ky<=ay){
                valid=false;break;
            }
            
            }
            if (valid){
                count++;
        
    }}}}
    return count;
        
        
    }
};