#include <bits/stdc++.h>

using namespace std;

const int N=100000,LEN=1000000;
const char vowels[]={'a','e','i','o','u'};
int ans2[N];
bool isVowels[256];
bool vis[N];
char s[LEN+1];

struct Word {
    int nVowels;
    char *word,lastVowels;
    bool operator<(const Word& b) const {
        return nVowels==b.nVowels?lastVowels<b.lastVowels:nVowels<b.nVowels;
    }
} word[N];

int main() {
    for (int i=0;i<5;++i) isVowels[vowels[i]]=true;
    int n,ans=0,cnt=0;
    scanf("%d",&n);
    for (int i=0;i<n;++i) {
        scanf("%s",s);
        word[i].word=new char[strlen(s)+1];
        strcpy(word[i].word,s);
        for (int j=0;s[j];++j)
            if (isVowels[s[j]]) {
                ++word[i].nVowels;
                word[i].lastVowels=s[j];
            }
    }
    //puts("%%");
    sort(word,word+n);
    //for (int i=0;i<n;++i) puts(word[i].word);
    for (int i=0;i<n-1;++i)
        if (word[i].nVowels==word[i+1].nVowels) {
            ++ans;
            ++i;
        }
    if (ans&1) --ans;
    //printf("%d\n",ans);
    for (int i=0;i<n-1&&cnt<ans;++i) 
        if (word[i].nVowels==word[i+1].nVowels&&word[i].lastVowels==word[i+1].lastVowels) {
            vis[i]=vis[i+1]=true;
            ans2[cnt++]=i;
            ans2[cnt++]=i+1;
            ++i;
        }
    printf("%d\n",cnt>>1);
    for (int i=0,j=0;i<n-1&&j<cnt;++i)
        if (!vis[i])
            for (int k=i+1;k<n&&word[k].nVowels==word[i].nVowels;++k)
                if (!vis[k]) {
                    vis[k]=true;
                    printf("%s %s\n",word[i].word,word[ans2[j++]].word);
                    printf("%s %s\n",word[k].word,word[ans2[j++]].word);
                    break;
                }
    return 0;
}