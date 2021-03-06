#ifndef CODES_H
#define CODES_H

#define COAP_CODE(N) (((N)/100 << 5) | (N)%100)

#define DEFAULT_VERSION 0x01
#define PAYLOAD_MARKER 0xFF

// Message types:
#define TYPE_CON 0
#define TYPE_NON 1
#define TYPE_ACK 2
#define TYPE_RST 3

// Method codes:
#define CODE_EMPTY COAP_CODE(0)
#define CODE_GET COAP_CODE(1)
#define CODE_POST COAP_CODE(2)
#define CODE_PUT COAP_CODE(3)
#define CODE_DELETE COAP_CODE(4)

// Response codes:
#define CODE_CREATED COAP_CODE(201)
#define CODE_DELETED COAP_CODE(202)
#define CODE_VALID COAP_CODE(203)
#define CODE_CHANGED COAP_CODE(204)
#define CODE_CONTENT COAP_CODE(205)
#define CODE_BAD_REQUEST COAP_CODE(400)
#define CODE_UNAUTHORIZED COAP_CODE(401)
#define CODE_BAD_OPTION COAP_CODE(402)
#define CODE_FORBIDDEN COAP_CODE(403)
#define CODE_NOT_FOUND COAP_CODE(404)
#define CODE_METHOD_NOT_ALLOWED COAP_CODE(405)
#define CODE_NOT_ACCEPTABLE COAP_CODE(406)
#define CODE_PRECONDITION_FAILED COAP_CODE(412)
#define CODE_REQUEST_ENTITY_TOO_LARGE COAP_CODE(413)
#define CODE_UNSUPPORTED_CONTENT_FORMAT COAP_CODE(415)
#define CODE_shortERNAL_SERVER_ERROR COAP_CODE(500)
#define CODE_NOT_IMPLEMENTED COAP_CODE(501)
#define CODE_BAD_GATEWAY COAP_CODE(502)
#define CODE_SERVICE_UNAVAILABLE COAP_CODE(503)
#define CODE_GATEWAY_TIMEOUT COAP_CODE(504)
#define CODE_PROXYING_NOT_SUPPORTED COAP_CODE(505)


// Option codes:
#define OPTION_URI_PATH 11
#define OPTION_CONTENT_FORMAT 12
#define OPTION_ACCEPT 17
#define OPTION_BLOCK2 23

// Supported content formats:
#define CONTENT_TEXT_PLAIN 0
#define CONTENT_LINK_FORMAT 40

// Message header constants:
#define MASK_VER 0xC0
#define MASK_T 0x30
#define MASK_TKL 0x0F
#define MASK_MESSAGE_ID 0x00FF

#define OFFSET_VER 6
#define OFFSET_T 4
#define OFFSET_MESSAGE_ID 8

// Option header constants:
#define MASK_DELTA 0xF0
#define MASK_LENGTH 0x0F
#define MASK_EXTENDABLE 0x00FF

#define OFFSET_DELTA 4
#define OFFSET_EXTENDABLE 8

// Resource types constants:
#define RESOURCE_ALL1 "</remote/speaker>;value=1,</remote/lamp>;value=0"
#define RESOURCE_ALL2 ",</local/jitter>,</local/rtt>,</local/timed_out>"
#define RESOURCE_WELL_KNOWN ".well-known"
#define RESOURCE_CORE "core"
#define RESOURCE_LOCAL "local"
#define RESOURCE_REMOTE "remote"
#define RESOURCE_RTT "rtt"
#define RESOURCE_TIMED_OUT "timed_out"
#define RESOURCE_JITTER "jitter"
#define RESOURCE_SPEAKER "speaker"
#define RESOURCE_LAMP "lamp"

#endif //CODES_H
