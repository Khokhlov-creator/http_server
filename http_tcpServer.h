#ifndef HTTP_SERVER_HTTP_TCPSERVER_H
#define HTTP_SERVER_HTTP_TCPSERVER_H

#include <stdio.h>
#include <winsock.h>
#include <stdlib.h>
#include <string>

namespace http{
    class TcpServer{
    public:
        TcpServer(std::string ip_address, int port);
        ~TcpServer();
        coid startListen();

    private:
        std::string m_ip_address;
        int m_port;
        SOCKET m_socket;
        SOCKET m_new_socket;
        long m_incomingMessage;
        struct sockaddr_in m_socketAddress;
        int m_socketAddress_len;
        std::string m_serverMessage;
        WSADATA m_wsaData;

        int startServer();
        void closeServer();
        coid acceptConnection(SOCKET &new_socket);
        std::string buildResponse();
        void sendResponse();
    };
}//namespace http;

#endif //HTTP_SERVER_HTTP_TCPSERVER_H
