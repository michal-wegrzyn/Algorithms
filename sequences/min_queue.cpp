#include <iostream>
#include <deque>
#include <utility>
using namespace std;

deque<pair<int,int>> mmin_queue;

int cnt;
void ppush(int value){
    cnt = 0;
    while((!mmin_queue.empty()) && mmin_queue.back().first>=value){
        cnt += mmin_queue.back().second +1;
        mmin_queue.pop_back();
    }
    mmin_queue.push_back(make_pair(value, cnt));
}

void ppop(){
    if(mmin_queue.empty()) return;
    if(mmin_queue.front().second) mmin_queue.front().second--;
    else mmin_queue.pop_front();
}

int mmin(){
    if(mmin_queue.empty()) return 2100000000;
    else return mmin_queue.front().first;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie();
    int m, num;
    char c;
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> c;
        if(c=='M') cout << mmin() << '\n';
        else if(c=='P'){
            cin >> num;
            ppush(num);
        }
        else ppop();
    }
    return 0;
}