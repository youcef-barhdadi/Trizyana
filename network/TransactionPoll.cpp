

#include <iostream>
# include <iostream>
# include <string>
#include <vector>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <sstream>

#include "../types/Transaction.hpp"


// here we will implemnt  a server will listen to recive transaction and add then to pool 


using namespace std;

vector<string> split (const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}


/*
    transaction formt  :   SENDER | RECIVER | AMOUNT |   SIGNATURE
*/
void TransactionParser(string transaction)
{
        vector<string> tokens = split(transaction, '|');

        if (tokens.size() != 3)
        {
            // reject the transaction
        }

        Transaction *t = new Transaction();

        t->senderAdress = tokens[0];
        t->ReciverAdress = tokens[1];
        t->Amount = std::stod(tokens[2]);
        t->signature = tokens[3];
}



void    reciveTransactin()
{
        socklen_t addrlen;
        char buffer [256];
        string transaction;

    	int	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	    struct  sockaddr_in address;
		memset((char *)&address, 0, sizeof(address));
		address.sin_family = AF_INET;
		address.sin_addr.s_addr= INADDR_ANY;
		address.sin_port =htons(6969);
        int ret =  bind(server_fd, (struct sockaddr *)&address , sizeof(address));
         ret = listen(server_fd, 1000);
         while (1)
         {
            int new_socket = accept(server_fd , (struct sockaddr *)&address, (socklen_t*)&addrlen);

            while (( ret  = read(new_socket, buffer , 255) ))
            {

                buffer[ret] = '\0';
                std::string copy = std::string(buffer);
                transaction +=  copy;
            }
            TransactionParser(transaction);
         }
}


int main()
{
        Transaction pool;

        reciveTransactin();
}