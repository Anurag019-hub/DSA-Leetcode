class Solution {
public:
    int Mod=1e9+7;
    //Calcute C_{n} choose k by Pascal's equation
    
    int compute_C_N_choose_K(int N, int K){
        if (K>N/2) K=N-K;//C_N choose K =C_N choose N-K
        vector<int> C_N(K+1, 0), prevC(K+1, 0);
        for(int i=0; i<=N; i++){
            C_N[0]=1;
            for(int j=1; j<=min(i, K);j++){
                C_N[j]=((long)prevC[j-1]+prevC[j])%Mod;  
            }
            prevC=C_N;  
        }
        return C_N[K];
    }

    long Subproblem(vector<int>& nums){
        int n=nums.size();
        if (n<=2) return 1;
        vector<int> left, right;
        int root=nums[0];
        for (int i=1; i<n; i++){
            if (root<nums[i]) right.push_back(nums[i]);
            else left.push_back(nums[i]);
        }
        long r=Subproblem(right), l=Subproblem(left);
        return compute_C_N_choose_K(n-1, left.size())*r%Mod*l%Mod;

    }
    int numOfWays(vector<int>& nums) {
        return (Subproblem(nums)-1)%Mod;
    }
};