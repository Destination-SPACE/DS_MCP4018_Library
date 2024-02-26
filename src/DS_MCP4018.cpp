#include "DS_MCP4018.h"

bool MCP4018::begin()
{
    Wire.begin();
    delay(100);
    Wire.beginTransmission(MCP_ADDRESS);
    bool error = Wire.endTransmission();
    if(error == 0){
        delay(10);
        Wire.beginTransmission(MCP_ADDRESS);
        Wire.write(MCP_WRITE);
        Wire.write(DEFAULT_STEP);
        Wire.endTransmission();
        return false;
    }
    else{
        return true;
    }
}

void MCP4018::reset()
{
    Wire.beginTransmission(MCP_ADDRESS);
    Wire.write(0xFF);
    Wire.endTransmission();
    delay(10);
}

//Set Values
void MCP4018::setWiperPercent(int percent)
{
    float resistance = MAX_RESISTANCE * percent / 100;
    float terminalResistance = resistance - WIPER_RESISTANCE;
    uint8_t mcpByte = static_cast<uint8_t>(127 * terminalResistance / MAX_RESISTANCE);
    Wire.beginTransmission(MCP_ADDRESS);
    Wire.write(MCP_WRITE);
    Wire.write(mcpByte);
    Wire.endTransmission();
    delay(10);
}

void MCP4018::setWiperResistance(int resistance)
{
    float terminalResistance = resistance - WIPER_RESISTANCE;
    uint8_t mcpByte = static_cast<uint8_t>(127 * terminalResistance / MAX_RESISTANCE);
    Wire.beginTransmission(MCP_ADDRESS);
    Wire.write(MCP_WRITE);
    Wire.write(mcpByte);
    Wire.endTransmission();
    delay(10);
}

void MCP4018::setWiperByte(uint8_t value)
{
    Wire.beginTransmission(MCP_ADDRESS);
    Wire.write(MCP_WRITE);
    Wire.write(value);
    Wire.endTransmission();
    delay(10);
}

void MCP4018::setWiperZero()
{
    Wire.beginTransmission(MCP_ADDRESS);
    Wire.write(MCP_WRITE);
    Wire.write(0x00);
    Wire.endTransmission();
    delay(10);
}

void MCP4018::setWiperMax()
{
    Wire.beginTransmission(MCP_ADDRESS);
    Wire.write(MCP_WRITE);
    Wire.write(0x7F);
    Wire.endTransmission();
    delay(10);
}

//Get Values
int MCP4018::getWiperPercent()
{
    Wire.beginTransmission(MCP_ADDRESS);
    Wire.write(MCP_READ);
    Wire.endTransmission();
    Wire.reqestFrom(MCP_ADDRESS, 1);
    uint8_t value = Wire.read();
    int resistance = MAX_RESISTANCE * value / 127 + WIPER_RESISTANCE;
    int percent = resistance / MAX_RESISTANCE * 100

    return percent;
}

int MCP4018::getWiperResistance()
{
    Wire.beginTransmission(MCP_ADDRESS);
    Wire.write(MCP_READ);
    Wire.endTransmission();
    Wire.reqestFrom(MCP_ADDRESS, 1);
    uint8_t value = Wire.read();
    int resistance = MAX_RESISTANCE * value / 127 + WIPER_RESISTANCE;

    return resistance;
}

uint8_t MCP4018::getWiperByte()
{
    Wire.beginTransmission(MCP_ADDRESS);
    Wire.write(MCP_READ);
    Wire.endTransmission();
    Wire.reqestFrom(MCP_ADDRESS, 1);
    uint8_t value = Wire.read();
    
    return value;
}