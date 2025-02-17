#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//Make some xor related problems much easier
//can be used as ordered set too
//1895D 1658D2
const int N = 9100000, M = 30; // log aMax * Q (2e5 * 19, for example)
int cnt = 0;
int trie[N][2];
int sz[N];
int val[N];

multiset<int> an;


//if sz[x] == 3, then remove. (if insert)
//if sz[x] == 2, then insert. (both)
//if sz[x] == 1, then remove. (if remove)


void insert(int num){
    int cur = 0;
    vector<int> nds;
    for(int i=M-1;i >= 0; i--){
        sz[cur]++;
        if(sz[cur] == 3 && sz[trie[cur][0]] == 1 && sz[trie[cur][1]] == 1) an.erase(an.find(val[trie[cur][0]] ^ val[trie[cur][1]]));
        nds.push_back(cur);
        if(trie[cur][(num & (1 << i)) >> i]){
            cur = trie[cur][(num & (1 << i)) >> i];
        }else cur = trie[cur][(num & (1 << i)) >> i] = ++cnt;
    }
    nds.push_back(cur);
    sz[cur]++;
    if(sz[cur] == 2){
        an.insert(0);
    }
    val[cur] = num;
    reverse(nds.begin(), nds.end());
    for(auto &x : nds){
        if(sz[x] == 2 && sz[trie[x][0]] == 1 && sz[trie[x][1]] == 1){
            an.insert(val[trie[x][0]] ^ val[trie[x][1]]);
        }
        if(sz[x] == 1){
            if(trie[x][0] && sz[trie[x][0]] == 1) val[x] = val[trie[x][0]];
            else if(trie[x][1] && sz[trie[x][1]] == 1) val[x] = val[trie[x][1]];
        }
    }
}

void remove(int num){
    int cur = 0;
    vector<int> nds;
    for(int i=M-1;i>=0;i--){
        sz[cur]--;
        if(sz[cur] == 1 && sz[trie[cur][0]] == 1) an.erase(an.find(val[trie[cur][0]] ^ val[trie[cur][1]]));
        nds.push_back(cur);
        cur = trie[cur][(num & (1 << i)) >> i];
    }
    nds.push_back(cur);
    sz[cur]--;
    reverse(nds.begin(), nds.end());
    if(sz[cur] == 1) an.erase(an.find(0));
    for(auto &x : nds){
        if(sz[x] == 2 && sz[trie[x][1]] == 1){
            an.insert(val[trie[x][0]] ^ val[trie[x][1]]);
        }
        if(sz[x] == 1){
            if(trie[x][0] && sz[trie[x][0]] == 1) val[x] = val[trie[x][0]];
            else if(trie[x][1] && sz[trie[x][1]] == 1) val[x] = val[trie[x][1]];
        }
    }
}





//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        if(x == 3) cout << *an.begin() << "\n";
        else if(x == 1){
            cin >> x;
            insert(x);
        }else{
            cin >> x;
            remove(x);
        }
    }
}
