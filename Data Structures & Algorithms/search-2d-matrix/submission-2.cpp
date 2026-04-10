class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int i = matrix.size();
        int j = matrix[0].size();

        int left = 0 , right = i-1 , pos = j-1;
        
        while(left < right)
        {
            int mid = left + (right - left)/2;
            if(matrix[mid][pos] ==  target) return true;
            else if (matrix[mid][pos] > target) right = mid;
            else left = mid + 1 ;

            cout << mid << " " << left << " " << right << endl;
        }

        i=0;
        j=j-1;
        
        while(i <= j)
        {
             int mid = i + (j - i)/2;
            if(matrix[right][mid] ==  target) return true;
            else if (matrix[right][mid] < target) i = mid + 1;
            else j = mid - 1;
        }

        return false;
        
    }
};
