// Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, 
// for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].
/* RESTRICTION */
// 2 <= nums.length <= 500
// 0 <= nums[i] <= 100

// SOLUTION 1: HASH TABLE O(N)
// 1. count the frequency of numbers in nums[]
// 2. the count of numbers that smaller than x : smallerThanIndex[x]
// 3. smallerThanIndex[x] = smallerThanIndex[x-1] + hash[x-1],
// 4. 0<=nums[i]<=100, which means smallerThanIndex[0] == 0, itrate from x==1 to x==100;
// 5. result[i] = smallerThanIndex[nums[i]]

    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size(),  hash[101] = {0},  countSmallerThanIndex[101] = {0};                  
        vector<int> result(n);
        for(int i=0; i<n; i++)
            hash[nums[i]]++;        
        for(int i=1; i<101; i++)
            countSmallerThanIndex[i] = countSmallerThanIndex[i-1] + hash[i-1];        
        for(int i=0; i<n; i++)
            result[i] = countSmallerThanIndex[nums[i]];
        return result;
    }
    
// SOLUTION 2: BRUTE COUNT 0(N^2)

    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int count = 0;
            for(int j=0; j<nums.size(); j++)
                if(j != i && nums[j] < nums[i] ) count++;
            result.push_back(count);
            }
        return result;
    }
