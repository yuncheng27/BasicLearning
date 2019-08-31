#include <>

class TcpSocket;
class Select
{
    private:
        int _max_fd;
        fd_set _rfds;
        std::unordered_map<int, TcpSocket> _map;
    public:
        bool Add(TcpSocket sock)
        {
            int fd = sock.GetFd();
            FD_SET(fd, &_rfds);
            _map[fd] = sock;
            //_map.insert(make_pair(fd, sock));
            return true;
        }
        bool Del(TcpSocket sock);
        bool Wait(std::vector<TcpSocket> *list);
};
