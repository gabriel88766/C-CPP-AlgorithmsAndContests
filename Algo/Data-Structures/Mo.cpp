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

//specific case 86D
int loc[1000001]; //last occurence
ll aux[N];
void erase(){ //caution here!!! remember to erase everything.
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
            erase(); //once each block O(N)
        }
        while(p <= x.r){ //from 0 to n, sqrt(N) times
            if(loc[v[p]] == -1){
                loc[v[p]] = p;
                aux[p] = 1;
                cur += v[p];
            }else{
                aux[p] = aux[loc[v[p]]]+1;
                cur += v[p]*(2*aux[p]-1); //way to count
                loc[v[p]] = p;
            }
            p++;
        }
        ll sub = 0;
        for(int i=blk;i<x.l;i++){ //O(sqrt(N))
            sub += v[i]*((aux[loc[v[i]]] - aux[i])*2+1); //inverse count(remove)
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
    sort(vq.begin(), vq.end());
    Mo();
    for(int i=0;i<q;i++) cout << ans[i] << "\n";
}


//BELOW A new Mo template
constexpr int BLOCK = 500;
struct Query{
    int l, r, i;
    bool operator< (const Query u) const {
        if(l/BLOCK != u.l/BLOCK) return l/BLOCK < u.l/BLOCK;
        else return r < u.r;
    }
};

template<typename T, void (*erase)(), void (*insert)(int), void (*remove)(int), T (*get)(int)>
struct Mo{
    vector<Query> vq;
    vector<T> ans;
    static constexpr int sqrtN = BLOCK; //adjust accordingly with Q value. Compile time to increase performance
    Mo(vector<Query> &allq){ 
        vq = allq;
        sort(vq.begin(), vq.end());
        ans.resize(allq.size());
    }
    void solve(){ 
        int blk = -1, p = 0;
        ll cur = 0;
        for(auto x : vq){
            if((x.l/sqrtN)*sqrtN != blk){
                cur = 0;
                blk = p = (x.l/sqrtN)*sqrtN; //first element of block
                erase(); //once each block O(N * sqrtN) overall
            }
            while(p <= x.r){ //from 0 to n, sqrt(N) times
                insert(p++); //insert information about p;
            }
            for(int i=blk;i<x.l;i++){ //O(sqrt(N))
                remove(i);
            }
            ans[x.i] = get(x.i);
            for(int i=blk;i<x.l;i++){ //O(sqrt(N))
                insert(i);
            }      
        }
    }
};  

//These functions must be changed.
vector<Query> vx;
// int v[N], cnt[N]; //data stored

void erase(){
    //erase the whole DS; must be O(n) most of times
}
void insert(int p){
    //insert index p, must be O(1) most of times
}

void remove(int p){
    //remove index p, must be O(1) most of times
}

//must be same return type
int get(int j){
    //LOGIC to get the answer to determined index.
    //Up to O(sqrt(n))
    
}
