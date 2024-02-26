#ifndef _DS_MCP4018_h
#define _DS_MCP4018_h
#include <Arduino.h>
#include <Wire.h>

#define MCP_ADDRESS 0x2F        // Default I2C Address
#define MCP_WRITE 0x00          // MCP4018 write command
#define MCP_READ 0x01           // MCP4018 read command

#define STEP_NUMBER 127         // 127 total resistors, 128 possible steps (0x00 to 0x7F)
#define DEFAULT_STEP 0x3F       // Half of the total range

#define WIPER_RESISTANCE 100.00 // Nominal wiper resistance, very rough estimage :(
#define MAX_RESISTANCE 10000.00 // ~78.74R/step

class MCP4018
{
    public:
        bool begin(void);
        void reset(void);

        void setWiperPercent(int);
        void setWiperResistance(int);
        void setWiperByte(uint8_t);
        void setWiperZero(void);
        void setWiperMax(void);

        int getWiperPercent(void);
        int getWiperResistance(void);
        uint8_t getWiperByte(void);
};

#endif