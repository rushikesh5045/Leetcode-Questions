#include<bits/stdc++.h>
using namespace std;


class Solution {
private:
    const vector<string> numerals{"Billion", "Million", "Thousand", "Hundred", "Ninety","Eighty", "Seventy","Sixty", "Fifty", "Forty", "Thirty", "Twenty", "Nineteen", "Eighteen", "Seventeen", "Sixteen", "Fifteen", "Fourteen", "Thirteen", "Twelve","Eleven", "Ten","Nine", "Eight", "Seven", "Six", "Five", "Four", "Three","Two", "One"};
    const vector<int> units = {1000000000, 1000000, 1000, 100, 90, 80, 70, 60,50, 40,30,20,19, 18, 17, 16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
public:
    string numberToWords(int num) 
    {
        if(num == 0) return "Zero";
        int i = 0;
        for(; num < units[i]; ++i) ;
        int upper = num/units[i];
        int lower = num%units[i];
        return (i<4? numberToWords(upper) + " " : "") + numerals[i] + (lower? " " + numberToWords(lower) : "");
    }
};