// SOLUTOIN 1( MY SOLUTION ): BEATS 100%
// JUST CHECK IF s[i+2] == '#' OR NOT, THEN DECODE THE CURRENT CHARACTER.
// EACH ITERATION UPDATE s = s.substr( 1 or 3 ).
string freqAlphabets(string s) {
    string result = "";
    while(s != ""){
        if(s[2] == '#' && s.length() >= 3){
            result += 'a' + stoi(s.substr(0,2)) - 1;
            s = s.substr(3);
        }
        else{
            result += 'a' + s[0] - '0' - 1;
            s = s.substr(1);
        }
    }
    return result;
}
