#include <DHT11.h>
#include <ArduinoJson.h>
#include <Ethernet.h>


DHT11 dht11(2);
EthernetServer server(80);

void setup()
{
    Serial.begin(9600);
    if (Serial.available()){
      server.begin();
    }
    else
      Serial.println("Failed");
}



void loop()
{
  EthernetClient client = server.available();
  if (!client){
    return;
  }

  StaticJsonDocument<500> doc; //utworzenie dokumentu json

  JsonArray temp = doc.createNestedArray("valTemp"); //utworzenie listy zagnieżdżonej do temperatury

  JsonArray hum = doc.createNestedArray("valHum");// do wilgotności

  float temperature = dht11.readTemperature();

  float humidity = dht11.readHumidity();

    if (temperature != DHT11::ERROR_CHECKSUM && temperature != DHT11::ERROR_TIMEOUT &&
        humidity != DHT11::ERROR_CHECKSUM && humidity != DHT11::ERROR_TIMEOUT) // pewnie można to skrócić
    {
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.println(" °C");
        temp.add(temperature);
        

        Serial.print("Humidity: ");
        Serial.print(humidity);
        Serial.println(" %");
        hum.add(humidity);
        

        
        
     
    }
    else // żeby pokazywało errory przy timeout i checksum
    {
        if (temperature == DHT11::ERROR_TIMEOUT || temperature == DHT11::ERROR_CHECKSUM)
        {
            Serial.print("Temperature Reading Error: ");
            Serial.println(DHT11::getErrorString(temperature));
        }
        if (humidity == DHT11::ERROR_TIMEOUT || humidity == DHT11::ERROR_CHECKSUM)
        {
            Serial.print("Humidity Reading Error: ");
            Serial.println(DHT11::getErrorString(humidity));
        }
    }

  
  
    delay(1000); //delay żeby była różnca odczytów
}