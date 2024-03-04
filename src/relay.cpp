#include "relay.h"

void Print_outputs_state()
{
  for (int i = 0; i < arr_size; i++)
  {
    Serial.print(outputs_state[i]);
    }
  Serial.println(" ");
}

void Output_off_mark(int name)
{
  for (int i = 0; i < arr_size; i++)
  {
    if (outputs[i] == name)
    {
      outputs_state[i] = 0;
    }
  }
  Serial.print("\n");
  Print_outputs_state();
}

void Output_on_mark(int name)
{
  for (int i = 0; i < arr_size; i++)
  {
    if (outputs[i] == name)
    {
      outputs_state[i] = 1;
    }
  }
  Serial.print("\n");
  Print_outputs_state();
}

void Relay_action(String _message, String &message, int outputs[])
{
  if (_message == "1ON")
  {
    Serial.println("\n Projectors male ON");
    message = "";

    digitalWrite(projectrosM, HIGH);
    Send_message(projectrosM, "ON");
    Output_on_mark(projectrosM);
  }
  if (_message == "1OFF")
  {
    Serial.println("\n Projectors male OFF");
    message = "";
    digitalWrite(projectrosM, LOW);
    Send_message(projectrosM, "OFF");
    Output_off_mark(projectrosM);
  }

  if (_message == "2ON")
  {
    Serial.println("\n 3RE ON");
    message = "";
    digitalWrite(RE3, HIGH);
    Send_message(RE3, "ON");
    Output_on_mark(RE3);
  }
  if (_message == "2OFF")
  {
    Serial.println("\n 3RE OFF");
    message = "";
    digitalWrite(RE3, LOW);
    Send_message(RE3, "OFF");
    Output_off_mark(RE3);
  }

  if (_message == "3ON")
  {
    Serial.println("\n 4RE+5RE ON");
    message = "";
    digitalWrite(RE4RE5, HIGH);
    Send_message(RE4RE5, "ON");
    Output_on_mark(RE4RE5);
  }
  if (_message == "3OFF")
  {
    Serial.println("\n 4RE+5RE OFF");
    message = "";
    digitalWrite(RE4RE5, LOW);
    Send_message(RE4RE5, "OFF");
    Output_off_mark(RE4RE5);
  }

  if (_message == "4ON")
  {
    Serial.println("\n Projectors feMale ON");
    message = "";
    digitalWrite(projectrosF, HIGH);
    Send_message(projectrosF, "ON");
    Output_on_mark(projectrosF);
  }
  if (_message == "4OFF")
  {
    Serial.println("\n Projectors feMale OFF");
    message = "";
    digitalWrite(projectrosF, LOW);
    Send_message(projectrosF, "OFF");
    Output_off_mark(projectrosF);
  }

  if (_message == "5ON")
  {
    Serial.println("\n 3LE ON");
    message = "";
    digitalWrite(LE3, HIGH);
    Send_message(LE3, "ON");
    Output_on_mark(LE3);
  }
  if (_message == "5OFF")
  {
    Serial.println("\n 3LE OFF");
    message = "";
    digitalWrite(LE3, LOW);
    Send_message(LE3, "OFF");
    Output_off_mark(LE3);
  }

  if (_message == "6ON")
  {
    Serial.println("\n 4LE+5LE ON");
    message = "";
    digitalWrite(LE4LE5, HIGH);
    Send_message(LE4LE5, "ON");
    Output_on_mark(LE4LE5);
  }
  if (_message == "6OFF")
  {
    Serial.println("\n 4LE+5LE OFF");
    message = "";
    digitalWrite(LE4LE5, LOW);
    Send_message(LE4LE5, "OFF");
    Output_off_mark(LE4LE5);
  }

  if (_message == "7ON")
  {
    Serial.println("\n Lazers ON");
    message = "";
    digitalWrite(lasers, HIGH);
    Send_message(lasers, "ON");
    Output_on_mark(lasers);
  }
  if (_message == "7OFF")
  {
    Serial.println("\n Lazers OFF");
    message = "";
    digitalWrite(lasers, LOW);
    Send_message(lasers, "OFF");
    Output_off_mark(lasers);
  }

  if (_message == "8ON")
  {
    Serial.println("\n 1RE+2RE ON");
    message = "";
    digitalWrite(RE1RE2, HIGH);
    Send_message(RE1RE2, "ON");
    Output_on_mark(RE1RE2);
  }
  if (_message == "8OFF")
  {
    Serial.println("\n 1RE+2RE OFF");
    message = "";
    digitalWrite(RE1RE2, LOW);
    Send_message(RE1RE2, "OFF");
    Output_off_mark(RE1RE2);
  }

  if (_message == "9ON")
  {
    Serial.println("\n 1LE+2LE ON");
    message = "";
    digitalWrite(LE1LE2, HIGH);
    Send_message(LE1LE2, "ON");
    Output_on_mark(LE1LE2);
  }
  if (_message == "9OFF")
  {
    Serial.println("\n 1LE+2LE OFF");
    message = "";
    digitalWrite(LE1LE2, LOW);
    Send_message(LE1LE2, "OFF");
    Output_off_mark(LE1LE2);
  }

  if (_message == "ALLON")
  {
    Serial.println("\n");
    for (int i = 0; i < arr_size; i++)
    {
      digitalWrite(outputs[i], HIGH);
      Serial.print(outputs[i]);
      Serial.println(" On");

      Send_message(outputs[i], "ON");
      Output_on_mark(outputs[i]);
      delay(1000);
    }
    Print_outputs_state();
    message = "";
  }
  if (_message == "ALLOFF")
  {
    Serial.println("\n");
    for (int i = 0; i < arr_size; i++)
    {
      digitalWrite(outputs[i], LOW);
      Serial.print(outputs[i]);
      Serial.println(" Off");

      Send_message(outputs[i], "OFF");
      Output_off_mark(outputs[i]);
      delay(1000);
    }
    Print_outputs_state();
    message = "";
  }
}

void Light_OFF()
{
  digitalWrite(LE1LE2, LOW);
  Output_off_mark(LE1LE2);

  digitalWrite(LE3, LOW);
  Output_off_mark(LE3);

  digitalWrite(LE4LE5, LOW);
  Output_off_mark(LE4LE5);

  digitalWrite(RE1RE2, LOW);
  Output_off_mark(RE1RE2);

  digitalWrite(RE3, LOW);
  Output_off_mark(RE3);

  digitalWrite(RE4RE5, LOW);
  Output_off_mark(RE4RE5);

  Serial.print("\n LIGHT OFF ");
  Print_outputs_state();
  Serial.print("\n");
}