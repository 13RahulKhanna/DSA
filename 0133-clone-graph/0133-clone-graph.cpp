
class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;

        if(mp.find(node) != mp.end())
            return mp[node];

        Node* clone = new Node(node->val);
        mp[node] = clone;

        for(auto nei : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(nei));
        }

        return clone;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna