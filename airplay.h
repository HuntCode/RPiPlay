#ifndef HH_AIRPLAY_H
#define HH_AIRPLAY_H

#ifdef  __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C
#endif //  __cplusplus

#ifdef _WIN32
#ifdef LIBAIRPLAY_EXPORTS
	#define HHAIRPLAY_API EXTERN_C __declspec(dllexport)
#else
	#define HHAIRPLAY_API EXTERN_C __declspec(dllimport)
#endif
#else
	#define HHAIRPLAY_API EXTERN_C
#endif

#include <functional>

HHAIRPLAY_API void HHAirPlaySetVideoFrameHandler(std::function<void(unsigned char* data, int data_len)> callback);

HHAIRPLAY_API void HHAirPlaySetAudioFrameHandler(std::function<void(unsigned char* data, int data_len)> callback);

/** Start AirPlay Service
 *
 * @param  deviceName The device name(service name) shown on the list of Apple Screen Mirroring
 *
 * @return
 * - 0: Success.
 * - < 0: Failure.
 */
HHAIRPLAY_API int HHAirPlayStart(const char* deviceName);

/** Stop AirPlay Service
 *
 */
HHAIRPLAY_API void HHAirPlayStop();

#endif // HH_AIRPLAY_H