#include <bits/stdc++.h>

using namespace std;

bool astar(int ini,int goal,vector <pair <int,int>> adj[],vector <bool> &vis,vector <int> heuristic,int curr,int &ans){
    vis[ini]=true;
    vector <pair <int,int>> temp;
    for(auto x: adj[ini]){
        int v=x.first;
        int wt=x.second;
       
        if(vis[v]==false){
            int f=curr+heuristic[v]+wt;
            if(v==goal){
                ans=f;
                return true;
            }
           
            temp.push_back({f,v});
           
        }
       
    }
    sort(temp.begin(),temp.end());
    if(temp.size()==0){
        return false;
    }
    else{
        int i=0;
        while(i<temp.size() && temp[0].first==temp[i].first){
            vis[temp[i].second]=true;
            int newf=temp[i].first;
            if(astar(temp[i].second,goal,adj,vis,heuristic,newf,ans)){
                ans=newf+heuristic[temp[i].second];
                return true;
            }
                i++;
        }
    }
   
    return false;
   
}

void astarAlgo(int ini,int goal, vector <pair <int,int>> adj[],vector <int> &heuristic,int ver,int &ans){
   
    queue <pair <int,int>> q;
    int g=0;
    q.push({ini,g});
   // int ans=INT_MAX;
   
    vector <bool> vis(ver,false);
   
    while(!q.empty()){
        int curr=q.front().first;
        vis[curr]=true;
        int currg=q.front().second;
        vector <pair <int,int>> temp;
        q.pop();
        bool isBreak=false;
        for(auto x:adj[curr]){
         
            int v=x.first;
            int wt=x.second;
            int f=curr+heuristic[v]+wt;
           
            if(vis[v]==false){
                vis[v]=true;
               
                if(v==goal){
                    ans=min(ans,f);
                    isBreak=true;
                    break;
                    //return true;
                }
                else{
                    temp.push_back({f,v});
                }
            }
           
           
           
           
        }
        if(isBreak){
            temp.clear();
            continue;
        }
        sort(temp.begin(),temp.end());
       
       
       
            int i=0;
           
            while(i<temp.size() && temp[0].first==temp[i].first){
                q.push({temp[i].second,temp[i].first-heuristic[temp[i].second]});
                i++;
            }
       
        temp.clear();
       
    }
   if(ans!=INT_MAX)
    cout<<"\nSuccess and Total cost to reach goal : "<<goal<<" is : "<<ans<<endl;
    else
        cout<<" Failure:  "<<endl;
}

int main()
{
   int ver,edg;
   cout<<"enter no. of vertices and edges : ";
   cin>>ver>>edg;
   vector <pair <int,int>> adj[ver];
   
   for(int i=0;i<edg;i++){
       int u,v,w;
       cin>>u>>v>>w;
       adj[u].push_back({v,w});
      adj[v].push_back({u,w});
       
   }
   
   int ini,goal;
   cout<<"Enter initial and goal value : ";
   cin>>ini>>goal;
   vector <int> heuristic(ver,0);
   cout<<"Enter the heuristic value:  ";
   for(int i=0;i<ver;i++){
       cin>>heuristic[i];
   }
   
   int ans=INT_MAX;
   vector <bool> vis(ver,false);
   
   // astar(ini,goal,adj,vis,heuristic,0,ans)
   
   
//   0 1 1
// 0 2 2
// 0 3 3
// 1 4 4
// 2 4 5
// 3 4 6


   astarAlgo(ini,goal,adj,heuristic,ver,ans);
   
   
   
   

    return 0;
}
