#include "relay.h"

void Relay_action(String _message, String &message, int outputs[])
{
  if (_message == "1ON")
  {
    Serial.println("\n Projectors male ON");
    message = "";
    digitalWrite(projectrosM, HIGH);
  }
  if (_message == "1OFF")
  {
    Serial.println("\n Projectors male OFF");
    message = "";
    digitalWrite(projectrosM, LOW);
  }

  if (_message == "2ON")
  {
    Serial.println("\n 3RE ON");
    message = "";
    digitalWrite(RE3, HIGH);
  }
  if (_message == "2OFF")
  {
    Serial.println("\n 3RE OFF");
    message = "";
    digitalWrite(RE3, LOW);
  }

  if (_message == "3ON")
  {
    Serial.println("\n 4RE+5RE ON");
    message = "";
    digitalWrite(RE4RE5, HIGH);
  }
  if (_message == "3OFF")
  {
    Serial.println("\n 4RE+5RE OFF");
    message = "";
    digitalWrite(RE4RE5, LOW);
  }

  if (_message == "4ON")
  {
    Serial.println("\n Projectors feMale ON");
    message = "";
    digitalWrite(projectrosF, HIGH);
  }
  if (_message == "4OFF")
  {
    Serial.println("\n Projectors feMale OFF");
    message = "";
    digitalWrite(projectrosF, LOW);
  }

  if (_message == "5ON")
  {
    Serial.println("\n 3LE ON");
    message = "";
    digitalWrite(LE3, HIGH);
  }
  if (_message == "5OFF")
  {
    Serial.println("\n 3LE OFF");
    message = "";
    digitalWrite(LE3, LOW);
  }

  if (_message == "6ON")
  {
    Serial.println("\n 4LE+5LE ON");
    message = "";
    digitalWrite(LE4LE5, HIGH);
  }
  if (_message == "6OFF")
  {
    Serial.println("\n 4LE+5LE OFF");
    message = "";
    digitalWrite(LE4LE5, LOW);
  }

  if (_message == "7ON")
  {
    Serial.println("\n Lazers ON");
    message = "";
    digitalWrite(lasers, HIGH);
  }
  if (_message == "7OFF")
  {
    Serial.println("\n Lazers OFF");
    message = "";
    digitalWrite(lasers, LOW);
  }

  if (_message == "8ON")
  {
    Serial.println("\n 1RE+2RE ON");
    message = "";
    digitalWrite(RE1RE2, HIGH);
  }
  if (_message == "8OFF")
  {
    Serial.println("\n 1RE+2RE OFF");
    message = "";
    digitalWrite(RE1RE2, LOW);
  }

  if (_message == "9ON")
  {
    Serial.println("\n 1LE+2LE ON");
    message = "";
    digitalWrite(LE1LE2, HIGH);
  }
  if (_message == "9OFF")
  {
    Serial.println("\n 1LE+2LE OFF");
    message = "";
    digitalWrite(LE1LE2, LOW);
  }

  if (_message == "ALLON")
  {
    Serial.println("\n");
    for (int i = 0; i < arr_size; i++)
    {
      digitalWrite(outputs[i], HIGH);
      Serial.print(outputs[i]);
      Serial.println(" On");
      String S = String(outputs[i]);
      S = S + "ON";
      const char *c = S.c_str();
      client.write(c);
      delay(1000);
    }
    message = "";
  }
  if (_message == "ALLOFF")
  {
    Serial.println("\n");
    for (int i = 0; i < arr_size; i++)
    {
      digitalWrite(outputs[i], LOW);
      delay(1000);
      Serial.print(outputs[i]);
      Serial.println(" Off");
      String S = String(outputs[i]);
      S = S + "OFF";
      const char *c = S.c_str();
      client.write(c);
    }
    message = "";
  }
}