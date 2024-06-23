// tcp-client.cpp
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <thread>

using namespace boost::asio;
using ip::tcp;
using std::string;
using std::cout;
using std::endl;

string getFirstLine(const string& input) {
    size_t pos = input.find('\n');  // Encontrar la posición del primer '\n'
    
    if (pos != std::string::npos) {
        return input.substr(0, pos);  // Devolver la subcadena hasta esa posición
    } else {
        return input;  // Si no se encuentra '\n', devolver la cadena completa
    }
}

void readHandler(tcp::socket& socket, std::atomic<bool>& server_running) {
  boost::asio::streambuf buffer;
  boost::system::error_code error;

  while (true) {
    boost::asio::read_until(socket, buffer, "\n", error);
    if (error) {
      if (error == boost::asio::error::eof || error == boost::asio::error::connection_reset) {
        server_running.store(false);
        break;
      } else {
        throw boost::system::system_error(error);
      }
    }
    string message = getFirstLine(boost::asio::buffer_cast<const char*>(buffer.data()));
    buffer.consume(buffer.size());
    cout << message << endl;
  }
}

int main() {
  std::atomic<bool> server_running(true);
  bool exit_chat = false;

  try {
    boost::asio::io_service io_service;
    tcp::socket socket(io_service);
    socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234));

    cout << "Connected to the server. You can start typing messages..." << endl;

    std::thread reader_thread(readHandler, std::ref(socket), std::ref(server_running));

    string message;
    while (server_running && !exit_chat) {
      std::getline(std::cin, message);
      message += "\n";
      boost::asio::write(socket, boost::asio::buffer(message));
      if (message == "exit\n") {
        exit_chat = true;
      }
    }
    socket.close();
    reader_thread.join();
  } catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << endl;
  }
  if (!server_running) {
    cout << "Disconnected from server." << endl;
  }
  return 0;
}

