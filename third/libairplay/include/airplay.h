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

HHAIRPLAY_API int HHAirPlayStart(const char* deviceName);
HHAIRPLAY_API void HHAirPlayStop();

#endif // HH_AIRPLAY_H