#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int v[N];

bool custom_f(int a, int b){
    return v[a] < v[b];
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, k;
    cin >> n >> k;
    vector<int> ord;
    for(int i=1;i<=n;i++){
        ord.push_back(i);
        cin >> v[i];
    }
    sort(ord.begin(), ord.end(), custom_f);
    vector<int> ans(n+1);
    int cnt = 0;
    ans[ord[0]] = 0;
    for(int i=1;i<n;i++){
        int j = ord[i], k = ord[i-1];
        if(v[k] < v[j]) cnt = i;
        ans[j] = cnt;
    }
    for(int i=0;i<k;i++){
        int a,b;
        cin >> a >> b;
        if(v[a] > v[b]) ans[a]--;
        else if(v[a] < v[b]) ans[b]--;
    }


    for(int i=1;i<=n;i++) cout << ans[i] << " ";
}
