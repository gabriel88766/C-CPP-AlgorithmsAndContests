#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5e5+6;
int pr0[4*N], pr1[4*N], su0[4*N], su1[4*N], mid1[4*N], mid0[4*N], lz[4*N];
int v[N];
int n;

void build(int l = 1, int r = n, int p = 1){
    if(l == r){ 
        if(v[l] == 1) pr1[p] = su1[p] = mid1[p] = 1; 
        else pr0[p] = su0[p] = mid0[p] = 1; 
        return; 
    }
    build(l, (l+r)/2, 2 * p);
    build((l+r)/2 + 1, r, 2 * p + 1);
    pr0[p] = pr0[2*p] == ((l+r)/2 - l + 1) ? pr0[2*p] + pr0[2*p+1] : pr0[2*p];
    pr1[p] = pr1[2*p] == ((l+r)/2 - l + 1) ? pr1[2*p] + pr1[2*p+1] : pr1[2*p];
    su0[p] = su0[2*p+1] == (r - (l+r)/2) ? su0[2*p] + su0[2*p+1] : su0[2*p+1];
    su1[p] = su1[2*p+1] == (r - (l+r)/2) ? su1[2*p] + su1[2*p+1] : su1[2*p+1];
    mid0[p] = max(mid0[2*p], max(mid0[2*p+1], su0[2*p] + pr0[2*p+1])); 
    mid1[p] = max(mid1[2*p], max(mid1[2*p+1], su1[2*p] + pr1[2*p+1]));
}

void push(int l, int r, int p){
    if(lz[p]){ //0 can be assigned? change!
        swap(pr0[p], pr1[p]);
        swap(su0[p], su1[p]);
        swap(mid0[p], mid1[p]);
        if(l != r){
            lz[2 * p] ^= lz[p]; // += increment = update
            lz[2 * p + 1] ^= lz[p];
        } 
        lz[p] = 0;
    }
}

struct Interval{
    int l, r, p;
    bool operator< (const Interval in) const{
        return l < in.l;
    }
};
vector<Interval> vq;

void query(int i, int j, int l = 1, int r = n, int p = 1){
    push(l, r, p);
    if(j < l || i > r) return;//identity element
    if(j >= r && i <= l){
        vq.push_back({l, r, p});
        return;
    }
    query(i, j, l, (l + r)/2, 2 * p);
    query(i, j, (l + r)/2 + 1, r, 2 * p + 1); //some operation
}

void update(int i, int j, int l = 1, int r = n, int p = 1){
    push(l, r, p);
    if(j < l || i > r) return;
    if(l >= i && r <= j) {lz[p] = 1; push(l, r, p); return;}
    update(i, j, l, (l + r)/2, 2 * p);
    update(i, j, (l + r)/2 + 1, r, 2 * p + 1);
    pr0[p] = pr0[2*p] == ((l+r)/2 - l + 1) ? pr0[2*p] + pr0[2*p+1] : pr0[2*p];
    pr1[p] = pr1[2*p] == ((l+r)/2 - l + 1) ? pr1[2*p] + pr1[2*p+1] : pr1[2*p];
    su0[p] = su0[2*p+1] == (r - (l+r)/2) ? su0[2*p] + su0[2*p+1] : su0[2*p+1];
    su1[p] = su1[2*p+1] == (r - (l+r)/2) ? su1[2*p] + su1[2*p+1] : su1[2*p+1];
    mid0[p] = max(mid0[2*p], max(mid0[2*p+1], su0[2*p] + pr0[2*p+1])); 
    mid1[p] = max(mid1[2*p], max(mid1[2*p+1], su1[2*p] + pr1[2*p+1]));
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int q;
    cin >> n >> q;
    string str;
    cin >> str;
    for(int i=0;i<n;i++){
        v[i+1] = str[i] - '0';
    }
    build();
    for(int i=0;i<q;i++){
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1){
            update(l, r);
        }else{
            vq.clear();
            query(l, r);
            sort(vq.begin(), vq.end());
            int ans = 0, cur = 0;
            for(auto x : vq){
                if(pr1[x.p] == x.r-x.l+1){
                    cur += pr1[x.p];
                    ans = max(ans, cur);
                }else{
                    cur += pr1[x.p];
                    ans = max(ans, cur);
                    ans = max(ans, mid1[x.p]);
                    cur = su1[x.p];
                }
            }
            cout << ans << "\n";
        }
    }
}
