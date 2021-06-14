int led = D1;
int sensorD = D0;
int thresh = 0;
int i = 0;

void setup() {
    pinMode(led, OUTPUT);
    pinMode(sensorD, INPUT);
}

void loop() {
    thresh = digitalRead(sensorD);
    
    if (thresh == 1)
    {
        Particle.publish("RPi_Threshold", String(thresh));
        digitalWrite(led, HIGH);
    }
    else
    {
        i++;
        if (i >= 10000)
        {
            Particle.publish("Threshold", String(thresh));
            i = 0;
        }

        
        digitalWrite(led, LOW);        
    }

    delay(1);
}
