#include <bits/stdc++.h>
#define ll long long int

using namespace std;

//Evaluate a^n == mod m -- O(log n)
long long int binpow(long long int a, long long int b, long long int m){
    a %= m;
    long long int res = 1;
    while(b > 0){
        if(b & 1) 
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    cin >> n;
    for(int i=0; i< n; i++){
        ll a,b;
        cin >> a >> b;
        cout << binpow(a,b,1e9+7) << "\n";
    }
}
