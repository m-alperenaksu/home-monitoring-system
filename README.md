# Home Monitoring System

A simple home monitoring system built with Arduino Uno. Tracks temperature and humidity using a DHT11 sensor and shows the values on an LCD screen.

## Components

- Arduino Uno
- DHT11 Temperature & Humidity Sensor
- 16x2 LCD Display
- Buzzer

## Wiring

| Component | Pin |
|-----------|-----|
| DHT11 | D2 |
| Buzzer | D13 |
| LCD RS | D7 |
| LCD EN | D8 |
| LCD D4-D7 | D9-D12 |

## How It Works

Reads temperature and humidity from the DHT11 every 2 seconds and displays them on the LCD. If temperature goes above 30°C or humidity goes above 70%, the buzzer triggers an alarm.
