class Solution {
private:
    unordered_map<Node*, Node*> nodeMap;
    
    void dfs(Node* node) {
        Node* cloneNode = nodeMap[node];
        for(auto n: node->neighbors) {
            if (nodeMap.find(n)==nodeMap.end()) {
                nodeMap[n] = new Node(n->val);
                dfs(n);
            }
            cloneNode->neighbors.push_back(nodeMap[n]);
        }
        return;
    }

public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        
        Node* firstNode = new Node(node->val);
        nodeMap[node] = firstNode;
        
        dfs(node);
        
        return firstNode;
    }
};