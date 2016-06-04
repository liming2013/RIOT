/*
 * Copyright (C) 2016 Freie Universität Berlin
 *                    Kaspar Schleiser <kaspar@schleiser.de>
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @defgroup    net_sock_addr   Address abstractions
 * @ingroup     net_sock
 * @brief       Address abstractions for usage with @ref net_sock
 * @{
 *
 * @file
 * @brief   Address abstraction definitions for @ref net_sock
 *
 * @author  Martine Lenders <m.lenders@fu-berlin.de>
 * @author  Kaspar Schleiser <kaspar@schleiser.de>
 */
#ifndef SOCK_ADDR_H_
#define SOCK_ADDR_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Special @ref net_netif "netif" ID for "any interface"
 * @todo    Define in @ref net_netif
 */
#define SOCK_ADDR_ANY_NETIF (0)

/**
 * @brief   Address to bind to any IPv4 address
 */
#define SOCK_ADDR_IPV4_ADDR_ANY (0U)

/**
 * @brief   Address to bind to any IPv6 address
 */
#define SOCK_ADDR_IPV6_ADDR_ANY { { 0 } }

typedef uint32_t sock_addr_ipv4_t;

/**
 * @brief   Type to represent an IPv6 address
 */
typedef struct {
    uint8_t u8[16];         /**< bytes of the address */
} sock_addr_ipv6_t;

/**
 * @brief   Type to abstract both IPv4 and IPv6 addresses
 */
typedef union {
#ifdef SOCK_HAS_IPV6
    sock_addr_ipv6_t ipv6;  /**< IPv6 address mode */
#endif
    sock_addr_ipv4_t ipv4;  /**< IPv4 address mode */
} sock_addr_ip_t;

/**
 * @brief   Address to bind to any IPv4 address
 */
static const sock_addr_ipv4_t sock_addr_ipv4_any = SOCK_ADDR_IPV4_ADDR_ANY;

/**
 * @brief   Address to bind to any IPv6 address
 */
static const sock_addr_ipv6_t sock_addr_ipv6_any = SOCK_ADDR_IPV6_ADDR_ANY;

#ifdef __cplusplus
}
#endif

#endif /* SOCK_ADDR_H_ */
/** @} */
