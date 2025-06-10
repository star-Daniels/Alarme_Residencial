# Alarme_Residencial


## 🎯 Objetivo do Projeto

Desenvolver um **sistema de alarme inteligente para residências**, que utiliza um **sensor PIR conectado a um ESP32**. Ao detectar movimento, **outro ESP32 registra data/hora da ocorrência e envia uma notificação via WhatsApp**, alertando sobre atividade suspeita.

---

## 🧩 Componentes Utilizados

- 1x Módulo **ESP32 DevKit**
- 1x **Sensor de Movimento PIR**
- 1x **Buzzer** (ativo ou passivo)
- 1x **Protoboard**
- 1x **Fonte de alimentação 5V**
- **Conexão Wi-Fi**

---

## ⚙️ Funcionamento do Sistema

1. O **ESP32-Sensor** monitora o ambiente com o **sensor PIR**.
2. Ao detectar movimento, envia a **identificação da porta** onde houve o evento.
3. O **ESP32-Notificador**:
   - Consulta **data e hora atual via NTP**.
   - Envia **mensagem via Telegram**.
   - (Opcional) Ativa um **buzzer como alarme sonoro local**.

---

## 💻 Tecnologias Utilizadas

- Plataforma de desenvolvimento: **ESP32 (Arduino IDE)**
- Linguagem: **C++**
- Comunicação entre ESP32s: **Firebase Realtime Database** ou **MQTT**
- Sincronização de horário: **NTP (Network Time Protocol)**
- Serviço de notificação: **Telegram**

---

## 🔁 Fluxo de Funcionamento

1. Sensor PIR detecta movimento
2. ESP32-Sensor envia sinal para o ESP32-Notificador
3. ESP32-Notificador sincroniza horário via NTP
4. Alerta enviado via  bot do Telegram:

---

## Projeto no Wokwi
https://wokwi.com/projects/432148800056274945

---

## Link do bot
http://t.me/Noobpirsensorbot
