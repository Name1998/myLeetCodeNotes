// SOLUTION 1: FIND PATTERN, O(1)
// CASE 1：
// if start % 4 == 0 or 1, the second bit from right must be 0 (xx00 or xx01, start + 2 == xx10 or xx11; xx00 ^ xx10 == 2, xx01 ^ xx11 == 2 ), 
// so start ^ (start+2) == 2，(start + 2) ^ (start + 4) == 2 .....
// and 2 ^ 2 == 0, which means start ^ (start+2) ^ (start + 4) ^ (start + 6) == 0,
// which means every 4 elements ^sum up 0, so we just need to care about the last (n%4) element(s).
// if n % 4 == 0, [0].
// if n % 4 == 1, the last numebr is [start + 2 * (n - 1)].
// if n % 4 == 2, the last two numbers ^sum up [2]. (line 2-3)
// if n % 4 == 3, the last three numbers ^sum up [2^last] == [2^(start+ 2 * (n - 1))]
// CASE 2：
// if start % 4 == 2 or 3, the second right bit is 1 (xx10 or xx11, if directly +2 a carry will be generated,  )
// in order to avoid the carry, let it be (start + 2) % 4, which equals to 0 or 1, same as CASE 1.
// as the series is : (start) ^ (start+2) ^ (start+2*2) ^ ...... ^ (start+2*(n-1)) == (start) ^ (start+2+0) ^ ......(start+2+2*(n-2))
// so we just consider the first and last several elements
// if (n-1) % 4 == 0, [start]
// if (n-1) % 4 == 1, the start one ^ the last 1 == [start ^ last] == [start ^ start + 2 * (n - 1)]
// if (n-1) % 4 == 2, the last two ^sum up 2, [start ^ 2]
// if (n-1) % 4 == 3, [start ^ 2 ^ (start + 2 * (n - 1))]

public int xorOperation(int n, int start) {
    /*----SOLUTION 2： O(1) ----*/
    int last = start + 2*(n-1);
    int    c = start % 4;
    if( c==0 || c==1 )
    {
        switch(n%4)
        {
            case 0: return 0;
            case 1: return last;
            case 2: return 2;
            case 3: return 2^last;
        }
    }
    else if( c==2 || c==3 )
    {
        switch((n-1)%4)
        {
            case 0: return start;
            case 1: return start^last;
            case 2: return start^2;
            case 3: return start^2^last;
        }
    }
    return 0;
}

// SOLUTION 2: BRUTE FORCE O(n)
public int xorOperation(int n, int start) {
    int sum=start;
    for(int i=1;i<n;i++)
        sum ^= start+2*i;
    return sum;
}
