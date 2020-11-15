// SOLUTION 1( MY SOLUIION, STUPID AND SLOW )
// USE A HASH TABLE TO STORE NUMBERS AND IT'S INDEX,
// FOR EACH NUMBER IN HASH TABLE( VALUE(INDEX) > 0 ), REPLACE THOSE LEFT TO IT IN arr[].    
// --> when traverse the hash[], the number is strictly increasing, thus unneccessary to check if arr[j] smaller than i;
// REPLACE arr[n-1] WITH -1.
vector<int> replaceElements(vector<int>& arr) {
  int n = arr.size();
  vector<int> hash(100001,0); 
  for(int i=0;i<n; i++)
    hash[arr[i]] = i;
  for(int i=0; i<100001; i++)
    if(hash[i])
      for(int j=0; j<hash[i]; j++)
        arr[j] = i;
  arr[n-1] = -1;
  return  arr;
}

// SOLUTOIN 2: O(n)
// SET max = -1.( CAUSE THE LAST NUMBER IN arr[] SHALL BE -1)
// TRAVERSE FROM RIGHT TO LEFT, FOR EACH ITERATION:
// 1. STORE CURRENT NUMBER  --> temp = arr[i]
// 2. REPLACE IT WITH max   --> arr[i] = max
// 3. UPDATE max            --> max = max(max,temp)
vector<int> replaceElements(vector<int>& arr) {
    int n = arr.size();
    int max = -1;//arr[n-1];
    int temp;
    for(int i=n-1; i>=0; i--){
        temp = arr[i];
        arr[i] = max;
        max = std::max(max,temp);
    }
    return  arr;
}
