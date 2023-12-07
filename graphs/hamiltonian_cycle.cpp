#include <iostream>
using namespace std;
bool graph[10003][10003];
int path[10003];
int n;

bool isSafe(int v, int pos){
	if (graph [path[pos - 1]][ v ] == 0) return false;
	for (int i = 0; i < pos; i++) if (path[i] == v) return false;
	return true;
}

bool hamCycleUtil(int pos){
	if (pos == n){
		if (graph[path[pos - 1]][path[0]] == 1) return true;
		else return false;
	}
	for (int i = 1; i < n; i++){
		if (isSafe(i, pos)){
			path[pos] = i;
			if (hamCycleUtil(pos + 1) == true) return true;
			path[pos] = -1;
		}
	}
	return false;
}

bool hamCycle(){
	for (int i = 1; i < n; i++) path[i] = -1;
	return hamCycleUtil(1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, num1, num2;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> num1 >> num2;
        graph[num1][num2] = true;
        graph[num2][num1] = true;
    }
	if(hamCycle()) for(int i=0; i<n; i++) cout << path[i] << ' ';
    else cout << -1;

	return 0;
}