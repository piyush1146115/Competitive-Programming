class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
         // difference between two numbers (x and y) which were seen only once
        long int bitmask = 0;
        for (int num : nums) bitmask ^= num;

        // rightmost 1-bit diff between x and y
        long int diff = bitmask & (-bitmask);

        int x = 0;
        // bitmask which will contain only x
        for (int num : nums) if ((num & diff) != 0) x ^= num;

        return {x, (int)bitmask^x};
    }
};