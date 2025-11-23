#pragma once

#include <cstdint>
#include <vector>
#include <string>
#include <span>
#include <optional>

#ifdef _WIN32
  #ifdef PACKET_PARSER_EXPORTS
    #define PACKET_PARSER_API __declspec(dllexport)
  #else
    #define PACKET_PARSER_API __declspec(dllimport)
  #endif
#else
  #define PACKET_PARSER_API
#endif

struct PACKET_PARSER_API Packet {
    uint16_t type = 0;
    uint32_t length = 0;
    std::vector<uint8_t> body;
};

class PACKET_PARSER_API ParseResult {
public:
    bool HasError() const { return hasError_; }
    const std::string& ErrorMessage() const { return errorMessage_; }

    explicit operator bool() const { return !hasError_; }

    const Packet& GetPacket() const { return packet_; }

    static ParseResult Success(Packet pkt) {
        ParseResult r;
        r.packet_ = std::move(pkt);
        return r;
    }

    static ParseResult Error(const std::string& msg) {
        ParseResult r;
        r.hasError_ = true;
        r.errorMessage_ = msg;
        return r;
    }

private:
    bool hasError_ = false;
    std::string errorMessage_;
    Packet packet_;
};

class PACKET_PARSER_API PacketParser {
public:
    // parse 完整 packet
    static ParseResult Parse(std::span<const uint8_t> buffer);

    // 支援 std::vector<uint8_t>
    static ParseResult Parse(const std::vector<uint8_t>& buffer) {
        return Parse(std::span<const uint8_t>(buffer.data(), buffer.size()));
    }

    // 支援 std::string
    static ParseResult Parse(const std::string& buffer) {
        return Parse(std::span<const uint8_t>(
            reinterpret_cast<const uint8_t*>(buffer.data()),
            buffer.size()
        ));
    }
};
