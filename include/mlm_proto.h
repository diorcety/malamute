/*  =========================================================================
    mlm_proto - Set the content field, transferring ownership from caller

    Copyright (c) the Contributors as noted in the AUTHORS file.       
    This file is part of the Malamute Project.                         
                                                                       
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.           
    =========================================================================
*/

#ifndef MLM_PROTO_H_INCLUDED
#define MLM_PROTO_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

//  @warning THE FOLLOWING @INTERFACE BLOCK IS AUTO-GENERATED BY ZPROJECT
//  @warning Please edit the model at "api/mlm_proto.api" to make changes.
//  @interface
//  This API is a draft, and may change without notice.
#ifdef MLM_BUILD_DRAFT_API
#define MLM_PROTO_SUCCESS 200               // 
#define MLM_PROTO_FAILED 300                // 
#define MLM_PROTO_COMMAND_INVALID 500       // 
#define MLM_PROTO_NOT_IMPLEMENTED 501       // 
#define MLM_PROTO_INTERNAL_ERROR 502        // 
#define MLM_PROTO_CONNECTION_OPEN 1         // 
#define MLM_PROTO_CONNECTION_PING 2         // 
#define MLM_PROTO_CONNECTION_PONG 3         // 
#define MLM_PROTO_CONNECTION_CLOSE 4        // 
#define MLM_PROTO_STREAM_WRITE 5            // 
#define MLM_PROTO_STREAM_READ 6             // 
#define MLM_PROTO_STREAM_SEND 7             // 
#define MLM_PROTO_STREAM_DELIVER 8          // 
#define MLM_PROTO_MAILBOX_SEND 9            // 
#define MLM_PROTO_MAILBOX_DELIVER 10        // 
#define MLM_PROTO_SERVICE_SEND 11           // 
#define MLM_PROTO_SERVICE_OFFER 12          // 
#define MLM_PROTO_SERVICE_DELIVER 13        // 
#define MLM_PROTO_OK 14                     // 
#define MLM_PROTO_ERROR 15                  // 
#define MLM_PROTO_CREDIT 16                 // 
#define MLM_PROTO_CONFIRM 17                // 

//  *** Draft method, for development use, may change without warning ***
//  Create a new empty mlm_proto
MLM_EXPORT mlm_proto_t *
    mlm_proto_new (void);

//  *** Draft method, for development use, may change without warning ***
//  Destroy a mlm_proto instance
MLM_EXPORT void
    mlm_proto_destroy (mlm_proto_t **self_p);

//  *** Draft method, for development use, may change without warning ***
//  Receive a mlm_proto from the socket. Returns 0 if OK, -1 if
//  there was an error. Blocks if there is no message waiting. 
MLM_EXPORT int
    mlm_proto_recv (mlm_proto_t *self, zsock_t *input);

//  *** Draft method, for development use, may change without warning ***
//  Send the mlm_proto to the output socket, does not destroy it
MLM_EXPORT int
    mlm_proto_send (mlm_proto_t *self, zsock_t *output);

//  *** Draft method, for development use, may change without warning ***
//  Print contents of message to stdout
MLM_EXPORT void
    mlm_proto_print (mlm_proto_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Get the message routing id, as a frame
MLM_EXPORT zframe_t *
    mlm_proto_routing_id (mlm_proto_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Set the message routing id from a frame
MLM_EXPORT void
    mlm_proto_set_routing_id (mlm_proto_t *self, zframe_t *routing_id);

//  *** Draft method, for development use, may change without warning ***
//  Get the mlm_proto message id
MLM_EXPORT int
    mlm_proto_id (mlm_proto_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Set the mlm_proto message id
MLM_EXPORT void
    mlm_proto_set_id (mlm_proto_t *self, int id);

//  *** Draft method, for development use, may change without warning ***
//  Get the mlm_proto message id as printable text
MLM_EXPORT const char *
    mlm_proto_command (mlm_proto_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Get the address field
MLM_EXPORT const char *
    mlm_proto_address (mlm_proto_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Set the address field
MLM_EXPORT void
    mlm_proto_set_address (mlm_proto_t *self, const char *address);

//  *** Draft method, for development use, may change without warning ***
//  Get the stream field
MLM_EXPORT const char *
    mlm_proto_stream (mlm_proto_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Set the stream field
MLM_EXPORT void
    mlm_proto_set_stream (mlm_proto_t *self, const char *stream);

//  *** Draft method, for development use, may change without warning ***
//  Get the pattern field
MLM_EXPORT const char *
    mlm_proto_pattern (mlm_proto_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Set the pattern field
MLM_EXPORT void
    mlm_proto_set_pattern (mlm_proto_t *self, const char *pattern);

//  *** Draft method, for development use, may change without warning ***
//  Get the subject field
MLM_EXPORT const char *
    mlm_proto_subject (mlm_proto_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Set the subject field
MLM_EXPORT void
    mlm_proto_set_subject (mlm_proto_t *self, const char *subject);

//  *** Draft method, for development use, may change without warning ***
//  Get a copy of the content field
MLM_EXPORT zmsg_t *
    mlm_proto_content (mlm_proto_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Get the content field and transfer ownership to caller
MLM_EXPORT zmsg_t *
    mlm_proto_get_content (mlm_proto_t *self);

//  *** Draft method, for development use, may change without warning ***
//  
MLM_EXPORT void
    mlm_proto_set_content (mlm_proto_t *self, zmsg_t **content_p);

//  *** Draft method, for development use, may change without warning ***
//  Get the sender field
MLM_EXPORT const char *
    mlm_proto_sender (mlm_proto_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Set the sender field
MLM_EXPORT void
    mlm_proto_set_sender (mlm_proto_t *self, const char *sender);

//  *** Draft method, for development use, may change without warning ***
//  Get the tracker field
MLM_EXPORT const char *
    mlm_proto_tracker (mlm_proto_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Set the tracker field
MLM_EXPORT void
    mlm_proto_set_tracker (mlm_proto_t *self, const char *tracker);

//  *** Draft method, for development use, may change without warning ***
//  Get the timeout field
MLM_EXPORT uint32_t
    mlm_proto_timeout (mlm_proto_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Set the timeout field
MLM_EXPORT void
    mlm_proto_set_timeout (mlm_proto_t *self, uint32_t timeout);

//  *** Draft method, for development use, may change without warning ***
//  Get the status_code field
MLM_EXPORT uint16_t
    mlm_proto_status_code (mlm_proto_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Set the status_code field
MLM_EXPORT void
    mlm_proto_set_status_code (mlm_proto_t *self, uint16_t status_code);

//  *** Draft method, for development use, may change without warning ***
//  Get the status_reason field
MLM_EXPORT const char *
    mlm_proto_status_reason (mlm_proto_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Set the status_reason field
MLM_EXPORT void
    mlm_proto_set_status_reason (mlm_proto_t *self, const char *status_reason);

//  *** Draft method, for development use, may change without warning ***
//  Get the amount field
MLM_EXPORT uint16_t
    mlm_proto_amount (mlm_proto_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Set the amount field
MLM_EXPORT void
    mlm_proto_set_amount (mlm_proto_t *self, uint16_t amount);

//  *** Draft method, for development use, may change without warning ***
//  Self test of this class.
MLM_EXPORT void
    mlm_proto_test (bool verbose);

#endif // MLM_BUILD_DRAFT_API
//  @end

#ifdef __cplusplus
}
#endif

#endif
