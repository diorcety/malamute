/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
package org.zeromq.mlm;
import org.zeromq.czmq.*;

public class MlmProto implements AutoCloseable{

    public long self;

    /*
    Create a new empty mlm_proto
    */
    native static long __new ();
    public MlmProto () {
        /*  TODO: if __new fails, self is null...            */
        self = __new ();
    }
    public MlmProto (long pointer) {
        self = pointer;
    }
    /*
    Create a new mlm_proto from zpl/zconfig_t *
    */
    native static long __newZpl (long config);
    public static MlmProto newZpl (Zconfig config) {
        return new MlmProto (__newZpl (config.self));
    }
    /*
    Destroy a mlm_proto instance
    */
    native static void __destroy (long self);
    @Override
    public void close () {
        __destroy (self);
        self = 0;
    }

    /*
    Create a deep copy of a mlm_proto instance
    */
    native static long __dup (long self);
    public MlmProto dup () {
        return new MlmProto (__dup (self));
    }
    /*
    Receive a mlm_proto from the socket. Returns 0 if OK, -1 if
    there was an error. Blocks if there is no message waiting.
    */
    native static int __recv (long self, long input);
    public int recv (Zsock input) {
        return __recv (self, input.self);
    }
    /*
    Send the mlm_proto to the output socket, does not destroy it
    */
    native static int __send (long self, long output);
    public int send (Zsock output) {
        return __send (self, output.self);
    }
    /*
    Print contents of message to stdout
    */
    native static void __print (long self);
    public void print () {
        __print (self);
    }
    /*
    Export class as zconfig_t*. Caller is responsibe for destroying the instance
    */
    native static long __zpl (long self, long parent);
    public Zconfig zpl (Zconfig parent) {
        return new Zconfig (__zpl (self, parent.self));
    }
    /*
    Get the message routing id, as a frame
    */
    native static long __routingId (long self);
    public Zframe routingId () {
        return new Zframe (__routingId (self));
    }
    /*
    Set the message routing id from a frame
    */
    native static void __setRoutingId (long self, long routingId);
    public void setRoutingId (Zframe routingId) {
        __setRoutingId (self, routingId.self);
    }
    /*
    Get the mlm_proto message id
    */
    native static int __id (long self);
    public int id () {
        return __id (self);
    }
    /*
    Set the mlm_proto message id
    */
    native static void __setId (long self, int id);
    public void setId (int id) {
        __setId (self, id);
    }
    /*
    Get the mlm_proto message id as printable text
    */
    native static String __command (long self);
    public String command () {
        return __command (self);
    }
    /*
    Get the address field
    */
    native static String __address (long self);
    public String address () {
        return __address (self);
    }
    /*
    Set the address field
    */
    native static void __setAddress (long self, String address);
    public void setAddress (String address) {
        __setAddress (self, address);
    }
    /*
    Get the stream field
    */
    native static String __stream (long self);
    public String stream () {
        return __stream (self);
    }
    /*
    Set the stream field
    */
    native static void __setStream (long self, String stream);
    public void setStream (String stream) {
        __setStream (self, stream);
    }
    /*
    Get the pattern field
    */
    native static String __pattern (long self);
    public String pattern () {
        return __pattern (self);
    }
    /*
    Set the pattern field
    */
    native static void __setPattern (long self, String pattern);
    public void setPattern (String pattern) {
        __setPattern (self, pattern);
    }
    /*
    Get the subject field
    */
    native static String __subject (long self);
    public String subject () {
        return __subject (self);
    }
    /*
    Set the subject field
    */
    native static void __setSubject (long self, String subject);
    public void setSubject (String subject) {
        __setSubject (self, subject);
    }
    /*
    Get a copy of the content field
    */
    native static long __content (long self);
    public Zmsg content () {
        return new Zmsg (__content (self));
    }
    /*
    Get the content field and transfer ownership to caller
    */
    native static long __getContent (long self);
    public Zmsg getContent () {
        return new Zmsg (__getContent (self));
    }
    /*

    */
    native static void __setContent (long self, long contentP);
    public void setContent (Zmsg contentP) {
        __setContent (self, contentP.self);
    }
    /*
    Get the sender field
    */
    native static String __sender (long self);
    public String sender () {
        return __sender (self);
    }
    /*
    Set the sender field
    */
    native static void __setSender (long self, String sender);
    public void setSender (String sender) {
        __setSender (self, sender);
    }
    /*
    Get the tracker field
    */
    native static String __tracker (long self);
    public String tracker () {
        return __tracker (self);
    }
    /*
    Set the tracker field
    */
    native static void __setTracker (long self, String tracker);
    public void setTracker (String tracker) {
        __setTracker (self, tracker);
    }
    /*
    Get the timeout field
    */
    native static int __timeout (long self);
    public int timeout () {
        return __timeout (self);
    }
    /*
    Set the timeout field
    */
    native static void __setTimeout (long self, int timeout);
    public void setTimeout (int timeout) {
        __setTimeout (self, timeout);
    }
    /*
    Get the status_code field
    */
    native static short __statusCode (long self);
    public short statusCode () {
        return __statusCode (self);
    }
    /*
    Set the status_code field
    */
    native static void __setStatusCode (long self, short statusCode);
    public void setStatusCode (short statusCode) {
        __setStatusCode (self, statusCode);
    }
    /*
    Get the status_reason field
    */
    native static String __statusReason (long self);
    public String statusReason () {
        return __statusReason (self);
    }
    /*
    Set the status_reason field
    */
    native static void __setStatusReason (long self, String statusReason);
    public void setStatusReason (String statusReason) {
        __setStatusReason (self, statusReason);
    }
    /*
    Get the amount field
    */
    native static short __amount (long self);
    public short amount () {
        return __amount (self);
    }
    /*
    Set the amount field
    */
    native static void __setAmount (long self, short amount);
    public void setAmount (short amount) {
        __setAmount (self, amount);
    }
    /*
    Self test of this class.
    */
    native static void __test (boolean verbose);
    public static void test (boolean verbose) {
        __test (verbose);
    }
}
