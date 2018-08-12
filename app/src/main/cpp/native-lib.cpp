#include <jni.h>
#include <string>
#include <android/asset_manager_jni.h>
#include <cassert>

#include "android_fopen.h"
#include "tsparser.h"

#if defined(LOG_TAG)
#undef LOG_TAG
#endif
#define LOG_TAG "native-lib"

#include "log.h"

static FILE *file;
static uint8_t buffer[kTSPacketSize];

extern "C" JNIEXPORT void JNICALL
Java_me_huntto_androidtsparser_MainActivity_openTS(JNIEnv *env,
                                                   jobject object,
                                                   jobject assetMgr,
                                                   jstring filename) {
    android_fopen_set_asset_manager(AAssetManager_fromJava(env, assetMgr));
    // convert Java string to UTF-8
    const char *utf8 = env->GetStringUTFChars(filename, NULL);
    assert(NULL != utf8);

    // open the file to play
    file = android_fopen(utf8, "rb");
    if (file == NULL) {
        return;
    }

    LOGD("start parse");
    TSParser ts_parser;
    size_t bytes_read;
    long count = 0;
    while ((bytes_read = fread(buffer, 1, kTSPacketSize, file)) > 0) {
        ts_parser.FeedPacket(buffer, bytes_read);
        count++;
    }
    LOGD("parsed %d ts packets", count);
}
