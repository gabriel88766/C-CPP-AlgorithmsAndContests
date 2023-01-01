#include <bits/stdc++.h>
#include <cstring>
#define ll long long int

using namespace std;
const int N = 1e3 + 5;
int m2[N][N]; //4MB
int m5[N][N]; //4MB
int dp[N][N][2]; //8MB

char answrev[2005], answ[2005];

int main(){
    //freopen("in.txt", "r", stdin);
    int n, aux;
    int hasZ = 0;
    int indeX, indeY;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&aux);
            int aux2 = aux;
            if(aux2 == 0){
                indeX = i;
                indeY = j;
                hasZ = 1;
                m2[i][j] = 1e6; //avoid this path
                m5[i][j] = 1e6;
                continue;
            }
            while(!(aux2 % 2)){
                m2[i][j] ++;
                aux2 >>= 1;
            }
            aux2 = aux;
            while(!(aux2 % 5)){
                m5[i][j] ++;
                aux2 /= 5;
            }
        }
    }


    for(int i=0;i<n; i++){
        for(int j=0; j<n; j++){
            if(i == 0 && j == 0){
                dp[i][j][0] = m2[i][j];
                dp[i][j][1] = m5[i][j];
            }else if(i == 0){
                dp[i][j][0] = dp[i][j-1][0] + m2[i][j];
                dp[i][j][1] = dp[i][j-1][1] + m5[i][j];
            }else if(j == 0){
                dp[i][j][0] = dp[i-1][j][0] + m2[i][j];
                dp[i][j][1] = dp[i-1][j][1] + m5[i][j];
                
            }else{
                dp[i][j][0] = min(dp[i-1][j][0], dp[i][j-1][0]) + m2[i][j];
                dp[i][j][1] = min(dp[i-1][j][1], dp[i][j-1][1]) + m5[i][j];
            }
        }
    }
    int nm = dp[n-1][n-1][0] < dp[n-1][n-1][1] ? 0 : 1;
    int ans = min(dp[n-1][n-1][0], dp[n-1][n-1][1]);
    int i_ = n-1,j_ = n-1;
    if(!hasZ || dp[i_][j_][nm] == 0){
        while(i_ > 0 || j_ > 0){
            if(i_> 0 && j_ > 0){
                if(dp[i_-1][j_][nm] < dp[i_][j_-1][nm]){
                    answrev[2*n-2 - i_ - j_] = 'D';
                    i_--;
                }else{
                    answrev[2*n-2 - i_ - j_] = 'R';
                    j_--;
                }
            }else{
                if(i_ == 0){
                    answrev[2*n-2 - i_ - j_] = 'R';
                    j_--;
                }else{
                    answrev[2*n-2 - i_ - j_] = 'D';
                    i_--;
                }
            }
        }
    }else{
        ans=1;
        while(i_ > 0 && j_ > 0){
            while(i_ > indeX){
                answrev[2*n-2 - i_ - j_] = 'D';
                i_--;
            }
            while(j_ > indeY){
                answrev[2*n-2 - i_ - j_] = 'R';
                j_--;
            }
            while(i_ > 0){
                answrev[2*n-2 - i_ - j_] = 'D';
                i_--;
            }
            while(j_ > 0){
                answrev[2*n-2 - i_ - j_] = 'R';
                j_--;
            }
        }
    }
    printf("%d\n",ans);
    for(int i = 2*n-3; i>=0; i--){
        answ[2*n-3-i] = answrev[i];
    }
    printf("%s", answ);
}
