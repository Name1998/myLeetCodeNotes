// SOLUTION 1 ( MY SOLUTION ): O(n)
// JUST 1 FOR LOOP 
// UPDATE max AND secondMax EACH ITERATION
int maxProduct(vector<int>& nums) {
    int   max = nums[0], secondMax = 0;

    for(int i=1; i<nums.size(); i++){
        if(nums[i] >= max){
            secondMax = max;
            max = nums[i];
        }
        else if(secondMax < =nums[i] && nums[i] <= max)
            secondMax = nums[i];
    }
    return (secondMax-1)*(max-1);
}
