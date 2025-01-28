#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 1e6+2; 
int n, c;
// n log n
int cnt[N], aux[N], mp2[256];
pair<int, int> cs[N];
vector<int> suffix_array(string &s){
    s += "$";
    n = s.size(), c=-1;
    vector<int> mp(n);
    for(int i=0;i<n;i++) cnt[s[i]]++;
    for(int i=0;i<256;i++){
        if(cnt[i]) mp2[i] = ++c;
        if(i) cnt[i] += cnt[i-1];
    } 
    for(int i=0;i<n;i++) mp[--cnt[s[i]]] = i; 
    for(int i=0;i<n;i++) cs[i].first = mp2[s[i]];

    for(int i=0;(1 << i) < n;i++){
        fill(cnt, cnt + c + 2, 0);
        int offset = 1 << i;
        for(int j=0;j<n;j++){
            int mindex = (j + offset) >= n ? j + offset - n : j + offset;
            cs[j].second = cs[mindex].first;
            cnt[cs[j].second + 1]++;
        }
        //begin raddix_sort of pair O(n)
        for(int j=2; j<=(c+1); j++) cnt[j] += cnt[j-1];
        for(int j=0; j<n; j++) aux[cnt[cs[j].second]++] = j;
        fill(cnt, cnt + c + 2, 0);
        for(int j=0; j<n; j++) cnt[cs[j].first+1]++; 
        for(int j=2; j<=(c+1); j++) cnt[j] += cnt[j-1];
        for(int j=0; j<n;j++) mp[cnt[cs[aux[j]].first]++] = aux[j]; 
        //end raddix_sort
        aux[mp[0]] = c = 0;
        for(int j=1;j<n;j++){
            if(cs[mp[j]] == cs[mp[j-1]]) aux[mp[j]] = c;
            else aux[mp[j]] = ++c;
        }
        for(int j=0;j<n;j++) cs[j].first = aux[j];
    }
    return mp;
}
//longest common prefix in O(n), between 2 consecutive indexes of suffix array
vector<int> lcp(string &s, vector<int> &sa){
    vector<int> ans(n - 1, 0);
    vector<int> invmp(n, 0);
    for(int i=0;i<n; i++) {invmp[sa[i]] = i;}
    int cnt = 0;
    for(int i=0;i < (n-1); i++){
        if(invmp[i] == (n-1)){
            cnt = 0;
            continue;
        }
        int j = sa[invmp[i] + 1];
        while (s[i+cnt] == s[j+cnt]) cnt++;
        ans[invmp[i]] = cnt;
        if (cnt) cnt--;
    }
    return ans;
}

  
int p[N], sz[N];
vector<pair<int, int>> lcx[N];
vector<int> pad[N];
bool us[N];

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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in", "r", stdin); //test input
    init();
    int n;
    string s;
    cin >> n >> s;
    auto sa = suffix_array(s);
    auto lc = lcp(s, sa);
    ll ans = n;
    for(int i=1;i<lc.size();i++){
        lcx[lc[i]].push_back({i, i+1});
    }
    vector<int> gp;
    for(int i=n;i>=2;i--){
        vector<int> ng;
        vector<int> nv;
        for(auto &[a, b] : lcx[i]){
            unite(a, b);
            if(sz[get(a)] >= i) ng.push_back(get(a));
            else pad[sz[get(a)]].push_back(get(a));
        }
        for(auto &x : gp){
            x = get(x);
            if(!us[x]){
                nv.push_back(x);
                us[x] = true;
            }
        }
        for(auto &x : ng){
            x = get(x);
            if(!us[x]){
                nv.push_back(x);
                us[x] = true;
            }
        }
        for(auto &x : pad[i]){
            x = get(x);
            if(!us[x]){
                nv.push_back(x);
                us[x] = true;
            }
        }
        for(auto &x : nv) us[x] = false;
        gp = nv;
        for(auto &x : gp){
            if(!(sz[x] % i)) ans += sz[x];
        }
    }
    cout << ans << "\n";
}
