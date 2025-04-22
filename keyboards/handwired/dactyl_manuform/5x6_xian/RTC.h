#pragma once

#include "i2c_master.h"

#define RTC_ADDRESS (0b1101000 << 1)
#define I2C_TIMEOUT 50

typedef struct
{
    uint8_t seconds;
    uint8_t minutes;
    uint8_t hours;
    uint8_t day_of_month;
    uint8_t day_of_week;
    uint8_t month;
    uint16_t year;
} time;

// set us in direct switching mode, clear the control bit
void rtc_init(void)
{
    uint8_t control_3[1] = { 0 };
    i2c_write_register(RTC_ADDRESS, 0x2, control_3, 1, I2C_TIMEOUT);

    uint8_t control_1[1] = { 0 };
    i2c_status_t status = i2c_read_register(RTC_ADDRESS, 0x0, control_1, 1, I2C_TIMEOUT);
    if (status == I2C_STATUS_SUCCESS)
    {
        control_1[0] &= ~(1 << 5);
        i2c_write_register(RTC_ADDRESS, 0x0, control_1, 1, I2C_TIMEOUT);
    }
}

// bcd: binary-coded decimal https://en.wikipedia.org/wiki/Binary-coded_decimal
uint8_t bcd_to_bin(uint8_t bcd)
{
    return ((bcd & 0b11110000) >> 4) * 10 + (bcd & 0b00001111);
}

uint8_t bin_to_bcd(uint8_t bin)
{
    return ((bin / 10) << 4) | (bin % 10);
}

time current_time;
i2c_status_t read_rtc(void)
{
    uint8_t time_registers[7];
    i2c_status_t read_status = i2c_read_register(RTC_ADDRESS, 0x3, time_registers, 7, I2C_TIMEOUT);
    if (read_status == I2C_STATUS_SUCCESS)
    {
        // these register values are in BCD format, which means each digit can take up to 4 bits
        uint8_t raw_seconds = time_registers[0] & 0b01111111; // the MSB is used for something else
        current_time.seconds = bcd_to_bin(raw_seconds);
        current_time.minutes = bcd_to_bin(time_registers[1]);
        current_time.hours = bcd_to_bin(time_registers[2]);
        current_time.day_of_month = bcd_to_bin(time_registers[3]) + 1;
        current_time.day_of_week = bcd_to_bin(time_registers[4]);
        current_time.month = bcd_to_bin(time_registers[5]);
        current_time.year = (uint16_t)bcd_to_bin(time_registers[6]) + 2000;
    }
    return read_status;
}

i2c_status_t read_rtc_ctrl(void)
{
    uint8_t ctrl_registers[3];
    i2c_status_t read_status = i2c_read_register(RTC_ADDRESS, 0x0, ctrl_registers, 3, I2C_TIMEOUT);
    if (read_status == I2C_STATUS_SUCCESS)
    {

    }
    return read_status;
}

//https://github.com/adafruit/RTClib/blob/master/src/RTC_PCF8523.cpp
//TODO: adjust?
//TODO: calibrate?

// increment value and get it into the range [0, max)
uint8_t increment_value_bounded(uint8_t value, uint8_t max)
{
    return (value + 1) % max;
}

uint8_t decrement_value_bounded(uint8_t value, uint8_t max)
{
    if (value == 0)
    {
        return max - 1;
    }

    return value - 1;
}

void increment_year(void)
{
    i2c_status_t read_result = read_rtc();
    if (read_result == I2C_STATUS_SUCCESS)
    {
        uint8_t new_year = bin_to_bcd(((uint8_t)(current_time.year - 2000)) + 1);
        i2c_write_register(RTC_ADDRESS, 0x9, &new_year, 1, I2C_TIMEOUT);
    }
}

void decrement_year(void)
{
    i2c_status_t read_result = read_rtc();
    if (read_result == I2C_STATUS_SUCCESS)
    {
        uint8_t new_year = bin_to_bcd(((uint8_t)(current_time.year - 2000)) - 1);
        i2c_write_register(RTC_ADDRESS, 0x9, &new_year, 1, I2C_TIMEOUT);
    }
}

void increment_month(void)
{
    i2c_status_t read_result = read_rtc();
    if (read_result == I2C_STATUS_SUCCESS)
    {
        uint8_t new_month = bin_to_bcd(increment_value_bounded(current_time.month, 12));
        i2c_write_register(RTC_ADDRESS, 0x8, &new_month, 1, I2C_TIMEOUT);
    }
}

