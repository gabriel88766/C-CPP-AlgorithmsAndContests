#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
int p[N], sz[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    init();
    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        unite(a,b);
    }
    set<int> acc;
    vector<int> v;
    for(int i=1;i<=n;i++){
        if(!acc.count(get(i))){
            acc.insert(get(i));
            v.push_back(sz[get(i)]);
        }
    }
    sort(v.begin(), v.end());

    //knapsack 3k + bitset (double optimization) O(Sqrt(N)*N/64 + NlogN)
    map<int,int> mp;
    set<int> st;
    for(int i=0;i<v.size();i++){
        mp[v[i]]++;
        st.insert(v[i]);
    }
    vector<pair<int,int>> kn;
    for(auto x : st){
        if(mp[x] >= 3){
            int k = (mp[x]-1)/2;
            st.insert(2*x);
            mp[2*x] += k;
            mp[x] -= 2*k;
        }
        kn.push_back({x, mp[x]});
    }
    bitset<100005> dp;
    dp[0] = 1;
    for(int i = 0;i < kn.size();i++){ //at most sqrt(N)
        for(int k=1; k <=kn[i].second; k++){
            int x = kn[i].first;
            dp |= (dp << x);
        }
    }
    for(int i=1;i<=n;i++){
        if(dp[i]) cout << "1";
        else cout << "0";
    }
}