#include <bits/stdc++.h>
using namespace std;
vector<string> tokenize (string in){
    
    vector<string> tokens;
    string word;
    for (int i = 1; i < in.length(); i++)
    {
        char a = in[i];
        if (a == '/' || i == in.length() - 1)
        {
            tokens.push_back(word);
            word = "";
            continue;
        }
        word = word + a;
    }
    return tokens;
    
}

int main()
{
    int N;
    cin >> N;
    //std::map<string, int> mappa;
    //std::vector<vector<int>> adj;
    std::map<string, bool> adjTruth;
    std::map<string, vector<string>> adj;
    for (int i = 0; i < N; i++){
        bool edited;
        cin >> edited;
        string in; 
        cin >> in;
        vector<string> Tokens(tokenize(in));
        std::reverse(Tokens.begin(), Tokens.end());
        string prec = Tokens[0];
        for (int i = 1; i < Tokens.size(); i++)
        {
            if (adjTruth[prec])
                continue;
            adj[Tokens[i]].push_back(prec);
            adjTruth[prec] = true;
            prec = Tokens[i];
        }
        if (adjTruth[prec])
            continue;
        adjTruth[prec] = true;
        adj["/"].push_back(prec);
    }

    return 0;
}
