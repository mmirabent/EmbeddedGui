# MotorServer class

A small server using wxWidgets to provide sockets and event handling

## Protocol

The server receives command messages and replies with responses.

Each command message is defined in three parts. The size, the command, and the
(optional) command attributes. The size is one byte, and must be followed by a
one byte command. The command can then be followed by up to 254 bytes.

Each command will receive a response. The response is in two parts. The first
part is the response type. The response types are OK, Info, Warning, and Error.
The second part is the response attribute. The response attribute is a 4 byte,
unsigned integer.
