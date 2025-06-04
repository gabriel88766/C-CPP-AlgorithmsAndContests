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
    vector<int> v, u;
    for(int i=0;i<(1 << n);i++){
        int x;
        cin >> x;
        v.push_back(x);
        u.push_back(i);
    }
    for(int i=0;i<n;i++){
        if(i+1 == n){
            if(v[u[0]] < v[u[1]]) cout << u[0] + 1 << "\n";
            else cout << u[1] + 1 << "\n";
        }else{
            vector<int> nu;
            for(int i=0;i<u.size();i+=2){
                if(v[u[i]] < v[u[i+1]]) nu.push_back(u[i+1]);
                else nu.push_back(u[i]);
            }
            u = nu;
        }
    }
}
