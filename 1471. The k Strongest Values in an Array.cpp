// SOLUTION 1 (MY SOLUTION) : REGULAR SORT, O(nlogn)
// vector<int> getStrongest(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    median = arr[(n-1)/2];
    vector<int> result;
    int i=0,j=n-1;
    while(k--)
    {   
        int a = abs(arr[i]-median), b = abs(arr[j]-median);
        if(a>b)       
            result.push_back(arr[i++]);        
        else            
            result.push_back(arr[j--]);            
    }
    return result;
}

// SOLUTION 2 ： nth_element(), O(n)
vector<int> getStrongest(vector<int>& arr, int k) {
  int median, n=arr.size();
  nth_element(arr.begin(), arr.begin()+(n-1)/2, arr.end());
  median = arr[(n-1)/2];
  nth_element(arr.begin(), arr.begin()+k, arr.end(), 
    [&](int a, int b)
    {return abs(a-median) > abs(b - median) || (abs(a-median) == abs(b - median) && a>b);}
  );
}
