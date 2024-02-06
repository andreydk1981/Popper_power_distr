#include <Arduino.h>
#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {0x00, 0x01, 0x9D, 0x0D, 0xE2, 0x77};
IPAddress server(10, 0, 1, 150);
IPAddress ip(10, 0, 1, 155);
IPAddress myDns(10, 0, 1, 1);

int outputs[]{3, 4, 5, 22, 23, 24, 25, 26, 27};
int arr_size = sizeof(outputs) / sizeof(outputs[0]);

int port = 2000;
int attempt = 0;
String message;
EthernetClient client;
String command;
void Relay_action(String, String &, int[]);
void Check_connection(int &);
void Read_message(String &);
void Check_status(String &);