#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_LL = 0x3f3f3f3f3f3f3f3f;
const int MAX_INT = 0x3f3f3f3f;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll sum = 0, maxsum = -MAX_INT, aux;
    //freopen("in", "r", stdin); test input
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> aux;
        sum += aux;
        maxsum = max(maxsum, sum);
        if(sum < 0) sum = 0;
    }
    cout << maxsum;
}
