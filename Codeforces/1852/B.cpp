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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<pair<int,int>> s;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int b;
            cin >> b;
            s.insert({b, i});
        }
        bool ok = true;
        int cnt1 = 0, cnt2 = 0;
        for(int i=n;i>=1;i--){
            int maxv = n-cnt2;
            int minv = cnt1;
            auto it1 = s.lower_bound({maxv, 0});
            auto it2 = s.lower_bound({minv, 0});
            bool ok1 = false, ok2 = false;
            if(it1 != s.end() && it1->first == maxv) ok1 = true;
            if(it2 != s.end() && it2->first == minv) ok2 = true;
            if(ok1 && ok2){
                ok = false;
                break;
            }else if(ok1 || ok2){
                if(ok1){
                    cnt1++;
                    ans[it1->second] = i;
                    s.erase(it1);
                }else{
                    cnt2++;
                    ans[it2->second] = -i;
                    s.erase(it2);
                }
            }else{
                ok = false;
                break;
            }
        }
        if(ok){
            cout << "YES\n";
            for(auto x : ans) cout << x << " ";
            cout << "\n";
        }else{
            cout << "NO\n";
        }
    }
}
