#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

template<typename T, T (*op)(T, T), T (*nullel)()>
struct SegmentTree{
    vector<T> st;
    int n;
    SegmentTree(vector<T> &v){
        n = v.size();
        st.resize(4*n);
        build(v, 0, n-1, 1);
    }
    SegmentTree(ll sz){
        n = sz;
        st.resize(4*n);
    }
    void build(vector<T> &v, int l, int r, int p){
        if(l == r){st[p] = v[l]; return;}
        build(v, l, (l+r)/2, 2*p);
        build(v, (l+r)/2+1, r, 2*p+1);
        st[p] = op(st[2*p], st[2*p+1]);
    }
    T query(int i, int j, int l, int r, int p){
        if(j < l || i > r) return nullel(); 
        if(j >= r && i <= l) return st[p];
        return op(query(i, j, l, (l + r)/2, 2 * p), query(i, j, (l + r)/2 + 1, r, 2 * p + 1)); 
    }
    T query(int i, int j){
        return query(i, j, 0, n-1, 1);
    }
    void update(int i, T value, int l, int r, int p){
        if(i < l || i > r) return;
        if(l == r) {st[p] = value; return;}
        update(i, value, l, (l + r)/2, 2 * p);
        update(i, value, (l + r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); //some operation
    }
    void update(int i, T value){
        update(i, value, 0, n-1, 1);
    }
    int find(int i, int x, int l, int r, int p){
        if(i > r) return INF_INT;
        if(l == r){
            if(st[p] >= x) return l;
            else return INF_INT;
        }
        if(st[2*p] >= x){
            int ans = find(i, x, l, (l + r)/2, 2 * p);
            if(ans != INF_INT) return ans;
            else return find(i, x, (l + r)/2 + 1, r, 2 * p + 1);
        }else if(st[2*p+1] >= x){
            return find(i, x, (l + r)/2 + 1, r, 2 * p + 1);
        }else return INF_INT;
    }
    int find(int i, int x){
        return find(i, x, 0, n-1, 1);
    }
};


int op(int a, int b){
    return max(a, b);
}

int el(){
    return 0;
}

int dp[1 << 17];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<SegmentTree<int, op, el>> st(k, SegmentTree<int, op, el>(n));
    for(int i=0;i<k;i++){
        int cs = 0;
        for(int j=0;j<n;j++){
            if(s[j] == '?' || s[j] == ('a' + i)) cs++;
            else cs = 0;
            st[i].update(j, cs);
        }
    }
    int lo = 0, hi = n;
    auto check = [&](int val){
        for(int j=0;j<(1 << k);j++) dp[j] = INF_INT;
        dp[0] = -1;
        for(int i=0;i<(1 << k) - 1;i++){
            if(dp[i] < INF_INT){
                for(int j=0;j<k;j++){
                    if(i & (1 << j)) continue;
                    int mn = dp[i] + val;
                    if(mn > n-1) continue;
                    int x = st[j].find(mn, val);
                    // cout << i << " " << mn << " " << x << "\n";
                    dp[i | (1 << j)] = min(dp[i | (1 << j)], x);
                }
            }   
        }
        return dp[(1 << k) - 1] < n;
    };
    while(lo != hi){
        int mid = lo + (hi - lo + 1) / 2;
        if(check(mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
}
