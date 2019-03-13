#ifndef HAL_WIFI_H
#define HAL_WIFI_H

#ifdef __cplusplus
    extern "C" {
#endif

#include <stdint.h>

#ifdef __arm__
#include "wifi_at_cmd.h"
#else
#include "wifi_posix_socket.h"
#endif // __arm

typedef enum {
    WIFI_OK = 0,
    WIFI_ERROR,
} HAL_WifiStatus;

#define MAX_CLIENT_NUM      9

HAL_WifiStatus HAL_WIFI_Server_init(const HAL_wifi_addr_t *const addr);
HAL_WifiStatus HAL_WIFI_Server_accept(HAL_wifi_addr_t *const clientAddr, const uint32_t clientNum);

HAL_WifiStatus HAL_WIFI_Client_init(void);
HAL_WifiStatus HAL_WIFI_Client_connect(const HAL_wifi_addr_t *const serverAddr);

HAL_WifiStatus HAL_WIFI_Send(uint8_t *const buf, const uint32_t bufSz);
HAL_WifiStatus HAL_WIFI_Receive(uint8_t *const buf, const uint32_t bufSz, uint32_t *const recvSz);

#ifdef __cplusplus
    }
#endif
#endif // HAL_WIFI_H