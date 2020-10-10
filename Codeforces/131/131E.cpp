#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
const int N2 = 2e5+10;
const int INF = 0x3f3f3f3f;
int maxcol[N],mincol[N],maxrow[N],minrow[N],minprimDiag[N2],maxprimDiag[N2],minsecDiag[N2],maxsecDiag[N2],n,m,x,y;
void init(){
    for(int i=0;i<N;i++){
        maxcol[i]=0;
        mincol[i]=N;
        maxrow[i]=0;
        minrow[i]=N;
    }
    for(int i=0;i<N2;i++){
        minprimDiag[i]=N;
        maxprimDiag[i]=0;
        minsecDiag[i]=N;
        maxsecDiag[i]=0;
    }
}

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
init();
map<int,int> mp;
vector<int> X,Y;
cin >> n >> m;
for(int i=0;i<m;i++){
    cin >> x >> y;
    X.push_back(x);
    Y.push_back(y);
    maxcol[y] = max(maxcol[y],x);
    mincol[y] = min(mincol[y],x);
    maxrow[x] = max(maxrow[x],y);
    minrow[x] = min(minrow[x],y);
    minprimDiag[x+y] = min(minprimDiag[x+y],y);
    maxprimDiag[x+y] = max(maxprimDiag[x+y],y);
    minsecDiag[n+x-y] = min(minsecDiag[n+x-y],x);
    maxsecDiag[n+x-y] = max(maxsecDiag[n+x-y],x);
}
for(int i=0;i<m;i++){
    int cont = 0;
    x = X[i], y = Y[i];
    if(x < maxcol[y]) cont++;
    if(x > mincol[y]) cont++;
    if(y < maxrow[x]) cont++;
    if(y > minrow[x]) cont++;
    if(y > minprimDiag[x+y]) cont++;
    if(y < maxprimDiag[x+y]) cont++;
    if(x > minsecDiag[n+x-y]) cont++;
    if(x < maxsecDiag[n+x-y]) cont++;
    mp[cont]++;
}
for(int i=0;i<=8;i++){
    cout << mp[i] << " ";
}


}

