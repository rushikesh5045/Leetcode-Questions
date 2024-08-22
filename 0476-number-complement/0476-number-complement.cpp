class Solution {
public:
    int findComplement(int nums) {
        long  long digits = log2(nums)+1;
        long  long ones = 1;
        long long  shifting = ones<<digits;
        shifting = shifting - 1;
        return (long long )nums ^ shifting;
    }
};