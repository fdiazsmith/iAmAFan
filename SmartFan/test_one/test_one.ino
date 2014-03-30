#define AC  10 
#define genericIn A0
const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int index = 0;                  // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average


void setup() {

  pinMode(AC, OUTPUT);
  pinMode(genericIn, INPUT);
  Serial.begin(9600);
  Serial.println("Ready");
  
    for (int thisReading = 0; thisReading < numReadings; thisReading++)
    readings[thisReading] = 0;   
}

void loop(){       
        total= total - readings[index];         
  // read from the sensor:  
  readings[index] = analogRead(genericIn); 
  // add the reading to the total:
  total= total + readings[index];       
  // advance to the next position in the array:  
  index = index + 1;                    

  // if we're at the end of the array...
  if (index >= numReadings)              
    // ...wrap around to the beginning: 
    index = 0;                           

  // calculate the average:
  average = total / numReadings;         
  // send it to the computer as ASCII digits
    
  delay(1);        // delay in 
  
  int maped =  map(average, 0, 1023, 0, 255);

  analogWrite(AC, maped);
 Serial.println(maped);
}

