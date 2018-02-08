/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/

#include "QmlMlmClient.h"


///
//  Return actor, when caller wants to work with multiple actors and/or
//  input sockets asynchronously.
zactor_t *QmlMlmClient::actor () {
    return mlm_client_actor (self);
};

///
//  Return message pipe for asynchronous message I/O. In the high-volume case,
//  we send methods and get replies to the actor, in a synchronous manner, and
//  we send/recv high volume message data to a second pipe, the msgpipe. In
//  the low-volume case we can do everything over the actor pipe, if traffic
//  is never ambiguous.
zsock_t *QmlMlmClient::msgpipe () {
    return mlm_client_msgpipe (self);
};

///
//  Return true if client is currently connected, else false. Note that the
//  client will automatically re-connect if the server dies and restarts after
//  a successful first connection.
bool QmlMlmClient::connected () {
    return mlm_client_connected (self);
};

///
//  Set PLAIN authentication username and password. If you do not call this, the
//  client will use NULL authentication. TODO: add "set curve auth".
//  Returns >= 0 if successful, -1 if interrupted.
int QmlMlmClient::setPlainAuth (const QString &username, const QString &password) {
    return mlm_client_set_plain_auth (self, username.toUtf8().data(), password.toUtf8().data());
};

///
//  Connect to server endpoint, with specified timeout in msecs (zero means wait
//  forever). Constructor succeeds if connection is successful. The caller may
//  specify its address.
//  Returns >= 0 if successful, -1 if interrupted.
int QmlMlmClient::connect (const QString &endpoint, uint32_t timeout, const QString &address) {
    return mlm_client_connect (self, endpoint.toUtf8().data(), timeout, address.toUtf8().data());
};

///
//  Prepare to publish to a specified stream. After this, all messages are sent to
//  this stream exclusively.
//  Returns >= 0 if successful, -1 if interrupted.
int QmlMlmClient::setProducer (const QString &stream) {
    return mlm_client_set_producer (self, stream.toUtf8().data());
};

///
//  Consume messages with matching subjects. The pattern is a regular expression
//  using the CZMQ zrex syntax. The most useful elements are: ^ and $ to match the
//  start and end, . to match any character, \s and \S to match whitespace and
//  non-whitespace, \d and \D to match a digit and non-digit, \a and \A to match
//  alphabetic and non-alphabetic, \w and \W to match alphanumeric and
//  non-alphanumeric, + for one or more repetitions, * for zero or more repetitions,
//  and ( ) to create groups. Returns 0 if subscription was successful, else -1.
//  Returns >= 0 if successful, -1 if interrupted.
int QmlMlmClient::setConsumer (const QString &stream, const QString &pattern) {
    return mlm_client_set_consumer (self, stream.toUtf8().data(), pattern.toUtf8().data());
};

///
//  Remove all subscriptions to a stream
//  Returns >= 0 if successful, -1 if interrupted.
int QmlMlmClient::removeConsumer (const QString &stream) {
    return mlm_client_remove_consumer (self, stream.toUtf8().data());
};

///
//  Offer a particular named service, where the pattern matches request subjects
//  using the CZMQ zrex syntax.
//  Returns >= 0 if successful, -1 if interrupted.
int QmlMlmClient::setWorker (const QString &address, const QString &pattern) {
    return mlm_client_set_worker (self, address.toUtf8().data(), pattern.toUtf8().data());
};

///
//  Send STREAM SEND message to server, takes ownership of message
//  and destroys message when done sending it.
int QmlMlmClient::send (const QString &subject, zmsg_t **content) {
    return mlm_client_send (self, subject.toUtf8().data(), content);
};

///
//  Send MAILBOX SEND message to server, takes ownership of message
//  and destroys message when done sending it.
int QmlMlmClient::sendto (const QString &address, const QString &subject, const QString &tracker, uint32_t timeout, zmsg_t **content) {
    return mlm_client_sendto (self, address.toUtf8().data(), subject.toUtf8().data(), tracker.toUtf8().data(), timeout, content);
};

