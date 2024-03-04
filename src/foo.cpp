#include <Arduino.h>
#include <SPI.h>
#include <Ethernet.h>

extern EthernetClient client;
extern int port;
extern IPAddress server;
void Light_OFF();
extern int outputs_state[];
bool flag = false;

void Check_connection(int &_attempt)
{
    if (!client.connect(server, port))
    {
        Serial.println("Server not found");
        _attempt = 0;
        Light_OFF();
        do
        {
            Serial.print("Connection attempt ");
            Serial.println(_attempt++);
            delay(1000);
            flag ? digitalWrite(2, LOW) : digitalWrite(2, HIGH);
            flag = !flag;
        } while (!client.connect(server, port));
        Serial.print("Connected to server running at ");
        Serial.println(client.remoteIP());
        client.write("connected to BOX");
        flag = true;
        digitalWrite(2, HIGH);
    }
}

void Read_message(String &_message)
{
    if (client.available() > 0)
    {
        _message = client.readStringUntil(NULL);
        Serial.print(_message);
    }
}

void Send_message(int output, String state)
{
    if (client.connected())
    {
        String S = String(output);
        S = S + state;
        const char *c = S.c_str();
        client.write(c);
    }
}

void Check_status(String &_message)
{
    String result = "";
    if (_message == "state")
    {
        for (int i = 0; i < 9; i++)
        {
            String S = String(outputs_state[i]);
            result += S;
        }
        Serial.print("\n STATUS: ");
        Serial.println(result);
        const char *c = result.c_str();
        client.write(c);
        _message = "";
    }
}