#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    map<int,int> mp;
    vector<int> v;
    ll L = 0, H = 0;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int aux;
        cin >> aux;
        v.push_back(aux);
        mp[aux]++;
    }
    for(int i=0;i<n;i++){
        if(mp[v[i]] >= 2){
            mp[v[i]] -= 2;
            if(v[i] >= H) L=H, H=v[i];
            else if(v[i] > L) L = v[i];
        }
    }
    cout << L*H;
}
