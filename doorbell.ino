// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Using HC-SR04 Module & Relay Module
// Nov 1 2020
// ---------------------------------------------------------------- //

#define __pin_echo 2		// attach pin D2 Arduino to pin Echo of HC-SR04
#define __pin_trig 3		//attach pin D3 Arduino to pin Trig of HC-SR04
#define __pin_relay 4		// attach pin D4 Arduino to pin Trig of Relay module

#define __duration_cooldown 2000
#define __duration_bell 2000

long duration;			// duration of sound wave travel
int distance;			// distance measurement

void
setup ()
{
  pinMode (__pin_trig, OUTPUT);	// sensor trigger pin => OUTPUT device.
  pinMode (__pin_echo, INPUT);	// sensor echo pin => INPUT device.
  pinMode (__pin_relay, OUTPUT);	// sensor relay pin => OUTPUT device.
  Serial.begin (9600);		// serial communication => 9600 of baudrate speed
}

void
loop ()
{
  // Clears the trigPin condition
  digitalWrite (__pin_trig, LOW);
  digitalWrite (__pin_relay, LOW);
  delayMicroseconds (2);

  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite (__pin_trig, HIGH);
  delayMicroseconds (10);
  digitalWrite (__pin_trig, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn (__pin_echo, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  if (distance < 4)
    {
      Serial.print ("Doorbell triggered at ");
      Serial.print (distance);
      Serial.println (" cm");
      digitalWrite (__pin_relay, LOW);
      delay (__duration_bell);
      digitalWrite (__pin_relay, HIGH);
      delay (__duration_cooldown);
    }
}
