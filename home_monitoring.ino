// Ev İzleme Sistemi - Muhammet Alperen AKSU

#include <DHT.h>
#include <LiquidCrystal.h>

#define DHT_PIN 2
#define DHT_TIP DHT11
#define BUZZER_PIN 13

#define SICAKLIK_ESIK 30
#define NEM_ESIK 70

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
DHT dht(DHT_PIN, DHT_TIP);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(BUZZER_PIN, OUTPUT);
  dht.begin();

  lcd.print("Sistem basliyor");
  delay(2000);
  lcd.clear();
}

void loop() {
  float nem = dht.readHumidity();
  float sicaklik = dht.readTemperature();

  // sensör bazen nan dönüyor
  if (isnan(nem) || isnan(sicaklik)) {
    lcd.clear();
    lcd.print("Sensor hatasi!");
    delay(2000);
    return;
  }

  Serial.print("Sicaklik: ");
  Serial.print(sicaklik);
  Serial.print(" C  |  Nem: ");
  Serial.print(nem);
  Serial.println(" %");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sic: ");
  lcd.print(sicaklik, 1);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Nem: ");
  lcd.print(nem, 1);
  lcd.print(" %");

  if (sicaklik > SICAKLIK_ESIK || nem > NEM_ESIK) {
    alarmCal();
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(2000);
}

void alarmCal() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(200);
    digitalWrite(BUZZER_PIN, LOW);
    delay(200);
  }
}
