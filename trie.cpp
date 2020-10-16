#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node{
	char value;
	vector<int> ending_index;
	Node* arr[30];      
};

Node* createNewNode (){
	Node* newNode = new Node;
	for(int i = 0;i < 30;++i)newNode->arr[i] = NULL;
	return newNode;
}

void printall(Node* head,string prv){
	if(head == NULL)return ;
	for(auto &x:head->ending_index)cout << x << " " << prv << "\n";
	for(int i = 0;i < 30;++i)if(head->arr[i] != NULL)printall(head->arr[i],prv+char('a'+i));
}

int main() {
	// your code goes here
	Node* root = createNewNode();
	int n;
	cin >> n;
	vector<string>v;
	for(int i = 0;i < n;++i){
		string s;
		cin >> s;
		Node* head = root;
		for(int j = 0;j < (int)s.size();++j){
			if(head->arr[s[j]-'a'] != NULL){
				head = head->arr[s[j]-'a'];
			}
			else {
				head->arr[s[j]-'a'] = createNewNode();
				head = head->arr[s[j]-'a'];
				head->value = s[j];
			}
			if(j == (int)s.size()-1)head->ending_index.push_back(i);
		}
	}
	printall(root,"");
	return 0;
}