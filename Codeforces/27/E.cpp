#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> divs;
vector<vector<int>> pos;
ll pr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
ll pot[10][64];
ll maxpot[10];
ll MAXV = 1e18;

void gendivs(int n, vector<int> &cur){
    if(n == 1){
        reverse(cur.begin(), cur.end());
        pos.push_back(cur);
        reverse(cur.begin(), cur.end());
        return;
    }
    for(auto x: divs){
        if(cur.size() && x < cur.back()) continue;
        if(!(n % x)){
            cur.push_back(x);
            gendivs(n/x, cur);
            cur.pop_back();
        }
    }
}

void init(){
    for(int i=0;i<=8;i++){
        ll cur = 1;
        pot[i][0] = 1;
        for(int j=1;j<64;j++){
            if(MAXV/pr[i] >= pot[i][j-1]){
                pot[i][j] = pr[i] * pot[i][j-1];
            }else{
                maxpot[i] = j-1;
                break;
            }
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    init();
    cin >> n;
    for(int i=2;i<=n;i++) if(!(n%i)) divs.push_back(i);
    if(n != 1){
        vector<int> aux;
        gendivs(n, aux);
        ll ans = INF_LL;
        for(auto x : pos){
            ll cur = 1;
            for(int i=0;i<x.size();i++){
                if((x[i]-1) > maxpot[i] || MAXV/cur < pot[i][x[i]-1]){
                    cur = INF_LL;
                    break;
                }else cur *= pot[i][x[i]-1];
            }
            ans = min(ans, cur);
        }
        cout << ans;
    }else cout << "1\n";
}
