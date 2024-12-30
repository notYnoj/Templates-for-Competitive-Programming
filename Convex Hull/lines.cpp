//Convex Hull is a useful optimization strategy for dyanmic programming revolving around optimizations of lines
//the basic strategy is to find a way to write a statement in the equation of a line y=mx+b
template <typename type_T>
struct ConvexHull_Lines{
    struct line{
        type_T m;
        type_T b;
        Line(type_T slope, type_T y_intercept): m(slope), b(y_intercept) {}
    };
    //maintain a multiset of lines such that we can compare lines
    
    multiset<line> lines;
    bool redundant{

    }
    void add_line(T m, T b){
        lines.insert(line(m, b));
    }


};