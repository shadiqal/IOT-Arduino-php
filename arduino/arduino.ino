#include <SPI.h>
#include <Ethernet.h>
#define PORT 5000
#include "HX711.h"
#define DOUT  A0
#define CLK  A1
HX711 scale(DOUT, CLK);

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

IPAddress ip(192, 168, 1, 177); //Masukkan ip address ethernet shield nya
IPAddress serv(192, 168, 1, 2); //Masukkan ip address laptop/komputer kanda
EthernetClient client;

float calibration_factor = 310;
int berat;
EthernetServer server(80);
void setup()
{
  Serial.begin(9600);
  Ethernet.begin(mac, ip);

  scale.set_scale();
  scale.tare();
  Serial.print(Ethernet.localIP());
}

void loop()
{

  scale.set_scale(calibration_factor);
  berat = scale.get_units(), 4;
  Serial.print("Berat = ");
  Serial.println(berat);
  int beratmuatan;
  beratmuatan = scale.get_units(), 4;

  beratmuatan = berat - 797;

  if (berat < 0) {
    berat = 0;
  }
  if (beratmuatan < 0){
    beratmuatan = 0;
  }
  if (client.connect(serv, 80) == 1) { 
    Serial.println(" Connected With Server");
    client.print("GET /iot/assets/php/masukkanData.php?berat="); //Mengambil file di masukkanData.php untuk memasukkan data sensor ke database 
    client.print(berat);
    client.println(" HTTP/1.1");
    client.println("Host: 192.168.1.2");
    client.println("Connection: close\r\n");
    client.println();
    client.println();

    Serial.println();


    //Get any page response
    while (client.connected()) {
      while (client.available()) {
        //do your serial parsing here
        Serial.write(client.read());
      }
    }

  } else {
    Serial.println("Not Connected");
  }

  // Disconnect kan
  client.stop();
  delay(1000);
}
