/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
#ifndef Q_MLM_PROTO_H
#define Q_MLM_PROTO_H

#include "qmalamute.h"

class QT_MLM_EXPORT QMlmProto : public QObject
{
    Q_OBJECT
public:

    //  Copy-construct to return the proper wrapped c types
    QMlmProto (mlm_proto_t *self, QObject *qObjParent = 0);

    //  Create a new empty mlm_proto
    explicit QMlmProto (QObject *qObjParent = 0);

    //  Create a new mlm_proto from zpl/zconfig_t *
    static QMlmProto* newZpl (QZconfig *config, QObject *qObjParent = 0);

    //  Destroy a mlm_proto instance
    ~QMlmProto ();

    //  Create a deep copy of a mlm_proto instance
    QMlmProto * dup ();

    //  Receive a mlm_proto from the socket. Returns 0 if OK, -1 if
    //  there was an error. Blocks if there is no message waiting.
    int recv (QZsock *input);

    //  Send the mlm_proto to the output socket, does not destroy it
    int send (QZsock *output);

    //  Print contents of message to stdout
    void print ();

    //  Export class as zconfig_t*. Caller is responsibe for destroying the instance
    QZconfig * zpl (QZconfig *parent);

    //  Get the message routing id, as a frame
    QZframe * routingId ();

    //  Set the message routing id from a frame
    void setRoutingId (QZframe *routingId);

    //  Get the mlm_proto message id
    int id ();

    //  Set the mlm_proto message id
    void setId (int id);

    //  Get the mlm_proto message id as printable text
    const QString command ();

    //  Get the address field
    const QString address ();

    //  Set the address field
    void setAddress (const QString &address);

    //  Get the stream field
    const QString stream ();

    //  Set the stream field
    void setStream (const QString &stream);

    //  Get the pattern field
    const QString pattern ();

    //  Set the pattern field
    void setPattern (const QString &pattern);

    //  Get the subject field
    const QString subject ();

    //  Set the subject field
    void setSubject (const QString &subject);

    //  Get a copy of the content field
    QZmsg * content ();

    //  Get the content field and transfer ownership to caller
    QZmsg * getContent ();

    //
    void setContent (QZmsg *contentP);

    //  Get the sender field
    const QString sender ();

    //  Set the sender field
    void setSender (const QString &sender);

    //  Get the tracker field
    const QString tracker ();

    //  Set the tracker field
    void setTracker (const QString &tracker);

    //  Get the timeout field
    quint32 timeout ();

    //  Set the timeout field
    void setTimeout (quint32 timeout);

    //  Get the status_code field
    quint16 statusCode ();

    //  Set the status_code field
    void setStatusCode (quint16 statusCode);

    //  Get the status_reason field
    const QString statusReason ();

    //  Set the status_reason field
    void setStatusReason (const QString &statusReason);

    //  Get the amount field
    quint16 amount ();

    //  Set the amount field
    void setAmount (quint16 amount);

    //  Self test of this class.
    static void test (bool verbose);

    mlm_proto_t *self;
};
#endif //  Q_MLM_PROTO_H
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
