//
// Created by xiangtao on 2018/8/12.
//

#include <cassert>

#include "tsparser.h"

#if defined(LOG_TAG)
#undef LOG_TAG
#endif
#define LOG_TAG "TSParser"

#include "log.h"

static long count = 0;

void TSParser::FeedPacket(uint8_t *packet, size_t size) {
    assert(size % kTSPacketSize == 0);
    assert(packet[0] = 0x47);
}