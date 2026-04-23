// ========================================================================
//      🔸 A S 5 6 0 0  -  I 2 C   A N G L E   1 x S E N S O R 🔸
// ========================================================================
//  Archivo    : AS5600_I2C-Angle-1xSensor.ino
//  Autor      : Klaus Michalsky
//  Fecha      : Feb-2026
//
//  DESCRIPCION
//  -----------------------------------------------------------------------
//  - Lee el ángulo del sensor AS5600 conectado a GP26 (SDA) y GP27 (SCL)
//    usando I2C.
//  - Convierte el valor crudo de 12 bits (0–4095) a grados (0°–360°).
//  - Muestra el ángulo por Serial cada 200 ms.
//  - Usa Wire1 para I2C independiente de los pines por defecto.
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

#include <Wire.h>        // Librería para comunicación I2C
#define AS5600_ADDR 0x36 // Dirección I2C fija del AS5600

void setup()
{
    Serial.begin(115200); // Inicializa comunicación Serial a 115200 baudios
    delay(1000);          // Espera 1 segundo para que Serial se estabilice

    // Configuración I2C en GP26=SDA, GP27=SCL usando Wire1
    Wire1.setSDA(26); // Asigna GP26 como SDA
    Wire1.setSCL(27); // Asigna GP27 como SCL
    Wire1.begin();    // Inicializa Wire1

    Serial.println("AS5600 listo para lectura con Wire1"); // Mensaje de confirmación
}

void loop()
{
    uint16_t angle = readAS5600Angle();       // Lectura cruda de 12 bits (0–4095)
    float degrees = (angle * 360.0) / 4096.0; // Conversión a grados

    Serial.print("Ángulo: "); // Imprime texto
    Serial.print(degrees);    // Imprime valor en grados
    Serial.println("°");      // Nueva línea con símbolo de grados

    delay(200); // Espera 200 ms antes de siguiente lectura
}

// FUNCION DE LECTURA DEL AS5600
//  -----------------------------------------------------------------------
//  - Lee registros 0x0E (alto) y 0x0F (bajo)
//  - Valor de 12 bits (0–4095)
uint16_t readAS5600Angle()
{
    Wire1.beginTransmission(AS5600_ADDR);       // Inicia comunicación con el sensor
    Wire1.write(0x0E);                          // Selecciona registro de ángulo alto
    Wire1.endTransmission(false);               // Termina escritura, pero mantiene bus activo (repeated start)
    Wire1.requestFrom(AS5600_ADDR, (uint8_t)2); // Solicita 2 bytes (alto y bajo)

    if (Wire1.available() < 2) // Si no llegan 2 bytes, devuelve 0
        return 0;

    uint8_t high = Wire1.read(); // Lee byte alto
    uint8_t low = Wire1.read();  // Lee byte bajo

    return ((high & 0x0F) << 8) | low; // Combina los 12 bits y devuelve valor final
}
