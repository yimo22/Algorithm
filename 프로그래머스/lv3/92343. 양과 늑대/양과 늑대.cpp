#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

typedef struct Node{
    int visited;
    int sheep;
    int wolf;
    Node(int V, int S, int W) : visited(V), sheep(S), wolf(W) {}
}Node;

int path[17];
int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    int N = info.size();
    int maxSheep = 0;
    for(int i=0;i<edges.size();i++){
        int s= edges[i][0];
        int e = edges[i][1];
        path[s] |= (1 << e);
        path[e] |= (1 << s);
    }
    for(int i=0;i<N;i++) if(!info[i]) maxSheep++;
    queue<Node> q;
    q.push(Node(1, 1, 0));
    
    
    answer = 1;
    while(!q.empty()){
        Node cur = q.front(); q.pop();
        
        if(cur.sheep == maxSheep) {
            break;
        }
        
        // i : 목적지
        for(int i=0;i<N;i++){
            if(cur.visited & (1 << i)) continue;
            // 경로 check
            for(int j=0;j<N;j++){
                if((cur.visited & (1 << j)) && (path[j] & (1 << i))){
                    
                    if(info[i]){
                        // wolf
                        if(cur.sheep - cur.wolf > 1){
                            q.push(Node(cur.visited | (1 << i), cur.sheep, cur.wolf + 1));
                        }
                    }
                    else{
                        answer = max(answer, cur.sheep + 1);
                        q.push(Node(cur.visited | (1 << i), cur.sheep + 1,cur.wolf));
                    }
                    break;
                }
            }
        }
        
    }
        
        
    return answer;
}