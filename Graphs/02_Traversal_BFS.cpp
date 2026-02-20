#include <iostream>

using namespace std;

vector<vector<int>> GraphRepresentation(){
    int n,m;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    cout << "For " << m << " edges give the nodes(1-based indexing) in a space separated format below:" << endl;

    vector<vector<int>> nodes(n+1);
    
    for(int a=0; a<m; a++){
        int inp1,inp2;

        cin >> inp1;
        cin >> inp2;

        nodes[inp1].push_back(inp2);
        nodes[inp2].push_back(inp1);
    }

    return nodes;
}

void BFSTraversal(vector<vector<int>> graph, int startingNode){
    int n = graph.size();

    vector<bool> isTraversed(n, false);
    
    queue<int> Q;
    Q.push(startingNode);
    isTraversed[startingNode] = true;

    while(!Q.empty()){
        int crntEl = Q.front();
        cout << crntEl << " ";
        Q.pop();

        for(int i:graph[crntEl]){
            if(!isTraversed[i]){
                isTraversed[i] = true;
                Q.push(i);
            }
        }
    }
}

int main(){
    vector<vector<int>> graph = GraphRepresentation();

    int startingNode;
    cout << "Enter the starting node: ";
    cin >> startingNode;

    BFSTraversal(graph, startingNode);
    return 0;
}