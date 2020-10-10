
#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< pair<int, int>, int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>
//matrix vector<vector<int>> matrix(row,vector<int>(col))

using namespace std;

bool erastotenes[18003001];

void mk_eras(){
    erastotenes[0]=false;
    erastotenes[1]=false;
    for(int i=2;i<=18003000;i++){
        erastotenes[i]=true;
    }
    for(int i = 2; i < 6000;i++){
            if(erastotenes[i]){
                for(int j=(2*i);j<=18003000;j+=i){
                    erastotenes[j]=false;
                }
            }
    }
}

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
mk_eras();
int n,k;
cin >> n;
k=(n*(n+1))/2;
if(erastotenes[k]){
        for(int i=0;i<n;i++){
            cout << "1 ";
        }
}else if(k%2){
    if(erastotenes[2]&&erastotenes[k-2]){
        cout << "1 2 ";
        for(int i=0;i<(n-2);i++) cout << "1 ";
    }else{
        k-=3;
        int i,x,ncur=n;
        for(i=3;i<k;i++){
            if(erastotenes[i]&&erastotenes[k-i]){
                break;
            }
        }
        vector <bool> lb(n+1,false);
        x=i;
        while(i>ncur){
            i-=ncur;
            lb[ncur]=true;
            ncur--;
        }
        lb[i]=true;
        if(lb[3]){
            cout << "3 3 2 ";
            for(int i=4;i<=n;i++){
                if(lb[i]) cout << "2 ";
                else cout << "1 ";
            }
        }else{
         rsxfchdgru34wazxfre435etsw ''   for(int i=1;i<=n;i++){
                if(i==3) cout << "2 ";
                else if(lb[i]) cout << "3 ";
                else cout << "1 ";
            }
        for(i=3;i<k;i++){
            if(erastotenes[i]&&erastotenes[k-i]){
                break;
            }
        }

        vector <bool> lb(n+1,false);
        while(i>ncur){
            i-=ncur;
            lb[ncur]=true;
            ncur--;
        }
        lb[i]=true;
        for(i=1;i<=n;i++){
            if(lb[i]){
                cout << "2 ";
            }else{
                cout << "1 ";
            }
        }

}
}

