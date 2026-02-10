// ========================================================================
//     🔸 A S 5 6 0 0  -  A N A L O G   A N G L E  R E A D I N G 🔸
// ========================================================================
//  Archivo    : AS5600--Analog_angle_reading.ino
//  Autor      : Klaus Michalsky
//  Fecha      : Feb-2026
//
//  DESCRIPCION
//  -----------------------------------------------------------------------
//  - Lee directamente la salida analógica del AS5600 usando un pin ADC (GP26).
//  - Convierte el valor leído (0–1023) en un ángulo equivalente entre 0° y 360°.
//  - Muestra el ángulo por Serial cada 100 ms.
//  - Método simple y rápido sin usar I2C ni librerías.
//  - Ideal para pruebas rápidas o cuando solo se usa la salida OUT del AS5600.
//  - Sensible al ruido electrico
//
//  HARDWARE
//  -----------------------------------------------------------------------
//  MCU     : RP2040-Zero
//  Sensor  : AS5600
//
//  ESTADO
//  -----------------------------------------------------------------------
//  ✅ Funcional
// ========================================================================

#define ENCODER 26 // tiene que ser Pin ADC con Analog Input

void setup()
{
  Serial.begin(9600);
  pinMode(ENCODER, INPUT);
}

void loop()
{
  int value = analogRead(ENCODER);           // Leer voltage analogo
  float angle = map(value, 0, 1023, 0, 360); // Conversion a angulos

  Serial.print("Analog Angle: ");
  Serial.print(angle);
  Serial.println(" degrees");

  delay(100);
}
