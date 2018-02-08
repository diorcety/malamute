/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
#ifndef Q_ZCHUNK_H
#define Q_ZCHUNK_H

#include "qmalamute.h"

class QT_MLM_EXPORT QZchunk : public QObject
{
    Q_OBJECT
public:

    //  Copy-construct to return the proper wrapped c types
    QZchunk (zchunk_t *self, QObject *qObjParent = 0);

    //  Create a new chunk of the specified size. If you specify the data, it
    //  is copied into the chunk. If you do not specify the data, the chunk is
    //  allocated and left empty, and you can then add data using zchunk_append.
    explicit QZchunk (const void *data, size_t size, QObject *qObjParent = 0);

    //  Destroy a chunk
    ~QZchunk ();

    //  Resizes chunk max_size as requested; chunk_cur size is set to zero
    void resize (size_t size);

    //  Return chunk cur size
    size_t size ();

    //  Return chunk max size
    size_t maxSize ();

    //  Return chunk data
    byte * data ();

    //  Set chunk data from user-supplied data; truncate if too large. Data may
    //  be null. Returns actual size of chunk
    size_t set (const void *data, size_t size);

    //  Fill chunk data from user-supplied octet
    size_t fill (byte filler, size_t size);

    //  Append user-supplied data to chunk, return resulting chunk size. If the
    //  data would exceeded the available space, it is truncated. If you want to
    //  grow the chunk to accommodate new data, use the zchunk_extend method.
    size_t append (const void *data, size_t size);

    //  Append user-supplied data to chunk, return resulting chunk size. If the
    //  data would exceeded the available space, the chunk grows in size.
    size_t extend (const void *data, size_t size);

    //  Copy as much data from 'source' into the chunk as possible; returns the
    //  new size of chunk. If all data from 'source' is used, returns exhausted
    //  on the source chunk. Source can be consumed as many times as needed until
    //  it is exhausted. If source was already exhausted, does not change chunk.
    size_t consume (QZchunk *source);

    //  Returns true if the chunk was exhausted by consume methods, or if the
    //  chunk has a size of zero.
    bool exhausted ();

    //  Read chunk from an open file descriptor
    static QZchunk * read (FILE *handle, size_t bytes);

    //  Write chunk to an open file descriptor
    int write (FILE *handle);

    //  Try to slurp an entire file into a chunk. Will read up to maxsize of
    //  the file. If maxsize is 0, will attempt to read the entire file and
    //  fail with an assertion if that cannot fit into memory. Returns a new
    //  chunk containing the file data, or NULL if the file could not be read.
    static QZchunk * slurp (const QString &filename, size_t maxsize);

    //  Create copy of chunk, as new chunk object. Returns a fresh zchunk_t
    //  object, or null if there was not enough heap memory. If chunk is null,
    //  returns null.
    QZchunk * dup ();

    //  Return chunk data encoded as printable hex string. Caller must free
    //  string when finished with it.
    QString strhex ();

    //  Return chunk data copied into freshly allocated string
    //  Caller must free string when finished with it.
    QString strdup ();

    //  Return TRUE if chunk body is equal to string, excluding terminator
    bool streqNoConflict (const QString &string);

    //  Transform zchunk into a zframe that can be sent in a message.
    QZframe * pack ();

    //  Transform a zframe into a zchunk.
    static QZchunk * unpack (QZframe *frame);

    //  Calculate SHA1 digest for chunk, using zdigest class.
    const QString digest ();

    //  Dump chunk to FILE stream, for debugging and tracing.
    void fprint (FILE *file);

    //  Dump message to stderr, for debugging and tracing.
    //  See zchunk_fprint for details
    void print ();

    //  Probe the supplied object, and report if it looks like a zchunk_t.
    static bool is (void *self);

    //  Self test of this class.
    static void test (bool verbose);

    zchunk_t *self;
};
#endif //  Q_ZCHUNK_H
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
