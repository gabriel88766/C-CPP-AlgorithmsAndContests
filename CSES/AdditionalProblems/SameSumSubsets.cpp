#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int M = 45;
ll v[M];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> v[i];
    int hf = n/2;
    vector<pair<ll, ll>> s1, s2;
    for(int i=0;i<(1 << hf);i++){
        ll cs = 0;
        for(int j=0;j<hf;j++){
            if(i & (1 << j)){
                cs += v[j];
            }
        }
        s1.push_back({cs, i});
    }
    for(int i=0;i<(1 << (n-hf)); i++){
        ll cs = 0;
        for(int j=hf;j<n;j++){
            if(i & (1 << (j-hf))){
                cs += v[j];
            }
        }
        s2.push_back({cs, i});
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    map<ll, ll> cache;
    auto getLower = [&](ll k){
        if(cache.count(k)) return cache[k];
        ll ans = -1;
        int p1 = 0, p2 = s2.size() - 1;
        while(p1 < s1.size()){
            while(p2 >= 0 && s1[p1].first + s2[p2].first > k) p2--; 
            ans += p2;
            p1++;
        }
        return cache[k] = ans;
    };
    ll lo = 1, hi = 0;
    for(int i=0;i<n;i++) hi += v[i];
    while(lo != hi){
        ll mid = lo + (hi - lo)/2;
        if(getLower(mid) - getLower(lo-1) > mid - lo + 1) hi = mid;
        else lo = mid + 1;
    }
    int p1 = 0, p2 = s2.size() - 1;
    vector<ll> ann;
    while(p1 < s1.size() && p2 >= 0){
        if(s1[p1].first + s2[p2].first > lo) p2--;
        else if(s1[p1].first + s2[p2].first < lo) p1++;
        else{
            ann.push_back({s1[p1].second + (s2[p2].second << hf)});
            if(p1 + 1 < s1.size() && s1[p1].first == s1[p1+1].first) p1++; //hidden logic
            else if(p2 - 1 >= 0 && s2[p2].first == s2[p2-1].first) p2--;
            else p1++, p2--;
        }
    }
    assert(ann.size() >= 2);
    ll a1 = ann[0], a2 = ann[1];
    ll inter = a1 & a2;
    a1 ^= inter;
    a2 ^= inter;
    assert(a1 && a2);
    cout << __builtin_popcountll(a1) << "\n";
    for(int i=0;i<n;i++){
        if(a1 & (1LL << i)) cout << v[i] << " ";
    }
    cout << "\n";
    cout << __builtin_popcountll(a2) << "\n";
    for(int i=0;i<n;i++){
        if(a2 & (1LL << i)) cout << v[i] << " ";
    }
    cout << "\n";
}
