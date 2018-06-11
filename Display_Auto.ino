#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>      //Nucleo de la librería gráfica.
#include <Adafruit_SSD1306.h>  //Librería para pantallas OLED monocromas de 128x64 y 128x32
#define OLED_RESET 0 
Adafruit_SSD1306 display(OLED_RESET);

void setup()   {                
 
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // //Inicializa pantalla con en la dirección 0x3D para la conexión I2C.
 
}

void loop() {
 
//PUNTOS EN LAS CUATRO ESQUINAS DE LA PANTALLA
 
  display.fillScreen(0);         //Limpiamos la pantalla
 
  display.setFont();             //Fuente por defecto -si no la hemos cambiado no es necesario seleccionarla
  
  display.drawCircle(8,16,8,1);
  display.fillCircle(8,16,6,1);
  display.setTextSize(2);        
  display.setTextColor(1,0);
  display.setCursor(18,10);
  display.println("Nivel OK");
  
  display.drawCircle(8,48,8,1);
  display.fillCircle(8,48,6,1);
  display.setTextSize(2);        
  display.setTextColor(1,0);
  display.setCursor(18,42);
  display.println("Temp 78C");
  
  display.display();             //Refrescamos la pantalla para visualizarlo
  delay(4000);
  
  display.fillScreen(0);         //Limpiamos la pantalla
 
  display.setFont();             //Fuente por defecto -si no la hemos cambiado no es necesario seleccionarla
 
  display.drawCircle(8,16,8,1);
  display.setTextSize(2);        
  display.setTextColor(0,1);
  display.setCursor(18,10);
  display.println("Nivel ERR");

  display.drawCircle(8,48,8,1);
  display.fillCircle(8,48,6,1);
  display.setTextSize(2);        
  display.setTextColor(1,0);
  display.setCursor(18,42);
  display.println("Temp 78C");

  display.display();             //Refrescamos la pantalla para visualizarlo
  delay(4000);
  
  display.fillScreen(0);         //Limpiamos la pantalla
 
  display.setFont();             //Fuente por defecto -si no la hemos cambiado no es necesario seleccionarla
  
  display.drawCircle(8,16,8,1);
  display.setTextSize(2);        
  display.setTextColor(0,1);
  display.setCursor(18,10);
  display.println("Nivel ERR");

  display.drawCircle(8,48,8,1);
  display.setTextSize(2);        
  display.setTextColor(0,1);
  display.setCursor(18,42);
  display.println("Temp 110C");
  
  display.display();             //Refrescamos la pantalla para visualizarlo
  delay(4000);    
}
