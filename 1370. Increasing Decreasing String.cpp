// https://leetcode.com/problems/increasing-decreasing-string/
// SOLUTION 1(MY SOLUTION): USE STL: map
// USE map INSTEAD OF unodered_map DUE TO IT'S ODERLINESS
// BEAWARE: erase() WHILE TRAVERSING IS COMPLICATED, USE iterator INSTEAD OF auto.
 string sortString(string s) {
    map<char,int> hash;
    int l=s.length();
    string result="";
    for(int i=0;i<l; i++)
        hash[s[i]]++;
    map<char, int>::iterator tmp;
    while(!hash.empty()){
        for(map<char, int>::iterator it=hash.begin();it!=hash.end(); ){
            result+=it->first;
            hash[it->first]--;
            if(it->second==0){
                hash.erase(it++);
            } else it++;
        }
        string temp = "";
        for(map<char, int>::iterator it=hash.begin();it!=hash.end(); ){
            temp = it->first + temp;
            hash[it->first]--;
            if(it->second==0){
                hash.erase(it++);
            } else it++;
        }
        result += temp;
    }
    return result;
}

// SOLUTION 2: USE ARRAY AS HASH TABLE
string sortString(string s) {
    //map<char,int> hash;
    int l=s.length();
    string result="";
    char hash[26]={0};
    for(int i=0;i<l;i++)
        hash[s[i]-'a']++;
    int len = l;

    while(len){
      for(int i=0;i<26;i++){
          if(hash[i]>0){
              result += i +'a';
              hash[i]--;
              len--;
          } 
      }
      string temp = "";
      for(int i=0;i<26;i++)                
          if(hash[i]>0){
              temp = (char)(i+'a') + temp;
              hash[i]--;
              len--;
          }
      result += temp;
    }
    return result;        
}
