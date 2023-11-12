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
    sort(v.begin(), v.end());
    int minv = 0, maxv = 0;
    map<int,int> mp, mp2;
    for(int i=0;i<n;i++){
        if(!mp.count(v[i] - 1)){
            mp[v[i] - 1] = 1;
            maxv++;
        }else if(!mp.count(v[i])){
            mp[v[i]] = 1;
            maxv++;
        }else if(!mp.count(v[i] + 1)){
            mp[v[i] + 1] = 1;
            maxv++;
        }

        if(mp2.count(v[i] - 1) || mp2.count(v[i]) || mp2.count(v[i] + 1)); //ok
        else{
            mp2[v[i] + 1] = 1;
            minv++;
        }
    }
    cout << minv << " " << maxv << "\n";
}
