#ifndef HH_COMMON_DEFINES_H
#define HH_COMMON_DEFINES_H

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*VideoFrameHandler)(unsigned char* data, int data_len);
typedef void (*AudioFrameHandler)(unsigned char* data, int data_len);

extern VideoFrameHandler g_videoFrameHandler;
extern AudioFrameHandler g_audioFrameHandler;

#ifdef __cplusplus
}
#endif


#endif // HH_COMMON_DEFINES_H