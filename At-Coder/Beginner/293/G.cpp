#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
const int sqrtN = 500; //200000 = 500*400
ll v[N];
int n;

struct Query{
    int l, r, i;
    bool operator< (const Query u) const {
        if(l/sqrtN != u.l/sqrtN) return l/sqrtN < u.l/sqrtN;
        else return r < u.r;
    }
};

int loc[N]; //last occurence
ll aux[N];
ll gr[N];
ll lo[N];
void init(){
    ll sum = 0;
    for(ll i=1;i<N;i++){
        gr[i] = (i*(i-1)*(i-2))/6;
        gr[i] -= sum;
        sum += gr[i];
    }
}
void erase(){
    for(int i=1;i<=n;i++){
        loc[v[i]] = -1;
        aux[i] = 0;
    }
}

ll ans[N];
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
            erase();
        }
        while(p <= x.r){
            if(loc[v[p]] == -1){
                loc[v[p]] = p;
                aux[p] = 1;
                cur += gr[aux[p]];
            }else{
                aux[p] = aux[loc[v[p]]]+1;
                cur += gr[aux[p]];
                loc[v[p]] = p;
            }
            p++;
        }
        ll sub = 0;
        for(int i=blk;i<x.l;i++){
            sub += gr[aux[loc[v[i]]] - aux[i] + 1];
        }
        ans[x.i] = cur - sub;        
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int  q;
    cin >> n >> q;
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        vq.push_back({a-1, b-1, i});
    }
    init();
    sort(vq.begin(), vq.end());
    Mo();
    for(int i=0;i<q;i++) cout << ans[i] << "\n";
}
