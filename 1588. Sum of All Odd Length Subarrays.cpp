// SOLUTION 1: BRUTE FORCE(MY SOLUTION), USE TWO POINTER 

int sumOddLengthSubarrays(vector<int>& arr) {
    int n = 1, l = arr.size();
    int sum = 0;
    while(n<=l){
        // 双指针思想
        for(int i=0,j=n; j<=l;i++,j++ ){
            for(int k=i;k<j; k++)
                sum += arr[k];
        }
        n += 2;
    }
    return sum;
}

// SOLUTION 2: FIND THE PATTERN, O(N)
// 1.TAKE FOR ALL SUBARRAYS( BORH ODD AND EVEN LENGRH ):
// EACH ELEMENT AT INDEX i, IT'S COUNTED (i + 1) * (n - i) TIMES 
// ******* i + 1 means how many start index there are to the left of arr[i] (included), 
// ******* n - i means how many end index there are to the right of arr[i] (included)
// 2.THEN IN THE CIRCUMSTANCE OF ODD SUBARRAY, CEIL DEVIDE IT BY 2.
// WHY CEIL? IF EITHER i+1 OR n-i IS EVEN, NUMBER OF EVEN LENGTH = NUMBER OF ODD LENGTH
// IF BOTH EVEN, NUMBER OF ODD LENGTH = NUMBER OF EVEN LENGTH + 1

int sumOddLengthSubarrays(vector<int>& arr) {        
    int ans = 0,n=arr.size(),i;
    for(i =0;i<n;i++)
    {
        int contribution = ceil((i+1)*(n-i)/2.0);
        ans+=(contribution*arr[i]);
    }
    return ans;
}
