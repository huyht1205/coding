#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include "wifi_const.h"
#include "hal_wifi.h"
#include "macros.h"

static void *listen_connection(void *arg);

int main(void) {
    uint32_t recvByte = 0;
    char buf[20];
    HAL_WifiStatus wifiErr = WIFI_OK;
    HAL_wifi_addr_t addr;
    pthread_t listenThread;

    memset(&addr, 0, sizeof(addr));
    addr.sin_family      = AF_INET;
    addr.sin_port        = htons(SERVER_PORT);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    wifiErr = HAL_WIFI_Server_init(&addr);
    RETURN_WEMSG_IF(wifiErr, wifiErr, "Server could not init WiFi\n");

    pthread_create(&listenThread, NULL, &listen_connection, NULL);

    memset(buf, '\0', sizeof(buf));
    HAL_WIFI_Receive((uint8_t *)buf, sizeof(buf), &recvByte);

    pthread_cancel(listenThread);

    return 0;
};

void *listen_connection(void *arg)
{
    int ret = 0;
    HAL_wifi_addr_t comingAddr;

    ret = HAL_WIFI_Server_accept(&comingAddr, MAX_CLIENT_NUM);
    if (WIFI_OK != ret) {
        LOG("Server: Failed to accept\n");
    }
    else {
        LOG("Server: accepted\n");
    }

    return NULL;
}