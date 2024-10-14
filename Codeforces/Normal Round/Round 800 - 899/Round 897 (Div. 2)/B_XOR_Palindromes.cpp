#include <bits/stdc++.h>
using namespace std;
class Node {
   public:
    int EoW;
    Node *children[26];
    Node() {
        EoW = 0;
        for (int i = 0; i < 26; i++) {
            this->children[i] = NULL;
        }
    }
};
void trie_insert(Node *root, string s) {
    Node *u = root;
    for (int k = 0; k < s.size(); k++) {
        int r = s[k] - 65;
        if (u->children[r] == NULL)
            u->children[r] = new Node;
        u = u->children[r];
    }
    u->EoW = u->EoW + 1;
    // cout << u->EoW << endl;
}
int trie_search(Node *root, string s, int k = 0) {
    Node *u = root;
    for (int k = 0; k < s.size(); k++) {
        int r = s[k] - 65;
        if (u->children[r] == NULL)
            return 0;
        u = u->children[r];
    }
    return u->EoW;

    /*
    if(u == NULL)
        return 0;
    if(k == s.size())
        return u->EoW;
    int r = s[k] - 65;
    return trie_search(u->children[r], s, ++k);
    */
}
// lexicographical sort
void printTRIE(Node *root, string s = "") {
    Node *cur = root;
    if (cur->EoW > 0)
        cout << s << " - " << cur->EoW << endl;
    for (int i = 0; i < 26; i++) {
        if (cur->children[i] != NULL) {
            char temp = i + 65;
            printTRIE(cur->children[i], s + temp);
        }
    }
}

void removeEdge(Node *cur, char c, int d) {
    if (d == 0)
        return;
    int r = c - 'A';
    Node *v = cur->children[r];
    cur->children[r] = NULL;
    delete v;
}
bool isLeaf(Node *cur) {
    for (int i = 0; i <= 26; i++)
        if (cur->children[i] != NULL)
            return false;
    return true;
}
bool isJunction(Node *cur) {
    int cnt = 0;
    for (int i = 0; i <= 26; i++)
        if (cur->children[i] != NULL)
            cnt++;
    if (cur->EoW > 0 && cnt > 1)
        return true;
    return false;
}

int deleteTRIE(Node *root, string s, int k) {
    Node *cur = root;
    if (cur == NULL)
        return 0;
    if (k == s.length()) {
        if (cur->EoW == 0)
            return 0;
        if (!isLeaf(cur)) {
            cur->EoW--;
            return 0;
        }
        else if (isLeaf(cur) && cur->EoW > 1) {
            cur->EoW--;
            return 0;
        }
        return 1;
    }
    int r = s[k] - 65;
    int d = deleteTRIE(cur->children[r], s, k + 1);
    int j = isJunction(cur);
    removeEdge(cur, s[k], d);
    if (j == 1)
        d = 0;
    return d;
}
int main() {
    Node *root = new Node();

    while (1) {
        cout << "1. Insert\n2. Search\n3. Delete\n4. Lexicographical "
                "Sorting\n5. Display Strings\n6. End"
             << endl
             << endl;
        int choice;
        string x;
        cin >> choice;
        if (choice == 1) {
            cout << "Insert String: ";
            cin >> x;
            trie_insert(root, x);
            cout << x << " is inserted in the trie" << endl;
        }
        else if (choice == 2) {
            cout << "Enter string to search: ";
            cin >> x;
            if (trie_search(root, x) > 0)
                cout << x << " FOUND " << endl;
            else
                cout << x << " NOT FOUND " << endl;
        }
        else if (choice == 3) {
            string x;
            cout << "Enter element which you want to delete: ", cin >> x;
            if (trie_search(root, x) <= 0)
                cout << "Element isnot present in the TIRE.\n";
            else
                deleteTRIE(root, x, 0), cout << "Element deleted.\n";
            // cout<<"Not yet implemented."<<endl;
        }
        else if (choice == 4) {
            printTRIE(root);
        }
        else if (choice == 5) {
            printTRIE(root);
        }
        else if (choice == 6) {
            break;
        }
        else {
            cout << "Invalid Choice" << endl;
            break;
        }
        cout << endl;
    }
}
/*inputs:

1 MIST
1 MIT
1 CSE
1 CSE
1 CE
1 MISTCSE
1 ME
1 EECE
1 ABC
1 ABC
1 AB

*/