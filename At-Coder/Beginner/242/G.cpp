#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
const int sqrtN = 100; //200000 = 500*400
int v[N];
int n;
int ans[1000005];

struct Query{
    int l, r, i;
    bool operator< (const Query u) const {
        if(l/sqrtN != u.l/sqrtN) return l/sqrtN < u.l/sqrtN;
        else return r < u.r;
    }
};

//specific case 86D
int cnt[N]; //last occurence
int cans = 0;
void erase(){ //caution here!!! remember to erase everything.
    for(int i=1;i<=n;i++){
        cnt[i] = 0;
    }
    cans = 0;
}

vector<Query> vq;
//Key idea,
//Process queries that begin in block 1, then block 2, and so on...
//build array with the right position while the right position grow.
void Mo(){ //This is an example, function need to be changed, but idea remains.
    int blk = -1, p = 0;
    ll cur = 0;
    for(auto x : vq){
        if((x.l/sqrtN)*sqrtN != blk){
            cur = 0;
            blk = p = (x.l/sqrtN)*sqrtN; //first element of block
            erase(); //once each block O(N)
        }
        while(p <= x.r){ //from 0 to n, sqrt(N) times
            cnt[v[p]]++;
            if(!(cnt[v[p]] % 2)) cans++;
            p++;
        }
        for(int i=blk;i<x.l;i++){ //O(sqrt(N))
            if(!(cnt[v[i]] % 2)) cans--;
            cnt[v[i]]--;
        }
        ans[x.i] = cans;  
        for(int i=blk;i<x.l;i++){ //O(sqrt(N))
            cnt[v[i]]++;
            if(!(cnt[v[i]] % 2)) cans++;
        }      
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n;
    for(int i=1;i<=n;i++) cin >> v[i];
    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        int l, r;
        cin >> l >> r;
        vq.push_back({l, r, i});
    }
    sort(vq.begin(), vq.end());
    Mo();
    for(int i=1;i<=q;i++) cout << ans[i] << "\n";
}
