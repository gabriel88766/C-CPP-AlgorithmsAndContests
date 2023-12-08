const int N = 1002*1002; //substrings of a string of len 1505

int cntn = 0;
int trie[N][26];

int add(int node, char c){
    c -= 'a';
    if(trie[node][c]) return trie[node][c];
    else return trie[node][c] = ++cntn;
}

//example add string
void add(string s){
    int curn = 0;
    for(auto c : s) curn = add(curn, c);
}