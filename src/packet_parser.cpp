#include <packet_parser.hpp>

ParseResult PacketParser::Parse(std::span<const uint8_t> buffer)
{
    if (buffer.size() < 6)
    {
        return ParseResult::Error("Buffer too small");
    }

    Packet pkt;
    pkt.type = (static_cast<uint16_t>(buffer[0]) << 8) | buffer[1];
    pkt.length = (static_cast<uint32_t>(buffer[2]) << 24) | (static_cast<uint32_t>(buffer[3]) << 16) | (static_cast<uint32_t>(buffer[4]) << 8) | buffer[5];

    if (buffer.size() < 6 + pkt.length)
    {
        return ParseResult::Error("Body size mismatch");
    }

    pkt.body.assign(buffer.begin() + 6, buffer.begin() + 6 + pkt.length);

    return ParseResult::Success(std::move(pkt));
}