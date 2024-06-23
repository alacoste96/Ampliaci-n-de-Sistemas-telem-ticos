// tcp-server.cpp
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <boost/asio.hpp>
#include <thread>
#include <mutex>

using namespace boost::asio;
using ip::tcp;
using std::string;
using std::cout;
using std::endl;

std::vector<std::shared_ptr<tcp::socket>> clients;
std::mutex clients_mutex;

string getFirstLine(const string& input) {
    size_t pos = input.find('\n');  // Encontrar la posición del primer '\n'
    
    if (pos != std::string::npos) {
        return input.substr(0, pos);  // Devolver la subcadena hasta esa posición
    } else {
        return input;  // Si no se encuentra '\n', devolver la cadena completa
    }
}

void disconectClient(std::shared_ptr<tcp::socket> client_socket) {
  std::lock_guard<std::mutex> guard(clients_mutex);
  clients.erase(std::remove(clients.begin(), clients.end(), client_socket), clients.end());
  cout << "Client " << client_socket->remote_endpoint().port() << " disconnected." << endl;
}

void send2all(std::shared_ptr<tcp::socket> client_socket, string message){
  boost::system::error_code error;

  std::lock_guard<std::mutex> guard(clients_mutex);
  for (auto& client : clients) {
    if (client != client_socket) {
      boost::asio::write(*client, boost::asio::buffer(message), error);
    }
  }
}

void readFromClient(std::shared_ptr<tcp::socket> client_socket) {
  boost::asio::streambuf buffer;
  boost::system::error_code error;
  string message;

  cout << "Client connected from IP: " << client_socket->remote_endpoint().address().to_string() 
       << " and port: " << client_socket->remote_endpoint().port() << endl;
  send2all(client_socket, "Server: " + std::to_string(client_socket->remote_endpoint().port()) 
                          + " joined the lobby.\n");
  while (true) {
    boost::asio::read_until(*client_socket, buffer, "\n", error);
    if (error) {
      if (error == boost::asio::error::eof || error == boost::asio::error::connection_reset) {
        send2all(client_socket, "Server: " + std::to_string(client_socket->remote_endpoint().port())
                                + " left the lobby.\n");
        disconectClient(client_socket);
        break;
      } else {
          throw boost::system::system_error(error);
      }
    }
    message = getFirstLine(boost::asio::buffer_cast<const char*>(buffer.data()));
    buffer.consume(buffer.size());
    if (message == "exit") {
      send2all(client_socket, "Server: " + std::to_string(client_socket->remote_endpoint().port()) + " left the lobby.\n");
      disconectClient(client_socket);
      break;
    }
    message = std::to_string(client_socket->remote_endpoint().port()) 
              + " says: " + message + "\n";
    send2all(client_socket, message);
  }
}

int main() {
  try {
    boost::asio::io_service io_service;
    tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 1234));

    cout << "Server listening on port 1234 and IP 127.0.0.1 ..." << endl;

    while (true) {
      auto client_socket = std::make_shared<tcp::socket>(io_service);
      acceptor.accept(*client_socket);

      std::lock_guard<std::mutex> guard(clients_mutex);
      clients.push_back(client_socket);

      std::thread(readFromClient, client_socket).detach();
      }
  } catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << endl;
  }

  return 0;
}



