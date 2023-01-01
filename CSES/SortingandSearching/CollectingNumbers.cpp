#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_LL = 0x3f3f3f3f3f3f3f3f;
const int MAX_INT = 0x3f3f3f3f;
using namespace std;

const int N = 2e5+4;
int mp[N];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, cnt = 0, j=0;
    cin >> n;
    for(int i=1; i<=n;i++){
        int aux;
        cin >> aux;
        mp[aux] = i;
    }
    while(j < n){
        cnt++;
        j++;
        while(j < n){
            if(mp[j+1] > mp[j]){
                j++;
            }else{
                break;
            }
        }
    }
    cout << cnt;
}
