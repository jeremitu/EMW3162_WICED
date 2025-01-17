/*
 * Copyright 2014, Broadcom Corporation
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Broadcom Corporation;
 * the contents of this file may not be disclosed to third parties, copied
 * or duplicated in any form, in whole or in part, without the prior
 * written permission of Broadcom Corporation.
 */

/** @file
 *  Defines common constants used with WICED
 *
 */

#ifndef INCLUDED_WWD_CONSTANTS_H_
#define INCLUDED_WWD_CONSTANTS_H_

#include <stdint.h>
#include "wwd_wlioctl.h"

#ifdef __cplusplus
extern "C"
{
#endif


#ifndef MIN
extern int MIN (/*@sef@*/ int x, /*@sef@*/ int y); /* LINT : This tells lint that  the parameter must be side-effect free. i.e. evaluation does not change any values (since it is being evaulated more than once */
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#endif /* ifndef MIN */

#ifndef MAX
extern int MAX (/*@sef@*/ int x, /*@sef@*/ int y); /* LINT : This tells lint that  the parameter must be side-effect free. i.e. evaluation does not change any values (since it is being evaulated more than once */
#define MAX(x,y)  ((x) > (y) ? (x) : (y))
#endif /* ifndef MAX */

#ifndef ROUND_UP
extern int ROUND_UP (/*@sef@*/ int x, /*@sef@*/ int y); /* LINT : This tells lint that  the parameter must be side-effect free. i.e. evaluation does not change any values (since it is being evaulated more than once */
#define ROUND_UP(x,y)    ((x) % (y) ? (x) + (y)-((x)%(y)) : (x))
#endif /* ifndef ROUND_UP */

#ifndef DIV_ROUND_UP
extern int DIV_ROUND_UP (int m, /*@sef@*/ int n); /* LINT : This tells lint that  the parameter must be side-effect free. i.e. evaluation does not change any values (since it is being evaulated more than once */
#define DIV_ROUND_UP(m, n)    (((m) + (n) - 1) / (n))
#endif /* ifndef DIV_ROUND_UP */

#ifndef PLATFORM
#define PLATFORM "Unknown"
#endif /* ifndef PLATFORM */

#ifndef FreeRTOS_VERSION
#define FreeRTOS_VERSION "Unknown"
#endif /* ifndef FreeRTOS_VERSION */

#ifndef LwIP_VERSION
#define LwIP_VERSION "Unknown"
#endif /* ifndef LwIP_VERSION */

#ifndef WICED_VERSION
#define WICED_VERSION "Unknown"
#endif /* ifndef WICED_VERSION */


/** @cond !ADDTHIS*/
#define SHARED_ENABLED  0x00008000
#define WPA_SECURITY    0x00200000
#define WPA2_SECURITY   0x00400000
#define WPS_ENABLED     0x10000000
/** @endcond */

/** Enumeration of WICED interfaces. \n
 * @note The config interface is a virtual interface that shares the softAP interface
 */
typedef enum
{
    WWD_STA_INTERFACE, /**< STA or Client Interface  */
    WWD_AP_INTERFACE,  /**< softAP Interface         */
} wwd_interface_t;

/**
 * Enumeration of Wi-Fi security modes
 */
typedef enum
{
    WICED_SECURITY_OPEN           = 0,                                                /**< Open security                           */
    WICED_SECURITY_WEP_PSK        = WEP_ENABLED,                                      /**< WEP Security with open authentication   */
    WICED_SECURITY_WEP_SHARED     = ( WEP_ENABLED | SHARED_ENABLED ),                 /**< WEP Security with shared authentication */
    WICED_SECURITY_WPA_TKIP_PSK   = ( WPA_SECURITY  | TKIP_ENABLED ),                 /**< WPA Security with TKIP                  */
    WICED_SECURITY_WPA_AES_PSK    = ( WPA_SECURITY  | AES_ENABLED ),                  /**< WPA Security with AES                   */
    WICED_SECURITY_WPA2_AES_PSK   = ( WPA2_SECURITY | AES_ENABLED ),                  /**< WPA2 Security with AES                  */
    WICED_SECURITY_WPA2_TKIP_PSK  = ( WPA2_SECURITY | TKIP_ENABLED ),                 /**< WPA2 Security with TKIP                 */
    WICED_SECURITY_WPA2_MIXED_PSK = ( WPA2_SECURITY | AES_ENABLED | TKIP_ENABLED ),   /**< WPA2 Security with AES & TKIP           */

    WICED_SECURITY_WPS_OPEN       = ( WPS_ENABLED ),                                      /**< WPS with open security                  */
    WICED_SECURITY_WPS_SECURE     = ( WPS_ENABLED | AES_ENABLED),                      /**< WPS with AES security                   */

    WICED_SECURITY_UNKNOWN        = -1,                                               /**< May be returned by scan function if security is unknown. Do not pass this to the join function! */

    WICED_SECURITY_FORCE_32_BIT   = 0x7fffffff                                        /**< Exists only to force wiced_security_t type to 32 bits */
} wiced_security_t;


/**
 * Enumeration of methods of scanning
 */
typedef enum
{
    WICED_SCAN_TYPE_ACTIVE              = 0x00,  /**< Actively scan a network by sending 802.11 probe(s)         */
    WICED_SCAN_TYPE_PASSIVE             = 0x01,  /**< Passively scan a network by listening for beacons from APs */
    WICED_SCAN_TYPE_PROHIBITED_CHANNELS = 0x04   /**< Passively scan on channels not enabled by the country code */
} wiced_scan_type_t;

/**
 * Enumeration of network types
 */
typedef enum
{
    WICED_BSS_TYPE_INFRASTRUCTURE = 0, /**< Denotes infrastructure network                  */
    WICED_BSS_TYPE_ADHOC          = 1, /**< Denotes an 802.11 ad-hoc IBSS network           */
    WICED_BSS_TYPE_ANY            = 2, /**< Denotes either infrastructure or ad-hoc network */

    WICED_BSS_TYPE_UNKNOWN        = -1 /**< May be returned by scan function if BSS type is unknown. Do not pass this to the Join function */
} wiced_bss_type_t;

/**
 * Enumeration of 802.11 radio bands
 */
typedef enum
{
    WICED_802_11_BAND_5GHZ   = 0, /**< Denotes 5GHz radio band   */
    WICED_802_11_BAND_2_4GHZ = 1  /**< Denotes 2.4GHz radio band */
} wiced_802_11_band_t;

/**
 * Enumeration of antenna selection options
 */
typedef enum
{
    WICED_ANTENNA_1    = 0,  /**< Denotes antenna 1 */
    WICED_ANTENNA_2    = 1,  /**< Denotes antenna 2 */
    WICED_ANTENNA_AUTO = 3   /**< Denotes auto diversity, the best antenna is automatically selected */
} wiced_antenna_t;

/**
 * Enumeration of applicable packet mask bits for custom Information Elements (IEs)
 */
typedef enum
{
    VENDOR_IE_BEACON         = 0x1,  /**< Denotes beacon packet                  */
    VENDOR_IE_PROBE_RESPONSE = 0x2,  /**< Denotes probe response packet          */
    VENDOR_IE_ASSOC_RESPONSE = 0x4,  /**< Denotes association response packet    */
    VENDOR_IE_AUTH_RESPONSE  = 0x8,  /**< Denotes authentication response packet */
    VENDOR_IE_PROBE_REQUEST  = 0x10, /**< Denotes probe request packet           */
    VENDOR_IE_ASSOC_REQUEST  = 0x20, /**< Denotes association request packet     */
    VENDOR_IE_CUSTOM         = 0x100 /**< Denotes a custom IE identifier         */
} wiced_ie_packet_flag_t;

/**
 * Enumeration of custom IE management actions
 */
typedef enum
{
    WICED_ADD_CUSTOM_IE,     /**< Add a custom IE    */
    WICED_REMOVE_CUSTOM_IE   /**< Remove a custom IE */
} wiced_custom_ie_action_t;

/**
 * Enumeration of 802.11 QoS, i.e. WMM, traffic classes
 */
typedef enum
{
    WMM_AC_BE =         0,      /**< Best Effort */
    WMM_AC_BK =         1,      /**< Background  */
    WMM_AC_VI =         2,      /**< Video       */
    WMM_AC_VO =         3,      /**< Voice       */
} wiced_qos_access_category_t;

/**
 * Enumeration of IP header Type of Service (TOS) values, which map to 802.11 QoS traffic classes
 */
typedef enum
{
    TOS_VO7 = 7, /**< 0xE0, 111 0  0000 (7)  AC_VO tos/dscp values */
    TOS_VO  = 6, /**< 0xD0, 110 0  0000 (6)  AC_VO                 */
    TOS_VI  = 5, /**< 0xA0, 101 0  0000 (5)  AC_VI                 */
    TOS_VI4 = 4, /**< 0x80, 100 0  0000 (4)  AC_VI                 */
    TOS_BE  = 0, /**< 0x00, 000 0  0000 (0)  AC_BE                 */
    TOS_EE  = 3, /**< 0x60, 011 0  0000 (3)  AC_BE                 */
    TOS_BK  = 1, /**< 0x20, 001 0  0000 (1)  AC_BK                 */
    TOS_LE  = 2, /**< 0x40, 010 0  0000 (2)  AC_BK                 */
} wiced_ip_header_tos_t;

/**
 * Enumeration of listen interval time unit types
 */
typedef enum
{
    WICED_LISTEN_INTERVAL_TIME_UNIT_BEACON, /**< Time units specified in beacon periods */
    WICED_LISTEN_INTERVAL_TIME_UNIT_DTIM    /**< Time units specified in DTIM periods   */
} wiced_listen_interval_time_unit_t;

/**
 * Enumeration of packet filter modes
 */
typedef enum
{
    WICED_PACKET_FILTER_MODE_FORWARD = 1, /**< Packet filter engine forwards matching packets, discards non-matching packets */
    WICED_PACKET_FILTER_MODE_DISCARD = 0, /**< Packet filter engine discards matching packets, forwards non-matching packets */
} wiced_packet_filter_mode_t;

/**
 * Enumeration of packet filter rules
 */
typedef enum
{
    WICED_PACKET_FILTER_RULE_POSITIVE_MATCHING  = 0, /**< Specifies that a filter should match a given pattern     */
    WICED_PACKET_FILTER_RULE_NEGATIVE_MATCHING  = 1  /**< Specifies that a filter should NOT match a given pattern */
} wiced_packet_filter_rule_t;

typedef enum
{
    WICED_SCAN_INCOMPLETE,
    WICED_SCAN_COMPLETED_SUCCESSFULLY,
    WICED_SCAN_ABORTED,
} wiced_scan_status_t;

#ifndef RESULT_ENUM
#define RESULT_ENUM( prefix, name, value )  prefix ## name = (value)
#endif /* ifndef RESULT_ENUM */


/* These Enum result values are for WWD errors
 * Values: 1000 - 1999
 */

#define WWD_RESULT_LIST( prefix )  \
    RESULT_ENUM( prefix, SUCCESS,                         0 ),   /**< Success */                           \
    RESULT_ENUM( prefix, PENDING,                         1 ),   /**< Pending */                           \
    RESULT_ENUM( prefix, TIMEOUT,                         2 ),   /**< Timeout */                           \
    RESULT_ENUM( prefix, PARTIAL_RESULTS,              1003 ),   /**< Partial results */                   \
    RESULT_ENUM( prefix, INVALID_KEY,                  1004 ),   /**< Invalid key */                       \
    RESULT_ENUM( prefix, DOES_NOT_EXIST,               1005 ),   /**< Does not exist */                    \
    RESULT_ENUM( prefix, NOT_AUTHENTICATED,            1006 ),   /**< Not authenticated */                 \
    RESULT_ENUM( prefix, NOT_KEYED,                    1007 ),   /**< Not keyed */                         \
    RESULT_ENUM( prefix, IOCTL_FAIL,                   1008 ),   /**< IOCTL fail */                        \
    RESULT_ENUM( prefix, BUFFER_UNAVAILABLE_TEMPORARY, 1009 ),   /**< Buffer unavailable temporarily */    \
    RESULT_ENUM( prefix, BUFFER_UNAVAILABLE_PERMANENT, 1010 ),   /**< Buffer unavailable permanently */    \
    RESULT_ENUM( prefix, WPS_PBC_OVERLAP,              1011 ),   /**< WPS PBC overlap */                   \
    RESULT_ENUM( prefix, CONNECTION_LOST,              1012 ),   /**< Connection lost */                   \
    RESULT_ENUM( prefix, OUT_OF_EVENT_HANDLER_SPACE,   1013 ),   /**< Cannot add extra event handler */    \
    RESULT_ENUM( prefix, SEMAPHORE_ERROR,              1014 ),   /**< Error manipulating a semaphore */    \
    RESULT_ENUM( prefix, FLOW_CONTROLLED,              1015 ),   /**< Packet retrieval cancelled due to flow control */ \
    RESULT_ENUM( prefix, NO_CREDITS,                   1016 ),   /**< Packet retrieval cancelled due to lack of bus credits */ \
    RESULT_ENUM( prefix, NO_PACKET_TO_SEND,            1017 ),   /**< Packet retrieval cancelled due to no pending packets */ \
    RESULT_ENUM( prefix, CORE_CLOCK_NOT_ENABLED,       1018 ),   /**< Core disabled due to no clock */    \
    RESULT_ENUM( prefix, CORE_IN_RESET,                1019 ),   /**< Core disabled - in reset */         \
    RESULT_ENUM( prefix, UNSUPPORTED,                  1020 ),   /**< Unsupported function */             \
    RESULT_ENUM( prefix, BUS_WRITE_REGISTER_ERROR,     1021 ),   /**< Error writing to WLAN register */   \
    RESULT_ENUM( prefix, SDIO_BUS_UP_FAIL,             1022 ),   /**< SDIO bus failed to come up */       \
    RESULT_ENUM( prefix, JOIN_IN_PROGRESS,             1023 ),   /**< Join not finished yet */   \
    RESULT_ENUM( prefix, NETWORK_NOT_FOUND,            1024 ),   /**< Specified network was not found */   \
    RESULT_ENUM( prefix, INVALID_JOIN_STATUS,          1025 ),   /**< Join status error */   \
    RESULT_ENUM( prefix, UNKNOWN_INTERFACE,            1026 ),   /**< Unknown interface specified */ \
    RESULT_ENUM( prefix, SDIO_RX_FAIL,                 1027 ),   /**< Error during SDIO receive */   \
    RESULT_ENUM( prefix, HWTAG_MISMATCH,               1028 ),   /**< Hardware tag header corrupt */   \
    RESULT_ENUM( prefix, RX_BUFFER_ALLOC_FAIL,         1029 ),   /**< Failed to allocate a buffer to receive into */   \
    RESULT_ENUM( prefix, BUS_READ_REGISTER_ERROR,      1030 ),   /**< Error reading a bus hardware register */   \
    RESULT_ENUM( prefix, THREAD_CREATE_FAILED,         1031 ),   /**< Failed to create a new thread */   \
    RESULT_ENUM( prefix, QUEUE_ERROR,                  1032 ),   /**< Error manipulating a queue */   \
    RESULT_ENUM( prefix, BUFFER_POINTER_MOVE_ERROR,    1033 ),   /**< Error moving the current pointer of a packet buffer  */   \
    RESULT_ENUM( prefix, BUFFER_SIZE_SET_ERROR,        1034 ),   /**< Error setting size of packet buffer */   \
    RESULT_ENUM( prefix, THREAD_STACK_NULL,            1035 ),   /**< Null stack pointer passed when non null was reqired */   \
    RESULT_ENUM( prefix, THREAD_DELETE_FAIL,           1036 ),   /**< Error deleting a thread */   \
    RESULT_ENUM( prefix, SLEEP_ERROR,                  1037 ),   /**< Error sleeping a thread */ \
    RESULT_ENUM( prefix, BUFFER_ALLOC_FAIL,            1038 ),   /**< Failed to allocate a packet buffer */ \
    RESULT_ENUM( prefix, NO_PACKET_TO_RECEIVE,         1039 ),   /**< No Packets waiting to be received */ \
    RESULT_ENUM( prefix, INTERFACE_NOT_UP,             1040 ),   /**< Requested interface is not active */ \
    RESULT_ENUM( prefix, DELAY_TOO_LONG,               1041 ),   /**< Requested delay is too long */ \
    RESULT_ENUM( prefix, INVALID_DUTY_CYCLE,           1042 ),   /**< Duty cycle is outside limit 0 to 100 */ \
    RESULT_ENUM( prefix, PMK_WRONG_LENGTH,             1043 ),   /**< Returned pmk was the wrong length */ \
    RESULT_ENUM( prefix, UNKNOWN_SECURITY_TYPE,        1044 ),   /**< AP security type was unknown */ \
    RESULT_ENUM( prefix, WEP_NOT_ALLOWED,              1045 ),   /**< AP not allowed to use WEP - it is not secure - use Open instead */ \
    RESULT_ENUM( prefix, WPA_KEYLEN_BAD,               1046 ),   /**< WPA / WPA2 key length must be between 8 & 64 bytes */ \
    RESULT_ENUM( prefix, FILTER_NOT_FOUND,             1047 ),   /**< Specified filter id not found */ \
    RESULT_ENUM( prefix, SPI_ID_READ_FAIL,             1048 ),   /**< Failed to read 0xfeedbead SPI id from chip */ \
    RESULT_ENUM( prefix, SPI_SIZE_MISMATCH,            1049 ),   /**< Mismatch in sizes between SPI header and SDPCM header */ \
    RESULT_ENUM( prefix, ADDRESS_ALREADY_REGISTERED,   1050 ),   /**< Attempt to register a multicast address twice */ \
    RESULT_ENUM( prefix, SDIO_RETRIES_EXCEEDED,        1051 ),   /**< SDIO transfer failed too many times. */ \
    RESULT_ENUM( prefix, NULL_PTR_ARG,                 1052 ),   /**< Null Pointer argument passed to function. */ \
    RESULT_ENUM( prefix, THREAD_FINISH_FAIL,           1053 ),   /**< Error deleting a thread */ \
    RESULT_ENUM( prefix, WAIT_ABORTED,                 1054 ),   /**< Semaphore/mutex wait has been aborted */ \
    RESULT_ENUM( prefix, SET_BLOCK_ACK_WINDOW_FAIL,    1055 ),   /**< Failed to set block ack window */ \
    RESULT_ENUM( prefix, INVALID_INTERFACE,            1056 ),   /**< Invalid interface provided */


/* These Enum result values are returned directly from the WLAN during an ioctl or iovar call.
 * Values: 1100 - 1200
 */
#define WLAN_ENUM_OFFSET  (2000)

#define WLAN_RESULT_LIST( prefix ) \
    RESULT_ENUM( prefix, ERROR,                       2001 ),  /**< Generic Error */                     \
    RESULT_ENUM( prefix, BADARG,                      2002 ),  /**< Bad Argument */                      \
    RESULT_ENUM( prefix, BADOPTION,                   2003 ),  /**< Bad option */                        \
    RESULT_ENUM( prefix, NOTUP,                       2004 ),  /**< Not up */                            \
    RESULT_ENUM( prefix, NOTDOWN,                     2005 ),  /**< Not down */                          \
    RESULT_ENUM( prefix, NOTAP,                       2006 ),  /**< Not AP */                            \
    RESULT_ENUM( prefix, NOTSTA,                      2007 ),  /**< Not STA  */                          \
    RESULT_ENUM( prefix, BADKEYIDX,                   2008 ),  /**< BAD Key Index */                     \
    RESULT_ENUM( prefix, RADIOOFF,                    2009 ),  /**< Radio Off */                         \
    RESULT_ENUM( prefix, NOTBANDLOCKED,               2010 ),  /**< Not  band locked */                  \
    RESULT_ENUM( prefix, NOCLK,                       2011 ),  /**< No Clock */                          \
    RESULT_ENUM( prefix, BADRATESET,                  2012 ),  /**< BAD Rate valueset */                 \
    RESULT_ENUM( prefix, BADBAND,                     2013 ),  /**< BAD Band */                          \
    RESULT_ENUM( prefix, BUFTOOSHORT,                 2014 ),  /**< Buffer too short */                  \
    RESULT_ENUM( prefix, BUFTOOLONG,                  2015 ),  /**< Buffer too long */                   \
    RESULT_ENUM( prefix, BUSY,                        2016 ),  /**< Busy */                              \
    RESULT_ENUM( prefix, NOTASSOCIATED,               2017 ),  /**< Not Associated */                    \
    RESULT_ENUM( prefix, BADSSIDLEN,                  2018 ),  /**< Bad SSID len */                      \
    RESULT_ENUM( prefix, OUTOFRANGECHAN,              2019 ),  /**< Out of Range Channel */              \
    RESULT_ENUM( prefix, BADCHAN,                     2020 ),  /**< Bad Channel */                       \
    RESULT_ENUM( prefix, BADADDR,                     2021 ),  /**< Bad Address */                       \
    RESULT_ENUM( prefix, NORESOURCE,                  2022 ),  /**< Not Enough Resources */              \
    RESULT_ENUM( prefix, UNSUPPORTED,                 2023 ),  /**< Unsupported */                       \
    RESULT_ENUM( prefix, BADLEN,                      2024 ),  /**< Bad length */                        \
    RESULT_ENUM( prefix, NOTREADY,                    2025 ),  /**< Not Ready */                         \
    RESULT_ENUM( prefix, EPERM,                       2026 ),  /**< Not Permitted */                     \
    RESULT_ENUM( prefix, NOMEM,                       2027 ),  /**< No Memory */                         \
    RESULT_ENUM( prefix, ASSOCIATED,                  2028 ),  /**< Associated */                        \
    RESULT_ENUM( prefix, RANGE,                       2029 ),  /**< Not In Range */                      \
    RESULT_ENUM( prefix, NOTFOUND,                    2030 ),  /**< Not Found */                         \
    RESULT_ENUM( prefix, WME_NOT_ENABLED,             2031 ),  /**< WME Not Enabled */                   \
    RESULT_ENUM( prefix, TSPEC_NOTFOUND,              2032 ),  /**< TSPEC Not Found */                   \
    RESULT_ENUM( prefix, ACM_NOTSUPPORTED,            2033 ),  /**< ACM Not Supported */                 \
    RESULT_ENUM( prefix, NOT_WME_ASSOCIATION,         2034 ),  /**< Not WME Association */               \
    RESULT_ENUM( prefix, SDIO_ERROR,                  2035 ),  /**< SDIO Bus Error */                    \
    RESULT_ENUM( prefix, WLAN_DOWN,                   2036 ),  /**< WLAN Not Accessible */               \
    RESULT_ENUM( prefix, BAD_VERSION,                 2037 ),  /**< Incorrect version */                 \
    RESULT_ENUM( prefix, TXFAIL,                      2038 ),  /**< TX failure */                        \
    RESULT_ENUM( prefix, RXFAIL,                      2039 ),  /**< RX failure */                        \
    RESULT_ENUM( prefix, NODEVICE,                    2040 ),  /**< Device not present */                \
    RESULT_ENUM( prefix, UNFINISHED,                  2041 ),  /**< To be finished */                    \
    RESULT_ENUM( prefix, NONRESIDENT,                 2042 ),  /**< access to nonresident overlay */     \
    RESULT_ENUM( prefix, DISABLED,                    2043 ),  /**< Disabled in this build */

/**
 * Common result type for WICED functions
 */
typedef enum
{
    WWD_RESULT_LIST( WWD_ )
    WLAN_RESULT_LIST( WWD_WLAN_ )
} wwd_result_t;

/**
 * Boolean values
 */
typedef enum
{
    WICED_FALSE = 0,
    WICED_TRUE  = 1
} wiced_bool_t;

/**
 * I/O State Values
 */
typedef enum
{
    WWD_ACTIVE_LOW = 0,
    WWD_ACTIVE_HIGH = 1
} wwd_io_state_t;

/**
 * Enumeration of Dot11 Reason Codes
 */
typedef enum
{
    WWD_DOT11_RC_RESERVED  = 0,    /**< Reserved     */
    WWD_DOT11_RC_UNSPECIFIED  = 1  /**< Unspecified  */
} wwd_dot11_reason_code_t;


/******************************************************
 * @cond      Constants
 ******************************************************/

/**
 * Transfer direction for the WICED platform bus interface
 */
typedef enum
{
    /* If updating this enum, the bus_direction_mapping variable will also need to be updated */
    BUS_READ,
    BUS_WRITE
} wwd_bus_transfer_direction_t;

/**
 * Macro for creating country codes according to endianness
 * @cond !ADDTHIS
 */

#ifdef IL_BIGENDIAN
#define MK_CNTRY( a, b, rev )  (((unsigned char)(b)) + (((unsigned char)(a))<<8) + (((unsigned char)(rev))<<24) )
#else /* ifdef IL_BIGENDIAN */
#define MK_CNTRY( a, b, rev )  (((unsigned char)(a)) + (((unsigned char)(b))<<8) + (((unsigned char)(rev))<<24) )
#endif /* ifdef IL_BIGENDIAN */

/* Suppress unused parameter warning */
#ifndef UNUSED_PARAMETER
#define UNUSED_PARAMETER(x) /*@-noeffect@*/ ( (void)(x) ) /*@+noeffect@*/
#endif

/* Suppress unused variable warning */
#ifndef UNUSED_VARIABLE
#define UNUSED_VARIABLE(x) /*@-noeffect@*/ ( (void)(x) ) /*@+noeffect@*/
#endif


/* Suppress unused variable warning occurring due to an assert which is disabled in release mode */
#ifndef REFERENCE_DEBUG_ONLY_VARIABLE
#define REFERENCE_DEBUG_ONLY_VARIABLE(x) /*@-noeffect@*/ ( (void)(x) ) /*@+noeffect@*/
#endif

/* Allow functions to be deprecated */
#ifdef __GNUC__
#define DEPRECATE( name )  name __attribute__ ((deprecated))
#else
#define DEPRECATE( name )  deprecated_ ## name
#endif

/*
 * @endcond
 */

/**
 * Enumerated list of country codes
 */
typedef enum
{
    WICED_COUNTRY_AFGHANISTAN                                     = MK_CNTRY( 'A', 'F', 0 ),             /* AF Afghanistan */
    WICED_COUNTRY_ALBANIA                                         = MK_CNTRY( 'A', 'L', 0 ),             /* AL Albania */
    WICED_COUNTRY_ALGERIA                                         = MK_CNTRY( 'D', 'Z', 0 ),             /* DZ Algeria */
    WICED_COUNTRY_AMERICAN_SAMOA                                  = MK_CNTRY( 'A', 'S', 0 ),             /* AS American_Samoa */
    WICED_COUNTRY_ANGOLA                                          = MK_CNTRY( 'A', 'O', 0 ),             /* AO Angola */
    WICED_COUNTRY_ANGUILLA                                        = MK_CNTRY( 'A', 'I', 0 ),             /* AI Anguilla */
    WICED_COUNTRY_ANTIGUA_AND_BARBUDA                             = MK_CNTRY( 'A', 'G', 0 ),             /* AG Antigua_and_Barbuda */
    WICED_COUNTRY_ARGENTINA                                       = MK_CNTRY( 'A', 'R', 0 ),             /* AR Argentina */
    WICED_COUNTRY_ARMENIA                                         = MK_CNTRY( 'A', 'M', 0 ),             /* AM Armenia */
    WICED_COUNTRY_ARUBA                                           = MK_CNTRY( 'A', 'W', 0 ),             /* AW Aruba */
    WICED_COUNTRY_AUSTRALIA                                       = MK_CNTRY( 'A', 'U', 0 ),             /* AU Australia */
    WICED_COUNTRY_AUSTRIA                                         = MK_CNTRY( 'A', 'T', 0 ),             /* AT Austria */
    WICED_COUNTRY_AZERBAIJAN                                      = MK_CNTRY( 'A', 'Z', 0 ),             /* AZ Azerbaijan */
    WICED_COUNTRY_BAHAMAS                                         = MK_CNTRY( 'B', 'S', 0 ),             /* BS Bahamas */
    WICED_COUNTRY_BAHRAIN                                         = MK_CNTRY( 'B', 'H', 0 ),             /* BH Bahrain */
    WICED_COUNTRY_BAKER_ISLAND                                    = MK_CNTRY( '0', 'B', 0 ),             /* 0B Baker_Island */
    WICED_COUNTRY_BANGLADESH                                      = MK_CNTRY( 'B', 'D', 0 ),             /* BD Bangladesh */
    WICED_COUNTRY_BARBADOS                                        = MK_CNTRY( 'B', 'B', 0 ),             /* BB Barbados */
    WICED_COUNTRY_BELARUS                                         = MK_CNTRY( 'B', 'Y', 0 ),             /* BY Belarus */
    WICED_COUNTRY_BELGIUM                                         = MK_CNTRY( 'B', 'E', 0 ),             /* BE Belgium */
    WICED_COUNTRY_BELIZE                                          = MK_CNTRY( 'B', 'Z', 0 ),             /* BZ Belize */
    WICED_COUNTRY_BENIN                                           = MK_CNTRY( 'B', 'J', 0 ),             /* BJ Benin */
    WICED_COUNTRY_BERMUDA                                         = MK_CNTRY( 'B', 'M', 0 ),             /* BM Bermuda */
    WICED_COUNTRY_BHUTAN                                          = MK_CNTRY( 'B', 'T', 0 ),             /* BT Bhutan */
    WICED_COUNTRY_BOLIVIA                                         = MK_CNTRY( 'B', 'O', 0 ),             /* BO Bolivia */
    WICED_COUNTRY_BOSNIA_AND_HERZEGOVINA                          = MK_CNTRY( 'B', 'A', 0 ),             /* BA Bosnia_and_Herzegovina */
    WICED_COUNTRY_BOTSWANA                                        = MK_CNTRY( 'B', 'W', 0 ),             /* BW Botswana */
    WICED_COUNTRY_BRAZIL                                          = MK_CNTRY( 'B', 'R', 0 ),             /* BR Brazil */
    WICED_COUNTRY_BRITISH_INDIAN_OCEAN_TERRITORY                  = MK_CNTRY( 'I', 'O', 0 ),             /* IO British_Indian_Ocean_Territory */
    WICED_COUNTRY_BRUNEI_DARUSSALAM                               = MK_CNTRY( 'B', 'N', 0 ),             /* BN Brunei_Darussalam */
    WICED_COUNTRY_BULGARIA                                        = MK_CNTRY( 'B', 'G', 0 ),             /* BG Bulgaria */
    WICED_COUNTRY_BURKINA_FASO                                    = MK_CNTRY( 'B', 'F', 0 ),             /* BF Burkina_Faso */
    WICED_COUNTRY_BURUNDI                                         = MK_CNTRY( 'B', 'I', 0 ),             /* BI Burundi */
    WICED_COUNTRY_CAMBODIA                                        = MK_CNTRY( 'K', 'H', 0 ),             /* KH Cambodia */
    WICED_COUNTRY_CAMEROON                                        = MK_CNTRY( 'C', 'M', 0 ),             /* CM Cameroon */
    WICED_COUNTRY_CANADA                                          = MK_CNTRY( 'C', 'A', 0 ),             /* CA Canada */
    WICED_COUNTRY_CAPE_VERDE                                      = MK_CNTRY( 'C', 'V', 0 ),             /* CV Cape_Verde */
    WICED_COUNTRY_CAYMAN_ISLANDS                                  = MK_CNTRY( 'K', 'Y', 0 ),             /* KY Cayman_Islands */
    WICED_COUNTRY_CENTRAL_AFRICAN_REPUBLIC                        = MK_CNTRY( 'C', 'F', 0 ),             /* CF Central_African_Republic */
    WICED_COUNTRY_CHAD                                            = MK_CNTRY( 'T', 'D', 0 ),             /* TD Chad */
    WICED_COUNTRY_CHILE                                           = MK_CNTRY( 'C', 'L', 0 ),             /* CL Chile */
    WICED_COUNTRY_CHINA                                           = MK_CNTRY( 'C', 'N', 0 ),             /* CN China */
    WICED_COUNTRY_CHRISTMAS_ISLAND                                = MK_CNTRY( 'C', 'X', 0 ),             /* CX Christmas_Island */
    WICED_COUNTRY_COLOMBIA                                        = MK_CNTRY( 'C', 'O', 0 ),             /* CO Colombia */
    WICED_COUNTRY_COMOROS                                         = MK_CNTRY( 'K', 'M', 0 ),             /* KM Comoros */
    WICED_COUNTRY_CONGO                                           = MK_CNTRY( 'C', 'G', 0 ),             /* CG Congo */
    WICED_COUNTRY_CONGO_THE_DEMOCRATIC_REPUBLIC_OF_THE            = MK_CNTRY( 'C', 'D', 0 ),             /* CD Congo,_The_Democratic_Republic_Of_The */
    WICED_COUNTRY_COSTA_RICA                                      = MK_CNTRY( 'C', 'R', 0 ),             /* CR Costa_Rica */
    WICED_COUNTRY_COTE_DIVOIRE                                    = MK_CNTRY( 'C', 'I', 0 ),             /* CI Cote_D'ivoire */
    WICED_COUNTRY_CROATIA                                         = MK_CNTRY( 'H', 'R', 0 ),             /* HR Croatia */
    WICED_COUNTRY_CUBA                                            = MK_CNTRY( 'C', 'U', 0 ),             /* CU Cuba */
    WICED_COUNTRY_CYPRUS                                          = MK_CNTRY( 'C', 'Y', 0 ),             /* CY Cyprus */
    WICED_COUNTRY_CZECH_REPUBLIC                                  = MK_CNTRY( 'C', 'Z', 0 ),             /* CZ Czech_Republic */
    WICED_COUNTRY_DENMARK                                         = MK_CNTRY( 'D', 'K', 0 ),             /* DK Denmark */
    WICED_COUNTRY_DJIBOUTI                                        = MK_CNTRY( 'D', 'J', 0 ),             /* DJ Djibouti */
    WICED_COUNTRY_DOMINICA                                        = MK_CNTRY( 'D', 'M', 0 ),             /* DM Dominica */
    WICED_COUNTRY_DOMINICAN_REPUBLIC                              = MK_CNTRY( 'D', 'O', 0 ),             /* DO Dominican_Republic */
    WICED_COUNTRY_DOWN_UNDER                                      = MK_CNTRY( 'A', 'U', 0 ),             /* AU G'Day mate! */
    WICED_COUNTRY_ECUADOR                                         = MK_CNTRY( 'E', 'C', 0 ),             /* EC Ecuador */
    WICED_COUNTRY_EGYPT                                           = MK_CNTRY( 'E', 'G', 0 ),             /* EG Egypt */
    WICED_COUNTRY_EL_SALVADOR                                     = MK_CNTRY( 'S', 'V', 0 ),             /* SV El_Salvador */
    WICED_COUNTRY_EQUATORIAL_GUINEA                               = MK_CNTRY( 'G', 'Q', 0 ),             /* GQ Equatorial_Guinea */
    WICED_COUNTRY_ERITREA                                         = MK_CNTRY( 'E', 'R', 0 ),             /* ER Eritrea */
    WICED_COUNTRY_ESTONIA                                         = MK_CNTRY( 'E', 'E', 0 ),             /* EE Estonia */
    WICED_COUNTRY_ETHIOPIA                                        = MK_CNTRY( 'E', 'T', 0 ),             /* ET Ethiopia */
    WICED_COUNTRY_FALKLAND_ISLANDS_MALVINAS                       = MK_CNTRY( 'F', 'K', 0 ),             /* FK Falkland_Islands_(Malvinas) */
    WICED_COUNTRY_FAROE_ISLANDS                                   = MK_CNTRY( 'F', 'O', 0 ),             /* FO Faroe_Islands */
    WICED_COUNTRY_FIJI                                            = MK_CNTRY( 'F', 'J', 0 ),             /* FJ Fiji */
    WICED_COUNTRY_FINLAND                                         = MK_CNTRY( 'F', 'I', 0 ),             /* FI Finland */
    WICED_COUNTRY_FRANCE                                          = MK_CNTRY( 'F', 'R', 0 ),             /* FR France */
    WICED_COUNTRY_FRENCH_GUINA                                    = MK_CNTRY( 'G', 'F', 0 ),             /* GF French_Guina */
    WICED_COUNTRY_FRENCH_POLYNESIA                                = MK_CNTRY( 'P', 'F', 0 ),             /* PF French_Polynesia */
    WICED_COUNTRY_FRENCH_SOUTHERN_TERRITORIES                     = MK_CNTRY( 'T', 'F', 0 ),             /* TF French_Southern_Territories */
    WICED_COUNTRY_GABON                                           = MK_CNTRY( 'G', 'A', 0 ),             /* GA Gabon */
    WICED_COUNTRY_GAMBIA                                          = MK_CNTRY( 'G', 'M', 0 ),             /* GM Gambia */
    WICED_COUNTRY_GEORGIA                                         = MK_CNTRY( 'G', 'E', 0 ),             /* GE Georgia */
    WICED_COUNTRY_GERMANY                                         = MK_CNTRY( 'D', 'E', 0 ),             /* DE Germany */
    WICED_COUNTRY_GHANA                                           = MK_CNTRY( 'G', 'H', 0 ),             /* GH Ghana */
    WICED_COUNTRY_GIBRALTAR                                       = MK_CNTRY( 'G', 'I', 0 ),             /* GI Gibraltar */
    WICED_COUNTRY_GREECE                                          = MK_CNTRY( 'G', 'R', 0 ),             /* GR Greece */
    WICED_COUNTRY_GRENADA                                         = MK_CNTRY( 'G', 'D', 0 ),             /* GD Grenada */
    WICED_COUNTRY_GUADELOUPE                                      = MK_CNTRY( 'G', 'P', 0 ),             /* GP Guadeloupe */
    WICED_COUNTRY_GUAM                                            = MK_CNTRY( 'G', 'U', 0 ),             /* GU Guam */
    WICED_COUNTRY_GUATEMALA                                       = MK_CNTRY( 'G', 'T', 0 ),             /* GT Guatemala */
    WICED_COUNTRY_GUERNSEY                                        = MK_CNTRY( 'G', 'G', 0 ),             /* GG Guernsey */
    WICED_COUNTRY_GUINEA                                          = MK_CNTRY( 'G', 'N', 0 ),             /* GN Guinea */
    WICED_COUNTRY_GUINEA_BISSAU                                   = MK_CNTRY( 'G', 'W', 0 ),             /* GW Guinea-bissau */
    WICED_COUNTRY_GUYANA                                          = MK_CNTRY( 'G', 'Y', 0 ),             /* GY Guyana */
    WICED_COUNTRY_HAITI                                           = MK_CNTRY( 'H', 'T', 0 ),             /* HT Haiti */
    WICED_COUNTRY_HOLY_SEE_VATICAN_CITY_STATE                     = MK_CNTRY( 'V', 'A', 0 ),             /* VA Holy_See_(Vatican_City_State) */
    WICED_COUNTRY_HONDURAS                                        = MK_CNTRY( 'H', 'N', 0 ),             /* HN Honduras */
    WICED_COUNTRY_HONG_KONG                                       = MK_CNTRY( 'H', 'K', 0 ),             /* HK Hong_Kong */
    WICED_COUNTRY_HUNGARY                                         = MK_CNTRY( 'H', 'U', 0 ),             /* HU Hungary */
    WICED_COUNTRY_ICELAND                                         = MK_CNTRY( 'I', 'S', 0 ),             /* IS Iceland */
    WICED_COUNTRY_INDIA                                           = MK_CNTRY( 'I', 'N', 0 ),             /* IN India */
    WICED_COUNTRY_INDONESIA                                       = MK_CNTRY( 'I', 'D', 0 ),             /* ID Indonesia */
    WICED_COUNTRY_IRAN_ISLAMIC_REPUBLIC_OF                        = MK_CNTRY( 'I', 'R', 0 ),             /* IR Iran,_Islamic_Republic_Of */
    WICED_COUNTRY_IRAQ                                            = MK_CNTRY( 'I', 'Q', 0 ),             /* IQ Iraq */
    WICED_COUNTRY_IRELAND                                         = MK_CNTRY( 'I', 'E', 0 ),             /* IE Ireland */
    WICED_COUNTRY_ISRAEL                                          = MK_CNTRY( 'I', 'L', 0 ),             /* IL Israel */
    WICED_COUNTRY_ITALY                                           = MK_CNTRY( 'I', 'T', 0 ),             /* IT Italy */
    WICED_COUNTRY_JAMAICA                                         = MK_CNTRY( 'J', 'M', 0 ),             /* JM Jamaica */
    WICED_COUNTRY_JAPAN                                           = MK_CNTRY( 'J', 'P', 2 ),             /* JP Japan */
    WICED_COUNTRY_JERSEY                                          = MK_CNTRY( 'J', 'E', 0 ),             /* JE Jersey */
    WICED_COUNTRY_JORDAN                                          = MK_CNTRY( 'J', 'O', 0 ),             /* JO Jordan */
    WICED_COUNTRY_KAZAKHSTAN                                      = MK_CNTRY( 'K', 'Z', 0 ),             /* KZ Kazakhstan */
    WICED_COUNTRY_KENYA                                           = MK_CNTRY( 'K', 'E', 0 ),             /* KE Kenya */
    WICED_COUNTRY_KIRIBATI                                        = MK_CNTRY( 'K', 'I', 0 ),             /* KI Kiribati */
    WICED_COUNTRY_KOREA_REPUBLIC_OF                               = MK_CNTRY( 'K', 'R', 0 ),             /* KR Korea,_Republic_Of */
    WICED_COUNTRY_KOSOVO                                          = MK_CNTRY( '0', 'A', 0 ),             /* 0A Kosovo */
    WICED_COUNTRY_KUWAIT                                          = MK_CNTRY( 'K', 'W', 0 ),             /* KW Kuwait */
    WICED_COUNTRY_KYRGYZSTAN                                      = MK_CNTRY( 'K', 'G', 0 ),             /* KG Kyrgyzstan */
    WICED_COUNTRY_LAO_PEOPLES_DEMOCRATIC_REPUBIC                  = MK_CNTRY( 'L', 'A', 0 ),             /* LA Lao_People's_Democratic_Repubic */
    WICED_COUNTRY_LATVIA                                          = MK_CNTRY( 'L', 'V', 0 ),             /* LV Latvia */
    WICED_COUNTRY_LEBANON                                         = MK_CNTRY( 'L', 'B', 0 ),             /* LB Lebanon */
    WICED_COUNTRY_LESOTHO                                         = MK_CNTRY( 'L', 'S', 0 ),             /* LS Lesotho */
    WICED_COUNTRY_LIBERIA                                         = MK_CNTRY( 'L', 'R', 0 ),             /* LR Liberia */
    WICED_COUNTRY_LIBYAN_ARAB_JAMAHIRIYA                          = MK_CNTRY( 'L', 'Y', 0 ),             /* LY Libyan_Arab_Jamahiriya */
    WICED_COUNTRY_LIECHTENSTEIN                                   = MK_CNTRY( 'L', 'I', 0 ),             /* LI Liechtenstein */
    WICED_COUNTRY_LITHUANIA                                       = MK_CNTRY( 'L', 'T', 0 ),             /* LT Lithuania */
    WICED_COUNTRY_LUXEMBOURG                                      = MK_CNTRY( 'L', 'U', 0 ),             /* LU Luxembourg */
    WICED_COUNTRY_MACAO                                           = MK_CNTRY( 'M', 'O', 0 ),             /* MO Macao */
    WICED_COUNTRY_MACEDONIA_FORMER_YUGOSLAV_REPUBLIC_OF           = MK_CNTRY( 'M', 'K', 0 ),             /* MK Macedonia,_Former_Yugoslav_Republic_Of */
    WICED_COUNTRY_MADAGASCAR                                      = MK_CNTRY( 'M', 'G', 0 ),             /* MG Madagascar */
    WICED_COUNTRY_MALAWI                                          = MK_CNTRY( 'M', 'W', 0 ),             /* MW Malawi */
    WICED_COUNTRY_MALAYSIA                                        = MK_CNTRY( 'M', 'Y', 0 ),             /* MY Malaysia */
    WICED_COUNTRY_MALDIVES                                        = MK_CNTRY( 'M', 'V', 0 ),             /* MV Maldives */
    WICED_COUNTRY_MALI                                            = MK_CNTRY( 'M', 'L', 0 ),             /* ML Mali */
    WICED_COUNTRY_MALTA                                           = MK_CNTRY( 'M', 'T', 0 ),             /* MT Malta */
    WICED_COUNTRY_MAN_ISLE_OF                                     = MK_CNTRY( 'I', 'M', 0 ),             /* IM Man,_Isle_Of */
    WICED_COUNTRY_MARTINIQUE                                      = MK_CNTRY( 'M', 'Q', 0 ),             /* MQ Martinique */
    WICED_COUNTRY_MAURITANIA                                      = MK_CNTRY( 'M', 'R', 0 ),             /* MR Mauritania */
    WICED_COUNTRY_MAURITIUS                                       = MK_CNTRY( 'M', 'U', 0 ),             /* MU Mauritius */
    WICED_COUNTRY_MAYOTTE                                         = MK_CNTRY( 'Y', 'T', 0 ),             /* YT Mayotte */
    WICED_COUNTRY_MEXICO                                          = MK_CNTRY( 'M', 'X', 0 ),             /* MX Mexico */
    WICED_COUNTRY_MICRONESIA_FEDERATED_STATES_OF                  = MK_CNTRY( 'F', 'M', 0 ),             /* FM Micronesia,_Federated_States_Of */
    WICED_COUNTRY_MOLDOVA_REPUBLIC_OF                             = MK_CNTRY( 'M', 'D', 0 ),             /* MD Moldova,_Republic_Of */
    WICED_COUNTRY_MONACO                                          = MK_CNTRY( 'M', 'C', 0 ),             /* MC Monaco */
    WICED_COUNTRY_MONGOLIA                                        = MK_CNTRY( 'M', 'N', 0 ),             /* MN Mongolia */
    WICED_COUNTRY_MONTENEGRO                                      = MK_CNTRY( 'M', 'E', 0 ),             /* ME Montenegro */
    WICED_COUNTRY_MONTSERRAT                                      = MK_CNTRY( 'M', 'S', 0 ),             /* MS Montserrat */
    WICED_COUNTRY_MOROCCO                                         = MK_CNTRY( 'M', 'A', 0 ),             /* MA Morocco */
    WICED_COUNTRY_MOZAMBIQUE                                      = MK_CNTRY( 'M', 'Z', 0 ),             /* MZ Mozambique */
    WICED_COUNTRY_MYANMAR                                         = MK_CNTRY( 'M', 'M', 0 ),             /* MM Myanmar */
    WICED_COUNTRY_NAMIBIA                                         = MK_CNTRY( 'N', 'A', 0 ),             /* NA Namibia */
    WICED_COUNTRY_NAURU                                           = MK_CNTRY( 'N', 'R', 0 ),             /* NR Nauru */
    WICED_COUNTRY_NEPAL                                           = MK_CNTRY( 'N', 'P', 0 ),             /* NP Nepal */
    WICED_COUNTRY_NETHERLANDS                                     = MK_CNTRY( 'N', 'L', 0 ),             /* NL Netherlands */
    WICED_COUNTRY_NETHERLANDS_ANTILLES                            = MK_CNTRY( 'A', 'N', 0 ),             /* AN Netherlands_Antilles */
    WICED_COUNTRY_NEW_CALEDONIA                                   = MK_CNTRY( 'N', 'C', 0 ),             /* NC New_Caledonia */
    WICED_COUNTRY_NEW_ZEALAND                                     = MK_CNTRY( 'N', 'Z', 0 ),             /* NZ New_Zealand */
    WICED_COUNTRY_NICARAGUA                                       = MK_CNTRY( 'N', 'I', 0 ),             /* NI Nicaragua */
    WICED_COUNTRY_NIGER                                           = MK_CNTRY( 'N', 'E', 0 ),             /* NE Niger */
    WICED_COUNTRY_NIGERIA                                         = MK_CNTRY( 'N', 'G', 0 ),             /* NG Nigeria */
    WICED_COUNTRY_NORFOLK_ISLAND                                  = MK_CNTRY( 'N', 'F', 0 ),             /* NF Norfolk_Island */
    WICED_COUNTRY_NORTHERN_MARIANA_ISLANDS                        = MK_CNTRY( 'M', 'P', 0 ),             /* MP Northern_Mariana_Islands */
    WICED_COUNTRY_NORWAY                                          = MK_CNTRY( 'N', 'O', 0 ),             /* NO Norway */
    WICED_COUNTRY_OMAN                                            = MK_CNTRY( 'O', 'M', 0 ),             /* OM Oman */
    WICED_COUNTRY_PAKISTAN                                        = MK_CNTRY( 'P', 'K', 0 ),             /* PK Pakistan */
    WICED_COUNTRY_PALAU                                           = MK_CNTRY( 'P', 'W', 0 ),             /* PW Palau */
    WICED_COUNTRY_PANAMA                                          = MK_CNTRY( 'P', 'A', 0 ),             /* PA Panama */
    WICED_COUNTRY_PAPUA_NEW_GUINEA                                = MK_CNTRY( 'P', 'G', 0 ),             /* PG Papua_New_Guinea */
    WICED_COUNTRY_PARAGUAY                                        = MK_CNTRY( 'P', 'Y', 0 ),             /* PY Paraguay */
    WICED_COUNTRY_PERU                                            = MK_CNTRY( 'P', 'E', 0 ),             /* PE Peru */
    WICED_COUNTRY_PHILIPPINES                                     = MK_CNTRY( 'P', 'H', 0 ),             /* PH Philippines */
    WICED_COUNTRY_POLAND                                          = MK_CNTRY( 'P', 'L', 0 ),             /* PL Poland */
    WICED_COUNTRY_PORTUGAL                                        = MK_CNTRY( 'P', 'T', 0 ),             /* PT Portugal */
    WICED_COUNTRY_PUETO_RICO                                      = MK_CNTRY( 'P', 'R', 0 ),             /* PR Pueto_Rico */
    WICED_COUNTRY_QATAR                                           = MK_CNTRY( 'Q', 'A', 0 ),             /* QA Qatar */
    WICED_COUNTRY_REUNION                                         = MK_CNTRY( 'R', 'E', 0 ),             /* RE Reunion */
    WICED_COUNTRY_ROMANIA                                         = MK_CNTRY( 'R', 'O', 0 ),             /* RO Romania */
    WICED_COUNTRY_RUSSIAN_FEDERATION                              = MK_CNTRY( 'R', 'U', 0 ),             /* RU Russian_Federation */
    WICED_COUNTRY_RWANDA                                          = MK_CNTRY( 'R', 'W', 0 ),             /* RW Rwanda */
    WICED_COUNTRY_SAINT_KITTS_AND_NEVIS                           = MK_CNTRY( 'K', 'N', 0 ),             /* KN Saint_Kitts_and_Nevis */
    WICED_COUNTRY_SAINT_LUCIA                                     = MK_CNTRY( 'L', 'C', 0 ),             /* LC Saint_Lucia */
    WICED_COUNTRY_SAINT_PIERRE_AND_MIQUELON                       = MK_CNTRY( 'P', 'M', 0 ),             /* PM Saint_Pierre_and_Miquelon */
    WICED_COUNTRY_SAINT_VINCENT_AND_THE_GRENADINES                = MK_CNTRY( 'V', 'C', 0 ),             /* VC Saint_Vincent_and_The_Grenadines */
    WICED_COUNTRY_SAMOA                                           = MK_CNTRY( 'W', 'S', 0 ),             /* WS Samoa */
    WICED_COUNTRY_SANIT_MARTIN_SINT_MARTEEN                       = MK_CNTRY( 'M', 'F', 0 ),             /* MF Sanit_Martin_/_Sint_Marteen */
    WICED_COUNTRY_SAO_TOME_AND_PRINCIPE                           = MK_CNTRY( 'S', 'T', 0 ),             /* ST Sao_Tome_and_Principe */
    WICED_COUNTRY_SAUDI_ARABIA                                    = MK_CNTRY( 'S', 'A', 0 ),             /* SA Saudi_Arabia */
    WICED_COUNTRY_SENEGAL                                         = MK_CNTRY( 'S', 'N', 0 ),             /* SN Senegal */
    WICED_COUNTRY_SERBIA                                          = MK_CNTRY( 'R', 'S', 0 ),             /* RS Serbia */
    WICED_COUNTRY_SEYCHELLES                                      = MK_CNTRY( 'S', 'C', 0 ),             /* SC Seychelles */
    WICED_COUNTRY_SIERRA_LEONE                                    = MK_CNTRY( 'S', 'L', 0 ),             /* SL Sierra_Leone */
    WICED_COUNTRY_SINGAPORE                                       = MK_CNTRY( 'S', 'G', 0 ),             /* SG Singapore */
    WICED_COUNTRY_SLOVAKIA                                        = MK_CNTRY( 'S', 'K', 0 ),             /* SK Slovakia */
    WICED_COUNTRY_SLOVENIA                                        = MK_CNTRY( 'S', 'I', 0 ),             /* SI Slovenia */
    WICED_COUNTRY_SOLOMON_ISLANDS                                 = MK_CNTRY( 'S', 'B', 0 ),             /* SB Solomon_Islands */
    WICED_COUNTRY_SOMALIA                                         = MK_CNTRY( 'S', 'O', 0 ),             /* SO Somalia */
    WICED_COUNTRY_SOUTH_AFRICA                                    = MK_CNTRY( 'Z', 'A', 0 ),             /* ZA South_Africa */
    WICED_COUNTRY_SPAIN                                           = MK_CNTRY( 'E', 'S', 0 ),             /* ES Spain */
    WICED_COUNTRY_SRI_LANKA                                       = MK_CNTRY( 'L', 'K', 0 ),             /* LK Sri_Lanka */
    WICED_COUNTRY_SURINAME                                        = MK_CNTRY( 'S', 'R', 0 ),             /* SR Suriname */
    WICED_COUNTRY_SWAZILAND                                       = MK_CNTRY( 'S', 'Z', 0 ),             /* SZ Swaziland */
    WICED_COUNTRY_SWEDEN                                          = MK_CNTRY( 'S', 'E', 0 ),             /* SE Sweden */
    WICED_COUNTRY_SWITZERLAND                                     = MK_CNTRY( 'C', 'H', 0 ),             /* CH Switzerland */
    WICED_COUNTRY_SYRIAN_ARAB_REPUBLIC                            = MK_CNTRY( 'S', 'Y', 0 ),             /* SY Syrian_Arab_Republic */
    WICED_COUNTRY_TAIWAN_PROVINCE_OF_CHINA                        = MK_CNTRY( 'T', 'W', 0 ),             /* TW Taiwan,_Province_Of_China */
    WICED_COUNTRY_TAJIKISTAN                                      = MK_CNTRY( 'T', 'J', 0 ),             /* TJ Tajikistan */
    WICED_COUNTRY_TANZANIA_UNITED_REPUBLIC_OF                     = MK_CNTRY( 'T', 'Z', 0 ),             /* TZ Tanzania,_United_Republic_Of */
    WICED_COUNTRY_THAILAND                                        = MK_CNTRY( 'T', 'H', 0 ),             /* TH Thailand */
    WICED_COUNTRY_TOGO                                            = MK_CNTRY( 'T', 'G', 0 ),             /* TG Togo */
    WICED_COUNTRY_TONGA                                           = MK_CNTRY( 'T', 'O', 0 ),             /* TO Tonga */
    WICED_COUNTRY_TRINIDAD_AND_TOBAGO                             = MK_CNTRY( 'T', 'T', 0 ),             /* TT Trinidad_and_Tobago */
    WICED_COUNTRY_TUNISIA                                         = MK_CNTRY( 'T', 'N', 0 ),             /* TN Tunisia */
    WICED_COUNTRY_TURKEY                                          = MK_CNTRY( 'T', 'R', 0 ),             /* TR Turkey */
    WICED_COUNTRY_TURKMENISTAN                                    = MK_CNTRY( 'T', 'M', 0 ),             /* TM Turkmenistan */
    WICED_COUNTRY_TURKS_AND_CAICOS_ISLANDS                        = MK_CNTRY( 'T', 'C', 0 ),             /* TC Turks_and_Caicos_Islands */
    WICED_COUNTRY_TUVALU                                          = MK_CNTRY( 'T', 'V', 0 ),             /* TV Tuvalu */
    WICED_COUNTRY_UGANDA                                          = MK_CNTRY( 'U', 'G', 0 ),             /* UG Uganda */
    WICED_COUNTRY_UKRAINE                                         = MK_CNTRY( 'U', 'A', 0 ),             /* UA Ukraine */
    WICED_COUNTRY_UNITED_ARAB_EMIRATES                            = MK_CNTRY( 'A', 'E', 0 ),             /* AE United_Arab_Emirates */
    WICED_COUNTRY_UNITED_KINGDOM                                  = MK_CNTRY( 'G', 'B', 0 ),             /* GB United_Kingdom */
    WICED_COUNTRY_UNITED_STATES                                   = MK_CNTRY( 'U', 'S', 0 ),             /* US United_States */
    WICED_COUNTRY_UNITED_STATES_REV4                              = MK_CNTRY( 'U', 'S', 4 ),             /* US United_States Revision 4 */
    WICED_COUNTRY_UNITED_STATES_NO_DFS                            = MK_CNTRY( 'Q', '2', 0 ),             /* Q2 United_States_(No_DFS) */
    WICED_COUNTRY_UNITED_STATES_MINOR_OUTLYING_ISLANDS            = MK_CNTRY( 'U', 'M', 0 ),             /* UM United_States_Minor_Outlying_Islands */
    WICED_COUNTRY_URUGUAY                                         = MK_CNTRY( 'U', 'Y', 0 ),             /* UY Uruguay */
    WICED_COUNTRY_UZBEKISTAN                                      = MK_CNTRY( 'U', 'Z', 0 ),             /* UZ Uzbekistan */
    WICED_COUNTRY_VANUATU                                         = MK_CNTRY( 'V', 'U', 0 ),             /* VU Vanuatu */
    WICED_COUNTRY_VENEZUELA                                       = MK_CNTRY( 'V', 'E', 0 ),             /* VE Venezuela */
    WICED_COUNTRY_VIET_NAM                                        = MK_CNTRY( 'V', 'N', 0 ),             /* VN Viet_Nam */
    WICED_COUNTRY_VIRGIN_ISLANDS_BRITISH                          = MK_CNTRY( 'V', 'G', 0 ),             /* VG Virgin_Islands,_British */
    WICED_COUNTRY_VIRGIN_ISLANDS_US                               = MK_CNTRY( 'V', 'I', 0 ),             /* VI Virgin_Islands,_U.S. */
    WICED_COUNTRY_WALLIS_AND_FUTUNA                               = MK_CNTRY( 'W', 'F', 0 ),             /* WF Wallis_and_Futuna */
    WICED_COUNTRY_WEST_BANK                                       = MK_CNTRY( '0', 'C', 0 ),             /* 0C West_Bank */
    WICED_COUNTRY_WESTERN_SAHARA                                  = MK_CNTRY( 'E', 'H', 0 ),             /* EH Western_Sahara */
    WICED_COUNTRY_WORLD_WIDE_XX                                   = MK_CNTRY( 'X', 'X', 0 ),             /* Worldwide Locale (passive Ch12-14) */
    WICED_COUNTRY_YEMEN                                           = MK_CNTRY( 'Y', 'E', 0 ),             /* YE Yemen */
    WICED_COUNTRY_ZAMBIA                                          = MK_CNTRY( 'Z', 'M', 0 ),             /* ZM Zambia */
    WICED_COUNTRY_ZIMBABWE                                        = MK_CNTRY( 'Z', 'W', 0 ),             /* ZW Zimbabwe */
} wiced_country_code_t;

/** @endcond */

#ifdef __cplusplus
} /* extern "C" */
#endif
#endif /* ifndef INCLUDED_WWD_CONSTANTS_H_ */
