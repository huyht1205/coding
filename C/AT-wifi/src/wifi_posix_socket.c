#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "hal_wifi.h"
#include "macros.h"

static int privSock = 0;
static int privPeer[MAX_CLIENT_NUM];

HAL_WifiStatus
HAL_WIFI_Server_init(const HAL_wifi_addr_t *const addr)
{
    RETURN_WEMSG_IF(privSock != 0, WIFI_BUSY, "A server instance was created");

    int ret = 0;

    memset(privPeer, 0, sizeof(privPeer));

    privSock = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    RETURN_WEMSG_IF((-1) == privSock, WIFI_ERROR, "socket: %s\n", strerror(errno));

    ret = bind(privSock, (struct sockaddr *) addr, sizeof(HAL_wifi_addr_t));
    RETURN_WEMSG_IF((-1) == ret, WIFI_ERROR, "bind: %s\n", strerror(errno));

    return WIFI_OK;
}

HAL_WifiStatus
HAL_WIFI_Server_accept(const uint32_t clientNum)
{
    int ret = 0;
    HAL_wifi_addr_t addr;
    uint32_t sockSz = sizeof(HAL_wifi_addr_t);

    ret = listen(privSock, clientNum);
    RETURN_WEMSG_IF((-1) == ret, WIFI_ERROR, "listen: %s\n", strerror(errno));
    
    for (size_t i = 0; i < clientNum; ++i) {
        privPeer[i] = accept(privSock, (struct sockaddr *) &addr, &sockSz);
        RETURN_WEMSG_IF((-1) == privPeer[i], WIFI_ERROR, "accept: %s\n", strerror(errno));
    }

    return WIFI_OK;
}

HAL_WifiStatus
HAL_WIFI_Client_init(const HAL_wifi_addr_t *const serverAddr)
{
    int ret = 0;

    privSock = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    RETURN_WEMSG_IF((-1) == privSock, WIFI_ERROR, "socket: %s\n", strerror(errno));

    ret = connect(privSock, (struct sockaddr *) serverAddr, sizeof(HAL_wifi_addr_t));
    RETURN_WEMSG_IF((-1) == ret, WIFI_ERROR, "connect: %s\n", strerror(errno));

    return WIFI_OK;
}

HAL_WifiStatus
HAL_WIFI_Client_connect(const HAL_wifi_addr_t *const serverAddr)
{


    return WIFI_OK;
}

HAL_WifiStatus
HAL_WIFI_Send(uint8_t *const buf,
              const uint32_t bufSz)
{
    int ret = 0;

    ret = send(privSock, buf, bufSz, 0);
    RETURN_WEMSG_IF((-1) == ret, WIFI_ERROR, "sendto: %s\n", strerror(errno));

    return WIFI_OK;
}

HAL_WifiStatus
HAL_WIFI_Receive(uint8_t *const  buf,
                 const uint32_t  bufSz,
                 uint32_t *const recvSz)
{
    int ret = 0;

    while (1) {
        memset(buf, '\0', bufSz);
        for (size_t i = 0; i < ARR_LEN(privPeer); ++i) {
            if (0 != privPeer[i]) {
                ret = recv(privPeer[i], buf, bufSz, 0);
                if (ret > 0) {
                    LOG("Server receive from connection %lu: %s (%d Bytes)\n", i, buf, ret);
                }
            }
        }
    }

    return WIFI_OK;
}