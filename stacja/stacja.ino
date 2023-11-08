#include <DHT11.h>
#include <ArduinoJson.h>


DHT11 dht11(2);

void setup()
{
    Serial.begin(9600);
    StaticJsonDocument<200> doc;
    String jsonString;
    serializeJson(doc, jsonString);
}



void loop()
{

    float temperature = dht11.readTemperature();



    float humidity = dht11.readHumidity();

    if (temperature != DHT11::ERROR_CHECKSUM && temperature != DHT11::ERROR_TIMEOUT &&
        humidity != DHT11::ERROR_CHECKSUM && humidity != DHT11::ERROR_TIMEOUT) // pewnie można to skrócić
    {
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.println(" °C");
        float doc["Temperatura"]=temperature;
        

        Serial.print("Humidity: ");
        Serial.print(humidity);
        Serial.println(" %");
        float doc["Wilgotność"]=humidity;
        

        
        
     
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