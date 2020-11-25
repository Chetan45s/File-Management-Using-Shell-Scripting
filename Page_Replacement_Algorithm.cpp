#include <bits/stdc++.h>
using namespace std;
#define int long long

int predict(int page[], vector<int>& fr, int n, int index) {
   int res = -1, farthest = index;
   for (int i = 0; i < fr.size(); i++) {
      int j;
      for (j = index; j < n; j++) {
         if (fr[i] == page[j]) {
            if (j > farthest) {
               farthest = j;
               res = i;
            }
            break;
         }
      }
      if (j == n)
         return i;
   }
   return (res == -1) ? 0 : res;
}
bool search(int key, vector<int>& fr) {
   for (int i = 0; i < fr.size(); i++)
   if (fr[i] == key)
   return true;
   return false;
}
void optimal(int n, int fn,int page[]) {
   vector<int> fr;
   int hit = 0;
   for (int i = 0; i < n; i++) {
      if (search(page[i], fr)) {
         hit++;
         continue;
      }
      if (fr.size() < fn)
      fr.push_back(page[i]);
      else {
         int j = predict(page, fr, n, i + 1);
         fr[j] = page[i];
      }
   }
   cout << "Hits = " << hit << endl;
   cout << "Misses = " << n - hit << endl;
}

int fifo(int n,int fn,int pages[]) { 
    unordered_set<int> s; 
    queue<int> Q; 
    int pf = 0; 
    for (int i=0; i<n; i++) { 
        if (s.size() < fn) { 
            if (s.find(pages[i])==s.end()) { 
                s.insert(pages[i]); 
                pf++; 
                Q.push(pages[i]); 
            } 
        } 
        else{ 
            if (s.find(pages[i]) == s.end()){ 
                int val = Q.front(); 
                Q.pop(); 
                s.erase(val); 
                s.insert(pages[i]); 
                Q.push(pages[i]); 
                pf++; 
            } 
        } 
    } 
    return pf; 
} 
  
void lru(int N,int fn,int page[]){
    int n = fn;
    int m = N;
    int i,j,k,hit=0;

    vector<int> p(m);
    vector<int> hi(m);
    for(i=0;i<m;i++){
        p[i] = page[i];
    }    
    vector<vector<int>> a(n);
    for(i=0;i<n;i++){
        a[i]=vector<int>(m,-1);
    }
    map <int, int> mp;    
    for(i=0;i<m;i++){
        vector<pair<int,int>> c;
        for(auto q: mp){
            c.push_back({q.second,q.first});
        }
        sort(c.begin(),c.end());
        bool hasrun=false;
        for(j=0;j<n;j++){
            if(a[j][i]==p[i]){
                hit++;
                hi[i]=1;
                mp[p[i]]=1;
                hasrun=true;
                break;
            }
            if(a[j][i]==-1){
                for(k=i;k<m;k++)
                    a[j][k]=p[i];
                mp[p[i]]++;
                hasrun=true;
                break;
            }
        }
        if(j==n||hasrun==false){
            for(j=0;j<n;j++){
                if(a[j][i]==c[c.size()-1].second){
                    mp.erase(a[j][i]);
                    for(k=i;k<m;k++)
                        a[j][k]=p[i];
                    mp[p[i]]++;
                    break;
                }
            }
        }
        for(auto q:mp){
            if(q.first!=p[i]){
                mp[q.first]++;
            }
        }
    }
    cout<<"\n";
    cout<<"Hit "<<hit<<'\n'<<"Page Fault "<<m-hit<<'\n';
}

int32_t main(){
    int t = 3;
    int fn;
    cout<<"Number of Frames: ";
    cin>>fn;
    int n;
    cout<<"Page Reference Stream Length: ";
    cin>>n;
    int page[n];
    cout<<"Page Reference Stream:\n";
    for(int i=0; i<n; i++)
        cin>>page[i];
    while(t--){
        int choice;
        cout<<"1. LRU"<<endl;
        cout<<"2. FIFO"<<endl;
        cout<<"3. Optimal"<<endl;
        cout<<"Choose : ";cin>>choice;
        switch (choice){
        case 1:
            cout<<endl;
            lru(n,fn,page);
            break;
        case 2:
            cout<<endl;
            cout<<"Page Faults : "<<fifo(n,fn,page)<<endl;;
            break;
        case 3:
            cout<<endl;
            optimal(n,fn,page);
            break;
        }
    }
    return 0;
}

/*
Number of Frames: 3
Page Reference Stream Length: 12
Page Reference Stream: 1 2 3 4 1 2 5 1 2 3 4 5

1. LRU
2. FIFO
3. Optimal
Choose : 1

Hit 2
Page Fault 10

1. LRU
2. FIFO
3. Optimal
Choose : 2

Page Faults : 9

1. LRU
2. FIFO
3. Optimal

Choose : 3

Hits = 5
Misses = 7

*/