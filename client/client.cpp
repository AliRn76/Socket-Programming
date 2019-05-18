#include "client.h"

using namespace std;

void main(){

    long SUCCESSFUL;
    WSAData WinSockData;
    WORD DLLVersion;
    DLLVersion = MAKEWORD(2,1);
    SUCCESSFUL = WSAStartup(DLLVersion, &WinSockData);

    string RESPONSE;
    string CONVERTER;
    char MESSAGE[200];

    SOCKADDR_IN ADDRESS;

    SOCKET sock;
    sock = socket(AF_INET, SOCK_STREAM, NULL);

    ADDRESS.sin_addr.s_addr = inet_addr("127.0.0.1");
    ADDRESS.sin_family = AF_INET;
    ADDRESS.sin_port = htons(444);

    cout<<"client: do you want to connect to this server? (Y/N)";
    cin>> RESPONSE;

    RESPONSE[0] = tolower(RESPONSE[0]);

    if(RESPONSE == "n"){
        cout<< "ok. QUITTING instead.";
    }else if(RESPONSE == "y"){
        connect(sock, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));
        SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
        CONVERTER = MESSAGE;
        cout<< "\n message from server\n\n"<<CONVERTER << endl;

    }else{
        cout<<"\n that was inappropriate response";

    }
    cout<<"\n\n";
    system("pause");
    exit(1);
}
