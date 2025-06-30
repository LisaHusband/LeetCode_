class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> total = nums1;
        total.insert(total.end(), nums2.begin(), nums2.end());
        sort(total.begin(), total.end());

        int n = total.size();
        double median = 0.0;

        if (n == 0) return 0.0;

        if (n % 2 == 0) {
            median = (total[n / 2 - 1] + total[n / 2]) / 2.0;
        } else {
            median = total[n / 2];
        }

        return median;
    }
};