//tested in https://cses.fi/problemset/result/7045040/ (String Find Patterns)

struct Aho{ //declare once! too much memory
    int len;
    vector<vector<int>> trie;
    vector<int> slink;
    vector<bool> isFinal;
    int c = 0;
    void add(const string &s){
        int cur = 0;
        for(int i = 0; i < s.size(); i++){
            if(trie[cur][s[i]-'a']) cur = trie[cur][s[i]-'a'];
            else cur = trie[cur][s[i]-'a'] = ++c;
        }
        isFinal[cur] = true;
    }
    int get(const string &s){
        int cur = 0;
        for(int i = 0; i < s.size(); i++) cur = trie[cur][s[i]-'a'];
        return cur;
    }
    void addLink(){
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int i=0;i<26;i++){
                if(trie[u][i]){
                    q.push(trie[u][i]);
                    if(u){
                        int v = slink[u];
                        while(v && !trie[v][i]) v = slink[v];
                        slink[trie[u][i]] = trie[v][i];
                    }
                }
            }
        }
    }
    Aho(vector<string> &v, int maxlen){
        len = maxlen;
        isFinal = vector<bool>(maxlen, false);
        trie = vector<vector<int>>(maxlen, vector<int>(26, 0));
        slink = vector<int>(maxlen, 0);
        for(auto x : v) add(x);
        addLink();
    }
    //mark all reachable states in the trie
    vector<bool> CheckText(string &s){
        vector<bool> canReach(len, false);
        queue<int> q;
        int cur = 0;
        canReach[0] = true;
        for(int i=0;i<s.size();i++){
            while(cur && !trie[cur][s[i]-'a']) cur = slink[cur];
            cur = trie[cur][s[i]-'a'];
            if(!canReach[cur]){
                canReach[cur] = true;
                q.push(cur);
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(!canReach[slink[u]]){
                q.push(slink[u]);
                canReach[slink[u]] = true;
            }
        }
        return canReach;
    }
};