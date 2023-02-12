#include<bits/stdc++.h>

using namespace std;
bool ok[4][13];
char mapc[] = {'S', 'H', 'C', 'D'};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int k;
        char c;
        cin >> c >> k;
        if(c == 'S') ok[0][k-1] = true;
        else if(c == 'H') ok[1][k-1] = true;
        else if(c == 'C') ok[2][k-1] = true;
        else ok[3][k-1] = true;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            if(!ok[i][j]){
                cout << mapc[i] << " " << j+1 << "\n"; 
            }
        }
    }
}

