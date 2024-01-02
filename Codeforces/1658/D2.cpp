#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3800005, M = 19; // log aMax * Q (2e5 * 19, for example)
int cnt = 0;
int trie[N][2];
int sz[N];

bool get(int num){
    int cur = 0;
    for(int i=M-1;i >= 0; i--){
        if(trie[cur][(num & (1 << i)) >> i]){
            cur = trie[cur][(num & (1 << i)) >> i];
        }else return false;
    }
    return true;
}
void insert(int num){
    if(get(num)) return;
    int cur = 0;
    for(int i=M-1;i >= 0; i--){
        sz[cur]++;
        if(trie[cur][(num & (1 << i)) >> i]){
            cur = trie[cur][(num & (1 << i)) >> i];
        }else cur = trie[cur][(num & (1 << i)) >> i] = ++cnt;
    }
    sz[cur]++;
}

void remove(int num){
    if(!get(num)) return;
    int cur = 0;
    for(int i=M-1;i>=0;i--){
        sz[cur]--;
        cur = trie[cur][(num & (1 << i)) >> i];
    }
    sz[cur]--;
    cur = 0;
    for(int i=M-1;i>=0;i--){
        int nxt = trie[cur][(num & (1 << i)) >> i];
        if(sz[nxt] == 0){
            trie[cur][(num & (1 << i)) >> i] = 0;
        }
        cur = nxt;
    }
}

int minxor(int num){
    int cur = 0;
    int key = 0;
    for(int i=M-1;i>=0;i--){
        int b = (num & (1 << i)) >> i;
        if(trie[cur][b]){
            cur = trie[cur][b];
            if(b) key ^= (1 << i);
        }else{
            cur = trie[cur][b^1];
            if(b^1) key ^= (1 << i);
        }
    }
    return key ^ num;
}


int maxxor(int num){
    int cur = 0;
    int key = 0;
    for(int i=M-1;i>=0;i--){
        int b = (num & (1 << i)) >> i;
        if(trie[cur][b^1]){
            cur = trie[cur][b^1];
            if(b^1) key ^= (1 << i);
        }else{
            cur = trie[cur][b];
            if(b) key ^= (1 << i);
        }
    }
    return key ^ num;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        int n = r - l + 1;
        vector<int> v(n);
        vector<int> chk;
        for(int i=0;i<n;i++) cin >> v[i];
        for(int i=0;i<n;i++) insert(v[i]);
        for(int i=0;i<n;i++) chk.push_back(v[i] ^ l);
        //find some x, maxxor(x) = r, minxor(x) = l
        for(auto x : chk){
            if(maxxor(x) == r && minxor(x) == l){
                cout << x << "\n";
                break;
            }
        }


        //clear tree
        trie[0][0] = trie[0][1] = sz[0] = 0;
    }
}