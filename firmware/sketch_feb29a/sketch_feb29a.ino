/*
 * Rui Santos 
 * Complete Project Details https://randomnerdtutorials.com
 */

// include TFT and SPI libraries
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>
#include <mySD.h>

// pin definition for Arduino UNO
#define TFT_CS     10 // PA18
#define TFT_RST    8  // PA06
// TFT_MOSI    PB10
//TFT SCK PB11
#define TFT_DC     9 //PA07
#define TFT_BACKLIGHT A3 // Display backlight pin
// create an instance of the library
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
//SPIClass SPI (&PERIPH_SPI,  PIN_SPI_MISO,  PIN_SPI_SCK,  PIN_SPI_MOSI,  PAD_SPI_TX,       PAD_SPI_RX);
//SPIClass SPI_ETH (&sercom2,   PORT_PA08,     PORT_PA11,    PORT_PA10,     SPI_PAD_2_SCK_3,  SERCOM_RX_PAD_0);
//SPIClass SPI_ETH (&sercom2,   PORT_PA08,     PORT_PA11,    PORT_PA10,     SPI_PAD_2_SCK_3,  SERCOM_RX_PAD_0);

void setup() {

  //initialize the library
  tft.initR(INITR_BLACKTAB); 

 tft.fillScreen(ST7735_BLACK); 


   Serial.print("Initializing SD card...");
  /* initialize SD library with SPI pins */
  if (!SD.begin(26, 14, 12, 27)) {
    Serial.println("initialization failed!");
    return;
  }
    Serial.println("initialization done.");


}

void loop() {


  


 tft.setTextWrap(false);

 tft.setCursor(0, 0);
 tft.setTextColor(ST7735_WHITE);
 tft.setTextSize(3);
 tft.println("Hello");
  
  // wait 200 miliseconds until change to next color
  delay(200);
}
