#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "jones";
const char* password = "senha";

String botToken = "7590203312:AAFxxsKmVnWf0DrVKaX_P0o_M4V3MByA-_U";
String chatId = "meu-id-chat";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  Serial.print("Conectando ao Wi-Fi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("");

    
    Serial.print(".");
  }
  Serial.println("Conectado!");

  sendTelegramMessage("Olá do ESP32 via Telegram!");
}

void loop() {
  
}

void sendTelegramMessage(String message) {
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