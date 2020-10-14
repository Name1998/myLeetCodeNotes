// SOLUTION 1

// when sum+nums[i] < nums[i], which means it must be: sum+nums[i]+nums[i+1] < nums[i] + nums[i+1]
// say if the first number is negetive, nums[1]>nums[1]+sum,
// then we abandon nums[0] and start the sub-array from nums[1];

int maxSubArray(vector<int>& nums) {
    int max = nums[0], sum = 0;
    for(int i=0; i<nums.size(); i++)
    {   
        sum = std::max(nums[i], sum+nums[i]); 
        max = std::max(sum,max);
    }
    return max;
}


// SOLUTION 2: DP
