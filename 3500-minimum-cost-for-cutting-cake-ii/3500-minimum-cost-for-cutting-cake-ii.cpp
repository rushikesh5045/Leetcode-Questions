#include <vector>
#include <algorithm>

class Solution {
public:
    long long minimumCost(int m, int n, std::vector<int>& h, std::vector<int>& v) {
        std::sort(h.begin(), h.end(), std::greater<int>());
        std::sort(v.begin(), v.end(), std::greater<int>());

        long long totalCost = 0;
        int horizontalPieces = 1; 
        int verticalPieces = 1;  

        int i = 0, j = 0;

        // Use a greedy approach to take the minimum cost at each step
        while (i < h.size() && j < v.size()) {
            if (h[i] >= v[j]) {
                totalCost += (long long)h[i] * verticalPieces;
                horizontalPieces++;
                i++;
            } else {
                totalCost += (long long)v[j] * horizontalPieces;
                verticalPieces++;
                j++;
            }
        }

        while (i < h.size()) {
            totalCost += (long long)h[i] * verticalPieces;
            i++;
        }

        while (j < v.size()) {
            totalCost += (long long)v[j] * horizontalPieces;
            j++;
        }

        return totalCost;
    }
};
