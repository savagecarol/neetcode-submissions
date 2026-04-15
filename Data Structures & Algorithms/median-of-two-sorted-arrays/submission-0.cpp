class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 1. Add sentinels to handle boundaries easily
        nums1.insert(nums1.begin(), INT_MIN);
        nums1.push_back(INT_MAX);
        nums2.insert(nums2.begin(), INT_MIN);
        nums2.push_back(INT_MAX);

        // 2. Ensure we binary search on the smaller array
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        int n = nums1.size();
        int m = nums2.size();
        
        // Total elements including 4 sentinels. 
        // We want to partition the "real" elements + the 2 INT_MINs.
        int totalWithSentinels = n + m;
        int half = totalWithSentinels / 2;

        int i = 0, j = n - 2; // Range includes the first sentinel up to the last real element

        while (i <= j) {
            int mid1 = i + (j - i) / 2;
            // mid1 + mid2 must equal the number of elements on the left
            int mid2 = half - mid1 - 2; 

            // Check if the partition is correct
            if (nums1[mid1] <= nums2[mid2 + 1] && nums2[mid2] <= nums1[mid1 + 1]) {
                
                // If the original sum of elements was even
                // (n+m-4) is the original size
                if ((n + m - 4) % 2 == 0) {
                    return (double)(max(nums1[mid1], nums2[mid2]) + 
                                    min(nums1[mid1 + 1], nums2[mid2 + 1])) / 2.0;
                } else {
                    // If original size was odd, median is the smallest of the right side
                    return (double)min(nums1[mid1 + 1], nums2[mid2 + 1]);
                }
            } 
            else if (nums1[mid1] > nums2[mid2 + 1]) {
                j = mid1 - 1;
            } else {
                i = mid1 + 1;
            }
        }

        return 0.0;
    }
};