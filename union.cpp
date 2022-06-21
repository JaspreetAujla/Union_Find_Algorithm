#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Disjoint
{
    unordered_map<int, int> parent;
 
public:
 
    void Set(vector<int> const &uni)
    {
        for (int i: uni) 
        {
            parent[i] = i;
        }
    }
 
    int Find(int j)
    {
        if (parent[j] == j) 
        {
            return j;
        }
        return Find(parent[j]);
    }
 
    void Union(int m, int n)
    {
        int u = Find(m);
        int v = Find(n);
 
        parent[m] = n;
    }
};
 
void print(vector<int> const &uni, Disjoint &ds)
{
    for (int i: uni)
    {
        cout << ds.Find(i) << " ";
    }
    cout << endl;
}
 
int main()
{
    vector<int> uni = { 2, 4, 6, 8, 10 };
 
    Disjoint ds;
 
    ds.Set(uni);
    print(uni, ds);
 
    ds.Union(2, 3);      
    print(uni, ds);
 
    ds.Union(3, 4);      
    print(uni, ds);
 
    ds.Union(1, 2);   
    print(uni, ds);

    return 0;
}
