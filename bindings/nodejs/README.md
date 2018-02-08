# Node.js Binding for Malamute

This is a development kit. Note: this README is generated automatically
by zproject from project.xml. Please DO NOT modify by hand except for test
purposes.

## Prerequisites

### Node.js

* You need Python (v2.7 recommended, v3.x not supported)
* You need (I recommend) nvm and Node.js.
* If your Linux has an existing 'node' command, `sudo apt-get remove node`.
* In every terminal, or .bashrc: `nvm use v5.5.0`

To install the necessary Node tools:

```
sudo apt-get update
sudo apt-get install build-essential libssl-dev
curl https://raw.githubusercontent.com/creationix/nvm/v0.11.1/install.sh | bash
# close terminal, re-open
nvm ls-remote
nvm install v5.5.0
npm install -g nan
npm install -g node-ninja
npm install -g prebuild
npm install -g bindings
```

To build:

```
mkdir -p $HOME/temp
cd $HOME/temp
git clone https://github.com/zeromq/malamute
cd malamute/bindings/nodejs
#   Clones dependencies, builds everything
./build.sh
```

## API

This is a wrapping of the native C libmlm library. See binding.cc for the code.

### The MlmProto class - Set the content field, transferring ownership from caller

Constructor:

```
var mlm = require ('bindings')('malamute')
var my_mlm_proto = new mlm.MlmProto ()
```

You *must* call the destructor on every MlmProto instance:

```
my_mlm_proto.destroy ()
```

Methods:

```
mlm_proto my_mlm_proto.dup ()
```

Create a deep copy of a mlm_proto instance

```
integer my_mlm_proto.recv (Zsock)
```

Receive a mlm_proto from the socket. Returns 0 if OK, -1 if
there was an error. Blocks if there is no message waiting.

```
integer my_mlm_proto.send (Zsock)
```

Send the mlm_proto to the output socket, does not destroy it

```
nothing my_mlm_proto.print ()
```

Print contents of message to stdout

```
zconfig my_mlm_proto.zpl (Zconfig)
```

Export class as zconfig_t*. Caller is responsibe for destroying the instance

```
zframe my_mlm_proto.routingId ()
```

Get the message routing id, as a frame

```
nothing my_mlm_proto.setRoutingId (Zframe)
```

Set the message routing id from a frame

```
integer my_mlm_proto.id ()
```

Get the mlm_proto message id

```
nothing my_mlm_proto.setId (Number)
```

Set the mlm_proto message id

```
string my_mlm_proto.command ()
```

Get the mlm_proto message id as printable text

```
string my_mlm_proto.address ()
```

Get the address field

```
nothing my_mlm_proto.setAddress (String)
```

Set the address field

```
string my_mlm_proto.stream ()
```

Get the stream field

```
nothing my_mlm_proto.setStream (String)
```

Set the stream field

```
string my_mlm_proto.pattern ()
```

Get the pattern field

```
nothing my_mlm_proto.setPattern (String)
```

Set the pattern field

```
string my_mlm_proto.subject ()
```

Get the subject field

```
nothing my_mlm_proto.setSubject (String)
```

Set the subject field

```
zmsg my_mlm_proto.content ()
```

Get a copy of the content field

```
zmsg my_mlm_proto.getContent ()
```

Get the content field and transfer ownership to caller

```
nothing my_mlm_proto.setContent (Zmsg)
```



```
string my_mlm_proto.sender ()
```

Get the sender field

```
nothing my_mlm_proto.setSender (String)
```

Set the sender field

```
string my_mlm_proto.tracker ()
```

Get the tracker field

```
nothing my_mlm_proto.setTracker (String)
```

Set the tracker field

```
number my_mlm_proto.timeout ()
```

Get the timeout field

```
nothing my_mlm_proto.setTimeout (Number)
```

Set the timeout field

```
number my_mlm_proto.statusCode ()
```

Get the status_code field

```
nothing my_mlm_proto.setStatusCode (Number)
```

Set the status_code field

```
string my_mlm_proto.statusReason ()
```

Get the status_reason field

```
nothing my_mlm_proto.setStatusReason (String)
```

Set the status_reason field

```
number my_mlm_proto.amount ()
```

Get the amount field

```
nothing my_mlm_proto.setAmount (Number)
```

Set the amount field

```
nothing my_mlm_proto.test (Boolean)
```

Self test of this class.

### The MlmClient class - Malamute Client

    Codec class for mlm_client.

Constructor:

```
var mlm = require ('bindings')('malamute')
var my_mlm_client = new mlm.MlmClient ()
```

You *must* call the destructor on every MlmClient instance:

```
my_mlm_client.destroy ()
```

