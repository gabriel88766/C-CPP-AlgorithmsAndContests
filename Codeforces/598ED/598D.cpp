#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< int, int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>
# define PI          3.141592653589793238462643383279502884L
//matrix vector<vector<int>> matrix(row,vector<int>(col));

using namespace std;

int cont;
stack <par> st1;
int n,m;

void routine1(unsigned char **v,int a,int b){
    v[a][b]=2;
    st1.push(mp(a,b));
    if(a>0){
        if(v[a-1][b]==0) cont ++;
        else if(v[a-1][b]==1) routine1(v,a-1,b);
    }
    if(a<n){
        if(v[a+1][b]==0) cont ++;
        else if(v[a+1][b]==1) routine1(v,a+1,b);
    }
    if(b>0){
        if(v[a][b-1]==0) cont++;
        else if(v[a][b-1]==1) routine1(v,a,b-1);
    }
    if(b<m){
        if(v[a][b+1]==0) cont++;
        else if(v[a][b+1]==1) routine1(v,a,b+1);
    }
}

void routine2(unsigned int **v){
    par p;
    while(!st1.empty()){
        p = st1.top();
        st1.pop();
        v[p.st][p.nd] = cont;
    }
}

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
int k,a,b;

char in;
cin  >> n >> m >> k;
unsigned char **u;
unsigned int  **v;
u = (unsigned char **)malloc(n*sizeof(unsigned char *));
v = (unsigned int **)malloc(n*sizeof(unsigned int *));
for(int i=0;i<n;i++){
    u[i]=(unsigned char *)malloc(m*sizeof(unsigned char));
    v[i]=(unsigned int *)malloc(m*sizeof(unsigned int));
}
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin >> in;
        v[i][j]=0;
        if(in=='*'){
            u[i][j]=0;
        }else{
            u[i][j]=1;
        }
    }
}
// now
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(u[i][j]==1){
            cont=0;
            routine1(u,i,j);
            routine2(v);
        }
    }
}


for(int i=0;i<k;i++){
    cin >> a >> b;
    cout << v[a-1][b-1] << endl;
}
for(int i=0;i<n;i++){
    free(u[i]);
    free(v[i]);
}
free(u);
free(v);
}
