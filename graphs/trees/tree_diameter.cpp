#include <iostream>
#include <vector>
using namespace std;

vector <int> treee[10003];
int x, diam;
bool visited[10003];

void dfs(int v, int curr_diam){
	visited[v] = true;
	curr_diam++;
	for (int i:treee[v]) {
		if (!visited[i]) {
			if (curr_diam >= diam) {
				diam = curr_diam;
				x = i;
			}
			dfs(i, curr_diam);
		}
	}
}

int diameter(int n){
	diam = -2100000000;
	int curr_diam = 0;
	dfs(1, curr_diam + 1);
	for(int i=0; i<10002; i++) visited[i] = false;
	curr_diam = 0;
	dfs(x, curr_diam + 1);
	return diam;
}

int main(){
	int n, num1, num2;
    cin >> n;
    for(int i=1; i<n; i++){
        cin >> num1 >> num2;
        treee[num1].push_back(num2);
        treee[num2].push_back(num1);
    }

	cout << diameter(n);
	return 0;
}
