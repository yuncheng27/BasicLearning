template <class T> class Tree {
//对象：树是由n个节点组成的有限集合。在类界面中的position是树中节点的地址
//在顺序存储方式下是下标型，在链式存储方式下是指针型。T是树节点中存放数据的类型，要求所有节点的数据类型都是一样的

  public:
    Tree();     //构造函数，生成树的结构并初始化
    ~Tree();    //析构函数，释放树所占存储
    position Root();   //返回根节点地址，若树为空，则返回0
    BuildRoot(const T& value);    //建立树的根节点
    position FirstChild(position p);   //返回p第一个子女地址，无子女返回0
    position NextSibling(position p);   //返回p下一兄弟地址，若无则返回0
    position Parent(position p);    //返回p父节点地址，若无则返回0
    T getData(position p);    //函数返回节点p中存放的值
    bool InsertChild(const position p, const T& value);  //在节点p下插入值为value的新子女
    bool DeleteChild(position p, int i);    //删除节点p的第i个子女及其全部子孙节点
    void DeleteSubTree(position t);     //删除以t为根节点的子树
    bool IsEmpty();     //判树空否，空返回true
    void Traversal(void (* visit)(position p));    //遍历，visit是用户自编的访问节点p数据的函数
};
