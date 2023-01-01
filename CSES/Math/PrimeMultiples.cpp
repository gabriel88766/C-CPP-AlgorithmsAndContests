#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_LL = 0x3f3f3f3f3f3f3f3f;
using namespace std;

ll countBytes(ll num){
    ll count = 0;
    while(num > 0){
        if(num & 1) count++;
        num >>= 1;
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll n, k, aux, sum1=0, sum2=0, cursum, curnum;
    vector<ll> primes(25);
    cin >> n >> k;
    for(int i=0;i<k;i++){
        cin >> primes[i];
    }
    for(int i = 1; i < (1 << k); i++){
        curnum = 1;
        for(int j=0; j<k; j++){
            if(i & (1 << j)){
                if((MAX_LL / curnum) < primes[j]){
                    curnum = MAX_LL;
                    break;
                }else{
                    curnum *= primes[j];
                }
            }
        }
        cursum = n/curnum;
        if(countBytes(i) % 2) sum1 += cursum;
        else sum2 += cursum;
    }
    cout << sum1-sum2;
}
