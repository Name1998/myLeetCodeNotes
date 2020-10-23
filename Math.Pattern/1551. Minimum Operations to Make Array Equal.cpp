// SOLUTION 1： MY SOLUTION (O(1)  找规律，不解释
int minOperations(int n) {   
    return n*n/4;
    // if(n%2) //n odd
    //     // actually = n^2/4 - 1/4, as n is odd, n^2/4 is integer so (int) n^2/4 - 1/4 = n^/4
    //     return (1+(n-1)/2)*((n-1)/2);         
    // else 
    //     return n*n/4;
    // return 0;
}

/*
1 3 5 7 9     odd
  4   6
  5   5
2       8
3       7
4       6
5       5       //    result = 2 * (1+2+3+...+(n-1)/2)

1 3 5 7 9 11   even
    6 6                         1
  4     8     
  5     7
  6     6                       3
2         10
3         9
4         8
5         7
6         6                     5
            
1 3 5 7 9 11 13 15
      8 8                       1
    6     10
    7     9
    8     8                     3
  4          12
  5          11
  6          10
  7          9
  8          8                  5
2               14
3               13
4               12
5               11
6               10
7               9
8               8               7
*/
