#include <packet_parser.hpp>

#include <iostream>
#include <vector>

int main() {
    std::vector<uint8_t> buf = {0x00,0x01, 0x00,0x00,0x00,0x03, 'a','b','c'};

    auto result = PacketParser::Parse(buf);

    if (!result) {
        std::cerr << "Parse failed: " << result.ErrorMessage() << "\n";
        return 1;
    }

    const Packet& pkt = result.GetPacket();
    std::cout << "Type=" << pkt.type
              << " Length=" << pkt.length
              << " Body=" << std::string(pkt.body.begin(), pkt.body.end())
              << "\n";

    return 0;
}
