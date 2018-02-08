/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
package org.zeromq.mlm;
import org.zeromq.czmq.*;

public class MlmClient implements AutoCloseable{

    public long self;

    /*
    Create a new mlm_client, return the reference if successful,
    or NULL if construction failed due to lack of available memory.
    */
    native static long __new ();
    public MlmClient () {
        /*  TODO: if __new fails, self is null...            */
        self = __new ();
    }
    public MlmClient (long pointer) {
        self = pointer;
    }
    /*
    Destroy the mlm_client and free all memory used by the object.
    */
    native static void __destroy (long self);
    @Override
    public void close () {
        __destroy (self);
        self = 0;
    }

    /*
    Return actor, when caller wants to work with multiple actors and/or
    input sockets asynchronously.
    */
    native static long __actor (long self);
    public Zactor actor () {
        return new Zactor (__actor (self));
    }
    /*
    Return message pipe for asynchronous message I/O. In the high-volume case,
    we send methods and get replies to the actor, in a synchronous manner, and
    we send/recv high volume message data to a second pipe, the msgpipe. In
    the low-volume case we can do everything over the actor pipe, if traffic
    is never ambiguous.
    */
    native static long __msgpipe (long self);
    public Zsock msgpipe () {
        return new Zsock (__msgpipe (self));
    }
    /*
    Return true if client is currently connected, else false. Note that the
    client will automatically re-connect if the server dies and restarts after
    a successful first connection.
    */
    native static boolean __connected (long self);
    public boolean connected () {
        return __connected (self);
    }
    /*
    Set PLAIN authentication username and password. If you do not call this, the
    client will use NULL authentication. TODO: add "set curve auth".
    Returns >= 0 if successful, -1 if interrupted.
    */
    native static int __setPlainAuth (long self, String username, String password);
    public int setPlainAuth (String username, String password) {
        return __setPlainAuth (self, username, password);
    }
    /*
    Connect to server endpoint, with specified timeout in msecs (zero means wait
    forever). Constructor succeeds if connection is successful. The caller may
    specify its address.
    Returns >= 0 if successful, -1 if interrupted.
    */
    native static int __connect (long self, String endpoint, int timeout, String address);
    public int connect (String endpoint, int timeout, String address) {
        return __connect (self, endpoint, timeout, address);
    }
    /*
    Prepare to publish to a specified stream. After this, all messages are sent to
    this stream exclusively.
    Returns >= 0 if successful, -1 if interrupted.
    */
    native static int __setProducer (long self, String stream);
    public int setProducer (String stream) {
        return __setProducer (self, stream);
    }
    /*
    Consume messages with matching subjects. The pattern is a regular expression
    using the CZMQ zrex syntax. The most useful elements are: ^ and $ to match the
    start and end, . to match any character, \s and \S to match whitespace and
    non-whitespace, \d and \D to match a digit and non-digit, \a and \A to match
    alphabetic and non-alphabetic, \w and \W to match alphanumeric and
    non-alphanumeric, + for one or more repetitions, * for zero or more repetitions,
    and ( ) to create groups. Returns 0 if subscription was successful, else -1.
    Returns >= 0 if successful, -1 if interrupted.
    */
    native static int __setConsumer (long self, String stream, String pattern);
    public int setConsumer (String stream, String pattern) {
        return __setConsumer (self, stream, pattern);
    }
    /*
    Remove subscriptions to a stream.
    Returns >= 0 if successful, -1 if interrupted.
    */
    native static int __removeConsumer (long self, String stream, String pattern);
    public int removeConsumer (String stream, String pattern) {
        return __removeConsumer (self, stream, pattern);
    }
    /*
    Offer a particular named service, where the pattern matches request subjects
    using the CZMQ zrex syntax.
    Returns >= 0 if successful, -1 if interrupted.
    */
    native static int __setWorker (long self, String address, String pattern);
    public int setWorker (String address, String pattern) {
        return __setWorker (self, address, pattern);
    }
    /*
    Remove offers for named service.
    Returns >= 0 if successful, -1 if interrupted.
    */
    native static int __removeWorker (long self, String address, String pattern);
    public int removeWorker (String address, String pattern) {
        return __removeWorker (self, address, pattern);
    }
    /*
    Send STREAM SEND message to server, takes ownership of message
    and destroys message when done sending it.
    */
    native static int __send (long self, String address, String subject, long content);
    public int send (String address, String subject, Zmsg content) {
        return __send (self, address, subject, content.self);
    }
    /*
    Send MAILBOX SEND message to server, takes ownership of message
    and destroys message when done sending it.
    */
    native static int __sendto (long self, String address, String subject, String tracker, int timeout, long content);
    public int sendto (String address, String subject, String tracker, int timeout, Zmsg content) {
        return __sendto (self, address, subject, tracker, timeout, content.self);
    }
    /*
    Send SERVICE SEND message to server, takes ownership of message
    and destroys message when done sending it.
    */
    native static int __sendfor (long self, String address, String subject, String tracker, int timeout, long content);
    public int sendfor (String address, String subject, String tracker, int timeout, Zmsg content) {
        return __sendfor (self, address, subject, tracker, timeout, content.self);
    }
    /*
    Receive message from server; caller destroys message when done
    */
    native static long __recv (long self);
    public Zmsg recv () {
        return new Zmsg (__recv (self));
    }
    /*
    Return last received command. Can be one of these values:
        "STREAM DELIVER"
        "MAILBOX DELIVER"
        "SERVICE DELIVER"
    */
    native static String __command (long self);
    public String command () {
        return __command (self);
    }
    /*
    Return last received status
    */
    native static int __status (long self);
    public int status () {
        return __status (self);
    }
    /*
    Return last received reason
    */
    native static String __reason (long self);
    public String reason () {
        return __reason (self);
    }
    /*
    Return last received address
    */
    native static String __address (long self);
    public String address () {
        return __address (self);
    }
    /*
    Return last received sender
    */
    native static String __sender (long self);
    public String sender () {
        return __sender (self);
    }
    /*
    Return last received subject
    */
    native static String __subject (long self);
    public String subject () {
        return __subject (self);
    }
    /*
    Return last received content
    */
    native static long __content (long self);
    public Zmsg content () {
        return new Zmsg (__content (self));
    }
    /*
    Return last received tracker
    */
    native static String __tracker (long self);
    public String tracker () {
        return __tracker (self);
    }
    /*
    Send multipart string message to stream, end list with NULL
    Returns 0 if OK, -1 if failed due to lack of memory or other error.
    */
    native static int __sendx (long self, String address, String subject, String content);
    public int sendx (String address, String subject, String content []) {
        return __sendx (self, address, subject, content [0]);
    }
    /*
    Send multipart string to mailbox, end list with NULL
    Returns 0 if OK, -1 if failed due to lack of memory or other error.
    */
    native static int __sendtox (long self, String address, String subject, String content);
    public int sendtox (String address, String subject, String content []) {
        return __sendtox (self, address, subject, content [0]);
    }
    /*
    Send multipart string to service, end list with NULL
    Returns 0 if OK, -1 if failed due to lack of memory or other error.
    */
    native static int __sendforx (long self, String address, String subject, String content);
    public int sendforx (String address, String subject, String content []) {
        return __sendforx (self, address, subject, content [0]);
    }
    /*
    Enable verbose tracing (animation) of state machine activity.
    */
    native static void __setVerbose (long self, boolean verbose);
    public void setVerbose (boolean verbose) {
        __setVerbose (self, verbose);
    }
    /*
    Self test of this class.
    */
    native static void __test (boolean verbose);
    public static void test (boolean verbose) {
        __test (verbose);
    }
}
