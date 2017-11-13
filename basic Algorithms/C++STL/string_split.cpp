#include<iostream>
#include<vector>
#include<sstream>

using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();
        if (nums1.empty()) {
            if (n%2 != 0)
                return 1.0*nums2[n/2];
            return (nums2[n/2]+nums2[n/2-1])/2.0;
        }
        if (nums2.empty()) {
            if (m%2 != 0)
                return 1.0*nums1[m/2];
            return (nums1[m/2]+nums1[m/2-1])/2.0;
        }
        int i = 0;
        int j = 0;
        vector<int> ans;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            } else {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        if (i < m) {
            for (; i < m; i++)
                ans.push_back(nums1[i]);
        } else if (j < n) {
            for (; j < n; j++)
                ans.push_back(nums2[j]);
        }
        int len = ans.size();
        if (len%2 != 0)
            return 1.0*ans[len/2];
        return (ans[len/2]+ans[len/2-1])/2.0;
    }
int main()
{
    string s;
    ////////////////
    vector<int> v1;
    v1.clear();
    getline(cin, s);
    istringstream is(s);
    int inter;
    char ch;
    while (is >> inter)
    {
         v1.push_back(inter);
         is >> ch;
    }
    ///////////////
    vector<int> v2;
    v2.clear();
    s.clear();
    getline(cin, s);
    istringstream is2(s);
    while (is2 >> inter)
    {
         v2.push_back(inter);
         is2 >> ch;
    }
    cout<<int(findMedianSortedArrays(v1, v2))<<endl;
    return 0;
}