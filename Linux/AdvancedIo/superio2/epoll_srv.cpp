
class Epoll
{
    private:
        int _epfd;  //epoll句柄--贯穿上下文
        //保存描述符与TcpSocket对应关系
        std::unordered_map<int, TcpSocket> _map;
    public:
        Epoll():_epfd(-1) {}
        //创建epoll
        bool Create();
        //向内核epoll结构中添加事件节点
        bool Add(TcpSocket &sock, uint32_t events = EPOLLIN);
        //从内核epoll结构中移除事件节点
        bool Del(TcpSocket &sock);
        //开始监控，并且获取就绪TcpSocket
        bool Wait(std::vector<TcpSocket> *list);
};
