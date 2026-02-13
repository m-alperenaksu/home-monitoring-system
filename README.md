# Home Monitoring System

Arduino Uno ile sıcaklık ve nem takibi yapan basit bir ev izleme sistemi.

## Kullanılan Bileşenler

- Arduino Uno
- DHT11 Sıcaklık & Nem Sensörü
- 16x2 LCD Ekran
- Buzzer

## Bağlantılar

| Bileşen | Pin |
|--------|-----|
| DHT11 | D2 |
| Buzzer | D13 |
| LCD RS | D7 |
| LCD EN | D8 |
| LCD D4-D7 | D9-D12 |

## Nasıl Çalışır

Sistem her 2 saniyede bir DHT11 sensöründen sıcaklık ve nem değerlerini okur, LCD ekranda gösterir. Sıcaklık 30°C veya nem %70 üzerine çıktığında buzzer alarm verir.

## Kütüphaneler

- `DHT sensor library` — Adafruit
- `LiquidCrystal` — Arduino yerleşik
