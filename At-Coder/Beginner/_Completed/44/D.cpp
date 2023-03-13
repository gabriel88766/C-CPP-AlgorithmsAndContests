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
    ll n, s;
    cin >> n >> s;
    if(s > n) cout << "-1";
    else if(s == n) cout << n+1;
    else{
        //1st case, a0 + a1b + a2b^2 + ....., b^2 <= n
        for(ll b=2;b*b <= n; b++){
            ll sdig = 0;
            ll aux = 1;
            vector<ll> pot = {1};
            while(aux <= n/b){
                aux *= b;
                pot.emplace_back(aux);
            }
            aux = n;
            for(int i=pot.size()-1;i>=0;i--){
                sdig += aux/pot[i];
                aux -= (aux/pot[i])*pot[i];
            }
            if(sdig == s){
                cout << b;
                return 0;
            }
        }
        //2nd case: a0 + b*a1
        //find all divs of n-s, d = b-1, d >= a1 => d >= (n-s)/d
        vector<ll> divs;
        for(ll i=1;i*i <= (n-s); i++){
            if(!((n-s)%i)) divs.push_back((n-s)/i);
        }
        reverse(divs.begin(), divs.end());
        for(int i=0;i<divs.size();i++){
            ll a1 = (n-s)/divs[i];
            ll b = divs[i]+1;
            ll a0 = s - a1;
            if(a0 < b && a0 >= 0){
                cout << b << "\n";
                return 0;
            }
        }
        cout << -1;
    }
}
