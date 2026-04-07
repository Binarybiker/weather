// *************************************************************************************
// *  Autor: Binarybiker
// *  Programa: Meteo
// *  Descripcion: Sencilla estacion Metereologica basica
// *  Fecha: 6-Abril-2026
// *  Version: 1.00
// *  Placa: ESP8266 Wemos D1 Mini (clone)
// **************************************************************************************

#include <Arduino.h>               // --- Necesaria para el entorno arduino

#include <ESP8266WiFi.h>           // --- Para hacer funcionar wifi que ya tiene la placa
#include <ESP8266HTTPClient.h>     // --- Cliente http
#include <WiFiClient.h>            // --- Cliente wifi
#include <ArduinoJson.h>           // --- Para extraer los datos del tiempo

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "weather_iconos.h"         // --- Llamo al archivo que contiene los iconos esta en /include

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


// --- En este fragmento es donde estan los datos de la wifi a la que nos vamos a conectar
// --- recuerda poner los tuyos

const char* ssid = "XXXXXXXXXXXX";  // --nombre de tu wifi
const char* password = "XXXXXXXXXX"; // -- contraseña de tu wifi
String apiKey = "XXXXXXXXXXXXXXXXXXXXXXXX"; // -- apikey que te da openweathermap.org cuando te registras
String ciudad = "Madrid,ES"; // -- Tu ciudad


// --- Nos permite seleccionar el icono a dibujar segun el clima. Solo hice 4

void drawWeatherIcon(String condition) {
  // x = 80 (Este valor regulo lo separado que esta el icono del borde derecho de la pantalla)
  // y = 18 (Centrado vertical)
  // w = 28 (Ancho del icono)
  // h = 32 (Altura del icono)
  // -- Estos valores se puede ajustar un poco segun gusto, si nos pasamos veremos cosas raras
  
  int x = 80; 
  int y = 18;
  int w = 28; 
  int h = 32;

  if (condition == "Clear") {
    display.drawBitmap(x, y, soleado_bmp, w, h, SSD1306_WHITE);
  } else if (condition == "Clouds") {
    display.drawBitmap(x, y, nublado_bmp, w, h, SSD1306_WHITE);
  } else if (condition == "Rain" || condition == "Drizzle") {
    display.drawBitmap(x, y, lluvioso_bmp, w, h, SSD1306_WHITE);
  } else if (condition == "Thunderstorm") {
    display.drawBitmap(x, y, tormentoso_bmp, w, h, SSD1306_WHITE);
  }
}

void setup() {
  // --- Si el display no se inicializa el programa no arranca
  Serial.begin(115200);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { for(;;); }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2);
  display.setCursor(5,30);
  display.println("METEO 1.00");
  display.display();
  delay (5000);
  
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0,20);
  display.println("Conectando a WiFi...");
  display.display();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }

  display.clearDisplay();
  display.setCursor(0,20);
  display.println("-Conectado!-");
  display.display();
  delay(1000);
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;
    String url = "http://api.openweathermap.org/data/2.5/weather?q=" + ciudad + "&units=metric&appid=" + apiKey;
    
    http.begin(client, url);
    int httpCode = http.GET();

    if (httpCode > 0) {
      String payload = http.getString();
      DynamicJsonDocument doc(1024);
      deserializeJson(doc, payload);

      float temp = doc["main"]["temp"];
      int hum = doc["main"]["humidity"];
      String climaStr = doc["weather"][0]["main"]; // Obtenemos el String del clima

      display.clearDisplay();
      
      // Parte Izquierda de la pantalla (Información)
      display.setTextColor(SSD1306_WHITE);
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.println(ciudad.substring(0, 10)); // Si el nombre de la ciudad es largo se cortará

      display.setTextSize(2);
      display.setCursor(0, 22);
      display.print(temp, 1);
      display.print("C");

      display.setTextSize(1);
      display.setCursor(0, 48);
      display.print("H: "); display.print(hum); display.print("%");
      
      display.setCursor(0, 56);
      display.print(climaStr);

      // Parte derecha de la pantalla (Icono)
      drawWeatherIcon(climaStr);

      display.display();
    }
    http.end();
  }
  delay(600000); 
}
