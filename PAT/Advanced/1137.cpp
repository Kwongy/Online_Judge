#include<iostream>
#include<map>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

struct grade{
	string name;
	int p;
	int mid_term = -1;
	int final_term = -1;
	int g;
};
map<string,grade> maze;
vector<grade> vec;
bool cmp(const struct grade &a, const struct grade &b){
	if(a.g != b.g) return a.g > b.g;
	else{
		return a.name.compare(b.name) < 0;
	}
}
int main(){
	int n, m, k;
	scanf("%d %d %d\n", &n, &m, &k);
	string first;
	int temp;
	for(int i = 0; i < n; i++){
		cin >> first >> temp;
		if(temp >= 200){
			maze[first].name = first;
			maze[first].p = temp;
		}
	}
	for(int i = 0; i < m; i++){
		cin >> first >> temp;
		if(maze.find(first) != maze.end()){
			maze[first].mid_term = temp;
		}
	}
	for(int i = 0; i < k; i++){
		cin >> first >> temp;
		if(maze.find(first) != maze.end()){
			maze[first].final_term = temp;
			if(maze[first].final_term < maze[first].mid_term){
				maze[first].g = (int)(maze[first].final_term * 0.6 + maze[first].mid_term * 0.4 + 0.5);
			}else{
				maze[first].g = maze[first].final_term;
			}
			if(maze[first].g >= 60){
				vec.push_back(maze[first]);
			}
		}
	}
	n = vec.size();
	sort(vec.begin(),vec.end(),cmp);
	for(int i = 0; i < n; i++){
		cout << vec[i].name << " " << vec[i].p << " " << vec[i].mid_term << " " << vec[i].final_term << " " << vec[i].g << endl;
	}
	return 0;
}
