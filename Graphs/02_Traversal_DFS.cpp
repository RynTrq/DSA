#include <iostream>

using namespace std;

vector<vector<int>> GraphRepresentation(){
    int n,m;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> graph(n);

    for(int i=0; i<m; i++){
        int inp1, inp2;

        cin >> inp1;
        cin >> inp2;

        graph[inp1].push_back(inp2);
        graph[inp2].push_back(inp1);
    }

    return graph;
}

void DFSTraversal(vector<vector<int>>& graph, int currentNode, vector<bool>& isTraversed){
    cout << currentNode << " ";

    for(int el:graph[currentNode]){
        if(!isTraversed[el]){
            isTraversed[el] = true;
            DFSTraversal(graph, el, isTraversed);
        }
    }
}

int main(){
    vector<vector<int>> graph = GraphRepresentation();
    vector<bool> isTraversed(graph.size(), false);

    int startingNode;
    cout << "Enter the starting node: ";
    cin >> startingNode;

    isTraversed[startingNode] = true;

    DFSTraversal(graph, startingNode, isTraversed);
    return 0;
}