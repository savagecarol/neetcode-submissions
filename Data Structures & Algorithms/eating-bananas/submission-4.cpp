class Solution {
public:
    // int minEatingSpeed(vector<int>& piles, int h) {

    //     int n = piles.size();
    //     int i = 0 , j = 0 , ans = 0, mid = -1;
    //     long long  sum=0 ;
    //     for( i = 0 ; i < n ; i++){
    //         sum+=piles[i];
    //     }
    //     i = 1;
    //     j = sum;
        
    //     while(i <= j){
    //         mid = i + (j-i)/2;
    //         long long value = 0;
    //         for(int x = 0 ; x < n ; x++){
    //                 value += ceil((double)piles[x] / mid);
    //         }
    //         cout << mid << " " << value << " " << i << " " << j << endl;     
                   
    //         if(value <= h){ 
    //             ans = mid;
    //             j = mid-1;  
    //         }
    //         else i = mid+1;        
    //     }
    //     return ans;
    // }


    int minEatingSpeed(vector<int>& piles, int h) {

        int n = piles.size();

        int i = 1;
        int j = *max_element(piles.begin(), piles.end());

        int ans = 0;

        while (i <= j) {
            int mid = i + (j - i) / 2;

            long long value = 0;

            for (int x = 0; x < n; x++) {
                value += (piles[x] + mid - 1) / mid;  // integer ceil trick
            }

            if (value <= h) {
                ans = mid;
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }

        return ans;
    }

};