///
//  Send SERVICE SEND message to server, takes ownership of message
//  and destroys message when done sending it.
int QmlMlmClient::sendfor (const QString &address, const QString &subject, const QString &tracker, uint32_t timeout, zmsg_t **content) {
    return mlm_client_sendfor (self, address.toUtf8().data(), subject.toUtf8().data(), tracker.toUtf8().data(), timeout, content);
};

///
//  Receive message from server; caller destroys message when done
zmsg_t *QmlMlmClient::recv () {
    return mlm_client_recv (self);
};

///
//  Return last received command. Can be one of these values:
//      "STREAM DELIVER"
//      "MAILBOX DELIVER"
//      "SERVICE DELIVER"
const QString QmlMlmClient::command () {
    return QString (mlm_client_command (self));
};

///
//  Return last received status
int QmlMlmClient::status () {
    return mlm_client_status (self);
};

///
//  Return last received reason
const QString QmlMlmClient::reason () {
    return QString (mlm_client_reason (self));
};

///
//  Return last received address
const QString QmlMlmClient::address () {
    return QString (mlm_client_address (self));
};

///
//  Return last received sender
const QString QmlMlmClient::sender () {
    return QString (mlm_client_sender (self));
};

///
//  Return last received subject
const QString QmlMlmClient::subject () {
    return QString (mlm_client_subject (self));
};

///
//  Return last received content
zmsg_t *QmlMlmClient::content () {
    return mlm_client_content (self);
};

///
//  Return last received tracker
const QString QmlMlmClient::tracker () {
    return QString (mlm_client_tracker (self));
};

///
//  Send multipart string message to stream, end list with NULL
//  Returns 0 if OK, -1 if failed due to lack of memory or other error.
int QmlMlmClient::sendx (const QString &subject, const QString &content) {
    return mlm_client_sendx (self, subject.toUtf8().data(), content.toUtf8().data());
};

///
//  Send multipart string to mailbox, end list with NULL
//  Returns 0 if OK, -1 if failed due to lack of memory or other error.
int QmlMlmClient::sendtox (const QString &address, const QString &subject, const QString &content) {
    return mlm_client_sendtox (self, address.toUtf8().data(), subject.toUtf8().data(), content.toUtf8().data());
};

///
//  Send multipart string to service, end list with NULL
//  Returns 0 if OK, -1 if failed due to lack of memory or other error.
int QmlMlmClient::sendforx (const QString &address, const QString &subject, const QString &content) {
    return mlm_client_sendforx (self, address.toUtf8().data(), subject.toUtf8().data(), content.toUtf8().data());
};

///
//  Receive a subject and string content from the server. The content may be
//  1 or more string frames. This method is orthogonal to the sendx methods.
//  End the string arguments with NULL. If there are not enough frames in
//  the received message, remaining strings are set to NULL. Returns number
//  of string contents received, or -1 in case of error. Free the returned
//  subject and content strings when finished with them. To get the type of
//  the command, use mlm_client_command ().
int QmlMlmClient::recvx (QString subjectP, QString stringP) {
    return mlm_client_recvx (self, subjectP.toUtf8().data(), stringP.toUtf8().data());
};

///
//  Enable verbose tracing (animation) of state machine activity.
void QmlMlmClient::setVerbose (bool verbose) {
    mlm_client_set_verbose (self, verbose);
};


QObject* QmlMlmClient::qmlAttachedProperties(QObject* object) {
    return new QmlMlmClientAttached(object);
}


///
//  Self test of this class.
void QmlMlmClientAttached::test (bool verbose) {
    mlm_client_test (verbose);
};

///
//  Create a new mlm_client, return the reference if successful,
//  or NULL if construction failed due to lack of available memory.
QmlMlmClient *QmlMlmClientAttached::construct () {
    QmlMlmClient *qmlSelf = new QmlMlmClient ();
    qmlSelf->self = mlm_client_new ();
    return qmlSelf;
};

///
//  Destroy the mlm_client and free all memory used by the object.
void QmlMlmClientAttached::destruct (QmlMlmClient *qmlSelf) {
    mlm_client_destroy (&qmlSelf->self);
};

/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
