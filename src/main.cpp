#include <iostream>


int main(int argc, char** argv) {
    // ./chat -h or chat --help
    // ./chat [type] [server] [port]
    // ./chat -c/-s or --client/--server
    // for server: ./chat -s/--server [port]
    // for client: ./chat -c/--client [server] [port]

    // 3 -> server
    // 4 -> client
    
    std::string server = "localhost";
    int port = 5000;

    // check arguments
    if (argc != 3 && argc != 4 && argc != 2) {
        std::cout << "Usage: " << argv[0] << " [type] [server] [port]" << std::endl;
        std::cout << "[type]: c/s" << std::endl;
        std::cout << "[server: only for client]: server address" << std::endl;
        std::cout << "[port]: port number" << std::endl;
        return 1;
    }
    
    const char type = *argv[1];
    switch (type) {
        case 's': {
            // server
            if (argc == 3) {
                port = std::stoi(argv[2]);
            }

            std::cout << "Running server on port: " << port << std::endl;
            break;
        } 
        case 'c': {
            // client
            if (argc == 4) {
                server = argv[2];
                port = std::stoi(argv[3]);
            }

            std::cout << "Running client with server: " << server << "; port: " << port << std::endl;
            break;
        }
        default: {
            std::cout << "Usage: " << argv[0] << " [type] [server] [port]" << std::endl;
            std::cout << "[type]: c/s" << std::endl;
            std::cout << "[server: only for client]: server address" << std::endl;
            std::cout << "[port]: port number" << std::endl;
            return 1;
        }
    }


    return 0;
}
