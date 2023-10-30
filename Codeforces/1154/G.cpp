#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e7;
int cnt[N+2];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    ll minv = INF_LL;
    pair<ll,ll> ans;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        cnt[v[i]]++;
    }
    for(int i=1;i<=N;i++){
        ll fi = -1, si = -1;
        for(int j=i;j<=N;j += i){
            if(cnt[j]){
                if(cnt[j] >= 2 && fi == -1){
                    if(i == j) si=fi=j;
                    break;
                }else if(fi == -1) fi = j;
                else{
                    si = j;
                    break;
                } 
            }
        }
        if(fi != -1 && si != -1){
            if((fi/i)*si < minv){
                minv = (fi/i)*si;
                ans = {fi, si};
            }
        }
    }
    int ind1 = -1, ind2 = -1;
    for(int i=1;i<=n;i++) if(ans.first == v[i]){ ind1 = i; break;}
    for(int i=1;i<=n;i++) if(ans.second == v[i] && i != ind1) {ind2 = i; break;}
    if(ind1 > ind2) swap(ind1, ind2);
    cout << ind1 << " " << ind2 << "\n";
}   
