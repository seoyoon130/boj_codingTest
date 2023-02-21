#include <vector>
#include <map>
#include <string.h>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
int n, m;
string str;
vector<string>name;
map<string, int> name_number;
vector<int> indegree(1000, 0);
vector<int> adj[1000];

vector<string> start_name;
vector<string> family_info;
vector<int> childern_cnt(1000, 0);
vector<string> children[1000];

int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    cin >> n;
    
    for(int i = 0;i<n;i++){
        cin >> str;
        name.push_back(str);
        //map에 이름과 번호(순서대로) 를 저장
        name_number.insert(make_pair(str, i));
    }
    cin >> m;
    for(int i = 0;i<m;i++){
        string x, y;
        // x: 자식, y: 조상
        cin >> x >> y;
        //해당하는 번호를 map에서 찾아준다.
        int x_number = name_number[x];
        int y_number = name_number[y];

        //조상의 번호에, 자식의 번호를 넣어준다 (노드연결)
        adj[y_number].push_back(x_number);
        //하나씩 연결시켜준다.
        indegree[x_number]++;

    }
    int k = 0;
    queue<int> q;
    for(int i = 0;i<n;i++){
        //차수가 연결되어있지 않으면 (즉, 0이면)
        //조상이므로
        if(indegree[i]==0){
            start_name.push_back(name[i]);
            //자식을 넣어주고
            q.push(i);
            //가문의 갯수를 카운트 해준다.
            k++;
        }
    }
    while(!q.empty()){
        int here = q.front();
        q.pop();

        for(int i = 0;i<adj[here].size();i++){
            int there = adj[here][i];
            indegree[there]--;

            if(indegree[there]==0){
                childern_cnt[here]++;
                children[here].push_back(name[there]);
                q.push(there);
            }
        }
        string this_info = name[here];
        this_info += (' ' + to_string(childern_cnt[here]));

        sort(children[here].begin(), children[here].end());
        for(int i = 0;i<children[here].size();i++){
            this_info += (' ' + children[here][i]);
        }
        family_info.push_back(this_info);

       
    }
     cout << k << "\n";

        sort(start_name.begin(), start_name.end());
        for(int i = 0;i<start_name.size();i++){
            cout << start_name[i]<<" ";
        }
        cout << "\n";
        sort(family_info.begin(), family_info.end());
        for(int i = 0;i<family_info.size();i++){
            cout << family_info[i] << "\n";
        }
    return 0;
}