#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3; 
int n, c;
// n log n
vector<int> suffix_array(string &s){
    s += "$";
    n = s.size(), c=-1;
    vector<int> mp(n), cnt(max(n+1, 256)), mp2(256), aux(n); 
    vector<pair<int,int>> cs(n); // class,class <int,int>

    for(int i=0;i<n;i++) cnt[s[i]]++;
    for(int i=0;i<256;i++){
        if(cnt[i]) mp2[i] = ++c;
        if(i) cnt[i] += cnt[i-1];
    } 
    for(int i=0;i<n;i++) mp[--cnt[s[i]]] = i; 
    for(int i=0;i<n;i++) cs[i].first = mp2[s[i]];

    for(int i=0;(1 << i) < n;i++){
        fill(cnt.begin(), cnt.begin() + c + 2, 0);
        int offset = 1 << i;
        for(int j=0;j<n;j++){
            int mindex = (j + offset) >= n ? j + offset - n : j + offset;
            cs[j].second = cs[mindex].first;
            cnt[cs[j].second + 1]++;
        }
        //begin raddix_sort of pair O👎
        for(int j=2; j<=(c+1); j++) cnt[j] += cnt[j-1];
        for(int j=0; j<n; j++) aux[cnt[cs[j].second]++] = j;
        fill(cnt.begin(), cnt.begin() + c + 2, 0);
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

const int M = 18;
ll sparse[N][M];
vector<int> v;

void build(){
    int n = v.size();
    for(int i=0;i<n;i++) sparse[i][0] = v[i];
    for(int j = 1; j < M; j++){
        for(int i = 0; i < n; i ++){
            if((i + (1 << (j-1))) < n) sparse[i][j] = min(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
            else sparse[i][j] = sparse[i][j-1];
        }
    }
}

ll query(int a, int b){
    if(a == b) return sparse[a][0]; //bug
    int pot = 32 - __builtin_clz(b - a) - 1; 
    return min(sparse[a][pot], sparse[b - (1 << pot) + 1][pot]);
}

//P 745
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("p067.txt", "r", stdin); //test input
    string s;
    ll k;
    cin >> s >> k;
    auto sa = suffix_array(s);
    v = lcp(s, sa);
    v.push_back(0); //lcp between last sa and next (doesnt exist)
    build();
    ll cnt = 0, l = 1, r = s.size() - 1, p = 0;
    vector<ll> ps(r+1, 0);
    for(int i=1;i<=r;i++){ ps[i] = ps[i-1] + r-sa[i];}
    string ans;
    while(true){
        int d = l;
        for(int i = n; i>=1; i >>= 1){
            while(d+i <= r && query(l, d+i) >= (1+p)) d += i;
        }
        if(v[d] >= (1+p)) d++;
        ll qt = (ps[d] - ps[l-1]-p*(d-l+1));
        if(qt + cnt >= k){
            r = d;
            ans += s[sa[l]+p];
            cnt += d-l+1;
            if(cnt >= k){
                cout << ans << "\n";
                return 0;
            }
            p++;
            if(p == ps[l]-ps[l-1]) l++;
        }else{
            cnt += qt;
            l = d+1;
        }
    }
    
}