void decrement_month(void)
{
    i2c_status_t read_result = read_rtc();
    if (read_result == I2C_STATUS_SUCCESS)
    {
        uint8_t new_month = bin_to_bcd(decrement_value_bounded(current_time.month, 12));
        i2c_write_register(RTC_ADDRESS, 0x8, &new_month, 1, I2C_TIMEOUT);
    }
}

void increment_day_of_week(void)
{
    i2c_status_t read_result = read_rtc();
    if (read_result == I2C_STATUS_SUCCESS)
    {
        uint8_t new_day_of_week = bin_to_bcd(increment_value_bounded(current_time.day_of_week, 7));
        i2c_write_register(RTC_ADDRESS, 0x7, &new_day_of_week, 1, I2C_TIMEOUT);
    }
}

void decrement_day_of_week(void)
{
    i2c_status_t read_result = read_rtc();
    if (read_result == I2C_STATUS_SUCCESS)
    {
        uint8_t new_day_of_week = bin_to_bcd(decrement_value_bounded(current_time.day_of_week, 7));
        i2c_write_register(RTC_ADDRESS, 0x7, &new_day_of_week, 1, I2C_TIMEOUT);
    }
}

void increment_day_of_month(void)
{
    i2c_status_t read_result = read_rtc();
    if (read_result == I2C_STATUS_SUCCESS)
    {
        uint8_t new_day_of_month = bin_to_bcd(increment_value_bounded(current_time.day_of_month - 1, 30));
        i2c_write_register(RTC_ADDRESS, 0x6, &new_day_of_month, 1, I2C_TIMEOUT);
    }
}

void decrement_day_of_month(void)
{
    i2c_status_t read_result = read_rtc();
    if (read_result == I2C_STATUS_SUCCESS)
    {
        uint8_t new_day_of_month = bin_to_bcd(decrement_value_bounded(current_time.day_of_month - 1, 30));
        i2c_write_register(RTC_ADDRESS, 0x6, &new_day_of_month, 1, I2C_TIMEOUT);
    }
}

void increment_hours(void)
{
    i2c_status_t read_result = read_rtc();
    if (read_result == I2C_STATUS_SUCCESS)
    {
        uint8_t new_hours = bin_to_bcd(increment_value_bounded(current_time.hours, 24));
        i2c_write_register(RTC_ADDRESS, 0x5, &new_hours, 1, I2C_TIMEOUT);
    }
}

void decrement_hours(void)
{
    i2c_status_t read_result = read_rtc();
    if (read_result == I2C_STATUS_SUCCESS)
    {
        uint8_t new_hours = bin_to_bcd(decrement_value_bounded(current_time.hours, 24));
        i2c_write_register(RTC_ADDRESS, 0x5, &new_hours, 1, I2C_TIMEOUT);
    }
}

void increment_minutes(void)
{
    i2c_status_t read_result = read_rtc();
    if (read_result == I2C_STATUS_SUCCESS)
    {
        uint8_t new_minutes = bin_to_bcd(increment_value_bounded(current_time.minutes, 60));
        i2c_write_register(RTC_ADDRESS, 0x4, &new_minutes, 1, I2C_TIMEOUT);
    }
}

void decrement_minutes(void)
{
    i2c_status_t read_result = read_rtc();
    if (read_result == I2C_STATUS_SUCCESS)
    {
        uint8_t new_minutes = bin_to_bcd(decrement_value_bounded(current_time.minutes, 60));
        i2c_write_register(RTC_ADDRESS, 0x4, &new_minutes, 1, I2C_TIMEOUT);
    }
}

//TODO: seconds registers need to clear the MSB?
void increment_seconds(void)
{
    i2c_status_t read_result = read_rtc();
    if (read_result == I2C_STATUS_SUCCESS)
    {
        uint8_t new_seconds = bin_to_bcd(increment_value_bounded(current_time.seconds, 60));
        i2c_write_register(RTC_ADDRESS, 0x3, &new_seconds, 1, I2C_TIMEOUT);
    }
}

void decrement_seconds(void)
{
    i2c_status_t read_result = read_rtc();
    if (read_result == I2C_STATUS_SUCCESS)
    {
        uint8_t new_seconds = bin_to_bcd(decrement_value_bounded(current_time.seconds, 60));
        i2c_write_register(RTC_ADDRESS, 0x3, &new_seconds, 1, I2C_TIMEOUT);
    }
}

