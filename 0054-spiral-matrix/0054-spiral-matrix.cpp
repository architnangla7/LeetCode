class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rows=matrix.size();
        int columns=matrix[0].size();
        int total=rows*columns;
        int count=0;
        int startingRow=0;
        int endingColumn=columns-1;
        int endingRow=rows-1;
        int startingColumn=0;
        while(count<total)
        {
            for(int index=startingColumn;count<total && index<=endingColumn;index++)
            {
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;
            for(int index=startingRow;count<total && index<=endingRow;index++)
            {
                ans.push_back(matrix[index][endingColumn]);
                count++;
            }
            endingColumn--;
            for(int index=endingColumn;count<total && index>=startingColumn;index--)
            {
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;
            for(int index=endingRow;count<total && index>=startingRow;index--)
            {
                ans.push_back(matrix[index][startingColumn]);
                count++;
            }
            startingColumn++;
        }
           return ans;
    }
};