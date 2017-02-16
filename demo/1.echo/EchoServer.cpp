#include <EchoServer.h>
#include <iostream>

#include <Log.h>

using namespace agilNet::log;
using namespace agilNet::net;
using namespace std;

EchoServer::EchoServer(IOEventLoop* loop,SocketAddr& addr)
    :TcpServer(loop,addr)
{

}

void EchoServer::connectCallback(int sockfd,const SocketAddr& addr)
{

    cout<<"new connect:"<<addr.toString() <<"<count>" <<getConnectCount()<<endl;
}
void EchoServer::messageCallback(const TcpConnect& tcpConnect, Buffer& buffer)
{
    string addr = tcpConnect.getAddr().toString();
    string data = buffer.readAllAsString();
    cout<<"thread id:"<<boost::this_thread::get_id()<<endl;
    cout<<"receive data form "<<addr<<":"<<data<<endl;
    LogOutput(info)<<"receive data form "<<addr<<":"<<data;
    write(tcpConnect.getName(),data);
}
void EchoServer::writeCompletCallback()
{

}

void EchoServer::connectCloseCallback(const TcpConnect& connect)
{
    string addr = connect.getAddr().toString();
    cout<<"close connect :"<<addr<<endl;
    LogOutput(info)<<"close connect : "<<addr;
}