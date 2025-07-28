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
    // freopen("out", "w", stdout); //test input
    int n;
    cin >> n;
    vector<pair<ll, string>> vp(n);
    vector<string> rev(n);
    priority_queue<pair<ll, string>, vector<pair<ll, string>>, greater<pair<ll, string>>> pq;
    map<string, ll> mp;

    for(int i=0;i<n;i++){
        cin >> vp[i].second >> vp[i].first;
        rev[i] = vp[i].second;
        reverse(rev[i].begin(), rev[i].end());
    }


    for(int i=0;i<n;i++){
        pq.push(vp[i]);
        if(!mp.count(vp[i].second)) mp[vp[i].second] = vp[i].first;
        else if(mp[vp[i].second] > vp[i].first) mp[vp[i].second] = vp[i].first;
    }
    while(pq.size()){
        auto [u, str] = pq.top();
        // cout << str << " " << u << "\n";
        pq.pop();
        if(mp[str] != u) continue;
        //check if is prefix of some
        bool isp = false;
        for(int j=0;j<n;j++){
            if(rev[j].size() > str.size() && rev[j].substr(0, str.size()) == str) isp = true;
        }
        //try reduc
        for(int j=0;j<n;j++){
            if(str.size() >= rev[j].size() && str.substr(0, rev[j].size()) == rev[j]){
                string rem;
                for(int i=rev[j].size();i<str.size();i++) rem += str[i];
                if((!mp.count(rem)) || mp[rem] > u + vp[j].first){
                    mp[rem] = u + vp[j].first;
                    pq.push({u + vp[j].first, rem});
                }
            }
        }
        if(isp){
            for(int j=0;j<n;j++){
                string cs = str + vp[j].second;
                ll cv = u + vp[j].first;
                if((!mp.count(cs)) || mp[cs] > cv){
                    mp[cs] = cv;
                    pq.push({cv, cs});
                }
            }
        }
    }
    ll ans = INF_LL;
    for(auto [str, val] : mp){
        string cur = str;
        reverse(cur.begin(), cur.end());
        if(cur == str) ans = min(ans, val);
    }
    if(ans != INF_LL)  cout << ans << "\n";
    else cout << "-1\n";
}       
