#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[10003];
bool visited[10003];
int preorder[10003];
int low[10003];
bool isAP[10003];
int ttime;

void AP(int v, int parent){
	int children = 0;
	visited[v] = true;
	preorder[v] = low[v] = ++ttime;
	for (int u : graph[v]) {
		if (!visited[u]) {
			children++;
			AP(u, v);
			low[v] = min(low[v], low[u]);
			if (parent != -1 && low[u] >= preorder[v]) isAP[v] = true;
		}
		else if (u != parent) low[v] = min(low[v], preorder[u]);
	}
	if (parent == -1 && children > 1) isAP[v] = true;
}

int main(){
	int n, m, num1, num2;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> num1 >> num2;
        graph[num1].push_back(num2);
        graph[num2].push_back(num1);
    }
	int parent = -1;
	for (int i = 1; i<=n; i++) if (!visited[i]) AP(i, parent);
	for (int i = 1; i<=n; i++) if (isAP[i] == true) cout << i << " ";

	return 0;
}