Methods:

```
zactor my_mlm_client.actor ()
```

Return actor, when caller wants to work with multiple actors and/or
input sockets asynchronously.

```
zsock my_mlm_client.msgpipe ()
```

Return message pipe for asynchronous message I/O. In the high-volume case,
we send methods and get replies to the actor, in a synchronous manner, and
we send/recv high volume message data to a second pipe, the msgpipe. In
the low-volume case we can do everything over the actor pipe, if traffic
is never ambiguous.

```
boolean my_mlm_client.connected ()
```

Return true if client is currently connected, else false. Note that the
client will automatically re-connect if the server dies and restarts after
a successful first connection.

```
integer my_mlm_client.setPlainAuth (String, String)
```

Set PLAIN authentication username and password. If you do not call this, the
client will use NULL authentication. TODO: add "set curve auth".
Returns >= 0 if successful, -1 if interrupted.

```
integer my_mlm_client.connect (String, Number, String)
```

Connect to server endpoint, with specified timeout in msecs (zero means wait
forever). Constructor succeeds if connection is successful. The caller may
specify its address.
Returns >= 0 if successful, -1 if interrupted.

```
integer my_mlm_client.setConsumer (String, String)
```

Consume messages with matching subjects. The pattern is a regular expression
using the CZMQ zrex syntax. The most useful elements are: ^ and $ to match the
start and end, . to match any character, \s and \S to match whitespace and
non-whitespace, \d and \D to match a digit and non-digit, \a and \A to match
alphabetic and non-alphabetic, \w and \W to match alphanumeric and
non-alphanumeric, + for one or more repetitions, * for zero or more repetitions,
and ( ) to create groups. Returns 0 if subscription was successful, else -1.
Returns >= 0 if successful, -1 if interrupted.

```
integer my_mlm_client.removeConsumer (String, String)
```

Remove subscriptions to a stream.
Returns >= 0 if successful, -1 if interrupted.

```
integer my_mlm_client.setWorker (String, String)
```

Offer a particular named service, where the pattern matches request subjects
using the CZMQ zrex syntax.
Returns >= 0 if successful, -1 if interrupted.

```
integer my_mlm_client.removeWorker (String, String)
```

Remove offers for named service.
Returns >= 0 if successful, -1 if interrupted.

```
integer my_mlm_client.send (String, String, Zmsg)
```

Send STREAM SEND message to server, takes ownership of message
and destroys message when done sending it.

```
integer my_mlm_client.sendto (String, String, String, Number, Zmsg)
```

Send MAILBOX SEND message to server, takes ownership of message
and destroys message when done sending it.

```
integer my_mlm_client.sendfor (String, String, String, Number, Zmsg)
```

Send SERVICE SEND message to server, takes ownership of message
and destroys message when done sending it.

```
zmsg my_mlm_client.recv ()
```

Receive message from server; caller destroys message when done

```
string my_mlm_client.command ()
```

Return last received command. Can be one of these values:
    "STREAM DELIVER"
    "MAILBOX DELIVER"
    "SERVICE DELIVER"

```
integer my_mlm_client.status ()
```

Return last received status

```
string my_mlm_client.reason ()
```

Return last received reason

```
string my_mlm_client.address ()
```

Return last received address

```
string my_mlm_client.sender ()
```

Return last received sender

```
string my_mlm_client.subject ()
```

Return last received subject

```
zmsg my_mlm_client.content ()
```

Return last received content

```
string my_mlm_client.tracker ()
```

Return last received tracker

```
integer my_mlm_client.sendx (String, String, String)
```

Send multipart string message to stream, end list with NULL
Returns 0 if OK, -1 if failed due to lack of memory or other error.

```
integer my_mlm_client.sendtox (String, String, String)
```

Send multipart string to mailbox, end list with NULL
Returns 0 if OK, -1 if failed due to lack of memory or other error.

```
integer my_mlm_client.sendforx (String, String, String)
```

Send multipart string to service, end list with NULL
Returns 0 if OK, -1 if failed due to lack of memory or other error.

```
integer my_mlm_client.recvx (String, String, String)
```

Receive a subject and string content from the server. The content may be
1 or more string frames. This method is orthogonal to the sendx methods.
End the string arguments with NULL. If there are not enough frames in
the received message, remaining strings are set to NULL. Returns number
of string contents received, or -1 in case of error. Free the returned
subject and content strings when finished with them. To get the type of
the command, use mlm_client_command ().

```
nothing my_mlm_client.setVerbose (Boolean)
```

Enable verbose tracing (animation) of state machine activity.

```
nothing my_mlm_client.test (Boolean)
```

Self test of this class.
