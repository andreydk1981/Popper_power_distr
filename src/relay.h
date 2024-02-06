#include<Arduino.h>
#include <SPI.h>
#include <Ethernet.h>

#define projectrosM 22
#define RE3 23
#define RE4RE5 24
#define projectrosF 25
#define LE3 26
#define LE4LE5 27
#define lasers 3
#define RE1RE2 4
#define LE1LE2 5

extern int outputs[];
extern int arr_size;
extern EthernetClient client;

int outputs_state[] = {0,0,0,0,0,0,0,0,0};

void Send_message (int, String);

