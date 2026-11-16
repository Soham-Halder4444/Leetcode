class Solution {
public:
    int count = 0;

    void mergeSort(vector<int>& arr, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Count reverse pairs
        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)arr[i] > 2LL * arr[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        // Merge step
        vector<int> temp;
        int i = left; j = mid + 1;
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
            else temp.push_back(arr[j++]);
        }
        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= right) temp.push_back(arr[j++]);
        for (int k = 0; k < temp.size(); k++) arr[left + k] = temp[k];
    }
    int reversePairs(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return count;
    }
};