class Solution {
public:
    bool DFS(vector<vector<int>>& graph,int node,vector<int>&color,int nodeColor)
    {
        for(auto v:graph[node])
        {
            if(color[v]==nodeColor)
            {
                return false;
            }else if(color[v]==-1)
            {
                int c = 1-nodeColor;
                color[v]=c;
                if(DFS(graph,v,color,c)==false)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V,-1);
        for(int i=0;i<V;i++)
        {
            if(color[i]==-1)
            {
                color[i]=1;
                if(DFS(graph,i,color,color[i])==false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};