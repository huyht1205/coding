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
    WIFI_BUSY,
} HAL_WifiStatus;

#define MAX_CLIENT_NUM      9

/**
 * @brief Init a singleton server
 * 
 * Execute all commands related to initializing a server instance.
 * 
 * @param addr IN IP address or hostname, port number
 * @return HAL_WifiStatus 
 */
HAL_WifiStatus HAL_WIFI_Server_init(const HAL_wifi_addr_t *const addr);

/**
 * @brief Accept incoming connection
 * 
 * Accept incoming connection and put new connection ID into an empty slot in a ring buffer.
 * This can be run forever to wait for new connections.
 * Ring buffer of connection ID is static allocation inside WiFi library.
 * 
 * @param clientNum IN The maximum number of client can be accepted.
 * @return HAL_WifiStatus 
 */
HAL_WifiStatus HAL_WIFI_Server_accept(const uint32_t clientNum);

/**
 * @brief Create a client
 * 
 * Execute all commands related to initializing a server instance.
 * Multi client can be created. 
 * Since there most likely no way for user to perform disconnect except turn off the mic,
 * there is no need for a disconnect API. As a result, connect() is mixed into init().
 * 
 * @param serverAddr IN IP Address/hostname and port of server
 * @return HAL_WifiStatus 
 */
HAL_WifiStatus HAL_WIFI_Client_init(const HAL_wifi_addr_t *const serverAddr);

/**
 * @brief Logically transparent blocking send
 * 
 * Although it's possible to use APIs from HAL_UART but to be more flexible,
 * it's better to have send() API in HAL_WIFI.
 * If buffer is bigger than 1 block that the WiFi module can handle,
 * this API will internally break it into blocks.
 * API user should not concern about block size limitation of the WiFi module.
 * 
 * @param buf   IN Sending buffer
 * @param bufSz IN Sending buffer size
 * @return HAL_WifiStatus 
 */
HAL_WifiStatus HAL_WIFI_Send(uint8_t *const buf, const uint32_t bufSz);

/**
 * @brief Logically transparent receive
 * 
 * Although it's possible to use APIs from HAL_UART but to be more flexible,
 * it's better to have recv() API in HAL_WIFI.
 * TODO:
 *      1. Have an API to connect to UART interrupt.
 *      2. How to let the user know the ID of receiving connection for request-reply protocol.
 *  
 * @param buf    IN  Receive buffer
 * @param bufSz  IN  Receive buffer size
 * @param recvSz OUT Number of received bytes
 * @return HAL_WifiStatus 
 */
HAL_WifiStatus HAL_WIFI_Receive(uint8_t *const buf, const uint32_t bufSz, uint32_t *const recvSz);

#ifdef __cplusplus
    }
#endif
#endif // HAL_WIFI_H