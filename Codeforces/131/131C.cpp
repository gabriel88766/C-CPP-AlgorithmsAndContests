#include <bits/stdc++.h>

using namespace std;

long long int Pascal[31][31];

void init(){
    for(int i=0;i<=30;i++){
        for(int j=0;j<=i;j++){
            if(j==i){
                Pascal[i][j] = 1;
            }else if(j&&i){
                Pascal[i][j] = Pascal[i-1][j] + Pascal[i-1][j-1];
            }else{
                Pascal[i][j] = 1;
            }
        }
    }

}

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
 init();
 long long int n,m,t,Total=0;
 cin >> n >> m >> t;
 for(int i=4; i<=(t-1) ;i++ ){
    if( n>=i && m>=(t-i)) Total += Pascal[n][i]*Pascal[m][t-i];
 }
 cout << Total;
}

