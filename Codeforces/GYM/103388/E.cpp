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
    vector<int> v[3];
    for(int i=0;i<n;i++){
        int t, x;
        cin >> t >> x;
        v[x].push_back(t);
    }
    sort(v[0].begin(), v[0].end(), greater<int>());
    sort(v[1].begin(), v[1].end(), greater<int>());
    int s = 0, st = 0;
    while(v[0].size() || v[1].size()){
        while(v[s].size() && v[s].back() < st){
            st = v[s].back() + 10;
            v[s].pop_back();
        }
        if(v[0].size() && v[1].size()){
            if(v[0].back() < v[1].back()) s = 0;
            else s = 1;
            bool ok = false;
            while(v[s].size() && v[s].back() <= st){
                ok = true;
                v[s].pop_back();
            }
            if(ok){
                st += 10;
            }else{
                st = v[s].back() + 10;
                v[s].pop_back();
            }
        }else if(v[0].size()){
            st = max(st, v[0][0]) + 10;
            break;
        }else{
            st = max(st, v[1][0]) + 10;
            break;
        }
        
    }
    cout << st << "\n";
}
