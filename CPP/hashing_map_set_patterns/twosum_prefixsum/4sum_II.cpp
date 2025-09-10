class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> sumAB;
        int count = 0;

        // Step 1: store sums of A[i]+B[j]
        for (int a : A) {
            for (int b : B) {
                sumAB[a+b]++;
            }
        }

        // Step 2: check sums of C[k]+D[l]
        for (int c : C) {
            for (int d : D) {
                int target = -(c+d);
                if (sumAB.find(target) != sumAB.end()) {
                    count += sumAB[target];
                }
            }
        }

        return count;
    }
};
