#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N =2e5+3;
int cnt[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        cnt[aux]++;
    }
    vector<int> v;
    for(int i=0;i<N;i++){
        if(cnt[i]) v.push_back(cnt[i]);
    }
    sort(v.begin(), v.end(), greater<int>());
    int ans = n;
    for(int i=0;i<min(k, (int)v.size());i++){
        ans -= v[i];
    }
    cout << ans;
}
