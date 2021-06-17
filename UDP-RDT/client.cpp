#include "UDP_RDT_SOCKET.hpp"
// #include "UDP_SOCKET.hpp"
// #include "SOCKET.hpp"

using namespace std;

// Driver code
int main() {
	//std::string servIP = "34.94.147.12", servPort = "8080";
	std::string servIP = "127.0.0.1", servPort = "8080";

	RDT::UdpSocket client_socket(servIP, servPort);

	std::string text_msg;

	for(int i = 0; i < 1000; ++i){
		text_msg += std::to_string(i);
	}
	cout << "tamaño del mensaje: " << text_msg.size() << endl;
	
	
	u_char message[MAX_DGRAM_SIZE];
	for(int i = 0; i < MAX_DGRAM_SIZE; ++i)
	{
		message[i] = text_msg[i];
	}

	int bytes_sent = 0;	
	for(int i = 0; i < 5; ++i) {
		//cout << "mensaje enviado: " << text_msg << endl;
		std::cout << client_socket.send(text_msg) << std::endl;
	}


	return 0;
}