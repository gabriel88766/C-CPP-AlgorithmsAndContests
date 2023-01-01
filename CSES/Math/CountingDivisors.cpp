#include <bits/stdc++.h>
typedef long long int ll;

using namespace std;
const int N = 1e6+5;
int divisors[N];

void solve(){
    for(int i=1; i <= 1000000; i++){
        divisors[i] = 1;
    }
    for(int i = 2; i <= 1000000;i++){
        if(divisors[i] == 1){
            for(int j = i; j <= 1000000; j+=i){
                int x = divisors[j];
                int aux = j;
                while(!(aux % i)){
                    aux /= i;
                    divisors[j] += x;
                }

            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    solve();
    cin >> n;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        cout << divisors[aux] << "\n";
    }
}
