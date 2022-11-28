
// Librerias necesarias para le funcionamiento del código en Arduino IDE.
// Estas librerias nos permiten: leer los datos por el sensor DHT11, usar las operaciones de Arduino,
// y acceder a Firebase para registrar (set) y regresar (get) datos de los sensores

//Definir librerías de WiFi
#include <esp_wpa2.h>
#include <WiFi.h>
//Librería de Firebase
#include <Firebase_ESP_Client.h>
#include <addons/TokenHelper.h>
//Librería de Arduino
#include "Arduino.h"
#include "addons/RTDBHelper.h"
//Librería del DHT11
#include "DHT.h"

// Se definen los pines empleados para el caso de los sensores de fuerza, de luz y el DHT11, este también debe ser
// definido debido a la variedad de sensores de humedad y temperatura

//Definir pin del DHT
#define DHTPIN 4
//Definir tipo de DHT
#define DHTTYPE DHT11

//Definir pin del sensor de luz y fuerza
#define LIGHT_SENSOR_PIN 36 // ESP32 pin GIOP36 (ADC0)
#define FORCE_SENSOR_PIN 39 // ESP32 pin GIOP39 (ADC0)


// Declaramos la red wifi que el ESP32 empleará para conectarse y enviar elementos a la base de datos, debido a las
// Características de la red del Tec, también se necesita definir una identidad

const char* ssid = "Tec";
#define EAP_IDENTITY "a0xxxxxxx@tec.mx"
#define EAP_PASSWORD "+**********"

// Autorización para poder publicar/subir datos a la base de datos de Firebase
#define USER_EMAIL "a0xxxxxxxx@tec.mx"
#define USER_PASSWORD "***********"


// Firebase project API Key
#define API_KEY "AIzaSyCkZtABLrWDkAvyqf8IRr5s3kIwp724vXo"//AIzaSyCush_8W74MW4SfN3NgmAFBr7GGDfwnjkA

// RTDB URLefine the RTDB URL 
#define DATABASE_URL "https://corintios-5023e-default-rtdb.firebaseio.com"

// Definimos un objeto de datos Firebase
FirebaseData fbdo;

// Declaramos el autor para subir elementos en la base de datos
FirebaseAuth auth;

// Declaramos las configuraciones para subir elementos a la base de datos
FirebaseConfig config;

// Declaración de variables que permitirán almacenar datos particulares (control de acceso y tiempos de espera)
// y de los sensores o salidas digitales de nuestro ESP32
unsigned long sendDataPrevMillis = 0;
int intValue;
float floatValue;
String stringValue;
const int PIN_TO_SENSOR = 19; // GIOP19 pin connected to OUTPUT pin of sensor
int pinStateCurrent   = LOW;  // current state of pin
int pinStatePrevious  = LOW;  // previous state of pin

bool signupOK = false;
int count = 0;
DHT dht(DHTPIN, DHTTYPE);


int LEDs[] = {22,23,1,3,19,18,5};    // for ESP32 microcontroller

//se declaran los arreglos que forman los dígitos
int zero[] = {0, 1, 1, 1, 1, 1, 1};   // cero
int one[] = {0, 0, 0, 0, 1, 1, 0};   // uno
int two[] = {1, 0, 1, 1, 0, 1, 1};   // dos
int three[] = {1, 0, 0, 1, 1, 1, 1};   // tres
int four[] = {1, 1, 0, 0, 1, 1, 0};   // cuatro 
int five[] = {1, 1, 0, 1, 1, 0, 1};   // cinco
int six[] = {1, 1, 1, 1, 1, 0, 1};   // seis
int seven[] = {1, 0, 0, 0, 1, 1, 1};   // siete
int eight[] = {1, 1, 1, 1, 1, 1, 1}; // ocho
int nine[] = {1, 1, 0, 1, 1, 1, 1};   // nueve
int line[] = {1, 0, 0, 0, 0, 0, 0};   // nueve


//Void Setup - Instrucciones que se ejecutan una sola vez
void setup() {
    Serial.begin(115200);
    delay(1);
    Serial.println(F("DHTxx test!"));
    pinMode(PIN_TO_SENSOR, INPUT); // set ESP32 pin to input mode to read value from OUTPUT pin of sensor
    dht.begin();

    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
    
    
    // WPA2 enterprise magic starts here
    WiFi.disconnect(true);
    WiFi.mode(WIFI_STA);   //init wifi mode
    //esp_wifi_set_mac(ESP_IF_WIFI_STA, &masterCustomMac[0]);
    Serial.print("MAC >> ");
    Serial.println(WiFi.macAddress());
    Serial.printf("Connecting to WiFi: %s ", ssid);
    //esp_wifi_sta_wpa2_ent_set_ca_cert((uint8_t *)incommon_ca, strlen(incommon_ca) + 1);
    esp_wifi_sta_wpa2_ent_set_identity((uint8_t *)EAP_IDENTITY, strlen(EAP_IDENTITY));
    esp_wifi_sta_wpa2_ent_set_username((uint8_t *)EAP_IDENTITY, strlen(EAP_IDENTITY));
    esp_wifi_sta_wpa2_ent_set_password((uint8_t *)EAP_PASSWORD, strlen(EAP_PASSWORD));
    //esp_wpa2_config_t configW = WPA2_CONFIG_INIT_DEFAULT();
    //esp_wifi_sta_wpa2_ent_enable(&configW);
    esp_wifi_sta_wpa2_ent_enable();
    // WPA2 enterprise magic ends here


    WiFi.begin(ssid);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    // Asignar la API key
    config.api_key = API_KEY;

    // Asignar la URL RTDB (Real Time Database)
    config.database_url = DATABASE_URL;

    //Iniciar sesión
    if (Firebase.signUp(&config, &auth, "", "")){
      Serial.println("ok");
      signupOK = true;
    }
    else{
      Serial.printf("%s\n", config.signer.signupError.message.c_str());
    }

    // Asignar la función de devolución para la tarea prolongada de generación de tokens
    config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h

    //Ingresar a la base de datos
    Firebase.begin(&config, &auth);
    Firebase.reconnectWiFi(true);
    
    //Impresión inicial de los números del 1 al 7 en el LED
    for (int i = 0; i<7; i++) pinMode(LEDs[i], OUTPUT);
}



