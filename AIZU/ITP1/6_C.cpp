#include<bits/stdc++.h>

using namespace std;
int v[4][3][10];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        v[a-1][b-1][c-1] += d;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<10;k++){
                cout << " " << v[i][j][k];
            }
            cout << "\n";
        }
        if(i != 3) cout << "####################" << "\n";
    }
}

