#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+6;
 
ll bit[N];
int n;
vector<int> indx;

ll query(int b){ // sum in range [1, b]
    ll ans = 0;
    for(int i = b; i > 0; i -= i & -i){
        ans += bit[i];
    }
    return ans;
}
 
void add(int b, ll value){ //add value to position b
    for(int i = b; i <= n; i += i & -i){
        bit[i] += value;
    }
}

ll ans = 0;

int pl = 0, pr = 0;

void addright(){
    pr++;
    ans += query(n) - query(indx[pr]);
    add(indx[pr], 1);
}

void remright(){
    ans -= query(n) - query(indx[pr]);
    add(indx[pr], -1);
    pr--;
}

void addleft(){
    pl--;
    ans += query(indx[pl]-1);
    add(indx[pl], 1);
}

void remleft(){
    ans -= query(indx[pl]-1);
    add(indx[pl], -1);
    pl++;
}


const int sqrtN = 300; 

struct Query{
    int l, r, i;
    bool operator< (const Query u) const {
        if(l/sqrtN != u.l/sqrtN) return l/sqrtN < u.l/sqrtN;
        else return r < u.r;
    }
};


vector<Query> vq;
ll ansq[N];
//Key idea,
//Process queries that begin in block 1, then block 2, and so on...
//build array with the right position while the right position grow.
void Mo(){ //This is an example, function need to be changed, but idea remains.
    int blk = -1;
    for(auto x : vq){
        if((x.l/sqrtN)*sqrtN != blk){
            blk = pl = pr = (x.l/sqrtN)*sqrtN; //first element of block
            pr--;
            memset(bit, 0, sizeof(bit));
            ans = 0;
        }
        while(pr < x.r) addright();
        while(pl < x.l) remleft();
        while(pl > x.l) addleft();
        ansq[x.i] = ans;
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //freopen("out", "w", stdout); //test input
    int m, q;
    cin >> m >> q;
    vector<int> a(m);
    indx.resize(m);
    for(int i=0;i<m;i++){
        cin >> a[i];
    }
    auto v = a;
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    n = v.size();
    map<int, int> mp; //value -> index; 1-based
    int ind = 0;
    for(auto x : v){
        mp[x] = ++ind;
    }
    for(int i=0;i<m;i++){
        indx[i] = mp[a[i]];
    }
    vq.resize(q);
    for(int i=0;i<q;i++){
        int l, r;
        cin >> l >> r;
        vq[i].l = l;
        vq[i].r = r - 1;
        vq[i].i = i;
    } 
    sort(vq.begin(), vq.end());
    Mo();
    for(int i=0;i<q;i++) cout << ansq[i] << "\n";
    
}
