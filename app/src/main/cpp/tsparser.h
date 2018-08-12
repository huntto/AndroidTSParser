//
// Created by xiangtao on 2018/8/12.
//

#ifndef TS_PARSER_H_
#define TS_PARSER_H_

#include <stdint.h>

const int kTSPacketSize = 188;

class TSParser {
public:
    TSParser() {}

    TSParser(const TSParser &) = delete;

    TSParser &operator=(const TSParser &) = delete;

    void FeedPacket(uint8_t *packet, size_t size);
};

#endif //TS_PARSER_H_
