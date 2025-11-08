#include "LowVoltage.h"
#include "../UIMain.h"
#include <string>

LowVoltage::LowVoltage()
{
}

void LowVoltage::activate()
{
    HIDE_SIDEBAR = true;
}
void LowVoltage::draw()
{
    u8g2.setFont(u8g2_font_profont12_mf);
    u8g2.drawStr(65, 5, "!!Low Voltage!!");
    u8g2.setFont(u8g2_font_profont10_mf);
    u8g2.drawStr(20, 25, "Please connect to the charger.");
    u8g2.drawStr(10, 35, "DO NOT TURN OFF or you will lose your work.");
    std::string volt = std::string("Voltage :") + std::to_string(getBatteryVoltage()).substr(0, 4) + "V";
    u8g2.drawStr(65, 55, volt.c_str());
}


void LowVoltage::update()
{
    draw();
}

void LowVoltage::deactivate()
{
    HIDE_SIDEBAR = false;
}
