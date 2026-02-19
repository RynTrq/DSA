#include <iostream>

using namespace std;

int main(){
    int m,n;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    cout << "For every edge give two space separated nodes(1-based indexing) and then the weight separated with a space" << endl;

    vector<vector<pair<int, int>>> nodeList(n+1);

    for(int i=0; i<m; i++){
        int inp1, inp2, inp3;

        cin >> inp1;
        cin >> inp2;
        cin >> inp3;

        nodeList[inp1].push_back(make_pair(inp2, inp3));
        nodeList[inp2].push_back(make_pair(inp1, inp3));
    }

    for(int i=1; i<=n; i++){
        cout << "Node " << i << " has neighbours: ";
        for(int j=0; j<nodeList[i].size(); j++){
            if(j==nodeList[i].size()-1){
                cout << nodeList[i][j].first << " of weight " << nodeList[i][j].second << ".";
            }else{
                cout << nodeList[i][j].first << " of weight " << nodeList[i][j].second << ", ";
            }
        }
        cout << endl;
    }

    return 0;
}