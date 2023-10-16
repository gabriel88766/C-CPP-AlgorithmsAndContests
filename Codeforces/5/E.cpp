#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    ll ans = 0;
    deque<pair<int,int>> dq;
    for(int i=0;i<n;i++){
        while(!dq.empty() && dq.back().first < v[i]){
            dq.pop_back();
        }
        dq.push_back({v[i], i});
    }
    for(int i=0;i<n;i++){
        if(dq.front().second == i) dq.pop_front();
        while(!dq.empty() && dq.back().first < v[i]){
            ans++;
            dq.pop_back();
        }
        int k = dq.size() - 1;
        if(k >= 0){
            for(int j=n/2; j>= 1; j/=2){
                while(k-j >= 0 && dq[k-j].first == dq.back().first) k -= j;
            }
            ans += dq.size() - k;
            if(dq[k].first == v[i] && k) ans++;
        }
        dq.push_back({v[i], i});
        //cout << ans << " ";
    }
    int gr = 0;
    for(int i=0;i<n;i++) gr = max(gr, v[i]);
    int sgr = 0;
    for(int i=0;i<n;i++) if(v[i] != gr) sgr = max(sgr, v[i]);
    ll cnt1 = 0, cnt2 = 0;
    for(int i=0;i<n;i++){
        if(v[i] == gr) cnt1++;
        if(v[i] == sgr) cnt2++;
    }
    ans -= (cnt1*(cnt1-1))/2;
    ans -= cnt2;
    cout << ans << "\n";

}
