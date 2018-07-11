#include <SPI.h>
#include <Wire.h>
#include <OneWire.h> 
#include <DallasTemperature.h>
#include <Adafruit_GFX.h>      //Nucleo de la librería gráfica.
#include <Adafruit_SSD1306.h>  //Librería para pantallas OLED monocromas de 128x64 y 128x32
#define OLED_RESET 0 
#define ONE_WIRE_BUS D4
Adafruit_SSD1306 display(OLED_RESET);
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);
int Temp=0;
int Nivel=1;
char bufferT[8]="";

void setup() { 
  Serial.begin(9600);               
 
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // //Inicializa pantalla con en la dirección 0x3D para la conexión I2C.
  pinMode(ONE_WIRE_BUS,INPUT_PULLUP);
  

  sensors.begin(); 
 
}

void loop() {
 
//PUNTOS EN LAS CUATRO ESQUINAS DE LA PANTALLA
  sensors.requestTemperatures(); // Send the command to get temperature readings 
  Temp=(int)sensors.getTempCByIndex(0);

  display.fillScreen(0);         //Limpiamos la pantalla
 
  display.setFont();             //Fuente por defecto -si no la hemos cambiado no es necesario seleccionarla
  display.drawCircle(8,16,8,1);
  display.setTextSize(2);        
  if(Nivel == 0) {
     display.setTextColor(0,1);
     display.setCursor(18,10);
     display.println("Nivel ERR");
  }else{
     display.fillCircle(8,16,6,1);
     display.setTextColor(1,0);
     display.setCursor(18,10);
     display.println("Nivel OK");
  }
  
  display.drawCircle(8,48,8,1);
  display.setTextSize(2);
  if(Temp > 92){
     display.setTextColor(0,1);
  }else{
     display.fillCircle(8,48,6,1);
     display.setTextColor(1,0);
  }
  display.setCursor(18,42);
  sprintf(bufferT,"Temp %dC",Temp); 
  display.println(bufferT);

  
  display.display();             //Refrescamos la pantalla para visualizarlo
  delay(4000);
  
 }
