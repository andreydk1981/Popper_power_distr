#include "main.h"

void setup()
{

  for (size_t i = 0; i < sizeof(outputs) / sizeof(outputs[0]); i++)
  {
    pinMode(outputs[i], OUTPUT);
  }
  // Initialize serial communication.
  Serial.begin(9600);

  Ethernet.begin(mac, ip, myDns);
  Serial.print("Manually assigned the following IP address to the Arduino:");
  Serial.println();
  Serial.println(Ethernet.localIP());
  Serial.print("\narr size=");
  Serial.println(arr_size);
  // Check for Ethernet hardware.
  if (Ethernet.hardwareStatus() == EthernetNoHardware)
  {
    Serial.println("Ethernet shield was not found.");
  }

  // Check for Ethernet cable connection.
  if (Ethernet.linkStatus() == LinkOFF)
  {
    Serial.println("Ethernet cable is not connected.");
  }

  Serial.print("Attempting connection to ");
  Serial.print(server);
  Serial.println("...");

  // Attempt to connect to the server running at IP address 192.168.1.81 and port 5000.

  do
  {
    Serial.print("Connection attempt ");
    Serial.println(attempt++);
  } while (!client.connect(server, port));

  if (client.connect(server, port))
  {
    Serial.print("Connected to server running at ");
    Serial.println(client.remoteIP());
    client.write("connected to BOX");
    attempt = 0;
  }
  else
  {
    Serial.println("Connection to server failed.");
  }
}

void loop()
{

  Check_connection(attempt);
  Read_message (message);

  if (client.connected())
  {
    Relay_action(message, message, outputs);
    Check_status(message);
  }
}
