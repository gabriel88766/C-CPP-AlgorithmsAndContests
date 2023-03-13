//Evaluate a^n == mod m -- O(log n), if m > 1e9, multiply with binmul
typedef long long int ll;
ll binpow(ll a, ll  b, ll  m){
    a %= m;
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

ll binmul(ll a, ll  b, ll  m){
    a %= m;
    ll ans = 1;
    while(b > 0){
        if(b & 1) 
            ans = (ans + a) % m;
        a = (a + a) % m;
        b >>= 1;
    }
    return ans;
}

//matrix version O(k³ log(n)) ** k matrix size
vector<vector<ll>> multMatrix(vector<vector<ll>> a, vector<vector<ll>> b, ll m){
    int size = a.size();
    vector<vector<ll>> ans(size, vector<ll>(size));
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            ll cel = 0;
            for(int k=0;k<size;k++){
                cel = (cel + a[i][k] * b[k][j]) % m;
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