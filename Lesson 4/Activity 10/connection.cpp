#include <connection.h>

std::array<char, 100> TcpConnection::readNext() {
    return data;
}

void TcpConnection::writeNext(const std::array<char, 100>& blob) {
    data = blob;
}


std::array<char, 100> UdpConnection::readNext() {
    return data;
}

void UdpConnection::writeNext(const std::array<char, 100>& blob) {
    data = blob;
}
