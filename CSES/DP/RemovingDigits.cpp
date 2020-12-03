#include <bits/stdc++.h>

using namespace std;

const int N  = 1e6+5;
const int INF = 0x3f3f3f3f;

int dp[N];
int digits[8];
int qtdig;

void what(int k){
    int u = k;
    qtdig=0;
    while(u!=0){
        digits[qtdig] = u%10;
        qtdig++;
        u/=10;
    }
}


void make_dp(){
    for(int i=1;i<N;i++){
        dp[i] = INF;
    }
    for(int i=1;i<N;i++){
        what(i);
        for(int j=0;j<qtdig;j++){
            dp[i] = min(dp[i],dp[i-digits[j]]+1);
        }
    }
}



int main() {
    make_dp();
    int n;
    cin >> n;
    cout << dp[n];
}
