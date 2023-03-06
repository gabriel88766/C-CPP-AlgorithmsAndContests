//old
#include <bits/stdc++.h>
 
using namespace std;
 
const int INF = 0x3f3f3f3f;
 
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int N,k;
    int ps[150005];
    ps[0] = 0;
    cin >> N >> k;
    for(int i=1;i<=N;i++){
        int aux;
        cin >> aux;
        ps[i] = ps[i-1] + aux;
    }
    int minsum = INF, minindex;
    for(int i=k; i<=N; i++){
        if(minsum > (ps[i]-ps[i-k])){
            minsum = ps[i] - ps[i-k];
            minindex = i-k+1;
        }
    }
    cout << minindex;
}