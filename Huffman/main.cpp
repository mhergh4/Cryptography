#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;

class Node {
public:
    char s;
    int f;
    Node* l;
    Node* r;
    Node(char s, int f) : s(s), f(f), l(nullptr), r(nullptr) {}
};

class Comparator {
public:
    bool operator()(Node* a, Node* b) {
        return a->f > b->f;
    }
};

Node* buildTree(int freqs[]) {
    priority_queue<Node*, vector<Node*>, Comparator> pq;

    for (int i = 0; i < 256; ++i) {
        if (freqs[i] > 0) {
            Node* n = new Node(static_cast<char>(i), freqs[i]);
            pq.push(n);
        }
    }

    while (pq.size() > 1) {
        Node* l = pq.top();
        pq.pop();

        Node* r = pq.top();
        pq.pop();

        Node* combined = new Node('\0', l->f + r->f);
        combined->l = l;
        combined->r = r;

        pq.push(combined);
    }
    return pq.top();
}

void generateCodes(Node* root, string code, string codes[]) {
    if (root != nullptr) {
        if (root->s != '\0') {
            codes[static_cast<int>(root->s)] = code;
        }

        generateCodes(root->l, code + "0", codes);
        generateCodes(root->r, code + "1", codes);
    }
}

int main() {
    int freqs[256] = { 0 };

    freqs['Y'] = 15;
    freqs['Z'] = 22;
    freqs['W'] = 10;
    freqs['K'] = 18;
    freqs['L'] = 27;
    freqs['X'] = 8;

    Node* root = buildTree(freqs);

    string codes[256];
    generateCodes(root, "", codes);

    cout << "Codes:" << endl;
    for (int i = 0; i < 256; ++i) {
        if (!codes[i].empty()) {
            cout << static_cast<char>(i) << ": " << codes[i] << endl;
        }
    }
    return 0;
}
