#include<iostream>
#include<string>
#include<unistd.h>

#include "UdpSocket.hpp"

#define CHECK_RET(q) if((q)==false){return -1;}
int main(int argc,char *argv[])
{
    //argc表示程序运行的参数个数
    // ./udp_srv 192.168.2.2 9000
    if(argc!=3){
        std::cout<<"Usage: ./udp_cli ip port\n";
        return -1;
    }
    uint16_t svr_port=std::stoi(argv[2]);
    std::string svr_ip=argv[1];

    UdpSocket cli_sock;
    //创建套接字
    CHECK_RET(cli_sock.Socket());
    //绑定地址信息
    //CHECK_RET(cli_sock.Bind(ip,port));
    while(1){
        //发送数据
       std::cout<<"client say:";
       std::string buf;
       std::cin>>buf;
       CHECK_RET(cli_sock.Send(buf,svr_ip,svr_port));
       //接受数据  
       buf.clear();
       CHECK_RET(cli_sock.Recv(&buf));
       std::cout<<"server say:"<<buf<<std::endl;

    }

    //关闭套接字
    cli_sock.Close();
    return 0;
}