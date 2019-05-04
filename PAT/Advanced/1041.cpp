#include <iostream>
#include <map> 

using namespace std;
#define MAX 1<<29

int main(){
	int n;
	cin>>n;
	map<int,int> maze;
	int a;
	for(int i = 0;i < n ; i++){
		cin >> a;
		if(maze.find(a)!=maze.end()){
			maze[a] = MAX;
		}else{
			maze.insert(make_pair(a, i));
		}
	}
	int index = MAX;
	int output;
	map<int, int>::iterator it;
	for (it = maze.begin(); it != maze.end(); it++){
		if(it->second<index){
			index = it->second;
			output =  it->first ;
		}
    }
    if(index!=MAX){
    	cout << output <<endl;
	}else{
		cout << "None" <<endl;
	}
}
