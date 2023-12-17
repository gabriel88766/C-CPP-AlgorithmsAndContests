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
    vector<pair<int,int>> act(n+1);
    vector<vector<int>> pot(n+1);
    vector<char> used(n+1, false);
    bool ok = true;
    for(int i=1;i<=n;i++){
        cin >> act[i].first >> act[i].second;
        if(act[i].first == 1){
            pot[act[i].second].push_back(i);
        }else{
            if(pot[act[i].second].size()){
                used[pot[act[i].second].back()] = true;
                pot[act[i].second].pop_back();
            }else{
                ok = false;
            }
        }
    }
    if(!ok){
        cout << "-1\n";
        return 0;
    }
    int ans = 0, cnt = 0;
    for(int i=1;i<=n;i++){
        if(act[i].first == 1){
            if(used[i]) cnt++; 
        }else cnt--;
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
    for(int i=1;i<=n;i++){
        if(act[i].first == 1){
            if(used[i]) cout << "1 ";
            else cout << "0 ";
        }
        
    }
    cout << "\n";
}
