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
    vector<int> v(n+1);
    int sd = 0;
    int md = n, id = -1;
    for(int i=1;i<=n;i++) {
        cin >> v[i];
        sd += v[i];
        if(v[i] < md){
            md = v[i];
            id = i;
        }
    }
    if(md == 2){
        cout << "YES" << " " << n-1 << "\n";
        cout << n-1 << "\n";
        for(int i=1;i<n;i++){
            cout << i << " " << i+1 << "\n";
        }
    }else if(sd < 2*n - 2) cout << "NO\n";
    else{
        int cr = id; //is 1 dg
        int d = 0;
        vector<pair<int,int>> ans;
        vector<int> ms, chk;
        for(int i=1;i<=n;i++){
            if(i == id) continue;
            if(v[i] >= 2){
                v[cr]--;
                v[i]--;
                d++;
                ans.push_back({cr, i});
                cr = i;
                chk.push_back(i);
            }else ms.push_back(i);
        }
        if(ans.size() == n-1){
            cout << "YES" << " " << n-1 << "\n" << n-1 << "\n";
            for(auto [a, b] : ans) cout << a << " " << b << "\n";
        }else{
            ans.push_back({cr, ms.back()});
            v[cr]--;
            d++;
            ms.pop_back();
            for(auto x : ms){
                while(v[chk.back()] == 0) chk.pop_back();
                ans.push_back({x, chk.back()});
                v[chk.back()]--;
            }
            cout << "YES" << " " << d << "\n" << n-1 << "\n";
            for(auto [a, b]: ans) cout << a << " " << b << "\n";
        }
    }

}
