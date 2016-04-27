# FIU Protocol

Server connected to a virtual motor

Client

* Has a GUI
* Can control motor remotely

Commands from Client

* First byte is the size. The next byte is the command. The last byte is the payload

* '1' Start
* '2' Stop
* '3' Rotate (Left or Right)
* '4' Speed (RPM)

* Have a GUI for sending commands
* Have an area to display the response

Responses from Server

* OK
* Error

April 28 - Assignment 8 (client/server)

May 4 - BeagleBone Black

# BeagleBone Black

Deliverable - MicroSD card with program

Analysis, Design, SourceCode, Instructions on how to use, MicroSD card with full application.

linaro arm compiler?

Look for wxgtk for debian on BBB so we don't have to build it? Build app on BBB?
