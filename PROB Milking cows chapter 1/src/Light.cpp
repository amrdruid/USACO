/*
LANG: C++
PROB: milk2
*/

#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define all(v) (v).begin( ), (v).end( )
double pi = 3.1415926536;
const int oo = (int) 1e9;
const long long OO = numeric_limits<long long>::max();

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int di[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dj[] = { 1, -1, 0, 0, 1, -1, -1, 1 };

int f1[] = { 0, 0, 0, 1, 1, 1, -1, -1, -1 };
int f2[] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

bool comp(pair<int,int>x , pair<int ,int>y){
	return x.first <= y.first && x.second >= y.second;
}

int main(){
    ios_base::sync_with_stdio(false);
  freopen("milk2.in","r",stdin);
  freopen("milk2.out","w",stdout);

    int mx1 = 0, mx2 = 0;
    int n;
    cin >> n;
    vector<pair<int,int> >myvec(n);

    for(int i = 0 ; i < n ; i++){
    	cin >> myvec[i].first >> myvec[i].second;
    }

    sort(all(myvec));

    mx1 = myvec[0].second - myvec[0].first;
    int head = myvec[0].first , tail = myvec[0].second;
//
//    for(int i = 0 ; i < sz(myvec) ; i++){
//    	cout << myvec[i].first << " " << myvec[i].second << endl;
//    }

    for(int i = 0 ; i < n ; i++){
    	if(myvec[i].first > head && myvec[i].first > tail){
    		mx2 = max(mx2 , myvec[i].first - tail);
    		head = myvec[i].first , tail = myvec[i].second;
    		mx1 = max(mx1 , tail - head);
    	}else if(myvec[i].second > tail){
    		tail = myvec[i].second;
    		mx1 = max(mx1 , tail - head);
    	}

    }

    cout << mx1 << " " << mx2 << endl;

}
