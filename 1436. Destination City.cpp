//You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. 
//Return the destination city, that is, the city without any path outgoing to another city.
//It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.

// SOLUTION 1: BRUTE FORCE (double loop, O(n^2))
// first loop, traverse all paths and set each destination as tmp.
// second loop, set a flag, traverse again, if tmp is another pair's start, flag=1, else flag is always 0, which means it's the answer.
string destCity(vector<vector<string>>& paths) {
  int n=paths.size();
  for(int i=0; i<n;i++)
  {
    int flag=0;
    string tmp = paths[i][1];
    for(int j=0;j<n;j++){
      if(tmp == paths[j][0]){
          flag=1;
          break;
      }
    }
    if(flag==0)
      return tmp;
  }
   return "";
}


// SOLUTION 2: USE HASH SET TO STORE startingCity, while destCity is not found in starting's hash set, it's the answer.
string destCity(vector<vector<string>>& paths) {
  unordered_set<string> start;
  for(auto pair:paths)
      start.insert(pair[0]);
  for(auto pair:paths)
      if(!start.count(pair[1]))
          return pair[1];
  return "";
}

// SOLUTION 2.1: A MUCH EXPLICIT ONE
// STORE ALL CITY INTO A HASH MAP, IF IT'S A START, KEY++, IF IT'S A END, KEY += 0
// THE CITY WHOSE KEY = 0 IS THE ANSWER.
string destCity(vector<vector<string>>& paths) {
  unordered_map<string, int> degreeMap;        
  for(auto& e: paths){
      degreeMap[e[0]] += 1;
      degreeMap[e[1]] += 0;
  }

  for (auto& [k, v]: degreeMap)
      if (v == 0)
          return k;
  return ""; 
}

// SOLUTION 3：
// STORE START CITY AND END CITY INTO HASH MAP, SET MAP[START CITY] = END CITY,
// SET THE FIRST END CITY AS cur, IF IT CAN BE FOUND IN MAP(AS .FIRST), UPDATE cur = MAP[cur]
// WHICH MEAN WHEN cur CANNOT BE FOUND IT IS THE ANSWER.
string destCity(vector<vector<string>>& paths) {
    unordered_map<string, string> m;
    for(auto& e: paths)     m[e[0]] = e[1];
    string cur(paths[0][0]);
    while(m.count(cur))
        cur = m[cur];
    return cur;
}
