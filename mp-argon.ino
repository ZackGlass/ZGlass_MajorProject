int led = D4;
int sensorD = D3;
int thresh = 0;
int ledTrigger = 0;
int i = 0;

void thresholdHandler(const char *event, const char *data)
{
    thresh = digitalRead(sensorD);
    
    if (thresh == 1)
    {
        Particle.publish("Threshold", String(thresh));
    }
    else
    {
        i++;
        if (i >= 10000)
        {
            Particle.publish("Threshold", String(thresh));
            i = 0;
        }
    }
    
    delay(100);
}

void setup() {
    pinMode(led, OUTPUT);
    pinMode(sensorD, INPUT);
    Particle.subscribe("RPi_Threshold", thresholdHandler);
}

void loop() {

    ledTrigger = digitalRead(sensorD);
    
    if (ledTrigger == 1){
        digitalWrite(led, HIGH);
    }
    else {
        digitalWrite(led, LOW);
    }
    
    delay(10);
}