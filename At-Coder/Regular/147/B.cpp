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
    vector<int> pr(n+1);
    for(int i=1;i<=n;i++) cin >> pr[i];
    int cnt = 0, c1 = 0;
    for(int i=1;i<=n;i++){
        if(pr[i] % 2 != i % 2){
            cnt++;
            if(i % 2) c1++;
        }
    }
    assert(cnt % 2 == 0);
    assert(2*c1 == cnt);
    vector<pair<char, int>> ans;
    while(c1--){
        int od = -1, ev = -1;
        for(int i=1;i<=n;i++){
            if(pr[i] % 2 != i % 2){
                if(i % 2 == 0) od = i;
                else ev = i;
            }
        }
        if(ev > od){
            while(ev - 2 > od){
                ans.push_back({'B', ev - 2});
                swap(pr[ev-2], pr[ev]);
                ev -= 2;
            }
            assert(od + 1 == ev);
            ans.push_back({'A', od});
            swap(pr[od], pr[ev]);
        }else{
            while(od - 2 > ev){
                ans.push_back({'B', od - 2});
                swap(pr[od-2], pr[od]);
                od -= 2;
            }
            assert(ev + 1 == od);
            ans.push_back({'A', ev});
            swap(pr[od], pr[ev]);
        }
    }    
    for(int i=1;i<=n;i++){
        if(pr[i] != i){
            int id = -1;
            for(int j=i;j<=n;j+=2){
                if(pr[j] == i){
                    id = j;
                }
            }
            assert(id != -1);
            while(id != i){
                ans.push_back({'B', id - 2});
                swap(pr[id-2], pr[id]);
                id -= 2;
            }
        }
    }
    cout << ans.size() << "\n";
    for(auto [a, b] : ans){
        cout << a << " " << b << "\n";
    }
}
