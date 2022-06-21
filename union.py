class DisjointSet:
    parent = {}
 
    def Set(self, uni):
        for i in uni:
            self.parent[i] = i
 
    def Find(self, j):
        if self.parent[j] == j:
            return j
        return self.Find(self.parent[j])
 
    
    def Union(self, m, n):

        u = self.Find(m)
        v = self.Find(n)
 
        self.parent[u] = v
 
 
def printSets(uni, ds):
    print([ds.Find(i) for i in uni])
 
 
if __name__ == '__main__':
 

    uni = [1, 3, 5, 4, 2]
 
    ds = DisjointSet()
 
    ds.Set(uni)
    printSets(uni, ds)
 
    ds.Union(2, 3) 
    printSets(uni, ds)
 
    ds.Union(1, 2) 
    printSets(uni, ds)
 
    ds.Union(1, 4) 
    printSets(uni, ds)
 
