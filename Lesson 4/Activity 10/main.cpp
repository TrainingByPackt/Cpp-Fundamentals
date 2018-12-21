#include <connection.h>
#include <useraccount.h>

template<typename Object, typename Connection>
void writeObjectToConnection(Connection& con, const Object& obj) {
    std::array<char, 100> data = obj.serialize(obj);
    con.writeNext(data);
}

// Read an object from a generic connection.
// The connection needs to have a 'readNext()' method which
// returns an array of 100 chars.
// The object must have a static 'deserialize' function
// which crates a new instance of the objects from an array of 100 chars
template<typename Object, typename Connection>
Object readObjectFromConnection(Connection& con) {
    // Inside the function we can use Object as if it was a real type
    std::array<char, 100> data = con.readNext();
    return Object::deserialize(data);
}


int main() {
    // Create an account
    UserAccount source(1, "something@email.com");
    std::cout << "Original: " << source << std::endl;

    // Create a local TCP connection
    TcpConnection tcpConnection;
    // Write the account to the connection
    writeObjectToConnection(tcpConnection, source);

    // Read an usere account from the content in the connection
    // We explicitly specify the type of the object to read
    UserAccount userAccountTcp = readObjectFromConnection<UserAccount>(tcpConnection);
    std::cout << "Deserialized on TCP: " << userAccountTcp << std::endl;

    // Create a local UDP connection and serialize the object into it.
    // Note: the template just works, we don't have to write a new function for the new
    //       connection!
    UdpConnection udpConnection;
    writeObjectToConnection(udpConnection, source);
    UserAccount userAccountUdp = readObjectFromConnection<UserAccount>(udpConnection);
    std::cout << "Deserialized on UDP: " << userAccountUdp << std::endl;
}
