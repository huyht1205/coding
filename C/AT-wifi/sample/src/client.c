#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "wifi_const.h"
#include "hal_wifi.h"
#include "macros.h"

int main(void) {
    HAL_WifiStatus wifiErr = WIFI_OK;
    HAL_wifi_addr_t addr;
    char buf[12];
    int error = 0;

    wifiErr = HAL_WIFI_Client_init();
    RETURN_WEMSG_IF(wifiErr, wifiErr, "Could not init WiFi\n");

    memset(&addr, 0, sizeof(addr));
    addr.sin_family      = AF_INET;
    addr.sin_port        = htons(SERVER_PORT);
    addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    wifiErr = HAL_WIFI_Client_connect(&addr);
    RETURN_WEMSG_IF(wifiErr, wifiErr, "Could not connect to server\n");

    for (int i = 0; i < 10; ++i) {
        snprintf(buf, sizeof(buf), "Count %02d\n", i);

        LOG("Client: sending...\n");
        error = HAL_WIFI_Send((uint8_t *)buf, sizeof(buf));
        if (error) {
            LOG("ERROR: failed to send\n");
        }

        sleep(1);
    }

    strncpy(buf, "exit", sizeof(buf));
    error = HAL_WIFI_Send((uint8_t *)buf, sizeof(buf));
    if (error) {
        LOG("ERROR: failed to EXIT\n");
    }

    return 0;
};