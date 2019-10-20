/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

LINK: https://www.interviewbit.com/problems/clone-graph/
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    
        unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> m;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        
        UndirectedGraphNode* ret, *tmp;
        vector<UndirectedGraphNode*> nb;
        
        ret = new UndirectedGraphNode(node->label);
        m[node] = ret;
        
        while(!q.empty()){
            UndirectedGraphNode* curr = q.front();
            q.pop();

            for(auto n:curr->neighbors){
                if(m.find(n)!=m.end()){
                    nb.push_back(m[n]);
                }else{
                    tmp = new UndirectedGraphNode(n->label);
                    m[n] = tmp;
                    nb.push_back(tmp);
                    q.push(n);
                }
                
            }
            
            m[curr]->neighbors = nb;
            nb.clear();

        }
        
        return ret;

}
