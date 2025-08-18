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
    string s;
    ll k;
    cin >> s >> k;
    int n = s.size();
    int cnt = 0;
    for(auto c : s) if(c == 'Y') cnt++;
    if(!cnt) cout << "0\n";
    else{
        int lo = 1, hi = cnt;
        vector<ll> df;
        int lst = -1;
        for(int i=0;i<n;i++){
            if(s[i] == 'Y'){
                if(lst != -1) df.push_back(i - lst - 1);
                lst = i;
            }
        }
        // for(auto x : df) cout << x << " ";
        // cout << "\n";
        while(lo != hi){
            int mid = lo + (hi - lo + 1) / 2;
            //mid isn't 1
            //if 7: 1 2 3 3 2 1 
            //if 8: Y 1 Y 2 Y 3 Y 4 Y 3 Y 2 Y 1 Y
            int hf = mid / 2;
            vector<ll> tl(df.size());
            vector<ll> tr(df.size());
            vector<ll> ps(df.size());
            vector<ll> aps(df.size());
            for(int i=0;i<df.size();i++){
                ps[i] = df[i];
                if(i != 0) ps[i] += ps[i-1];
            }
            for(int i=df.size()-1;i>=0;i--){
                aps[i] = df[i];
                if(i != df.size() - 1) aps[i] += aps[i+1];
            }
            ll cur = 0;
            // cout << "\n";
            for(int i=0;i<df.size();i++){
                cur += df[i] * (hf + 1);
                cur -= ps[i];
                if(i>= hf + 1) cur += ps[i-hf-1];
                if(i + 1 >= hf) tl[i] = cur;
                else tl[i] = INF_LL;
                // cout << tl[i] << " ";
            }
            // cout << "\n";
            cur = 0;
            for(int i=df.size()-1;i>=0;i--){
                cur += df[i] * (hf + 1);
                cur -= aps[i];
                if(i + hf + 1 < df.size()) cur += aps[i + hf + 1];
                if(i + hf <= df.size()) tr[i] = cur;
                else tr[i] = INF_LL;
                // cout << tr[i] << " ";
            }
            // cout << "\n";
            ll mn = INF_LL;
            if(mid % 2){
                for(int i=1;i<df.size();i++){
                    mn = min(mn, tl[i-1] + tr[i]);
                }
            }else{
                for(int i=0;i<df.size();i++){
                    mn = min(mn, tl[i] + tr[i] - hf * df[i]);
                }
            }
            if(mn <= k) lo = mid;
            else hi = mid - 1;
        }
        cout << lo << "\n";
    }
}

