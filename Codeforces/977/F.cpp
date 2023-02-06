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
    //freopen("in", "r", stdin); test input
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    vector<int> p(n+1), qt(n+1);
    map<int,int> mp;
    int ans, maxqt = 0;
    for(int i=1;i<=n;i++){
        mp[a[i]] = i;
        if(mp[a[i]-1]){
            p[i] = mp[a[i]-1];
            qt[i] = qt[p[i]] + 1;
        }else{
            p[i] = -1;
            qt[i] = 1;
        }
        if(qt[i] > maxqt){
            maxqt = qt[i];
            ans = i;
        }
    }
    vector<int> vans;
    vans.push_back(ans);
    while(p[ans] != -1){
        ans = p[ans];
        vans.push_back(ans);
    }
    reverse(vans.begin(), vans.end());
    cout << vans.size() << "\n";
    for(int i=0;i<vans.size();i++) cout << vans[i] << " ";
    cout << "\n";
}
