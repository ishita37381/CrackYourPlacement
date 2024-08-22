class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int i)
    {
        if(i == parent[i])
                return  i;
        return parent[i]=find(parent[i]);
    }

    void Union(int x ,int y)
    {
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent)
        return;

        if(rank[x_parent]>rank[y_parent])
        {
            parent[y_parent]=x_parent;
        }
        else if(rank[x_parent]<rank[y_parent])
        {
            parent[x_parent]=y_parent;
        }
        else{
            rank[x_parent]++;
            parent[y_parent]=x_parent;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        parent.resize(edges.size()+1);
        rank.resize(edges.size()+1,0);

        for(int i = 1;i<=edges.size();i++)
        {
            parent[i]=i;
        }

        for(auto edge : edges)
        {
            int x_parent = find(edge[0]);
            int y_parent = find(edge[1]);

            if(x_parent == y_parent)
            {
                return edge;
            }
            else{
                Union(edge[0],edge[1]);
            }
        }
        
        return {};
    }
};
