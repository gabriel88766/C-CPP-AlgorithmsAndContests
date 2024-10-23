#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 4e6;
const int M = 30;
int trie[N][2];
int sz[N];
int idx[N];
int cnt = 0;


void insert(int num, int j){
    int cur = 0;
    for(int i=M-1;i >= 0; i--){
        sz[cur]++;
        idx[cur] = j;
        if(trie[cur][(num & (1 << i)) >> i]){
            cur = trie[cur][(num & (1 << i)) >> i];
        }else cur = trie[cur][(num & (1 << i)) >> i] = ++cnt;
    }
    sz[cur]++;
    idx[cur] = j;
}
int findxor(int mv, int num, int lv, int cx, int p){
    //try to find some index with xor num^a[j] lower than mv
    if(cx >= mv) return -1;
    int cur = (1 << (lv+1)) - 1 + cx;
    if(cur < mv) return idx[p];


    if(trie[p][0] && trie[p][1]){
        if(num & (1 << lv)) return max(findxor(mv, num, lv-1, cx | (1 << lv), trie[p][0]), findxor(mv, num, lv-1, cx, trie[p][1]));
        else return max(findxor(mv, num, lv-1, cx, trie[p][0]), findxor(mv, num, lv-1, cx | (1 << lv), trie[p][1]));
    }else if(trie[p][0]){
        if(num & (1 << lv)) return findxor(mv, num, lv-1, cx | (1 << lv), trie[p][0]);
        else return findxor(mv, num, lv-1, cx, trie[p][0]);
    }else{
        if(num & (1 << lv)) return findxor(mv, num, lv-1, cx, trie[p][1]);
        else return findxor(mv, num, lv-1, cx | (1 << lv), trie[p][1]);
    }
}
int findxor(int mv, int num){
    return findxor(mv, num, M-1, 0, 0);
}

void clear(){
    for(int i=0;i<=cnt;i++) trie[i][0] = trie[i][1] = sz[i] = idx[i] = 0;
    cnt = 0;
}




//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++) cin >> a[i];
        
        ll tt = n * (n-1);
        tt /= 2;
        auto solve = [&](int x){
            vector<int> mxv(n+1);
            clear();
            for(int i=1;i<=n;i++){
                mxv[i] = findxor(x, a[i]);
                insert(a[i], i);
            }
            ll qnt = 0;
            int p1 = 1, p2 = 1;
            while(p1 <= n && p2 <= n){
                while(p2+1 <= n && mxv[p2+1] < p1) p2++;
                qnt += p2 - p1;
                p1++;
            }
            return qnt;
        };
        int lo = 0, hi = (1 << 30)-1;
        while(lo != hi){
            int mid = lo + (hi - lo + 1)/2;
            if(solve(mid) >= (tt-k+1)) lo = mid;
            else hi = mid - 1;
        }
        cout << lo << "\n";
    }
}
