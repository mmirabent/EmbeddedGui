#ifndef MOTOR_PROTOCOL_H_INCLUDED
#define MOTOR_PROTOCOL_H_INCLUDED

struct MotorRequest
{
    unsigned char size;
    unsigned char command;
    unsigned char attributes[254];
};

struct MotorResponse
{
    unsigned char type;
    uint32_t attribute;
};

enum
{
    STOP_CMD = 0x00,
    START_CMD,
    ROTATE_CMD,
    SPEED_CMD
};

enum
{
    ROTATE_LEFT = 0x00,
    ROTATE_RIGHT
};


#endif // MOTOR_PROTOCOL_H_INCLUDED
