const long long is_query = -(1LL<<30);
template <typename type_T>
struct ConvexHull_Lines{
    struct line{
        type_T m;
        type_T b;
        Line(type_T slope, type_T y_intercept): m(slope), b(y_intercept) {}
        //comparator for when inside multiset
        mutable function<const line*()> neighbor;
        bool operator<(const line& rhs) const{
            if(rhs.b != is_query){
                return m<rhs.m;
            }
            //need a new succ function declaration below
            const line* s = succ();
            if(!s) return false;
            type_T x = rhs.m;
            //check if other is bigger m*x + b < ms*x+bs, b-bs<ms*x-m*x, x*(ms-m)
            return b-s->b < (s->m-m) * x;
        }
    };
    //maintain a multiset of lines such that we can compare lines
    
    multiset<line> lines;
    bool redundant(line l){
        auto i = lines.lower_bound(l)

    }
    void add_line(type_T m, type_T b){
        lines.insert(line(m, b));
    }


};
