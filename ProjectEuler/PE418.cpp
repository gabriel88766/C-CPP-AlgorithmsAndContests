#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<ll> pr = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43};
vector<ll> xp(pr.size());
const int N = 43;

//it is easy to prove 2*a >= c, and 2*a >=b, then a^3 >= 43!/4
//also c <= 2*a and c <= 2*b then c^3 <= 4 * 43!

ll lb = 247'188'859'180'748'009LL;
ll ub = 622'876'893'962'647'981LL;
// ll lb = 847269;
// ll ub = 2134985; 
vector<ll> alln;
void find_all(ll pd = 1, int i = 0){
    if(i == pr.size() && pd >= lb && pd <= ub){
        alln.push_back(pd);
        return;
    }else if(i == pr.size()) return;
    ll nf = 1;
    for(int j=0;j<=xp[i];j++){
        if(INF_LL/pd > nf){
            find_all(pd*nf, i+1);
        }else break;
        nf *= pr[i];
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll divt = 1;
    for(int i=0;i<pr.size();i++){
        ll x = 1;
        while(x * pr[i] <= N){
            x *= pr[i];
            xp[i] += N / x;
        }
    }
    find_all();
    sort(alln.begin(), alln.end());
    cout << alln.size() << "\n";
    pair<__int128, __int128> bf = {3000, 10};
    ll ans = 0;
    for(int i=0;i<alln.size();i++){ //alln.size() = 4919553
        //alln[i] = b
        if(i % 100000 == 0) cout << i << endl;
        for(int j=i;j>=0;j--){
            vector<ll> cf = xp;
            ll n1 = alln[j];
            ll n2 = alln[i];
            ll n3 = 1;
            for(int k=0;k<xp.size();k++){
                while(n1 % pr[k] == 0){
                    n1 /= pr[k];
                    cf[k]--;
                }
                while(n2 % pr[k] == 0){
                    n2 /= pr[k];
                    cf[k]--;
                }
                if(cf[k] < 0){
                    n3 = -1;
                    break;
                }else{
                    for(int xx=1;xx<=cf[k];xx++) n3 *= pr[k];
                }
            }
            n1 = alln[j];
            n2 = alln[i];
            if(n3 == -1) continue;
            else{
                if(n3 >= n2 && n2 >= n1){
                    pair<__int128, __int128> cur = {n3, n1}; //frac cur < frac bf.
                    if(cur.first * bf.second < cur.second * bf.first){
                        bf = cur;
                        ans = n1 + n2 + n3;
                    }
                }
                break;
            }
        }
    }
    cout << ans << "\n";
}
