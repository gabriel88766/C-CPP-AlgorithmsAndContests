#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_LL = 0x3f3f3f3f3f3f3f3f;
const int MAX_INT = 0x3f3f3f3f;
using namespace std;

ll MOD = 1e9+7;

vector<vector<ll>> dice ={{1, 1, 0, 0, 0, 0},
                          {1, 0, 1, 0, 0, 0},
                          {1, 0, 0, 1, 0, 0},
                          {1, 0, 0, 0, 1, 0},
                          {1, 0, 0, 0, 0, 1},
                          {1, 0, 0, 0, 0, 0}};
                                         

vector<vector<ll>> multMatrix(vector<vector<ll>> a, vector<vector<ll>> b, ll m){
    int size = a.size();
    vector<vector<ll>> ans(size, vector<ll>(size));
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            ll cel = 0;
            for(int k=0;k<size;k++){
                cel = (cel + a[i][k] * b[k][j]) % MOD;
            }
            ans[i][j] = cel;
        }
    }
    return ans;
}

vector<vector<ll>> binpow(vector<vector<ll>> a, ll b, ll  m){
    int size = a.size();
    vector<vector<ll>> ans(size,vector<ll>(size)); //idt
    for(int i=0;i<size;i++) ans[i][i] = 1; //idt

    while(b > 0){
        if(b & 1) 
            ans = multMatrix(ans, a, m);
        a = multMatrix(a, a, m);
        b >>= 1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll n;
    cin >> n;
    if(n == 1) cout << 1; 
    else if(n == 2) cout << 2;
    else if(n == 3) cout << 4;
    else if(n == 4) cout << 8;
    else if(n == 5) cout << 16;
    else if(n == 6) cout << 32;
    else{
        vector<vector<ll>> ans = binpow(dice, n-6, MOD);
        cout << ( ans[0][0] * 32 + ans[1][0] * 16 + ans[2][0] * 8 + ans[3][0] * 4 + ans[4][0] * 2 + ans[5][0] ) % MOD;
    }
}
