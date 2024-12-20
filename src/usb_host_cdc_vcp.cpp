/*
 * SPDX-FileCopyrightText: 2022 Espressif Systems (Shanghai) CO LTD
 * SPDX-FileCopyrightText: 2021 WCH
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "usb/vcp_cdc.hpp"
#include "usb/usb_types_ch9.h"
#include "esp_log.h"
#include "esp_check.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sdkconfig.h"

#ifndef CONFIG_COMPILER_CXX_EXCEPTIONS
#error This component requires C++ exceptions
#endif

static const char *TAG = "CDC";

namespace esp_usb {
CDC::CDC(uint16_t pid, const cdc_acm_host_device_config_t *dev_config, uint8_t interface_idx)
    : intf(interface_idx)
{   
    const esp_err_t err = this->open(vid, pid, this->intf, dev_config);
    if (err != ESP_OK) {
        throw (err);
    }
};
}
