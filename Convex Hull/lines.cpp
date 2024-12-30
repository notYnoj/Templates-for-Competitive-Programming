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