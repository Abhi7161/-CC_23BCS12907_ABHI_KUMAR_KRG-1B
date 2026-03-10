#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<string> words(n);
    for(int i=0;i<n;i++)
    cin>>words[i];
    vector<bitset<32>> bitmasked;
    int maxLen=0;
    for(int i=0;i<n;i++)
    {
        bitset<32> bits1;
        for(auto ch: words[i]) bits1.set(ch-'a');
        bitmasked.push_back(bits1);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if((bitmasked[i] & bitmasked[j]).none())
            {
                maxLen=max(maxLen,(int)(words[i].length()*words[j].length()));
            }
        }
    }
    cout << maxLen << endl;
    return 0;
}