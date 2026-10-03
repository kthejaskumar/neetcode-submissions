class CountSquares {
private:
    unordered_map<long,int> ptsCount;
    vector<vector<int>> points;

    long getkey(int x, int y){
        return (static_cast<long>(x)<<32 | static_cast<long>(y));
    }
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        long key = getkey(point[0],point[1]);
        ptsCount[key]++;
        points.push_back(point);
    }
    
    int count(vector<int> point) {
        int res=0;
        int px = point[0], py = point[1];
        for(auto pt: points){
            int x = pt[0], y = pt[1];
            if(abs(px-x)==abs(py-y) && x!=px && y!=py){
                res+= ptsCount[getkey(x,py)]*ptsCount[getkey(px,y)];
            }
        }
        return res;
    }
};