/*
 *  everyhting below this, in loop(), is just a standard request to a webserver and nothing else than an example to show that is works.
 *
 */

int value = 0;

void loop() {

  pinStatePrevious = pinStateCurrent;             // Leer el estado anterior
  pinStateCurrent = digitalRead(PIN_TO_SENSOR);   // Leer el estado actual

  int analogValue = analogRead(LIGHT_SENSOR_PIN);
  int analogReading = analogRead(FORCE_SENSOR_PIN);

  //Serial.print("Analog Value = ");
  //Serial.print(analogValue);   // the raw analog reading

  // Leer la humedad y la temperatura en Celsius (default) y en Fahrenheit
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  // Calcular el índice de calor en Fahrenheit (default) y Celsius
  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  
  if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 1 || sendDataPrevMillis == 0)) {
    sendDataPrevMillis = millis();
  // Write an Int number on the database path test/int
  if (Firebase.RTDB.setInt(&fbdo, "app_inventor/Luz", analogValue)){
    Serial.println("PASSED");
    Serial.println("PATH: " + fbdo.dataPath());
    Serial.println("TYPE: " + fbdo.dataType());
  }
  else {
    Serial.println("FAILED");
    Serial.println("REASON: " + fbdo.errorReason());
  }
  //count++;
  if (Firebase.RTDB.setFloat(&fbdo, "app_inventor/Humedad", h)){
    Serial.println("PASSED");     
    Serial.println("PATH: " + fbdo.dataPath());
    Serial.println("TYPE: " + fbdo.dataType());
  }
  else {
    Serial.println("FAILED");
    Serial.println("REASON: " + fbdo.errorReason());
  }
  // Write an Float number on the database path test/float
  if (Firebase.RTDB.setFloat(&fbdo, "app_inventor/Temperatura",hic )){
    Serial.println("PASSED");
    Serial.println("PATH: " + fbdo.dataPath());
    Serial.println("TYPE: " + fbdo.dataType());
  }
  else {
    Serial.println("FAILED");
    Serial.println("REASON: " + fbdo.errorReason());
  }
  // Write an Int number on the database path test/int
  if (Firebase.RTDB.setInt(&fbdo, "app_inventor/Fuerza", analogReading)){
    Serial.println("PASSED");
    Serial.println("PATH: " + fbdo.dataPath());
    Serial.println("TYPE: " + fbdo.dataType());
    //delay(10);
    //Firebase.RTDB.setInt(&fbdo, "ti/mov", pinStateP);
   }
  else {
    Serial.println("FAILED");
    Serial.println("REASON: " + fbdo.errorReason());
  }
  // Write an Int number on the database path test/int
  if (Firebase.RTDB.setInt(&fbdo, "app_inventor/Movimiento", pinStateCurrent)){
    Serial.println("PASSED");
    Serial.println("PATH: " + fbdo.dataPath());
    Serial.println("TYPE: " + fbdo.dataType());
    delay(5000);{
     Firebase.RTDB.setInt(&fbdo, "app_inventor/Movimiento", 0);
    }
  }
  else {
    Serial.println("FAILED");
    Serial.println("REASON: " + fbdo.errorReason());
  }
  if (Firebase.RTDB.getString(&fbdo, "app_inventor/Numero")){
    if (fbdo.dataType() == "string"){
      stringValue = fbdo.stringData(); 
        int n = stringValue.toInt();
          if (n == 0){
            for (int i = 0; i<7; i++) digitalWrite(LEDs[i], zero[i]);}   
          if (n == 1){
            for (int i = 0; i<7; i++) digitalWrite(LEDs[i], one[i]);}  
          if (n == 2){
            for (int i = 0; i<7; i++) digitalWrite(LEDs[i], two[i]);} 
          if (n == 3){
            for (int i = 0; i<7; i++) digitalWrite(LEDs[i], three[i]);}
          if (n == 4){
            for (int i = 0; i<7; i++) digitalWrite(LEDs[i], four[i]);}
          if (n == 5){
            for (int i = 0; i<7; i++) digitalWrite(LEDs[i], five[i]);}
          if (n == 6){
            for (int i = 0; i<7; i++) digitalWrite(LEDs[i], six[i]);}
          if (n == 7){
            for (int i = 0; i<7; i++) digitalWrite(LEDs[i], seven[i]);}
          if (n == 8){
            for (int i = 0; i<7; i++) digitalWrite(LEDs[i], eight[i]);}  
          if (n == 9){
            for (int i = 0; i<7; i++) digitalWrite(LEDs[i], nine[i]);}
          if (n > 9){
            for (int i = 0; i<7; i++) digitalWrite(LEDs[i], line[i]);}           
    }
   }
 }
}


