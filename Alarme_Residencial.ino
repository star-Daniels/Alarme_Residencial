#include <WiFiManager.h>
#include <HTTPClient.h>
#include "time.h"


String botToken = "7590203312:AAFxxsKmVnWf0DrVKaX_P0o_M4V3MByA-_U";
String chatId = "";


//ntp
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = -10800; 
const int   daylightOffset_sec = 0;

void setup() {
  Serial.begin(115200);

  pinMode(16, INPUT);
  pinMode(19, OUTPUT);


  Serial.print("Conectando ao Wi-Fi...");
  WiFiManager wm;
  bool res;
  res = wm.autoConnect("AlarmeESP32-Setup");

  if (!res) {
    Serial.println("Falha ao conectar e timeout atingido");
    ESP.restart();
  }
  Serial.println("Conectado com sucesso!");
  
  configura();
  EnviarMensagem("Ligado");

  tone(23,350,200);
  delay(300);
  tone(23,300,200);
  delay(700);
  tone(23,350,200);
  delay(300);
  tone(23,300,200);
  
}

void loop() {


  if(digitalRead(16) == HIGH){
    tone(23,500,10000);
    Serial.println(digitalRead(16));
    EnviarMensagem("Movimento Detectado");
    EnviarMensagem(Data_hora());
    EnviarMensagem("________________");
    tone(23,300,200);

    
  } else{
    noTone(23);
    
  }
  
}

void EnviarMensagem(String message) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    String url = "https://api.telegram.org/bot" + botToken + "/sendMessage?chat_id=" + chatId + "&text=" + message;
    http.begin(url);
    int httpCode = http.GET();

    if (httpCode > 0) {
      String response = http.getString();
      Serial.println("Resposta do Telegram:");
      Serial.println(response);
    } else {
      Serial.print("Erro na requisição: ");
      Serial.println(httpCode);
    }

    http.end();
  } else {
    Serial.println("Wi-Fi não conectado!");
  }
}

void configura() {
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  Serial.println("Configurando horário via NTP...");
  delay(2000); 
}

String Data_hora() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    return "Erro ao obter data e hora";
  }

  char buffer[30];
  strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", &timeinfo);
  return String(buffer);
}
