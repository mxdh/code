#include <cstring>

const int N_CHAR = 26, N = 100, LEN = 100;

class Trie_Tr {
  public:
    Trie_Tr() {
        n_node = 1;
        n_str = 0;
        node[0].init();
    }
    void insert(const char *const str) {
        int k = 0;
        for (int i = 0; str[i]; i++) {
            if (!node[k].k[str[i] - 'a']) {
                node[n_node].init();
                node[k].k[str[i] - 'a'] = n_node++;
            }
            k = node[k].k[str[i] - 'a'];
        }
        if (!node[k].n_end) {
            node[k].k_end = n_str;
            strcpy(this->str[n_str++], str);
        }
        node[k].n_end++;
    }

  private:
    int n_node, n_str;
    struct Node {
        inline void init() {
            memset(k, 0, sizeof k);
            n_end = k_end = 0;
        }
        int k[N_CHAR], n_end, k_end;
    } node[N * LEN];
    char str[N][LEN + 1];
} trie_tr;