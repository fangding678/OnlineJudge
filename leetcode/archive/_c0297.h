//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "#_";
        }
        string res = to_string(root->val) + "_";
        res += serialize(root->left);
        res += serialize(root->right);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string node;
        queue<string> qu;
        while (getline(ss, node, '_')) {
            qu.push(node);
        }
        return helper(qu);
    }
    TreeNode* helper(queue<string> &qu) {
        string val = qu.front();
        qu.pop();
        if (val == "#") {
            return NULL;
        }
        TreeNode *t = new TreeNode(stoi(val));
        t->left = helper(qu);
        t->right = helper(qu);
        return t;
    }

};


void func() {
    Codec codec;
    string data = "1_2_3_#_#_4_5_#_#_#_#_";
    TreeNode *t = codec.deserialize(data);
    cout << t->val << endl;
}

