/*
 * SPDX-FileCopyrightText: 2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <array>
#include <memory>
#include <vector>
#include "usb/cdc_acm_host.h"

#define CDC_VID            (0x1546)
#define CDC_PID            (0x01A9)

namespace esp_usb {
class CDC : public CdcAcmDevice {
public:
    /**
     * @brief Constructor for this CDC driver
     *
     * @note USB Host library and CDC-ACM driver must be already installed
     *
     * @param[in] pid            PID eg. CDCPID
     * @param[in] dev_config     CDC device configuration
     * @param[in] interface_idx  Interface number
     * @return CdcAcmDevice      Pointer to created and opened CDC device
     */
    CDC(uint16_t pid, const cdc_acm_host_device_config_t *dev_config, uint8_t interface_idx = 0);

    /**
     * @brief Set Line Coding method
     *
     * @note Overrides default implementation in CDC-ACM driver
     * @param[in] line_coding Line Coding structure
     * @return esp_err_t
     */
    using CdcAcmDevice::line_coding_set;
  

    // List of supported VIDs and PIDs
    static constexpr uint16_t vid = CDC_VID;
    static constexpr std::array<uint16_t, 1> pids = {CDC_PID};

private:
    const uint8_t intf;

    // Make open functions from CdcAcmDevice class private
    using CdcAcmDevice::open;
    using CdcAcmDevice::open_vendor_specific;
    using CdcAcmDevice::send_break; // Break is not supported by CDC
    using CdcAcmDevice::line_coding_get; // Manufacturer doesn't provide enough information to implement this
   
};
} // namespace esp_usb
