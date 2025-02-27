#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>

using namespace std;
vector<int> prevec;
vector<int> postvec;
map<int, vector<int>> tree; // key: node value: [x, y, left, right]

bool cmp(vector<int> v1, vector<int> v2){
    if(v1[1] == v2[1]){
        return v1[0] < v2[0];
    }
    else return v1[1] > v2[1];
}

// 전위 순회
vector<int> preorder(int node){
    // 현재 노드 출력
    prevec.push_back(node);
    // 왼쪽 자식이 있다면
    if(tree[node][2] != 0){
        preorder(tree[node][2]);
    }
    // 오른쪽 자식이 있다면
    if(tree[node][3] != 0){
        preorder(tree[node][3]);
    }
    return prevec;
}

// 후위 순회
vector<int> postorder(int node){
    // 왼쪽 자식이 있다면
    if(tree[node][2] != 0){
        postorder(tree[node][2]);
    }
    // 오른쪽 자식이 있다면
    if(tree[node][3] != 0){
        postorder(tree[node][3]);
    }
    // 현재 노드 출력
    postvec.push_back(node);
    return postvec;
}

void setTree(int par, int node){
    if(tree[par][0] > tree[node][0]){
        if(tree[par][2] == 0){
            tree[par][2] = node;
        }
        else{
            setTree(tree[par][2], node);
        }
    }
    else{
        if(tree[par][3] == 0){
            tree[par][3] = node;
        }
        else{
            setTree(tree[par][3], node);
        }
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    // 이진트리 구조 생성
    // y값을 기준으로 내림차순, x값을 기준으로 오름차순 정렬
    // 7 4 2 6 1 3 9 8 5
    for(int i = 1; i <= nodeinfo.size(); i++){
        // nodeinfo에 노드 번호 추가
        nodeinfo[i-1].push_back(i);
    }
    sort(nodeinfo.begin(), nodeinfo.end(), cmp);
    
    // map 초기화
    for(int i = 0; i < nodeinfo.size(); i++){
        tree[nodeinfo[i][2]] = {nodeinfo[i][0], nodeinfo[i][1], 0, 0};
    }
    
    // 노드별로 왼쪽, 오른쪽 자식 탐색해서 map으로 저장 / 없으면 0
    // 노드 번호 : [왼쪽 자식, 오른쪽 자식]
    for(int i = 1; i < nodeinfo.size(); i++){
        setTree(nodeinfo[0][2], nodeinfo[i][2]);
    }
    
    answer.push_back(preorder(nodeinfo[0][2]));
    answer.push_back(postorder(nodeinfo[0][2]));
    
    return answer;
}