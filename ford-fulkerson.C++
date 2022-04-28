#include <iostream>
#include <string.h>
using namespace std;
#define N 7
#define INF 9999999

int Flow[N][N];

bool visited[N];

int graph[N][N] = {
        { 0, 5, 4, 0, 0, 0, 0 }, //0
        { 0, 0, 0, 0, 0, 0, 4 }, //1
        { 0, 0, 0, 3, 0, 0, 6 }, //2
        { 0, 0, 0, 0, 5, 0, 0 }, //3
        { 0, 0, 0, 0, 0, 0, 8 }, //4
        { 6, 0, 0, 2, 0, 0, 0 }, //5
        { 0, 0, 0, 0, 0, 0, 0 }, //6
        };
int dfs(int s, int t, int minimum) {
    visited[s] = true;
    
    if (s == t)
        return minimum;
    for (int i = 0; i < N; i++) {
        int flow_capacity = graph[s][i] - Flow[s][i];
        if (!visited[i] && flow_capacity > 0) {
            
            if (int sent = dfs (i, t, min (minimum, flow_capacity))) {
               
                Flow[s][i] += sent;
                Flow[i][s] -= sent;
                return sent;
            }
        }
    }
    return false;
}
int main() {
    
    memset(Flow, 0, sizeof(Flow));
    
    memset(visited, 0, sizeof(visited));
    int s = 5;
    int t = 6;
    int max_flow = 0;
    
    while (int sent = dfs(s, t, INF)) {
        max_flow += sent;
        
        memset(visited, 0, sizeof(visited));
    }
    cout << "노드5에서 노드6까지의 최대유량: " << max_flow;
    cout << endl;
}

