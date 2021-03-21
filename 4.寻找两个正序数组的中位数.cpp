/*
 * @Author: kotwzjc
 * @Github: https://github.com/kotwzjc
 * @Date: 2021-03-21 16:46:29
 * @LastEditors: kotwzjc
 * @LastEditTime: 2021-03-21 21:18:13
 */
/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    // recommend solution 
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
        /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
         * 这里的 "/" 表示整除
         * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
         * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
         * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
         * 这样 pivot 本身最大也只能是第 k-1 小的元素
         * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
         * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
         * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
         */

        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0, index2 = 0;

        while (true) {
            // 边界情况
            if (index1 == m) {
                return nums2[index2 + k - 1];
            }
            if (index2 == n) {
                return nums1[index1 + k - 1];
            }
            if (k == 1) {
                return min(nums1[index1], nums2[index2]);
            }

            // 正常情况
            int newIndex1 = min(index1 + k / 2 - 1, m - 1);
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];
            if (pivot1 <= pivot2) {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }
            else {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
        // my solution
        vector<int>::iterator it1 = nums1.begin();
        vector<int>::iterator it2 = nums2.begin();
        int len = 0;
        int l = nums1.size() + nums2.size();
        int flag = 0;
        if(l%2 == 0) flag = 1;
        double tempResult, preResult;
        while(it1 != nums1.end() && it2 != nums2.end()){
            if(*it1 <= *it2)
                tempResult = *it1++;
            else
                tempResult = *it2++;
            len++;
            if(flag == 0 && len == (l/2 + 1)) return tempResult;
            if(flag == 1){
                if(len == l/2) preResult = tempResult;
                else if(len == (l/2 + 1)) return (preResult+tempResult) / 2.0;
            }
        }
        while(it1 != nums1.end()){
            len++;
            if(flag == 0 && len == (l/2 + 1)) return (double)*it1;
            if(flag == 1){
                if(len == l/2) preResult = *it1;
                else if(len == (l/2 + 1)) return (preResult+*it1) / 2.0;
            }
            it1++;
        }
        while(it2 != nums2.end()){
            len++;
            if(flag == 0 && len == (l/2 + 1)) return (double)*it2;
            if(flag == 1){
                if(len == l/2) preResult = *it2;
                else if(len == (l/2 + 1)) return (preResult+*it2) / 2.0;
            }
            it2++;
        }
        return 0;*/
        // recommend solution
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        }
        else {
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }
};
// @lc code=end

