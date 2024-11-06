#include <bits/stdc++.h>
using namespace std;
std::map<string, bool> visited;
std::map<int, vector<int>> adj;
std::map<int, bool> adjEdit;
vector<string> Output;
vector <string> TokenList;
string dfs(int i,string history) {
	bool k;
	if (adjEdit.find(i) == adjEdit.end())
		k = true;
	else
		k = adjEdit[i];
	vector<string> localOut;
	history = history + TokenList[i] + '/';
	if (i == 0)
	    history = "/";
	for (auto u : adj[i]) {
		string a = dfs(u,history);
		if (a == ""){
		    k = false;
            continue;
		}
		localOut.push_back(a);
	}
	if (k){
	    if (history == "/")
	        return history;
	    history.pop_back();
	    return history;
	}
	if (localOut.empty())
	    return "";
	for (auto u:localOut) cout << u << endl;
	return "";
}
pair<int,int> tokenize (string in) {

	int start = TokenList.size();
	string word;
	for (int i = 1; i < in.length(); i++)
	{
		char a = in[i];
		if (i == in.length() - 1)
		{
			TokenList.push_back(word + a);
			continue;
		}
		if (a == '/')
		{
			TokenList.push_back(word);
			word = "";
			continue;
		}
		word = word + a;
	}
	return {TokenList.size() - 1,start};
}

int main()
{
	int N;
	cin >> N;
	std::map<int, bool> adjTruth;
    TokenList.push_back("/");
	for (int i = 0; i < N; i++) {
		bool edited;
		cin >> edited;
		string in;
		cin >> in;
		int prec, start;
	    pair<int,int> temp = tokenize(in);
	    prec = temp.first;
	    start = temp.second;
		adjEdit[prec] = edited;
		for (int i = prec - 1; i >= start; i--)
		{
			if (adjTruth[prec])
				continue;
			adj[i].push_back(prec);
			adjTruth[prec] = true;
			prec = i--;
		}
		if (adjTruth[prec])
			continue;
		adjTruth[prec] = true;
		adj[0].push_back(prec);
	}
    cout << dfs(0,"");
	return 0;
}
